//
// Created by Tarik Berkan Bilge on 27/10/2022.
//
#include "Team.h"

Team::Team(){
}

Team::~Team() {}

string Team::getName() const {
    return name;
}

void Team::setName( string tName ) {
    Team::name = tName;
}

int Team::getFound() const {
    return found;
}

void Team::setFound( int year ) {
    Team::found = year;
}

Team &Team::operator=(const Team &right) {
    if ( &right != this ) {
        name = right.name;
        found = right.found;
    }
    return *this;
}
