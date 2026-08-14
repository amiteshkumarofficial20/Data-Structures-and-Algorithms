#include <iostream>
using namespace std;

int main()
{
    float radius;
    cout << "Enter Radius : ";
    cin >> radius;
    float pie = 3.1415;
    float area;
    area = pie * radius * radius;
    cout << "Area Of a Circle is " << area << endl;
    return 0;
}
