# C++ STL `pair` — Complete Notes

## 1. `pair` क्या होता है?

C++ STL में `pair` एक ऐसा container है जिसका उपयोग दो values को एक साथ store करने के लिए किया जाता है।

इन दोनों values के data types same भी हो सकते हैं और अलग भी।

उदाहरण:

`pair<int, string>`

इसमें पहली value `int` और दूसरी value `string` हो सकती है।

जैसे:

`{10, "Rahul"}`

एक valid pair है।

---

# 2. `pair` का Syntax

`pair` बनाने का basic syntax है:

`pair<data_type1, data_type2> variable_name;`

उदाहरण:

`pair<int, int> p;`

इसमें दोनों values `int` type की होंगी।

दूसरा उदाहरण:

`pair<int, string> p;`

इसमें:

- `first` → `int`
- `second` → `string`

होगा।

---

# 3. `pair` में कितनी Values होती हैं?

एक `pair` में exactly दो values होती हैं।

इन दोनों values को `first` और `second` से access किया जाता है।

उदाहरण:

`pair<int, string> p = {10, "Rahul"};`

तो:

`p.first` → `10`

`p.second` → `"Rahul"`

याद रखने का आसान तरीका:

**pair = first + second**

---

# 4. `pair` को Initialize करना

सबसे simple तरीका:

`pair<int, string> p = {10, "Rahul"};`

अब pair के अंदर:

पहली value = `10`

दूसरी value = `"Rahul"`

है।

इन्हें print करने के लिए:

`cout << p.first << endl;`

`cout << p.second << endl;`

Output:

`10`

`Rahul`

---

# 5. `first` और `second`

हर pair के दो important members होते हैं:

## `first`

यह pair की पहली value को represent करता है।

## `second`

यह pair की दूसरी value को represent करता है।

उदाहरण:

`pair<int, int> p = {100, 200};`

तो:

`p.first = 100`

`p.second = 200`

अगर पहली value चाहिए:

`cout << p.first;`

अगर दूसरी value चाहिए:

`cout << p.second;`

---

# 6. `make_pair()`

C++ में pair बनाने के लिए `make_pair()` का भी उपयोग किया जा सकता है।

उदाहरण:

`pair<int, string> p;`

`p = make_pair(10, "Rahul");`

या सीधे:

`auto p = make_pair(10, "Rahul");`

यहाँ compiler automatically pair का type समझ लेता है।

इसका type होगा:

`pair<int, string>`

---

# 7. `pair` की Values को Change करना

Pair की values को बाद में modify किया जा सकता है।

उदाहरण:

`pair<int, string> p = {10, "Rahul"};`

अब:

`p.first = 20;`

`p.second = "Aman";`

अब pair होगा:

`{20, "Aman"}`

इसलिए `first` और `second` को read करने के साथ-साथ modify भी किया जा सकता है।

---

# 8. Different Data Types वाला `pair`

Pair की दोनों values का data type same होना जरूरी नहीं है।

उदाहरण:

`pair<int, string> p = {10, "Rahul"};`

यहाँ:

`int + string`

है।

दूसरा उदाहरण:

`pair<string, int> p = {"Age", 20};`

तीसरा उदाहरण:

`pair<int, double> p = {10, 99.5};`

चौथा उदाहरण:

`pair<char, bool> p = {'A', true};`

इसलिए pair का उपयोग अलग-अलग data types की दो values को एक unit की तरह store करने के लिए किया जाता है।

---

# 9. `pair<int, int>`

Competitive Programming में `pair<int, int>` बहुत ज्यादा इस्तेमाल होता है।

उदाहरण:

`pair<int, int> p = {10, 20};`

तो:

`p.first = 10`

`p.second = 20`

इसका उपयोग कई जगह किया जाता है:

- Coordinates
- Array index + value
- Node + distance
- Value + frequency
- Sorting
- Graph algorithms
- Priority Queue

---

# 10. Coordinates में `pair`

मान लीजिए हमें किसी point का `(x, y)` coordinate store करना है।

हम लिख सकते हैं:

`pair<int, int> point = {5, 10};`

यहाँ:

`point.first` → x-coordinate

`point.second` → y-coordinate

इसलिए:

`x = 5`

`y = 10`

Competitive Programming में coordinates store करने के लिए यह बहुत common तरीका है।

---

# 11. Array में `pair`

हम pairs का array भी बना सकते हैं।

उदाहरण:

`pair<int, int> arr[3];`

अब इसमें तीन pairs store किए जा सकते हैं।

`arr[0] = {1, 10};`

`arr[1] = {2, 20};`

`arr[2] = {3, 30};`

अगर पहली pair की first value चाहिए:

`arr[0].first`

Output:

`1`

अगर दूसरी pair की second value चाहिए:

`arr[1].second`

Output:

`20`

---

# 12. `vector` के साथ `pair`

STL में `vector<pair<int, int>>` बहुत important combination है।

Syntax:

`vector<pair<int, int>> v;`

