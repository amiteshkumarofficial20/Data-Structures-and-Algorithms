# Algorithms in C++ STL — Complete Detailed Guide

> **Language:** C++17 / C++20  
> **Purpose:** DSA, Competitive Programming, Interviews, and STL reference  
> **Style:** Detailed explanations, commented implementations, STL equivalents, complexity analysis, and reusable templates.

---

# Table of Contents

1. Algorithm Basics
2. Complexity Analysis
3. STL Containers
4. Iterators
5. Searching
6. Sorting
7. Useful STL Algorithms
8. Two Pointers
9. Sliding Window
10. Prefix Sum
11. Difference Array
12. Binary Search on Answer
13. Stack
14. Queue and Deque
15. Hashing
16. Linked Lists
17. Trees
18. Binary Search Trees
19. Heaps / Priority Queue
20. Graphs
21. BFS
22. DFS
23. Cycle Detection
24. Topological Sort
25. Shortest Paths
26. Minimum Spanning Tree
27. DSU
28. Dynamic Programming
29. Greedy
30. Backtracking
31. Bit Manipulation
32. String Algorithms
33. Monotonic Stack
34. Monotonic Queue
35. Intervals
36. Coordinate Compression
37. Common Problem Patterns
38. Competitive Programming Templates
39. Complexity Cheat Sheet
40. Final Problem-Solving Checklist

---

# 1. Algorithm Basics

An **algorithm** is a finite sequence of well-defined steps used to solve a problem.

Example: find the maximum element.

```cpp
#include <bits/stdc++.h>
using namespace std;

int findMaximum(const vector<int>& a) {
    // Assume the first element is the maximum initially.
    int maximum = a[0];

    // Compare every remaining element.
    for (int i = 1; i < (int)a.size(); ++i) {
        if (a[i] > maximum) {
            maximum = a[i];
        }
    }

    return maximum;
}

int main() {
    vector<int> a = {10, 4, 25, 7, 18};

    cout << findMaximum(a) << '\n';

    return 0;
}
```

Complexity:

```text
Time:  O(n)
Space: O(1)
```

---

# 2. Complexity Analysis

## 2.1 Common Big-O Complexities

| Complexity | Typical Example          |
| ---------- | ------------------------ |
| O(1)       | Array access             |
| O(log n)   | Binary Search            |
| O(n)       | Linear Search            |
| O(n log n) | Merge Sort               |
| O(n²)      | Bubble Sort              |
| O(2^n)     | Some subset recursion    |
| O(n!)      | Brute-force permutations |

## O(1)

```cpp
int firstElement(const vector<int>& a) {
    // Direct indexing is constant time.
    return a[0];
}
```

## O(n)

```cpp
long long sumArray(const vector<int>& a) {
    long long sum = 0;

    // Executes once for every element.
    for (int x : a) {
        sum += x;
    }

    return sum;
}
```

## O(n²)

```cpp
void printPairs(const vector<int>& a) {
    // Outer loop: n iterations.
    for (int i = 0; i < (int)a.size(); ++i) {

        // Inner loop: n iterations for every i.
        for (int j = 0; j < (int)a.size(); ++j) {
            cout << a[i] << ' ' << a[j] << '\n';
        }
    }
}
```

---

# 3. STL Containers

## 3.1 Vector

`vector` is a dynamic array.

```cpp
vector<int> v = {10, 20, 30};

// Add at the end.
v.push_back(40);

// Remove last element.
v.pop_back();

// Access by index.
cout << v[0] << '\n';

// Number of elements.
cout << v.size() << '\n';

// Check whether empty.
cout << v.empty() << '\n';
```

Important complexities:

```text
Access:       O(1)
push_back:    O(1) amortized
pop_back:     O(1)
insert front: O(n)
erase front:  O(n)
```

---

## 3.2 Array

```cpp
array<int, 5> a = {1, 2, 3, 4, 5};

cout << a[2] << '\n';
```

Unlike a C-style array, `std::array` provides STL functions such as:

```cpp
a.size();
a.begin();
a.end();
a.front();
a.back();
```

---

## 3.3 Deque

A deque supports insertion/removal from both ends.

```cpp
deque<int> dq;

dq.push_back(10);
dq.push_front(20);

dq.pop_back();
dq.pop_front();
```

Typical end operations are `O(1)`.

---

## 3.4 Set

`set` stores unique values in sorted order.

```cpp
set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(20); // Duplicate is ignored.

for (int x : s) {
    cout << x << ' ';
}
```

Output:

```text
10 20 30
```

Operations:

```text
insert: O(log n)
find:   O(log n)
erase:  O(log n)
```

---

## 3.5 Multiset

Duplicates are allowed.

```cpp
multiset<int> ms;

ms.insert(10);
ms.insert(10);
ms.insert(20);

cout << ms.count(10) << '\n';
// 2
```

---

## 3.6 Map

`map` stores key-value pairs sorted by key.

```cpp
map<string, int> marks;

marks["Alice"] = 95;
marks["Bob"] = 87;

cout << marks["Alice"] << '\n';
```

Complexity:

```text
insert/find/erase: O(log n)
```

---

## 3.7 Unordered Map

Hash-table-based key-value storage.

```cpp
unordered_map<string, int> marks;

marks["Alice"] = 95;

cout << marks["Alice"] << '\n';
```

Average complexity:

```text
insert: O(1)
find:   O(1)
erase:  O(1)
```

Worst-case can be `O(n)`.

---

## 3.8 Priority Queue

Default priority queue is a max heap.

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top() << '\n';
// 30

pq.pop();
```

Min heap:

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

---

# 4. Iterators

```cpp
vector<int> a = {10, 20, 30, 40};

auto it = a.begin();

cout << *it << '\n';
// 10
```

`begin()` points to the first element.

`end()` points one position after the last element.

```cpp
for (auto it = a.begin(); it != a.end(); ++it) {
    cout << *it << ' ';
}
```

Range-based loop:

```cpp
for (int x : a) {
    cout << x << ' ';
}
```

---

# 5. Searching Algorithms

## 5.1 Linear Search

```cpp
int linearSearch(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); ++i) {

        // Target found.
        if (a[i] == target) {
            return i;
        }
    }

    // Not found.
    return -1;
}
```

Complexity:

```text
Best:  O(1)
Worst: O(n)
Space: O(1)
```

---

## 5.2 STL `find`

```cpp
vector<int> a = {10, 20, 30, 40};

auto it = find(a.begin(), a.end(), 30);

if (it != a.end()) {
    int index = distance(a.begin(), it);

    cout << index << '\n';
}
```

---

# 6. Binary Search

Binary search requires a sorted array.

```cpp
int binarySearch(const vector<int>& a, int target) {
    int left = 0;
    int right = (int)a.size() - 1;

    while (left <= right) {

        // Safer than (left + right) / 2
        // when integer overflow is possible.
        int mid = left + (right - left) / 2;

        if (a[mid] == target) {
            return mid;
        }

        if (a[mid] < target) {
            // Target can only exist on the right.
            left = mid + 1;
        } else {
            // Target can only exist on the left.
            right = mid - 1;
        }
    }

    return -1;
}
```

Complexity:

```text
Time: O(log n)
Space: O(1)
```

---

## 6.1 `binary_search`

```cpp
vector<int> a = {1, 2, 3, 4, 5};

bool exists = binary_search(a.begin(), a.end(), 3);
```

Returns `true` or `false`.

---

## 6.2 `lower_bound`

Returns iterator to the first element `>= target`.

```cpp
vector<int> a = {1, 2, 2, 2, 4, 5};

auto it = lower_bound(a.begin(), a.end(), 2);

int index = distance(a.begin(), it);

cout << index << '\n';
// 1
```

---

## 6.3 `upper_bound`

Returns iterator to the first element `> target`.

```cpp
auto it = upper_bound(a.begin(), a.end(), 2);

