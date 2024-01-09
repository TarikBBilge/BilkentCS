//
// Created by Tarik Berkan Bilge on 11/12/2022.
//

#include "Movie.h"

Movie::Movie(const int id) {
    this ->movieId = id;
}

Movie::~Movie() {

}

const int Movie::getId() const {
    return this -> movieId;
}

void Movie::setId(const int id) {
    this -> movieId = id;
}

const int Movie::getCopies() const {
    return this -> copy;
}

void Movie::setCopies(const int copyCount) {
    this -> copy = copyCount;
}

const int Movie::getSub() const {
    return this -> subId;
}

void Movie::setSub(const int subId) {
    this -> subId = subId;
}
