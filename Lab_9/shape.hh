#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

class shape {
public:

	// goto an x,y location on this level (don't change z) without extrusion
	void goto_xy(std::ostream& gc, double x, double y) const;

	// goto an x,y location on this level (don't change z) and extrude plastic
	void squirt_toxy(std::ostream& gc, double x, double y) const;

	// goto an x,y,z location and don't extrude plastic	
	void goto_xyz(std::ostream& gc, double x, double y, double z) const;

	// just move to next level while staying in same x,y
	void goto_z(std::ostream& gc, double z) const;

	// retract the filament so it doesn't leak out while moving
 	void retract(std::ostream& gc, bool b) const;
	void rotate(double ang, double & x, double& y) {
	    // for any point x, y transform it as follows:
	    double xnew = x * cos(ang) - y * sin(ang);
    	double ynew = x * sin(ang) + y * cos(ang);
		x = xnew;
		y = ynew;
	}

	virtual void draw_layer(std::ostream& gc,
													double x, double y,
													double layer_thickness, double z) const = 0;
	virtual double height() const = 0;
	virtual ~shape();
};

inline bool by_height(const shape* a, const shape* b) {
	return a->height() > b->height();
}

