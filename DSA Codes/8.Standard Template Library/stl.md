# C++ STL - Standard Template Library

STL stands for **Standard Template Library**.

STL provides ready-made:

1. Containers
2. Iterators
3. Algorithms
4. Function Objects

The four important STL containers covered here are:

1. Vector
2. List
3. Set
4. Map

==================================================

# 1. VECTOR

==================================================

Vector is a **dynamic array**.

Unlike a normal array, its size can grow or shrink
automatically during runtime.

Header:

#include <vector>

Syntax:

vector<int> v;

---

## VECTOR DECLARATION

---

vector<int> v;

vector<string> names;

vector<double> marks;

---

## VECTOR INITIALIZATION

---

vector<int> v1;

vector<int> v2 = {10, 20, 30};

vector<int> v3{10, 20, 30};

vector<int> v4(5);
// Creates 5 elements with default value 0

vector<int> v5(5, 10);
// Creates 5 elements, all having value 10

---

## ADD ELEMENT

---

push_back() adds an element at the end.

vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

Result:

10 20 30

---

## ACCESS ELEMENT

---

vector<int> v = {10, 20, 30};

cout << v[0];

cout << v[1];

cout << v.at(2);

v.front();
// First element

v.back();
// Last element

---

## [] vs at()

---

v[2];

Direct access.

It does NOT perform bounds checking.

v.at(2);

Performs bounds checking.

---

## UPDATE ELEMENT

---

vector<int> v = {10, 20, 30};

v[1] = 50;

Result:

10 50 30

---

## REMOVE LAST ELEMENT

---

v.pop_back();

---

## ERASE ELEMENT

---

vector<int> v = {10, 20, 30};

v.erase(v.begin());
// Removes first element

v.erase(v.begin() + 1);
// Removes second element

---

## ERASE RANGE

---

v.erase(v.begin(), v.begin() + 2);

---

## CLEAR VECTOR

---

v.clear();

---

## SIZE

---

cout << v.size();

Returns number of elements.

---

## CAPACITY

---

cout << v.capacity();

Capacity tells how much storage has currently
been allocated.

---

## EMPTY

---

if (v.empty())
{
cout << "Vector is empty";
}

---

## RESERVE

---

v.reserve(100);

Reserves memory for at least 100 elements.

It does NOT change the size of the vector.

---

## RESIZE

---

v.resize(10);

Changes the number of elements.

---

## TRAVERSING VECTOR

---

Normal loop:

for (int i = 0; i < v.size(); i++)
{
cout << v[i] << " ";
}

Range-based loop:

for (int x : v)
{
cout << x << " ";
}

Iterator:

for (auto it = v.begin(); it != v.end(); it++)
{
cout << \*it << " ";
}

---

## VECTOR ITERATORS

---

v.begin()
-> Iterator pointing to first element

v.end()
-> Iterator pointing after last element

v.rbegin()
-> Reverse iterator at last element

v.rend()
-> Reverse iterator before first element

Example:

for (auto it = v.begin(); it != v.end(); it++)
{
cout << \*it << " ";
}

---

## VECTOR EXAMPLE

---

#include <iostream>
#include <vector>
using namespace std;

int main()
{
vector<int> v = {10, 20, 30};

    v.push_back(40);
    v.push_back(50);

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;

}

==================================================

# 2. LIST

==================================================

List is a **doubly linked list**.

Each node contains:

- Data
- Address of previous node
- Address of next node

Header:

#include <list>

Syntax:

list<int> l;

---

## LIST INITIALIZATION

---

list<int> l1;

list<int> l2 = {10, 20, 30};

list<int> l3(5, 10);

Creates:

10 10 10 10 10

---

## PUSH FRONT

---

l.push_front(10);

---

## PUSH BACK

---

l.push_back(20);

---

## POP FRONT

---

l.pop_front();

---

## POP BACK

---

l.pop_back();

---

## ACCESS FIRST AND LAST

---

l.front();

l.back();

IMPORTANT:

List does NOT support random access.

This is wrong:

l[2];

This is not allowed for std::list.

---

## INSERT

---

list<int> l = {10, 20, 30};

auto it = l.begin();

advance(it, 1);

l.insert(it, 50);

Result:

10 50 20 30

---

## ERASE

---

auto it = l.begin();

advance(it, 1);

l.erase(it);

---

## REMOVE

---

l.remove(20);

Removes all elements having value 20.

---

## REMOVE IF

---

l.remove_if([](int x)
{
return x % 2 == 0;
});

Removes even numbers.

---

## SORT

---

l.sort();

---

## REVERSE

---

l.reverse();

---

## UNIQUE

