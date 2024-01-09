/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>

using namespace std;

#ifndef HWBANK_BRANCH_H
#define HWBANK_BRANCH_H


class Branch {
public:
    Branch( int brchId = 0, string brchName = "" );

    ~Branch();

    int getBranchId() const;

    void setBranchId(int branchId);

    const string &getBranchName() const;

    void setBranchName(const string &branchName);

    Branch &operator=( const Branch& );

private:
    int branchId;
    string branchName;
};

#endif //HWBANK_BRANCH_H