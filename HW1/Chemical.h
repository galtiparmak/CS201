
/*
 * Chemical.h
 * Gökberk Altýparmak
 * 21901798
 * CS201-02
 * 19.11.2021
 */

#ifndef CHEMICAL__H
#define CHEMICAL__H
#include <iostream>
using namespace std;
#include <string>

class Chemical {
public:
    Chemical();
    Chemical(int, string, string);
    int getChemID();
    string getChemType();
    string getLocation();
    void setLocation(string);
private:
    int chemID;
    string chemType;
    string chemLoc;
};
#endif // CHEMICALS__H
