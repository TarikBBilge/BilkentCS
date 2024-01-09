# include <iostream>
using namespace std;
#include "BankingSystem.h"
int main () {
    BankingSystem B;
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.addCustomer(3, "3");
    B.addCustomer(4, "3");
    B.deleteCustomer(4);
    B.deleteCustomer(4);
    B.deleteCustomer(1);
    B.deleteCustomer(2);
    B.deleteCustomer(3);
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.deleteCustomer(3);
    B.deleteCustomer(2);
    B.deleteCustomer(1);
    B.deleteCustomer(3);
    B.deleteCustomer(2);
    B.deleteCustomer(1);
    return 0;
}