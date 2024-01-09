//Name:Tarik Berkan Bilge
// ID: 22003392

#include "ParkingSystem.h"
#include "Car.h"

ParkingSystem::ParkingSystem() {
    lotNum = 0;
    lotArrPtr = NULL;

    carNum = 0;
    carArrPtr = NULL;
}

ParkingSystem::~ParkingSystem() {

}

void ParkingSystem::createLot( int id, int rows, int columns ) {
    lotNum++;
    if( lotArrPtr == NULL ) {
        lotArrPtr = new Lot[ 1 ]; //changes array
    }
    for( int i = 0; i < lotNum; i++ ){
        if( lotNum > 1 && lotArrPtr[ i ].getI() == id ){
            cout << "Cannot create the parking lot " << id << ", a lot with this ID already exists" << endl;
            lotNum--;
            break;
        }
        else if( i == ( lotNum - 1 ) ){
            if( rows > 12 || columns > 12 ){
                cout << "Cannot create the parking lot" << id << ", dimensions exceed acceptable bounds" << endl;
                lotNum--;
                break;
            }
            else {
                if ( lotNum > 1 ) {
                    Lot *resized = new Lot[ lotNum ]; //adds +1 to array size
                    for( int i = 0; i < lotNum; i++ ){
                        resized[ i ] = lotArrPtr[ i ];
                    }
                    delete []lotArrPtr;
                    lotArrPtr = resized;
                }
                Lot *lotPtr = new Lot( id, rows, columns ); //creates new lot

                lotArrPtr[ lotNum - 1 ] = *lotPtr; //adds the lot to array's last slot

                delete lotPtr; //delete lot from memory(?)

                cout << "Parking lot with ID " << id << " and dimensions (" << rows << "," << columns << ") has been added to the system" << endl;
            }
        }
    }
}

void ParkingSystem::removeLot( int id ) {
    for( int i = 0; i < lotNum; i++ ){
        if( lotArrPtr[ i ].getI() == id ){

            //removes car from the lot
            for( int k = 0; k < carNum; k++ ){
                if( carArrPtr[ k ].getLot() == id ){
                    removeCar( carArrPtr[ k ].getPl() );
                }
                else if( carArrPtr[ k ].getLot() != id && k == (carNum - 1) ){
                    break;
                }
            }

            //shows message
            cout << "Lot " << id << " has been successfully removed from the system" << endl;

            //resizes array
            Lot *temp = new Lot[ lotNum - 1 ]; //removes 1 from array size
            if( i == 0 ) {
                for( int j = 1; j < lotNum; j++ ){
                    temp[ j - 1 ] = lotArrPtr[ j ];
                }
                delete []lotArrPtr;
                lotArrPtr = temp;
            }
            else{
                for( int j = 0; j < i; j++ ){
                    temp[ j ] = lotArrPtr[ j ];
                }
                for( int j = (i + 1); j < lotNum; j++ ){
                    temp[ j - 1 ] = lotArrPtr[ j ];
                }
                delete []lotArrPtr;
                lotArrPtr = temp;
            }
            lotNum--;
            break;
        }
        else if( i == ( lotNum - 1 ) && lotArrPtr[ i ].getI() != id ){
            cout << "Lot " << id << " is not in the system" << endl;
        }
    }
}

void ParkingSystem::listLots() {
    if( lotArrPtr != NULL ) {
        cout << "List of lots: " << endl;
        for( int i = 0; i < lotNum; i++ ){
            //car count in the lot
            int carCount = 0;
            for( int j = 0; j < carNum; j++ ){
                if( carArrPtr[ j ].getLot() == lotArrPtr[ i ].getI() ){
                    carCount++;
                }
            }
            cout << "ID: " << lotArrPtr[ i ].getI() << ", Dim: (" << lotArrPtr[ i ].getC() << "," << lotArrPtr[ i ].getR()
                 << "), number of empty parking spaces: " << lotArrPtr[ i ].getC() * lotArrPtr[ i ].getR() - carCount << endl;
        }
    }
    else{
        cout << "No lots to list" << endl;
    }
}

