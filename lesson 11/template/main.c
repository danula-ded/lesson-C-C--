#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void** elements;
    size_t capacity;
    size_t size;
    size_t element_size;
} Container;

Container* container_create(size_t element_size) {
    Container* c = (Container*)malloc(sizeof(Container));
    c->elements = NULL;
    c->capacity = 0;
    c->size = 0;
    c->element_size = element_size;
    return c;
}

void container_destroy(Container* c) {
    for (size_t i = 0; i < c->size; ++i) {
        free(c->elements[i]);
    }
    free(c->elements);
    free(c);
}

void container_add(Container* c, const void* element) {
    if (c->size >= c->capacity) {
        c->capacity = c->capacity == 0 ? 1 : c->capacity * 2;
        c->elements = (void**)realloc(c->elements, c->capacity * sizeof(void*));
    }
    c->elements[c->size] = malloc(c->element_size);
    memcpy(c->elements[c->size], element, c->element_size);
    c->size++;
}

void container_remove(Container* c, size_t index) {
    if (index >= c->size) {
        fprintf(stderr, "Index out of range\n");
        return;
    }
    
    free(c->elements[index]);
    for (size_t i = index; i < c->size - 1; ++i) {
        c->elements[i] = c->elements[i + 1];
    }
    c->size--;
}

void* container_get(Container* c, size_t index) {
    if (index >= c->size) {
        fprintf(stderr, "Index out of range\n");
        return NULL;
    }
    return c->elements[index];
}

size_t container_size(Container* c) {
    return c->size;
}

int main() {
    // Пример с int
    Container* intContainer = container_create(sizeof(int));
    
    int a = 10, b = 20, c = 30;
    container_add(intContainer, &a);
    container_add(intContainer, &b);
    container_add(intContainer, &c);
    
    printf("Int container:\n");
    for (size_t i = 0; i < container_size(intContainer); ++i) {
        int* val = (int*)container_get(intContainer, i);
        printf("%d ", *val);
    }
    printf("\n");
    
    // Пример с string (char*)
    Container* strContainer = container_create(sizeof(char*));
    
    char* s1 = strdup("Hello");
    char* s2 = strdup("World");
    container_add(strContainer, &s1);
    container_add(strContainer, &s2);
    
    printf("String container:\n");
    for (size_t i = 0; i < container_size(strContainer); ++i) {
        char** s = (char**)container_get(strContainer, i);
        printf("%s ", *s);
    }
    printf("\n");
    
    // Освобождение памяти
    for (size_t i = 0; i < container_size(strContainer); ++i) {
        char** s = (char**)container_get(strContainer, i);
        free(*s);
    }
    
    container_destroy(intContainer);
    container_destroy(strContainer);
    
    return 0;
}