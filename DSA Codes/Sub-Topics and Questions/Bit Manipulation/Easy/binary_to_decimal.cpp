#include <iostream>
#include <string>
#include <cmath> // for pow()
using namespace std;

/*
    ---------------------------------------------------------
    Function: convert2decimal(string bin)
    Purpose : Convert a binary string to its decimal equivalent.
    ---------------------------------------------------------
    Algorithm:
      1. Initialize:
            - num = 0 (stores final decimal value)
            - p2 = 1  (represents the current power of 2, starting from 2^0)
      2. Traverse the binary string from RIGHT to LEFT (LSB → MSB)
         using a for loop with index `i = len - 1` down to 0:
            - If bin[i] == '1':
                → Add current power of 2 (p2) to num.
            - Multiply p2 by 2 for the next higher bit.
      3. Return num as the decimal value.

    Example:
        bin = "1010"
        Steps:
          (From right)
          i=3: '0' → skip
          i=2: '1' → num += 2 (p2=2)
          i=1: '0' → skip (p2=4)
          i=0: '1' → num += 8 (p2=8)
        num = 10
*/
int convert2decimal(string bin)
{
    int len = bin.length(); // get length of binary string
    int num = 0;            // stores the decimal value
    int p2 = 1;             // power of 2, starting from 2^0 = 1

    // Loop from rightmost bit to leftmost bit
    for (int i = len - 1; i >= 0; i--)
    {
        if (bin[i] == '1')
        {
            num += p2; // if bit is 1, add current power of 2
        }
        p2 *= 2; // move to next power of 2
    }

    return num;
}

/*
    ---------------------------------------------------------
    Time Complexity: O(n)
        - We traverse each bit once (n = length of binary string).

    Space Complexity: O(1)
        - Only a few integer variables used, no extra data structures.
    ---------------------------------------------------------
*/

int main()
{
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    // Basic validation
    for (char c : binary)
    {
        if (c != '0' && c != '1')
        {
            cout << "Invalid binary input!" << endl;
            return 0;
        }
    }

    int decimal = convert2decimal(binary);
    cout << "Decimal representation: " << decimal << endl;

    return 0;
}
