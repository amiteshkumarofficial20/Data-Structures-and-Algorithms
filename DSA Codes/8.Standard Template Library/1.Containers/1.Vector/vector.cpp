#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ============================================================
    // CREATION OF VECTOR
    // ============================================================

    // Creates a vector of size 10.
    // Every element is initialized with the value 8.
    //
    // So the vector initially looks like:
    //
    // [8, 8, 8, 8, 8, 8, 8, 8, 8, 8]
    //
    // size     = 10
    // capacity >= 10
    vector<int> vec(10, 8);

    // Other examples of vector creation:

    // Creates a vector of size 10.
    // Elements of type int are value-initialized to 0.
    // vector<int> miles(10);

    // Creates a vector of size 15.
    // Every element contains 0.
    // vector<int> distances(15, 0);

    // ============================================================
    // begin()
    // ============================================================

    // vec.begin() returns an iterator pointing to the
    // FIRST element of the vector.
    //
    // Since the first element is 8:
    //
    // *(vec.begin()) -> gives the value stored at the first element.
    cout << *(vec.begin()) << endl;

    // ============================================================
    // end()
    // ============================================================

    // IMPORTANT:
    // vec.end() does NOT point to the last element.
    //
    // It points to the position JUST AFTER the last element.
    //
    // Therefore, dereferencing vec.end() like:
    //
    // *(vec.end())
    //
    // is INVALID and causes UNDEFINED BEHAVIOR.
    //
    // So this line should NOT be used in real code:
    cout << *(vec.end()) << endl;

    // To access the LAST element using an iterator,
    // we can use:
    //
    // *(vec.end() - 1)
    //
    // But the easier way is:
    //
    // vec.back()

    // ============================================================
    // size()
    // ============================================================

    // size() returns the number of elements currently
    // present in the vector.
    //
    // Currently:
    //
    // [8,8,8,8,8,8,8,8,8,8]
    //
    // size = 10
    cout << vec.size() << endl;

    // ============================================================
    // push_back()
    // ============================================================

    // push_back() adds a new element at the END of the vector.

    vec.push_back(10);
    // Vector:
    // [8,8,8,8,8,8,8,8,8,8,10]

    vec.push_back(20);
    // Vector:
    // [8,8,8,8,8,8,8,8,8,8,10,20]

    vec.push_back(30);
    // Vector:
    // [8,8,8,8,8,8,8,8,8,8,10,20,30]

    vec.push_back(40);
    // Vector:
    // [8,8,8,8,8,8,8,8,8,8,10,20,30,40]

    // ============================================================
    // pop_back()
    // ============================================================

    // pop_back() removes the LAST element of the vector.
    //
    // IMPORTANT:
    // pop_back() does not return the removed value.

    vec.pop_back();
    // Removes 40.
    //
    // Vector:
    // [8,8,8,8,8,8,8,8,8,8,10,20,30]

    vec.pop_back();
    // Removes 30.
    //
    // Vector:
    // [8,8,8,8,8,8,8,8,8,8,10,20]

    // Now the size is:
    // 12
    cout << "Size: " << vec.size() << endl;

    // ============================================================
    // front()
    // ============================================================

    // front() returns the FIRST element of the vector.
    //
    // Current vector:
    // [8,8,8,8,8,8,8,8,8,8,10,20]
    //
    // First element = 8
    cout << vec.front() << endl;

    // ============================================================
    // back()
    // ============================================================

    // back() returns the LAST element of the vector.
    //
    // Current last element = 20
    cout << vec.back() << endl;

    // ============================================================
    // empty()
    // ============================================================

    // empty() checks whether the vector contains zero elements.
    //
    // Returns:
    //
    // 1 -> true  -> vector is empty
    // 0 -> false -> vector is NOT empty
    //
    // Current vector has elements, so output will be 0.
    cout << vec.empty() << endl;

    // ============================================================
    // Access using []
    // ============================================================

    // vec[0] means:
    // "Give me the element at index 0."
    //
    // Indexing starts from 0:
    //
    // index:   0  1  2  3 ...
    // value:   8  8  8  8 ...

    // We are changing the first element from 8 to 100.
    vec[0] = 100;

    // Now the first element is 100.
    cout << vec[0] << endl;

    // ============================================================
    // at()
    // ============================================================

    // at(index) is another way to access an element.
    //
    // vec.at(0) -> first element.
    //
    // Difference between [] and at():
    //
    // vec[0]
    // -> Does NOT perform bounds checking.
    //
    // vec.at(0)
    // -> Performs bounds checking.
    //
    // If the index is invalid, at() can throw
    // std::out_of_range exception.

    cout << vec.at(0) << endl;

    // ============================================================
    // capacity()
    // ============================================================

    // capacity() tells us how much memory the vector has
    // currently allocated for its elements.
    //
    // IMPORTANT:
    //
    // size()     = number of elements actually present
    // capacity() = number of elements that can fit in the
    //              currently allocated storage without
    //              requiring another allocation.
    //
    // capacity can be GREATER than size.
    cout << vec.capacity() << endl;

    // Current number of actual elements.
    cout << "Size: " << vec.size() << endl;

    // ============================================================
    // reserve()
    // ============================================================

    // reserve(40) requests enough capacity for at least
    // 40 elements.
    //
    // IMPORTANT:
    //
    // reserve() changes CAPACITY.
    // reserve() does NOT change SIZE.
    //
    // So after:
    //
    // vec.reserve(40);
    //
    // size remains the same,
    // but capacity becomes at least 40.
    vec.reserve(40);

    cout << vec.capacity() << endl;
    // capacity >= 40

    cout << "Size: " << vec.size() << endl;
    // size is still 12

    // ============================================================
    // max_size()
    // ============================================================

    // max_size() returns the theoretical maximum number
    // of elements that this vector could contain,
    // according to the implementation/system limitations.
    //
    // This is NOT the current size.
    // It is also NOT the current capacity.
    cout << vec.max_size() << endl;

    // ============================================================
    // clear()
    // ============================================================

    // clear() removes ALL elements from the vector.
    //
    // Before clear():
    //
    // [100,8,8,8,8,8,8,8,8,8,10,20]
    //
    // After clear():
    //
    // []
    //
    // IMPORTANT:
    //
    // clear() changes size to 0,
    // but it does NOT guarantee that capacity becomes 0.
    //
    // The allocated memory may still remain available
    // for future insertions.
    vec.clear();

    cout << "Size: " << vec.size() << endl;
    // Output = 0

    // ============================================================
    // insert()
    // ============================================================

    // insert() adds an element at a specified position.

    // ------------------------------------------------------------
    // First insertion
    // ------------------------------------------------------------

    // vec.begin() points to the beginning of the vector.
    //
    // Since the vector is currently empty,
    // inserting 50 at begin() puts 50 into the vector.
    //
    // Vector:
    //
    // [50]
    vec.insert(vec.begin(), 50);

    cout << "Size: " << vec.size() << endl;
    // size = 1

    // ------------------------------------------------------------
    // Second insertion
    // ------------------------------------------------------------

    // Current vector:
    //
    // [50]
    //
    // vec.begin() + 2 means position/index 2.
    //
    // IMPORTANT:
    // This is INVALID here because the vector currently
    // has only ONE element, and begin() + 2 is outside
    // the valid insertion range for this iterator.
    //
    // For a safe insertion, the iterator must be in the range:
    //
    // [begin(), end()]
    //
    // Since end() currently equals begin() + 1,
    // begin() + 2 is beyond end().
    //
    // Therefore, this line is also NOT valid:
    vec.insert(vec.begin() + 2, 20);

    // ------------------------------------------------------------
    // Third insertion
    // ------------------------------------------------------------

    // Same problem here.
    //
    // The vector does NOT have enough elements for
    // vec.begin() + 8 to be a valid insertion position.
    //
    // This line is also invalid:
    vec.insert(vec.begin() + 8, 80);

    // ============================================================
    // Accessing vec[0]
    // ============================================================

    // Because the first insertion was successful,
    // vec[0] is 50.
    //
    // However, because the two insert() calls above use
    // invalid iterator positions, the program has
    // UNDEFINED BEHAVIOR before reaching this point.
    //
    // Therefore, the behavior of the program as a whole
    // is not reliable.
    cout << vec[0] << endl;

    // ============================================================
    // CREATION OF VECTORS
    // ============================================================

    // Creating first vector.
    //
    // vec1 contains:
    //
    // [10, 20, 30]
    vector<int> vec1 = {10, 20, 30};

    // Creating second vector.
    //
    // vec2 contains:
    //
    // [100, 200]
    vector<int> vec2 = {100, 200};

    // ============================================================
    // size()
    // ============================================================

    // size() returns the number of elements currently present
    // inside the vector.
    //
    // vec1:
    // [10, 20, 30]
    //
    // Number of elements = 3
    //
    // IMPORTANT:
    //
    // vec1.size();
    //
    // This only returns the value.
    // If we want to see the value on the screen,
    // we need to use cout.
    cout << "Size of vec1: " << vec1.size() << endl;

    // vec2:
    // [100, 200]
    //
    // Number of elements = 2
    cout << "Size of vec2: " << vec2.size() << endl;

    // ============================================================
    // erase(begin(), end())
    // ============================================================

    // erase() is used to remove elements from a vector.
    //
    // General syntax:
    //
    // vec.erase(start_position, end_position);
    //
    // The range follows:
    //
    // [start, end)
    //
    // This means:
    //
    // start -> INCLUDED
    // end   -> NOT INCLUDED
    //
    //
    // vec1 currently:
    //
    // [10, 20, 30]
    //
    // vec1.begin()
    // -> points to the first element, 10
    //
    // vec1.end()
    // -> points JUST AFTER the last element
    //
    // Therefore:
    //
    // vec1.erase(vec1.begin(), vec1.end());
    //
    // means:
    //
    // "Erase every element from the beginning
    //  until the end."
    vec1.erase(vec1.begin(), vec1.end());

    // Now vec1 becomes:
    //
    // []
    //
    // So its size becomes 0.
    cout << "Size of vec1 after erase: "
         << vec1.size() << endl;

    // ============================================================
    // IMPORTANT: erase() vs clear()
    // ============================================================

    // The following:
    //
    // vec1.erase(vec1.begin(), vec1.end());
    //
    // removes all elements.
    //
    // But when we simply want to remove ALL elements,
    // a much cleaner way is:
    //
    // vec1.clear();
    //
    // Example:
    //
    // vector<int> v = {1, 2, 3};
    // v.clear();
    //
    // Now v becomes empty.

    // ============================================================
    // SWAP FUNCTION
    // ============================================================

    // swap() exchanges the contents of two vectors.
    //
    // Before swap:
    //
    // vec1 = []
    // vec2 = [100, 200]
    //
    // We will now put some elements back into vec1
    // so that the swap operation is easier to understand.

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // Now:
    //
    // vec1 = [10, 20, 30]
    // vec2 = [100, 200]

    // ============================================================
    // PRINT VECTORS BEFORE SWAP
    // ============================================================

    cout << "\nBefore swap:" << endl;

    cout << "vec1: ";

    // Range-based for loop:
    //
    // It goes through every element of vec1.
    for (int x : vec1)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "vec2: ";

    // Printing every element of vec2.
    for (int x : vec2)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // swap()
    // ============================================================

    // swap() exchanges the contents of vec1 and vec2.
    //
    // Syntax:
    //
    // vec1.swap(vec2);
    //
    // Before swap:
    //
    // vec1 = [10, 20, 30]
    // vec2 = [100, 200]
    //
    // After swap:
    //
    // vec1 = [100, 200]
    // vec2 = [10, 20, 30]
    vec1.swap(vec2);

    // ============================================================
    // PRINT VECTORS AFTER SWAP
    // ============================================================

    cout << "\nAfter swap:" << endl;

    cout << "vec1: ";

    for (int x : vec1)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "vec2: ";

    for (int x : vec2)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // CHECK SIZE AFTER SWAP
    // ============================================================

    // After swapping:
    //
    // vec1 = [100, 200]
    // vec2 = [10, 20, 30]
    //
    // Therefore:
    //
    // vec1.size() = 2
    // vec2.size() = 3

    cout << "\nSize of vec1 after swap: "
         << vec1.size() << endl;

    cout << "Size of vec2 after swap: "
         << vec2.size() << endl;

    // ============================================================
    // ANOTHER WAY TO SWAP
    // ============================================================

    // We can also use the standard swap() function:
    //
    // swap(vec1, vec2);
    //
    // This also exchanges the contents of the two vectors.
    //
    // Example:
    //
    // Current:
    //
    // vec1 = [100, 200]
    // vec2 = [10, 20, 30]
    //
    // After:
    //
    // swap(vec1, vec2);
    //
    // vec1 = [10, 20, 30]
    // vec2 = [100, 200]
    //
    // We are not executing it here because we already swapped
    // the vectors above.

    // ============================================================
    // FINAL STATE
    // ============================================================

    // At this point:
    //
    // vec1 = [100, 200]
    // vec2 = [10, 20, 30]
    //
    // And:
    //
    // vec1.size() = 2
    // vec2.size() = 3

    return 0;
}