void ParkingSystem::lotContents( int id ) {

    Lot currentLot;

    //finds the lot in lot array
    for( int i = 0; i < lotNum; i++ ){
        if( id == lotArrPtr[ i ].getI() ){
            currentLot = lotArrPtr[ i ];
        }
    }

    //allocates 2d array parking map
    mapArrPtr = new char*[ currentLot.getR() ];//creates lot rows
    for( int i = 0; i < currentLot.getR(); ++i ){
        mapArrPtr[ i ] = new char[ currentLot.getC() ];//creates lot columns
    }

    int emptySlots = currentLot.getR() * currentLot.getC();

    //fills map with +
    for( int i = 0; i < currentLot.getR(); i++ ){
        for( int j = 0; j < currentLot.getC(); j++ ){
            mapArrPtr[ i ][ j ] = '+';
        }
    }

    //fills map with cars
    for( int i = 0; i < carNum; i++ ){
        if( carArrPtr[ i ].getLot() == id ){
            //mapArrPtr[ ( carArrPtr[ i ].getRowVal() - 65 ) ][ ( carArrPtr[ i ].getColVal() ) ] = carArrPtr[ i ].getType().at( 0 );
            emptySlots--;
        }
    }

    cout << "ID: " << id << ", (" << currentLot.getC() <<"," << currentLot.getR() << "), empty slots: " << emptySlots <<
    ", parked cars: " << endl;
    cout << endl;

    //prints map
    for( int i = 0; i < currentLot.getR(); i++ ){
        for( int j = 0; j < currentLot.getC(); j++ ){ //prints lot rows
            if( i == 0 && j == 0 ) {
                cout << " "; //prints " " for corner
            }
            else if( i > 0 && j == 0 ){
                cout << (char)( i + 64 ); //prints row letters
            }
            else if( i == 0 && j > 0 ){
                cout << j; //prints column numbers
            }
            else if( i > 0 && j > 0 ){
                cout << mapArrPtr[ i - 1 ][ j - 1 ]; //prints lot contents
            }
        }
        cout << endl;
    }
}

void ParkingSystem::parkCar( int lotId, string location, string carType, int plateNumber ) {

    carNum++;
    //location variables
    char rowLoc = location.at( 0 );
    char charColLoc = location.at( 1 );
    int colLoc = charColLoc - '0';

    //checks if there is a lot with the lotId
    for( int j = 0; j < lotNum; j++ ){
        //creates car and allocates in array
        if( carArrPtr == NULL ){
            carArrPtr = new Car[ 1 ];
        }
        //if lot exists in lot array
        if( lotId == lotArrPtr[ j ].getI() ){
            for( int i = 0; i < carNum; i++ ){
                if( carNum > 1 && carArrPtr[ i ].getPl() == plateNumber ){ //if there is already a same car in array
                    carNum--;
                    break;
                }
                else if( carNum > 1 && carArrPtr[ i ].getLot() == lotId && carArrPtr[ i ].getRowVal() == rowLoc &&
                         carArrPtr[ i ].getColVal() == colLoc && carType == "a" ){ //if full light car
                    cout << "Cannot park light-duty car with number plate " << plateNumber
                         << " at location " << location << ", already occupied" << endl;
                    carNum--;
                    break;
                }
                else if( carNum > 1 && carArrPtr[ i ].getLot() == lotId && carArrPtr[ i ].getUpperRowVal() == rowLoc &&
                         carArrPtr[ i ].getColVal() == colLoc && carType == "a" ){ //if light car x heavy car upper
                    cout << "Cannot park light-duty car with number plate " << plateNumber
                         << " at location " << location << ", already occupied" << endl;
                    carNum--;
                    break;
                }
                else if( carNum > 1 && carArrPtr[ i ].getLot() == lotId && carArrPtr[ i ].getRowVal() == rowLoc &&
                         carArrPtr[ i ].getColVal() == colLoc && carType == "b" ){ //if full heavy car
                    cout << "Cannot park heavy-duty car with number plate " << plateNumber
                         << " at location " << location << ", already occupied" << endl;
                    carNum--;
                    break;
                }
                else if( carNum > 1 && carArrPtr[ i ].getLot() == lotId && carArrPtr[ i ].getUpperRowVal() == rowLoc &&
                         carArrPtr[ i ].getColVal() == colLoc && carType == "b" ){//if heavy car x heavy car upper
                    cout << "Cannot park heavy-duty car with number plate " << plateNumber
                         << " at location " << location << ", already occupied" << endl;
                    carNum--;
                    break;
                }
                else if( carNum > 1 && carArrPtr[ i ].getLot() == lotId && carArrPtr[ i ].getRowVal() == (char)( rowLoc - 1 ) &&
                         carArrPtr[ i ].getColVal() == colLoc && carType == "b" ){//if heavy car upper x any car
                    cout << "Cannot park heavy-duty car with number plate " << plateNumber
                         << " at location " << location << ", already occupied" << endl;
                    carNum--;
                    break;
                }
                else if( carNum > 1 && carType == "b" && rowLoc == 'A' ){ //if heavy car in last row
                    cout << "Cannot park heavy-duty car with number plate " << plateNumber
                         << " at location " << location << ", not enough space" << endl;
                    carNum--;
                    break;
                }
                else if( i == ( carNum - 1 ) ){

                    if ( carNum > 0 ) {
                        Car *temp = new Car[ carNum ]; //adds +1 to array size
                        for( int i = 0; i < carNum; i++ ){
                            temp[ i ] = carArrPtr[ i ];
                        }
                        delete []carArrPtr;
                        carArrPtr = temp;
                    }
                    Car *carPtr = new Car( plateNumber ); //creates new car
                    //parks the car to the specified lot and location
                    //carPtr->setPl( plateNumber );
                    carPtr->setLot( lotId );
                    carPtr->setRowVal( rowLoc );
                    carPtr->setColVal( colLoc );
                    carPtr->setType( carType );

                    if( carType == "b" ){
                        carPtr->setUpperRowVal( rowLoc - 1 );
                    }
                    else{
                        carPtr->setUpperRowVal( '\0' );
                    }

                    carArrPtr[ carNum - 1 ] = *carPtr; //adds the car to array's last slot

                    if( carType == "a" ) {
                        cout << "Light-duty car with number plate " << carArrPtr[ carNum - 1 ].getPl() <<
                             " has been parked at location " << location << ", lot " << lotId << endl;
                    }
                    else{
                        cout << "Heavy-duty car with number plate " << carArrPtr[ carNum - 1 ].getPl() <<
                             " has been parked at location " << location << ", lot " << lotId << endl;
                    }

                    delete carPtr; //delete car from memory
                }
            }
            break;
        }
        //if lot does not exist in lot array
        else if( j == ( lotNum - 1 ) ){
            cout << "Lot " << lotId << " is not in the system" << endl;
            carNum--;
            break;
        }
    }
}

