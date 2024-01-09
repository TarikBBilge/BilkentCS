/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "Account.h"

Account::Account( int branchId, int customerId, double depoAmount ) {
    this->accId = getAccId();
    this->branchId = branchId;
    this->customerId = customerId;
    this->depositAmount = depoAmount;
}

Account::~Account() {

}

int Account::getAccId() const {
    return accId;
}

void Account::setAccId(int accId) {
    Account::accId = accId;
}

int Account::getCustomerId() const {
    return customerId;
}

void Account::setCustomerId(int customerId) {
    Account::customerId = customerId;
}

double Account::getDepositAmount() const {
    return depositAmount;
}

void Account::setDepositAmount(double depositAmount) {
    Account::depositAmount = depositAmount;
}

int Account::getBranchId() const {
    return branchId;
}

void Account::setBranchId(int branchId) {
    Account::branchId = branchId;
}

Account &Account::operator=(const Account &right) {
    if( this != &right ){
        accId = right.accId;
        customerId = right.customerId;
        depositAmount = right.depositAmount;
        branchId = right.branchId;
    }
    return *this;
}
