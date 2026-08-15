#include <iostream>
using namespace std;

int main()
{
    int n;
    int i = 1;

    cout << "Enter n: ";
    cin >> n;

    do
    {
        cout << i << endl;
        i++;
    } while (i <= n);

    return 0;
}