cout << distance(a.begin(), it) << '\n';
// 4
```

---

## 6.4 Count Occurrences in Sorted Array

```cpp
int countOccurrences(const vector<int>& a, int x) {

    // First position where x can appear.
    auto first = lower_bound(a.begin(), a.end(), x);

    // First position strictly greater than x.
    auto last = upper_bound(a.begin(), a.end(), x);

    // Difference between the two positions
    // equals the number of occurrences.
    return last - first;
}
```

Complexity:

```text
O(log n)
```

---

# 7. Sorting Algorithms

## 7.1 Bubble Sort

Repeatedly compares adjacent elements and swaps them if necessary.

```cpp
void bubbleSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n; ++i) {

        // Tracks whether this pass changed anything.
        bool swapped = false;

        // Last i elements are already sorted.
        for (int j = 0; j < n - i - 1; ++j) {

            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        // If no swap happened, array is already sorted.
        if (!swapped) {
            break;
        }
    }
}
```

Complexity:

```text
Best:  O(n)
Average: O(n²)
Worst: O(n²)
Space: O(1)
```

---

# 8. Selection Sort

Select the smallest remaining element.

```cpp
void selectionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n; ++i) {

        // Assume a[i] is the smallest.
        int minIndex = i;

        // Search the remaining unsorted part.
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        // Put smallest element at position i.
        swap(a[i], a[minIndex]);
    }
}
```

Complexity:

```text
O(n²)
```

---

# 9. Insertion Sort

Builds a sorted section one element at a time.

```cpp
void insertionSort(vector<int>& a) {
    int n = a.size();

    // First element alone is already sorted.
    for (int i = 1; i < n; ++i) {

        // Element that must be inserted.
        int key = a[i];

        // Start from the previous element.
        int j = i - 1;

        // Shift larger elements to the right.
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }

        // Insert key at its correct location.
        a[j + 1] = key;
    }
}
```

Complexity:

```text
Best: O(n)
Average: O(n²)
Worst: O(n²)
```

Very useful when the data is nearly sorted.

---

# 10. Merge Sort

Merge sort uses divide and conquer.

Steps:

1. Divide the array.
2. Sort both halves.
3. Merge sorted halves.

```cpp
void mergeArrays(
    vector<int>& a,
    int left,
    int mid,
    int right
) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    // Compare elements from both sorted halves.
    while (i <= mid && j <= right) {

        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            ++i;
        } else {
            temp.push_back(a[j]);
            ++j;
        }
    }

    // Copy remaining left-half elements.
    while (i <= mid) {
        temp.push_back(a[i]);
        ++i;
    }

    // Copy remaining right-half elements.
    while (j <= right) {
        temp.push_back(a[j]);
        ++j;
    }

    // Copy merged result back into original array.
    for (int k = 0; k < (int)temp.size(); ++k) {
        a[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& a, int left, int right) {

    // Base case.
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // Sort left half.
    mergeSort(a, left, mid);

    // Sort right half.
    mergeSort(a, mid + 1, right);

    // Merge both sorted halves.
    mergeArrays(a, left, mid, right);
}
```

Complexity:

```text
Time: O(n log n)
Space: O(n)
```

---

# 11. Quick Sort

Quick sort chooses a pivot and partitions the array.

```cpp
int partitionArray(vector<int>& a, int low, int high) {
    // Choose last element as pivot.
    int pivot = a[high];

    // Index of the location where the next
    // smaller element should be placed.
    int i = low - 1;

    for (int j = low; j < high; ++j) {

        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }

    // Put pivot into its final position.
    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {

    if (low >= high) {
        return;
    }

    int pivotIndex = partitionArray(a, low, high);

    quickSort(a, low, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, high);
}
```

Average:

```text
O(n log n)
```

Worst case:

```text
O(n²)
```

---

# 12. STL `sort`

Usually the first choice for sorting in C++.

```cpp
vector<int> a = {5, 1, 4, 2, 3};

sort(a.begin(), a.end());
```

Descending:

```cpp
sort(a.begin(), a.end(), greater<int>());
```

Custom comparator:

```cpp
sort(a.begin(), a.end(), [](int x, int y) {
    // Sort by absolute value.
    return abs(x) < abs(y);
});
```

---

# 13. `stable_sort`

`stable_sort` preserves the relative order of equivalent elements.

```cpp
stable_sort(a.begin(), a.end());
```

It can use more memory than `sort`.

---

# 14. `reverse`

```cpp
reverse(a.begin(), a.end());
```

Complexity:

```text
O(n)
```

---

# 15. `min_element` and `max_element`

```cpp
vector<int> a = {5, 2, 9, 1, 7};

auto minIt = min_element(a.begin(), a.end());
auto maxIt = max_element(a.begin(), a.end());

cout << *minIt << '\n';
// 1

cout << *maxIt << '\n';
// 9
```

Complexity:

```text
O(n)
```

---

# 16. `accumulate`

Requires:

```cpp
#include <numeric>
```

```cpp
vector<int> a = {1, 2, 3, 4, 5};

int sum = accumulate(a.begin(), a.end(), 0);

cout << sum << '\n';
// 15
```

For large sums:

```cpp
long long sum = accumulate(
    a.begin(),
    a.end(),
    0LL
);
```

The `0LL` is important because it makes the accumulation type `long long`.

---

# 17. `count`

```cpp
vector<int> a = {1, 2, 2, 3, 2};

int frequency = count(a.begin(), a.end(), 2);

cout << frequency << '\n';
// 3
```

---

# 18. `count_if`

```cpp
int evenCount = count_if(
    a.begin(),
    a.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

---

# 19. `all_of`, `any_of`, `none_of`

```cpp
vector<int> a = {2, 4, 6, 8};

bool allEven = all_of(
    a.begin(),
    a.end(),
    [](int x) {
        return x % 2 == 0;
    }
);

bool hasOdd = any_of(
    a.begin(),
    a.end(),
    [](int x) {
        return x % 2 != 0;
    }
);

bool noNegative = none_of(
    a.begin(),
    a.end(),
    [](int x) {
        return x < 0;
    }
);
```

---

# 20. `find_if`

Find the first element satisfying a condition.

```cpp
auto it = find_if(
    a.begin(),
    a.end(),
    [](int x) {
        return x > 5;
    }
);

if (it != a.end()) {
    cout << *it << '\n';
}
```

---

# 21. `remove` and Erase Idiom

Important:

`remove` does **not** actually reduce the vector size.

Correct pattern:

```cpp
a.erase(
    remove(a.begin(), a.end(), 5),
    a.end()
);
```

This removes every occurrence of `5`.

C++20 provides:

```cpp
erase(a, 5);
```

for containers where the corresponding free function is available.

---

# 22. Two Pointers

Two pointers are useful when processing an array/string from two directions or maintaining two positions.

## Example: Pair Sum in Sorted Array

```cpp
bool hasPairWithSum(
    const vector<int>& a,
    int target
) {
    int left = 0;
    int right = (int)a.size() - 1;

    while (left < right) {

        int sum = a[left] + a[right];

        if (sum == target) {
            return true;
        }

        if (sum < target) {
            // Need a larger sum.
            ++left;
        } else {
            // Need a smaller sum.
            --right;
        }
    }

    return false;
}
```

Complexity:

```text
O(n)
```

The array must be sorted.

---

# 23. Reverse an Array Using Two Pointers

```cpp
void reverseArray(vector<int>& a) {
    int left = 0;
    int right = a.size() - 1;

    while (left < right) {
        swap(a[left], a[right]);

        ++left;
        --right;
    }
}
```

---

# 24. Sliding Window

Sliding window is useful for contiguous subarrays/substrings.

## Fixed Window Sum

```cpp
long long maximumWindowSum(
    const vector<int>& a,
    int k
) {
    int n = a.size();

    // Sum of the first window.
    long long windowSum = 0;

    for (int i = 0; i < k; ++i) {
        windowSum += a[i];
    }

    long long answer = windowSum;

    // Move the window one position at a time.
    for (int right = k; right < n; ++right) {

        // Add new element entering the window.
        windowSum += a[right];

        // Remove old element leaving the window.
        windowSum -= a[right - k];

        answer = max(answer, windowSum);
    }

    return answer;
}
```

Complexity:

```text
O(n)
```

Without sliding window, a naive solution may take `O(n*k)`.

---

# 25. Variable Sliding Window

Example: longest subarray whose sum is at most `k`, assuming all values are non-negative.

```cpp
int longestSubarrayAtMostK(
    const vector<int>& a,
    long long k
) {
    int left = 0;
    long long sum = 0;
    int answer = 0;

    for (int right = 0; right < (int)a.size(); ++right) {

        sum += a[right];

        // Shrink the window while the condition is violated.
        while (left <= right && sum > k) {
            sum -= a[left];
            ++left;
        }

        // Current window [left, right] is valid.
        answer = max(answer, right - left + 1);
    }

    return answer;
}
```

---

# 26. Prefix Sum

Prefix sum allows repeated range-sum queries in `O(1)`.

Build:

```cpp
vector<long long> prefix(n + 1, 0);

for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + a[i];
}
```

Range sum `[l, r]`:

```cpp
long long rangeSum(
    const vector<long long>& prefix,
    int l,
    int r
) {
    // prefix[r + 1] contains sum [0, r].
    // Subtract prefix[l] to remove [0, l - 1].
    return prefix[r + 1] - prefix[l];
}
```

Complexity:

```text
Build: O(n)
Query: O(1)
```

---

# 27. Difference Array

Difference arrays are useful for applying many range updates.

Suppose we want:

```text
Add x to every element from l to r.
```

Instead of updating every element:

```cpp
diff[l] += x;
diff[r + 1] -= x;
```

Then reconstruct using prefix sum.

```cpp
vector<long long> diff(n + 1, 0);

// Add x to [l, r].
diff[l] += x;

if (r + 1 < n) {
    diff[r + 1] -= x;
}

// Reconstruct final values.
long long current = 0;

for (int i = 0; i < n; ++i) {
    current += diff[i];

    // current is the total update applied to i.
}
```

---

# 28. Binary Search on Answer

This is one of the most important competitive-programming patterns.

Instead of binary-searching an array, binary-search the answer itself.

The key question:

> Is the answer `x` feasible?

If feasibility is monotonic:

```text
false false false true true true
```

we can binary search.

## Generic Template

```cpp
long long low = MIN_ANSWER;
long long high = MAX_ANSWER;
long long answer = high;

while (low <= high) {

    long long mid = low + (high - low) / 2;

    if (can(mid)) {
        // mid is possible.
        answer = mid;

        // Try to find a smaller answer.
        high = mid - 1;
    } else {
        // mid is impossible.
        low = mid + 1;
    }
}
```

---

# 29. Stack

A stack follows:

```text
LIFO = Last In, First Out
```

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top() << '\n';
// 30

st.pop();

cout << st.top() << '\n';
// 20
```

Complexity:

```text
push: O(1)
pop:  O(1)
top:  O(1)
```

---

# 30. Balanced Parentheses

```cpp
bool validParentheses(const string& s) {
    stack<char> st;

    for (char c : s) {

        // Opening brackets go into the stack.
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }

        else {
            // Closing bracket without an opening bracket.
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            st.pop();

            // Check matching pair.
            if (c == ')' && top != '(') {
                return false;
            }

            if (c == ']' && top != '[') {
                return false;
            }

            if (c == '}' && top != '{') {
                return false;
            }
        }
    }

    // Every opening bracket must have been closed.
    return st.empty();
}
```

---

# 31. Queue

Queue follows:

```text
FIFO = First In, First Out
```

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.front() << '\n';
// 10

q.pop();

cout << q.front() << '\n';
// 20
```

---

# 32. Deque

```cpp
deque<int> dq;

dq.push_back(10);
dq.push_front(20);

cout << dq.front() << '\n';
cout << dq.back() << '\n';

dq.pop_front();
dq.pop_back();
```

Useful when both ends need to be modified.

---

# 33. Hashing

## Frequency Map

```cpp
unordered_map<int, int> frequency;

for (int x : a) {
    // Increase the count for x.
    ++frequency[x];
}
```

---

## Frequency of Characters

```cpp
vector<int> freq(26, 0);

for (char c : s) {

    // Convert lowercase character into index 0..25.
    ++freq[c - 'a'];
}
```

---

# 34. Two Sum Using Hashing

```cpp
vector<int> twoSum(
    const vector<int>& a,
    int target
) {
    unordered_map<int, int> position;

    for (int i = 0; i < (int)a.size(); ++i) {

        int needed = target - a[i];

        // Check whether the required value
        // appeared earlier.
        if (position.count(needed)) {
            return {
                position[needed],
                i
            };
        }

        // Store current value and index.
        position[a[i]] = i;
    }

    return {};
}
```

Average complexity:

```text
Time: O(n)
Space: O(n)
```

---

# 35. Linked List

Basic node:

```cpp
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
```

---

# 36. Reverse Linked List

```cpp
Node* reverseList(Node* head) {

    // Previous node starts as null because
    // the new tail will point to null.
    Node* previous = nullptr;

    // Current node starts at head.
    Node* current = head;

    while (current != nullptr) {

        // Save next node before changing the link.
        Node* nextNode = current->next;

        // Reverse current node's pointer.
        current->next = previous;

        // Move previous forward.
        previous = current;

        // Move current forward.
        current = nextNode;
    }

    // Previous is now the new head.
    return previous;
}
```

Complexity:

```text
Time: O(n)
Space: O(1)
```

---

# 37. Find Middle of Linked List

Use slow and fast pointers.

```cpp
Node* findMiddle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr &&
           fast->next != nullptr) {

        // Slow moves one step.
        slow = slow->next;

        // Fast moves two steps.
        fast = fast->next->next;
    }

    return slow;
}
```

When `fast` reaches the end, `slow` is around the middle.

---

# 38. Detect Cycle in Linked List

Floyd's cycle detection algorithm:

```cpp
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        // If they meet, a cycle exists.
        if (slow == fast) {
            return true;
        }
    }

    return false;
}
```

Complexity:

```text
Time: O(n)
Space: O(1)
```

---

# 39. Trees

Basic binary-tree node:

```cpp
struct TreeNode {
    int value;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : value(x),
          left(nullptr),
          right(nullptr) {}
};
```

---

# 40. Tree Traversals

There are three classic depth-first traversals.

```text
Inorder:   Left -> Root -> Right
Preorder:  Root -> Left -> Right
Postorder: Left -> Right -> Root
```

---

## 40.1 Inorder

```cpp
void inorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    // Visit left subtree.
    inorder(root->left);

    // Process root.
    cout << root->value << ' ';

    // Visit right subtree.
    inorder(root->right);
}
```

---

## 40.2 Preorder

```cpp
void preorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    cout << root->value << ' ';

    preorder(root->left);

    preorder(root->right);
}
```

---

## 40.3 Postorder

```cpp
void postorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->value << ' ';
}
```

---

# 41. Level Order Traversal

Uses BFS and a queue.

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> answer;

    if (root == nullptr) {
        return answer;
    }

    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {

        int levelSize = q.size();

        vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {

            TreeNode* node = q.front();
            q.pop();

            currentLevel.push_back(node->value);

            if (node->left != nullptr) {
                q.push(node->left);
            }

            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        answer.push_back(currentLevel);
    }

    return answer;
}
```

---

# 42. Height of Binary Tree

```cpp
int height(TreeNode* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Current node contributes one level.
    return 1 + max(leftHeight, rightHeight);
}
```

Complexity:

```text
O(n)
```

---

# 43. Binary Search Tree

BST property:

```text
left subtree < root < right subtree
```

Search:

```cpp
bool searchBST(TreeNode* root, int target) {

    TreeNode* current = root;

    while (current != nullptr) {

        if (current->value == target) {
            return true;
        }

        if (target < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}
```

Balanced BST search:

```text
O(log n)
```

Worst-case unbalanced BST:

```text
O(n)
```

---

# 44. Heap / Priority Queue

## Max Heap

```cpp
priority_queue<int> pq;

pq.push(5);
pq.push(20);
pq.push(10);

cout << pq.top() << '\n';
// 20
```

---

## Min Heap

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;

pq.push(5);
pq.push(20);
pq.push(10);

cout << pq.top() << '\n';
// 5
```

---

# 45. K Largest Elements

```cpp
vector<int> kLargest(
    const vector<int>& a,
    int k
) {
    // Min heap stores the current k largest values.
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

    for (int x : a) {

        pq.push(x);

        // Keep only k elements.
        if ((int)pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> answer;

    while (!pq.empty()) {
        answer.push_back(pq.top());
        pq.pop();
    }

    return answer;
}
```

Complexity:

```text
O(n log k)
```

---

# 46. Graph Representation

For most problems, adjacency lists are preferred.

## Unweighted Graph

```cpp
int n;
vector<vector<int>> graph(n);

graph[u].push_back(v);
graph[v].push_back(u);
```

For directed graph:

```cpp
graph[u].push_back(v);
```

---

# 47. Weighted Graph

```cpp
vector<vector<pair<int, int>>> graph(n);

// pair = {neighbor, weight}
graph[u].push_back({v, weight});
```

Access:

```cpp
for (auto [neighbor, weight] : graph[u]) {
    cout << neighbor << ' '
         << weight << '\n';
}
```

---

# 48. BFS

Breadth-first search explores level by level.

```cpp
vector<int> bfs(
    int start,
    const vector<vector<int>>& graph
) {
    int n = graph.size();

    vector<int> visited(n, false);
    vector<int> order;

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        order.push_back(node);

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {

                visited[neighbor] = true;

                q.push(neighbor);
            }
        }
    }

    return order;
}
```

Complexity:

```text
O(V + E)
```

where:

```text
V = number of vertices
E = number of edges
```

---

# 49. Shortest Path in Unweighted Graph

BFS gives shortest distance when every edge has equal cost.

```cpp
vector<int> shortestPath(
    int start,
    const vector<vector<int>>& graph
) {
    int n = graph.size();

    vector<int> distance(n, -1);

    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {

            // If not visited.
            if (distance[neighbor] == -1) {

                // One more edge from current node.
                distance[neighbor] =
                    distance[node] + 1;

                q.push(neighbor);
            }
        }
    }

    return distance;
}
```

---

# 50. DFS

Depth-first search explores as far as possible before backtracking.

```cpp
void dfs(
    int node,
    const vector<vector<int>>& graph,
    vector<bool>& visited
) {
    visited[node] = true;

    cout << node << ' ';

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
```

Complexity:

```text
O(V + E)
```

---

# 51. Iterative DFS

Avoid recursion depth issues by using a stack.

```cpp
void iterativeDFS(
    int start,
    const vector<vector<int>>& graph
) {
    int n = graph.size();

    vector<bool> visited(n, false);

    stack<int> st;

    st.push(start);

    while (!st.empty()) {

        int node = st.top();
        st.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;

        cout << node << ' ';

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}
```

---

# 52. Cycle Detection in Undirected Graph

Use DFS with a parent.

```cpp
bool hasCycleDFS(
    int node,
    int parent,
    const vector<vector<int>>& graph,
    vector<bool>& visited
) {
    visited[node] = true;

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {

            if (hasCycleDFS(
                    neighbor,
                    node,
                    graph,
                    visited
                )) {
                return true;
            }

        } else if (neighbor != parent) {

            // Already visited and it is not the parent.
            // Therefore a cycle exists.
            return true;
        }
    }

    return false;
}
```

---

# 53. Cycle Detection in Directed Graph

Use three states:

```text
0 = unvisited
1 = currently in recursion stack
2 = completely processed
```

```cpp
bool directedCycleDFS(
    int node,
    const vector<vector<int>>& graph,
    vector<int>& state
) {
    // Mark as currently processing.
    state[node] = 1;

    for (int neighbor : graph[node]) {

        if (state[neighbor] == 1) {
            // Back edge to a currently active node.
            return true;
        }

        if (state[neighbor] == 0) {

            if (directedCycleDFS(
                    neighbor,
                    graph,
                    state
                )) {
                return true;
            }
        }
    }

    // Fully processed.
    state[node] = 2;

    return false;
}
```

---

# 54. Topological Sort

Topological ordering exists only for a DAG:

```text
Directed Acyclic Graph
```

## Kahn's Algorithm

Uses indegree + queue.

```cpp
vector<int> topologicalSort(
    const vector<vector<int>>& graph
) {
    int n = graph.size();

    vector<int> indegree(n, 0);

    // Calculate indegree of every node.
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            ++indegree[v];
        }
    }

    queue<int> q;

    // All nodes with indegree zero can come first.
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : graph[u]) {

            --indegree[v];

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If not all vertices are included,
    // a cycle exists.
    if ((int)order.size() != n) {
        return {};
    }

    return order;
}
```

Complexity:

```text
O(V + E)
```

---

# 55. Dijkstra's Algorithm

Dijkstra finds shortest paths from a source when edge weights are **non-negative**.

Use a min heap.

```cpp
vector<long long> dijkstra(
    int source,
    const vector<vector<pair<int, int>>>& graph
) {
    int n = graph.size();

    const long long INF =
        numeric_limits<long long>::max() / 4;

    vector<long long> dist(n, INF);

    // {distance, node}
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {

        auto [currentDistance, node] = pq.top();
        pq.pop();

        // This is an outdated heap entry.
        if (currentDistance != dist[node]) {
            continue;
        }

        for (auto [neighbor, weight] : graph[node]) {

            long long newDistance =
                currentDistance + weight;

            if (newDistance < dist[neighbor]) {

                dist[neighbor] = newDistance;

                pq.push({
                    newDistance,
                    neighbor
                });
            }
        }
    }

    return dist;
}
```

Complexity:

```text
O((V + E) log V)
```

Do **not** use Dijkstra when negative edge weights are present.

---

# 56. Bellman-Ford

Bellman-Ford handles negative edges and can detect negative cycles reachable from the source.

```cpp
struct Edge {
    int u;
    int v;
    long long weight;
};

vector<long long> bellmanFord(
    int n,
    int source,
    const vector<Edge>& edges
) {
    const long long INF =
        numeric_limits<long long>::max() / 4;

    vector<long long> dist(n, INF);

    dist[source] = 0;

    // Relax every edge n - 1 times.
    for (int i = 1; i <= n - 1; ++i) {

        bool changed = false;

        for (const Edge& e : edges) {

            // Ignore unreachable vertices.
            if (dist[e.u] == INF) {
                continue;
            }

            if (dist[e.u] + e.weight < dist[e.v]) {

                dist[e.v] =
                    dist[e.u] + e.weight;

                changed = true;
            }
        }

        // Early termination if no update happened.
        if (!changed) {
            break;
        }
    }

    return dist;
}
```

Complexity:

```text
O(VE)
```

---

# 57. Floyd-Warshall

Find shortest paths between **every pair** of vertices.

```cpp
const long long INF = 4e18;

vector<vector<long long>> dist(
    n,
    vector<long long>(n, INF)
);

// Distance from node to itself is zero.
for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
}

// Initialize direct edges here.

for (int k = 0; k < n; ++k) {

    for (int i = 0; i < n; ++i) {

        if (dist[i][k] == INF) {
            continue;
        }

        for (int j = 0; j < n; ++j) {

            if (dist[k][j] == INF) {
                continue;
            }

            dist[i][j] = min(
                dist[i][j],
                dist[i][k] + dist[k][j]
            );
        }
    }
}
```

Complexity:

```text
O(V³)
```

---

# 58. Minimum Spanning Tree

An MST connects all vertices with minimum total edge weight.

Two major algorithms:

1. Kruskal
2. Prim

---

# 59. Kruskal's Algorithm

Kruskal:

1. Sort edges by weight.
2. Add the next smallest edge if it doesn't form a cycle.
3. DSU is used to detect cycles.

```cpp
struct Edge {
    int u;
    int v;
    int weight;
};
```

Sort:

```cpp
sort(
    edges.begin(),
    edges.end(),
    [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }
);
```

Complete Kruskal:

```cpp
int kruskal(
    int n,
    vector<Edge> edges
) {
    sort(
        edges.begin(),
        edges.end(),
        [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        }
    );

    // DSU implementation is shown later.
    // It determines whether two vertices
    // already belong to the same component.

    // ...
    return 0;
}
```

---

# 60. Disjoint Set Union

DSU supports:

```text
find(x)
union(a, b)
```

with path compression and union by size/rank.

```cpp
class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        // Initially every node is its own parent.
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {

        // If x is not its own parent,
        // recursively find its root.
        if (parent[x] != x) {

            // Path compression:
            // directly connect x to the root.
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int a, int b) {

        a = find(a);
        b = find(b);

        // Already in the same component.
        if (a == b) {
            return false;
        }

        // Attach smaller tree to larger tree.
        if (size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];

        return true;
    }
};
```

Almost constant amortized complexity:

```text
O(alpha(n))
```

where `alpha` is the inverse Ackermann function.

---

# 61. Complete Kruskal Implementation

```cpp
struct Edge {
    int u;
    int v;
    int weight;
};

int kruskal(int n, vector<Edge> edges) {

    // Sort edges by increasing weight.
    sort(
        edges.begin(),
        edges.end(),
        [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        }
    );

    DSU dsu(n);

    int totalWeight = 0;
    int edgesUsed = 0;

    for (const Edge& e : edges) {

        // If joining u and v does not create a cycle,
        // include this edge in the MST.
        if (dsu.unite(e.u, e.v)) {

            totalWeight += e.weight;

            ++edgesUsed;

            // An MST of n vertices has n - 1 edges.
            if (edgesUsed == n - 1) {
                break;
            }
        }
    }

    // If fewer than n - 1 edges were used,
    // the graph was disconnected.
    if (edgesUsed != n - 1) {
        return -1;
    }

    return totalWeight;
}
```

---

# 62. Prim's Algorithm

Prim grows the MST from a starting vertex.

```cpp
long long prim(
    int start,
    const vector<vector<pair<int, int>>>& graph
) {
    int n = graph.size();

    const long long INF =
        numeric_limits<long long>::max() / 4;

    vector<bool> used(n, false);

    // {edgeWeight, vertex}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, start});

    long long total = 0;

    int count = 0;

    while (!pq.empty()) {

        auto [weight, node] = pq.top();
        pq.pop();

        if (used[node]) {
            continue;
        }

        used[node] = true;

        total += weight;

        ++count;

        for (auto [neighbor, edgeWeight] : graph[node]) {

            if (!used[neighbor]) {
                pq.push({
                    edgeWeight,
                    neighbor
                });
            }
        }
    }

    if (count != n) {
        return -1;
    }

    return total;
}
```

Typical complexity:

```text
O(E log V)
```

---

# 63. Dynamic Programming

Dynamic Programming (DP) is useful when a problem has:

1. **Overlapping subproblems**
2. **Optimal substructure**

Two common approaches:

- Memoization
- Tabulation

---

# 64. Fibonacci — Naive Recursion

```cpp
long long fib(int n) {

    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}
```

This repeats many calculations.

Complexity is approximately:

```text
O(2^n)
```

---

# 65. Fibonacci — Memoization

```cpp
long long fibMemo(
    int n,
    vector<long long>& dp
) {
    // Base cases.
    if (n <= 1) {
        return n;
    }

    // Return already computed answer.
    if (dp[n] != -1) {
        return dp[n];
    }

    // Compute and store the result.
    return dp[n] =
        fibMemo(n - 1, dp)
        + fibMemo(n - 2, dp);
}
```

Usage:

```cpp
int n = 50;

vector<long long> dp(n + 1, -1);

cout << fibMemo(n, dp);
```

Complexity:

```text
Time: O(n)
Space: O(n)
```

---

# 66. Fibonacci — Tabulation

```cpp
long long fibTabulation(int n) {

    if (n <= 1) {
        return n;
    }

    vector<long long> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] =
            dp[i - 1]
            + dp[i - 2];
    }

    return dp[n];
}
```

Space can be optimized:

```cpp
long long fibOptimized(int n) {

    if (n <= 1) {
        return n;
    }

    long long previous2 = 0;
    long long previous1 = 1;

    for (int i = 2; i <= n; ++i) {

        long long current =
            previous1 + previous2;

        previous2 = previous1;
        previous1 = current;
    }

    return previous1;
}
```

Space:

```text
O(1)
```

---

# 67. 0/1 Knapsack

Given items with weight and value, choose each item at most once.

```cpp
int knapsack(
    int capacity,
    const vector<int>& weight,
    const vector<int>& value
) {
    int n = weight.size();

    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; ++i) {

        // Iterate backwards because each item
        // can be used only once.
        for (int w = capacity;
             w >= weight[i];
             --w) {

            dp[w] = max(
                dp[w],
                value[i]
                + dp[w - weight[i]]
            );
        }
    }

    return dp[capacity];
}
```

Complexity:

```text
O(n * capacity)
```

Important:

```text
0/1 Knapsack -> capacity loop goes backwards.
Unbounded Knapsack -> capacity loop usually goes forwards.
```

---

# 68. Longest Common Subsequence

LCS finds the longest subsequence common to two strings.

```cpp
int lcs(
    const string& a,
    const string& b
) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= m; ++j) {

            if (a[i - 1] == b[j - 1]) {

                // Matching characters extend
                // the previous LCS.
                dp[i][j] =
                    dp[i - 1][j - 1] + 1;

            } else {

                // Skip one character from either string.
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    return dp[n][m];
}
```

Complexity:

```text
Time: O(nm)
Space: O(nm)
```

---

# 69. Longest Increasing Subsequence

Efficient LIS uses a vector often called `tails`.

```cpp
int lengthOfLIS(const vector<int>& a) {

    vector<int> tails;

    for (int x : a) {

        // Find first value >= x.
        auto it = lower_bound(
            tails.begin(),
            tails.end(),
            x
        );

        if (it == tails.end()) {

            // x is larger than every current tail.
            tails.push_back(x);

        } else {

            // Replace the first tail >= x.
            // This keeps future possibilities flexible.
            *it = x;
        }
    }

    return tails.size();
}
```

Complexity:

```text
O(n log n)
```

---

# 70. Greedy Algorithms

A greedy algorithm makes a locally optimal choice at every step.

Greedy works only when the problem has the required structural properties.

---

# 71. Activity Selection

Choose the maximum number of non-overlapping activities.

Strategy:

> Always choose the activity that finishes earliest.

```cpp
int maxActivities(
    vector<pair<int, int>> activities
) {
    // Sort by finishing time.
    sort(
        activities.begin(),
        activities.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );

    int answer = 0;

    int lastFinish =
        numeric_limits<int>::min();

    for (auto [start, finish] : activities) {

        if (start >= lastFinish) {

            ++answer;

            lastFinish = finish;
        }
    }

    return answer;
}
```

---

# 72. Fractional Knapsack

Unlike 0/1 knapsack, fractions of items can be taken.

Sort by:

```text
value / weight
```

```cpp
struct Item {
    double value;
    double weight;
};

double fractionalKnapsack(
    double capacity,
    vector<Item> items
) {
    sort(
        items.begin(),
        items.end(),
        [](const Item& a, const Item& b) {

            return
                a.value / a.weight
                >
                b.value / b.weight;
        }
    );

    double answer = 0.0;

    for (const Item& item : items) {

        if (capacity == 0) {
            break;
        }

        double take =
            min(capacity, item.weight);

        answer +=
            take * (item.value / item.weight);

        capacity -= take;
    }

    return answer;
}
```

---

# 73. Backtracking

Backtracking explores choices and undoes them when necessary.

Typical problems:

- Subsets
- Permutations
- Combination Sum
- N-Queens
- Sudoku
- Maze

---

# 74. Generate All Subsets

```cpp
void generateSubsets(
    int index,
    const vector<int>& a,
    vector<int>& current,
    vector<vector<int>>& answer
) {
    // If every element has been considered,
    // store the current subset.
    if (index == (int)a.size()) {

        answer.push_back(current);

        return;
    }

    // Choice 1:
    // Do not take a[index].
    generateSubsets(
        index + 1,
        a,
        current,
        answer
    );

    // Choice 2:
    // Take a[index].
    current.push_back(a[index]);

    generateSubsets(
        index + 1,
        a,
        current,
        answer
    );

    // Undo the choice.
    current.pop_back();
}
```

Number of subsets:

```text
2^n
```

Complexity is at least proportional to the output size.

---

# 75. Generate Permutations

STL provides:

```cpp
next_permutation
```

Example:

```cpp
vector<int> a = {1, 2, 3};

sort(a.begin(), a.end());

do {
    for (int x : a) {
        cout << x << ' ';
    }

    cout << '\n';

} while (next_permutation(
    a.begin(),
    a.end()
));
```

---

# 76. Manual Permutation Backtracking

```cpp
void generatePermutations(
    vector<int>& a,
    int index,
    vector<vector<int>>& answer
) {
    if (index == (int)a.size()) {

        answer.push_back(a);

        return;
    }

    for (int i = index;
         i < (int)a.size();
         ++i) {

        // Choose element i for position index.
        swap(a[index], a[i]);

        generatePermutations(
            a,
            index + 1,
            answer
        );

        // Undo the choice.
        swap(a[index], a[i]);
    }
}
```

Complexity:

```text
O(n * n!)
```

if storing every permutation.

---

# 77. Bit Manipulation

Important operators:

```text
&   AND
|   OR
^   XOR
~   NOT
<<  Left Shift
>>  Right Shift
```

---

# 78. Check Odd / Even

```cpp
bool isOdd(int x) {
    // Last bit is 1 for odd numbers.
    return (x & 1);
}
```

---

# 79. Check Power of Two

For positive integer `n`:

```cpp
bool isPowerOfTwo(int n) {

    // A power of two has exactly one set bit.
    return n > 0 && (n & (n - 1)) == 0;
}
```

Examples:

```text
1  -> true
2  -> true
4  -> true
8  -> true
10 -> false
```

---

# 80. Count Set Bits

```cpp
int countSetBits(unsigned int x) {

    int count = 0;

    while (x != 0) {

        // Removes the lowest set bit.
        x &= (x - 1);

        ++count;
    }

    return count;
}
```

STL:

```cpp
int count = __builtin_popcount(x);
```

For `long long`:

```cpp
int count = __builtin_popcountll(x);
```

---

# 81. XOR Properties

Important properties:

```text
x ^ x = 0
x ^ 0 = x
x ^ y = y ^ x
```

Find the single number when every other number appears twice:

```cpp
int singleNumber(const vector<int>& a) {

    int answer = 0;

    for (int x : a) {
        answer ^= x;
    }

    return answer;
}
```

Why it works:

```text
a ^ a = 0
0 ^ b = b
```

---

# 82. String Algorithms

## Reverse String

```cpp
string s = "hello";

reverse(s.begin(), s.end());

cout << s;
// olleh
```

---

## Palindrome

```cpp
bool isPalindrome(const string& s) {

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {

        if (s[left] != s[right]) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}
```

---

# 83. Character Frequency

```cpp
vector<int> frequency(26, 0);

for (char c : s) {

    if ('a' <= c && c <= 'z') {
        ++frequency[c - 'a'];
    }
}
```

---

# 84. Anagram Check

```cpp
bool isAnagram(
    const string& a,
    const string& b
) {
    if (a.size() != b.size()) {
        return false;
    }

    vector<int> freq(256, 0);

    for (char c : a) {
        ++freq[(unsigned char)c];
    }

    for (char c : b) {
        --freq[(unsigned char)c];
    }

    for (int count : freq) {

        if (count != 0) {
            return false;
        }
    }

    return true;
}
```

Complexity:

```text
O(n)
```

---

# 85. KMP String Matching

KMP avoids repeatedly restarting the pattern search.

Build the LPS array:

```cpp
vector<int> buildLPS(
    const string& pattern
) {
    int n = pattern.size();

    vector<int> lps(n, 0);

    int length = 0;

    int i = 1;

    while (i < n) {

        if (pattern[i] == pattern[length]) {

            ++length;

            lps[i] = length;

            ++i;

        } else {

            if (length != 0) {

                // Try the previous possible prefix.
                length = lps[length - 1];

            } else {

                lps[i] = 0;

                ++i;
            }
        }
    }

    return lps;
}
```

Search:

```cpp
int kmpSearch(
    const string& text,
    const string& pattern
) {
    if (pattern.empty()) {
        return 0;
    }

    vector<int> lps = buildLPS(pattern);

    int i = 0;
    int j = 0;

    while (i < (int)text.size()) {

        if (text[i] == pattern[j]) {

            ++i;
            ++j;

            if (j == (int)pattern.size()) {
                return i - j;
            }

        } else {

            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    return -1;
}
```

Complexity:

```text
O(n + m)
```

---

# 86. Monotonic Stack

A monotonic stack maintains elements in increasing or decreasing order.

Useful for:

- Next Greater Element
- Next Smaller Element
- Histogram
- Stock Span
- Largest Rectangle

---

# 87. Next Greater Element

```cpp
vector<int> nextGreaterElement(
    const vector<int>& a
) {
    int n = a.size();

    vector<int> answer(n, -1);

    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {

        // Remove elements that cannot be the answer.
        while (!st.empty() &&
               st.top() <= a[i]) {

            st.pop();
        }

        // Stack top is the next greater element.
        if (!st.empty()) {
            answer[i] = st.top();
        }

        // Current element may be useful
        // for elements to its left.
        st.push(a[i]);
    }

    return answer;
}
```

Complexity:

```text
O(n)
```

Each element is pushed once and popped at most once.

---

# 88. Largest Rectangle in Histogram

```cpp
long long largestRectangle(
    const vector<int>& heights
) {
    int n = heights.size();

    stack<int> st;

    long long answer = 0;

    for (int i = 0; i <= n; ++i) {

        // Use height 0 after the last element
        // to force processing of remaining bars.
        long long currentHeight =
            (i == n ? 0 : heights[i]);

        while (!st.empty() &&
               heights[st.top()] > currentHeight) {

            int height = heights[st.top()];
            st.pop();

            int leftBoundary =
                st.empty() ? -1 : st.top();

            int width =
                i - leftBoundary - 1;

            answer = max(
                answer,
                1LL * height * width
            );
        }

        if (i < n) {
            st.push(i);
        }
    }

    return answer;
}
```

---

# 89. Monotonic Queue

Useful for sliding-window minimum/maximum.

Example: maximum of every window of size `k`.

```cpp
vector<int> slidingWindowMaximum(
    const vector<int>& a,
    int k
) {
    deque<int> dq;

    vector<int> answer;

    for (int i = 0; i < (int)a.size(); ++i) {

        // Remove indices outside current window.
        while (!dq.empty() &&
               dq.front() <= i - k) {

            dq.pop_front();
        }

        // Remove smaller values from the back.
        // They can never become the maximum while
        // a[i] is inside the window.
        while (!dq.empty() &&
               a[dq.back()] <= a[i]) {

            dq.pop_back();
        }

        dq.push_back(i);

        // Window becomes complete at i >= k - 1.
        if (i >= k - 1) {
            answer.push_back(
                a[dq.front()]
            );
        }
    }

    return answer;
}
```

Complexity:

```text
O(n)
```

---

# 90. Interval Algorithms

Given intervals:

```text
[1,3]
[2,6]
[8,10]
[9,12]
```

Merge overlapping intervals.

```cpp
vector<vector<int>> mergeIntervals(
    vector<vector<int>> intervals
) {
    if (intervals.empty()) {
        return {};
    }

    // Sort by starting point.
    sort(
        intervals.begin(),
        intervals.end()
    );

    vector<vector<int>> answer;

    for (const auto& interval : intervals) {

        // If answer is empty OR intervals don't overlap,
        // add a new interval.
        if (
            answer.empty() ||
            answer.back()[1] < interval[0]
        ) {
            answer.push_back(interval);
        } else {

            // Overlapping intervals:
            // extend the end.
            answer.back()[1] =
                max(
                    answer.back()[1],
                    interval[1]
                );
        }
    }

    return answer;
}
```

Complexity:

```text
O(n log n)
```

because of sorting.

---

# 91. Meeting Rooms

Determine whether all meetings can be attended.

```cpp
bool canAttendAll(
    vector<pair<int, int>> meetings
) {
    sort(meetings.begin(), meetings.end());

    for (int i = 1;
         i < (int)meetings.size();
         ++i) {

        // Current meeting starts before
        // previous meeting finishes.
        if (meetings[i].first <
            meetings[i - 1].second) {

            return false;
        }
    }

    return true;
}
```

---

# 92. Coordinate Compression

Useful when values are very large but only relative ordering matters.

Example:

```text
1000000000
5
100
5
```

can become:

```text
2
0
1
0
```

Implementation:

```cpp
vector<int> compress(
    const vector<int>& a
) {
    vector<int> values = a;

    // Get all distinct values in sorted order.
    sort(
        values.begin(),
        values.end()
    );

    values.erase(
        unique(
            values.begin(),
            values.end()
        ),
        values.end()
    );

    vector<int> result;

    for (int x : a) {

        // Position in sorted unique values.
        int index = lower_bound(
            values.begin(),
            values.end(),
            x
        ) - values.begin();

        result.push_back(index);
    }

    return result;
}
```

---

# 93. `unique`

`unique` moves duplicates toward the end and returns a new logical end.

Correct erase pattern:

```cpp
sort(a.begin(), a.end());

a.erase(
    unique(a.begin(), a.end()),
    a.end()
);
```

Now all elements are unique.

---

# 94. `next_permutation`

Generates the next lexicographical permutation.

```cpp
vector<int> a = {1, 2, 3};

sort(a.begin(), a.end());

do {
    for (int x : a) {
        cout << x << ' ';
    }

    cout << '\n';

} while (
    next_permutation(
        a.begin(),
        a.end()
    )
);
```

Output:

```text
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

---

# 95. `prev_permutation`

```cpp
prev_permutation(
    a.begin(),
    a.end()
);
```

Generates the previous lexicographical permutation.

---

# 96. `rotate`

```cpp
vector<int> a = {
    1, 2, 3, 4, 5
};

// Rotate so that index 2 becomes the first element.
rotate(
    a.begin(),
    a.begin() + 2,
    a.end()
);
```

Result:

```text
3 4 5 1 2
```

---

# 97. `partition`

Moves elements satisfying a condition before elements that do not.

```cpp
vector<int> a = {
    1, 4, 3, 6, 2, 8
};

auto it = partition(
    a.begin(),
    a.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

Elements before `it` satisfy the condition.

`partition` does not guarantee their relative order.

---

# 98. `stable_partition`

```cpp
stable_partition(
    a.begin(),
    a.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

Preserves relative order within both groups.

---

# 99. `nth_element`

`nth_element` places the element that would appear at position `k` after sorting into its correct position.

Elements before it are not necessarily sorted, but are not greater than it according to the comparator.

```cpp
vector<int> a = {
    7, 2, 9, 1, 5, 4
};

int k = 2;

nth_element(
    a.begin(),
    a.begin() + k,
    a.end()
);

cout << a[k] << '\n';
```

The element at index `k` is the same value that would occur there in sorted order.

Average complexity:

```text
O(n)
```

Very useful for kth smallest/largest problems.

---

# 100. GCD and LCM

C++17:

```cpp
#include <numeric>

int g = gcd(12, 18);

int l = lcm(12, 18);
```

Result:

```text
gcd = 6
lcm = 36
```

Manual Euclidean algorithm:

```cpp
long long gcdManual(
    long long a,
    long long b
) {
    while (b != 0) {

        long long remainder = a % b;

        a = b;
        b = remainder;
    }

    return a;
}
```

Complexity:

```text
O(log(min(a, b)))
```

---

# 101. Fast Exponentiation

Calculate:

```text
a^b
```

in `O(log b)`.

```cpp
long long power(
    long long a,
    long long b
) {
    long long result = 1;

    while (b > 0) {

        // If the current bit of b is 1,
        // multiply result by current base.
        if (b & 1) {
            result *= a;
        }

        // Square the base.
        a *= a;

        // Divide exponent by 2.
        b >>= 1;
    }

    return result;
}
```

---

# 102. Modular Exponentiation

```cpp
long long modPower(
    long long a,
    long long b,
    long long mod
) {
    long long result = 1 % mod;

    a %= mod;

    while (b > 0) {

        if (b & 1) {
            result =
                (__int128)result * a % mod;
        }

        a =
            (__int128)a * a % mod;

        b >>= 1;
    }

    return result;
}
```

Using `__int128` prevents intermediate multiplication overflow for typical 64-bit modular arithmetic.

---

# 103. Sieve of Eratosthenes

Find all primes up to `n`.

```cpp
vector<bool> sieve(int n) {

    vector<bool> isPrime(
        n + 1,
        true
    );

    if (n >= 0) {
        isPrime[0] = false;
    }

    if (n >= 1) {
        isPrime[1] = false;
    }

    for (int p = 2;
         1LL * p * p <= n;
         ++p) {

        if (!isPrime[p]) {
            continue;
        }

        // Every multiple smaller than p*p
        // has already been marked by a smaller prime.
        for (long long multiple =
                 1LL * p * p;
             multiple <= n;
             multiple += p) {

            isPrime[multiple] = false;
        }
    }

    return isPrime;
}
```

Complexity:

```text
O(n log log n)
```

---

# 104. Prime Factorization

```cpp
vector<pair<long long, int>> primeFactors(
    long long n
) {
    vector<pair<long long, int>> factors;

    for (long long p = 2;
         p * p <= n;
         ++p) {

        if (n % p != 0) {
            continue;
        }

        int count = 0;

        while (n % p == 0) {
            n /= p;
            ++count;
        }

        factors.push_back({
            p,
            count
        });
    }

    // If n > 1, it is itself a prime factor.
    if (n > 1) {
        factors.push_back({
            n,
            1
        });
    }

    return factors;
}
```

---

# 105. Fast Input / Output

For competitive programming:

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

Typical template:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Your code here.

    return 0;
}
```

---

# 106. Useful STL Functions

## Vector / Sequence Algorithms

```cpp
sort(begin, end);
stable_sort(begin, end);

reverse(begin, end);

find(begin, end, value);
find_if(begin, end, predicate);

count(begin, end, value);
count_if(begin, end, predicate);

min_element(begin, end);
max_element(begin, end);

lower_bound(begin, end, value);
upper_bound(begin, end, value);

binary_search(begin, end, value);

unique(begin, end);

remove(begin, end, value);

rotate(begin, middle, end);

partition(begin, end, predicate);

nth_element(begin, nth, end);

next_permutation(begin, end);
prev_permutation(begin, end);
```

---

# 107. Numeric STL Functions

```cpp
accumulate(begin, end, initial);

gcd(a, b);
lcm(a, b);

iota(begin, end, start);
```

Example:

```cpp
vector<int> a(5);

iota(a.begin(), a.end(), 1);
```

Result:

```text
1 2 3 4 5
```

---

# 108. `transform`

Apply a function to every element.

```cpp
vector<int> a = {1, 2, 3, 4};

vector<int> squared(a.size());

transform(
    a.begin(),
    a.end(),
    squared.begin(),
    [](int x) {
        return x * x;
    }
);
```

Result:

```text
1 4 9 16
```

---

# 109. `for_each`

```cpp
for_each(
    a.begin(),
    a.end(),
    [](int x) {
        cout << x << ' ';
    }
);
```

---

# 110. `equal`

Compare ranges:

```cpp
bool same =
    equal(
        a.begin(),
        a.end(),
        b.begin()
    );
```

---

# 111. `lexicographical_compare`

Useful for comparing sequences lexicographically.

```cpp
bool smaller =
    lexicographical_compare(
        a.begin(),
        a.end(),
        b.begin(),
        b.end()
    );
```

---

# 112. Common Problem-Solving Patterns

## Pattern 1: Need membership?

Consider:

```cpp
set
unordered_set
```

Use:

```cpp
unordered_set
```

when ordering is unnecessary and average O(1) lookup is useful.

Use:

```cpp
set
```

when sorted order or ordered operations are required.

---

## Pattern 2: Need frequency?

Use:

```cpp
unordered_map<int, int>
```

or:

```cpp
map<int, int>
```

---

## Pattern 3: Sorted array + search?

Think:

```text
binary_search
lower_bound
upper_bound
two pointers
```

---

## Pattern 4: Contiguous subarray?

Think:

```text
sliding window
prefix sum
two pointers
deque
```

---

## Pattern 5: Next greater/smaller?

Think:

```text
monotonic stack
```

---

## Pattern 6: Shortest path?

Ask:

```text
Unweighted graph?
    -> BFS

Non-negative weighted graph?
    -> Dijkstra

Negative edges?
    -> Bellman-Ford

All pairs?
    -> Floyd-Warshall
```

---

## Pattern 7: Connected components / dynamic connectivity?

Think:

```text
DFS
BFS
DSU
```

---

## Pattern 8: Dependency ordering?

Think:

```text
Topological Sort
```

---

## Pattern 9: Minimum spanning tree?

Think:

```text
Kruskal + DSU
Prim + Priority Queue
```

---

## Pattern 10: Optimization with repeated states?

Think:

```text
Dynamic Programming
```

---

# 113. Important Edge Cases

Always consider:

## Empty input

```cpp
if (a.empty()) {
    // Handle empty input.
}
```

## One element

```text
n = 1
```

## Duplicate values

```text
[2, 2, 2, 2]
```

## Negative numbers

```text
[-5, -2, -10]
```

## Integer overflow

Prefer:

```cpp
long long
```

when values or sums can become large.

For multiplication:

```cpp
1LL * a * b
```

Example:

```cpp
long long product = 1LL * a * b;
```

## Large recursion depth

Recursive DFS/DP may overflow the call stack for very deep inputs.

Consider iterative implementations where appropriate.

---

# 114. Complete Competitive Programming Template

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF =
    numeric_limits<ll>::max() / 4;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n);

    for (ll& x : a) {
        cin >> x;
    }

    // Solve the problem here.

    return 0;
}
```

---

# 115. Graph Template

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {

        int u, v;

        cin >> u >> v;

        // For an undirected graph:
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    return 0;
}
```

---

# 116. Weighted Graph Template

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, ll>>> graph(n);

    for (int i = 0; i < m; ++i) {

        int u, v;
        ll w;

        cin >> u >> v >> w;

        graph[u].push_back({
            v,
            w
        });

        graph[v].push_back({
            u,
            w
        });
    }

    return 0;
}
```

---

# 117. BFS Grid Template

Very common for matrix/grid problems.

```cpp
int n, m;

vector<string> grid(n);

vector<vector<int>> dist(
    n,
    vector<int>(m, -1)
);

queue<pair<int, int>> q;

// Four directions:
// up, down, left, right.
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

q.push({startRow, startCol});

dist[startRow][startCol] = 0;

while (!q.empty()) {

    auto [r, c] = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d) {

        int nr = r + dr[d];
        int nc = c + dc[d];

        // Check boundaries.
        if (nr < 0 ||
            nr >= n ||
            nc < 0 ||
            nc >= m) {
            continue;
        }

        // Skip blocked cells.
        if (grid[nr][nc] == '#') {
            continue;
        }

        // Already visited.
        if (dist[nr][nc] != -1) {
            continue;
        }

        dist[nr][nc] =
            dist[r][c] + 1;

        q.push({nr, nc});
    }
}
```

---

# 118. DFS Grid Template

```cpp
void dfs(
    int r,
    int c,
    vector<string>& grid
) {
    int n = grid.size();
    int m = grid[0].size();

    // Out of bounds.
    if (r < 0 ||
        r >= n ||
        c < 0 ||
        c >= m) {
        return;
    }

    // Blocked or already visited.
    if (grid[r][c] != '1') {
        return;
    }

    // Mark visited.
    grid[r][c] = '0';

    dfs(r + 1, c, grid);
    dfs(r - 1, c, grid);
    dfs(r, c + 1, grid);
    dfs(r, c - 1, grid);
}
```

---

# 119. Binary Search Template — First True

This is one of the most useful generic templates.

Suppose:

```text
false false false true true true
```

We want the first `true`.

```cpp
long long firstTrue(
    long long low,
    long long high
) {
    long long answer = high;

    while (low <= high) {

        long long mid =
            low + (high - low) / 2;

        if (check(mid)) {

            // mid works.
            // Search for an earlier working value.
            answer = mid;
            high = mid - 1;

        } else {

            // mid does not work.
            low = mid + 1;
        }
    }

    return answer;
}
```

---

# 120. Binary Search Template — Last True

For:

```text
true true true false false
```

find the last `true`.

```cpp
long long lastTrue(
    long long low,
    long long high
) {
    long long answer = low - 1;

    while (low <= high) {

        long long mid =
            low + (high - low) / 2;

        if (check(mid)) {

            answer = mid;

            // Try a larger value.
            low = mid + 1;

        } else {

            // mid is too large.
            high = mid - 1;
        }
    }

    return answer;
}
```

---

# 121. Prefix Sum 2D

Useful for matrix rectangle-sum queries.

Build:

```cpp
vector<vector<long long>> prefix(
    n + 1,
    vector<long long>(m + 1, 0)
);

for (int i = 1; i <= n; ++i) {

    for (int j = 1; j <= m; ++j) {

        prefix[i][j] =
            a[i - 1][j - 1]
            + prefix[i - 1][j]
            + prefix[i][j - 1]
            - prefix[i - 1][j - 1];
    }
}
```

Rectangle sum from `(r1,c1)` to `(r2,c2)`:

```cpp
long long rectangleSum(
    const vector<vector<long long>>& prefix,
    int r1,
    int c1,
    int r2,
    int c2
) {
    ++r1;
    ++c1;
    ++r2;
    ++c2;

    return
        prefix[r2][c2]
        - prefix[r1 - 1][c2]
        - prefix[r2][c1 - 1]
        + prefix[r1 - 1][c1 - 1];
}
```

---

# 122. Kadane's Algorithm

Find maximum subarray sum.

```cpp
long long maxSubarraySum(
    const vector<long long>& a
) {
    long long current = a[0];

    long long answer = a[0];

    for (int i = 1;
         i < (int)a.size();
         ++i) {

        // Either extend the previous subarray
        // or start a new subarray at i.
        current = max(
            a[i],
            current + a[i]
        );

        answer = max(
            answer,
            current
        );
    }

    return answer;
}
```

Complexity:

```text
O(n)
```

Works even when all numbers are negative.

---

# 123. Maximum Subarray with Empty Subarray Allowed

If the problem allows choosing no elements:

```cpp
long long maxSubarraySumEmptyAllowed(
    const vector<long long>& a
) {
    long long current = 0;
    long long answer = 0;

    for (long long x : a) {

        current = max(
            0LL,
            current + x
        );

        answer = max(
            answer,
            current
        );
    }

    return answer;
}
```

---

# 124. Dutch National Flag Algorithm

Sort an array containing only:

```text
0, 1, 2
```

in linear time.

```cpp
void sort012(vector<int>& a) {

    int low = 0;
    int mid = 0;
    int high = a.size() - 1;

    while (mid <= high) {

        if (a[mid] == 0) {

            // Put zero into the low region.
            swap(a[low], a[mid]);

            ++low;
            ++mid;

        } else if (a[mid] == 1) {

            // 1 belongs in the middle.
            ++mid;

        } else {

            // Put 2 into the high region.
            swap(a[mid], a[high]);

            --high;

            // Do not increment mid yet.
            // The swapped element must be examined.
        }
    }
}
```

Complexity:

```text
Time: O(n)
Space: O(1)
```

---

# 125. Boyer-Moore Majority Vote

Find an element occurring more than `n/2` times.

```cpp
int majorityElement(
    const vector<int>& a
) {
    int candidate = 0;
    int count = 0;

    for (int x : a) {

        if (count == 0) {
            candidate = x;
        }

        if (x == candidate) {
            ++count;
        } else {
            --count;
        }
    }

    return candidate;
}
```

If the problem does **not guarantee** that a majority exists, verify the candidate afterward.

---

# 126. Reservoir-Style Basic Random Selection Note

For randomized algorithms, avoid relying on `rand()` for high-quality randomness.

Modern C++:

```cpp
#include <random>

mt19937 rng(
    chrono::steady_clock::now()
        .time_since_epoch()
        .count()
);

int randomIndex =
    uniform_int_distribution<int>(
        0,
        n - 1
    )(rng);
```

---

# 127. `map` vs `unordered_map`

## `map`

```cpp
map<int, int> mp;
```

Properties:

```text
Sorted keys
O(log n) operations
Predictable ordering
Usually implemented as balanced tree
```

## `unordered_map`

```cpp
unordered_map<int, int> mp;
```

Properties:

```text
No sorted order
Average O(1)
Hash table
Worst-case O(n)
```

Use `map` when ordering matters.

Use `unordered_map` when fast average lookup matters and ordering is unnecessary.

---

# 128. `set` vs `unordered_set`

```text
set:
    unique
    sorted
    O(log n)

unordered_set:
    unique
    unordered
    average O(1)
```

---

# 129. `vector` vs `deque`

`vector`:

```text
Contiguous memory
Fast random access
Excellent cache locality
Fast push_back
```

`deque`:

```text
Fast insertion/removal at both ends
Random access available
Not necessarily contiguous
```

For most normal arrays, prefer:

```cpp
vector
```

---

# 130. `stack` vs `queue`

Stack:

```text
LIFO
push
pop
top
```

Queue:

```text
FIFO
push
pop
front
```

---

# 131. Common Mistakes

## Mistake 1: Using `lower_bound` on unsorted data

Wrong:

```cpp
vector<int> a = {5, 1, 3, 2};

lower_bound(a.begin(), a.end(), 3);
```

Correct:

```cpp
sort(a.begin(), a.end());

lower_bound(
    a.begin(),
    a.end(),
    3
);
```

---

## Mistake 2: Integer Overflow

Potentially dangerous:

```cpp
int product = a * b;
```

Safer:

```cpp
long long product =
    1LL * a * b;
```

---

## Mistake 3: Erasing While Iterating Incorrectly

Use iterator-returning erase carefully:

```cpp
for (auto it = s.begin();
     it != s.end();) {

    if (*it % 2 == 0) {
        it = s.erase(it);
    } else {
        ++it;
    }
}
```

---

# 132. Complexity Cheat Sheet

| Algorithm / Operation         |            Time |
| ----------------------------- | --------------: |
| Vector access                 |            O(1) |
| Vector `push_back`            |  O(1) amortized |
| Vector insert front           |            O(n) |
| Linear Search                 |            O(n) |
| Binary Search                 |        O(log n) |
| `set::find`                   |        O(log n) |
| `map::find`                   |        O(log n) |
| `unordered_map::find` average |            O(1) |
| Bubble Sort                   |           O(n²) |
| Selection Sort                |           O(n²) |
| Insertion Sort                |           O(n²) |
| Merge Sort                    |      O(n log n) |
| Quick Sort average            |      O(n log n) |
| `std::sort`                   |      O(n log n) |
| Heap push                     |        O(log n) |
| Heap pop                      |        O(log n) |
| Heap top                      |            O(1) |
| BFS                           |        O(V + E) |
| DFS                           |        O(V + E) |
| Dijkstra                      |  O((V+E) log V) |
| Bellman-Ford                  |           O(VE) |
| Floyd-Warshall                |           O(V³) |
| Kruskal                       |      O(E log E) |
| Prim with heap                |      O(E log V) |
| DSU operation                 | ~O(1) amortized |
| Prefix Sum build              |            O(n) |
| Prefix Sum query              |            O(1) |
| Sliding Window                |            O(n) |
| Two Pointers                  |            O(n) |
| Kadane                        |            O(n) |
| LIS                           |      O(n log n) |
| KMP                           |        O(n + m) |
| Sieve                         |  O(n log log n) |

---

# 133. Algorithm Selection Cheat Sheet

When you see:

```text
Sorted array
```

Think:

```text
Binary Search
Two Pointers
Lower Bound
Upper Bound
```

When you see:

```text
Subarray / substring
```

Think:

```text
Sliding Window
Prefix Sum
Two Pointers
Kadane
Monotonic Queue
```

When you see:

```text
Next greater/smaller
```

Think:

```text
Monotonic Stack
```

When you see:

```text
Shortest path
```

Think:

```text
BFS
Dijkstra
Bellman-Ford
Floyd-Warshall
```

When you see:

```text
Dependencies
```

Think:

```text
Topological Sort
```

When you see:

```text
Connectivity
```

Think:

```text
DFS
BFS
DSU
```

When you see:

```text
Minimum connection cost
```

Think:

```text
MST
Kruskal
Prim
```

When you see:

```text
Repeated states / choices
```

Think:

```text
Dynamic Programming
```

When you see:

```text
Try all possibilities + undo
```

Think:

```text
Backtracking
```

When you see:

```text
Huge answer range + yes/no feasibility
```

Think:

```text
Binary Search on Answer
```

---

# 134. Final Problem-Solving Checklist

Before coding, ask:

## Step 1 — Understand the input

- What is `n`?
- What are the value limits?
- Is the input sorted?
- Are duplicates possible?
- Can values be negative?
- Can the answer exceed `int`?

## Step 2 — Identify the structure

Is it:

```text
Array?
String?
Linked List?
Tree?
Graph?
Grid?
Intervals?
```

## Step 3 — Identify the pattern

Try:

```text
Brute force
Hashing
Sorting
Two pointers
Sliding window
Prefix sum
Binary search
Stack
Queue
Heap
Greedy
DP
Graph traversal
DSU
Backtracking
```

## Step 4 — Estimate complexity

If:

```text
n <= 20
```

exponential algorithms may be possible.

If:

```text
n <= 100
```

`O(n³)` may sometimes work.

If:

```text
n <= 1000
```

`O(n²)` is often reasonable.

If:

```text
n <= 100000
```

usually target:

```text
O(n log n)
```

or:

```text
O(n)
```

If:

```text
n >= 1000000
```

prefer very efficient `O(n)` or near-linear solutions.

These are only rough guidelines; always use the actual time limits and operation costs.

---

# 135. Master C++ Template

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF =
    numeric_limits<ll>::max() / 4;

void solve() {

    // Read input.
    int n;
    cin >> n;

    vector<ll> a(n);

    for (ll& x : a) {
        cin >> x;
    }

    // --------------------------------------------------
    // Write your algorithm here.
    // --------------------------------------------------

    // Example:
    sort(a.begin(), a.end());

    for (ll x : a) {
        cout << x << ' ';
    }

    cout << '\n';
}

int main() {

    // Fast I/O.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = 1;

    // Uncomment if the problem contains T test cases.
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
```

---

# 136. Final Summary

The most important C++ algorithms and STL concepts to master are:

```text
1. Complexity Analysis
2. Vector
3. Set / Multiset
4. Map / Unordered Map
5. Stack
6. Queue / Deque
7. Priority Queue
8. Sorting
9. Binary Search
10. Lower Bound / Upper Bound
11. Two Pointers
12. Sliding Window
13. Prefix Sum
14. Difference Array
15. Hashing
16. Linked List
17. Tree Traversals
18. BST
19. Heap
20. BFS
21. DFS
22. Cycle Detection
23. Topological Sort
24. Dijkstra
25. Bellman-Ford
26. Floyd-Warshall
27. Kruskal
28. Prim
29. DSU
30. Dynamic Programming
31. Greedy
32. Backtracking
33. Bit Manipulation
34. String Algorithms
35. Monotonic Stack
36. Monotonic Queue
37. Interval Problems
38. Coordinate Compression
39. Prefix Sum 2D
40. Binary Search on Answer
```

The most important skill is not memorizing implementations. The goal is to recognize **which pattern fits the problem**, prove why it works, and then implement it with the appropriate STL data structure or algorithm.

---

# End of `algorithms.md`
