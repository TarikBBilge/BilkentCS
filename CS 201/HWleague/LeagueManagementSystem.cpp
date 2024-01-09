//
// Created by Tarik Berkan Bilge on 27/10/2022.
//
#include "LeagueManagementSystem.h"

//constructor
LeagueManagementSystem::LeagueManagementSystem() {
    teamCount = 0;
    teamArrPtr = NULL;

    playerCount = 0;
    playerArrPtr = NULL;
}

//destructor
LeagueManagementSystem:: ~LeagueManagementSystem(){
    delete []teamArrPtr;
    delete []playerArrPtr;

    teamArrPtr = NULL;
    playerArrPtr = NULL;
}

void LeagueManagementSystem::addTeam(const string name, const int year) {

    //add the first team
    if( teamArrPtr == NULL ){
        teamArrPtr = new Team[ 1 ];

        Team *tempT = new Team(); //create a team as named in parameter
        tempT->setFound(year); //set team's foundation year
        tempT->setName(name);

        teamArrPtr[ 0 ] = *tempT; //add the team to the teams array
        delete tempT; //delete the temp object

        cout << "Added team " << name << "." << endl;
        teamCount++;
    }
    else {
        //check if the team already exists
        for (int i = 0; i < teamCount; i++) {
            if ( teamArrPtr[i].getName() == name ) {
                //teamCount--;
                cout << "Cannot add team. Team " << name << " already exists." << endl;
                break;
            } else if (i == teamCount - 1) { //if it is not previously added
                //increment the team size
                Team *resizedT = teamArrPtr;
                teamArrPtr = new Team[teamCount + 1];

                for (int j = 0; j < teamCount; j++) {
                    teamArrPtr[j] = resizedT[j];
                }

                Team *tempT = new Team(); //create a team as named in parameter
                tempT->setFound(year); //set team's foundation year
                tempT->setName(name); //set team's name

                teamArrPtr[teamCount] = *tempT; //add the team to the teams array
                delete tempT; //delete the temp object

                cout << "Added team " << teamArrPtr[teamCount].getName() << "." << endl;
                teamCount++;
                delete []resizedT;
                resizedT = NULL;
                break;
            }
        }
    }
}

void LeagueManagementSystem::removeTeam( const string name ) {
    int removeT;
    for( int i = 0; i < teamCount; i++ ){
        if( teamArrPtr[ i ].getName() == name ){
            removeT = i;
            //remove team
            Team *resizedT = teamArrPtr;
            teamArrPtr = new Team[ teamCount - 1 ];
            for( int j = 0; j < teamCount - 1; j++ ){
                if( j >= removeT ){
                    teamArrPtr[ j ] = resizedT[ j + 1 ];
                }
                else{
                    teamArrPtr[j] = resizedT[j];
                }
            }

            cout << "Removed team " << name << "." << endl;
            teamCount--;

            //remove players in the team
            for( int k = 0; k < playerCount; k++ ){
                if( playerArrPtr[ k ].getTeamName() == name ){
                    removePlayer( name, playerArrPtr[ k ].getTeamName()  );
                }
            }
            delete [] resizedT;
            resizedT = NULL;
            goto label;
        }
        else if( i == teamCount - 1 ){
            cout << "Cannot remove team. Team " << name << " does not exist." << endl;
        }
    }
    label:{};
}

void
LeagueManagementSystem::addPlayer(const string teamName, const string playerName, const int jersey, const int salary) {

    //add the first player
    if( playerArrPtr == NULL ){
        playerArrPtr = new Player[ 1 ];

        Player *tempP = new Player(  );
        tempP->setTeamName( teamName );
        tempP->setJerseyNum ( jersey );
        tempP->setSalary( salary );
        tempP->setName( playerName );

        playerArrPtr[ 0 ] = *tempP; //add player to the player array

        cout << "Added player " << playerName << " to team " << teamName << endl;
        delete tempP;
        playerCount++;
    }
    else {
        for (int i = 0; i < teamCount; i++) {
            //check if the team exists
            if (teamArrPtr[i].getName() == teamName){
                //check if the jersey number already exist in this team
                for (int j = 0; j < playerCount; j++){
                    if (playerArrPtr[i].getTeamName() == teamName && playerArrPtr[i].getJerseyNum() == jersey) {
                        cout << "Cannot add player. Jersey number " << jersey << " already exists in team " << teamName
                             << endl;
                        //playerCount--;
                        goto label;
                    }
                        //add player
                    else if (j == playerCount - 1){
                        //increment the player size
                        Player *resizedP = playerArrPtr;
                        playerArrPtr = new Player[playerCount + 1];

                        for (int k = 0; k < playerCount; k++) {
                            playerArrPtr[k] = resizedP[k];
                        }

                        Player *tempP = new Player();
                        tempP->setTeamName(teamName);
                        tempP->setJerseyNum(jersey);
                        tempP->setSalary(salary);
                        tempP->setName(playerName);

                        playerArrPtr[playerCount] = *tempP; //add player to the player array
                        delete tempP;

                        cout << "Added player " << playerName << " to team " << teamName << endl;
                        playerCount++;
                        delete []resizedP;
                        resizedP = NULL;

                        goto label; //exit the loop
                    }
                }
                goto label;
            }
            else if (i == teamCount - 1){ //if the team does not exist
                cout << "Cannot add player. Team " << teamName << " does not exist." << endl;
                if (playerCount == 1) {
                    playerArrPtr = NULL;
                }
                goto label;
            }
        }
    }
    label:{};
}

