#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int f(int a, int b) { // a = 5, b = 2
    int res = a + b;
    return res;
}
int main() {
    // example for integer operation
    cout << "example for integer operation-----------------------------------" << endl;
    int i1 = 5 + 2;
    int i2 = 5 * 2;
    int i3 = 5 / 2;
    cout << "value of integer 1:  " << i1 << endl;
    cout << "value of integer 2:  " << i2 << endl;
    cout << "value of integer 3:  " << i3 << endl;
    // example for floating point number
    cout << "example for floating point number------------------------------" << endl;
    float r1 = 5 / 2;
    cout << "r1 = " << r1 << endl;
    float r2 = 5 / 2.0;
    cout << "r2 = " << r2 << endl;
    float r3 = 10 / 3.0;
    cout << "r3 = " << setprecision(8) << r3 << endl;
    // example for array & dynamic array
    cout << "example for array & dynamic array------------------------------" << endl;
    int arr[10]; // no initialized, random garbage
    int* arrD =  new int[10](); // initialized, with default value 0
    // for dynamic array
    cout << "the size of *arrD = " << sizeof(*arrD) << endl; // size of 1st element for this array
    cout << "the size of arrD = " << sizeof(arrD) << endl; // size of the pointer arrD
    // for array
    cout << "the size of arr = " << sizeof(arr) << endl; // size of the arr
    cout << "the size of integer(32 bit): " << sizeof(int) << endl;
    cout << "Elements contained in arr:" << endl;
    for (int i = 0; i < 10; i++) { // len of array = sizeof(arr)/sizeof(int)
        cout << arr[i] << ",";
    }
    cout << endl;
    cout << "Elements contained in arrD:----------------------------------" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arrD[i] << ",";
    }
    cout << endl;
    cout << "function ------------------------------" << endl;
    int a = 5;
    int b = 2;
    int res = f(a, b);
    cout << res << endl;
    return 0;
}

