# C++ STL — Map Detailed Notes

# 1. What is `map`?

C++ STL ka `map` ek **associative container** hai.

Isme data:

```text
KEY → VALUE
```

ke form mein store hota hai.

Example:

```cpp
map<int, string> mp;
```

Yahan:

```text
int
 ↓
Key

string
 ↓
Value
```

Example data:

```text
1 → Rahul
2 → Aman
3 → Priya
```

So:

```text
Key   Value

1  →  Rahul
2  →  Aman
3  →  Priya
```

---

# 2. Map ka Main Concept

Normal array/vector mein hum index se data access karte hain:

```cpp
arr[5];
```

Lekin `map` mein hum **key** ke through value access karte hain.

Example:

```cpp
map<int, string> mp;

mp[101] = "Rahul";
mp[102] = "Aman";
mp[103] = "Priya";
```

Now:

```cpp
cout << mp[101];
```

Output:

```text
Rahul
```

So:

```text
Key = 101
Value = Rahul
```

---

# 3. Header File

For `map`:

```cpp
#include <map>
```

Usually competitive programming mein:

```cpp
#include <bits/stdc++.h>
```

enough hota hai.

Example:

```cpp
#include <iostream>
#include <map>

using namespace std;

int main() {

    map<int, string> mp;

    return 0;
}
```

---

# 4. Basic Syntax

General syntax:

```cpp
map<KeyType, ValueType> mapName;
```

Example:

```cpp
map<int, string> mp;
```

Meaning:

```text
Key   = int
Value = string
```

Another example:

```cpp
map<string, int> mp;
```

Meaning:

```text
Key   = string
Value = int
```

Another:

```cpp
map<char, int> mp;
```

Meaning:

```text
Key   = char
Value = int
```

---

# 5. Map Stores Key-Value Pairs

Example:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
mp[2] = "Aman";
mp[3] = "Priya";
```

Conceptually:

```text
1 → Rahul
2 → Aman
3 → Priya
```

Each entry consists of:

```text
KEY + VALUE
```

In C++, internally each element behaves like a:

```cpp
pair<const Key, Value>
```

For:

```cpp
map<int, string>
```

each element is approximately:

```cpp
pair<const int, string>
```

---

# 6. Why is the Key `const`?

In a `map`, keys determine the ordering of elements.

Therefore, you cannot directly modify the key of an existing element.

For example:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
```

You cannot do:

```cpp
// Not allowed
it->first = 10;
```

because:

```cpp
it->first
```

is a constant key.

If you want to change a key, generally you need to:

```text
erase old key
+
insert new key
```

---

# 7. Creating an Empty Map

```cpp
map<int, string> mp;
```

Initially:

```text
{}
```

No elements are present.

We can insert using:

```cpp
mp[key] = value;
```

Example:

```cpp
mp[1] = "Rahul";
```

Now:

```text
1 → Rahul
```

---

# 8. Inserting Using `[]`

One of the easiest ways to insert:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
mp[2] = "Aman";
mp[3] = "Priya";
```

Now:

```text
1 → Rahul
2 → Aman
3 → Priya
```

---

# 9. Accessing a Value Using `[]`

Suppose:

```cpp
map<int, string> mp;

mp[101] = "Rahul";
mp[102] = "Aman";
```

We can access:

```cpp
cout << mp[101];
```

Output:

```text
Rahul
```

Similarly:

```cpp
cout << mp[102];
```

Output:

```text
Aman
```

The syntax:

```cpp
mp[key]
```

means:

```text
Find this key
    ↓
Return its associated value
```

---

# 10. Very Important: `[]` Can Insert a New Key

This is one of the most important things to understand.

Suppose:

```cpp
map<int, int> mp;

mp[1] = 100;
```

Now:

```text
1 → 100
```

But if we do:

```cpp
cout << mp[5];
```

and key `5` does not exist, `map` will create it.

For `int` value:

```text
5 → 0
```

So after:

```cpp
mp[5]
```

the map contains:

```text
1 → 100
5 → 0
```

This is a very important difference between:

```cpp
mp[key]
```

and:

```cpp
mp.find(key)
```

---

# 11. Example of Automatic Insertion

```cpp
map<int, int> mp;

mp[10] = 50;

cout << mp[20];
```

Since `20` doesn't exist, it gets inserted with the default value:

```text
20 → 0
```

So:

```cpp
cout << mp.size();
```

will give:

```text
2
```

This is why you should be careful when checking whether a key exists.

---

# 12. `insert()`

Another way to insert elements:

```cpp
map<int, string> mp;

mp.insert({1, "Rahul"});
mp.insert({2, "Aman"});
mp.insert({3, "Priya"});
```

Now:

```text
1 → Rahul
2 → Aman
3 → Priya
```

You can also write:

```cpp
mp.insert(make_pair(4, "Riya"));
```

But modern C++ mein:

```cpp
mp.insert({4, "Riya"});
```

is simpler.

---

# 13. `emplace()`

We can also use:

```cpp
mp.emplace(key, value);
```

Example:

```cpp
map<int, string> mp;

