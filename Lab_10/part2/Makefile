bench: bench.cc asm.s funcs.cc 
	g++ -g -O2 -c bench.cc
	g++ -c asm.s
	g++ -g -O2 -mavx2 -c funcs.cc
	g++ -g bench.o asm.o funcs.o -o bench

clean:
	rm *.o bench
	
