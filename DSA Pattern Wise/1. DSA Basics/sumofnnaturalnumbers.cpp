// gfg
#include <bits/stdc++.h>
using namespace std;

int findsum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        // int sum = 0;
        // for (int i = 0; i <= n; i++)
        // {
        //     sum += i;
        // }
        // return sum;
        int sum = (n * (n + 1) / 2);
        return sum;
    }
}
int main()
{

    // functions
    //  return type function name input type input number
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    int result = findsum(n);
    cout << result << endl; // cout << findsum << endl;
    return 0;
}