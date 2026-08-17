# POINTERS IN C++

## Detailed Notepad-Style Notes

============================================================

1. # POINTERS - BASIC INTRODUCTION

- Pointer C++ ka ek special variable hota hai.
- Normal variable kisi value ko store karta hai.
- Pointer kisi doosre variable/object ka memory address store karta hai.
- Isliye pointer ko "address storing variable" bhi kaha ja sakta hai.

Example:

int x = 10;
int\* p = &x;

Yahan:

x -> 10 store karta hai
&x -> x ka address deta hai
p -> x ka address store karta hai
\*p -> x ki value deta hai

Simple relation:

x = value
&x = address of x
p = address stored in pointer
\*p = value at that address

============================================================ 2. POINTER KI ZAROORAT KYON PADTI HAI?
============================================================

Pointers ka use mainly in situations mein hota hai:

- Memory address ke saath directly kaam karne ke liye.
- Function ke andar original variable ko modify karne ke liye.
- Dynamic memory allocation ke liye.
- Arrays ko efficiently access karne ke liye.
- Strings ke saath kaam karne ke liye.
- Linked List banane ke liye.
- Stack aur Queue jaise dynamic data structures implement karne ke liye.
- Trees aur Graphs implement karne ke liye.
- Objects ko dynamically create/manage karne ke liye.
- Function pointers aur callbacks ke liye.
- Low-level/system programming mein.
- Memory management ko samajhne ke liye.

============================================================ 3. MEMORY ADDRESS KYA HOTA HAI?
============================================================

- Computer memory ko bahut saare locations/bytes ka collection
  samjha ja sakta hai.
- Har memory location ka ek address hota hai.
- Variable memory mein kisi location par store hota hai.

Example:

int x = 10;

Conceptually maan lo:

## Address Value

1000 10

To:

x = 10
&x = 1000

Agar:

int\* p = &x;

To:

p = 1000
\*p = 10

NOTE:

- 1000 sirf example hai.
- Actual memory address system aur program execution ke
  according different ho sakta hai.

============================================================ 4. POINTER DECLARATION
============================================================

General syntax:

data_type\* pointer_name;

Examples:

int* p;
float* q;
char* r;
double* s;

Meaning:

int\* p;

- p ek pointer hai jo int type ke object ko point kar sakta hai.

float\* q;

- q float object ka address store kar sakta hai.

char\* r;

- r char object ka address store kar sakta hai.

double\* s;

- s double object ka address store kar sakta hai.

============================================================ 5. POINTER INITIALIZATION
============================================================

Pointer ko declare karne ke baad valid address dena chahiye.

Example:

int x = 10;
int\* p = &x;

Yahan p properly initialized hai.

Null initialization:

int\* p = nullptr;

Yahan p kisi valid object ko point nahi kar raha.

Best practice:

int\* p = nullptr;

============================================================ 6. ADDRESS-OF OPERATOR &
============================================================

- & ko address-of operator kaha jata hai.
- Ye kisi variable ka memory address return karta hai.

Example:

int x = 10;

cout << &x;

Output kuch is tarah ho sakta hai:

0x7ffd12345678

Exact address fixed nahi hota.

Example:

int x = 10;
int\* p = &x;

Yahan:

&x
-> x ka address.

p
-> wahi address store karta hai.

Therefore:

p == &x

============================================================ 7. DEREFERENCE OPERATOR \*
============================================================

- Pointer ke saath \* use karne par ise dereference operator
  kaha jata hai.
- Dereferencing ka matlab hai pointer mein stored address par
  jo value/object hai, usko access karna.

Example:

int x = 50;
int\* p = &x;

cout << \*p;

Output:

50

Explanation:

p -> x ka address
\*p -> x ki value

============================================================ 8. DECLARATION MEIN _ AUR DEREFERENCE MEIN _ KA DIFFERENCE
============================================================

Example:

int\* p;

Yahan \* declaration ka part hai.

Meaning:

p is a pointer to int.

