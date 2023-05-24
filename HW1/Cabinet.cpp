
/*
 * Cabinet.cpp
 * Gökberk Altýparmak
 * 21901798
 * CS201-02
 * 19.11.2021
 */

#include "Cabinet.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Cabinet::Cabinet() {
    cabinetId = 0;
    table = NULL;
    rowNum = 0;
    columnNum = 0;
    chemicalsInCabinet = 0;
    chemicalArray = NULL;
    contentOfCabinet = "";
    chemicalsStr = "";
}

Cabinet::Cabinet(int id, int row, int column) {
    cabinetId = id;
    rowNum = row;
    columnNum = column;
    table = new char*[rowNum];
    for (int i = 0; i < rowNum; i++) {
        table[i] = new char[columnNum];
    }
    chemicalsInCabinet = 0;
    chemicalArray = NULL;
    contentOfCabinet = "";
    chemicalsStr = "";

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            table[i][j] = '+';
        }
    }
}

Cabinet::~Cabinet() {
     if (chemicalArray != NULL) {
        for (int i = 0; i < rowNum; i++) {
            delete [] table[i];
        }
        delete [] table;
        delete [] chemicalArray;
    }
    cabinetId = 0;
    rowNum = 0;
    columnNum = 0;
    chemicalsInCabinet = 0;
    contentOfCabinet = "";
    chemicalsStr = "";
}

Cabinet::Cabinet(const Cabinet& other) : chemicalsInCabinet(other.chemicalsInCabinet){
    cabinetId = other.cabinetId;
    rowNum = other.rowNum;
    contentOfCabinet = other.contentOfCabinet;
    chemicalsStr = other.chemicalsStr;

    table = new char*[rowNum];
    for (int i = 0; i < rowNum; i++) {
        table[i] = new char[columnNum];
    }

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            table[i][j] = other.table[i][j];
        }
    }

    if (chemicalsInCabinet > 0) {
        chemicalArray = new Chemical[chemicalsInCabinet];
        for (int i = 0; i < chemicalsInCabinet; i++) {
            chemicalArray[i] = other.chemicalArray[i];
        }
    }
    else {
        chemicalArray = NULL;
    }

}

ostream& operator<<(ostream& out, Cabinet& cb) {
    cb.updateTable(cb.contentOfCabinet);
    out << "ID: " << cb.cabinetId << ", " << cb.rowNum << "x" << cb.columnNum << ", empty: ";
    out << (cb.rowNum * cb.columnNum) - cb.chemicalsInCabinet << ". Chemicals: " << cb.chemicalsStr << endl;
    out << cb.contentOfCabinet;
    return out;
}

int Cabinet::getID() {
    return cabinetId;
}

int Cabinet::getRow() {
    return rowNum;
}

int Cabinet::getColumn() {
    return columnNum;
}

Chemical Cabinet::getSpesificChemical(int index) {
    return chemicalArray[index];
}

int Cabinet::getCabinetCapacity() {
    return (rowNum*columnNum) - chemicalsInCabinet;
}

int Cabinet::getChemicalsNum() {
    return chemicalsInCabinet;
}

string Cabinet::getContentOfCabinet() {
    return contentOfCabinet;
}

Chemical* Cabinet::getArr(){
    return chemicalArray;
}

void Cabinet::setChemicalNum(int numToSet) {
    chemicalsInCabinet = numToSet;
}

void Cabinet::setChemicalArr(Chemical* temp) {
    chemicalArray = temp;
}

void Cabinet::putChemicalToCabinet(string loc, string chemType, int chemID) {
    Chemical* chem = new Chemical(chemID, chemType, "");
    if (Cabinet::isLocSuitable(*chem, loc)) {
        chemicalsInCabinet++;
        chem->setLocation(loc);
        if (chemicalArray == NULL) {
            chemicalArray = new Chemical[chemicalsInCabinet];
            chemicalArray[0] = *chem;
        }
        else {
            Chemical* temp = new Chemical[chemicalsInCabinet];
            for (int i = 0; i < chemicalsInCabinet - 1; i++) {
                temp[i] = chemicalArray[i];
            }
            temp[chemicalsInCabinet - 1] = *chem;
            delete[] chemicalArray;
            chemicalArray = temp;
        }
        string str;
        stringstream ss;
        ss << chemID;
        ss >> str;
        chemicalsStr += loc + ": " + str + " ";
    }
    else {
        delete chem;
    }
}

