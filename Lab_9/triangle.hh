#pragma once

#include "shape.hh"

class triangle : public shape { // a pipe is_a shape
private:
    double l; //side length
	//double t; // wall thickness
	//double r; // outer radius
	//double H; // height
	//uint32_t facets; // quality of approximation to circle

	// number of conentric rings of plastic to create one layer
	//uint32_t num_concentric_layers; 
public:
    triangle(double l) :
        l(l) {
	//triangle(double t, double r, double H, uint32_t facets, uint32_t num_concentric_layers) :
		//t(t), r(r), H(H), facets(facets), num_concentric_layers(num_concentric_layers) {
	}
	void draw_layer(std::ostream& gc,
									double x, double y,
									double layer_thickness, double z) const override;	
	double height() const override;
};