void LeagueManagementSystem::removePlayer(const string teamName, const string playerName) {
    int removeP;
    for( int i = 0; i < playerCount; i++ ){
        if( playerArrPtr[ i ].getTeamName() == teamName ){
            if( playerArrPtr[ i ].getName() == playerName ){
                removeP = i;
                //remove player from the array
                Player *resizedP = playerArrPtr;
                playerArrPtr = new Player[ playerCount - 1 ];
                for( int j = 0; j < playerCount - 1; j++ ){
                    //pass the removed player
                    if( j >= removeP ) {
                        playerArrPtr[ j ] = resizedP[ j + 1 ];
                    }
                    else {
                        playerArrPtr[j] = resizedP[j];
                    }
                }

                cout << "Removed player " << playerName << " from team " << teamName << "." << endl;
                playerCount--;
                delete []resizedP;
                resizedP = NULL;
                goto label;
            }
            else if( i == playerCount - 1 ){
                cout << "Cannot remove player. Player " << playerName << " does not exist." << endl;
                goto label;
            }
        }
        else if( i == playerCount - 1 ){
            cout << "Cannot remove player. Team " << teamName << " does not exist." << endl;
        }
    }
    label:{};
}

void LeagueManagementSystem::transferPlayer(const string playerName, const string departTeamName,
                                            const string arriveTeamName) {
    for( int i = 0; i < playerCount; i++ ){
        if( playerArrPtr[ i ].getName() == playerName ){    //check if the player exists
            if( playerArrPtr[ i ].getTeamName() == departTeamName ){    //check if the player in the departTeam
                for( int j = 0; j < teamCount; j++ ){
                    if( teamArrPtr[ j ].getName() == arriveTeamName ){  //check if the arriveTeam exists
                        for( int k = 0; k < playerCount; k++ ){
                            if( playerArrPtr[ k ].getTeamName() == arriveTeamName &&
                            playerArrPtr[ i ].getJerseyNum() == playerArrPtr[ k ].getJerseyNum() ){ //check arrival team jersey numbers
                                cout << "Cannot transfer player. Jersey number " << playerArrPtr[ i ].getJerseyNum()
                                <<" already exists in team " << arriveTeamName << endl;
                                goto label;
                            }
                            else if( k == playerCount - 1 ){    //everything is fine to transfer
                                playerArrPtr[ i ].setTeamName( arriveTeamName );
                                cout << "Transferred player " <<playerName << " from team " << departTeamName <<
                                " to team " << arriveTeamName << "." << endl;
                                goto label;
                            }
                        }
                    }
                    else if( j == teamCount - 1 ){
                        cout << "Cannot transfer player. Team " << arriveTeamName <<" does not exist." << endl;
                        goto label;
                    }
                }
            }
            else{
                cout << "Cannot transfer player. Team " << departTeamName <<" does not exist." << endl;
                goto label;
            }
        }
        else if( i == playerCount - 1 ){
                cout << "Cannot transfer player. Player " << playerName << " does not exist." << endl;
                goto label;
        }
    }
    label:{};
}

int LeagueManagementSystem::totalSalary( const string teamName ) const{
    int sum = 0;
    for( int i = 0; i < playerCount; i++ ){
        if( playerArrPtr[ i ].getTeamName() == teamName ){
            sum += playerArrPtr[ i ].getSalary();
        }
    }
    return sum;
}

int LeagueManagementSystem::countTeamPlayer( const string teamName ) const {
    int sum = 0;
    for( int i = 0; i < playerCount; i++ ){
        if( playerArrPtr[ i ].getTeamName() == teamName ){
            sum++;
        }
    }
    return sum;
}

void LeagueManagementSystem::showAllTeams() const {
    cout << "Teams in the league management system:" << endl;
    if( teamCount > 0 ) {
        for (int i = 0; i < teamCount; i++) {
            Team t = teamArrPtr[i];
            cout << t.getName() << ", " << t.getFound() << ", " << countTeamPlayer(t.getName()) <<
                 " players, " << totalSalary(t.getName()) << " TL total salary" << endl;
        }
    }
    else{
        cout << "None" << endl;
    }
}

void LeagueManagementSystem::showTeam(const string name) const {

    for( int i = 0; i < teamCount; i++ ){
        if( teamArrPtr[ i ].getName() == name ) {
            Team t = teamArrPtr[i];
            cout << "Team:" << endl;
            cout << t.getName() << ", " << t.getFound() << ", " << countTeamPlayer(t.getName()) <<
                 " players, " << totalSalary(t.getName()) << " TL total salary" << endl;

            cout << "Player:" << endl;
            for( int j = 0; j < playerCount; j++ ){
                if( playerArrPtr[ j ].getTeamName() == name ){
                    Player p = playerArrPtr[ j ];
                    cout << p.getName() << ", jersey " << p.getJerseyNum() << ", " << p.getSalary() << " TL salary" << endl;
                }
            }
            goto label;
        }
        else if( i == teamCount - 1 ){
            cout << "Team " << name << " does not exist." << endl;
        }
    }
    label:{};
}

void LeagueManagementSystem::showPlayer(const string name) const {

    for( int i = 0; i < playerCount; i++ ){
        if( playerArrPtr[ i ].getName() == name ){
            Player p = playerArrPtr[ i ];
            cout << "Player:" << endl;
            cout << p.getName() << ", jersey " << p.getJerseyNum() << ", " << p.getSalary() << " TL salary" << endl;
            cout << "Plays in team " << p.getTeamName() << "." << endl;
            break;
        }
        else if( i == playerCount - 1 ){
            cout << "Player " << name << " does not exist." << endl;
        }
    }
}