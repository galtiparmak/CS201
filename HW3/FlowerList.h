#ifndef FLOWERLIST__H
#define FLOWERLIST__H

#include "Flower.h"
using namespace std;

class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    void printFlowerList() const;
    Flower* retrieve(string flowerName) const;
    string findFlowersAccordingToFeature(string feature) const;
private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary
};

#endif // FLOWERLIST__H
