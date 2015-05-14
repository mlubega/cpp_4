#include <iostream>
#include "ComplexNumber.h"
#include <ctype.h>

using namespace std;

/////////////// START MEMBER FUNCTIONS  ////////////////////////////////////////


//////////////////////// constructors ///////////////////////


/**Constructor
 *
 * No args-values preset to 0.0
 **/
ComplexNumber::ComplexNumber() :
	real(0.0), imag(0.0) {}

/** Constructor
 *
 * @param real_part: real number
 * @param imaginary_part: imaginary number  
 *
 **/
ComplexNumber::ComplexNumber(double real_part, double imaginary_part) :
	real(real_part), imag(imaginary_part) {}
	
/** Copy Constructor
 *
 * @param rhs : reference to an existing Complex Number
 **/
ComplexNumber::ComplexNumber(const ComplexNumber & rhs) :
	real(rhs.real), imag(rhs.imag) {}


///////////////////// named member functions //////////////////////

/** Print
 * Displays Complex Number in the format ( A + Bi) where
 * A is the real number and B the imaginary.
 *
 * @param out : out stream
 *
 **/
void ComplexNumber::print(ostream & out) const {
	if (real < 0)
		cout << '-';
	cout << real;
	char value;
	value =	(imag < 0) ?  '-' :  '+';
	
	if(imag < 0){
	        double temp = imag;
		cout << value << (temp * -1)  << 'i'; 
	} 
	else{	
		cout << value << imag  << 'i' ;  
	}
}

/** Equals
 *	-Compares real and imaginary numbers of two Complex Numbers
 *
 * @param rhs: reference to Complex Number
 * @return bool: true if equivalent, false otherwise
 */

bool ComplexNumber::equals(const ComplexNumber & rhs) const {
	return (real == rhs.real) && (imag == rhs.imag);
}


   ///////////// assignment operators //////////////


/** operator= 
 *	Assigns *this Complex Number the value of rhs
 *	(A + Bi) = (C + Di) 
 *
 * @param rhs: reference to a Complex number
 * @return const ComplexNumber & : *this ComplexNumber, modified
 *
 **/
const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs){
	if(this == &rhs) 
		return *this;
	real = rhs.real;
	imag = rhs.imag;
	return *this;
}
/** operator+= 
 *	Performs addition and modifies the left hand operator
 *	(A + Bi) + (C + Di) = (A + C) + (B + D)i
 *
 * @param rhs: reference to a Complex number
 * @return const ComplexNumber & : *this ComplexNumber, modified
 *
 **/
const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs){
	real += rhs.real;
	imag += rhs.imag;
	return *this;
}
/** operator-= 
 *	Performs subtraction and modifies the left hand operator
 *	(A + Bi) - (C + Di) = (A - C) + (B - D)i
 *
 * @param rhs: reference to a Complex number
 * @return const ComplexNumber & : *this ComplexNumber, modified
 *
 **/
const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs){
	real -= rhs.real;
	imag -= rhs.imag;
	return *this;
}
/** operator*= 
 *	Performs multiplication  and modifies the left hand operator
 *	(A + Bi) * (C + Di) = (A*C - B*D) + (A*D + B*C)i
 *
 * @param rhs: reference to a Complex number
 * @return const ComplexNumber & : *this ComplexNumber, modified
 *
 **/
const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs){
	double real_tmp = real;
	double imag_tmp = imag;
	real  = (real_tmp*rhs.real) - (imag_tmp*rhs.imag);
	imag = (real_tmp*rhs.imag) + (imag_tmp *rhs.real);
	return *this;
}                             

///////////////////////////////// END MEMBER FUNCTIONS ///////////////////////////

//////////////////// arithmetic operators//////////////////




/** operator+ 
 *	Makes a copy of lhs and calls += member function to perform addition
 *	using the copy.
 *	
 *
 * @param lhs: Left Hand Side- reference to a Complex number
 * @param rhs: Right Hand Side- reference to a Complex number
 * @return ComplexNumber: Complex Number with sum results
 *
 **/