Example:

cout << \*p;

Yahan \* dereference operator hai.

Meaning:

p jis object ko point kar raha hai uski value access karo.

============================================================ 9. POINTER KA COMPLETE BASIC EXAMPLE
============================================================

#include <iostream>
using namespace std;

int main()
{
int x = 10;

    int* p = &x;

    cout << "Value of x = " << x << endl;
    cout << "Address of x = " << &x << endl;
    cout << "Value of p = " << p << endl;
    cout << "Value pointed by p = " << *p << endl;

    return 0;

}

Expected concept:

x -> 10
&x -> address of x
p -> address of x
\*p -> 10

============================================================ 10. POINTER SE ORIGINAL VALUE CHANGE KARNA
============================================================

Pointer ke through original variable ki value change ki ja sakti hai.

Example:

int x = 10;
int\* p = &x;

\*p = 100;

cout << x;

Output:

100

Explanation:

p x ka address contain karta hai.

\*p x ko represent karta hai.

Isliye:

\*p = 100;

ka effect:

x = 100;

jaisa hota hai.

============================================================ 11. POINTER MEMORY MODEL
============================================================

Example:

int x = 10;
int\* p = &x;

Conceptually:

Memory:

Address 2000
+----------------+
| 10 |
+----------------+
x

p ke andar:

+----------------+
| 2000 |
+----------------+

Therefore:

x = 10
&x = 2000
p = 2000
\*p = 10

NOTE:

- Actual address example sirf understanding ke liye hai.

============================================================ 12. NULL POINTER / nullptr
============================================================

- A pointer jo kisi valid object ko point nahi karta,
  use null pointer kaha jata hai.
- Modern C++ mein nullptr use kiya jata hai.

Example:

int\* p = nullptr;

Check:

if (p == nullptr)
{
cout << "Pointer is null";
}

IMPORTANT:

nullptr ko dereference nahi karna chahiye.

Wrong:

int\* p = nullptr;

cout << \*p;

Ye undefined behavior hai.

============================================================ 13. UNINITIALIZED / WILD POINTER
============================================================

Example:

int\* p;

- p declared hai lekin initialized nahi hai.
- Isme koi valid known address hona guaranteed nahi hai.

Wrong:

int* p;
cout << *p;

Better:

int\* p = nullptr;

ya:

int x = 10;
int\* p = &x;

============================================================ 14. POINTER TO POINTER
============================================================

- Ek pointer kisi doosre pointer ka address bhi store kar sakta hai.

Example:

int x = 10;

int\* p = &x;

int\*\* q = &p;

Relationship:

q
|
v
p
|
v
x
|
v
10

Values:

x = 10
\*p = 10
\*\*q = 10

Explanation:

q
-> p ka address

\*q
-> p

\*\*q
-> x ki value

============================================================ 15. POINTER ARITHMETIC
============================================================

Pointers par arithmetic operations kiye ja sakte hain,
especially arrays ke saath.

Important operations:

- p++
- p--
- p + n
- p - n
- p1 - p2

Example:

int arr[] = {10, 20, 30, 40};

int\* p = arr;

cout << \*p << endl;

p++;

cout << \*p << endl;

Output:

10
20

p++ next element par move karta hai.

============================================================ 16. POINTER ARITHMETIC MEIN sizeof KA ROLE
============================================================

Agar:

int\* p;

aur:

sizeof(int) = 4 bytes

to:

p++

conceptually address ko 4 bytes aage move karega.

Agar:

double\* p;

aur:

sizeof(double) = 8 bytes

to:

p++

conceptually 8 bytes aage move karega.

IMPORTANT:

Pointer arithmetic elements ke according hoti hai,
raw bytes ke according manually nahi.

============================================================ 17. POINTERS AND ARRAYS
============================================================

Array aur pointer ka relation bahut important hai.

Example:

int arr[4] = {10, 20, 30, 40};

Expressions:

arr
&arr[0]

bahut contexts mein same first-element address ko represent karte hain.