void ParkingSystem::findCar( int plateNumber ) {
    for( int i = 0; i < carNum; i++ ){
        if( plateNumber == carArrPtr[ i ].getPl() ){
            if( carArrPtr[ i ].getType() == "a" ) {
                cout << "Light-duty car with number plate " << plateNumber << " is at location "
                << carArrPtr[ i ].getRowVal() <<""<< carArrPtr[ i ].getColVal()  <<", lot "<< carArrPtr[ i ].getLot() << endl;
                break;
            }
            else{
                cout << "Heavy-duty car with number plate " << plateNumber << " is at location "
                     << carArrPtr[ i ].getRowVal() <<""<< carArrPtr[ i ].getColVal()  <<", lot "<< carArrPtr[ i ].getLot() << endl;
                break;
            }
        }
        else if( i == ( carNum - 1 ) && plateNumber != carArrPtr[ i ].getPl() ){
            cout << "The car with number plate " << plateNumber << " is not in the system" << endl;
        }
    }
}

void ParkingSystem::removeCar( int plateNumber ) {
    for( int i = 0; i < carNum; i++ ){
        if( carArrPtr[ i ].getPl() == plateNumber ){
            //shows message
            if( carArrPtr[ i ].getType() == "a" ) {
                cout << "Light-duty car with number plate " <<plateNumber<<
                " car has been removed from slot "<<carArrPtr[ i ].getRowVal() <<
                carArrPtr[ i ].getColVal() <<", lot "<<carArrPtr[ i ].getLot() << endl;
            }
            else if( carArrPtr[ i ].getType() == "b" ){
                cout << "Heavy-duty car with number plate " <<plateNumber<<
                     " car has been removed from slot "<<carArrPtr[ i ].getRowVal() <<
                     carArrPtr[ i ].getColVal() <<", lot "<<carArrPtr[ i ].getLot() << endl;
            }
            //resizes array
            Car *temp = new Car[ carNum - 1 ]; //removes 1 from array size
            if( i == 0 ) {
                for( int j = 1; j < carNum; j++ ){
                    temp[ j - 1 ] = carArrPtr[ j ];
                }
                delete []carArrPtr;
                carArrPtr = temp;
            }
            else{
                for( int j = 0; j < i; j++ ){
                    temp[ j ] = carArrPtr[ j ];
                }
                for( int j = (i + 1); j < carNum; j++ ){
                    temp[ j - 1 ] = carArrPtr[ j ];
                }
                delete []carArrPtr;
                carArrPtr = temp;
            }
            carNum--;
            break;
        }
        else if( i == ( carNum - 1 ) && carArrPtr[ i ].getPl() != plateNumber ){
            cout << "The car with number plate " << plateNumber << " is not in the system" << endl;
        }
    }
}