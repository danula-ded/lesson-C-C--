#pragma once
#include "Vehicle.h"
#include "Engine.h"

class Car : public Vehicle, public Engine {
public:
    Car(int speed, int power);
}; 