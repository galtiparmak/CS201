#include "Flower.h"
#include "FlowerList.h"
#include "FlowerLibrary.h"

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

FlowerLibrary::FlowerLibrary() {
}

FlowerLibrary::~FlowerLibrary() {
    //flowers = NULL;
}

void FlowerLibrary::addFlower(string name) {
    string lowerName = toLowerChar(name);
    if (!flowers.add(lowerName)) {
        cout << lowerName << " cannot be added into the library because it already exists." << endl;
    }
    else {
        cout << lowerName << " has been added into the library." << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {
    string lowerName = toLowerChar(name);
    if (!flowers.remove(lowerName)) {
        cout << lowerName << " cannot be removed because it's not in the library." << endl;
    }
    else {
        cout << lowerName << " has been removed from the library." << endl;
    }

}

void FlowerLibrary::listFlowers() const {
    if (flowers.isEmpty()) {
        cout << "Library is empty" << endl;
    }
    else {
        flowers.printFlowerList();
    }
}

void FlowerLibrary::listFeatures(string name) const {
    Flower *f;
    f = flowers.retrieve(name);
    if (f == NULL) {
        cout << name << " isn't found in library" << endl;
    }
    else {
        cout << f->printFlower() << endl;
    }
}

void FlowerLibrary::addFeature(string name, string feature) {
    Flower *f;
    string lowerName = toLowerChar(name);
    f = flowers.retrieve(lowerName);
    string lowerFeature = toLowerChar(feature);
    if (f != NULL) {
        if (!f->add(lowerFeature)) {
            cout << lowerFeature << " already exists in " << lowerName << endl;
        }
        else {
            cout << lowerFeature << " is added into " << lowerName << endl;
        }
    }
    else {
        cout << lowerName << " isn't found in library" << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature) {
    Flower *f;
    string lowerName = toLowerChar(name);
    f = flowers.retrieve(lowerName);
    string lowerFeature = toLowerChar(feature);
    if (f != NULL) {
        if (!f->remove(lowerFeature)) {
            cout << lowerFeature << " doesn't exist in " << lowerName << endl;;
        }
        else {
            cout << lowerFeature << " is removed from " << lowerName << endl;
        }
    }
    else {
        cout << lowerName << " doesn't exist in the system" << endl;
    }
}

void FlowerLibrary::findFlowers(string feature) const {
    cout << flowers.findFlowersAccordingToFeature(feature) << endl;
}

string FlowerLibrary::toLowerChar(string str) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char ch = tolower(str[i]);
        result += ch;
    }
    return result;
}
