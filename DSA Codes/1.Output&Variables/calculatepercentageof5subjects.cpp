#include <iostream>
using namespace std;

int main()
{
    float a, b, c, d, e;
    cout << " Enter Marks of a, b, c, d and e : ";
    cin >> a >> b >> c >> d >> e;
    float percentage = (a + b + c + d + e) / 5;
    cout << percentage;
    return 0; // optional
}