bool Cabinet::isLocSuitable(Chemical ch, string loc) {
    char onRow = loc[0];
    char onColumn = loc[1];

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            if (onRow == intToChar(i) && onColumn == numberToChar(j)) {
                if (table[i][j] == '+') {
                    if (ch.getChemType() == "retardant") {
                        table[i][j] = 'r';
                        cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID()<< endl;
                        return true;
                    }
                    else {
                        if (i == 0 && j == 0) {
                            if (table[i][j+1] != 'c' && table[i+1][j] != 'c' && table[i+1][j+1] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " No nearest possible location is found." << endl;
                                return false;
                            }
                        }
                        else if (i == rowNum - 1 && j == columnNum - 1) {
                            if (table[i-1][j] != 'c' && table[i][j-1] != 'c' && table[i][j-1] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " No nearest possible location is found" << endl;
                                return false;
                            }
                        }
                        else if (i == 0 && j == columnNum - 1) {
                            if (table[i][j-1] != 'c' && table[i+1][j-1] != 'c' && table[i+1][j] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " No nearest possible location is found" << endl;
                                return false;
                            }
                        }
                        else if (i == rowNum - 1 && j == 0) {
                            if (table[i-1][j] != 'c' && table[i-1][j+1] != 'c' && table[i][j+1] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " No nearest possible location is found" << endl;
                                return false;
                            }
                        }
                        else if (i == 0) {
                            if (table[i][j+1] != 'c' && table[i][j-1] != 'c' && table[i+1][j-1] != 'c' && table[i+1][j] != 'c' && table[i+1][j+1] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " Nearest possible locations for this chemical: ";
                                for (int a = i; a < i + 2; a++) {
                                    for (int b = j - 1; b < j + 2; b++) {
                                        if (a == i && b == j) {
                                            continue;
                                        }
                                        else {
                                            cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                        }
                                    }
                                }
                                cout << endl;
                                return false;
                            }
                        }
                        else if (j == 0) {
                            if (table[i-1][j] != 'c' && table[i-1][j+1] != 'c' && table[i][j+1] != 'c' && table[i+1][j+1] != 'c' && table[i+1][j] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " Nearest possible locations for this chemical: ";
                                for (int a = i - 1; a < i + 2; a++) {
                                    for (int b = j; b < j + 2; b++) {
                                        if (a == i && b == j) {
                                            continue;
                                        }
                                        else {
                                            cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                        }
                                    }
                                }
                                cout << endl;
                                return false;
                            }
                        }
                        else if (i == rowNum - 1) {
                            if (table[i][j-1] != 'c' && table[i-1][j-1] != 'c' && table[i-1][j] != 'c' && table[i-1][j+1] != 'c' && table[i][j+1] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID()<< endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " Nearest possible locations for this chemical: ";
                                for (int a = i - 1; a < i + 1; a++) {
                                    for (int b = j - 1; b < j + 2; b++) {
                                        if (a == i && b == j) {
                                            continue;
                                        }
                                        else {
                                            cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                        }
                                    }
                                }
                                cout << endl;
                                return false;
                            }
                        }
                        else if (j == columnNum - 1) {
                            if (table[i-1][j] != 'c' && table[i-1][j-1] != 'c' && table[i][j-1] != 'c' && table[i+1][j-1] != 'c' && table[i+1][j] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " Nearest possible locations for this chemical: ";
                                for (int a = i - 1; a < i + 2; a++) {
                                    for (int b = j - 1; b < j + 1; b++) {
                                        if (a == i && b == j) {
                                            continue;
                                        }
                                        else {
                                            cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                        }
                                    }
                                }
                                cout << endl;
                                return false;
                            }
                        }
                        else {
                            if (table[i-1][j-1] != 'c' && table[i-1][j] != 'c' && table[i-1][j+1] != 'c' && table[i][j+1] != 'c' && table[i][j-1] != 'c' && table[i+1][j-1] != 'c' &&table[i+1][j] != 'c' && table[i+1][j+1] != 'c') {
                                table[i][j] = 'c';
                                cout << ch.getChemType() << " chemical with ID " << ch.getChemID() << " has been placed at location " << loc << " in cabinet " << this->getID() << endl;
                                return true;
                            }
                            else {
                                cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                                cout << " Nearest possible locations for this chemical: ";
                                for (int a = i - 1; a < i + 2; a++) {
                                    for (int b = j - 1; b < j + 2; b++) {
                                        if (a == i && b == j) {
                                            continue;
                                        }
                                        else {
                                            cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                        }
                                    }
                                }
                                cout << endl;
                                return false;
                            }
                        }
                    }
                }
                else {
                    cout << "Location " << loc << " in cabinet " << this->getID() << " is already occupied. ";
                    if (i == 0 && j == 0) {
                        string str = "";
                        cout << " No nearest possible location is found." << endl;
                    }
                    else if(i == rowNum - 1 && j == columnNum - 1) {
                        cout << " No nearest possible location is found" << endl;
                    }
                    else if(i == 0 && j == columnNum - 1) {
                        cout << " No nearest possible location is found" << endl;
                    }
                    else if(i == rowNum - 1 && j == 0){
                        cout << " No nearest possible location is found" << endl;
                    }
                    else if(i == 0) {
                        cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                        cout << " Nearest possible locations for this chemical: ";
                        for (int a = i; a < i + 2; a++) {
                            for (int b = j - 1; b < j + 2; b++) {
                                if (a == i && b == j) {
                                    continue;
                                }
                                else {
                                    cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                }
                            }
                        }
                        cout << endl;
                    }
                    else if(j == 0) {
                        cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                        cout << " Nearest possible locations for this chemical: ";
                        for (int a = i - 1; a < i + 2; a++) {
                            for (int b = j; b < j + 2; b++) {
                                if (a == i && b == j) {
                                    continue;
                                }
                                else {
                                    cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                }
                            }
                        }
                        cout << endl;
                    }
                    else if(i == rowNum - 1) {
                        cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                        cout << " Nearest possible locations for this chemical: ";
                        for (int a = i - 1; a < i + 1; a++) {
                            for (int b = j - 1; b < j + 2; b++) {
                                if (a == i && b == j) {
                                    continue;
                                }
                                else {
                                    cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                }
                            }
                        }
                        cout << endl;
                    }
                    else if(j == columnNum - 1) {
                        cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                        cout << " Nearest possible locations for this chemical: ";
                        for (int a = i - 1; a < i + 2; a++) {
                            for (int b = j - 1; b < j + 1; b++) {
                                if (a == i && b == j) {
                                    continue;
                                }
                                else {
                                    cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                }
                            }
                        }
                        cout << endl;
                    }
                    else {
                        cout << "Location " << loc << " in cabinet " << this->getID() << " is not suitable for a combustive chemical.";
                        cout << " Nearest possible locations for this chemical: ";
                        for (int a = i - 1; a < i + 2; a++) {
                            for (int b = j - 1; b < j + 2; b++) {
                                if (a == i && b == j) {
                                    continue;
                                }
                                else {
                                    cout << nearPossibleLocations(ch, intToChar(a), numberToChar(b));
                                }
                            }
                        }
                        cout << endl;
                    }
                    return false;
                }
            }
        }
    }
    return false;
}

