#include <iostream>
using namespace std;

int main()
{
    float principal, rate, time, simpleinterest;
    cout << " Enter Principal, Rate, Time: ";
    cin >> principal >> rate >> time;
    simpleinterest = (principal * rate * time) / 100;
    cout << simpleinterest;
    return 0; // optional
}