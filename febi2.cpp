// Fig. 19.4: PhoneNumber.cpp
// Overloaded stream insertion and stream extraction operators
// for class PhoneNumber.
#include <iomanip>
#include "febi1.h"
using namespace std;

// overloaded stream insertion operator; cannot be a member function if we would like to invoke it with  cout << somePhoneNumber;
ostream &operator<<( ostream &output, const febi1 &data )
{ output <<"Nama : "<<data.nama<< endl <<"NPM : "<< data.npm;
return output; // enables cout << a << b << c;
} // end function operator<<  overloaded stream extraction operator; cannot be a member function if we would like to invoke it with cin >> somePhoneNumber;

istream &operator>>( istream &input, febi1 &data )
{ input.ignore(); // skip (
input >> setw( 10 ) >> data.npm; // input area code
input.ignore(); // skip ) and space
input >> setw( 4 ) >> data.nama; // input exchange
input.ignore(); // skip dash (-)
return input; // enables cin >> a >> b >> c;
} // end function operator>>
