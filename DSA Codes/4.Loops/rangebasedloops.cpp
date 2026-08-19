#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // ============================================================
    // RANGE-BASED FOR LOOP
    // ============================================================
    //
    // A range-based for loop is used to traverse / iterate
    // through every element of a container or collection.
    //
    // Commonly used with:
    //
    // 1. Arrays
    // 2. Vectors
    // 3. Strings
    // 4. Sets
    // 5. Maps
    // 6. Other STL containers
    //
    // Instead of manually working with indexes or iterators,
    // a range-based for loop directly gives us each element.
    //
    // It was introduced in C++11.
    //
    // ------------------------------------------------------------
    // BASIC SYNTAX
    // ------------------------------------------------------------
    //
    // for (dataType variable : container)
    // {
    //     // code
    // }
    //
    // OR commonly:
    //
    // for (auto variable : container)
    // {
    //     // code
    // }
    //
    // ------------------------------------------------------------
    // Example:
    //
    // vector<int> vec = {10, 20, 30, 40};
    //
    // for (int x : vec)
    // {
    //     cout << x << " ";
    // }
    //
    // Output:
    //
    // 10 20 30 40
    //
    // Here:
    //
    // x becomes:
    //
    // 1st iteration -> 10
    // 2nd iteration -> 20
    // 3rd iteration -> 30
    // 4th iteration -> 40

    // ============================================================
    // EXAMPLE 1: BASIC RANGE-BASED FOR LOOP
    // ============================================================

    vector<int> vec = {10, 20, 30, 40, 50};

    // int x means:
    //
    // "For every element of vec, store that element
    //  temporarily in x."
    //
    // : vec means:
    //
    // "Take elements from vec one by one."
    for (int x : vec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // HOW THE LOOP WORKS
    // ============================================================

    // For:
    //
    // vector<int> vec = {10, 20, 30};
    //
    // this:
    //
    // for (int x : vec)
    // {
    //     cout << x;
    // }
    //
    // conceptually behaves like:
    //
    // x = 10 -> print
    // x = 20 -> print
    // x = 30 -> print
    //
    // So output:
    //
    // 10 20 30

    // ============================================================
    // EXAMPLE 2: USING auto
    // ============================================================

    // Instead of writing:
    //
    // for (int x : vec)
    //
    // we can write:
    //
    // for (auto x : vec)
    //
    // auto automatically determines the type of x.
    //
    // Since vec is vector<int>,
    // x will automatically become int.

    for (auto x : vec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // EXAMPLE 3: RANGE-BASED LOOP WITH ARRAY
    // ============================================================

    int arr[] = {1, 2, 3, 4, 5};

    // Range-based loops are NOT limited to vectors.
    // They also work with normal arrays.

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // EXAMPLE 4: RANGE-BASED LOOP WITH STRING
    // ============================================================

    string name = "RAHUL";

    // A string is a sequence of characters.
    //
    // So the loop will visit:
    //
    // R
    // A
    // H
    // U
    // L
    //
    // one by one.

    for (char ch : name)
    {
        cout << ch << " ";
    }

    cout << endl;

    // ============================================================
    // IMPORTANT: COPY VS REFERENCE
    // ============================================================
    //
    // This is VERY important in range-based loops.
    //
    // There are mainly three common forms:
    //
    // 1. for (auto x : vec)
    // 2. for (auto& x : vec)
    // 3. for (const auto& x : vec)
    //
    // Their behavior is different.

    // ============================================================
    // 1. for (auto x : vec)
    // ============================================================

    // Here x is a COPY of each element.
    //
    // Suppose:
    //
    // vec = [10, 20, 30]
    //
    // Iteration 1:
    //
    // x = copy of 10
    //
    // Iteration 2:
    //
    // x = copy of 20
    //
    // Iteration 3:
    //
    // x = copy of 30
    //
    // If we modify x, the original vector DOES NOT change.

    for (auto x : vec)
    {
        x = x + 100;
    }

    // Original vector is still:
    //
    // [10, 20, 30, 40, 50]
    //
    // because x was only a copy.

    // ============================================================
    // 2. for (auto& x : vec)
    // ============================================================

    // & means REFERENCE.
    //
    // Here x is NOT a copy.
    //
    // x becomes another name / reference to the actual
    // element inside the vector.
    //
    // Therefore, if we modify x,
    // the original vector WILL change.

    for (auto &x : vec)
    {
        x = x + 10;
    }

    // Original vector changes:
    //
    // Before:
    //
    // [10, 20, 30, 40, 50]
    //
    // After:
    //
    // [20, 30, 40, 50, 60]

    // Printing the modified vector.
    for (auto x : vec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 3. for (const auto& x : vec)
    // ============================================================

    // const means:
    //
    // "Do not allow modification of the referenced element."
    //
    // & means:
    //
    // "Do not make a copy; directly refer to the original."
    //
    // So:
    //
    // const auto& x
    //
    // = read-only reference to the original element.
    //
    // This is very useful when:
    //
    // - elements are large objects
    // - we only want to read them
    // - we want to avoid unnecessary copies

    for (const auto &x : vec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // WHY use const auto& ?
    // ============================================================

    // Suppose we have:
    //
    // vector<string> names = {"Rahul", "Aman", "Priya"};
    //
    // Strings can be relatively large compared to integers.
    //
    // If we write:
    //
    // for (auto name : names)
    //
    // every string is copied.
    //
    // Better:
    //
    // for (const auto& name : names)
    //
    // No unnecessary copy is made.
    //
    // And because of const, we cannot accidentally modify
    // the original strings.

    // ============================================================
    // EXAMPLE 5: const auto&
    // ============================================================

    vector<string> names = {
        "Rahul",
        "Aman",
        "Priya"};

    for (const auto &name : names)
    {
        cout << name << endl;
    }

    // ============================================================
    // EXAMPLE 6: MODIFYING VECTOR USING auto&
    // ============================================================

    vector<int> numbers = {1, 2, 3, 4, 5};

    // Because x is a reference,
    // changes made to x affect the actual vector.

    for (auto &x : numbers)
    {
        x = x * 2;
    }

    // numbers becomes:
    //
    // [2, 4, 6, 8, 10]

    for (const auto &x : numbers)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // EXAMPLE 7: PRINTING ONLY
    // ============================================================

    // If we only need to print integer values,
    // all of these are possible:
    //
    // for (int x : numbers)
    // for (auto x : numbers)
    // for (const auto& x : numbers)
    //
    // For int, copying is cheap, so:
    //
    // for (int x : numbers)
    //
    // is perfectly fine.

    // ============================================================
    // EXAMPLE 8: RANGE-BASED LOOP WITH 2D VECTOR
    // ============================================================

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // matrix contains vectors as its elements.
    //
    // First loop:
    //
    // row = {1,2,3}
    // row = {4,5,6}
    // row = {7,8,9}
    //
    // Second loop goes through each value inside the row.

    for (const auto &row : matrix)
    {
        for (const auto &x : row)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    // ============================================================
    // EXAMPLE 9: MODIFYING 2D VECTOR
    // ============================================================

    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}};

    // auto& is important here because we want
    // to modify the original matrix.

    for (auto &row : mat)
    {
        for (auto &x : row)
        {
            x *= 10;
        }
    }

    // Matrix becomes:
    //
    // [10, 20]
    // [30, 40]

    for (const auto &row : mat)
    {
        for (const auto &x : row)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    // ============================================================
    // EXAMPLE 10: char ARRAY
    // ============================================================

    char letters[] = {'A', 'B', 'C', 'D'};

    for (char ch : letters)
    {
        cout << ch << " ";
    }

    cout << endl;

    // ============================================================
    // EXAMPLE 11: STRING MODIFICATION
    // ============================================================

    string word = "hello";

    // Using char& gives us access to the actual characters
    // inside the string.
    //
    // Therefore, we can modify the string directly.

    for (char &ch : word)
    {
        ch = toupper(ch);
    }

    cout << word << endl;

    // Output:
    //
    // HELLO

    // ============================================================
    // RANGE-BASED FOR LOOP vs NORMAL FOR LOOP
    // ============================================================

    vector<int> v = {10, 20, 30, 40};

    // ------------------------------------------------------------
    // NORMAL FOR LOOP
    // ------------------------------------------------------------

    // In a normal loop we commonly use an index.

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;

    // ------------------------------------------------------------
    // RANGE-BASED FOR LOOP
    // ------------------------------------------------------------

    // We don't need an index.
    // The loop directly gives each element.

    for (int x : v)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ADVANTAGE OF RANGE-BASED LOOP
    // ============================================================

    // It is:
    //
    // - cleaner
    // - shorter
    // - easier to read
    // - useful when index is NOT needed
    //
    // Example:
    //
    // Normal:
    //
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i];
    // }
    //
    // Range-based:
    //
    // for (int x : v)
    // {
    //     cout << x;
    // }

    // ============================================================
    // WHEN RANGE-BASED LOOP IS NOT ENOUGH
    // ============================================================

    // Sometimes we need the INDEX.
    //
    // Example:
    //
    // "Print index and value together."
    //
    // A basic range-based loop does not directly give the index.

    for (int i = 0; i < v.size(); i++)
    {
        cout << "Index = " << i
             << ", Value = " << v[i] << endl;
    }

    // ============================================================
    // IMPORTANT SYNTAX
    // ============================================================

    // General syntax:
    //
    // for (declaration : range)
    // {
    //     statements;
    // }
    //
    //
    // Example:
    //
    // for (int x : vec)
    // {
    //     cout << x;
    // }
    //
    // Here:
    //
    // int  -> type
    // x    -> loop variable
    // :    -> means "from / in"
    // vec  -> container

    // ============================================================
    // DIFFERENT FORMS
    // ============================================================

    // 1. Copy
    //
    // for (auto x : vec)
    //
    // x is a copy.
    // Changes to x do not affect vec.

    // 2. Reference
    //
    // for (auto& x : vec)
    //
    // x refers to the actual element.
    // Changes to x DO affect vec.

    // 3. Const reference
    //
    // for (const auto& x : vec)
    //
    // x refers to the actual element.
    // But x cannot be modified.
    //
    // Very useful for reading large objects without copying.

    // ============================================================
    // COMMON MISTAKE
    // ============================================================

    // This:
    //
    // for (auto x : vec)
    // {
    //     x = 100;
    // }
    //
    // does NOT change vec,
    // because x is only a COPY.
    //
    // Correct way to modify:
    //
    // for (auto& x : vec)
    // {
    //     x = 100;
    // }

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    // ------------------------------------------------------------
    // READ / PRINT
    // ------------------------------------------------------------
    //
    // for (auto x : vec)
    // {
    //     cout << x;
    // }
    //
    // Good for simple values like int.

    // ------------------------------------------------------------
    // MODIFY
    // ------------------------------------------------------------
    //
    // for (auto& x : vec)
    // {
    //     x = x + 1;
    // }
    //
    // Changes original vector.

    // ------------------------------------------------------------
    // READ WITHOUT COPY
    // ------------------------------------------------------------
    //
    // for (const auto& x : vec)
    // {
    //     cout << x;
    // }
    //
    // Best general choice when elements are large and
    // we only need to read them.

    return 0;
}