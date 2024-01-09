//
// Created by Tarik Berkan Bilge on 21/03/2022.
//

#ifndef HW1_LOT_H
#define HW1_LOT_H
#include <iostream>
#include "Car.h"

using namespace std;

class Lot {
public:
    Lot( int = 0, int = 0, int = 0 );
    ~Lot();

    int getI() const;
    int getR() const;
    int getC() const;

    Lot& operator=( const Lot& );

    //string **mapArrPtr;
    //void parkingMap( Lot id );

private:
    int i, r, c;
};


#endif //HW1_LOT_H