#include <iostream>
#include <string>
#include <algorithm> // for reverse()
using namespace std;

/*
    ---------------------------------------------------------
    Function: convert2binary(int n)
    Purpose : Convert a decimal integer to its binary string.
    ---------------------------------------------------------
    Algorithm:
      1. Initialize an empty string `res` to store binary digits.
      2. Loop while n != 1:
            - If n % 2 == 1 → append '1' to res.
            - Else append '0' to res.
            - Then divide n by 2 (integer division).
      3. After loop ends, append the last '1' to res (since loop stops when n == 1).
      4. Reverse the string because binary digits are generated in reverse order.
      5. Return the reversed string.

    Example:
        n = 10
        Steps:
          10 % 2 = 0 → res = "0"
          5  % 2 = 1 → res = "01"
          2  % 2 = 0 → res = "010"
          1  → stop, add '1' → res = "0101"
        Reverse → "1010"
        Output = "1010"
*/
string convert2binary(int n)
{
    string res = ""; // result string to store binary digits (in reverse order)

    // Loop until n reduces to 1
    while (n != 1)
    {
        if (n % 2 == 1)
        {
            res += "1"; // if n is odd, append '1'
        }
        else
        {
            res += "0"; // if n is even, append '0'
        }
        n = n / 2; // integer division by 2 to reduce the number
    }

    res += "1"; // add the final '1' for the last remaining n=1

    reverse(res.begin(), res.end()); // reverse the string to get correct binary order
    return res;
}

/*
    ---------------------------------------------------------
    Time Complexity: O(log₂n)
        - We divide n by 2 each iteration, so the number of steps is log₂n.

    Space Complexity: O(log₂n)
        - The string `res` stores one character per bit → O(log₂n) space.
    ---------------------------------------------------------
*/

int main()
{
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive integer!" << endl;
        return 0;
    }

    string binary = convert2binary(n);
    cout << "Binary representation: " << binary << endl;

    return 0;
}
