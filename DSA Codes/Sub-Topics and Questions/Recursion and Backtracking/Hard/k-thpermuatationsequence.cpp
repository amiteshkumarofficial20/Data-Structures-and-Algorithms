// 🔹 LeetCode 60: K-th Permutation Sequence
// 🔹 Difficulty: Hard
// 🔹 Topics: Math, Recursion, Backtracking
// 🔹 Company Tags: Google, Amazon, Adobe, Microsoft
// 🔹 Author: Amitesh Kumar

/*
🧩 Problem Description:
------------------------
Given n and k, return the k-th permutation sequence of numbers [1, 2, ..., n]
in lexicographic (sorted) order.

You do NOT need to generate all permutations manually;
the goal is to efficiently compute the k-th one directly.

---------------------------------------
Example 1:
Input: n = 3, k = 3
Output: "213"

Explanation:
All permutations of [1,2,3] are:
1. "123"
2. "132"
3. "213" ← 3rd permutation
4. "231"
5. "312"
6. "321"

---------------------------------------
Constraints:
1 <= n <= 9
1 <= k <= n!
---------------------------------------
*/

// ============================================================
// ✅ Solution 1: Brute Force Approach (Generate All Permutations)
// ============================================================

/*
🧠 Intuition:
-------------
The most straightforward (naive) method is to generate all possible
permutations of the sequence [1, 2, ..., n] using recursion.
Once all permutations are generated, we sort them in lexicographic order
and simply return the K-th permutation.

Though easy to understand, this method is highly inefficient because
the number of permutations grows factorially with n.

---------------------------------------
Approach:
1. Build a string "123...n".
2. Use recursion + backtracking to generate all permutations.
3. Store all permutations in a vector.
4. Sort the vector.
5. Return the (k-1)th element from it.

---------------------------------------
Example:
For n = 3, k = 3
→ All permutations = ["123", "132", "213", "231", "312", "321"]
→ Sorted = same order
→ 3rd permutation = "213"
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce
{
public:
    // Helper function to generate all possible permutations of string s
    void permutationHelper(string &s, int index, vector<string> &res)
    {
        if (index == s.size())
        {
            res.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            swap(s[i], s[index]);                 // Choose
            permutationHelper(s, index + 1, res); // Explore
            swap(s[i], s[index]);                 // Undo (Backtrack)
        }
    }

    string getPermutation(int n, int k)
    {
        string s;
        vector<string> res;

        // Step 1: Build the string "123...n"
        for (int i = 1; i <= n; i++)
        {
            s.push_back(i + '0');
        }

        // Step 2: Generate all permutations
        permutationHelper(s, 0, res);

        // Step 3: Sort permutations in lexicographic order
        sort(res.begin(), res.end());

        // Step 4: Return Kth permutation (0-based index)
        return res[k - 1];
    }
};

/*
📈 Time Complexity:
--------------------
O(N! * N)  → generating all permutations and storing them
+ O(N! log N!) → sorting them
= O(N! * N + N! log N!)

💾 Space Complexity:
---------------------
O(N) for recursion stack
O(N!) for storing all permutations (implicit)
*/

// ============================================================
// ✅ Solution 2: Optimal Mathematical Approach (O(N²))
// ============================================================

/*
🧠 Intuition:
-------------
Instead of generating all permutations, we can directly calculate
which number should be placed at each position using the properties
of factorials.

For example, with n = 4 and k = 17:
There are 4! = 24 total permutations.

Each starting number (1, 2, 3, 4) fixes the first position and has
(3!) = 6 permutations for the remaining positions.

So:
- Permutations 1–6 start with '1'
- Permutations 7–12 start with '2'
- Permutations 13–18 start with '3'
- Permutations 19–24 start with '4'

Since k = 17, it lies in the block that starts with '3'.
Thus, '3' is the first digit of the permutation.

Now we reduce the problem:
→ Remaining numbers = [1,2,4]
→ New k = k % 6 = 4 (0-based)
→ Repeat the same logic for remaining positions.

We continue until all digits are placed.
This allows us to "skip" entire groups of permutations
without generating them explicitly.

---------------------------------------
Algorithm:
1. Precompute (n-1)! because each number contributes that many permutations per block.
2. Maintain a list of numbers [1, 2, 3, ..., n].
3. Convert k to 0-based index (k = k - 1).
4. While there are numbers left:
   - Find index = k / fact
   - Pick number at that index → append to answer
   - Remove that number from the list
   - Update k = k % fact
   - Update fact = fact / remaining_size
5. Return the answer string.

---------------------------------------
Example Walkthrough:
n = 4, k = 17
Numbers = [1,2,3,4]
fact = 3! = 6
k = 16 (0-based)

Step 1: index = 16 / 6 = 2 → pick numbers[2] = 3 → ans = "3"
Remove 3 → numbers = [1,2,4]
k = 16 % 6 = 4
fact = 6 / 3 = 2

Step 2: index = 4 / 2 = 2 → pick numbers[2] = 4 → ans = "34"
Remove 4 → numbers = [1,2]
k = 4 % 2 = 0
fact = 2 / 2 = 1

Step 3: index = 0 / 1 = 0 → pick numbers[0] = 1 → ans = "341"
Remove 1 → numbers = [2]
k = 0 % 1 = 0
fact = 1 / 1 = 1

Step 4: pick remaining number 2 → ans = "3412"
✅ Final Answer: "3412"
*/

class SolutionOptimal
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;

        // Step 1: Calculate (n-1)! and prepare the number list
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k - 1; // convert to 0-based indexing

        // Step 2: Build the permutation
        while (!numbers.empty())
        {
            int index = k / fact;                   // Find which block k belongs to
            ans += to_string(numbers[index]);       // Append the selected number
            numbers.erase(numbers.begin() + index); // Remove used number

            if (numbers.empty())
                break; // Base case: all numbers used

            k = k % fact;                 // Update k for next position
            fact = fact / numbers.size(); // Update factorial for next block
        }

        return ans;
    }
};

/*
📈 Time Complexity:
--------------------
O(N²)
Reason:
- We select N numbers (O(N))
- Each removal from vector takes O(N)
Hence, total = O(N * N) = O(N²)

💾 Space Complexity:
---------------------
O(N) for storing remaining numbers
*/

// ============================================================
// 🧪 Main Function (Testing Both Solutions)
// ============================================================

int main()
{
    int n = 3, k = 3;

    cout << "----------------------------------------\n";
    cout << "🔸 LeetCode 60: K-th Permutation Sequence\n";
    cout << "----------------------------------------\n\n";

    // ✅ Brute Force Solution
    SolutionBruteForce brute;
    string bruteAns = brute.getPermutation(n, k);
    cout << "🧮 Brute Force Answer: " << bruteAns << endl;

    // ✅ Optimal Mathematical Solution
    SolutionOptimal opt;
    string optAns = opt.getPermutation(n, k);
    cout << "⚡ Optimal Answer: " << optAns << endl;

    cout << "\nExpected Output: 213\n";
    return 0;
}

/*
🧾 Summary:
---------------------------------------------------------
Approach  | Time Complexity          | Space Complexity
---------------------------------------------------------
Brute     | O(N! * N + N! log N!)    | O(N)
Optimal   | O(N²)                    | O(N)
---------------------------------------------------------

🏁 Both produce correct results, but the optimal approach
is mathematically efficient and scales better.
*/
