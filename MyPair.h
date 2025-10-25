#ifndef MYPAIRGUARD
#define MYPAIRGUARD
#include <iostream>
#include <string>
using namespace std;

class MyPair {
private:
	double x, y;

public:
	MyPair(double x, double y): x(x), y(y) {}
	
	void scale(double a) {
		this->x *= a;
		this->y *= a;
	}

	void norm() {
		double size = sqrt(this->x * this->x + this->y * this->y);
		this->x /= size;
		this->y /= size;
	}

	void addiction(MyPair& p, bool minus = false) {
		int mult = 1;
		if(minus) mult = -1;
		this->x += mult*p.getX();
		this->y += mult*p.getY();
	}

	MyPair *clone() {
		return new MyPair(this->x, this->y);
	}

public:
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setBoth(double x, double y) {
		this->x = x, this->y = y;
	}

	double getX() { return this->x; }
	double getY() { return this->y; }

	void print() {
		cout << x << ", " << y;
	}

	string getData() {
		string res = to_string(this->x) + ", " + to_string(this->y); 
		return res;
	}
};
#endif