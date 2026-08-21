#include <iostream>
#include <utility> // pair, make_pair, swap, piecewise_construct
#include <tuple>   // get, tie, ignore, tuple
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>  // sort
#include <functional> // reference_wrapper
#include <typeinfo>

using namespace std;

/*
===============================================================================
                         C++ STL : std::pair
                    COMPLETE NOTES + OPERATIONS
===============================================================================

IMPORTANT IDEA
--------------

std::pair is an STL utility class/template used to store EXACTLY TWO values.

Syntax:

    pair<T1, T2> variableName;

Example:

    pair<int, string> student = {101, "Amit"};

Here:

    T1 = int
    T2 = string

    first  = 101
    second = "Amit"


VERY IMPORTANT:
--------------

pair is NOT a container like vector, deque, list, set or map.

Therefore pair DOES NOT have:

    push_back()
    push_front()
    pop_back()
    pop_front()
    insert()
    erase()
    clear()
    begin()
    end()
    capacity()
    reserve()

So if you ask "pair mein insertion / deletion / pop kaise karenge?":

    Directly pair ke liye ye operations EXIST NAHI karte.

A pair always contains two members:

    p.first
    p.second

You can MODIFY those two members, or REPLACE the whole pair.

For collection of pairs, use:

    vector<pair<int,int>>
    set<pair<int,int>>
    map<int,string>
    etc.

Then insertion/erase/pop are performed on the CONTAINER, not on pair itself.

===============================================================================
*/

