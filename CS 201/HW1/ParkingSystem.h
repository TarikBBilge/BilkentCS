//Name: Tarik Berkan Bilge
//ID: 22003392

#ifndef HW1_PARKINGSYSTEM_H
#define HW1_PARKINGSYSTEM_H

#include "Lot.h"

class ParkingSystem{
public:
    ParkingSystem();
    ~ParkingSystem();
    void createLot(int id, int rows, int columns);
    void removeLot(int id);
    void listLots();
    void lotContents(int id);
    void parkCar(int lotId, string location, string carType, int plateNumber);
    void findCar(int plateNumber);
    void removeCar(int plateNumber);

    int lotNum;
    char **mapArrPtr;
    Lot *lotArrPtr;
    int carNum;
    Car *carArrPtr;
// ...
//you may define additional member functions and data members, if necessary
};

#endif //HW1_PARKINGSYSTEM_H