#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
    Problem:
    --------
    Count character frequencies in a string using unordered_map
    and allow user queries for specific characters.

    Approach:
    ---------
    1. Take input string (using getline to include spaces).
    2. Use unordered_map<char, int> to store frequency of each character.
       - Average O(1) insertion and lookup.
    3. Traverse the string and increment the count for each character.
    4. Print all character frequencies (unordered, not sorted).
    5. Let user query character frequencies until EOF (Ctrl+Z/Ctrl+D).

    Time Complexity:
    ----------------
    - Counting frequencies: O(n) average, O(n) worst-case (rare)
      where n = length of string.
    - Printing frequencies: O(k), where k = number of distinct characters.
    - Each query: O(1) average, O(k) worst-case (rare).
    => Total: O(n + q) average, O(n + q * k) worst-case

    Space Complexity:
    -----------------
    - unordered_map stores at most k entries (k distinct characters).
    - Input string storage → O(n).
    => Total: O(n + k)
*/

int main()
{
    // Step 1: Input string
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    // Step 2: unordered_map for character frequencies
    unordered_map<char, int> freq;

    // Step 3: Count frequency of each character
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++; // increments frequency
    }

    // Step 4: Display frequencies (unordered)
    cout << "\nFrequencies (unordered):\n";
    for (auto &p : freq)
    {
        cout << "'" << p.first << "' -> " << p.second << endl;
    }

    // Step 5: Query loop
    cout << "\nEnter characters to query (Ctrl+Z or Ctrl+D to stop):\n";
    char ch;
    while (cin >> ch) // continues until EOF
    {
        if (freq.find(ch) != freq.end())
            cout << "Frequency of '" << ch << "' is: " << freq[ch] << endl;
        else
            cout << "Character '" << ch << "' not found in string.\n";
    }

    return 0;
}
