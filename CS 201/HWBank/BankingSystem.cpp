/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "BankingSystem.h"
#include "iomanip"

BankingSystem::BankingSystem() {
    branchPtr = NULL;
    customerPtr = NULL;
    accountPtr =  NULL;
    bArrSize = 0;
    cArrSize = 0;
    aArrSize = 0;
    uAccountId = 0;
}

BankingSystem::~BankingSystem() {
    delete[] branchPtr;
    delete[] customerPtr;
    delete[] accountPtr;
}

void BankingSystem::addBranch(const int branchId, const string branchName) {
    if( bArrSize == 0 ){    //add the first branch
        branchPtr = new Branch[1];
        Branch branchObj( branchId, branchName );
        branchPtr[ 0 ] = branchObj;

        cout << "Branch " << branchId << " has been added" << endl;
        bArrSize++;
    }
    else{
        for( int i = 0; i < bArrSize; i++ ){
            //if the branch already exists
            if( branchId == branchPtr[ i ].getBranchId() ){
                cout << "Branch " << branchId << " already exists" << endl;
                return;
            }
        }
        //add the new branch
        Branch* tempPtr = new Branch[ bArrSize + 1 ];
        for( int i = 0; i < bArrSize; i++ ){
            tempPtr[ i ] = branchPtr[ i ];
        }
        Branch branchObj( branchId, branchName );
        tempPtr[ bArrSize ] = branchObj;
        delete[] branchPtr;
        branchPtr = tempPtr;

        cout << "Branch " << branchId << " has been added" << endl;
        bArrSize++;
    }
}

void BankingSystem::deleteBranch(const int branchId) {
    //delete accounts in this branch
    for( int i = 0; i < aArrSize; i++ ){
        if( accountPtr[ i ].getBranchId() == branchId ){
            if( aArrSize == 1 ){
                delete[] accountPtr;
                accountPtr = NULL;
            }
            else {
                Account *tempPtr = new Account[aArrSize - 1];
                //before the deleted object
                for (int j = 0; j < i; j++) {
                    tempPtr[j] = accountPtr[j];
                }
                //after the deleted object
                for (int k = i + 1; k < aArrSize; k++) {
                    tempPtr[k - 1] = accountPtr[k];
                }
                delete[] accountPtr;
                accountPtr = tempPtr;
            }
            i--;
            aArrSize--;
        }
    }

    //delete branch
    for( int i = 0; i < bArrSize; i++ ){
        if( branchPtr[ i ].getBranchId() == branchId ){
            if( bArrSize == 1 ){
                delete[] branchPtr;
                branchPtr = NULL;
            }
            else {
                Branch *tempPtr = new Branch[bArrSize - 1];
                //before the deleted object
                for (int j = 0; j < i; j++) {
                    tempPtr[j] = branchPtr[j];
                }
                //after the deleted object
                for (int k = i + 1; k < bArrSize; k++) {
                    tempPtr[k - 1] = branchPtr[k];
                }
                delete[] branchPtr;
                branchPtr = tempPtr;
            }

            cout << "Branch " << branchId << " has been deleted" << endl;
            bArrSize--;
            return;
        }
    }
    cout << "Branch " << branchId << " does not exist" << endl;
}

void BankingSystem::addCustomer(const int customerId, const string customerName) {
    if( cArrSize == 0 ){    //add the first branch
        customerPtr = new Customer[1];
        Customer customerObj( customerId, customerName );
        customerPtr[ 0 ] = customerObj;

        cout << "Customer " << customerId << " has been added" << endl;
        cArrSize++;
    }
    else{
        for( int i = 0; i < cArrSize; i++ ){
            //if the customer already exists
            if( customerId == customerPtr[ i ].getCustomerId() ){
                cout << "Customer " << customerId << " already exists" << endl;
                return;
            }
        }
        //add the new customer
        Customer* tempPtr = new Customer[ cArrSize + 1 ];
        for( int i = 0; i < cArrSize; i++ ){
            tempPtr[ i ] = customerPtr[ i ];
        }
        Customer customerObj( customerId, customerName );
        tempPtr[ cArrSize ] = customerObj;
        delete[] customerPtr;
        customerPtr = tempPtr;

        cout << "Customer " << customerId << " has been added" << endl;
        cArrSize++;
    }
}

