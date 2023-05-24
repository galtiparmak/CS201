
/*
 * LabOrganizer.h
 * Gökberk Altýparmak
 * 21901798
 * CS201-02
 * 19.11.2021
 */

#ifndef LAB_ORGANIZER__H
#define LAB_ORGANIZER__H
#include "Cabinet.h"
#include "Chemical.h"
#include <iostream>
#include <string>
using namespace std;

class LabOrganizer{
    public:
        LabOrganizer();
        ~LabOrganizer();
        LabOrganizer(const LabOrganizer&);
        void addCabinet(int, int, int);
        void removeCabinet(int);
        void listCabinets();
        void cabinetContents(int);
        void placeChemical(int, string, string, int);
        void findChemical(int);
        void removeChemical(int);
        int getCabinetNumbers();
        bool isCabinetExist(int);
        void isChemicalExist(int);

    private:
        Cabinet* cabinets;
        int cabinetNumbers;
};
#endif // LAB_ORGANIZER__H
