#ifndef SYSTEMGUARD
#define SYSTEMGUARD
#include <iostream>
#include "Obj.h"
using namespace std;

class System {
private:
	vector<Obj*> objectList;
	int x, y, x_, y_, listSize;

public:
	System(int boarderX, int boarderY) {
		this->objectList = vector<Obj*>();
		this->listSize = 0;
		this->x = x/2;
		this->y = y/2;
		this->x_ = -x_/2;
		this->y_ = -y_/2;
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