# PATTERN 01 : TWO POINTER APPROACH (COMPLETE THEORY)

================================================================================
TWO POINTER TECHNIQUE
=====================

# WHAT IS TWO POINTER APPROACH?

The Two Pointer Technique is a very important DSA pattern where we use
two variables (called pointers or indices) to traverse a data structure,
usually an array or string.

Instead of using nested loops and checking every possible pair/subarray,
we intelligently move two pointers to reduce time complexity.

Most brute-force solutions work in O(N²),
while two pointers often optimize them to O(N).

---

# BASIC IDEA

---

We maintain two pointers:

```
left pointer
right pointer
```

These pointers move according to some condition.

The movement depends on:

- sum comparison
- duplicates
- window size
- sorting
- character frequency
- partition logic
- etc.

The main goal is:
Avoid unnecessary computations.

---

# WHY TWO POINTERS WORKS?

---

The technique works because:

1. We process elements in a structured manner.
2. Each pointer usually moves only forward.
3. No element is revisited unnecessarily.
4. We use properties like:
   - sorted order
   - contiguous subarrays
   - monotonic behavior
   - shrinking/expanding windows

This reduces repeated work.

---

# WHEN SHOULD YOU THINK OF TWO POINTERS?

---

Think of two pointers when:

✓ Array/String problems
✓ Pair finding problems
✓ Sorted arrays
✓ Subarrays/Substrings
✓ Palindrome checking
✓ Reversing
✓ Merging arrays
✓ Window problems
✓ Removing duplicates
✓ Partitioning problems
✓ Problems asking:

- longest
- shortest
- continuous
- contiguous

---

# COMMON TIME COMPLEXITY

---

Usually:

```
O(N)
```

Why?

Because each pointer moves at most N times.

Even if there are nested while loops,
total pointer movement is still linear.

Example:

```
left moves N times
right moves N times
```

Total = 2N = O(N)

---

# CORE TYPES OF TWO POINTER PATTERNS

---

There are many forms of two pointers.

The most important ones are:

1. Opposite Direction Pointers
2. Sliding Window
3. Fast and Slow Pointer
4. Same Direction Expand-Shrink
5. Partitioning Pointers
6. Merge Style Pointers
7. Multiple Pointer Variations

================================================================================
PATTERN TYPE 1 : OPPOSITE DIRECTION TWO POINTERS
================================================

# THEORY

One pointer starts from beginning.
Another starts from end.

They move toward each other.

Visual:

```
left ---> <--- right
```

---

# WHEN USED?

---

✓ Sorted arrays
✓ Pair sum problems
✓ Palindrome checking
✓ Container problems
✓ Trapping logic
✓ Reverse operations

---

# MAIN IDEA

---

We use array ordering or symmetry.

Instead of checking all pairs,
we intelligently eliminate impossible cases.

---

# HOW MOVEMENT WORKS

---

Suppose target sum problem:

If current sum is too small:
move left forward

If current sum is too large:
move right backward

Because array is sorted.

---

# IMPORTANT PROPERTY

---

Movement eliminates many possibilities at once.

That is why complexity becomes O(N).

---

# COMMON PROBLEMS

---

✓ Two Sum Sorted
✓ Valid Palindrome
✓ Container With Most Water
✓ 3 Sum
✓ 4 Sum
✓ Remove Duplicates
✓ Reverse String

================================================================================
PATTERN TYPE 2 : SLIDING WINDOW (MOST IMPORTANT)
================================================

# THEORY

Sliding Window is actually a special form of two pointers.

We maintain a window:

```
[left ........ right]
```

The window represents:
a subarray
or substring

---

# MAIN IDEA

---

Instead of generating all subarrays,
we dynamically grow and shrink one window.

---

# TYPES OF SLIDING WINDOW

---

1. Fixed Size Window
2. Variable Size Window

================================================================================
A) FIXED SIZE WINDOW
====================

# THEORY

Window size remains constant.

Example size:

```
K = 3
```

Window moves like:

```
[1 2 3]
  [2 3 4]
    [3 4 5]
```

---

# WHEN USED?

