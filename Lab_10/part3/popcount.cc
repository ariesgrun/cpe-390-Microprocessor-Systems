#include <iostream>
#include <immintrin.h>
#include <time.h>
// ?#include <nmmintrin.h>

using namespace std;
/*
	write code to traverse the array and count all the 1 bits
	00000000000001   0000000000000010    00000000000011  000000000000100 0000000000101
               1 +               1 +               2 +             1 +           2 + ...
 */
uint32_t countBits(uint32_t x[], uint32_t n);

/*
  now, do it using intel intrinsics
	https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
  the intel instruction to count bits is called _mm_popcnt_u32
*/
uint32_t countBits2(uint32_t x[], uint32_t n);

/*
Extra credit: do it 64 bits at a time for higher speed
__int64 _mm_popcnt_u64 (unsigned __int64 a)

Extra, extra credit. Do it 256 bits at a time
__m256i _mm256_maskz_popcnt_epi64 (__mmask8 k, __m256i a)

Using the avx2 vector registers is signfiicantly harder but if you can do it, just cite where you got the information. Copying is not bad, it's smart (just cite your sources)
*/

int main() {
  const int n = 1000000000;
  uint32_t* p = new uint32_t[n];
  for (int i = 0; i < n; i++)
    p[i] = i;

	clock_t t0 = clock();
	//uint32_t ans = countBits(p, n);
	uint32_t ans = countBits2(p, n);

	clock_t t1 = clock();
	cout << "Elapsed: " << (t1-t0) << '\n';
	cout << ans << '\n';
  delete [] p;

}
