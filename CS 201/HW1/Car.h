//
// Created by Tarik Berkan Bilge on 22/03/2022.
//

#ifndef HW1_CAR_H
#define HW1_CAR_H
#include <iostream>

using namespace std;

class Car {
public:
    Car( int = 0 );

    int getPl() const;
    void setPl( int pl );

    int getLot() const;
    void setLot(int lot);

    Car& operator=( const Car& );

    const char getRowVal();
    void setRowVal(char rowVal);

    int getColVal() const;
    void setColVal(int colVal);

    char getUpperRowVal() const;
    void setUpperRowVal(char upperRowVal);

    const string &getType() const;
    void setType(const string &type);

private:
    int pl;
    int lot;
    string type;
    char rowVal;
    char upperRowVal;
    int colVal;
};


#endif //HW1_CAR_H
