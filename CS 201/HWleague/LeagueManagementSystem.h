//
// Created by Tarik Berkan Bilge on 27/10/2022.
//

#ifndef HWLEAGUE_LEAGUEMANAGEMENTSYSTEM_H
#define HWLEAGUE_LEAGUEMANAGEMENTSYSTEM_H

#include "Team.h"

class LeagueManagementSystem {
public:
    LeagueManagementSystem();
    ~LeagueManagementSystem();
    void addTeam( const string name, const int year );
    void removeTeam( const string name );
    void addPlayer( const string teamName, const string playerName,
                    const int jersey, const int salary );
    void removePlayer( const string teamName, const string playerName );
    void transferPlayer( const string playerName,
                         const string departTeamName, const string arriveTeamName );
    void showAllTeams() const;
    void showTeam( const string name ) const;
    void showPlayer( const string name ) const;

    int totalSalary( const string teamName ) const;
    int countTeamPlayer( const string teamName ) const;


    //variables and arrays
    int teamCount;
    Team *teamArrPtr;
    int playerCount;
    Player *playerArrPtr;
};

#endif //HWLEAGUE_LEAGUEMANAGEMENTSYSTEM_H