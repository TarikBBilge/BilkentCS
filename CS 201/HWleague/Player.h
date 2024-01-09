//
// Created by Tarik Berkan Bilge on 27/10/2022.
//

#ifndef HWLEAGUE_PLAYER_H
#define HWLEAGUE_PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player{
public:
    Player();
    ~Player();

    string getName() const;
    void setName( string name );

    string getTeamName() const;
    void setTeamName( string teamName );

    int getJerseyNum() const;
    void setJerseyNum( int jerseyNum );

    int getSalary() const;
    void setSalary( int salary );

    Player &operator=(const Player& );

private:
    string name;
    string teamName;
    int jerseyNum;
    int salary;
};

#endif //HWLEAGUE_PLAYER_H