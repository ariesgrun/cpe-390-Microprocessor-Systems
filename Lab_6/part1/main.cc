#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

// TODO:
extern uint64_t count(int val);
extern uint64_t sumsq(const uint64_t a[], uint32_t len);
extern void add1(uint64_t a[], uint32_t len);
extern uint64_t replaceZero(uint64_t val);
extern uint64_t replaceOne(uint64_t val);
extern uint64_t toggles(uint64_t val);
extern uint64_t replaceD(uint64_t val);
//Please declare the function and create the test case yourself for the extra points function.

void print(const uint64_t a[], uint32_t len) {
    for (int i = 0; i < 4; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}


int main() {
// question 1: --------------------------
    count(20);

// question 2: --------------------------
    const uint64_t a[] = {9, 1, 2, 4};
    const uint32_t lena = sizeof(a)/sizeof(uint64_t);
    const uint64_t temp = sumsq(a, lena);
    cout << temp << endl;

// question 3: --------------------------
    uint64_t b[] = {5, 3, 6, 7, 4, 9};
    const uint32_t lenb = sizeof(b)/sizeof(uint64_t);
    add1(b, lenb);
    print(b, lenb);

// question 4: --------------------------
    const uint64_t t1 = 0xF2ECBABE;
    uint64_t res4 = replaceZero(t1);
    cout << "Binary:" << bitset<64>(res4) << endl;
    cout << hex << "Hex: " << res4 << endl;

// question 5: --------------------------
    const uint64_t t2 = 0xF2ECBABE;
    uint64_t res5 = replaceOne(t2);
    cout << "Binary: " << bitset<64>(res5) << endl;
    cout << hex << "Hex: " << res5 << endl;

// question 6: --------------------------
    const uint64_t t3 = 0xF2ECBABE;
    uint64_t res6 = toggles(t3);
    cout << "Binary: " << bitset<64>(res6) << endl;
    cout << hex << "Hex: " << res6 << endl;

// question 7: --------------------------
    uint64_t t = 0x987654321C9;
    uint64_t res = replaceD(t);
    cout << "Binary: " << bitset<64>(res) << endl;
    cout << hex << "Hex: " << res << endl;
// extra points function: ----------------

    return 0;
}
