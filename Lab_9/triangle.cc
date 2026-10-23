#include "triangle.hh"
#include <numbers>
#include <cmath>
using namespace std;
using namespace std::numbers;

void triangle::draw_layer(ostream& gc, double x, double y, double layer_thickness, double z) const {
	//TODO: jump from current point to nearest angle on circle. For now angle = 0
    double l = this->l;
	//double ang = 0;
	//double da = 2 * pi / facets;
	//double r = this->r;
    squirt_toxy(gc, (l/2), ((l/2)/tan(0.523599)));
    squirt_toxy(gc, -(l/2), ((l/2)/tan(0.523599)));
    squirt_toxy(gc, 0,0);


    /*
	for (uint32_t concentric = 0; concentric < num_concentric_layers; concentric++) {
		for (uint32_t f = 0; f < facets; f++, ang += da)
			squirt_toxy(gc, x + r * cos(ang), y + r * sin(ang)); // first time (r,0)
		r += layer_thickness;
	}
    */
}

double triangle::height() const {
	return ((l/2)/tan(0.523599));
}
