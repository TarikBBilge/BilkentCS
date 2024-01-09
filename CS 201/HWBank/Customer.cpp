/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "Customer.h"

Customer::Customer( int customerId, string cstmrName) {
    this->customerId = customerId;
    this->customerName = cstmrName ;
}

Customer::~Customer() {}

int Customer::getCustomerId() const {
    return customerId;
}

void Customer::setCustomerId(int customerId) {
    Customer::customerId = customerId;
}

const string &Customer::getCustomerName() const {
    return customerName;
}

void Customer::setCustomerName(const string &customerName) {
    Customer::customerName = customerName;
}

Customer &Customer::operator=(const Customer &right ) {
    if( &right != this ){
        customerId = right.customerId;
        customerName = right.customerName;
    }
    return *this;
}
