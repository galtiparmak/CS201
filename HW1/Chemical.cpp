
/*
 * Chemical.cpp
 * Gökberk Altýparmak
 * 21901798
 * CS201-02
 * 19.11.2021
 */

#include "Chemical.h"
#include <iostream>
#include <string>
using namespace std;

Chemical::Chemical(){
    chemID = 0;
    chemType = "";
    chemLoc = "";
}

Chemical::Chemical(int id, string type, string location) {
    chemID = id;
    chemType = type;
    chemLoc = location;
}

int Chemical::getChemID() {
    return chemID;
}

string Chemical::getChemType() {
    return chemType;
}

string Chemical::getLocation() {
    return chemLoc;
}

void Chemical::setLocation(string locToSet) {
    chemLoc = locToSet;
}