ComplexNumber::ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber nums(lhs);
	nums += rhs;
	return nums;
}
/** operator- 
 *	Makes a copy of lhs and calls -= member function to perform subtraction
 *	using the copy.
 *	
 *
 * @param lhs: Left Hand Side- reference to a Complex number
 * @param rhs: Right Hand Side- reference to a Complex number
 * @return ComplexNumber: Complex Number with subtraction results
 *
 **/
ComplexNumber::ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber nums(lhs);
	nums -= rhs;
	return nums;
}
/** operator* 
 *	Makes a copy of lhs and calls *= member function to perform multiplication
 *	using the copy.
 *	
 *
 * @param lhs: Left Hand Side- reference to a Complex number
 * @param rhs: Right Hand Side- reference to a Complex number
 * @return ComplexNumber: Complex Number with multiplication results
 *
 **/
ComplexNumber::ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber nums(lhs);
	nums *= rhs;
	return nums;
}



/////////////////////////// relational operators  ///////////////////////////



/** operator== 
 *	Calls equals member function to determine if two Complex Numbers
 *	are equal (lhs.real == rhs. real) && (lhs.imag == rhs.imag)
 *	
 *
 * @param lhs: Left Hand Side- reference to a Complex number
 * @param rhs: Right Hand Side- reference to a Complex number
 * @return bool: True if equal/ False otherwise
 *
 **/


bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
	return (lhs.equals(rhs));
} 
/** operator!= 
 *	Calls equals member function to determine if two Complex Numbers
 *	are equal and negates the result
 *	
 *
 * @param lhs: Left Hand Side- reference to a Complex number
 * @param rhs: Right Hand Side- reference to a Complex number
 * @return bool: True if unequal/ False if equal
 *
 **/
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
	return !(lhs.equals(rhs)); 
}


////////////////////////////// I/O operators/////////////////////////////////////




/** operator<<
 *
 *	Calls print member function to display a Complex Number
 *
 * @param & out : reference to out stream
 * @param const ComplexNumber &: reference to Complex number to be displayed
 * @return & out: reference to out stream for chaining purposes
 *
 **/
ostream & operator<<(ostream & out, const ComplexNumber & n){
	n.print(out);
	return out;
}

/** operator>>
 *
 *	Reads from input stream to construct a ComplexNumber
 *	Expects  A  < + - operator> Bi  
 *	 A = real
 *	 B = imaginary
 *	 whitespaces are variable
 *	 A and B can be either negative or positive 
 *
 * @param & in : reference to in stream
 * @param ComplexNumbern & n  : local of new  ComplexNumber 
 * @return istream & : reference to in  stream for chaining purposes
 *
 **/
istream & operator>>(istream & in, ComplexNumber & n){
	double real;
	double imag;
	char ch;	
	
	//process white space
	in.get(ch);
	while (ch == ' ' || ch == '\n' || ch == '\t') {
		in.get(ch);
	}

	//check if real is negative
	if (ch == '-') {
		in >> real; //get real number
		real = real * -1;
	// if real is positive
	} else if (isdigit(ch)) {
		in.putback(ch);
		in >> real;  // get real number
	//otherwise an error
	} else {
		in.setstate(ios::failbit);
		return in;
	}

	//process whitespace
	in.get(ch);
	while (ch == ' ' || ch == '\n' || ch == '\t'){
		in.get(ch);
	}
	//check for valid operator
	if (ch != '+' && ch != '-'){ 
		in.setstate(ios::failbit);
		return in;	
	}

	
	in >> imag; //get imaginary number

	//use operator to deterine pos/neg value of 
	//imaginary number
	if (ch == '-'){
		imag = imag * -1;
	}

	//process whitespace
	in.get(ch);
	while (ch == ' ' || ch == '\n' || ch == '\t'){
		in.get(ch);
	}

	//check for 'i' char at the end
	if(ch != 'i'){
		in.setstate(ios::failbit);
		return in;
	}

	//create new number
	n = *(new ComplexNumber(real, imag));

	return in;
}


