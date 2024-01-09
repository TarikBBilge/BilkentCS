//
// Created by Tarik Berkan Bilge on 27/10/2022.
//
#include "Player.h"

Player::Player(){}

Player::~Player() {}

string Player::getName() const{
    return name;
}

void Player::setName( string pName ){
    name = pName;
}

string Player::getTeamName() const {
    return teamName;
}
void Player::setTeamName(string teamName) {
    Player::teamName = teamName;
}

int Player::getJerseyNum() const {
    return jerseyNum;
}
void Player::setJerseyNum(int jerseyNum) {
    Player::jerseyNum = jerseyNum;
}

int Player::getSalary() const {
    return salary;
}
void Player::setSalary(int salary) {
    Player::salary = salary;
}

Player &Player::operator=(const Player &right) {
    if( &right != this ){
        name = right.name;
        teamName = right.teamName;
        jerseyNum = right.jerseyNum;
        salary = right.salary;
    }
    return *this;
}
