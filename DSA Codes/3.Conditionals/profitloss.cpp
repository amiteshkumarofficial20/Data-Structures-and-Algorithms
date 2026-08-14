#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int costprice;
    int sellingprice;

    cout << "Enter Cost Price: ";
    cin >> costprice;

    cout << "Enter Selling Price: ";
    cin >> sellingprice;

    if (costprice < sellingprice)
    {
        cout << "Profit is : " << (sellingprice - costprice) << endl;
    }
    else if (costprice > sellingprice)
    {
        cout << "Loss is : " << (costprice - sellingprice) << endl;
    }
    else
    {
        cout << "No Profit No Loss" << endl;
    }
    return 0;
}