mp.emplace(1, "Rahul");
mp.emplace(2, "Aman");
```

This inserts:

```text
1 → Rahul
2 → Aman
```

For basic DSA, these three are important:

```cpp
mp[key] = value;

mp.insert({key, value});

mp.emplace(key, value);
```

---

# 14. Duplicate Keys

A normal `map` does **not allow duplicate keys**.

Example:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
mp[1] = "Aman";
```

There is still only one key:

```text
1 → Aman
```

The second assignment updates the existing value.

So:

```text
Map:
One key → One value
```

---

# 15. Updating an Existing Value

Suppose:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
```

Now:

```cpp
mp[1] = "Aman";
```

The value gets updated.

Before:

```text
1 → Rahul
```

After:

```text
1 → Aman
```

The key remains:

```text
1
```

Only its value changes.

---

# 16. `map` Maintains Sorted Order of Keys

This is one of the most important properties of `map`.

Suppose:

```cpp
map<int, string> mp;

mp[50] = "A";
mp[10] = "B";
mp[30] = "C";
mp[20] = "D";
```

Even though we inserted:

```text
50
10
30
20
```

the map stores/iterates according to sorted key order:

```text
10
20
30
50
```

So:

```text
map
 ↓
keys are ordered
 ↓
ascending by default
```

---

# 17. Example of Sorted Order

```cpp
map<int, string> mp;

mp[50] = "A";
mp[10] = "B";
mp[30] = "C";
mp[20] = "D";

for (auto x : mp) {

    cout << x.first << " "
         << x.second << endl;
}
```

Output:

```text
10 B
20 D
30 C
50 A
```

Notice:

```text
10
20
30
50
```

is sorted.

---

# 18. Why is `map` Sorted?

A standard C++ `map` is typically implemented using a **self-balancing binary search tree**, commonly a Red-Black Tree.

Because of this:

```text
Keys remain ordered
```

and operations such as:

```text
search
insert
delete
```

can generally be performed in:

```text
O(log n)
```

---

# 19. Important Difference: `map` vs `unordered_map`

### `map`

```cpp
map<int, int> mp;
```

Properties:

```text
Keys ordered
Search = O(log n)
Insert = O(log n)
Erase  = O(log n)
```

### `unordered_map`

```cpp
unordered_map<int, int> ump;
```

Properties:

```text
Keys are not ordered
Average search = O(1)
Average insert = O(1)
Average erase  = O(1)
```

Quick memory:

```text
map
 ↓
Sorted
 ↓
O(log n)
```

```text
unordered_map
 ↓
No ordering
 ↓
Average O(1)
```

---

# 20. `begin()` and `end()`

`map` supports iterators.

Example:

```cpp
map<int, string> mp;

mp[10] = "A";
mp[20] = "B";
mp[30] = "C";

auto it = mp.begin();
```

`begin()` points to the first element.

Because map is sorted:

```text
begin()
  ↓
smallest key
```

For:

```text
10 → A
20 → B
30 → C
```

`mp.begin()` points to:

```text
10 → A
```

---

# 21. `end()`

`end()` points **after the last element**.

It does not point to the last element itself.

Correct traversal:

```cpp
for (auto it = mp.begin();
     it != mp.end();
     it++) {

    cout << it->first << " "
         << it->second << endl;
}
```

Never dereference:

```cpp
*mp.end()
```

because `end()` is not a valid element.

---

# 22. Iterating Through a Map

Modern C++:

```cpp
for (auto x : mp) {

    cout << x.first << " "
         << x.second << endl;
}
```

Here:

```cpp
x.first
```

means:

```text
key
```

and:

```cpp
x.second
```

means:

```text
value
```

---

# 23. Range-Based Loop

Example:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
mp[2] = "Aman";
mp[3] = "Priya";

for (auto x : mp) {

    cout << "Key: "
         << x.first
         << ", Value: "
         << x.second
         << endl;
}
```

Output:

```text
Key: 1, Value: Rahul
Key: 2, Value: Aman
Key: 3, Value: Priya
```

---

# 24. Structured Binding

Modern C++ mein aur clean way:

```cpp
for (auto [key, value] : mp) {

    cout << key << " "
         << value << endl;
}
```

Example:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
mp[2] = "Aman";
mp[3] = "Priya";

for (auto [key, value] : mp) {

    cout << key << " -> "
         << value << endl;
}
```

Output:

```text
1 -> Rahul
2 -> Aman
3 -> Priya
```

---

# 25. Accessing `first` and `second`

Every map element behaves like a pair.

Example:

```cpp
auto x = *mp.begin();
```

Then:

```cpp
x.first
```

is the key.

And:

```cpp
x.second
```

is the value.

Think:

```text
map element
    ↓
 pair
 /    \
first second
 |      |
key    value
```

---

# 26. `find()`

`find()` is used to search for a key.

Syntax:

```cpp
mp.find(key);
```

Example:

```cpp
map<int, string> mp;

mp[10] = "Rahul";
mp[20] = "Aman";

auto it = mp.find(10);
```

If key exists:

```text
it
 ↓
