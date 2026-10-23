#include <string>
#include "gcode.hh"
#include <Algorithm>
using namespace std;

gcode::gcode(const char printer[],
						 const char filename[],
						 double layer_thickness)
	: gc(filename), layer_thickness(layer_thickness) {
	gc << std::setprecision(3);
	string machine = string("conf/") + printer + ".conf";
	read_complete_file(machine.c_str());
}

gcode::~gcode() {
	for (auto s : shapes)
		delete s;
}

void gcode::draw() {
	sort(shapes.begin(), shapes.end(), by_height); // first sort by descending height
	double biggest = shapes[0]->height();
	uint32_t max_layers = biggest / layer_thickness;
	double z = 0;
	uint32_t last = shapes.size() - 1;
	const double shape_x_size = 3; // quick hack for now, it will work!
	for (uint32_t layer = 0; layer < max_layers; layer++, z += layer_thickness) {
		while (shapes[last]->height() < z)
			 last--;
 		shapes[0]->goto_z(gc, z); // g0 z0.0
		//always start drawing first shape at (0,0)
		double x = 0, y = 0;
		for (uint32_t i = 0; i <= last; i++) {
			shapes[i]->draw_layer(gc, x, y, layer_thickness, z);
			x += shape_x_size; // draw next shape at (20,0), then (40,0), ...
		}
	}
}	

string gcode::read_complete_file(const char filename[]) {
	ifstream f(filename);
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();
	string buffer(size + 1, '\0');
	f.seekg(0);
	f.read(&buffer[0], size); 
	return buffer;
}

