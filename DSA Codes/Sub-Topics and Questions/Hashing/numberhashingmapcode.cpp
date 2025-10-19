#include <iostream>
#include <vector>
#include <map> // Ordered map, keys are sorted automatically
using namespace std;

/*
    Problem:
    --------
    Given an array of integers, precompute the frequency of each number
    and allow queries to fetch the frequency of any number.
    Use a sorted map so that printing all frequencies is automatically in ascending order.

    Approach:
    ---------
    1. Read array size and elements.
    2. Use `map<int, int>` to store frequency of each number.
       - Key: the number
       - Value: frequency
       - Map automatically keeps keys in ascending order.
    3. Traverse array and increment frequency for each element.
    4. Print all numbers and their frequencies (sorted by key).
    5. Let user query frequencies until EOF (Ctrl+Z on Windows, Ctrl+D on Linux/Mac).

    Time Complexity:
    ----------------
    - Insertion into map: O(log k) per element, where k = distinct numbers
    - Total insertion for n elements: O(n * log k)
    - Printing all frequencies: O(k)
    - Each query: O(log k)
    => Total: O(n*log k + q*log k) for n elements and q queries

    Space Complexity:
    -----------------
    - Map stores k distinct numbers: O(k)
    - Array storage: O(n)
    => Total: O(n + k)
*/

int main()
{
    // Step 1: Input size of array
    int n;
    cout << "Enter Number Of Elements: ";
    cin >> n;

    // Step 2: Input array elements
    vector<int> arr(n);
    cout << "Enter Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Step 3: Display array elements
    cout << "Array Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Step 4: Precompute frequencies using map
    map<int, int> freq; // automatically ordered by key
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++; // increment count for arr[i]
    }

    // Step 5: Print all frequencies (sorted by key)
    cout << "\nAll Frequencies (sorted by number):\n";
    for (auto &p : freq)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    // Step 6: Query loop
    cout << "\nEnter numbers to query (Ctrl+Z or Ctrl+D to stop):" << endl;
    int number;
    while (cin >> number) // continues until EOF
    {
        if (freq.find(number) != freq.end()) // number exists in map
        {
            cout << "Frequency of " << number << " is: " << freq[number] << endl;
        }
        else // number not present in array
        {
            cout << "Frequency of " << number << " is: 0" << endl;
        }
    }

    return 0;
}
