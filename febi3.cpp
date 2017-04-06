// Fig. 19.5: fig19_05.cpp
// Demonstrating class PhoneNumber's overloaded stream insertion
// and stream extraction operators.
#include <iostream>
#include "FEBI1.h"
#include "febi2.cpp "

using namespace std;
int main()
{
febi1 mhs;
cout << "Masukan Nama Anda data dengan format 0615103030#FEBI#: " << endl;
cin >> mhs;
cout << "Data yang anda masukan : " << endl;
cout << mhs;

}

