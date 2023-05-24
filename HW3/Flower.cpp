#include "Flower.h"

#include <iostream>
#include <string>
using namespace std;

Flower::Flower() {
    size = 0;
    head = NULL;
    flowerName = "";
}

Flower::Flower(string flowerName) {
    this->flowerName = flowerName;
    size = 0;
    head = NULL;
}

Flower::Flower(const Flower& aFlower) : size(aFlower.size) {
    if (aFlower.head == NULL) {
        head = NULL;
    }
    else {
        head = new FeatureNode;
        head->feature = aFlower.head->feature;
        FeatureNode *newptr = head;

        for (FeatureNode *temp = aFlower.head->next; temp != NULL; temp = temp->next) {
            newptr->next = new FeatureNode;
            newptr = newptr->next;
            newptr->feature = temp->feature;
        }
        newptr->next = NULL;
    }
}

Flower::~Flower() {
    FeatureNode *currNode = head;
    FeatureNode *nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    size = 0;
}

bool Flower::isEmpty() const {
    return size == 0;
}

int Flower::getLength() const {
    return size;
}

bool Flower::add(string feature) {
    FeatureNode *newNode = new FeatureNode;
    newNode->feature = feature;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        size++;
        return true;
    }
    else {
        FeatureNode *currNode = head;
        while (currNode != NULL) {
            if (currNode->feature == feature) {
                return false;
            }
            currNode = currNode->next;
        }

        FeatureNode *prevNode = NULL;
        currNode = head;
        while (currNode != NULL) {
            if (newNode->feature.compare(currNode->feature) < 0) {
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

bool Flower::remove(string feature) {
    if (head == NULL) {
        return false;
    }
    else {
        FeatureNode *currNode = head;
        FeatureNode *prevNode = NULL;
        while (currNode != NULL) {
            if (currNode->feature == feature) {
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

string Flower::printFlower() const {
    string str = "";
    str += flowerName + ": ";

    if (head == NULL) {
        str += "No feature";
        return str;
    }
    else {
        FeatureNode *currNode = head;
        while (currNode != NULL) {
            str += currNode->feature;
            currNode = currNode->next;
            if (currNode != NULL) {
                str += ", ";
            }
        }
        return str;
    }
}

string Flower::getFlowerName() {
    return flowerName;
}

bool Flower::isFeatureExist(string feature) const {
    if (size == 0) {
        return false;
    }
    else {
        FeatureNode *currNode = head;
        while (currNode != NULL) {
            if (currNode->feature == feature) {
                return true;
            }
            currNode = currNode->next;
        }
        return false;
    }
}
