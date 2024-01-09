/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>

using namespace std;

#ifndef HWBANK_CUSTOMER_H
#define HWBANK_CUSTOMER_H


class Customer {
public:
    Customer( int customerId = 0, string cstmrName = "");
    ~Customer();

    int getCustomerId() const;

    void setCustomerId(int customerId);

    const string &getCustomerName() const;

    void setCustomerName(const string &customerName);

    Customer &operator=( const Customer& );

private:
    int customerId;
    string customerName;
};

#endif //HWBANK_CUSTOMER_H