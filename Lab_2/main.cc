#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

// int
int gcd(int a, int b);
bool isPrime(int a);
int countPrimes(int a, int b);
// float
float sum_forward(int n);
float sum_backward(int n);
double hypot(double a, double b);
// array
void double_each(int a[], int n);
float mean(float x[], int n);
int prod(int x[], int n);


int main() {
    //------------------------integer part
    cout << "part 1 output:" << endl;
    cout << "gcd(12, 18)=" << gcd(12, 18) << endl;
    cout << "gcd(1025, 3025)=" << gcd(1025, 3025) << endl;
    cout << "isPrime(5)=" << isPrime(5) << endl;
    cout << "isPrime(9)=" << isPrime(9) << endl;
    cout << "isPrime(1001)=" << isPrime(1001) << endl;
    cout << "isPrime(2601)=" << isPrime(2601) << endl;
    cout << "isPrime(1013)=" << isPrime(1013) << endl;
    cout << "countPrimes(1,100): " << countPrimes(1, 100) << endl;
    cout << "countPrimes(1,10000): " << countPrimes(1, 10000) << endl;
    
    //------------------------floating point number part
    cout << "part 2 output:" << endl;
    float ans_1 = sum_forward(100);
    float ans_2 = sum_backward(100);
    cout << setprecision(8)<< ans_1 << endl;
    cout << setprecision(8) << ans_2 << endl;
    cout << "hypot(3,4)=" << hypot(3, 4) << endl; // should print 5
    cout << "hypot(4,5)=" << hypot(4, 5) << endl;
    //------------------------array part
    cout << "part 3 output:" << endl;
    float x[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(x)/sizeof(float);
    cout << mean(x, n) << endl; // should print 35
    float y[] = {1.0, 2.0, 3.0, 4.0};
    cout << mean(y, sizeof(y)/sizeof(float)) << endl; // should print 2.5
    int z[] = {10, 20, 30, 40, 50, 60};
    int z_len = sizeof(z)/sizeof(int);
    double_each(z, z_len);
    for (int i = 0; i < z_len; i++) {
        cout << z[i] << ",";
    }
    cout << endl;
    int a[] = {3, 4, 1, 2, -2};
    cout << prod(a, sizeof(a)/sizeof(int)) << endl;
    int b[] = {2, 4, 8, -2, -4};
    cout << prod(b, sizeof(b)/sizeof(int)) << endl;
    
    return 0;
}
