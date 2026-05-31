#include <iostream>
using namespace std;

int main()
{
    // ++x x++ --x x--
    // pre post increment decrement operators on int data type
    int x = 5;
    x++;
    cout << x << endl;
    ++x;
    cout << x << endl;
    x--;
    cout << x << endl;
    --x;
    cout << x << endl;
    return 0; // optional
}