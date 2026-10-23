#include <iostream>
#include <cstring>
#include "funcs.hh"
#include <fstream>
#include <time.h>
using namespace std;

const int tries = 3;

template<typename Func>
void benchmark(const char msg[], Func f, uint64_t n) {
	cout << msg << ":\t";
	for (int i = 0; i < tries; i++) {
		clock_t t0 = clock();
		f(n);
		clock_t t1 = clock();
		cout << (t1-t0) << '\t';
	}
	cout << '\n';
}

template<typename Func>
void benchmark_array(const char msg[], Func f, uint64_t a[], uint64_t n) {
	cout << msg << ":\t";
	for (int i = 0; i < tries; i++) {
		clock_t t0 = clock();
		f(a, n);
		clock_t t1 = clock();
		cout << (t1-t0) << '\t';
	}
	cout << '\n';	
}

template<typename Func>
void benchmark_array2(const char msg[], Func f, uint64_t a[], uint64_t n, uint64_t k) {
	cout << msg << ":\t";
	for (int i = 0; i < tries; i++) {
		clock_t t0 = clock();
		f(a, n, k);
		clock_t t1 = clock();
		cout << (t1-t0) << '\t';
	}
	cout << '\n';	
}

template<typename Func>
void benchmark_array3(const char msg[], Func f, uint64_t crc, uint64_t a[], uint64_t n) {
	cout << msg << ":\t";
	for (int i = 0; i < tries; i++) {
		clock_t t0 = clock();
		f(crc, a, n);
		clock_t t1 = clock();
		cout << (t1-t0) << '\t';
	}
	cout << '\n';	
}

template<typename Func>
void benchmark_array4(char msg[], Func f, const uint64_t a[], uint64_t n) {
	cout << msg << ":\t";
	for (int i = 0; i < tries; i++) {
		clock_t t0 = clock();
		f((char*)a, n);
		clock_t t1 = clock();
		cout << (t1-t0) << '\t';
	}
	cout << '\n';		
}


int main() {
	const uint64_t n1 = 1000000000;

	// benchmark("count up from 0 to n-1 ", f1a, n1);
	// benchmark("count n downto 1       ", f1b, n1);

	// //f3 should count down without using compare against zero
	// benchmark("count n downto 1       ", f1c, n1);

	// benchmark("sum numbers 1 to n     ", f2a, n1);
	// benchmark("product numbers 1 to n ", f2b, n1);
	benchmark("sum of fractions       ", f2c, n1);
	
	const uint64_t n2 = 100000000;

	uint64_t* p = new uint64_t[n2];
	benchmark_array ("read in 64-bit numbers ", f3a, p, n2);

	benchmark_array ("read 64-bit every 2    ", f3b, p, n2);

	benchmark_array2("read 64-bit k=4        ", f3c, p, n2, 4);
	benchmark_array2("read 64-bit k=8        ", f3c, p, n2, 8);
	benchmark_array2("read 64-bit k=16       ", f3c, p, n2, 16);
	benchmark_array2("read 64-bit k=32       ", f3c, p, n2, 32);
	benchmark_array2("read 64-bit k=1k       ", f3c, p, n2, 1024);

	benchmark_array ("write 64-bit seq       ", f3d, p, n2);
	benchmark_array2("write 64-bit k=2       ", f3e, p, n2, 2);
	benchmark_array2("write 64-bit k=4       ", f3e, p, n2, 4);
	benchmark_array2("write 64-bit k=8       ", f3e, p, n2, 8);
	benchmark_array2("write 64-bit k=16      ", f3e, p, n2, 16);
	benchmark_array2("write 64-bit k=32      ", f3e, p, n2, 32);
	benchmark_array2("write 64-bit k=1024    ", f3e, p, n2, 1024);

	char msg1[] = "testing testing 123";
	const uint32_t msg1len = strlen(msg1);
	xor_crypt(msg1, msg1len, 11); // xor with the character whose code is 11 (control-k)
	cout << msg1 << '\n';
	xor_crypt(msg1, msg1len, 11); // xor with the same key to unencrypt
	cout << msg1 << '\n';

	const char mykey[] = {"\xc\x11\x9"};
	dov(msg1, msg1len, mykey);
	cout << "encoded using DOV:    " << msg1 << '\n';
	dov(msg1, msg1len, mykey);
	cout << "decoded using DOV:    " << msg1 << '\n';
	
	//benchmark_array4("xor bytewise          ", xor_crypt, p, n2);
	//benchmark_array4("dov encryption        ", dov, (char*)p, n2);
	//benchmark_array4("dov 64-bit at a time  ", dov8, (char*)p, n2);
	
	delete [] p;
}