इसका मतलब है:

एक vector जिसमें हर element एक pair होगा।

उदाहरण:

`v.push_back({10, 20});`

`v.push_back({30, 40});`

`v.push_back({50, 60});`

अब vector में तीन pairs हैं:

`{10, 20}`

`{30, 40}`

`{50, 60}`

पहली pair access करने के लिए:

`v[0]`

पहली pair की first value:

`v[0].first`

पहली pair की second value:

`v[0].second`

---

# 13. `vector<pair<int, int>>` को Traverse करना

हम normal loop से vector of pairs को traverse कर सकते हैं।

उदाहरण:

`for(int i = 0; i < v.size(); i++)`

`{`

`    cout << v[i].first << " " << v[i].second << endl;`

`}`

अगर vector है:

`{{10, 20}, {30, 40}, {50, 60}}`

तो output होगा:

`10 20`

`30 40`

`50 60`

---

# 14. Range-Based Loop के साथ `pair`

Range-based for loop में भी pair को आसानी से access कर सकते हैं।

उदाहरण:

`for(auto p : v)`

`{`

`    cout << p.first << " " << p.second << endl;`

`}`

यहाँ `p` हर बार vector के एक pair को represent करेगा।

---

# 15. Structured Binding के साथ `pair`

Modern C++ में pair को और आसानी से access करने के लिए structured binding का उपयोग किया जा सकता है।

उदाहरण:

`for(auto [first, second] : v)`

`{`

`    cout << first << " " << second << endl;`

`}`

यहाँ अलग से `p.first` और `p.second` लिखने की जरूरत नहीं है।

---

# 16. `pair` को Compare करना

C++ में pairs को compare भी किया जा सकता है।

Pair की comparison सामान्यतः:

**पहले `first` को compare करती है।**

अगर दोनों `first` बराबर हों, तो:

**`second` को compare किया जाता है।**

उदाहरण:

`pair<int, int> p1 = {10, 20};`

`pair<int, int> p2 = {10, 30};`

यहाँ दोनों का `first` बराबर है:

`10 == 10`

इसलिए `second` compare होगा:

`20 < 30`

इसलिए:

`p1 < p2`

true होगा।

---

# 17. Lexicographical Comparison

Pair की comparison को lexicographical comparison कहा जा सकता है।

उदाहरण:

`p1 = {1, 100}`

`p2 = {2, 10}`

पहले:

`1 < 2`

इसलिए `p1 < p2` true होगा।

यहाँ second value को compare करने की जरूरत नहीं पड़ेगी क्योंकि first values अलग हैं।

लेकिन:

`p1 = {1, 100}`

`p2 = {1, 200}`

यहाँ first values equal हैं।

इसलिए second values compare होंगी:

`100 < 200`

इसलिए:

`p1 < p2`

true होगा।

---

# 18. Sorting में `pair`

`pair` का सबसे important use sorting में होता है।

मान लीजिए:

`vector<pair<int, int>> v = {{3, 10}, {1, 20}, {2, 15}};`

अगर हम:

`sort(v.begin(), v.end());`

करते हैं, तो pairs ascending order में sort हो जाएँगे।

Result:

`{1, 20}`

`{2, 15}`

`{3, 10}`

क्योंकि सबसे पहले `first` value compare होती है।

---

# 19. अगर `first` Same हो तो?

अगर pairs हैं:

`{1, 50}`

`{1, 20}`

`{1, 30}`

तो `first` सभी में same है।

इस situation में `second` value के आधार पर sorting होगी।

Result:

`{1, 20}`

`{1, 30}`

`{1, 50}`

इसलिए default pair sorting का rule याद रखें:

**पहले first, फिर second।**

---

# 20. `pair` और `sort()` का Important Rule

Default sorting में:

1. `first` ascending order में आता है।
2. अगर `first` same है, तो `second` ascending order में आता है।

Example:

Input:

`{{3, 5}, {1, 10}, {3, 2}, {2, 8}}`

Sorted:

`{{1, 10}, {2, 8}, {3, 2}, {3, 5}}`

---

# 21. `pair` को Descending Order में Sort करना

अगर हमें pairs को descending order में sort करना है, तो:

`sort(v.rbegin(), v.rend());`

का उपयोग कर सकते हैं।

उदाहरण:

`vector<pair<int, int>> v = {{1, 10}, {3, 20}, {2, 15}};`

`sort(v.rbegin(), v.rend());`

Result:

`{3, 20}`

`{2, 15}`

`{1, 10}`

---

# 22. `pair` का Nested Pair

एक pair के अंदर दूसरा pair भी store किया जा सकता है।

उदाहरण:

`pair<int, pair<int, int>> p;`

इसमें structure होगा:

`first`

और

`second`

लेकिन `second` खुद एक pair होगा।

उदाहरण:

`pair<int, pair<int, int>> p = {1, {2, 3}};`

अब:

`p.first` → `1`

`p.second.first` → `2`

`p.second.second` → `3`

