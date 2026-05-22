#include <bits/stdc++.h>
using namespace std;

int doub(int num)
{
    int result = 2 * num;
    return result;
}
int main()
{

    // functions
    //  return type function name input type input number
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    int result = doub(n);
    cout << result << endl; // cout << doub(n) << endl;
    return 0;
}