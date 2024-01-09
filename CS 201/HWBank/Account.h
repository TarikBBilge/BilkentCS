/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>
using namespace std;

#ifndef HWBANK_ACCOUNT_H
#define HWBANK_ACCOUNT_H


class Account {
public:
    Account( int branchId = 0, int customerId = 0, double depoAmount = 0 );
    ~Account();

    int getAccId() const;

    void setAccId(int accId);

    int getCustomerId() const;

    void setCustomerId(int customerId);

    double getDepositAmount() const;

    void setDepositAmount(double depositAmount);

    int getBranchId() const;

    void setBranchId(int branchId);

    Account &operator=( const Account& );

private:
    int accId, customerId, branchId;
    double depositAmount;
};

#endif //HWBANK_ACCOUNT_H