points to that key-value pair
```

---

# 27. Checking `find()`

Very important pattern:

```cpp
auto it = mp.find(10);

if (it != mp.end()) {

    cout << "Key exists";

}
else {

    cout << "Key does not exist";
}
```

Meaning:

```text
find(key) == end()
        ↓
Key does not exist
```

Otherwise:

```text
find(key) != end()
        ↓
Key exists
```

---

# 28. `find()` Does NOT Insert

This is a major difference from `[]`.

Suppose:

```cpp
map<int, int> mp;
```

Now:

```cpp
mp.find(10);
```

If `10` does not exist:

```text
10 is NOT inserted
```

But:

```cpp
mp[10];
```

can insert:

```text
10 → 0
```

So:

```text
mp[key]
 ↓
May insert key
```

while:

```text
mp.find(key)
 ↓
Only searches
```

---

# 29. `count()`

`count()` tells whether a key exists.

For a normal `map`, a key can occur at most once.

Therefore:

```cpp
mp.count(key)
```

returns either:

```text
0 → key does not exist
1 → key exists
```

Example:

```cpp
map<int, string> mp;

mp[10] = "A";
mp[20] = "B";

cout << mp.count(10);
```

Output:

```text
1
```

For:

```cpp
cout << mp.count(50);
```

Output:

```text
0
```

---

# 30. `find()` vs `count()`

Use `count()` when you only need to know:

```text
Does this key exist?
```

Example:

```cpp
if (mp.count(10)) {

    cout << "Found";
}
```

Use `find()` when you need the actual element/iterator.

Example:

```cpp
auto it = mp.find(10);

if (it != mp.end()) {

    cout << it->second;
}
```

Memory trick:

```text
count()
 ↓
Exists or not?

find()
 ↓
Where is it?
```

---

# 31. `erase()`

`erase()` removes an element.

### Erase using key

```cpp
mp.erase(key);
```

Example:

```cpp
map<int, string> mp;

mp[10] = "A";
mp[20] = "B";
mp[30] = "C";

mp.erase(20);
```

Now:

```text
10 → A
30 → C
```

Key `20` is removed.

---

# 32. Erase Using Iterator

We can also erase using an iterator:

```cpp
auto it = mp.find(20);

if (it != mp.end()) {

    mp.erase(it);
}
```

This is useful when you already have an iterator.

---

# 33. Erase Complexity

For a `map`:

```cpp
mp.erase(key);
```

generally takes:

```text
O(log n)
```

Finding a key:

```text
O(log n)
```

and removing it maintains the tree structure.

---

# 34. `size()`

Returns the number of key-value pairs.

Example:

```cpp
map<int, string> mp;

mp[1] = "A";
mp[2] = "B";
mp[3] = "C";

cout << mp.size();
```

Output:

```text
3
```

Complexity:

```text
O(1)
```

---

# 35. `empty()`

Checks whether the map contains zero elements.

```cpp
if (mp.empty()) {

    cout << "Map is empty";
}
```

Otherwise:

```cpp
cout << "Map is not empty";
```

Return:

```text
true  → empty
false → not empty
```

---

# 36. `clear()`

Removes all elements.

```cpp
mp.clear();
```

Before:

```text
1 → A
2 → B
3 → C
```

After:

```text
{}
```

Then:

```cpp
mp.empty();
```

returns:

```text
true
```

---

# 37. `lower_bound()`

`lower_bound(key)` returns an iterator pointing to the **first key that is greater than or equal to the given key**.

Example:

```cpp
map<int, string> mp;

mp[10] = "A";
mp[20] = "B";
mp[30] = "C";
mp[40] = "D";
```

Now:

```cpp
auto it = mp.lower_bound(25);
```

The first key:

```text
>= 25
```

is:

```text
30
```

So:

```cpp
it->first
```

is:

```text
30
```

---

# 38. `lower_bound()` Example

```cpp
map<int, string> mp;

mp[10] = "A";
mp[20] = "B";
mp[30] = "C";
mp[40] = "D";

auto it = mp.lower_bound(25);

if (it != mp.end()) {

    cout << it->first << " "
         << it->second;
}
```

Output:

```text
30 C
```

Because `30` is the first key satisfying:

```text
key >= 25
```

---

# 39. More `lower_bound()` Examples

Suppose keys:

```text
10 20 30 40 50
```

### `lower_bound(20)`

Returns:

```text
20
```

because:

```text
20 >= 20
```

### `lower_bound(25)`

Returns:

```text
30
```

### `lower_bound(50)`

Returns:

```text
50
```

### `lower_bound(60)`

Returns:

```text
end()
```

because no key is:

```text
>= 60
```

---

# 40. `upper_bound()`

`upper_bound(key)` returns the first key that is **strictly greater than** the given key.

Example:

```text
Keys:

10 20 30 40
```

Then:

```cpp
mp.upper_bound(20);
```

returns:

```text
30
```

because:

```text
30 > 20
```

---

# 41. `lower_bound()` vs `upper_bound()`

This is important.

```text
lower_bound(x)
        ↓
