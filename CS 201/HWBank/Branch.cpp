/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "Branch.h"

Branch::Branch( int brchId, string brchName ) {
    this->branchId = brchId;
    this->branchName = brchName;
}

Branch::~Branch() {}

int Branch::getBranchId() const {
    return branchId;
}

void Branch::setBranchId(int branchId) {
    Branch::branchId = branchId;
}

const string &Branch::getBranchName() const {
    return branchName;
}

void Branch::setBranchName(const string &branchName) {
    Branch::branchName = branchName;
}

Branch &Branch::operator=(const Branch &right) {
    if( &right != this ){
        branchId = right.branchId;
        branchName = right.branchName;
    }
    return *this;
}
