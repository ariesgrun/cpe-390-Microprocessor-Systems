#include "shape.hh"
#include <cmath>
#include <unistd.h>
#include <string>
using namespace std;

double roundto(double v) {
	return round(v*100)*.01;
}

void shape::goto_xy(ostream& gc, double x, double y) const {
	gc << "g0 x" << roundto(x) << " y" << roundto(y) << '\n'; // g0 x1.2 y2.4
}

void shape::squirt_toxy(ostream& gc, double x, double y) const {
	double rate = 0; //TODO: fix this!
	gc << "g1 x" << roundto(x) << " y" << roundto(y) << " e" << rate << '\n'; // check this
}

void shape::goto_xyz(ostream& gc, double x, double y, double z) const {
	gc << "g0 x" << roundto(x) << " y" << roundto(y) << " z" << roundto(z) << '\n';
}

void shape::goto_z(ostream& gc, double z) const {
	gc << "g0 z" << roundto(z) << '\n';
}

void shape::retract(ostream& gc, bool b) const {
	gc << "g10 S" << b << '\n';
}

shape::~shape() {}




