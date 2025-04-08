#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char model[50];
    int year;
    void (*display)(void*);
} Car;

void Car_display(void* self) {
    Car* car = (Car*)self;
    printf("Car: %s, Year: %d\n", car->model, car->year);
}

Car* Car_create(const char* model, int year) {
    Car* car = (Car*)malloc(sizeof(Car));
    strcpy(car->model, model);
    car->year = year;
    car->display = Car_display;
    return car;
}

typedef struct {
    Car base;
    double battery_capacity;
} ElectricCar;

void ElectricCar_display(void* self) {
    ElectricCar* ecar = (ElectricCar*)self;
    printf("Electric Car: %s, Year: %d, Battery: %.1f kWh\n", 
           ecar->base.model, ecar->base.year, ecar->battery_capacity);
}

ElectricCar* ElectricCar_create(const char* model, int year, double battery) {
    ElectricCar* ecar = (ElectricCar*)malloc(sizeof(ElectricCar));
    strcpy(ecar->base.model, model);
    ecar->base.year = year;
    ecar->base.display = ElectricCar_display;
    ecar->battery_capacity = battery;
    return ecar;
}

int main() {
    Car* myCar = Car_create("Toyota Camry", 2020);
    myCar->display(myCar);

    ElectricCar* myECar = ElectricCar_create("Tesla Model 3", 2023, 75.5);
    myECar->base.display(myECar);

    free(myCar);
    free(myECar);

    return 0;
}