void BankingSystem::deleteCustomer(const int customerId) {
    //delete accounts of this customer
    for( int i = 0; i < aArrSize; i++ ){
        if( accountPtr[ i ].getCustomerId() == customerId ){
            if( aArrSize == 1 ){
                delete[] accountPtr;
                accountPtr = NULL;
            }
            else {
                Account *tempPtr = new Account[aArrSize - 1];
                //before the deleted object
                for (int j = 0; j < i; j++) {
                    tempPtr[j] = accountPtr[j];
                }
                //after the deleted object
                for (int k = i + 1; k < aArrSize; k++) {
                    tempPtr[k - 1] = accountPtr[k];
                }
                delete[] accountPtr;
                accountPtr = tempPtr;
            }
            i--;
            aArrSize--;
        }
    }

    //delete customer
    for( int i = 0; i < cArrSize; i++ ){
        if( customerPtr[ i ].getCustomerId() == customerId ){
            if( cArrSize == 1 ){
                delete[] customerPtr;
                customerPtr = NULL;
            }
            else {
                Customer *tempPtr = new Customer[cArrSize - 1];
                //before the deleted object
                for (int j = 0; j < i; j++) {
                    tempPtr[j] = customerPtr[j];
                }
                //after the deleted object
                for (int k = i + 1; k < cArrSize; k++) {
                    tempPtr[k - 1] = customerPtr[k];
                }
                delete[] customerPtr;
                customerPtr = tempPtr;
            }

            cout << "Customer " << customerId << " has been deleted" << endl;
            cArrSize--;
            return;
        }
    }
    cout << "Customer " << customerId << " does not exist" << endl;
}

int BankingSystem::addAccount(const int branchId, const int customerId, const double amount) {
    for( int i = 0; i < bArrSize; i++ ){
        //if the branch exists
        if( branchPtr[ i ].getBranchId() == branchId ){
            for( int j = 0; j < cArrSize; j++ ){
                //if the customer exists
                if( customerPtr[ j ].getCustomerId() == customerId ){
                    //add the account
                    uAccountId++;
                    Account* tempPtr = new Account[ aArrSize + 1 ];
                    for( int k = 0; k < aArrSize; k++ ){
                        tempPtr[ k ] = accountPtr[ k ];
                    }
                    Account accountObj( branchId, customerId, amount );
                    accountObj.setAccId( uAccountId );

                    tempPtr[aArrSize] = accountObj;
                    delete[] accountPtr;
                    accountPtr = tempPtr;

                    cout << "Account " << uAccountId << " added for customer " << customerId << " at branch " << branchId << endl;
                    aArrSize++;
                    return uAccountId;
                }
            }
            cout << "Customer " << customerId << " does not exist" << endl;
            return -1;
        }
    }
    cout << "Branch " << branchId << " does not exist" << endl;
    return -1;
}

void BankingSystem::deleteAccount(const int accountId) {
    for( int i = 0; i < aArrSize; i++ ){
        if( accountPtr[ i ].getAccId() == accountId ){
            if( aArrSize == 1 ){
                delete[] accountPtr;
                accountPtr = NULL;
            }
            else {
                Account *tempPtr = new Account[aArrSize - 1];
                //before the deleted object
                for (int j = 0; j < i; j++) {
                    tempPtr[j] = accountPtr[j];
                }
                //after the deleted object
                for (int k = i + 1; k < aArrSize; k++) {
                    tempPtr[k - 1] = accountPtr[k];
                }
                delete[] accountPtr;
                accountPtr = tempPtr;
            }

            cout << "Account " << accountId << " has been deleted" << endl;
            aArrSize--;
            return;
        }
    }
    cout << "Account " << accountId << " does not exist" << endl;
}