---

l.unique();

Removes consecutive duplicate elements.

Example:

10 20 20 30 30

After unique():

10 20 30

---

## SIZE

---

cout << l.size();

---

## EMPTY

---

l.empty();

---

## CLEAR

---

l.clear();

---

## TRAVERSE LIST

---

for (int x : l)
{
cout << x << " ";
}

Using iterator:

for (auto it = l.begin(); it != l.end(); it++)
{
cout << \*it << " ";
}

---

## LIST EXAMPLE

---

#include <iostream>
#include <list>
using namespace std;

int main()
{
list<int> l = {30, 10, 20};

    l.push_front(5);
    l.push_back(40);

    l.sort();

    for (int x : l)
    {
        cout << x << " ";
    }

    return 0;

}

==================================================

# 3. SET

==================================================

Set stores **unique values**.

Important properties:

- Duplicate values are not stored
- Elements are sorted automatically
- Default order is ascending
- No random access

Header:

#include <set>

Syntax:

set<int> s;

---

## SET INITIALIZATION

---

set<int> s = {30, 10, 20, 10};

Output:

10 20 30

The duplicate 10 is automatically removed.

---

## INSERT

---

s.insert(10);

s.insert(20);

s.insert(30);

---

## DUPLICATE INSERTION

---

s.insert(10);
s.insert(10);
s.insert(10);

Only one 10 will exist.

---

## FIND

---

if (s.find(20) != s.end())
{
cout << "Found";
}

find() returns an iterator.

If element is not found:

s.find(100) == s.end()

---

## COUNT

---

if (s.count(20))
{
cout << "Found";
}

For set:

count() returns:

0 -> Element does not exist
1 -> Element exists

---

## ERASE

---

s.erase(20);

---

## ERASE USING ITERATOR

---

auto it = s.find(20);

if (it != s.end())
{
s.erase(it);
}

---

## SIZE

---

cout << s.size();

---

## EMPTY

---

if (s.empty())
{
cout << "Empty";
}

---

## CLEAR

---

s.clear();

---

## FIRST AND LAST

---

\*s.begin()
// Smallest element

\*prev(s.end())
// Largest element

---

## TRAVERSING SET

---

for (int x : s)
{
cout << x << " ";
}

Using iterator:

for (auto it = s.begin(); it != s.end(); it++)
{
cout << \*it << " ";
}

---

## SET EXAMPLE

---

#include <iostream>
#include <set>
using namespace std;

int main()
{
set<int> s = {40, 10, 20, 10, 30};

    s.insert(50);

    for (int x : s)
    {
        cout << x << " ";
    }

    return 0;

}

Output:

10 20 30 40 50

==================================================

# 4. MAP

==================================================

Map stores data in the form:

KEY -> VALUE

Example:

1 -> Amit
2 -> Rahul
3 -> Ravi

Properties:

- Each key is unique
- Keys are sorted by default
- Values can be duplicate
- Data is stored as key-value pairs

Header:

#include <map>

Syntax:

map<int, string> m;

---

## MAP INITIALIZATION

---

map<int, string> m =
{
{1, "Amit"},
{2, "Rahul"},
{3, "Ravi"}
};

---

## INSERT USING []

---

m[1] = "Amit";

m[2] = "Rahul";

m[3] = "Ravi";

---

## INSERT USING insert()

---

m.insert({4, "Raj"});

---

## INSERT USING emplace()

---

m.emplace(5, "Rohit");

---

## ACCESS VALUE

---

cout << m[1];

---

## UPDATE VALUE

---

m[1] = "Amit Kumar";

---

## IMPORTANT [] BEHAVIOUR

---

Suppose:

map<int, string> m;

cout << m[10];

If key 10 does not exist, operator[]
creates the key with its default value.

For string:

10 -> ""

To only check whether key exists,
use find() or count().

---

## FIND

---

auto it = m.find(2);

if (it != m.end())
{
cout << it->first << " ";
cout << it->second;
}

---

## COUNT

---

if (m.count(2))
{
cout << "Key exists";
}

---

## ERASE USING KEY

---

m.erase(2);

---

## ERASE USING ITERATOR

---

auto it = m.find(2);

if (it != m.end())
{
m.erase(it);
}

---

## SIZE

---

cout << m.size();

---

## EMPTY

---

m.empty();

---

## CLEAR

---

m.clear();

---

## TRAVERSING MAP

---

for (auto x : m)
{
cout << x.first << " -> "
<< x.second << endl;
}

Here:

x.first
-> Key

x.second
-> Value

---

## MAP EXAMPLE

---

#include <iostream>
#include <map>
using namespace std;