first key >= x
```

```text
upper_bound(x)
        ↓
first key > x
```

Example:

```text
Keys:

10 20 30 40
```

For:

```text
x = 20
```

we get:

```text
lower_bound(20) → 20
upper_bound(20) → 30
```

Memory trick:

```text
LOWER
  ↓
>=

UPPER
  ↓
>
```

---

# 42. `lower_bound()` and `upper_bound()` Complexity

Because `map` is ordered:

```text
lower_bound() = O(log n)

upper_bound() = O(log n)
```

These operations are one of the biggest advantages of `map`.

---

# 43. Reverse Iteration

A map can also be traversed in reverse order.

Use:

```cpp
rbegin()
```

and:

```cpp
rend()
```

Example:

```cpp
for (auto it = mp.rbegin();
     it != mp.rend();
     it++) {

    cout << it->first << " "
         << it->second << endl;
}
```

This processes keys from:

```text
largest → smallest
```

---

# 44. Example of Reverse Traversal

Suppose:

```text
10 → A
20 → B
30 → C
40 → D
```

Normal traversal:

```text
10 20 30 40
```

Reverse traversal:

```text
40 30 20 10
```

Code:

```cpp
for (auto it = mp.rbegin();
     it != mp.rend();
     it++) {

    cout << it->first << " ";
}
```

Output:

```text
40 30 20 10
```

---

# 45. Map with String Keys

Map keys don't have to be integers.

Example:

```cpp
map<string, int> mp;
```

Now:

```cpp
mp["Rahul"] = 90;
mp["Aman"] = 85;
mp["Priya"] = 95;
```

Conceptually:

```text
Aman  → 85
Priya → 95
Rahul → 90
```

The keys are sorted lexicographically.

---

# 46. String Map Example

```cpp
map<string, int> marks;

marks["Rahul"] = 90;
marks["Aman"] = 85;
marks["Priya"] = 95;

for (auto [name, score] : marks) {

    cout << name << " → "
         << score << endl;
}
```

Output:

```text
Aman → 85
Priya → 95
Rahul → 90
```

Because strings are ordered lexicographically.

---

# 47. Character Frequency Using Map

One of the most common DSA uses of `map` is **frequency counting**.

Suppose:

```text
"aabbccc"
```

We want:

```text
a → 2
b → 2
c → 3
```

Code:

```cpp
string s = "aabbccc";

map<char, int> freq;

for (char ch : s) {

    freq[ch]++;
}
```

Now:

```text
a → 2
b → 2
c → 3
```

---

# 48. Why Does `freq[ch]++` Work?

Initially:

```cpp
map<char, int> freq;
```

Suppose `a` doesn't exist.

When we do:

```cpp
freq['a']++;
```

`freq['a']` creates:

```text
'a' → 0
```

Then `++` changes it to:

```text
'a' → 1
```

Next occurrence:

```text
'a' → 2
```

and so on.

This is one of the most useful properties of `map`.

---

# 49. Frequency Counting Example

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

    string s = "programming";

    map<char, int> freq;

    for (char ch : s) {

        freq[ch]++;
    }

    for (auto [ch, count] : freq) {

        cout << ch << " → "
             << count
             << endl;
    }

    return 0;
}
```

Output will be in sorted character order.

---

# 50. Integer Frequency Map

Similarly:

```cpp
vector<int> nums = {
    10, 20, 10, 30, 20, 10
};

map<int, int> freq;

for (int x : nums) {

    freq[x]++;
}
```

Result:

```text
10 → 3
20 → 2
30 → 1
```

Because map automatically keeps keys sorted.

---

# 51. Map as a Dictionary

A very useful mental model:

```text
map = Dictionary
```

Example:

```cpp
map<string, string> phoneBook;

phoneBook["Rahul"] = "9999999999";
phoneBook["Aman"] = "8888888888";
```

Now:

```cpp
cout << phoneBook["Rahul"];
```

returns Rahul's associated value.

So:

```text
Name → Phone Number
```

is a natural use of a map.

---

# 52. Map with `pair`

Map elements can be accessed as pairs.

Example:

```cpp
map<int, string> mp;

mp[10] = "A";
mp[20] = "B";

for (auto x : mp) {

    cout << x.first << " "
         << x.second << endl;
}
```

Here:

```text
x.first  → key
x.second → value
```

---

# 53. `auto` with Map

Instead of writing:

```cpp
map<int, string>::iterator it;
```

you can simply use:

```cpp
auto it = mp.begin();
```

Modern C++ code generally prefers:

```cpp
for (auto it = mp.begin();
     it != mp.end();
     ++it) {

    cout << it->first << " "
         << it->second;
}
```

---

# 54. `const auto&` During Traversal

If we don't want to copy each pair:

```cpp
for (const auto& [key, value] : mp) {

    cout << key << " "
         << value << endl;
}
```

This is a good modern C++ style.

For normal DSA:

```cpp
for (auto [key, value] : mp)
```

is also very convenient.

---

# 55. Updating Values While Iterating

Suppose:

