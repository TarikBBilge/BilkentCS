//
// Created by Tarik Berkan Bilge on 22/03/2022.
//

#include "Car.h"

Car::Car( int plate ) {
    pl = plate;
    /*lot = this->lot;
    upperRowVal = this->upperRowVal;
    rowVal = this->rowVal;
    colVal = this ->colVal;*/
}

int Car::getPl() const {
    return pl;
}

void Car::setPl(int pl) {
    Car::pl = pl;
}

char Car::getUpperRowVal() const {
    return upperRowVal;
}

void Car::setUpperRowVal(char upperRowVal) {
    Car::upperRowVal = upperRowVal;
}

const char Car::getRowVal() {
    return rowVal;
}

void Car::setRowVal(char rowVal) {
    Car::rowVal = rowVal;
}

int Car::getColVal() const {
    return colVal;
}

void Car::setColVal(int colVal) {
    Car::colVal = colVal;
}

int Car::getLot() const {
    return lot;
}

void Car::setLot(int lot) {
    Car::lot = lot;
}

const string &Car::getType() const {
    return type;
}

void Car::setType(const string &type) {
    Car::type = type;
}

Car &Car::operator=( const Car &right ){
    if ( &right != this ) {
        pl = right.pl;
        lot = right.lot;
        rowVal = right.rowVal;
        colVal = right.colVal;
    }
    return *this;
}