---

✓ Maximum sum of size K
✓ First negative in every window
✓ Average of window
✓ Fixed-length substring problems

---

# MOVEMENT

---

Add right element.
Remove left element.
Slide window.

================================================================================
B) VARIABLE SIZE WINDOW
=======================

# THEORY

Window size changes dynamically.

Window expands and shrinks according to condition.

---

# MAIN IDEA

---

Expand window:
right++

Shrink window:
left++

---

# MOST IMPORTANT CONCEPT

---

The window must maintain validity.

If condition breaks:
shrink from left.

---

# USED FOR

---

✓ Longest substring without repeating
✓ Smallest subarray with sum >= K
✓ Fruit into baskets
✓ Minimum window substring
✓ Longest repeating character replacement

---

# VISUAL

---

Expand:
[ l ........ r ]

Invalid?
Shrink from left:

```
   l++
```

---

# GOLDEN RULE

---

Each element enters window once.
Each element exits window once.

Therefore:

```
O(N)
```

================================================================================
PATTERN TYPE 3 : FAST AND SLOW POINTER
======================================

# THEORY

Two pointers move at different speeds.

Usually:

```
slow -> 1 step
fast -> 2 steps
```

---

# MOSTLY USED IN

---

✓ Linked Lists
✓ Cycle detection
✓ Middle node
✓ Happy number
✓ Circular structures

---

# FAMOUS ALGORITHM

---

Floyd Cycle Detection Algorithm

Also called:

```
Tortoise and Hare Algorithm
```

---

# WHY IT WORKS

---

If there is a cycle:

Fast pointer eventually catches slow pointer.

Because fast moves faster inside loop.

---

# IMPORTANT APPLICATIONS

---

1. Detect cycle
2. Find middle node
3. Find cycle start
4. Check palindrome linked list

---

# MIDDLE NODE LOGIC

---

When fast reaches end,
slow reaches middle.

Very important interview concept.

================================================================================
PATTERN TYPE 4 : SAME DIRECTION POINTERS
========================================

# THEORY

Both pointers move in same direction.

Usually:

```
left <= right
```

Both expand forward.

---

# USED IN

---

✓ Sliding window
✓ Duplicate removal
✓ Array compression
✓ Longest unique substring

---

# IMPORTANT IDEA

---

Pointers do NOT move backward.

This gives linear complexity.

================================================================================
PATTERN TYPE 5 : PARTITIONING POINTERS
======================================

# THEORY

Pointers divide array into sections.

Used heavily in sorting algorithms.

---

# MOST IMPORTANT USES

---

✓ Quick Sort Partition
✓ Dutch National Flag
✓ Segregation problems
✓ Positive-negative separation

---

# DUTCH NATIONAL FLAG

---

Uses:

```
low
mid
high
```

Partitions array into regions.

Very famous interview problem.

---

# PARTITION VISUAL

---

```
[0s][1s][unknown][2s]
```

Pointers maintain boundaries.

================================================================================
PATTERN TYPE 6 : MERGE STYLE POINTERS
=====================================

# THEORY

Used when processing multiple sorted arrays/lists.

---

# MAIN IDEA

---

Compare current elements from both arrays.

Move smaller one.

---

# USED IN

---

✓ Merge Sorted Arrays
✓ Merge Sort
✓ Interval problems
✓ Union/Intersection arrays

---

# WHY EFFICIENT?

---

Each element processed once.

Complexity:

```
O(N + M)
```

================================================================================
PATTERN TYPE 7 : MULTI POINTER TECHNIQUES
=========================================

# THEORY

Sometimes more than 2 pointers are used.

Examples:

```
i
j
k
```

---

# COMMON PROBLEMS

---

✓ 3 Sum
✓ 4 Sum
✓ Dutch National Flag
✓ Matrix traversal

---

# IMPORTANT IDEA

---

Still based on pointer movement optimization.

================================================================================
HOW TO IDENTIFY TWO POINTER PROBLEMS
====================================

# SIGNAL WORDS

If problem contains:

✓ pair
✓ subarray
✓ substring
✓ contiguous
✓ longest
✓ shortest
✓ sorted array
✓ palindrome
✓ remove duplicates
✓ merge
✓ partition

Then think about two pointers.

================================================================================
IMPORTANT OBSERVATIONS
======================

# OBSERVATION 1

Sorted arrays are strongest candidates.

---

# OBSERVATION 2

If nested loops are checking ranges,
two pointers may optimize it.

---

# OBSERVATION 3

Contiguous problems often use sliding window.

---

# OBSERVATION 4

Linked list cycle problems often use fast-slow pointers.

================================================================================
ADVANTAGES OF TWO POINTERS
==========================

✓ Reduces time complexity
✓ Avoids nested loops
✓ Elegant solutions
✓ Interview favorite
✓ Memory efficient
✓ Usually O(1) extra space

================================================================================
LIMITATIONS
===========

✗ Not every problem supports pointer movement
✗ Sometimes sorting is required
✗ Window conditions can become tricky
✗ Hard to debug initially

================================================================================
MOST IMPORTANT INTERVIEW INSIGHT
================================

# KEY PRINCIPLE

Pointer movement must be meaningful.

Never move randomly.

Every movement should eliminate possibilities
or maintain validity.

That is the entire philosophy of two pointers.

================================================================================
VERY IMPORTANT SLIDING WINDOW THEORY
====================================

# EXPAND-SHRINK PRINCIPLE

STEP 1:
Expand right pointer.

STEP 2:
Check validity.

STEP 3:
If invalid:
shrink from left.

STEP 4:
Update answer.

This pattern appears everywhere.

================================================================================
COMMON MISTAKES
===============

1. Forgetting window validity
2. Infinite loops
3. Moving wrong pointer
4. Missing duplicate handling
5. Incorrect shrink condition
6. Off-by-one errors
7. Updating answer at wrong time

================================================================================
MENTAL FRAMEWORK FOR SOLVING
============================

Ask these questions:

1. Is array sorted?
   -> Opposite pointers

2. Is it contiguous?
   -> Sliding window

3. Need longest/shortest subarray?
   -> Variable window

4. Linked list cycle?
   -> Fast-slow

5. Merge/compare arrays?
   -> Merge pointers

6. Partitioning?
   -> Multi pointers

================================================================================
MASTER TEMPLATE : OPPOSITE DIRECTION
====================================

while(left < right)
{
if(condition satisfied)
{
// answer found
}
else if(condition too small)
{
left++;
}
else
{
right--;
}
}

================================================================================
MASTER TEMPLATE : SLIDING WINDOW
================================

while(right < n)
{
// include right element

```
while(window invalid)
{
    // remove left element
    left++;
}

// update answer

right++;
```

}

================================================================================
MASTER TEMPLATE : FAST-SLOW POINTER
===================================

while(fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
}

================================================================================
HOW TO MASTER TWO POINTERS
==========================

Practice in this order:

## LEVEL 1

✓ Reverse array
✓ Palindrome
✓ Pair sum sorted

## LEVEL 2

✓ Remove duplicates
✓ Container with water
✓ Merge arrays

## LEVEL 3

✓ Sliding window fixed
✓ Sliding window variable

## LEVEL 4

✓ Minimum window substring
✓ 3 Sum
✓ Trapping rain water

## LEVEL 5

✓ Advanced partitioning
✓ Complex window constraints

================================================================================
FINAL SUMMARY
=============

Two Pointer Technique is one of the most powerful optimization patterns in DSA.

Core philosophy:

```
Move intelligently instead of checking everything.
```

Main categories:

1. Opposite Direction
2. Sliding Window
3. Fast-Slow Pointer
4. Same Direction
5. Partitioning
6. Merge Style
7. Multi Pointer

Most important benefits:

✓ O(N) optimization
✓ Cleaner logic
✓ Very common in interviews
✓ Works on arrays, strings, linked lists

Golden Interview Rule:

```
Whenever nested loops process ranges/pairs,
ask yourself:

"Can two pointers optimize this?"
```

================================================================================
END OF PATTERN 01 : TWO POINTER APPROACH
========================================