int main()
{
map<int, string> m;

    m[1] = "Amit";
    m[2] = "Rahul";
    m[3] = "Ravi";

    for (auto x : m)
    {
        cout << x.first << " -> "
             << x.second << endl;
    }

    return 0;

}

==================================================

# VECTOR vs LIST

==================================================

VECTOR:

- Dynamic array
- Contiguous memory
- Random access available
- v[index] works
- Fast access
- push_back() is efficient
- Insertion in middle can be expensive

LIST:

- Doubly linked list
- Non-contiguous memory
- Random access NOT available
- l[index] does not work
- Fast insertion/deletion when iterator is known
- Extra memory for links

Example:

vector<int> v;

v[2];

Works.

list<int> l;

l[2];

Does NOT work.

==================================================

# SET vs MAP

==================================================

SET:

Stores only values.

Example:

10
20
30

MAP:

Stores key-value pairs.

Example:

1 -> Amit
2 -> Rahul
3 -> Ravi

SET:

set<int> s;

MAP:

map<int, string> m;

==================================================

# DUPLICATES

==================================================

VECTOR:

Duplicates allowed.

vector<int> v = {10, 10, 20};

Result:

10 10 20

LIST:

Duplicates allowed.

list<int> l = {10, 10, 20};

Result:

10 10 20

SET:

Duplicates NOT allowed.

set<int> s = {10, 10, 20};

Result:

10 20

MAP:

Keys NOT duplicated.

map<int, string> m;

m[1] = "Amit";
m[1] = "Rahul";

Result:

1 -> Rahul

The second assignment updates the value.

==================================================

# ITERATORS

==================================================

Iterator is an object used to move through
elements of an STL container.

Basic syntax:

auto it = container.begin();

Example:

vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << \*it;

---

## begin()

---

Returns iterator to first element.

---

## end()

---

Returns iterator to position after last element.

IMPORTANT:

end() does NOT point to the last element.

To access last element:

\*(container.end() - 1)

This works for random-access containers like vector.

For general containers:

\*prev(container.end())

---

## Iterator Traversal

---

for (auto it = v.begin();
it != v.end();
it++)
{
cout << \*it << " ";
}

==================================================

# STL ALGORITHMS

==================================================

Most STL algorithms are available through:

#include <algorithm>

---

## SORT

---

vector<int> v = {30, 10, 20};

sort(v.begin(), v.end());

Result:

10 20 30

---

## SORT DESCENDING

---

sort(v.begin(), v.end(), greater<int>());

Result:

30 20 10

---

## REVERSE

---

reverse(v.begin(), v.end());

---

## FIND

---

auto it = find(v.begin(), v.end(), 20);

if (it != v.end())
{
cout << "Found";
}

---

## MAX ELEMENT

---

auto it = max_element(v.begin(), v.end());

cout << \*it;

---

## MIN ELEMENT

---

auto it = min_element(v.begin(), v.end());

cout << \*it;

---

## COUNT

---

int count = std::count(v.begin(), v.end(), 10);

---

## ACCUMULATE

---

For sum:

#include <numeric>

int sum = accumulate(v.begin(), v.end(), 0);

Example:

vector<int> v = {10, 20, 30};

int sum = accumulate(v.begin(), v.end(), 0);

Result:

60

==================================================

# LAMBDA WITH STL

==================================================

Lambda is an anonymous function.

Example:

auto square = [](int x)
{
return x \* x;
};

cout << square(5);

---

## LAMBDA WITH SORT

---

sort(v.begin(), v.end(),
[](int a, int b)
{
return a > b;
});

This sorts in descending order.

==================================================

# PAIR

==================================================

pair stores two values together.

Header:

#include <utility>

Syntax:

pair<int, string> p;

Initialization:

pair<int, string> p = {1, "Amit"};

Access:

p.first
-> First value

p.second
-> Second value

Example:

cout << p.first << endl;
cout << p.second << endl;

---

## MAKE_PAIR

---

auto p = make_pair(10, "Amit");

==================================================

# VECTOR OF PAIRS

==================================================

vector<pair<int, string>> v;

v.push_back({1, "Amit"});
v.push_back({2, "Rahul"});

for (auto x : v)
{
cout << x.first << " "
<< x.second << endl;
}

==================================================

# NESTED VECTOR

==================================================

vector<vector<int>> matrix =
{
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
};

Access:

cout << matrix[0][1];

Output:

2

Traverse:

for (auto row : matrix)
{
for (auto x : row)
{
cout << x << " ";
}

    cout << endl;

}

==================================================

# COMMON STL FUNCTIONS

==================================================

begin()
-> First element iterator

