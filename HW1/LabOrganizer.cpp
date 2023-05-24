
/*
 * LabOrganizer.cpp
 * Gökberk Altýparmak
 * 21901798
 * CS201-02
 * 19.11.2021
 */

#include "LabOrganizer.h"
#include "Cabinet.h"
#include <iostream>
#include <string>
using namespace std;

LabOrganizer::LabOrganizer() {
    cabinets = NULL;
    cabinetNumbers = 0;
}

LabOrganizer::~LabOrganizer() {
    if (cabinets != NULL) {
        delete [] cabinets;
    }
    cabinetNumbers = 0;
}

LabOrganizer::LabOrganizer(const LabOrganizer& other) : cabinetNumbers(other.cabinetNumbers){
if (cabinetNumbers > 0) {
        cabinets = new Cabinet[cabinetNumbers];
        for (int i = 0; i < cabinetNumbers; i++) {
            cabinets[i] = other.cabinets[i];
        }
    }
    else {
        cabinets = NULL;
    }
}

bool LabOrganizer::isCabinetExist(int id) {
    if (cabinets == NULL) {
        return false;
    }
    else {
        for (int i = 0; i < cabinetNumbers; i++) {
            if (cabinets[i].getID() == id) {
                return true;
            }
        }
        return false;
    }
}

void LabOrganizer::addCabinet(int id, int rows, int columns) {
    if (rows > 9 || columns > 9) {
        cout << "Cannot add the cabinet: dimensions are out of bounds" << endl;
    }
    else if (LabOrganizer::isCabinetExist(id)) {
        cout << "Cannot add the cabinet: ID " << id << " already in the system" << endl;
    }
    else {
        cabinetNumbers++;
        Cabinet* cabinet = new Cabinet(id, rows, columns);
        if (cabinets == NULL) {
            cabinets = new Cabinet[cabinetNumbers];
            cabinets[0] = *cabinet;
        }
        else {
            Cabinet* temp = new Cabinet[cabinetNumbers];
            for (int i = 0; i < cabinetNumbers - 1; i++) {
                temp[i] = cabinets[i];
            }
            temp[cabinetNumbers - 1] = *cabinet;
            delete [] cabinets;
            cabinets = temp;
        }
        cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
    }
}

void LabOrganizer::removeCabinet(int id) {
    if (cabinets == NULL) {
        cout << "There is no any cabinet in the system to remove" << endl;
    }
    else {
        for (int i = 0; i < cabinetNumbers; i++) {
            if (cabinets[i].getID() == id) {
                if (cabinetNumbers == 1) {
                    delete [] cabinets;
                    cabinetNumbers = 0;
                }
                else {
                    Cabinet* temp = new Cabinet[cabinetNumbers - 1];
                    for (int j = 0; j < i; j++) {
                        temp[j] = cabinets[j];
                    }
                    for (int j = i + 1; j < cabinetNumbers; j++) {
                        temp[j - 1] = cabinets[j];
                    }
                    delete [] cabinets;
                    cabinetNumbers--;
                    cabinets = temp;
                }
                cout << "Cabinet " << id << " has been removed" << endl;
                return;
            }
        }
        cout << "Cabinet " << id << " does not exist in the system" << endl;
    }

}

void LabOrganizer::listCabinets() {
    if (cabinetNumbers == 0) {
        cout << "There is no cabinet in the system" << endl;
    }
    for (int i = 0; i < cabinetNumbers; i++) {
        cout << "ID: " << cabinets[i].getID();
        cout << ", Dimensions: " << cabinets[i].getRow() << "x" << cabinets[i].getColumn();
        cout << ", Number of empty slots: " << cabinets[i].getCabinetCapacity() << endl;
    }
}

void LabOrganizer::cabinetContents(int id) {
    for (int i = 0; i < cabinetNumbers; i++) {
        if (cabinets[i].getID() == id) {
            cout << cabinets[i] << endl;
            return;
        }
    }
    cout << "Cabinet " << id << " is not in the system" << endl;
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    bool isExist;
    int a = 0;
    for (int i = 0; i < cabinetNumbers; i++) {
        for (int j = 0; j < cabinets[i].getChemicalsNum(); j++) {
            if (cabinets[i].getSpesificChemical(j).getChemID() == chemID) {
                a++;
                break;
            }
        }
    }
    if (a < 1) {
        isExist = false;
    }
    else {
        isExist = true;
    }
    if (isExist) {
        cout << "Chemical with ID: " << chemID << " already exist in the system" << endl;
        return;
    }
    else {
        for (int i = 0; i < cabinetNumbers; i++) {
            if (cabinets[i].getID() == cabinetId) {
                cabinets[i].putChemicalToCabinet(location, chemType, chemID);
                return;
            }
        }
    }
}

void LabOrganizer::findChemical(int chemID) {
    for (int i = 0; i < cabinetNumbers; i++) {
        for (int j = 0; j < cabinets[i].getChemicalsNum(); j++) {
            if (cabinets[i].getSpesificChemical(j).getChemID() == chemID) {
                cout << "Chemical " << chemID << " is at location " << cabinets[i].getSpesificChemical(j).getLocation() << " in cabinet " << cabinets[i].getID() << endl;
                return;
            }
        }
    }
    cout << "Chemical " << chemID << " is not in the system" << endl;
}

void LabOrganizer::removeChemical(int chemID) {
    for (int i = 0; i < cabinetNumbers; i++) {
        for (int j = 0; j < cabinets[i].getChemicalsNum(); j++) {
            if (cabinets[i].getSpesificChemical(j).getChemID() == chemID) {
                if (cabinets[i].getChemicalsNum() == 1) {
                    cabinets[i].removeSpesificChemical(j);
                    delete [] cabinets[i].getArr();
                    cabinets[i].setChemicalNum(0);
                }
                else {
                    Chemical* temp = new Chemical[cabinets[i].getChemicalsNum() - 1];
                    for (int k = 0; k < j; k++) {
                        temp[k] = cabinets[i].getSpesificChemical(k);
                    }
                    for (int k = j + 1; k < cabinets[i].getChemicalsNum(); k++) {
                        temp[k-1] = cabinets[i].getSpesificChemical(k);
                    }
                    cabinets[i].removeSpesificChemical(j);
                    delete [] cabinets[i].getArr();
                    cabinets[i].setChemicalArr(temp);
                    cabinets[i].setChemicalNum(cabinets[i].getChemicalsNum() - 1);
                }
                cout << "Chemical " << chemID << " removed from cabinet " << cabinets[i].getID() << endl;
                return;
            }
        }
    }
    cout << "Chemical " << chemID << " is not in the system" << endl;
}
