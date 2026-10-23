#pragma once
#include <iostream>

//counting
uint64_t f1a(uint64_t n); //count from 0 to n-1
uint64_t f1b(uint64_t n);  // count from n down to 1 (stop at zero)
uint64_t f1c(uint64_t n); // count from n down to 1 without the cmp instuint64_t64-bit math in Intel Assembler

uint64_t f2a(uint64_t n); // the sum of numbers from 1 to n
uint64_t f2b(uint64_t n); // n factorial

// do this in C++ (we don't know the divide instruction, so let the compiler figure it out)
// return the sum 1/2 + 2/3 + 3/4 + ... + n/(n+1). This is zero but C++ won't know that. Let's see how long it takes
uint64_t f2c(uint64_t n);

//memory reads
uint64_t f3a(uint64_t a[], uint64_t n); // read sequentially through array

/*
	read elements 0, 2, 4, ...
	then          1, 3, 5, ...

	In other words, read the same number of elements as f4, but a bit out of order
*/
uint64_t f3b(uint64_t a[], uint64_t n);

/*
	same but every k elements
	for example, if k = 4
	start with 0, 4, 8, ...
	start with 1, 5, 9, ...
	start with 2, 6, 10, ...
	start with 3, 7, 11, ...

	so you are adding up all the same elements, you are just doing it in a suboptimal order to see how much slower it is when you skip k
	We will test this for k=4, 8, 16, 32, and 1024
 */
uint64_t f3c(
	uint64_t a[], uint64_t n, uint64_t k);

//memory writing sequentially (probably no caching on pc)
uint64_t f3d(uint64_t a[], uint64_t n);

// memory writing, but starting at same but every k elements
uint64_t f3e(uint64_t a[], uint64_t n, uint64_t k);


/*
	given a message msg and a length, xor each letter in the message with the one-byte key.

	Since xor is its own inverse, you can unencrypt by simply calling this fcuntion again on the encrypted message.

	This is incredibly poor encryption, because for each letter, there will be exactly one answer, and since we know the frequency of letters in English, we can quickly find the most common letters and use it to break the code (or just brute force try every key since there are only 256 possible keys).
	The frequency for English starting from the most common is ETAON...
	https://en.wikipedia.org/wiki/Letter_frequency
 */
void xor_crypt(char msg[], uint64_t len, char key);

/*
	The "Data Overlay Vector" (Dov) encryption method.
	suppose your key is "dov" and your message is
	"this is a test"
	xor each letter with a letter in the key. When the key is exhausted
	start over

	In this example

	this is a test
	dovdovdovdovdo
	==============

	Note: xoring 't' with 'd' will result in a non-printable character, so we might have to print it out as an integer to even see it.
 */
void dov(char msg[], uint64_t len, const char key[]);

/*
	Much faster implementation of the Dov encryption method
	for a 64-bit computer and a long message: do 8-byte chunks
	at once since your computer can do them in a single operation.

	this is a test, this is a very long string....
	dovdovdo
	        vdovdovd
                  ovdovdov
                          here you can start with the first one again
													
	Notice you have to precompute 3 64-bit words because my key is 3 bytes long, so each one shifts, but after 3 times you are right back where you started. The worst case would be a key 7 letters long. If my key is 8 letters long it works right away.
 */

void dov8(char msg[], uint32_t len, const char key[]);

