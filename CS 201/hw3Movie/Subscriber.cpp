//
// Created by Tarik Berkan Bilge on 11/12/2022.
//

#include "Subscriber.h"

Subscriber::Subscriber(const int id) {
    this-> subId = id;
}

Subscriber::~Subscriber() {}

const int Subscriber::getId() const {
    return this -> subId;
}

void Subscriber::setId(const int id) {
    this -> subId = id;
}

const int Subscriber::getMovie() const {
    return this -> rented;
}

void Subscriber::setMovie(const int rented) {
    this -> rented = rented;
}

void Subscriber::operator=(const Subscriber &right) {
    this -> subId  = right.subId;
    this -> rented = right.rented;
}
