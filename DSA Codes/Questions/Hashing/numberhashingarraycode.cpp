#include <iostream>
#include <vector>
using namespace std;

/*
    Problem:
    --------
    Given an array of integers in a known range [0, MAX_VAL],
    precompute the frequency of each element and allow queries
    for any number's frequency.

    Approach:
    ---------
    1. Read array of integers.
    2. Precompute frequency using a "hash array" of size MAX_VAL + 1.
    3. Increment the frequency for each array element within range.
    4. For each query, fetch frequency from hash array in O(1).

    Time Complexity:
    ----------------
    - Reading array: O(n)
    - Precomputing hash array: O(n)
    - Querying frequency: O(1) per query
    => Total: O(n + q) for n elements and q queries

    Space Complexity:
    -----------------
    - Hash array: O(MAX_VAL + 1)
    - Array storage: O(n)
    => Total: O(n + MAX_VAL)
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

    // Step 3: Display array
    cout << "Array Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Step 4: Precompute frequencies
    const int MAX_VAL = 10;                // change as needed
    vector<int> hasharray(MAX_VAL + 1, 0); // initialize to 0
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0 && arr[i] <= MAX_VAL)
            hasharray[arr[i]]++;
    }

    // Step 5: Query loop
    cout << "Enter numbers to query (Ctrl+Z or Ctrl+D to stop):" << endl;
    int number;
    while (cin >> number) // continues until EOF
    {
        if (number >= 0 && number <= MAX_VAL)
            cout << "Frequency of " << number << " is: " << hasharray[number] << endl;
        else
            cout << "Number " << number << " is out of range (0-" << MAX_VAL << ")." << endl;
    }

    return 0;
}