Example:

int\* p = arr;

Ab:

_p -> 10
_(p + 1) -> 20
_(p + 2) -> 30
_(p + 3) -> 40

============================================================ 18. ARRAY INDEXING AUR POINTER NOTATION
============================================================

Given:

int arr[4] = {10, 20, 30, 40};

Normal indexing:

arr[0]
arr[1]
arr[2]
arr[3]

Pointer-style:

_(arr + 0)
_(arr + 1)
_(arr + 2)
_(arr + 3)

Important relationship:

arr[i] == \*(arr + i)

Ye C++ ka bahut important pointer/array concept hai.

============================================================ 19. POINTERS AND FUNCTIONS
============================================================

Pointer ko function mein argument ke roop mein pass kiya ja sakta hai.

Example:

void change(int* p)
{
*p = 100;
}

int main()
{
int x = 10;

    change(&x);

    cout << x;

    return 0;

}

Output:

100

Explanation:

change(&x);

- x ka address function ko diya.

Function mein:

int\* p

- us address ko receive karta hai.

\*p = 100;

- original x ko change kar deta hai.

============================================================ 20. CALL BY ADDRESS
============================================================

Pointer use karke function ko variable ka address diya ja sakta hai.

Example:

void update(int* p)
{
*p = 500;
}

int x = 10;

update(&x);

Ab:

x = 500

NOTE:

C++ technically pass-by-value language hai.

Yahan pointer ka value, yani address, function ko copy hokar milta hai.
Us copied address ke through original object access kiya jata hai.

============================================================ 21. SWAP USING POINTERS
============================================================

Example:

void swapValues(int* a, int* b)
{
int temp = \*a;

    *a = *b;

    *b = temp;

}

int main()
{
int x = 10;
int y = 20;

    swapValues(&x, &y);

    cout << x << " " << y;

    return 0;

}

Output:

20 10

============================================================ 22. POINTERS AND STRUCTURES
============================================================

Example:

struct Student
{
int age;
};

int main()
{
Student s;

    Student* p = &s;

    p->age = 20;

    cout << p->age;

    return 0;

}

Output:

20

Pointer ke through structure member access karne ke liye:

->

use hota hai.

============================================================ 23. DOT . VS ARROW ->
============================================================

Agar actual object hai:

Student s;

to:

s.age

use karenge.

Agar pointer hai:

Student\* p = &s;

to:

p->age

use karenge.

Equivalent expression:

p->age

is equivalent to:

(\*p).age

IMPORTANT:

s.age
-> Object ke liye.

p->age
-> Pointer-to-object ke liye.

============================================================ 24. POINTER TO OBJECT
============================================================

Classes ke objects ko bhi pointers point kar sakte hain.

Example:

class Student
{
public:
int marks;
};

int main()
{
Student s;

    Student* p = &s;

    p->marks = 90;

    cout << p->marks;

    return 0;

}

Output:

90

============================================================ 25. CONST POINTERS
============================================================

const ke saath pointers ka behavior carefully samajhna important hai.

---

## A. POINTER TO CONSTANT

const int\* p;

Meaning:

- Pointer ke through value modify nahi kar sakte.
- Pointer ko kisi doosre address par point kar sakte hain.

Example:

int a = 10;
int b = 20;

const int\* p = &a;

p = &b; // Allowed

// \*p = 50; // Not allowed

---

## B. CONSTANT POINTER

int\* const p = &a;

Meaning:

- Pointer ka target change nahi kar sakte.
- Pointed value modify kar sakte hain.

Example:

int a = 10;
int b = 20;

int\* const p = &a;

\*p = 50; // Allowed

// p = &b; // Not allowed

---

## C. CONSTANT POINTER TO CONSTANT

const int\* const p = &a;

Meaning:

- Pointer ko doosre address par nahi le ja sakte.
- Pointer ke through value modify nahi kar sakte.

============================================================ 26. VOID POINTER
============================================================

void\* ek generic pointer type hai.

