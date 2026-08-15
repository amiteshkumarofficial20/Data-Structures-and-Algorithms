#include <iostream>
using namespace std;

int main()
{
    int num;
    int count = 0;

    cout << "Enter a number: ";
    cin >> num;

    if (num < 2)
    {
        cout << " Not Prime";
    }

    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }

    if (count == 1)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }

    return 0;
}

// //using flag
// int main()
// {
//     int num;
//     bool flag = true;

//     cout << "Enter a number: ";
//     cin >> num;

//     if (num <= 1)
//     {
//         flag = false;
//     }
//     else
//     {
//         for (int i = 2; i < num; i++)
//         {
//             if (num % i == 0)
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }

//     if (flag == true)
//     {
//         cout << "Prime";
//     }
//     else
//     {
//         cout << "Not Prime";
//     }

//     return 0;
// }