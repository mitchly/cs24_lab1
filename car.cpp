// Michelle Ly (3774189)
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

Car::Car(){ //heap for pointers, stacks for everything else
    manufacturer = NULL;
    model = NULL;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
    manufacturer = new char[strlen(manufacturerName) + 1];
    model = new char[strlen(modelName) + 1];

    strcpy(manufacturer, manufacturerName);
    strcpy(model, modelName);
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    backseatDoors = backseatDoorDesign;
    seatCount = numSeats;
}
Car::Car(Car const& o){
    manufacturer = new char[strlen(o.getManufacturer()) + 1];
    model = new char[strlen(o.getModel()) + 1];

    strcpy(manufacturer, o.getManufacturer());
    strcpy(model, o.getModel());
    zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    headonDragCoeff = o.getStats().headonDragCoeff;
    horsepower = o.getStats().horsepower;
    backseatDoors = o.getBackseatDoors();
    seatCount = o.getSeatCount();
}
Car::~Car(){
    delete[] manufacturer;
    delete[] model;
}
Car& Car::operator=(Car const& o){ //set the values of the variables in the current object to be those in ‘o’
    if (this != &o) {  // do for manu and model
        manufacturer = nullptr;
        model = nullptr;
        return *this;
    }
    return *this;
}
char const* Car::getManufacturer() const{
    return manufacturer;
}
char const* Car::getModel() const{
    return model;
}
PerformanceStats Car::getStats() const{
    struct PerformanceStats temp{
        horsepower,
        zeroToSixtyNs,
        headonDragCoeff
    };
    return temp;
}
uint8_t Car::getSeatCount() const{
    return seatCount;
}
DoorKind Car::getBackseatDoors() const{
    return backseatDoors;
}
void Car::manufacturerChange(char const* const newManufacturer){
    delete[] manufacturer;
    manufacturer = new char[strlen(newManufacturer) + 1];
    strcpy(manufacturer, newManufacturer);
}
void Car::modelNameChange(char const* const newModelName){
    delete[] model;
    model = new char[strlen(newModelName) + 1];
    strcpy(model, newModelName);
}
void Car::reevaluateStats(PerformanceStats newStats){
    this->horsepower = newStats.horsepower;
    this->zeroToSixtyNs = newStats.zeroToSixtyNs;
    this->headonDragCoeff = newStats.headonDragCoeff;
}
void Car::recountSeats(uint8_t newSeatCount){
    this->seatCount = newSeatCount;
}
void Car::reexamineDoors(DoorKind newDoorKind){
    this->backseatDoors = newDoorKind;
}