#include <iostream>
#include "ComplexNumber.h"

using namespace std;
/**
 *Main : Tests ComplexNumber Class. 
 *
 * Takes input from terminal to create two ComplexNumbers
 * C1 and C2.
 *
 * First calls arthimetic operators + - * that should return
 * value of the operation without modifying original complex
 * number C1 and C2.
 *
 * Then calls assignment operators += -= *= that
 * should modify and return the new value of C1. 
 *
 **/




int main() {

ComplexNumber C1;
ComplexNumber C2;

cout << "Enter a complex number C1: ";
cin >> C1;

cout << "Enter a complex number C2: ";
cin >> C2;

cout << "For C1 = " << C1 << " and C2 = " << C2 << " :" << endl;
cout << "C1 + C2 = " << (C1 + C2) << endl;
cout << "C1 - C2 = " << (C1 - C2) << endl; 
cout << "C1 * C2 = " << (C1 * C2) << endl;
cout << "C1 == C2 is " << boolalpha << (C1 == C2) << endl;
cout << "C1 != C2 is " << boolalpha << (C1 != C2) << endl;
cout << "After C1 += C2, C1 = " << (C1 += C2) << endl;
cout << "After C1 -= C2, C1 = " << (C1 -= C2) << endl;
cout << "After C1 *= C2, C1 = " << (C1 *= C2) << endl;

return 0;
}
