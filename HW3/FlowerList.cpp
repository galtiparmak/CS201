#include "Flower.h"
#include "FlowerList.h"

#include <iostream>
#include <string>
using namespace std;

FlowerList::FlowerList() {
    size = 0;
    head = NULL;
}

FlowerList::FlowerList(const FlowerList& aList) : size(aList.size){
    if(aList.head == NULL) {
        head = NULL;
    }
    else {
        head = new FlowerNode;
        head->f = aList.head->f;
        FlowerNode *newptr = head;

        for (FlowerNode *temp = aList.head->next; temp != NULL; temp = temp->next) {
            newptr = new FlowerNode;
            newptr = newptr->next;
            newptr->f = temp->f;
        }
        newptr = NULL;
    }
}

FlowerList::~FlowerList() {
    FlowerNode *currNode = head;
    FlowerNode *nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    head = NULL;
    size = 0;
}

bool FlowerList::isEmpty() const {
    return size == 0;
}

int FlowerList::getLength() const {
    return size;
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const {
    if (head == NULL) {
        return false;
    }
    else {
        FlowerNode *currNode = head;
        while (currNode != NULL) {
            if (currNode->f.getFlowerName() == flowerName) {
                flower = currNode->f;
                return true;
            }
            currNode = currNode->next;
        }
        return false;
    }
}

bool FlowerList::add(string flowerName) {
    FlowerNode *newNode = new FlowerNode;
    newNode->f = Flower(flowerName);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        size++;
        return true;
    }
    else {
        FlowerNode *currNode = head;
        while (currNode != NULL) {
            if (currNode->f.getFlowerName() == flowerName) {
                return false;
            }
            currNode = currNode->next;
        }

        FlowerNode *prevNode = NULL;
        currNode = head;
        while (currNode != NULL) {
            if (newNode->f.getFlowerName().compare(currNode->f.getFlowerName()) < 0) {
                if (currNode == head) {
                    newNode->next = head;
                    head = newNode;
                }
                else {
                    newNode->next = prevNode->next;
                    prevNode->next = newNode;
                }
                size++;
                return true;
            }
            prevNode = currNode;
            currNode = currNode->next;
            if (currNode == NULL) {
                newNode->next = prevNode->next;
                prevNode->next = newNode;
                size++;
                return true;
            }
        }
        return false;
    }
}

bool FlowerList::remove(string flowerName) {
    if (head == NULL) {
        return false;
    }
    else {
        FlowerNode *currNode = head;
        FlowerNode *prevNode = NULL;
        while (currNode != NULL) {
            if (currNode->f.getFlowerName() == flowerName) {
                if (currNode == head) {
                    head = currNode->next;
                }
                else {
                    prevNode->next = currNode->next;
                }
                delete currNode;
                size--;
                return true;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
        return false;
    }
}

void FlowerList::printFlowerList() const {
    FlowerNode *currNode = head;
    while (currNode != NULL) {
        cout << currNode->f.printFlower() << endl;
        currNode = currNode->next;
    }
}

Flower* FlowerList::retrieve(string flowerName) const {
    if (head == NULL) {
        return NULL;
    }
    else {
        FlowerNode *currNode = head;
        while (currNode != NULL) {
            if (currNode->f.getFlowerName() == flowerName) {
                return &(currNode->f);
            }
            currNode = currNode->next;
        }
        return NULL;
    }
}

string FlowerList::findFlowersAccordingToFeature(string feature) const {
    string str = feature + " flowers: ";
    if (size == 0) {
        str += "there is no such flower";
        return str;
    }
    else {
        int count = 0;
        FlowerNode *currNode = head;
        FlowerNode *tempNode = currNode;
        while (currNode != NULL) {
            if (currNode->f.isFeatureExist(feature)) {
                str += currNode->f.getFlowerName();
                count++;
                tempNode = currNode->next;
                if (tempNode != NULL) {
                    str += ", ";
                }
            }
            currNode = currNode->next;
            tempNode = currNode;
        }
        if (count != 0) {
            return str;
        }
        str += "there is no such flower";
        return str;
    }
}