यह concept शुरुआत में थोड़ा confusing लग सकता है, लेकिन nested data structures में यह बहुत useful है।

---

# 23. `pair` का Real-Life Example

मान लीजिए किसी student की information में हमें:

Student ID

और

Student Name

store करना है।

हम लिख सकते हैं:

`pair<int, string> student = {101, "Rahul"};`

यहाँ:

`student.first` → Student ID

`student.second` → Student Name

इस प्रकार दो related values को एक साथ रखा जा सकता है।

---

# 24. Graph में `pair`

Graph Algorithms में pair का बहुत important role है।

मान लीजिए किसी graph में हमें:

`node`

और

`weight`

store करना है।

हम लिख सकते हैं:

`pair<int, int> edge = {5, 10};`

यह represent कर सकता है:

`node = 5`

`weight = 10`

Dijkstra जैसे algorithms में अक्सर:

`pair<distance, node>`

या

`pair<node, distance>`

जैसी representation दिखाई देती है।

---

# 25. Priority Queue में `pair`

Priority Queue के साथ भी pair बहुत commonly इस्तेमाल होता है।

उदाहरण:

`priority_queue<pair<int, int>> pq;`

इसमें pairs store किए जा सकते हैं।

उदाहरण:

`pq.push({10, 1});`

`pq.push({20, 2});`

`pq.push({5, 3});`

Default max-heap behavior में pair comparison के rules के अनुसार सबसे बड़ा pair top पर आएगा।

इसलिए pair का comparison rule priority queue में भी important हो जाता है।

---

# 26. `map` और `pair`

C++ का `map` internally key-value relationship के साथ काम करता है और iteration के दौरान elements pair के रूप में मिलते हैं।

उदाहरण:

`map<int, string> mp;`

`mp[1] = "Rahul";`

`mp[2] = "Aman";`

जब हम map को traverse करते हैं:

`for(auto p : mp)`

तो:

`p.first`

key होती है।

और:

`p.second`

value होती है।

उदाहरण:

`for(auto p : mp)`

`{`

`    cout << p.first << " " << p.second << endl;`

`}`

यहाँ pair concept बहुत naturally दिखाई देता है।

---

# 27. `pair` के फायदे

`pair` के मुख्य फायदे:

1. दो related values को एक साथ store कर सकते हैं।
2. दोनों values के data types अलग हो सकते हैं।
3. `first` और `second` से आसानी से access किया जा सकता है।
4. Sorting के साथ आसानी से काम करता है।
5. Vector के साथ बहुत useful है।
6. Map और Priority Queue जैसे STL containers के साथ commonly इस्तेमाल होता है।
7. Competitive Programming में बहुत ज्यादा उपयोग होता है।
8. Temporary data को एक साथ return करने के लिए भी उपयोगी है।

---

# 28. `pair` के Important Syntax

सबसे जरूरी syntax एक जगह:

`pair<int, int> p;`

`pair<int, string> p;`

`pair<string, int> p;`

`pair<int, int> p = {10, 20};`

`auto p = make_pair(10, "Rahul");`

`p.first`

`p.second`

`p.first = 100`

`p.second = 200`

---

# 29. Important Header File

अगर केवल pair use करना है:

`#include <utility>`

अगर Competitive Programming में:

`#include <bits/stdc++.h>`

use कर रहे हैं, तो pair भी उपलब्ध रहेगा।

साथ में:

`using namespace std;`

लिखने से `pair` को सीधे use कर सकते हैं।

---

# 30. Complete Example

एक simple complete program:

`#include <bits/stdc++.h>`

`using namespace std;`

`int main()`

`{`

`    pair<int, string> student = {101, "Rahul"};`

`    `

`    cout << "ID: " << student.first << endl;`

`    cout << "Name: " << student.second << endl;`

`    `

`    return 0;`

`}`

Output:

`ID: 101`

`Name: Rahul`

---

# 31. सबसे Important बात

C++ में `pair` को याद रखने के लिए केवल यह concept याद रखें:

**एक pair में exactly दो values होती हैं।**

पहली value:

`first`

दूसरी value:

`second`

उदाहरण:

`pair<int, string> p = {10, "Rahul"};`

तो:

`p.first` → `10`

`p.second` → `"Rahul"`

बस यही `pair` का core concept है।

---

# 32. Quick Revision

`pair` → दो values को एक साथ store करता है।

`first` → पहली value।

`second` → दूसरी value।

`make_pair()` → pair बनाने का function।

`pair<int, int>` → दो integers का pair।

`pair<int, string>` → integer + string।

`vector<pair<int,int>>` → pairs का vector।

`sort()` → pair को पहले `first`, फिर `second` के आधार पर sort करता है।

`p.first` → first value access।

`p.second` → second value access।

`p.first = value` → first value update।

`p.second = value` → second value update।

**Golden Rule:**

`pair = {first, second}`

और pair को देखते ही सबसे पहले याद करें:

**FIRST → पहली value**

**SECOND → दूसरी value**