Example:

int x = 10;

void\* p = &x;

void pointer kisi object ka address hold kar sakta hai,
lekin usko directly normal typed pointer ki tarah dereference
nahi karna chahiye.

Example:

cout << _(static_cast<int_>(p));

Yahan void pointer ko int pointer mein convert kiya gaya.

============================================================ 27. DYNAMIC MEMORY ALLOCATION
============================================================

C++ mein dynamic memory allocation ke liye:

new

use kiya ja sakta hai.

Example:

int\* p = new int;

\*p = 100;

cout << \*p;

Memory release:

delete p;

Better cleanup:

delete p;
p = nullptr;

============================================================ 28. new OPERATOR
============================================================

new dynamically memory allocate karta hai.

Example:

int\* p = new int(10);

Meaning:

- Dynamically ek int object create hua.
- Usme 10 initialize hua.
- p us object ka address store karta hai.

Access:

cout << \*p;

Output:

10

============================================================ 29. delete OPERATOR
============================================================

new se allocate ki gayi memory ko release karne ke liye:

delete

use hota hai.

Example:

int\* p = new int(10);

delete p;

After delete:

- p mein old address reh sakta hai.
- Lekin pointed object destroy ho chuka hai.
- p ko dereference nahi karna chahiye.

Safer:

delete p;
p = nullptr;

============================================================ 30. DYNAMIC ARRAY
============================================================

Dynamic array:

int\* arr = new int[5];

Use:

arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
arr[3] = 40;
arr[4] = 50;

Release:

delete[] arr;

IMPORTANT:

new[] -> delete[]

new -> delete

============================================================ 31. DANGLING POINTER
============================================================

Dangling pointer wo pointer hota hai jo aise memory/object ko
point kar raha ho jo ab valid nahi hai.

Example:

int\* p = new int(10);

delete p;

Ab p ke andar purana address ho sakta hai,
lekin object destroy ho chuka hai.

Isliye:

\*p

use nahi karna chahiye.

Better:

delete p;
p = nullptr;

============================================================ 32. MEMORY LEAK
============================================================

Memory leak tab hota hai jab dynamically allocated memory ko
release nahi kiya jata aur us memory tak access bhi lose ho jata hai.

Example:

void example()
{
int\* p = new int(10);

    // Agar p ka address lose ho gaya aur delete nahi hua,
    // memory leak ho sakta hai.

}

Modern C++ mein ownership ko smart pointers aur RAII ke through
manage karna preferred hai.

============================================================ 33. SMART POINTERS
============================================================

Modern C++ mein manual new/delete ko reduce karne ke liye
smart pointers use kiye ja sakte hain.

Main smart pointers:

- unique_ptr
- shared_ptr
- weak_ptr

Header:

#include <memory>

============================================================ 34. unique_ptr
============================================================

unique_ptr exclusive ownership represent karta hai.

Example:

std::unique_ptr<int> p = std::make_unique<int>(10);

Access:

cout << \*p;

unique_ptr normally copy nahi hota:

// std::unique_ptr<int> p2 = p; // Error

Ownership move ki ja sakti hai:

std::unique_ptr<int> p2 = std::move(p);

============================================================ 35. shared_ptr
============================================================

shared_ptr shared ownership provide karta hai.

Example:

std::shared_ptr<int> p1 = std::make_shared<int>(10);

std::shared_ptr<int> p2 = p1;

Ab p1 aur p2 same object ko own karte hain.

Object tab destroy hota hai jab last owning shared_ptr
release ho jata hai.

============================================================ 36. weak_ptr
============================================================

weak_ptr shared_ptr ke object ko observe karta hai,
lekin ownership share nahi karta.

Ye specially useful hota hai jab shared_ptr relationships
mein ownership cycles ko avoid karna ho.

============================================================ 37. FUNCTION POINTER
============================================================

Pointer kisi function ko bhi point kar sakta hai.

Example:

int add(int a, int b)
{
return a + b;
}

