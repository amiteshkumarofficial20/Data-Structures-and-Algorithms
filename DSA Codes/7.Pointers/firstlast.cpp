// Find first and last digit of a number using pointer
// Function does not return anything

#include <iostream>
using namespace std;

// Function to find first and last digit
void findDigits(int n, int *first, int *last)
{
    // Last digit
    *last = n % 10;

    // Find first digit
    while (n >= 10)
    {
        n = n / 10;
    }

    *first = n;
}

int main()
{
    int n;
    int first, last;

    // Taking input from user
    cout << "Enter a number: ";
    cin >> n;

    // Passing addresses to the function
    findDigits(n, &first, &last);

    // Display result
    cout << "First digit: " << first << endl;
    cout << "Last digit: " << last << endl;

    return 0;
}