```cpp
map<int, int> mp;

mp[1] = 10;
mp[2] = 20;
mp[3] = 30;
```

You can modify values:

```cpp
for (auto& [key, value] : mp) {

    value *= 2;
}
```

Now:

```text
1 → 20
2 → 40
3 → 60
```

But remember:

```text
key cannot be modified
value can be modified
```

---

# 56. Map Key Cannot Be Modified Directly

Suppose:

```cpp
auto it = mp.begin();
```

You cannot do:

```cpp
it->first = 100;
```

because the key is const.

But:

```cpp
it->second = 500;
```

is allowed.

This is because:

```text
first  → key   → const
second → value → modifiable
```

---

# 57. `insert()` Does Not Replace Existing Key

This is an important difference between:

```cpp
mp[key] = value;
```

and:

```cpp
mp.insert({key, value});
```

Suppose:

```cpp
map<int, string> mp;

mp[1] = "Rahul";
```

Now:

```cpp
mp.insert({1, "Aman"});
```

The existing value is **not replaced**.

The map remains:

```text
1 → Rahul
```

because key `1` already exists.

---

# 58. `[]` vs `insert()`

### Using `[]`

```cpp
mp[1] = "Rahul";
mp[1] = "Aman";
```

Final:

```text
1 → Aman
```

Existing value gets updated.

### Using `insert()`

```cpp
mp.insert({1, "Rahul"});
mp.insert({1, "Aman"});
```

Final:

```text
1 → Rahul
```

Second insertion doesn't replace the existing key-value pair.

This distinction is very important.

---

# 59. `insert()` Return Value

`insert()` returns a pair containing:

```text
iterator
+
bool
```

Example:

```cpp
auto result = mp.insert({10, "Rahul"});
```

Then:

```cpp
result.first
```

is an iterator.

And:

```cpp
result.second
```

is a boolean.

Meaning:

```text
true
 ↓
Insertion happened

false
 ↓
Key already existed
```

Example:

```cpp
auto result = mp.insert({10, "Rahul"});

if (result.second) {

    cout << "Inserted";

}
else {

    cout << "Key already exists";
}
```

---

# 60. `at()`

Another way to access a value is:

```cpp
mp.at(key);
```

Example:

```cpp
map<int, string> mp;

mp[1] = "Rahul";

cout << mp.at(1);
```

Output:

```text
Rahul
```

Important difference:

```cpp
mp[key]
```

can insert a missing key.

But:

```cpp
mp.at(key)
```

does not insert it.

If the key doesn't exist, `at()` throws an exception.

So:

```text
operator[]
 ↓
may insert

at()
 ↓
does not insert
```

---

# 61. `at()` vs `[]`

Example:

```cpp
map<int, int> mp;

mp[1] = 100;
```

Now:

```cpp
cout << mp[5];
```

creates:

```text
5 → 0
```

But:

```cpp
cout << mp.at(5);
```

throws an exception because key `5` doesn't exist.

Use:

```cpp
at()
```

when you want checked access without accidental insertion.

---

# 62. Complete Map Example

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

    // ============================================================
    // CREATE MAP
    // ============================================================

    map<int, string> mp;


    // ============================================================
    // INSERT ELEMENTS
    // ============================================================

    mp[30] = "Priya";
    mp[10] = "Rahul";
    mp[20] = "Aman";


    // ============================================================
    // ACCESS VALUE
    // ============================================================

    cout << "Value of key 10: "
         << mp[10]
         << endl;


    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size: "
         << mp.size()
         << endl;


    // ============================================================
    // FIND
    // ============================================================

    auto it = mp.find(20);

    if (it != mp.end()) {

        cout << "Found: "
             << it->first
             << " -> "
             << it->second
             << endl;
    }


    // ============================================================
    // COUNT
    // ============================================================

    if (mp.count(30)) {

        cout << "Key 30 exists"
             << endl;
    }


    // ============================================================
    // ITERATE
    // ============================================================

    cout << "All elements:" << endl;

    for (auto [key, value] : mp) {

        cout << key
             << " -> "
             << value
             << endl;
    }


    // ============================================================
    // ERASE
    // ============================================================

    mp.erase(20);


    cout << "After erase:" << endl;

    for (auto [key, value] : mp) {

        cout << key
             << " -> "
             << value
             << endl;
    }


    return 0;
}
```

---

# 63. Map Complexity

For `std::map`:

| Operation       | Complexity |
| --------------- | ---------: |
| `insert()`      |   O(log n) |
| `emplace()`     |   O(log n) |
| `find()`        |   O(log n) |
| `count()`       |   O(log n) |
| `erase(key)`    |   O(log n) |
| `lower_bound()` |   O(log n) |
| `upper_bound()` |   O(log n) |
| `size()`        |       O(1) |
| `empty()`       |       O(1) |
| `clear()`       |       O(n) |

Why most operations are:

```text
O(log n)
```

Because `map` is typically implemented using a balanced search tree.

---

# 64. Map vs Vector

### Vector

```cpp
vector<int> v;
```

Data:

```text
index → value
```

Example:

```text
0 → 10
1 → 20
2 → 30
```

### Map

```cpp
map<int, int> mp;
```

Data:

```text
key → value
```

Example:

```text
100 → 10
500 → 20
900 → 30
```

Map allows arbitrary keys.

---

# 65. Map vs Unordered Map

This comparison is very important.

| Feature            | `map`        | `unordered_map` |
| ------------------ | ------------ | --------------- |
| Ordering           | Sorted       | No ordering     |
| Internal structure | Balanced BST | Hash Table      |
| Search             | O(log n)     | Average O(1)    |
| Insert             | O(log n)     | Average O(1)    |
| Erase              | O(log n)     | Average O(1)    |
| `lower_bound()`    | Yes          | No              |
| `upper_bound()`    | Yes          | No              |
| Duplicate keys     | No           | No              |

Memory trick:

```text
map
 ↓