int (\*p)(int, int) = add;

cout << p(10, 20);

Output:

30

Function pointer ka syntax:

int (\*p)(int, int)

Meaning:

p ek pointer hai jo aise function ko point karta hai:

- Return type = int
- Parameter 1 = int
- Parameter 2 = int

============================================================ 38. POINTER TO POINTER - DETAILED
============================================================

Example:

int x = 10;

int\* p = &x;

int\*\* q = &p;

Step 1:

x = 10

Step 2:

p = &x

Therefore:

\*p = x = 10

Step 3:

q = &p

Therefore:

\*q = p

and:

\**q = *p = x = 10

So:

x -> 10
p -> address of x
q -> address of p
*p -> 10
*q -> address of x
\*\*q -> 10

============================================================ 39. POINTERS AND REFERENCES
============================================================

Pointer:

int x = 10;
int\* p = &x;

Reference:

int x = 10;
int& r = x;

Pointer:

- Address store karta hai.
- nullptr ho sakta hai.
- Different objects ko point kar sakta hai.
- - se dereference hota hai.

Reference:

- Existing object ka another name/alias hota hai.
- Initialization ke time bind hota hai.
- Normal reference ko reseat nahi kar sakte.

============================================================ 40. POINTER VS REFERENCE
============================================================

## Feature Pointer Reference

Address semantics Explicit Alias semantics
Can be null Yes No normal null reference
Can be reassigned Yes No
Dereference \* Not required
Member access -> .
Initialization Can be delayed Normally required
Arithmetic Possible Not pointer arithmetic

============================================================ 41. POINTERS AND C-STYLE STRINGS
============================================================

C-style string character array hoti hai jo '\0' par end hoti hai.

Example:

const char\* name = "Hello";

Conceptually:

H -> e -> l -> l -> o -> '\0'

name first character ka address point karta hai.

Modern C++ mein normal text ke liye:

std::string

generally preferred hai.

============================================================ 42. POINTERS AND 2D ARRAYS
============================================================

Example:

int arr[2][3] =
{
{1, 2, 3},
{4, 5, 6}
};

Pointer:

int (\*p)[3] = arr;

Yahan p ek row ko point karta hai,
jisme 3 integers hain.

IMPORTANT DIFFERENCE:

int (\*p)[3]

- Pointer to an array of 3 integers.

int\* p[3]

- Array of 3 pointers to int.

Parentheses bahut important hain.

============================================================ 43. POINTER COMPARISON
============================================================

Pointers ko compare kiya ja sakta hai.

Example:

int a = 10;
int b = 20;

int* p = &a;
int* q = &b;

if (p == q)
{
cout << "Same address";
}
else
{
cout << "Different address";
}

nullptr check:

if (p == nullptr)
{
cout << "No object";
}

============================================================ 44. POINTER SUBTRACTION
============================================================

Same array ke elements ko point karne wale pointers ke beech
subtraction meaningful hota hai.

Example:

int arr[5] = {10, 20, 30, 40, 50};

int* p = &arr[1];
int* q = &arr[4];

cout << q - p;

Output:

3

Meaning:

arr[4] aur arr[1] ke beech 3 element positions ka difference hai.

============================================================ 45. POINTERS AUR sizeof
============================================================

Pointer ka size pointed data type ke size ke equal hona zaroori nahi hai.

Example:

int* p;
double* q;
char\* r;

sizeof(p)
sizeof(q)
sizeof(r)

ka result platform/architecture par depend karta hai.

Important:

sizeof(int\*) != necessarily sizeof(int)

============================================================ 46. POINTER TYPE IMPORTANT KYON HAI?
============================================================

Pointer type compiler ko batata hai ki pointed object ko
kaise interpret karna hai.

Example:

int x = 10;
int\* p = &x;

Compiler jaanta hai ki p int ko point karta hai.

Isliye:

\*p

ko int value ki tarah access kiya jata hai.

Pointer arithmetic mein bhi pointer type important hota hai.

