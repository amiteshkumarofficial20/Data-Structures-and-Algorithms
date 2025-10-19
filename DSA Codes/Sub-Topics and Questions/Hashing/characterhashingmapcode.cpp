#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
    Problem:
    --------
    Count character frequencies in a string using STL map
    and allow user queries for specific characters.

    Approach:
    ---------
    1. Take input string.
    2. Use `map<char,int>` to store frequency of each character.
       - map is ordered (keys are sorted automatically).
    3. Traverse the string and increment frequency count.
    4. Print all character frequencies in sorted order.
    5. Let user query character frequencies until EOF.

    Time Complexity:
    ----------------
    - Counting frequencies: O(n log k), where
        n = length of string,
        k = number of distinct characters.
      (log k due to map insert/search).
    - Printing all: O(k).
    - Each query: O(log k).
    => Total: O(n log k + q log k)

    Space Complexity:
    -----------------
    - Map stores at most k entries (k distinct characters).
    - Input string takes O(n).
    => Total: O(n + k)
*/

int main()
{
    // Step 1: Input string
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    // Step 2: Ordered map for storing character frequencies
    map<char, int> mpp;

    // Step 3: Count frequency of each character
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++; // increments frequency of character
    }

    // Step 4: Print frequencies in sorted order
    cout << "\nFrequencies (in sorted order of characters):\n";
    for (auto &p : mpp)
    {
        cout << "'" << p.first << "' -> " << p.second << endl;
    }

    // Step 5: Query loop
    cout << "\nEnter characters to query (Ctrl+Z or Ctrl+D to stop):\n";
    char ch;
    while (cin >> ch) // continues until EOF
    {
        if (mpp.find(ch) != mpp.end())
            cout << "Frequency of '" << ch << "' is: " << mpp[ch] << endl;
        else
            cout << "Character '" << ch << "' not found in string.\n";
    }

    return 0;
}