ordered
 ↓
tree
 ↓
O(log n)
```

```text
unordered_map
 ↓
unordered
 ↓
hash table
 ↓
average O(1)
```

---

# 66. When Should You Use `map`?

Use `map` when:

### 1. You need sorted keys

```text
keys should remain ordered
```

### 2. You need `lower_bound()`

```cpp
mp.lower_bound(x);
```

### 3. You need `upper_bound()`

```cpp
mp.upper_bound(x);
```

### 4. You want predictable O(log n) operations

```text
search
insert
erase
```

### 5. You need key-value mapping

Examples:

```text
ID → Name

Number → Frequency

Character → Frequency

Student ID → Marks
```

---

# 67. When `map` is Especially Useful in DSA

Common patterns:

```text
1. Frequency counting

2. Coordinate/value mapping

3. Maintaining sorted keys

4. Searching nearest key

5. lower_bound / upper_bound

6. Prefix-related problems

7. Greedy problems

8. Graph-related mappings

9. Dictionary-like data

10. Counting occurrences
```

---

# 68. Frequency Counting Pattern

This is one of the most important patterns to memorize:

```cpp
map<int, int> freq;

for (int x : nums) {

    freq[x]++;
}
```

Meaning:

```text
key   = number
value = frequency
```

Example:

```text
nums:

5 5 2 3 5 2
```

Map:

```text
2 → 2
3 → 1
5 → 3
```

Because keys are automatically sorted.

---

# 69. Find Minimum Key

Since map is sorted:

```cpp
auto it = mp.begin();
```

gives the smallest key.

Example:

```cpp
map<int, string> mp;

mp[50] = "A";
mp[10] = "B";
mp[30] = "C";
```

Then:

```cpp
mp.begin()->first
```

is:

```text
10
```

So:

```text
begin()
 ↓
smallest key
```

---

# 70. Find Maximum Key

Use:

```cpp
prev(mp.end())
```

Example:

```cpp
auto it = prev(mp.end());

cout << it->first;
```

If keys are:

```text
10 20 30 50
```

then:

```text
maximum key = 50
```

You can also use:

```cpp
mp.rbegin()->first
```

because reverse begin points to the largest key.

---

# 71. Minimum and Maximum Key

For:

```cpp
map<int, string> mp;
```

### Minimum key

```cpp
mp.begin()->first
```

### Maximum key

```cpp
mp.rbegin()->first
```

But make sure the map is not empty.

Safe:

```cpp
if (!mp.empty()) {

    cout << "Min key: "
         << mp.begin()->first;

    cout << "Max key: "
         << mp.rbegin()->first;
}
```

---

# 72. Finding Nearest Key

This is where `lower_bound()` becomes very useful.

Suppose:

```text
Keys:

10 20 30 40 50
```

We want the first key:

```text
>= 25
```

Use:

```cpp
auto it = mp.lower_bound(25);
```

Result:

```text
30
```

This is extremely useful in ordered data problems.

---

# 73. Example: First Key Greater Than X

Suppose:

```text
Keys:

10 20 30 40 50
```

We want first key:

```text
> 30
```

Use:

```cpp
auto it = mp.upper_bound(30);
```

Result:

```text
40
```

---

# 74. Important `lower_bound()` Edge Case

Always check:

```cpp
if (it != mp.end())
```

because `lower_bound()` can return:

```cpp
mp.end()
```

Example:

```cpp
auto it = mp.lower_bound(1000);

if (it == mp.end()) {

    cout << "No key >= 1000";
}
```

---

# 75. Important `map` Safety Pattern

Before:

```cpp
mp.begin()
```

or:

```cpp
mp.rbegin()
```

make sure the map isn't empty.

Example:

```cpp
if (!mp.empty()) {

    cout << mp.begin()->first;
}
```

Otherwise, accessing the element of an empty map is invalid.

---

# 76. `erase()` While Iterating

If you need to erase a particular key:

```cpp
auto it = mp.find(20);

