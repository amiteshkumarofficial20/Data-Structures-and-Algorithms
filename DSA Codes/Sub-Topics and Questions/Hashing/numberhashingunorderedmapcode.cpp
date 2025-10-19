#include <iostream>
#include <unordered_map> // For hash map (average O(1) lookups)
#include <vector>
using namespace std;

/*
    Problem:
    --------
    Given an array of integers, compute the frequency of each number
    and allow queries to fetch frequency of any number using an
    unordered_map (hash map).

    Approach:
    ---------
    1. Input the number of elements and the array elements.
    2. Use `unordered_map<int,int>` to store frequency of each number:
       - Key: the number
       - Value: the frequency count
       - Lookup and insertion are O(1) on average.
    3. Traverse array and increment frequency for each element.
    4. Print all numbers and their frequencies (unordered).
    5. Let user query frequency until EOF (Ctrl+Z on Windows, Ctrl+D on Linux/Mac).

    Time Complexity:
    ----------------
    - Building frequency table: O(n), n = number of elements
    - Printing all frequencies: O(k), k = number of distinct numbers
    - Each query: O(1) on average
    => Total: O(n + q) for n elements and q queries (average case)

    Space Complexity:
    -----------------
    - unordered_map stores k distinct numbers: O(k)
    - Array storage: O(n)
    => Total: O(n + k)
*/

int main()
{
    // Step 1: Input size of array
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Input array elements
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Step 3: Create frequency table using unordered_map
    unordered_map<int, int> freq; // key = number, value = count
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++; // increment frequency
    }

    // Step 4: Display all frequencies (unordered)
    cout << "\nFrequencies (unordered):\n";
    for (auto &p : freq)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    // Step 5: Query loop
    cout << "\nEnter numbers to query (Ctrl+Z or Ctrl+D to stop):\n";
    int number;
    while (cin >> number) // continues until EOF
    {
        if (freq.find(number) != freq.end()) // number exists
            cout << "Frequency of " << number << " is: " << freq[number] << endl;
        else // number not present
            cout << number << " not found in array.\n";
    }

    return 0;
}
