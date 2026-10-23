#include "gcode.hh"
#include "pipe.hh"


//  gcode -mcr10 test.gc
int main(int argc, char* argv[]) {
	const char* printer = "cr10";
	const char* filename;
	if (argc > 1) {
		if (argv[1][0] == '-') {
			if (argv[1][1] == 'm') {
				printer = &argv[1][2];
			}
			if (argc > 2) {
				filename = argv[2];
			}
		} else {
			filename = argv[1];
		}
	} else {
		filename = "test.gcode";
	}
	const uint32_t facets = 20;
	gcode gc(printer, filename, 0.2);
	
	{ // vertical cylindrical pipe with wall thickness t
		const double t = 0.2;
		const	double r = 1;
		const double H = 1;
		const uint32_t num_concentric_layers = 5;
		gc.add( new pipe(t, r, H, facets, num_concentric_layers));
	}
  gc.draw();

#if 0
	{	// open box, no top
		const double t = 1;
		const double L = 10;
		const double W = 10;
		const double H = 5;
		gc.add(new Box(t, L, W, H));
	}
	{ // solid cube (don't fill 100%, fill with grid of some kind?
		const double L = 10;
		const double W = 10;
		const double H = 5;
		gc.add(new Cube(L, W, H));
	}

	{ // solid cylinder (don't fill 100%, fill with grid of some kind?
		const	double r = 20;
		const double H = 20;
		gc.add(new Cylinder(r, H, facets));
		
	}

	{ // 
		const	double r = 10;
		gc.add(new Sphere(r, facets));
	}

	{
		const double t = 2;
		const	double r = 10;
		gc.add(new SphericalShell(t, r, facets));
	}
#endif
	
	return 0;
}