if (it != mp.end()) {

    mp.erase(it);
}
```

For multiple elements, be careful with iterator invalidation.

A safe pattern for erasing while iterating is:

```cpp
for (auto it = mp.begin();
     it != mp.end(); ) {

    if (it->second == 0) {

        it = mp.erase(it);

    }
    else {

        ++it;
    }
}
```

Here `erase()` returns the iterator pointing to the next element.

---

# 77. Map of String to Integer

Very common:

```cpp
map<string, int> mp;
```

Example:

```cpp
mp["apple"] = 5;
mp["banana"] = 3;
mp["mango"] = 10;
```

Now:

```cpp
cout << mp["mango"];
```

gives:

```text
10
```

And iteration is lexicographically sorted:

```text
apple
banana
mango
```

---

# 78. Nested Map

Maps can also contain maps.

Example:

```cpp
map<int, map<int, int>> mp;
```

This can represent:

```text
row → column → value
```

Example:

```cpp
mp[1][2] = 100;
mp[1][3] = 200;
mp[2][1] = 300;
```

Conceptually:

```text
Row 1:
    Column 2 → 100
    Column 3 → 200

Row 2:
    Column 1 → 300
```

Useful in some matrix/grid and graph problems.

---

# 79. Map with Vector as Value

You can also have:

```cpp
map<int, vector<int>> mp;
```

Example:

```cpp
mp[1].push_back(10);
mp[1].push_back(20);

mp[2].push_back(30);
```

Result:

```text
1 → [10, 20]
2 → [30]
```

This is useful for grouping data.

---

# 80. Map with Set as Value

Similarly:

```cpp
map<int, set<int>> mp;
```

Example:

```cpp
mp[1].insert(10);
mp[1].insert(20);

mp[2].insert(30);
```

Useful when each key needs a collection of unique sorted values.

---

# 81. Custom Comparator for Map

By default:

```cpp
map<int, string> mp;
```

stores keys in ascending order.

We can change the ordering.

For descending keys:

```cpp
map<int, string, greater<int>> mp;
```

Now:

```text
50
40
30
20
10
```

instead of:

```text
10
20
30
40
50
```

---

# 82. Descending Order Map

Example:

```cpp
map<int, string, greater<int>> mp;

mp[10] = "A";
mp[50] = "B";
mp[20] = "C";

for (auto [key, value] : mp) {

    cout << key << " "
         << value << endl;
}
```

Output:

```text
50 B
20 C
10 A
```

The comparator controls key ordering.

---

# 83. Custom Comparator Structure

We can also define our own comparator.

```cpp
struct Compare {

    bool operator()(int a, int b) const {

        return a > b;
    }
};
```

Then:

```cpp
map<int, string, Compare> mp;
```

This produces descending key order.

---

# 84. Map of Pairs

You can also have:

```cpp
map<int, pair<int, int>> mp;
```

Example:

```cpp
mp[1] = {10, 20};
mp[2] = {30, 40};
```

Now:

```text
1 → (10, 20)
2 → (30, 40)
```

Access:

```cpp
cout << mp[1].first;
cout << mp[1].second;
```

---

# 85. Complete Frequency Counting Program

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> nums = {
        10, 20, 10, 30, 20, 10
    };


    // ============================================================
    // FREQUENCY MAP
    // ============================================================

    // key   = number
    // value = frequency

    map<int, int> freq;


    // Count frequency.

    for (int x : nums) {

        freq[x]++;
    }


    // Print frequencies.

    for (auto [value, count] : freq) {

        cout << value
             << " → "
             << count
             << endl;
    }


    return 0;
}
```

Output:

```text
10 → 3
20 → 2
30 → 1
```

---

