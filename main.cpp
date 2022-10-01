// abs complex example
#include <iostream>     // std::cout
#include <complex>      // std::complex, std::abs
using namespace std;

int main ()
{
    double re = -0.77568377;
    double im = 0.13646737;
    complex<double> c (re, im);
    complex<double> z (0,0);
    cout << "c = " << c << "\t";
    cout << "|c| = " << abs(c) << endl;
    cout << "Real component of c: " << c.real() << endl;
    cout << "Imaginary component of c: " << c.imag() << endl;
    z = z*z + c;
    cout << "z_2 = " << z << "\t";
    cout << "|z_2| = " << abs(z) << endl;
    z = z*z + c;
    cout << "z_3 = " << z << "\t";
    cout << "|z_3| = " << abs(z) << endl;
    return 0;
}