end()
-> Position after last element

size()
-> Number of elements

empty()
-> Checks whether container is empty

clear()
-> Removes all elements

insert()
-> Inserts element

erase()
-> Removes element

find()
-> Searches element/key

count()
-> Counts/checks element/key

front()
-> First element

back()
-> Last element

push_back()
-> Adds element at end

pop_back()
-> Removes last element

push_front()
-> Adds element at beginning
(available in list/deque)

==================================================

# TIME COMPLEXITY - BASIC

==================================================

VECTOR:

Access:
O(1)

push_back:
O(1) average

Search:
O(n)

Insert middle:
O(n)

Delete middle:
O(n)

LIST:

Access:
O(n)

Search:
O(n)

Insert/Delete at known iterator:
O(1)

SET:

Search:
O(log n)

Insert:
O(log n)

Delete:
O(log n)

MAP:

Search:
O(log n)

Insert:
O(log n)

Delete:
O(log n)

==================================================

# WHEN TO USE WHAT?

==================================================

USE VECTOR WHEN:

- You need fast index access
- You mostly add elements at the end
- You need a dynamic array
- You need cache-friendly storage

USE LIST WHEN:

- Frequent insertion/deletion is required
- You already have an iterator to the position
- Random access is not required

USE SET WHEN:

- You need unique values
- You need sorted values
- You frequently search for values

USE MAP WHEN:

- You need key-value data
- Keys should be unique
- You need searching using keys

==================================================

# COMPLETE STL PROGRAM

==================================================

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
// ---------------- VECTOR ----------------

    vector<int> v = {30, 10, 20, 10};

    v.push_back(40);

    sort(v.begin(), v.end());

    cout << "Vector: ";

    for (int x : v)
    {
        cout << x << " ";
    }


    // ---------------- LIST ----------------

    list<int> l = {30, 10, 20};

    l.push_front(5);
    l.push_back(40);

    l.sort();

    cout << "\nList: ";

    for (int x : l)
    {
        cout << x << " ";
    }


    // ---------------- SET ----------------

    set<int> s = {30, 10, 20, 10};

    cout << "\nSet: ";

    for (int x : s)
    {
        cout << x << " ";
    }


    // ---------------- MAP ----------------

    map<int, string> m;

    m[1] = "Amit";
    m[2] = "Rahul";
    m[3] = "Ravi";

    cout << "\nMap:" << endl;

    for (auto x : m)
    {
        cout << x.first << " -> "
             << x.second << endl;
    }


    // ---------------- ALGORITHM ----------------

    int sum = accumulate(v.begin(), v.end(), 0);

    cout << "\nSum of vector: " << sum << endl;

    return 0;

}

==================================================

# QUICK REVISION

==================================================

VECTOR

Dynamic Array
Duplicates allowed
Sorted automatically? NO
Random access: YES

Important functions:

push_back()
pop_back()
insert()
erase()
clear()
size()
capacity()
resize()
reserve()
front()
back()

LIST

Doubly Linked List
Duplicates allowed
Sorted automatically? NO
Random access: NO

Important functions:

push_front()
push_back()
pop_front()
pop_back()
insert()
erase()
remove()
remove_if()
sort()
reverse()
unique()

SET

Unique values
Duplicates not allowed
Sorted automatically: YES
Random access: NO

Important functions:

insert()
erase()
find()
count()
begin()
end()
size()
clear()

MAP

Key-value pairs
Keys unique
Values can duplicate
Sorted by key: YES

Important functions:

insert()
emplace()
erase()
find()
count()
size()
clear()

Access:

m[key]

Iterator:

it->first
it->second

==================================================

# MOST IMPORTANT HEADERS

==================================================

#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>

==================================================

# ONE-LINE DIFFERENCE

==================================================

vector
-> Dynamic array

list
-> Doubly linked list

set
-> Unique sorted values

map
-> Unique sorted keys + values

==================================================

# INTERVIEW POINTS

==================================================

1. Vector supports random access.

2. List does not support random access.

3. Set stores only unique values.

4. Map stores key-value pairs.

5. Set keys/values are sorted by default.

6. Map keys are sorted by default.

7. Vector stores elements in contiguous memory.

8. List nodes are generally stored in non-contiguous memory.

9. vector::at() performs bounds checking.

10. vector::operator[] does not perform bounds checking.

11. map[key] can create a new key if the key does not exist.

12. find() returns an iterator.

13. end() points after the last element.

14. Iterators are used to traverse STL containers.

15. Algorithms such as sort(), find(), reverse(),
    max_element() and min_element() are provided
    by the STL algorithm library.

==================================================

# END

==================================================
