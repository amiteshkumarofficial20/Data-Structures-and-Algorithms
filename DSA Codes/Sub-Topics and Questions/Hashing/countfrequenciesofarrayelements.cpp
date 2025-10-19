#include <iostream>
#include <vector>
#include <algorithm>     // For sort
#include <unordered_map> // For hash map approach
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nInput Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    /***********************************************
     * 1. BRUTE FORCE APPROACH
     ***********************************************/

    /*
        Idea:
        - For each element, count how many times it occurs in the array.
        - Skip elements that have already been counted.

        Steps:
        1. Use a boolean array "counted" to mark elements that are already counted.
        2. Use a nested loop: for each element, count its duplicates.
        3. Store element and its frequency in a vector of pairs.
    */

    cout << "\n--- Brute Force Approach ---\n";

    vector<pair<int, int>> freqBF;  // Store element & frequency
    vector<bool> counted(n, false); // Track if element already counted

    for (int i = 0; i < n; i++)
    {
        if (counted[i])
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                counted[j] = true; // Mark duplicate as counted
            }
        }
        freqBF.push_back({arr[i], count});
    }

    cout << "Frequencies (Brute Force): ";
    for (auto p : freqBF)
        cout << "[" << p.first << ", " << p.second << "] ";
    cout << endl;

    /*
        Time Complexity (T.C.):
        ----------------------
        - Outer loop runs n times.
        - Inner loop runs up to n-1 times for each element.
        - Worst case: all elements are unique → inner loop runs ~n times for each outer loop.
        - So, T.C. = O(n^2)

        Space Complexity (S.C.):
        ------------------------
        - 'counted' array → O(n)
        - 'freqBF' array → O(n) in worst case (all elements distinct)
        - Total S.C. = O(n + n) = O(n)
    */

    /***********************************************
     * 2. SORTING-BASED APPROACH
     ***********************************************/

    /*
       Idea:
       - Sort the array first so that duplicates are consecutive.
       - Count consecutive duplicates in a single pass.

       Steps:
       1. Make a copy of the original array to preserve input.
       2. Sort the array.
       3. Initialize count = 1, then iterate from 1 to n-1.
          - If current element equals previous, increment count.
          - Otherwise, store previous element and count, reset count.
       4. After loop, store the last element's frequency.
   */

    cout << "\n--- Sorting-Based Approach ---\n";

    vector<int> arrSort = arr;            // Preserve original
    sort(arrSort.begin(), arrSort.end()); // Sort array

    vector<pair<int, int>> freqSort;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arrSort[i] == arrSort[i - 1])
        {
            count++;
        }
        else
        {
            freqSort.push_back({arrSort[i - 1], count});
            count = 1;
        }
    }
    freqSort.push_back({arrSort[n - 1], count}); // last element

    cout << "Frequencies (Sorting): ";
    for (auto p : freqSort)
        cout << "[" << p.first << ", " << p.second << "] ";
    cout << endl;

    /*
        Time Complexity (T.C.):
        ----------------------
        - Sorting takes O(n log n)
        - Single pass to count duplicates → O(n)
        - Total T.C. = O(n log n + n) = O(n log n)

        Space Complexity (S.C.):
        ------------------------
        - freqSort array → O(n) worst case
        - arrSort array → O(n) copy of input
        - Total S.C. = O(n) + O(n) = O(n)
    */

    /***********************************************
     * 3. HASHING / UNORDERED MAP APPROACH (OPTIMAL)
     ***********************************************/

    /*
      Idea:
      - Use an unordered_map to store element -> frequency mapping.
      - Single pass over array gives O(n) time.

      Steps:
      1. Initialize unordered_map<int,int> freqMap.
      2. For each element, increment its count in freqMap.
      3. Iterate over original array to print frequencies once.
         - Mark each element as printed by setting freqMap[element] = 0.
  */

    cout << "\n--- Hashing / Unordered Map Approach (Optimal) ---\n";

    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++)
        freqMap[arr[i]]++; // increment frequency

    cout << "Frequencies (Hashing): ";
    for (int i = 0; i < n; i++)
    {
        if (freqMap[arr[i]] != 0)
        { // Print only once
            cout << "[" << arr[i] << ", " << freqMap[arr[i]] << "] ";
            freqMap[arr[i]] = 0; // Mark as printed
        }
    }
    cout << endl;

    /*
        Time Complexity (T.C.):
        ----------------------
        - Single pass to build freqMap → O(n)
        - Single pass to print frequencies → O(n)
        - Total T.C. = O(n + n) = O(n)

        Space Complexity (S.C.):
        ------------------------
        - freqMap → stores only distinct elements, so O(k), k = #distinct elements
        - Total S.C. = O(k)
    */

    return 0;
}
