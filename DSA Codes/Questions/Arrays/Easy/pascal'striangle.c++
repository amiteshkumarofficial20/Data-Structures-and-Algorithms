#include <bits/stdc++.h>
using namespace std;

/* =====================================================
   Pascal’s Triangle → Variation 1
   -----------------------------------------------------
   Problem:
   Given row number r and column number c (1-indexed),
   find the element at position (r, c) in Pascal’s Triangle.

   🔹 Example:
      Input: r = 5, c = 3
      Row 5 of Pascal’s Triangle = [1, 4, 6, 4, 1]
      Answer = 6
   -----------------------------------------------------
   Approaches:
   1. Naive: Generate factorials separately and compute nCr.
   2. Optimal: Iteratively calculate nCr without computing full factorials.
   ===================================================== */

/* ======================
   NAIVE APPROACH
   ------------------------------------------------------
   Formula:
   element(r, c) = (r-1)C(c-1) = nCr
   where n = r-1, r = c-1

   We compute factorial(n), factorial(r), factorial(n-r),
   and plug into nCr = n! / (r! * (n-r)!).

   🔹 Time Complexity: O(n) + O(r) + O(n-r) ≈ O(n)
   🔹 Space Complexity: O(1)
   ====================== */
long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

long long pascalElementNaive(int r, int c)
{
    int n = r - 1; // row index shifted
    int k = c - 1; // column index shifted
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/* ======================
   OPTIMAL APPROACH
   ------------------------------------------------------
   Instead of calculating big factorials, we iteratively
   compute nCr:

   nCr = (n * (n-1) * (n-2) ... (n-r+1)) / (r * (r-1) ... 1)

   Implementation trick:
   res = 1
   for i = 0 to r-1:
       res = res * (n-i) / (i+1)

   🔹 Time Complexity: O(min(r, n-r)) → efficient
   🔹 Space Complexity: O(1)
   ====================== */
long long pascalElementOptimal(int r, int c)
{
    int n = r - 1; // row index shifted
    int k = c - 1; // column index shifted

    long long res = 1;
    for (int i = 0; i < k; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

/* =====================================================
   MAIN FUNCTION → For Testing in VS Code
   ===================================================== */
int main()
{
    int r = 5, c = 3;

    cout << "=== Pascal's Triangle (Variation 1) ===" << endl;
    cout << "Row = " << r << ", Column = " << c << endl;

    // Naive approach
    cout << "\nNaive Approach (using factorials): "
         << pascalElementNaive(r, c) << endl;

    // Optimal approach
    cout << "Optimal Approach (iterative nCr): "
         << pascalElementOptimal(r, c) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/* =====================================================
   Pascal’s Triangle → Variation 2
   -----------------------------------------------------
   Problem (LeetCode 119: Pascal’s Triangle II):
   Given the row number n, print the n-th row of Pascal’s Triangle.
   (Row is 1-indexed in this explanation, but LC uses 0-index)

   🔹 Example:
      Input: n = 5
      Output: [1, 4, 6, 4, 1]

   🔹 Observations:
      - The n-th row has exactly n elements.
      - Each element is (n-1)C(c-1) where c = column number (1-indexed).
   ===================================================== */

/* ======================
   HELPER → nCr function
   Iterative calculation of combination.
   ====================== */
long long nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

/* ======================
   NAIVE APPROACH
   ------------------------------------------------------
   For every column c from 1 → n:
      element = (n-1)C(c-1)
   Just reuse nCr for each column.

   🔹 Time Complexity: O(n^2)
       - Because for each column (n), we compute nCr in O(r)
   🔹 Space Complexity: O(1)
   ====================== */
vector<long long> getRowNaive(int n)
{
    vector<long long> row;
    for (int c = 1; c <= n; c++)
    {
        row.push_back(nCr(n - 1, c - 1));
    }
    return row;
}

/* ======================
   OPTIMAL APPROACH
   ------------------------------------------------------
   Use the property:
      Current element = prevElement * (n - i) / i
   where i is the column index (1-based).

   🔹 Steps:
      1. First element = 1
      2. For i = 1 → n-1:
            curr = prev * (n-i) / i
   🔹 Time Complexity: O(n)
   🔹 Space Complexity: O(1) extra
   ====================== */
vector<long long> getRowOptimal(int n)
{
    vector<long long> row;
    long long prev = 1;
    row.push_back(prev); // first element always 1

    for (int i = 1; i < n; i++)
    {
        long long curr = (prev * (n - i)) / i;
        row.push_back(curr);
        prev = curr;
    }
    return row;
}

/* =====================================================
   MAIN FUNCTION → For Testing in VS Code
   ===================================================== */
int main()
{
    int n = 5; // Example row number

    cout << "=== Pascal's Triangle (Variation 2) ===" << endl;
    cout << "Row number = " << n << endl;

    // Naive approach
    vector<long long> rowNaive = getRowNaive(n);
    cout << "\nNaive Approach (O(n^2)): ";
    for (auto x : rowNaive)
        cout << x << " ";
    cout << endl;

    // Optimal approach
    vector<long long> rowOptimal = getRowOptimal(n);
    cout << "Optimal Approach (O(n)): ";
    for (auto x : rowOptimal)
        cout << x << " ";
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/* =====================================================
   Pascal’s Triangle → Variation 3
   -----------------------------------------------------
   Problem (LeetCode 118: Pascal’s Triangle):
   Given an integer n, return the first n rows of Pascal’s Triangle.

   🔹 Example:
      Input: n = 5
      Output:
      [
        [1],
        [1,1],
        [1,2,1],
        [1,3,3,1],
        [1,4,6,4,1]
      ]
   ===================================================== */

/* ======================
   HELPER → nCr function
   Iterative calculation of combination.
   ====================== */
long long nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

/* ======================
   NAIVE APPROACH
   ------------------------------------------------------
   For every row = 1 → n:
       For every col = 1 → row:
           element = (row-1)C(col-1)
           store in row vector

   🔹 Time Complexity: O(n^3)
       - There are n rows
       - Each row has up to n elements
       - Each element is computed in O(r) = O(n)
   🔹 Space Complexity: O(1) extra
   ====================== */
vector<vector<long long>> generateNaive(int n)
{
    vector<vector<long long>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<long long> temp;
        for (int col = 1; col <= row; col++)
        {
            temp.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(temp);
    }
    return ans;
}

/* ======================
   OPTIMAL APPROACH
   ------------------------------------------------------
   Use property from Variation 2:
      Current element = prevElement * (row - col) / col

   🔹 Steps:
       1. First element = 1
       2. For col = 1 → row-1:
             curr = prev * (row-col) / col
   🔹 Time Complexity: O(n^2)
       - Because each row takes O(row) to generate
   🔹 Space Complexity: O(1) extra
   ====================== */
vector<long long> generateRow(int row)
{
    vector<long long> ans;
    long long prev = 1;
    ans.push_back(prev);

    for (int col = 1; col < row; col++)
    {
        long long curr = (prev * (row - col)) / col;
        ans.push_back(curr);
        prev = curr;
    }
    return ans;
}

vector<vector<long long>> generateOptimal(int n)
{
    vector<vector<long long>> ans;

    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

/* =====================================================
   MAIN FUNCTION → For Testing in VS Code
   ===================================================== */
int main()
{
    int n = 5; // Example number of rows

    cout << "=== Pascal's Triangle (Variation 3) ===" << endl;
    cout << "Number of rows = " << n << endl;

    // Naive approach
    vector<vector<long long>> naive = generateNaive(n);
    cout << "\nNaive Approach (O(n^3)):" << endl;
    for (auto &row : naive)
    {
        for (auto x : row)
            cout << x << " ";
        cout << endl;
    }

    // Optimal approach
    vector<vector<long long>> optimal = generateOptimal(n);
    cout << "\nOptimal Approach (O(n^2)):" << endl;
    for (auto &row : optimal)
    {
        for (auto x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
