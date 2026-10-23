#pragma once
#include "shape.hh"

class gcode {
private:
	uint32_t max_layers;
	double layer_thickness;
	std::vector<const shape*> shapes;
	std::ofstream gc; // gcode gets written here
	std::string read_complete_file(const char filename[]);
public:
	gcode(const char printer[], const char filename[], double layer_thickness);
	~gcode();

	// we will not support copy constructor and operator =. You cannot copy a gshape. Too bad!
	gcode(const gcode& orig) = delete;
	gcode& operator=(const gcode& orig) = delete;
	
	/*
		add a shape to the list to be drawn
		Must be dynamically allocated using new 
		gcode will delete the objects when done
	*/
	
	void add(const shape* s) {
		shapes.push_back(s);
	}

	void draw();
};