void BankingSystem::showAllAccounts() {
    cout << "Account id Branch id Branch name Customer id Customer name Balance" << endl;
    for( int i = 0; i < aArrSize; i++ ) {
        Account cur = accountPtr[ i ];
        string  brName, cstmrName;
        //to find branch name
        for( int j = 0; j < bArrSize; j++ ){
            if( cur.getBranchId() == branchPtr[ j ].getBranchId() ){
                brName = branchPtr[ j ].getBranchName();
                break;
            }
        }
        //to find customer name
        for( int j = 0; j < cArrSize; j++ ){
            if( cur.getCustomerId() == customerPtr[ j ].getCustomerId() ){
                cstmrName = customerPtr[ j ].getCustomerName();
                break;
            }
        }

        cout << cur.getAccId() << " "
             << cur.getBranchId() << " "
             << brName << " "
             << cur.getCustomerId() << " "
             << cstmrName << " "
             << fixed << setprecision(2) << cur.getDepositAmount() << endl;
    }
}

void BankingSystem::showBranch(const int branchId) {
    string  brName;
    int     numAcc = 0;
    //to find number of accounts
    for( int i = 0; i < aArrSize; i++ ){
        if( accountPtr[ i ].getBranchId() == branchId ){
            numAcc++;
        }
    }
    //to find branch name
    for( int j = 0; j < bArrSize; j++ ){
        if( branchPtr[j].getBranchId() == branchId ){
            brName = branchPtr[ j ].getBranchName();
            cout << "Branch id: " << branchId << " Branch name: " <<brName << " Number of accounts: " << numAcc << endl;
            if( numAcc > 0 ){
                cout << "Accounts at this branch:" << endl;
                cout << "Account id Customer id Customer name Balance" << endl;
                for( int i = 0; i < aArrSize; i++ ){
                    if( accountPtr[ i ].getBranchId() == branchId ){
                        string cstmrName;
                        //to find customer name
                        for( int k = 0; k < cArrSize; k++ ){
                            if( accountPtr[i].getCustomerId() == customerPtr[ k ].getCustomerId() ){
                                cstmrName = customerPtr[ k ].getCustomerName();
                                break;
                            }
                        }

                        cout << accountPtr[ i ].getAccId() << " "
                        << accountPtr[ i ].getCustomerId() << " "
                        << cstmrName << " "
                        << fixed << setprecision(2) << accountPtr[ i ].getDepositAmount() << endl;
                    }
                }
            }
            return;
        }
    }
    cout << "Branch " << branchId << " does not exist" << endl;
}

void BankingSystem::showCustomer(const int customerId) {
    string  cstmrName;
    int     numAcc = 0;
    //to find number of accounts
    for( int i = 0; i < aArrSize; i++ ){
        if( accountPtr[ i ].getCustomerId() == customerId ){
            numAcc++;
        }
    }
    //to find customer name
    for( int j = 0; j < cArrSize; j++ ){
        if( customerPtr[j].getCustomerId() == customerId ){
            cstmrName = customerPtr[ j ].getCustomerName();
            cout << "Customer id: " << customerId << " Customer name: " << cstmrName << " Number of accounts: " << numAcc << endl;

            if( numAcc > 0 ){
                cout << "Accounts of this customer:" << endl;
                cout << "Account id Branch id Branch name Balance" << endl;
                for( int i = 0; i < aArrSize; i++ ){
                    if( accountPtr[ i ].getCustomerId() == customerId ){
                        string brName;
                        //to find branch name
                        for( int k = 0; k < bArrSize; k++ ){
                            if( accountPtr[i].getBranchId() == branchPtr[ k ].getBranchId() ){
                                brName = branchPtr[ k ].getBranchName();
                                break;
                            }
                        }

                        cout << accountPtr[ i ].getAccId() << " " <<
                        accountPtr[ i ].getBranchId() << " " <<
                        brName << " " <<
                        fixed << setprecision(2) << accountPtr[ i ].getDepositAmount() << endl;
                    }
                }
            }
            return;
        }
    }
    cout << "Customer " << customerId << " does not exist" << endl;
}