#include "System.h"
using namespace std;

int main() {
	System s(1080, 720);
	s.addObject(new Obj("A", 20.55, 0, 0, 1, 2));
	return 0;
}