#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Problem:
    --------
    Count the frequency of each character in a string using hashing,
    and then allow the user to query the frequency of characters.

    Approach:
    ---------
    1. Take input string (using getline so spaces are also included).
    2. Create a hash array of size 256 (for all ASCII characters).
    3. Traverse the string and update frequency counts in the hash array.
    4. Display frequencies of all characters that appear.
    5. Allow user to query frequency of characters until EOF.

    Time Complexity:
    ----------------
    - Precomputing frequencies (loop over string) → O(n), where n = length of string.
    - Printing frequencies → O(256) ≈ O(1).
    - Querying characters → O(1) per query, O(q) for q queries.
    => Total: O(n + q)

    Space Complexity:
    -----------------
    - Hash array → O(256) ≈ O(1) constant.
    - Input string storage → O(n).
    => Total: O(n)
*/

int main()
{
    // Step 1: Input string
    cout << "Enter a string: ";
    string input;
    getline(cin, input); // getline is used so we capture spaces too

    // Step 2: Hash array (size 256 for extended ASCII), initialized to 0
    vector<int> hash(256, 0);

    // Step 3: Count frequency of each character
    for (int i = 0; i < input.size(); i++)
    {
        hash[(unsigned char)input[i]]++; // cast to unsigned char for safety
    }

    // Step 4: Display character frequencies
    cout << "\nCharacter Frequencies:\n";
    for (int i = 0; i < 256; i++)
    {
        if (hash[i] > 0) // Only display characters that appear
        {
            if (isprint(i)) // Printable characters (letters, digits, space, etc.)
                cout << "'" << (char)i << "' : " << hash[i] << endl;
            else // Non-printable ASCII (just in case)
                cout << "ASCII(" << i << ") : " << hash[i] << endl;
        }
    }

    // Step 5: Query character frequencies
    cout << "\nEnter characters to query frequency (Ctrl+Z to stop):\n";
    char c;
    while (cin >> c) // Loop runs until EOF
    {
        cout << "Frequency of '" << c << "' is: " << hash[(unsigned char)c] << endl;
    }

    return 0;
}
