#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: LeetCode 344 - Reverse String
Given a character array s, reverse the array in-place.

-------------------------------------------------------
📝 Brute Force Approach:
-------------------------------------------------------
1. We create a new array (extra space) to store the reversed version.
2. Copy characters from s[n-1] → s[0] into the new array.
3. Copy back this reversed array into the original array s.
4. This works but is NOT optimal since it uses extra O(n) space.

⚡ Time Complexity: O(n)  → we traverse the string twice.
💾 Space Complexity: O(n) → extra array to store reversed string.
*/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();

        // Step 1: Create a new array to store reversed characters
        vector<char> temp(n);

        // Step 2: Fill temp with characters from s in reverse order
        for (int i = 0; i < n; i++)
        {
            temp[i] = s[n - 1 - i]; // picking from back to front
        }

        // Step 3: Copy temp back into s
        for (int i = 0; i < n; i++)
        {
            s[i] = temp[i];
        }
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    sol.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s)
        cout << c;
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
Given a character array s, reverse the array in-place.

-------------------------------------------------------
📝 Optimal Approach (Two Pointer / In-place Swap):
-------------------------------------------------------
1. Maintain two indices:
   - left pointer at the start (0)
   - right pointer at the end (n-1)
2. While left < right:
   - swap s[left] and s[right]
   - move left forward and right backward
3. Continue until the pointers cross each other.

⚡ Time Complexity: O(n)
   - Each element is swapped once, so linear.
💾 Space Complexity: O(1)
   - No extra space, everything is done in-place.
*/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;

        // Two pointer approach
        while (left < right)
        {
            swap(s[left], s[right]); // swap characters
            left++;                  // move forward
            right--;                 // move backward
        }
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    sol.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s)
        cout << c;
    cout << endl;

    return 0;
}
