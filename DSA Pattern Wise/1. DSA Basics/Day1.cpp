#include <bits/stdc++.h>
using namespace std;

int main()
{
    {
        int a = 10;
        a = 5;
        cout << "Hello World!";
        // endl is must to mark ending of a line
        cout << "Hello" << a;
    }
    cout << endl;
    // assignment operators + - / % *
    {
        int a = 10;
        int b = 5;
        int sum = a + b;
        cout << a + b;
        cout << sum;
    }
    cout << endl;
    {
        int a, b;
        cout << "Enter a and b " << endl;
        cin >> a >> b;
        int sum = a + b;
        cout << a << b << sum;
    }
    cout << endl;
    {
        int a, b;
        cout << "Enter a and b " << endl;
        cin >> a >> b;
        int sum = a % b;
        cout << a << b << sum;
    }
    cout << endl;
    {
        int num1, num2, num3, product;
        cout << "Enter 3 Numbers: ";
        cin >> num1 >> num2 >> num3;
        cout << endl;
        product = num1 * num2 * num3;
        cout << "Product is: " << product;
    }
    cout << endl;
    {
        int num1, num2, average;
        cout << "Enter 2 Numbers: ";
        cin >> num1 >> num2;
        cout << endl;
        average = (num1 + num2) / 2;
        cout << "Average is: " << average;
    }
    return 0;
}