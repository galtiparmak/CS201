
/*
 * Cabinet.h
 * Gökberk Altýparmak
 * 21901798
 * CS201-02
 * 19.11.2021
 */

#ifndef CABINET__H
#define CABINET__H
#include "Chemical.h"
#include <iostream>
#include <string>
using namespace std;

class Cabinet {
public:
    Cabinet();
    Cabinet(int, int, int);
    ~Cabinet();
    Cabinet(const Cabinet&);
    friend ostream& operator<<(ostream&, Cabinet&);
    int getID();
    int getRow();
    int getColumn();
    Chemical getSpesificChemical(int);
    int getCabinetCapacity();
    int getChemicalsNum();
    string getContentOfCabinet();
    Chemical* getArr();
    void setChemicalNum(int);
    void setChemicalArr(Chemical*);
    void putChemicalToCabinet(string, string, int);
    bool isLocSuitable(Chemical, string);
    char intToChar(int);
    char numberToChar(int);
    void updateTable(string&);
    string nearPossibleLocations(Chemical, char, char);
    void removeSpesificChemical(int);
private:
    int cabinetId;
    char** table;
    int rowNum;
    int columnNum;
    int chemicalsInCabinet;
    string contentOfCabinet;
    string chemicalsStr;
    Chemical* chemicalArray;
};
#endif // CABINET__H
