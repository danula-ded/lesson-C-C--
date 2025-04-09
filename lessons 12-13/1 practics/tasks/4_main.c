#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Point;

int main() {
    int n = 5;
    Point* points = (Point*) malloc(n * sizeof(Point));

    if (points == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Введите координаты точки %d (x y): ", i + 1);
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    printf("\nВведённые точки:\n");
    for (int i = 0; i < n; i++) {
        printf("Точка %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }

    free(points);
    return 0;
}
