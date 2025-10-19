#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Reverse an Array
    Platforms:
        - LeetCode 344 (Reverse String)
        - GeeksforGeeks: Reverse an Array

    Approaches Covered:
    ------------------------------------------------------
    1. Naive Approach → Using a temporary array
    2. Expected Approach 1 → Using Two Pointers
    3. Expected Approach 2 → By Swapping Elements
    4. Using Inbuilt Method → std::reverse()

    Each approach is explained with Time & Space Complexity.
*/

// ------------------------------------------------------
// 1. Naive Approach: Using a Temporary Array
// ------------------------------------------------------
/*
    Idea:
    - Create a temporary array of same size.
    - Copy elements from the original array in reverse order.
    - Copy them back to original array.

    Time Complexity: O(n)  [One pass for copy, one pass for restore]
    Space Complexity: O(n) [Extra array used]
*/
void reverseNaive(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n); // temporary array

    // Fill temp with reversed elements
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[n - 1 - i];
    }

    // Copy back into original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

// ------------------------------------------------------
// 2. Expected Approach 1: Using Two Pointers
// ------------------------------------------------------
/*
    Idea:
    - Maintain two pointers: one at start (i=0), one at end (j=n-1).
    - Swap elements at i and j.
    - Move i forward, j backward until they cross.

    Time Complexity: O(n) [Single pass with ~n/2 swaps]
    Space Complexity: O(1) [No extra array]
*/
void reverseTwoPointers(vector<int> &arr)
{
    int i = 0, j = arr.size() - 1;

    while (i < j)
    {
        swap(arr[i], arr[j]); // swap current pair
        i++;
        j--;
    }
}

// ------------------------------------------------------
// 3. Expected Approach 2: By Swapping Elements in loop
// ------------------------------------------------------
/*
    Idea:
    - Iterate from 0 to n/2.
    - For each i, swap arr[i] with arr[n-1-i].

    NOTE: This is essentially same as two-pointer method,
    but expressed in a single for-loop style.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
void reverseBySwapping(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - 1 - i]);
    }
}

// ------------------------------------------------------
// 4. Using Inbuilt Method: std::reverse()
// ------------------------------------------------------
/*
    Idea:
    - Use C++ STL inbuilt function reverse().
    - Works in-place.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
void reverseInbuilt(vector<int> &arr)
{
    reverse(arr.begin(), arr.end());
}

// ------------------------------------------------------
// Helper Function to Print Array
// ------------------------------------------------------
void printArray(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// ------------------------------------------------------
// Main Function: Test all approaches
// ------------------------------------------------------
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original Array: ";
    printArray(arr);

    // Approach 1
    vector<int> arr1 = arr;
    reverseNaive(arr1);
    cout << "Naive Approach (Extra Array): ";
    printArray(arr1);

    // Approach 2
    vector<int> arr2 = arr;
    reverseTwoPointers(arr2);
    cout << "Two Pointers Approach: ";
    printArray(arr2);

    // Approach 3
    vector<int> arr3 = arr;
    reverseBySwapping(arr3);
    cout << "Swapping Elements in Loop: ";
    printArray(arr3);

    // Approach 4
    vector<int> arr4 = arr;
    reverseInbuilt(arr4);
    cout << "Inbuilt reverse() function: ";
    printArray(arr4);

    return 0;
}