============================================================ 47. COMMON POINTER MISTAKES
============================================================

Mistake 1:

int* p;
cout << *p;

Problem:

- p initialized nahi hai.

Mistake 2:

int* p = nullptr;
cout << *p;

Problem:

- nullptr dereference kiya.

Mistake 3:

int\* p = new int(10);

delete p;

cout << \*p;

Problem:

- Deleted memory access ki.

Mistake 4:

int\* arr = new int[10];

delete arr;

Problem:

- new[] ke saath delete[] use hona chahiye.

Correct:

delete[] arr;

============================================================ 48. POINTER SAFETY RULES
============================================================

Pointer use karte waqt:

1. Pointer ko initialize karein.
2. Agar target nahi hai to nullptr use karein.
3. nullptr ko dereference na karein.
4. Uninitialized pointer ko dereference na karein.
5. Deleted memory ko access na karein.
6. new aur delete ka correct pair use karein.
7. new[] aur delete[] ka correct pair use karein.
8. Ownership clear rakhein.
9. Modern C++ mein smart pointers ko prefer karein
   jab dynamic ownership manage karni ho.
10. Pointer arithmetic sirf valid context mein karein.

============================================================ 49. EXAM-IMPORTANT DEFINITIONS
============================================================

Pointer:

- A variable that stores the address of another object.

Address-of operator:

- & operator jo variable ka address obtain karta hai.

Dereference operator:

- - operator jo pointer ke through pointed object/value
    ko access karta hai.

Null pointer:

- A pointer that represents no valid object.
- Modern C++ mein nullptr use hota hai.

Dangling pointer:

- A pointer referring to an object/memory whose lifetime
  has ended.

Wild pointer:

- An uninitialized pointer.

Pointer arithmetic:

- Pointer par ++, --, + aur - jaise operations.

Smart pointer:

- C++ object/template jo resource ownership ko automatically
  manage karne mein help karta hai.

============================================================ 50. MOST IMPORTANT POINTER REVISION
============================================================

Given:

int x = 10;
int\* p = &x;

Remember:

x
-> value = 10

&x
-> address of x

p
-> address of x

\*p
-> value of x

Therefore:

\*p = 50;

means:

x = 50;

POINTER TO POINTER:

int\*\* q = &p;

\*q
-> p

\*\*q
-> x ki value

ARRAY:

int arr[3] = {10, 20, 30};

int\* p = arr;

\*p
-> 10

\*(p + 1)
-> 20

\*(p + 2)
-> 30

FUNCTION:

void change(int* p)
{
*p = 100;
}

change(&x);

STRUCT/CLASS POINTER:

Student\* p = &s;

p->age

DYNAMIC MEMORY:

int\* p = new int(10);

delete p;
p = nullptr;

DYNAMIC ARRAY:

int\* arr = new int[5];

delete[] arr;
arr = nullptr;

SMART POINTER:

std::unique_ptr<int> p = std::make_unique<int>(10);

============================================================ 51. MOST IMPORTANT RELATIONSHIPS
============================================================

For:

int x = 10;
int\* p = &x;

p == &x

\*p == x

Therefore:

\*p = 20;

means:

x = 20;

For arrays:

arr[i] == \*(arr + i)

For object pointer:

p->member == (\*p).member

For pointer-to-pointer:

q = &p

\*q == p

\**q == *p

============================================================ 52. FINAL CONCEPT
============================================================

Pointer ko ek "address holder" ki tarah yaad rakho.

Normal variable:

int x = 10;

x ke andar:

10

Pointer:

int\* p = &x;

p ke andar:

x ka address

Aur:

\*p

us address par stored value ko access karta hai.

Sabse important expressions:

x
&x
p
\*p

Meaning:

x -> value
&x -> address of x
p -> stored address
\*p -> value at stored address

Agar ye 4 concepts clear hain:

x
&x
p
\*p

to pointers ka fundamental concept clear hai.

============================================================
END OF POINTERS NOTES
============================================================
