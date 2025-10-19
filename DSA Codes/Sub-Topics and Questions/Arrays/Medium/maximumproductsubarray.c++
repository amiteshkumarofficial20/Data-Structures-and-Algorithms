#include <bits/stdc++.h>
using namespace std;

/* ====================================================
   LeetCode 152: Maximum Product Subarray
   ----------------------------------------------------
   Problem:
   Given an integer array nums[], find the contiguous
   subarray within the array that has the largest product,
   and return that product.

   Example:
   Input:  nums = [2,3,-2,4]
   Output: 6   (because [2,3] has product 6)
==================================================== */

/* ====================================================
   1. BRUTE FORCE APPROACH (O(n^3))
   ----------------------------------------------------
   Idea:
   - Generate ALL possible subarrays.
   - For each subarray, compute its product using another loop.
   - Keep track of the maximum product found.

   Steps:
   1. Outer loop (i): starting index of subarray.
   2. Middle loop (j): ending index of subarray.
   3. Inner loop (k): multiply all elements nums[i..j].
   4. Update answer with max product.

   Time Complexity:  O(n^3)
                     → O(n^2) subarrays × O(n) to compute product
   Space Complexity: O(1)
                     → only variables for product and answer.
==================================================== */
int maxProductBruteON3(vector<int> &nums)
{
    int n = nums.size();
    long long ans = LLONG_MIN; // store max product

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long product = 1;
            for (int k = i; k <= j; k++)
            {
                product *= nums[k]; // compute product from scratch
            }
            ans = max(ans, product);
        }
    }
    return (int)ans;
}

/* ====================================================
   MAIN FUNCTION → Run O(n^3) Brute Force
==================================================== */
int main()
{
    vector<int> nums = {2, 3, -2, 4};

    cout << "=== Brute Force O(n^3) Solution ===\n";
    cout << "Maximum Product Subarray = " << maxProductBruteON3(nums) << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/* ====================================================
   LeetCode 152: Maximum Product Subarray
   ----------------------------------------------------
   Problem:
   Given an integer array nums[], find the contiguous
   subarray within the array that has the largest product,
   and return that product.

   Example:
   Input:  nums = [2,3,-2,4]
   Output: 6   (because [2,3] has product 6)
==================================================== */

/* ====================================================
   2. BETTER BRUTE FORCE APPROACH (O(n^2))
   ----------------------------------------------------
   Idea:
   - Generate ALL subarrays (using two loops).
   - Instead of recalculating product from scratch for
     each subarray, keep a running product as we extend
     the subarray.

   Steps:
   1. Outer loop (i): starting index of subarray.
   2. Inner loop (j): ending index of subarray.
   3. Maintain "product" for subarray nums[i..j].
   4. Update product by multiplying nums[j].
   5. Track maximum product found.

   Example Walkthrough:
   nums = [2,3,-2,4]
   i=0 → product=2 → max=2
          j=1: product=2*3=6 → max=6
          j=2: product=6*-2=-12
          j=3: product=-12*4=-48
   i=1 → product=3 → max=6
          j=2: product=3*-2=-6
          j=3: product=-6*4=-24
   i=2 → product=-2 → max=6
          j=3: product=-2*4=-8
   i=3 → product=4 → max=6

   Answer = 6

   Time Complexity:  O(n^2)
                     → O(n^2) subarrays, O(1) product update
   Space Complexity: O(1)
                     → only variables for product and answer
==================================================== */
int maxProductON2(vector<int> &nums)
{
    int n = nums.size();
    long long ans = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        long long product = 1;
        for (int j = i; j < n; j++)
        {
            product *= nums[j];      // extend subarray [i..j]
            ans = max(ans, product); // update max
        }
    }
    return (int)ans;
}

/* ====================================================
   MAIN FUNCTION → Run O(n^2) Approach
==================================================== */
int main()
{
    vector<int> nums = {2, 3, -2, 4};

    cout << "=== Better Brute Force O(n^2) Solution ===\n";
    cout << "Maximum Product Subarray = " << maxProductON2(nums) << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/* ====================================================
   LeetCode 152: Maximum Product Subarray
   ----------------------------------------------------
   OPTIMAL APPROACH → Prefix–Suffix Product
   ----------------------------------------------------
   🔹 Observation:
   - Product subarray can "flip sign" due to negatives.
   - If we only go left → right (prefix), we miss some cases.
   - If we only go right → left (suffix), we also miss some cases.
   - ✅ So, check both prefix & suffix and take the maximum.

   🔹 Edge Case:
   - Zeros split the array → reset product to 1.
   - Ensures we start fresh after a zero.

   ----------------------------------------------------
   Time Complexity:  O(n)   (2 passes over array)
   Space Complexity: O(1)   (only prefix, suffix, maxi)
   ----------------------------------------------------
*/

int maxProduct(vector<int> &nums)
{
    int n = nums.size();

    int prefix = 1;     // product from left → right
    int suffix = 1;     // product from right → left
    int maxi = INT_MIN; // answer (max product found)

    // Traverse from both sides
    for (int i = 0; i < n; i++)
    {
        // prefix product
        prefix *= nums[i];
        maxi = max(maxi, prefix);
        if (prefix == 0)
            prefix = 1; // reset after zero

        // suffix product (mirror index: n-1-i)
        suffix *= nums[n - 1 - i];
        maxi = max(maxi, suffix);
        if (suffix == 0)
            suffix = 1; // reset after zero
    }

    return maxi;
}

/* ====================================================
   MAIN FUNCTION → Run Example
   ---------------------------------------------------- */
int main()
{
    vector<int> nums = {2, 3, -2, 4}; // Example
    cout << "Maximum Product Subarray = " << maxProduct(nums) << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/* ====================================================
   LeetCode 152: Maximum Product Subarray
   ----------------------------------------------------
   OPTIMAL APPROACH → Kadane’s Algorithm Modification
   ----------------------------------------------------
   🔹 Idea:
   - Keep track of maxProd and minProd at each index.
   - Negative numbers can turn min into max and max into min.
   - Swap roles when nums[i] < 0.

   🔹 Formula:
   maxi = max(nums[i], nums[i]*old_maxi, nums[i]*old_mini)
   mini = min(nums[i], nums[i]*old_maxi, nums[i]*old_mini)

   🔹 Edge Case:
   - Single element array (answer is nums[0]).
   - Zeros reset product naturally via comparison.

   ----------------------------------------------------
   Time Complexity:  O(n)   (single pass)
   Space Complexity: O(1)   (constant extra variables)
   ----------------------------------------------------
*/

int maxProduct(vector<int> &nums)
{
    int n = nums.size();

    int maxi = nums[0]; // max product ending at current index
    int mini = nums[0]; // min product ending at current index
    int ans = nums[0];  // global maximum

    for (int i = 1; i < n; i++)
    {
        int curr = nums[i];

        // if current element is negative → swap maxi & mini
        if (curr < 0)
            swap(maxi, mini);

        // recalculate maxi & mini
        maxi = max(curr, curr * maxi);
        mini = min(curr, curr * mini);

        // update global maximum
        ans = max(ans, maxi);
    }

    return ans;
}

/* ====================================================
   MAIN FUNCTION → Run Example
   ---------------------------------------------------- */
int main()
{
    vector<int> nums = {2, 3, -2, 4}; // Example
    cout << "Maximum Product Subarray = " << maxProduct(nums) << "\n";
    return 0;
}
