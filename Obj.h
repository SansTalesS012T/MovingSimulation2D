#ifndef OBJGUARD
#define OBJGUARD
#include <iostream>
#include <vector>
#include <math.h>
#include "MyPair.h"
using namespace std;

class Obj {
private:
    string name;
    double mass;
    MyPair *pos, *force, *speed;
    
    double forceMagnitude(Obj& a, Obj& b) {
        double G = 6.67e-11; // G constant
        double rSqure = pow((a.getPos()->getX() - b.getPos()->getX()), 2) + pow((a.getPos()->getY() - b.getPos()->getY()), 2);
        return (G*a.getMass()*b.getMass())/rSqure;
    }

public:
    Obj(string name, double mass, double x, double y): 
        name(name), 
        mass(mass), 
        pos(new MyPair(x, y)), 
        force(new MyPair(0, 0)), 
        speed(new MyPair(0, 0)) {}

    ~Obj() {
        delete this->pos;
        delete this->force;
        delete this->speed;
    }

    void move(vector<Obj*>& objList, double timeDiff) {
        int size = objList.size();
        for(int i = 0; i < size; i++) {
            if(objList[i] == nullptr) continue;
                
        }
    }
    
    void pulling(Obj *a) {
        Obj *b = this;
        MyPair *dab = &MyPair(
            b->getPos()->getX() - a->getPos()->getX(), 
            b->getPos()->getY() - a->getPos()->getY()
        ); 
        dab->norm();

        // dab is unit vector from a point to b, now calculate how a pull b
        double fmag = this->forceMagnitude(*a, *b);
        dab->scale(fmag);
        b->applyForce(*dab);

        // inverse dab to describe how b pull a
        dab->scale(-1);
        a->applyForce(*dab);
    }

    void applyForce(MyPair& f) {
        this->force->addiction(f);
    }

    void calculateSpeed(double timeDiff) {
        MyPair *tempF = this->force->clone();
        tempF->scale(timeDiff/this->mass);
        this->speed->addiction(*tempF);
        delete tempF;
    }

    void changePostion(double timeDiff) {
        MyPair *tempV = this->speed->clone();
        tempV->scale(timeDiff);
        this->pos->addiction(*tempV);
        delete tempV;
    }

    void print() {
        cout << "Obj:       " << this->name << endl;
        cout << "Mass:      " << this->mass << endl;
        cout << "Positon:   " << this->pos->getData() << endl;
        cout << "Force:     " << this->force->getData() << endl;
        cout << "Speed:     " << this->speed->getData() << endl; 
    }

public: // setter and getter
    void setName(string name) { this->name = name; }
    void setMass(double mass) { this->mass = mass; }
    void setPos(double x, double y) { this->pos->setBoth(x, y); }

    string getName() { return this->name; }
    double getMass() { return this->mass; }
    MyPair *getPos() { return this->pos; }
};
#endif 