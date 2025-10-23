#ifndef SYSTEMGUARD
#define SYSTEMGUARD
#include <iostream>
#include "Obj.h"
using namespace std;

class System {
private:
    vector<Obj*> objectList;
    int borderX, borderY, listSize;

public:
    System(int x, int y) {
        this->objectList = vector<Obj*>();
        this->listSize = 0;
        this->borderX = x;
        this->borderY = y;
    }
    
    ~System() {
        for(int i = 0; i < this->listSize; i++) {
            delete this->objectList[i];
        }
    }

    void addObject(Obj *a) {
        this->objectList.push_back(a);
        this->listSize += 1;
    }

    void display() {
        
    }

    void simulate() {

    }
};
#endif