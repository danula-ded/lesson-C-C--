#include <windows.h>
#include <wininet.h>
#include <stdio.h>
#include <pthread.h>

#pragma comment(lib, "wininet.lib")

typedef struct {
    char url[256];
    char filename[256];
} DownloadTask;

void* download_thread(void* arg) {
    DownloadTask* task = (DownloadTask*)arg;
    HINTERNET hInternet = InternetOpenA("Downloader", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) {
        printf("Error: InternetOpen failed\n");
        return NULL;
    }

    HINTERNET hUrl = InternetOpenUrlA(hInternet, task->url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hUrl) {
        printf("Error: Cannot open URL %s\n", task->url);
        InternetCloseHandle(hInternet);
        return NULL;
    }

    FILE* fp = fopen(task->filename, "wb");
    if (!fp) {
        printf("Error: Cannot create file %s\n", task->filename);
        InternetCloseHandle(hUrl);
        InternetCloseHandle(hInternet);
        return NULL;
    }

    char buffer[1024];
    DWORD bytesRead;
    while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        fwrite(buffer, 1, bytesRead, fp);
    }

    fclose(fp);
    InternetCloseHandle(hUrl);
    InternetCloseHandle(hInternet);
    printf("Downloaded: %s -> %s\n", task->url, task->filename);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 3 || (argc % 2) != 1) {
        printf("Usage: %s <url1> <file1> [<url2> <file2> ...]\n", argv[0]);
        return 1;
    }

    int numTasks = (argc - 1) / 2;
    pthread_t threads[numTasks];
    DownloadTask tasks[numTasks];

    for (int i = 0; i < numTasks; i++) {
        strncpy(tasks[i].url, argv[1 + i * 2], sizeof(tasks[i].url) - 1);
        strncpy(tasks[i].filename, argv[2 + i * 2], sizeof(tasks[i].filename) - 1);
        pthread_create(&threads[i], NULL, download_thread, &tasks[i]);
    }

    for (int i = 0; i < numTasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}