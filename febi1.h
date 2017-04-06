// Fig. 19.3: PhoneNumber.h
// PhoneNumber class definition
#ifndef FEBI1_H
#define FEBI1_H

#include <iostream>
#include <string.h>
 using namespace std;

class febi1{
friend ostream &operator<<( ostream &, const febi1 & );
friend istream &operator>>( istream &, febi1 & ); 

private:
 string nama; // 3-digit area code
 string npm; // 3-digit exchange
 }; // end class PhoneNumber
 #endif
