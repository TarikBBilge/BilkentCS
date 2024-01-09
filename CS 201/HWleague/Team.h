//
// Created by Tarik Berkan Bilge on 27/10/2022.
//

#ifndef HWLEAGUE_TEAM_H
#define HWLEAGUE_TEAM_H

#include <iostream>
#include "Player.h"

class Team{
public:
    Team();
    ~Team();

    string getName() const;
    void setName( string name );

    int getFound() const;
    void setFound( int year );

    Team& operator=(const Team& );

private:
    string name; //team name
    int found; //the year team founded
};

#endif //HWLEAGUE_TEAM_H