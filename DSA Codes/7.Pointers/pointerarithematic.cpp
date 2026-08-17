// Pointer Arithmetic with Normal Variables
// Different Data Types

#include <iostream>
using namespace std;

int main()
{
     // =================================================
     // 1. INT
     // =================================================

     int a = 10;

     int *ip = &a;

     cout << "INT" << endl;
     cout << "Value: " << *ip << endl;
     cout << "Address: " << ip << endl;

     // Pointer increment
     ip++;
     cout << "After ip++: " << ip << endl;

     // Pointer decrement
     ip--;
     cout << "After ip--: " << ip << endl;

     // =================================================
     // 2. CHAR
     // =================================================

     char c = 'A';

     char *cp = &c;

     cout << "\nCHAR" << endl;
     cout << "Value: " << *cp << endl;
     cout << "Address: " << static_cast<void *>(cp) << endl;

     // char normally takes 1 byte
     cp++;
     cout << "After cp++: "
          << static_cast<void *>(cp) << endl;

     cp--;
     cout << "After cp--: "
          << static_cast<void *>(cp) << endl;

     // =================================================
     // 3. FLOAT
     // =================================================

     float f = 10.5f;

     float *fp = &f;

     cout << "\nFLOAT" << endl;
     cout << "Value: " << *fp << endl;
     cout << "Address: " << fp << endl;

     fp++;
     cout << "After fp++: " << fp << endl;

     fp--;
     cout << "After fp--: " << fp << endl;

     // =================================================
     // 4. DOUBLE
     // =================================================

     double d = 20.5;

     double *dp = &d;

     cout << "\nDOUBLE" << endl;
     cout << "Value: " << *dp << endl;
     cout << "Address: " << dp << endl;

     dp++;
     cout << "After dp++: " << dp << endl;

     dp--;
     cout << "After dp--: " << dp << endl;

     // =================================================
     // 5. SHORT
     // =================================================

     short s = 100;

     short *sp = &s;

     cout << "\nSHORT" << endl;
     cout << "Value: " << *sp << endl;
     cout << "Address: " << sp << endl;

     sp++;
     cout << "After sp++: " << sp << endl;

     sp--;
     cout << "After sp--: " << sp << endl;

     // =================================================
     // 6. LONG
     // =================================================

     long l = 1000;

     long *lp = &l;

     cout << "\nLONG" << endl;
     cout << "Value: " << *lp << endl;
     cout << "Address: " << lp << endl;

     lp++;
     cout << "After lp++: " << lp << endl;

     lp--;
     cout << "After lp--: " << lp << endl;

     // =================================================
     // 7. LONG LONG
     // =================================================

     long long ll = 100000;

     long long *llp = &ll;

     cout << "\nLONG LONG" << endl;
     cout << "Value: " << *llp << endl;
     cout << "Address: " << llp << endl;

     llp++;
     cout << "After llp++: " << llp << endl;

     llp--;
     cout << "After llp--: " << llp << endl;

     // =================================================
     // IMPORTANT
     // =================================================

     // Pointer arithmetic changes the address according
     // to the size of the pointer's data type.

     cout << "\nSIZE OF DATA TYPES" << endl;

     cout << "sizeof(char): " << sizeof(char) << " byte(s)" << endl;
     cout << "sizeof(short): " << sizeof(short) << " byte(s)" << endl;
     cout << "sizeof(int): " << sizeof(int) << " byte(s)" << endl;
     cout << "sizeof(float): " << sizeof(float) << " byte(s)" << endl;
     cout << "sizeof(double): " << sizeof(double) << " byte(s)" << endl;
     cout << "sizeof(long): " << sizeof(long) << " byte(s)" << endl;
     cout << "sizeof(long long): " << sizeof(long long) << " byte(s)" << endl;

     cout << "Playing With Numbers: " << endl;
     int g = 4;
     int *pointer = &g;
     cout << *pointer << endl;
     (*pointer)--;
     cout << *pointer << endl;
     return 0;
}
// IMPORTANT:
// p + 1, p - 1, p++, p-- are meaningful
// when working inside the same array/object sequence.
// For separate normal variables a and b,
// pointer arithmetic cannot be used to safely reach b.
// Pointer increment
// p++ moves the pointer by sizeof(int) bytes
// But p++ on a pointer to a single normal variable
// does NOT mean it will point to variable b.