# 86. Complete Map Notes Program

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

    // ============================================================
    // CREATE MAP
    // ============================================================

    map<int, string> mp;


    // ============================================================
    // INSERT
    // ============================================================

    mp[30] = "Priya";
    mp[10] = "Rahul";
    mp[20] = "Aman";


    // ============================================================
    // ACCESS
    // ============================================================

    cout << "Key 10: "
         << mp[10]
         << endl;


    // ============================================================
    // INSERT USING insert()
    // ============================================================

    mp.insert({40, "Riya"});


    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size: "
         << mp.size()
         << endl;


    // ============================================================
    // FIND
    // ============================================================

    auto it = mp.find(20);

    if (it != mp.end()) {

        cout << "Found: "
             << it->first
             << " -> "
             << it->second
             << endl;
    }


    // ============================================================
    // COUNT
    // ============================================================

    if (mp.count(30)) {

        cout << "Key 30 exists"
             << endl;
    }


    // ============================================================
    // LOWER BOUND
    // ============================================================

    auto lb = mp.lower_bound(15);

    if (lb != mp.end()) {

        cout << "Lower bound of 15: "
             << lb->first
             << endl;
    }


    // ============================================================
    // UPPER BOUND
    // ============================================================

    auto ub = mp.upper_bound(20);

    if (ub != mp.end()) {

        cout << "Upper bound of 20: "
             << ub->first
             << endl;
    }


    // ============================================================
    // ITERATE
    // ============================================================

    cout << "Map elements:" << endl;

    for (auto [key, value] : mp) {

        cout << key
             << " -> "
             << value
             << endl;
    }


    // ============================================================
    // ERASE
    // ============================================================

    mp.erase(20);


    // ============================================================
    // AFTER ERASE
    // ============================================================

    cout << "After erase:" << endl;

    for (auto [key, value] : mp) {

        cout << key
             << " -> "
             << value
             << endl;
    }


    return 0;
}
```

---

# 87. Important Interview Points

### Point 1

```cpp
map<int, int> mp;
```

stores:

```text
key → value
```

---

### Point 2

`map` stores keys in sorted order by default.

```text
ascending order
```

---

### Point 3

Duplicate keys are not allowed.

```text
One key → One value
```

---

### Point 4

```cpp
mp[key]
```

can create the key if it doesn't exist.

---

### Point 5

```cpp
mp.find(key)
```

does not insert anything.

---

### Point 6

```cpp
mp.count(key)
```

returns:

```text
0 or 1
```

for a normal `map`.

---

### Point 7

```cpp
mp.lower_bound(x)
```

means:

```text
first key >= x
```

---

### Point 8

```cpp
mp.upper_bound(x)
```

means:

```text
first key > x
```

---

### Point 9

Most tree-based map operations:

```text
O(log n)
```

---

### Point 10

`unordered_map` is different:

```text
map         → ordered
unordered_map → unordered
```

---

# 88. Quick Cheat Sheet

```cpp
#include <map>
```

### Create

```cpp
map<int, int> mp;
```

### Insert / Update

```cpp
mp[key] = value;
```

### Insert without replacing existing key

```cpp
mp.insert({key, value});
```

### Access

```cpp
mp[key];
```

### Checked access

```cpp
mp.at(key);
```

### Search

```cpp
mp.find(key);
```

### Check existence

```cpp
mp.count(key);
```

### Erase

```cpp
mp.erase(key);
```

### Size

```cpp
mp.size();
```

### Empty

```cpp
mp.empty();
```

### Clear

```cpp
mp.clear();
```

### Lower Bound

```cpp
mp.lower_bound(key);
```

### Upper Bound

```cpp
mp.upper_bound(key);
```

### First / Minimum Key

```cpp
mp.begin()->first;
```

### Last / Maximum Key

```cpp
mp.rbegin()->first;
```

### Traverse

```cpp
for (auto [key, value] : mp) {

    cout << key << " "
         << value << endl;
}
```

---

# 89. Final Mental Model

```text
                    MAP
                     |
                     ↓
                KEY → VALUE
                     |
                     ↓
              Keys are ordered
                     |
                     ↓
             Search / Insert
                     |
                     ↓
                  O(log n)
```

For example:

```text
10 → Rahul
20 → Aman
30 → Priya
```

Then:

```cpp
mp[20]
```

gives:

```text
Aman
```

And:

```cpp
mp.find(20)
```

finds:

```text
20 → Aman
```

---

# 90. One-Line Memory Tricks

```text
map
 ↓
Key → Value
```

```text
map
 ↓
Sorted Keys
```

```text
map
 ↓
Unique Keys
```

```text
mp[key]
 ↓
Access / Insert
```

```text
find(key)
 ↓
Search without insertion
```

```text
count(key)
 ↓
Exists?
```

```text
lower_bound(x)
 ↓
first key >= x
```

```text
upper_bound(x)
 ↓
first key > x
```

```text
erase(key)
 ↓
Remove key-value pair
```

---

# 91. Final DSA Revision

Whenever you see:

> "Store something against a key."

Think:

```cpp
map<Key, Value> mp;
```

Whenever you see:

> "Count frequency."

Think:

```cpp
map<int, int> freq;

for (int x : nums) {

    freq[x]++;
}
```

Whenever you see:

> "Need sorted keys."

Think:

```cpp
map<int, int> mp;
```

Whenever you see:

> "Find first key >= x."

Think:

```cpp
mp.lower_bound(x);
```

Whenever you see:

> "Find first key > x."

Think:

```cpp
mp.upper_bound(x);
```

Whenever you only need:

> "Does this key exist?"

Think:

```cpp
mp.count(x);
```

Whenever you need:

> "Find the actual key/value."

Think:

```cpp
mp.find(x);
```

---

# 92. Final 10-Second Revision

```text
MAP
 ↓
KEY → VALUE
 ↓
Keys are sorted
 ↓
Duplicate keys NOT allowed
 ↓
insert / find / erase
 ↓
O(log n)
```

Most important:

```cpp
map<int, int> mp;
```

Access:

```cpp
mp[key];
```

Search:

```cpp
mp.find(key);
```

Existence:

```cpp
mp.count(key);
```

Delete:

```cpp
mp.erase(key);
```

Sorted searching:

```cpp
mp.lower_bound(x);
mp.upper_bound(x);
```

Traversal:

```cpp
for (auto [key, value] : mp) {

    cout << key << " "
         << value << endl;
}
```

And the biggest difference to remember:

```text
map
 ↓
Ordered + O(log n)
```

```text
unordered_map
 ↓
Unordered + Average O(1)
```

**Bas — `map` ko DSA mein yaad rakhne ka core hai: `KEY → VALUE`, sorted keys, unique keys, aur generally `O(log n)` operations.**