char Cabinet::intToChar(int in)
{
    if (in > -1 && in < 9 )
   {
        return "ABCDEFGHI"[in];
   }
    return '-';
}

char Cabinet::numberToChar(int in)
{
    if (in > -1 && in < 9 ){
        return "123456789"[in];
   }
    return '-';
}

void Cabinet::updateTable(string& tab) {
    tab = "";
    for (int i = 0; i < rowNum + 1; i++) {
        for (int j = 0; j < columnNum + 1; j++) {
            if (i == 0 && j == 0) {
                tab += ' ';
            }
            else if (i == 0) {
                char ch = '0' + j;
                tab += ' ';
                tab += ch;
            }
            else if (j == 0) {
                tab += intToChar(i - 1);
                tab += ' ';
            }
            else {
                tab += table[i-1][j-1];
                tab += ' ';
            }
        }
        tab += "\n";
    }
}

string Cabinet::nearPossibleLocations(Chemical ch, char row, char column) {
    string result = "";
    result += row;
    result += column;

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            if (row == intToChar(i) && column == numberToChar(j)) {
                if (table[i][j] == '+') {
                    if (ch.getChemType() == "retardant") {
                        return result + " ";
                    }
                    else {
                        if (i == 0 && j == 0) {
                            if (table[i][j+1] != 'c' && table[i+1][j] != 'c' && table[i+1][j+1] != 'c') {
                                return result + " ";
                            }
                        }
                        else if (i == rowNum - 1 && j == columnNum - 1) {
                            if (table[i-1][j] != 'c' && table[i][j-1] != 'c' && table[i][j-1] != 'c') {
                                return result + " ";
                            }
                        }
                        else if (i == 0) {
                            if (table[i][j+1] != 'c' && table[i][j-1] != 'c' && table[i+1][j-1] != 'c' && table[i+1][j] != 'c' && table[i+1][j+1] != 'c') {
                                return result + " ";
                            }
                        }
                        else if (j == 0) {
                            if (table[i-1][j] != 'c' && table[i-1][j+1] != 'c' && table[i][j+1] != 'c' && table[i+1][j+1] != 'c' && table[i+1][j] != 'c') {
                                return result + " ";
                            }
                        }
                        else if (i == rowNum - 1) {
                            if (table[i][j-1] != 'c' && table[i-1][j-1] != 'c' && table[i-1][j] != 'c' && table[i-1][j+1] != 'c' && table[i][j+1] != 'c') {
                                return result + " ";
                            }
                        }
                        else if (j == columnNum - 1) {
                            if (table[i-1][j] != 'c' && table[i-1][j-1] != 'c' && table[i][j-1] != 'c' && table[i+1][j-1] != 'c' && table[i+1][j] != 'c') {
                                return result + " ";
                            }
                        }
                        else {
                            if (table[i-1][j-1] != 'c' && table[i-1][j] != 'c' && table[i-1][j+1] != 'c' && table[i][j+1] != 'c' && table[i][j-1] != 'c' && table[i+1][j-1] != 'c' &&table[i+1][j] != 'c' && table[i+1][j+1] != 'c') {
                                return result + " ";
                            }
                        }
                    }
                }
            }
        }
    }
    return "";
}

void Cabinet::removeSpesificChemical(int index) {
   string loc = chemicalArray[index].getLocation();
   char row = loc[0];
   char column = loc[1];

   for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            if (row == intToChar(i) && column == numberToChar(j)) {
                table[i][j] = '+';
            }
        }
   }

}
