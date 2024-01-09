//
// Created by Tarik Berkan Bilge on 21/03/2022.
//

#include "Lot.h"

Lot::Lot( int id, int rows, int column ) {
    i = id;
    r = rows;
    c = column;
}

Lot::~Lot(){

}

int Lot::getI() const {
    return i;
}

int Lot::getR() const {
    return r;
}

int Lot::getC() const {
    return c;
}

/*void Lot::parkingMap( Lot id ) {

    //allocates map 2d array
    mapArrPtr = new string*[ id.getR() ];

    for( int i = 0; i < id.getR(); ++i ){
        mapArrPtr[ i ] = new string[ id.getC() ];
    }

    switch( id.getR() ){
        case 0: *mapArrPtr = (string *) "A"; break;
        case 1: *mapArrPtr = (string *) "B"; break;
        case 2: *mapArrPtr = (string *) "C"; break;
        case 3: *mapArrPtr = (string *) "D"; break;
        case 4: *mapArrPtr = (string *) "E"; break;
        case 5: *mapArrPtr = (string *) "F"; break;
        case 6: *mapArrPtr = (string *) "G"; break;
        case 7: *mapArrPtr = (string *) "H"; break;
        case 8: *mapArrPtr = (string *) "I"; break;
        case 9: *mapArrPtr = (string *) "J"; break;
        case 10: *mapArrPtr = (string *) "K"; break;
        case 11: *mapArrPtr = (string *) "L"; break;
    }

}*/

Lot &Lot::operator=( const Lot &right ){
    if ( &right != this ) {
        i = right.i;
        r = right.r;
        c = right.c;
    }
    return *this;
}