int main()
{
    cout << "============================================================\n";
    cout << "                 STL std::pair - COMPLETE\n";
    cout << "============================================================\n\n";

    // ========================================================================
    // 1. CREATION OF A PAIR
    // ========================================================================

    /*
        Empty/default pair:

            pair<int, int> p;

        This creates:

            first  = 0
            second = 0

        for int/int because int is value-initialized.
    */

    pair<int, int> p1;

    cout << "1. DEFAULT CREATION\n";
    cout << "p1.first  = " << p1.first << '\n';
    cout << "p1.second = " << p1.second << "\n\n";

    // ========================================================================
    // 2. CREATION + INITIALIZATION USING {}
    // ========================================================================

    /*
        Most common modern syntax:

            pair<int, string> p = {101, "Amit"};

        first  -> int
        second -> string
    */

    pair<int, string> p2 = {101, "Amit"};

    cout << "2. INITIALIZATION USING {}\n";
    cout << p2.first << " " << p2.second << "\n\n";

    // ========================================================================
    // 3. CONSTRUCTOR STYLE
    // ========================================================================

    pair<int, string> p3(102, "Rahul");

    cout << "3. CONSTRUCTOR STYLE\n";
    cout << p3.first << " " << p3.second << "\n\n";

    // ========================================================================
    // 4. make_pair()
    // ========================================================================

    /*
        make_pair() automatically deduces the types.

            auto p = make_pair(10, "Amit");

        Type becomes approximately:

            pair<int, const char*>

        For std::string:

            auto p = make_pair(10, string("Amit"));
    */

    auto p4 = make_pair(103, string("Riya"));

    cout << "4. make_pair()\n";
    cout << p4.first << " " << p4.second << "\n\n";

    // ========================================================================
    // 5. DIFFERENT DATA TYPES IN PAIR
    // ========================================================================

    /*
        Pair ke dono types SAME hona zaroori nahi.

            pair<int, string>
            pair<string, double>
            pair<char, int>
            pair<bool, string>
            pair<vector<int>, string>
            pair<int, pair<int,int>>

        valid examples hain.
    */

    pair<string, double> price = {"Laptop", 59999.50};

    cout << "5. DIFFERENT DATA TYPES\n";
    cout << price.first << " = " << price.second << "\n\n";

    // ========================================================================
    // 6. ACCESSING first
    // ========================================================================

    /*
        first pair ka FIRST member hai.

            p.first

        Example:

            pair<int,string> p = {101,"Amit"};

            p.first  -> 101
            p.second -> Amit
    */

    cout << "6. ACCESS first\n";
    cout << "First = " << p2.first << "\n\n";

    // ========================================================================
    // 7. ACCESSING second
    // ========================================================================

    cout << "7. ACCESS second\n";
    cout << "Second = " << p2.second << "\n\n";

    // ========================================================================
    // 8. MODIFY first
    // ========================================================================

    /*
        Normal non-const pair ke first member ko modify kar sakte hain.
    */

    p2.first = 999;

    cout << "8. MODIFY first\n";
    cout << "New first = " << p2.first << "\n\n";

    // ========================================================================
    // 9. MODIFY second
    // ========================================================================

    p2.second = "Updated";

    cout << "9. MODIFY second\n";
    cout << "New second = " << p2.second << "\n\n";

    // ========================================================================
    // 10. REPLACE COMPLETE PAIR
    // ========================================================================

    /*
        Pair ko complete object ke roop mein bhi assign kar sakte hain.

            p = {value1, value2};

        ya:

            p = make_pair(value1, value2);
    */

    p2 = {101, "Amit"};

    cout << "10. COMPLETE PAIR ASSIGNMENT\n";
    cout << p2.first << " " << p2.second << "\n\n";

    // ========================================================================
    // 11. COPY CONSTRUCTOR / COPY
    // ========================================================================

    pair<int, string> original = {10, "Original"};

    pair<int, string> copied = original;

    cout << "11. COPY PAIR\n";
    cout << copied.first << " " << copied.second << "\n\n";

    // ========================================================================
    // 12. ASSIGN ONE PAIR TO ANOTHER
    // ========================================================================

    pair<int, string> destination;

    destination = original;

    cout << "12. PAIR ASSIGNMENT\n";
    cout << destination.first << " " << destination.second << "\n\n";

    // ========================================================================
    // 13. SWAP
    // ========================================================================

    /*
        pair::swap() dono pairs ke contents exchange karta hai.

            p1.swap(p2);

        Example:

            A = {10, "A"}
            B = {20, "B"}

        after A.swap(B):

            A = {20, "B"}
            B = {10, "A"}
    */

    pair<int, string> swapA = {10, "A"};
    pair<int, string> swapB = {20, "B"};

    cout << "13. BEFORE SWAP\n";
    cout << "swapA = " << swapA.first << " " << swapA.second << '\n';
    cout << "swapB = " << swapB.first << " " << swapB.second << '\n';

    swapA.swap(swapB);

    cout << "AFTER swapA.swap(swapB)\n";
    cout << "swapA = " << swapA.first << " " << swapA.second << '\n';
    cout << "swapB = " << swapB.first << " " << swapB.second << "\n\n";

    // ========================================================================
    // 14. std::swap()
    // ========================================================================

    /*
        Pair ko standard swap() function se bhi swap kar sakte hain.

            swap(a, b);
    */

    pair<int, int> swapC = {1, 2};
    pair<int, int> swapD = {3, 4};

    std::swap(swapC, swapD);

    cout << "14. std::swap()\n";
    cout << "swapC = " << swapC.first << " " << swapC.second << '\n';
    cout << "swapD = " << swapD.first << " " << swapD.second << "\n\n";

    // ========================================================================
    // 15. get<0>() AND get<1>()
    // ========================================================================

    /*
        <tuple> header se get<> use karke pair ke members access kar sakte hain.

            get<0>(p) -> first
            get<1>(p) -> second

        Important:
            index compile-time constant hona chahiye.
    */

    pair<int, string> getPair = {500, "Amit"};

    cout << "15. get<0>() and get<1>()\n";
    cout << "get<0> = " << get<0>(getPair) << '\n';
    cout << "get<1> = " << get<1>(getPair) << "\n\n";

    // ========================================================================
    // 16. MODIFY USING get<>
    // ========================================================================

    get<0>(getPair) = 600;
    get<1>(getPair) = "Rahul";

    cout << "16. MODIFY USING get<>()\n";
    cout << get<0>(getPair) << " " << get<1>(getPair) << "\n\n";

    // ========================================================================
    // 17. tie()
    // ========================================================================

    /*
        tie() pair ko existing variables mein unpack karne ka old/common way hai.

            int id;
            string name;

            tie(id, name) = p;

        Isse:
            id   = p.first
            name = p.second

        tie() C++11 se available hai.

        Ye structured binding ka alternative hai.
    */

    int id;
    string name;

    pair<int, string> tiePair = {101, "Amit"};

    tie(id, name) = tiePair;

    cout << "17. tie()\n";
    cout << "id = " << id << '\n';
    cout << "name = " << name << "\n\n";

    // ========================================================================
    // 18. tie() WITH ignore
    // ========================================================================

    /*
        Agar pair ka sirf ek member chahiye:

            tie(id, ignore) = p;

        Yahan second value ignore ho jayegi.
    */

    tie(id, ignore) = tiePair;

    cout << "18. tie() + ignore\n";
    cout << "Only id = " << id << "\n\n";

    // ========================================================================
    // 19. NESTED PAIR
    // ========================================================================

    /*
        Pair ke andar pair bhi ho sakta hai.

            pair<int, pair<int,int>>

        Example:

            {1, {10,20}}

        Access:

            p.first
            p.second.first
            p.second.second
    */

    pair<int, pair<int, int>> nested = {1, {10, 20}};

    cout << "19. NESTED PAIR\n";
    cout << "Outer first   = " << nested.first << '\n';
    cout << "Inner first   = " << nested.second.first << '\n';
    cout << "Inner second  = " << nested.second.second << "\n\n";

    // ========================================================================
    // 20. pair<pair<int,int>, pair<int,int>>
    // ========================================================================

    pair<pair<int, int>, pair<int, int>> nested2 =
        {
            {10, 20},
            {30, 40}};

    cout << "20. PAIR OF PAIRS\n";
    cout << nested2.first.first << " ";
    cout << nested2.first.second << " ";
    cout << nested2.second.first << " ";
    cout << nested2.second.second << "\n\n";

    // ========================================================================
    // 21. vector<pair<int,int>>
    // ========================================================================

    /*
        VERY IMPORTANT FOR DSA.

        Pair khud container nahi hai.

        Lekin vector ke andar pairs store kar sakte hain:

            vector<pair<int,int>>

        Ab vector ke paas:
            push_back()
            pop_back()
            insert()
            erase()
            clear()
            begin()
            end()
            etc.

        Ye functions VECTOR ke hain, pair ke nahi.
    */

    vector<pair<int, int>> vp;

    cout << "21. vector<pair<int,int>>\n";

    // INSERT / ADD PAIR AT END
    vp.push_back({10, 20});
    vp.push_back({30, 40});
    vp.push_back({50, 60});

    cout << "After push_back:\n";

    for (const pair<int, int> &x : vp)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 22. vector<pair> - emplace_back()
    // ========================================================================

    /*
        vector ka emplace_back() pair ko construct karke end mein add karta hai.

        Example:

            vp.emplace_back(70, 80);

        Important:
            emplace_back() pair ka function nahi hai.
            Ye VECTOR ka function hai.
    */

    vp.emplace_back(70, 80);

    cout << "22. vector<pair> + emplace_back()\n";

    for (const pair<int, int> &x : vp)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 23. vector<pair> - insert()
    // ========================================================================

    /*
        vector ke kisi position par pair insert kar sakte hain.

            vp.insert(vp.begin() + 1, {15, 25});
    */

    vp.insert(vp.begin() + 1, {15, 25});

    cout << "23. vector<pair> + insert()\n";

    for (const pair<int, int> &x : vp)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 24. vector<pair> - erase()
    // ========================================================================

    /*
        vector ke iterator se pair erase kar sakte hain.

            vp.erase(vp.begin() + 1);

        Again:
            erase() pair ka function nahi hai.
            erase() vector ka function hai.
    */

    vp.erase(vp.begin() + 1);

    cout << "24. vector<pair> + erase()\n";

    for (const pair<int, int> &x : vp)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 25. vector<pair> - pop_back()
    // ========================================================================

    /*
        Pair ko vector ke last se remove karna:

            vp.pop_back();

        Ye last PAIR remove karega.

        Again:
            pop_back() pair ka function nahi hai.
            Ye vector ka function hai.
    */

    vp.pop_back();

    cout << "25. vector<pair> + pop_back()\n";

    for (const pair<int, int> &x : vp)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 26. vector<pair> - size()
    // ========================================================================

    cout << "26. vector<pair> + size()\n";
    cout << "Number of pairs = " << vp.size() << "\n\n";

    // ========================================================================
    // 27. vector<pair> - empty()
    // ========================================================================

    cout << "27. vector<pair> + empty()\n";

    if (vp.empty())
        cout << "Vector is empty\n";
    else
        cout << "Vector is not empty\n";

    cout << '\n';

    // ========================================================================
    // 28. PAIR COMPARISON
    // ========================================================================

    /*
        Pairs lexicographically compare hote hain.

        First:
            first compare hota hai.

        Agar first equal ho:
            second compare hota hai.

        Example:

            A = {10, 20}
            B = {10, 30}

        first:
            10 == 10

        second:
            20 < 30

        Therefore:

            A < B  -> true
    */

    pair<int, int> pairA = {10, 20};
    pair<int, int> pairB = {10, 30};

    cout << "28. PAIR COMPARISON\n";

    cout << "pairA < pairB  = " << (pairA < pairB) << '\n';
    cout << "pairA == pairB = " << (pairA == pairB) << '\n';
    cout << "pairA != pairB = " << (pairA != pairB) << "\n\n";

    // ========================================================================
    // 29. ALL COMMON RELATIONAL OPERATORS
    // ========================================================================

    /*
        Depending on C++ standard/library support, pair relational
        operators include:

            ==
            !=
            <
            >
            <=
            >=

        Comparison lexicographical order follow karti hai.
    */

    cout << "29. RELATIONAL OPERATORS\n";

    cout << "A == B : " << (pairA == pairB) << '\n';
    cout << "A != B : " << (pairA != pairB) << '\n';
    cout << "A <  B : " << (pairA < pairB) << '\n';
    cout << "A >  B : " << (pairA > pairB) << '\n';
    cout << "A <= B : " << (pairA <= pairB) << '\n';
    cout << "A >= B : " << (pairA >= pairB) << "\n\n";

    // ========================================================================
    // 30. SORTING vector<pair>
    // ========================================================================

    /*
        Default sort():

            sort(v.begin(), v.end());

        pair ko lexicographically sort karta hai.

        First values ascending.

        If first values equal:
            second values ascending.
    */

    vector<pair<int, int>> sortPairs =
        {
            {2, 50},
            {1, 100},
            {2, 20},
            {1, 10}};

    sort(sortPairs.begin(), sortPairs.end());

    cout << "30. SORTING PAIRS\n";

    for (const pair<int, int> &x : sortPairs)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 31. SORTING BY SECOND VALUE
    // ========================================================================

    /*
        Agar second ke according sort karna hai,
        custom comparator use kar sakte hain.

            [](const pair<int,int>& a,
               const pair<int,int>& b)
            {
                return a.second < b.second;
            }
    */

    sort(sortPairs.begin(), sortPairs.end(),
         [](const pair<int, int> &left,
            const pair<int, int> &right)
         {
             return left.second < right.second;
         });

    cout << "31. SORT BY SECOND VALUE\n";

    for (const pair<int, int> &x : sortPairs)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 32. SORT BY FIRST, THEN SECOND
    // ========================================================================

    /*
        Default pair sorting already does:

            first ascending
            then second ascending
    */

    sort(sortPairs.begin(), sortPairs.end());

    cout << "32. SORT BY FIRST THEN SECOND\n";

    for (const pair<int, int> &x : sortPairs)
    {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 33. MAP AND PAIR
    // ========================================================================

    /*
        map ke elements pair-like objects hote hain:

            pair<const Key, Value>

        Example:

            map<int,string>

        Each element contains:

            first  -> key
            second -> value
    */

    map<int, string> students;

    students.insert({101, "Amit"});
    students.insert({102, "Rahul"});
    students.insert({103, "Riya"});

    cout << "33. MAP INSERT\n";

    for (const pair<const int, string> &x : students)
    {
        cout << x.first << " -> " << x.second << '\n';
    }

    cout << '\n';

    // ========================================================================
    // 34. MAP - insert()
    // ========================================================================

    /*
        map mein pair insert kar sakte hain:

            students.insert({104, "Neha"});

        Here the pair is the map element.
    */

    students.insert(make_pair(104, "Neha"));

    cout << "34. MAP + insert(make_pair())\n";

    for (const pair<const int, string> &x : students)
    {
        cout << x.first << " -> " << x.second << '\n';
    }

    cout << '\n';

    // ========================================================================
    // 35. MAP - emplace()
    // ========================================================================

    /*
        map::emplace() element ko construct karke insert karta hai.

            students.emplace(105, "Karan");

        Ye map ka operation hai.
    */

    students.emplace(105, "Karan");

    cout << "35. MAP + emplace()\n";

    for (const pair<const int, string> &x : students)
    {
        cout << x.first << " -> " << x.second << '\n';
    }

    cout << '\n';

    // ========================================================================
    // 36. MAP - erase()
    // ========================================================================

    /*
        Map ke pair ko key ke through erase kar sakte hain:

            students.erase(102);

        Isse key 102 wala pair remove hoga.
    */

    students.erase(102);

    cout << "36. MAP + erase(key)\n";

    for (const pair<const int, string> &x : students)
    {
        cout << x.first << " -> " << x.second << '\n';
    }

    cout << '\n';

    // ========================================================================
    // 37. MAP - erase(iterator)
    // ========================================================================

    /*
        Iterator se bhi pair erase kar sakte hain.
    */

    map<int, string>::iterator mapIt = students.find(103);

    if (mapIt != students.end())
    {
        students.erase(mapIt);
    }

    cout << "37. MAP + erase(iterator)\n";

    for (const pair<const int, string> &x : students)
    {
        cout << x.first << " -> " << x.second << '\n';
    }

    cout << '\n';

    // ========================================================================
    // 38. MAP - find()
    // ========================================================================

    /*
        find() key ko search karta hai.

        Agar mil gaya:
            iterator returned.

        Agar nahi mila:
            end() returned.
    */

    map<int, string>::iterator found = students.find(101);

    cout << "38. MAP + find()\n";

    if (found != students.end())
    {
        cout << "Found: "
             << found->first
             << " -> "
             << found->second
             << '\n';
    }

    cout << '\n';

    // ========================================================================
    // 39. MAP - pop_back() / pop_front() IMPORTANT
    // ========================================================================

    /*
        IMPORTANT:

        std::map mein:

            pop_back()
            pop_front()

        nahi hote.

        std::pair mein bhi:

            pop_back()
            pop_front()

        nahi hote.

        Map elements remove karne ke liye:

            erase()

        use karo.

        Sequence containers jaise vector/deque mein pop_back()
        available hota hai.

        std::pair mein koi pop operation nahi hota.
    */

    // ========================================================================
    // 40. PAIR HAS NO insert()
    // ========================================================================

    /*
        Ye WRONG hai:

            pair<int,int> p;
            p.insert({10,20});      // ERROR

        Reason:

            pair already exactly TWO members rakhta hai.

        Ismein third element insert karne ki concept hi nahi hai.

        Correct:

            p.first = 10;
            p.second = 20;

        OR:

            p = {10,20};
    */

    // ========================================================================
    // 41. PAIR HAS NO erase()
    // ========================================================================

    /*
        Ye WRONG hai:

            p.erase(...);

        Pair ka erase() function nahi hota.

        Agar first/second ko "remove" karna hai,
        technically member ko erase nahi kar sakte.

        Pair ki structure hamesha:

            first
            second

        hi rahegi.

        You can only:
            - replace first
            - replace second
            - replace complete pair
            - destroy/reassign the pair object
    */

    // ========================================================================
    // 42. PAIR HAS NO clear()
    // ========================================================================

    /*
        pair mein:

            clear()

        bhi nahi hota.

        Agar pair ko reset karna ho:

            p = {};

        ya appropriate values assign karo.

        Example:

            pair<int,string> p = {100,"Amit"};

            p = {0, ""};
    */

    pair<int, string> resetPair = {100, "Amit"};

    resetPair = {0, ""};

    cout << "42. RESET/REASSIGN PAIR\n";
    cout << resetPair.first << " " << resetPair.second << "\n\n";

    // ========================================================================
    // 43. pair::swap()
    // ========================================================================

    /*
        swap() pair ka actual member function hai.

            p1.swap(p2);

        Complexity generally O(1) conceptually, depending on the
        operations required by the two contained types.
    */

    pair<string, string> names1 = {"Amit", "Sharma"};
    pair<string, string> names2 = {"Rahul", "Verma"};

    names1.swap(names2);

    cout << "43. pair::swap()\n";
    cout << "names1 = " << names1.first << " " << names1.second << '\n';
    cout << "names2 = " << names2.first << " " << names2.second << "\n\n";

    // ========================================================================
    // 44. pair WITH vector - iterator
    // ========================================================================

    /*
        vector<pair<int,int>>::iterator

        current element ko point karega.

        Iterator ke through:

            it->first
            it->second
    */

    vector<pair<int, int>> iteratorPairs =
        {
            {10, 20},
            {30, 40},
            {50, 60}};

    cout << "44. VECTOR OF PAIRS + ITERATOR\n";

    for (vector<pair<int, int>>::iterator it = iteratorPairs.begin();
         it != iteratorPairs.end();
         ++it)
    {
        cout << it->first << " "
             << it->second
             << '\n';
    }

    cout << '\n';

    // ========================================================================
    // 45. PAIR OF STRING + INT : FREQUENCY PATTERN
    // ========================================================================

    /*
        DSA mein common:

            pair<string,int>

        Example:

            {"apple", 5}

        Means:

            word = apple
            frequency = 5
    */

    pair<string, int> frequency = {"apple", 5};

    cout << "45. FREQUENCY PAIR\n";
    cout << frequency.first
         << " occurs "
         << frequency.second
         << " times\n\n";

    // ========================================================================
    // 46. PAIR FOR COORDINATES
    // ========================================================================

    /*
        2D coordinates ke liye:

            pair<int,int>

        first  -> x
        second -> y
    */

    pair<int, int> point = {10, 20};

    cout << "46. COORDINATE PAIR\n";
    cout << "x = " << point.first << '\n';
    cout << "y = " << point.second << "\n\n";

    // ========================================================================
    // 47. PAIR FOR RANGE / INTERVAL
    // ========================================================================

    /*
        Interval:

            {start, end}

        Example:

            {10, 50}

        means range [10, 50].
    */

    pair<int, int> interval = {10, 50};

    cout << "47. RANGE PAIR\n";
    cout << "Start = " << interval.first << '\n';
    cout << "End   = " << interval.second << "\n\n";

    // ========================================================================
    // 48. PAIR FOR GRAPH EDGE
    // ========================================================================

    /*
        Graph mein:

            pair<int,int>

        can represent:

            {u, v}

        i.e.

            edge from u to v.
    */

    pair<int, int> edge = {1, 2};

    cout << "48. GRAPH EDGE PAIR\n";
    cout << edge.first
         << " -> "
         << edge.second
         << "\n\n";

    // ========================================================================
    // 49. WEIGHTED GRAPH PATTERN
    // ========================================================================

    /*
        Weighted graph / Dijkstra type problems mein common:

            pair<int,int>

        Example:

            {weight, node}

        Example:

            {5, 10}

        means:

            weight = 5
            node   = 10
    */

    pair<int, int> weightedEdge = {5, 10};

    cout << "49. WEIGHTED EDGE PAIR\n";
    cout << "Weight = " << weightedEdge.first << '\n';
    cout << "Node   = " << weightedEdge.second << "\n\n";

    // ========================================================================
    // 50. PRIORITY QUEUE + PAIR CONCEPT
    // ========================================================================

    /*
        Priority queue mein bhi pair frequently use hota hai.

        Example type:

            priority_queue<pair<int,int>>

        Pair comparison ki wajah se priority queue pairs ko
        lexicographical order ke according compare kar sakti hai.

        Iska practical use Dijkstra, scheduling, ranking etc. mein
        hota hai.

        Header <queue> required hota hai for actual priority_queue.
    */

    // ========================================================================
    // 51. SET OF PAIRS
    // ========================================================================

    /*
        set<pair<int,int>>

        Pair ko set mein store kar sakte hain.

        Set automatically unique pairs ko maintain karega
        aur default ordering pair ki lexicographical ordering hoti hai.
    */

    set<pair<int, int>> pairSet;

    pairSet.insert({3, 30});
    pairSet.insert({1, 10});
    pairSet.insert({2, 20});

    cout << "51. SET OF PAIRS\n";

    for (const pair<int, int> &x : pairSet)
    {
        cout << "(" << x.first
             << ", " << x.second
             << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 52. SET OF PAIRS - erase()
    // ========================================================================

    /*
        set mein pair ko directly erase kar sakte hain:

            pairSet.erase({2,20});
    */

    pairSet.erase({2, 20});

    cout << "52. SET OF PAIRS + erase()\n";

    for (const pair<int, int> &x : pairSet)
    {
        cout << "(" << x.first
             << ", " << x.second
             << ") ";
    }

    cout << "\n\n";

    // ========================================================================
    // 53. PAIR OF PAIR : MORE THAN TWO VALUES
    // ========================================================================

    /*
        Pair itself exactly two values rakhta hai.

        But nested pair se more values represent kar sakte hain.

            pair<int, pair<int,int>>

        = 3 integer values.

        Example:

            {100, {200, 300}}

        Access:

            p.first
            p.second.first
            p.second.second
    */

    pair<int, pair<int, int>> threeValues = {100, {200, 300}};

    cout << "53. THREE VALUES USING NESTED PAIR\n";
    cout << threeValues.first << " "
         << threeValues.second.first << " "
         << threeValues.second.second
         << "\n\n";

    // ========================================================================
    // 54. PAIR WITH VECTOR
    // ========================================================================

    pair<vector<int>, string> vectorPair;

    vectorPair.first = {10, 20, 30};
    vectorPair.second = "Numbers";

    cout << "54. PAIR WITH VECTOR\n";
    cout << vectorPair.second << ": ";

    for (int x : vectorPair.first)
    {
        cout << x << " ";
    }

    cout << "\n\n";

    // ========================================================================
    // 55. pair::swap() WITH DIFFERENT DATA
    // ========================================================================

    /*
        swap tabhi possible hai jab pair types compatible hon.

            pair<int,string>
            pair<int,string>

        easily swap honge.

        Completely unrelated pair types ko normal swap ke through
        interchange nahi kar sakte.
    */

    // ========================================================================
    // 56. CONST PAIR
    // ========================================================================

    /*
        const pair ko modify nahi kar sakte.

            const pair<int,int> p = {10,20};

        p.first = 100;     // ERROR
        p.second = 200;    // ERROR

        Read allowed:

            p.first
            p.second
    */

    const pair<int, int> constPair = {10, 20};

    cout << "56. CONST PAIR\n";
    cout << constPair.first
         << " "
         << constPair.second
         << "\n\n";

    // ========================================================================
    // 57. PAIR WITH POINTER
    // ========================================================================

    int value1 = 100;
    int value2 = 200;

    pair<int *, int *> pointerPair = {&value1, &value2};

    cout << "57. POINTER PAIR\n";
    cout << *pointerPair.first
         << " "
         << *pointerPair.second
         << "\n\n";

    // ========================================================================
    // 58. IMPORTANT: PAIR DOES NOT HAVE push_back()
    // ========================================================================

    /*
        WRONG:

            pair<int,int> p;
            p.push_back(10);       // ERROR

        Why?

            pair is not a sequence container.

        If you want multiple pairs:

            vector<pair<int,int>> v;

        Then:

            v.push_back({10,20});
    */

    // ========================================================================
    // 59. IMPORTANT: PAIR DOES NOT HAVE pop_back()
    // ========================================================================

    /*
        WRONG:

            pair<int,int> p;
            p.pop_back();          // ERROR

        Pair mein "last element" concept nahi hota.

        Pair has exactly:

            first
            second

        If you want to remove last PAIR from a collection:

            vector<pair<int,int>> v;
            v.pop_back();

        Here pop_back() belongs to vector.
    */

    // ========================================================================
    // 60. IMPORTANT: PAIR DOES NOT HAVE insert()
    // ========================================================================

    /*
        WRONG:

            p.insert(...);         // ERROR

        Pair mein new member insert nahi kar sakte.

        Pair ki capacity fixed = 2 members.

        To change values:

            p.first = ...
            p.second = ...

        To replace whole pair:

            p = {...};
    */

    // ========================================================================
    // 61. IMPORTANT: PAIR DOES NOT HAVE erase()
    // ========================================================================

    /*
        WRONG:

            p.erase(...);          // ERROR

        Pair ke member ko erase nahi kar sakte.

        If you need deletion from a collection of pairs:

            vector<pair<int,int>> -> erase()
            set<pair<int,int>>    -> erase()
            map<...>              -> erase()
    */

    // ========================================================================
    // 62. IMPORTANT: PAIR DOES NOT HAVE clear()
    // ========================================================================

    /*
        WRONG:

            p.clear();             // ERROR

        Pair ko reset/reassign kar sakte ho:

            p = {0, 0};

        or:

            p = {};
    */

    // ========================================================================
    // 63. IMPORTANT: PAIR DOES NOT HAVE begin()/end()
    // ========================================================================

    /*
        WRONG:

            p.begin();
            p.end();

        Pair directly iterable container nahi hai.

        Use:

            p.first
            p.second

        If you have:

            vector<pair<int,int>> v

        then:

            v.begin()
            v.end()

        valid hain.
    */

    // ========================================================================
    // 64. PAIR FUNCTION SUMMARY
    // ========================================================================

    /*
        REAL std::pair member/functions commonly used:

        1. first
        2. second
        3. swap()

        Construction / utility:
        4. pair<T1,T2>{...}
        5. make_pair(...)
        6. get<0>(p)
        7. get<1>(p)
        8. tie(...)

        Operators:
        9.  =
        10. ==
        11. !=
        12. <
        13. >
        14. <=
        15. >=

        IMPORTANT:
        Pair itself DOES NOT provide:

        16. push_back()
        17. push_front()
        18. pop_back()
        19. pop_front()
        20. insert()
        21. erase()
        22. clear()
        23. begin()
        24. end()
        25. empty()
        26. size()

        These are container operations, not pair operations.
    */

    // ========================================================================
    // 65. PAIR vs VECTOR OF PAIRS
    // ========================================================================

    /*
        VERY IMPORTANT DIFFERENCE:

        ---------------------------------------------------------------
        pair<int,int> p;
        ---------------------------------------------------------------

        Exactly two values:

            p.first
            p.second

        No:
            push_back
            pop_back
            insert
            erase
            clear


        ---------------------------------------------------------------
        vector<pair<int,int>> v;
        ---------------------------------------------------------------

        Multiple pairs:

            v.push_back({1,2});
            v.push_back({3,4});

        Has:

            push_back
            pop_back
            insert
            erase
            clear
            size
            empty
            begin
            end
            etc.

        So:

            pair = one fixed 2-value object

            vector<pair> = collection of many pair objects
    */

    // ========================================================================
    // 66. FINAL CHEAT SHEET
    // ========================================================================

    /*
        ============================================================
                         PAIR CHEAT SHEET
        ============================================================

        CREATE:
            pair<int,int> p;

        INITIALIZE:
            pair<int,int> p = {10,20};

        CONSTRUCTOR:
            pair<int,int> p(10,20);

        make_pair:
            auto p = make_pair(10,20);

        ACCESS:
            p.first
            p.second

        MODIFY:
            p.first = 100;
            p.second = 200;

        COMPLETE ASSIGNMENT:
            p = {10,20};

        COPY:
            pair<int,int> q = p;

        SWAP:
            p.swap(q);
            swap(p,q);

        get:
            get<0>(p);
            get<1>(p);

        tie:
            tie(a,b) = p;

        ignore:
            tie(a,ignore) = p;

        COMPARISON:
            p == q
            p != q
            p < q
            p > q
            p <= q
            p >= q

        NESTED:
            pair<int,pair<int,int>>

        VECTOR OF PAIRS:
            vector<pair<int,int>> v;

        ADD PAIR TO VECTOR:
            v.push_back({10,20});

        EMPLACE:
            v.emplace_back(10,20);

        INSERT:
            v.insert(v.begin(), {10,20});

        ERASE:
            v.erase(v.begin());

        POP:
            v.pop_back();

        MAP:
            map<int,string> m;

        MAP INSERT:
            m.insert({1,"Amit"});

        MAP EMPLACE:
            m.emplace(2,"Rahul");

        MAP ERASE:
            m.erase(1);

        MAP ITERATOR:
            it->first
            it->second

        SET OF PAIRS:
            set<pair<int,int>> s;

        SET INSERT:
            s.insert({1,2});

        SET ERASE:
            s.erase({1,2});

        ============================================================

        GOLDEN RULE:

        pair itself is NOT a container.

        Therefore:

            pair -> first + second

        For insertion/deletion/pop of MULTIPLE PAIRS:

            vector<pair<...>>
            set<pair<...>>
            map<...>

        ============================================================
    */

    cout << "============================================================\n";
    cout << "                 PAIR NOTES COMPLETED\n";
    cout << "============================================================\n";

    return 0;
}