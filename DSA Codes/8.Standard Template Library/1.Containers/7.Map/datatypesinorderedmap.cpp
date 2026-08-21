/*
===============================================================================
                         C++ STL - ORDERED MAP
                    DIFFERENT DATA TYPES - COMPLETE COURSE
===============================================================================

TOPIC:
    Different Data Types That Can Be Used With std::map

HEADER:
    #include <map>

BASIC SYNTAX:

    map<KeyType, ValueType> mapName;

Example:

    map<int, string> mp;

Here:

    int
    ↓
    KEY TYPE

    string
    ↓
    VALUE TYPE


===============================================================================
WHAT IS std::map?
===============================================================================

std::map is an ASSOCIATIVE CONTAINER of the C++ STL.

It stores data in the form:

        KEY  --->  VALUE

Example:

        101 ---> "Amit"
        102 ---> "Rahul"
        103 ---> "Riya"


===============================================================================
IMPORTANT PROPERTIES OF std::map
===============================================================================

1. map stores data in KEY-VALUE form.

2. Every KEY must be UNIQUE.

3. VALUES can be duplicate.

4. Keys are maintained in SORTED ORDER.

5. By default, sorting is in ASCENDING ORDER.

6. map is generally implemented using a balanced tree
   (commonly a Red-Black Tree).

7. Search, insertion and deletion are generally:

        O(log n)

8. The KEY and VALUE can have DIFFERENT data types.

Example:

        map<int, string>

This means:

        integer ---> string


===============================================================================
GENERAL FORM
===============================================================================

        map<Key, Value>

The first type:

        Key

represents the key.

The second type:

        Value

represents the value.


Example:

        map<string, int>

means:

        string ---> int


Example:

        map<int, double>

means:

        int ---> double


===============================================================================
IMPORTANT KEY RULE
===============================================================================

The key type must support the ordering required by std::map.

For normal built-in data types this already works.

Common key types:

        int
        long long
        char
        bool
        float
        double
        string

Custom data types can also be used if an appropriate ordering
(comparison) is provided.


===============================================================================
IMPORTANT VALUE RULE
===============================================================================

The VALUE can be many different data types.

Examples:

        int
        long long
        float
        double
        char
        bool
        string
        pair
        vector
        another map
        etc.


===============================================================================
                    PART 1
             map<int, int>
===============================================================================
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{

    //==========================================================================
    // 1. map<int, int>
    //==========================================================================
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      int
    //
    // Therefore:
    //
    //      integer ---> integer
    //
    // Example:
    //
    //      number ---> square
    //
    //==========================================================================

    map<int, int> intIntMap;

    intIntMap[1] = 1;
    intIntMap[2] = 4;
    intIntMap[3] = 9;
    intIntMap[4] = 16;
    intIntMap[5] = 25;

    cout << "==================================================" << endl;
    cout << "1. map<int, int>" << endl;
    cout << "==================================================" << endl;

    for (map<int, int>::iterator it = intIntMap.begin();
         it != intIntMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    IMPORTANT:

        map stores keys in sorted order.

    We inserted:

        1
        2
        3
        4
        5

    So iteration gives:

        1 -> 1
        2 -> 4
        3 -> 9
        4 -> 16
        5 -> 25


    IMPORTANT DIFFERENCE FROM unordered_map:

        map
        ----
        Ordered

        unordered_map
        --------------
        Not ordered
    */

    //==========================================================================
    // 2. map<int, string>
    //==========================================================================
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      string
    //
    // Example:
    //
    //      Student ID ---> Student Name
    //
    //==========================================================================

    map<int, string> intStringMap;

    intStringMap[103] = "Riya";
    intStringMap[101] = "Amit";
    intStringMap[104] = "Neha";
    intStringMap[102] = "Rahul";

    cout << endl;
    cout << "==================================================" << endl;
    cout << "2. map<int, string>" << endl;
    cout << "==================================================" << endl;

    for (map<int, string>::iterator it =
             intStringMap.begin();
         it != intStringMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    Notice:

        We inserted:

            103
            101
            104
            102

    But map automatically keeps keys sorted:

            101
            102
            103
            104

    Therefore:

        map = ORDERED ASSOCIATIVE CONTAINER
    */

    //==========================================================================
    // 3. map<string, int>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      int
    //
    // Example:
    //
    //      Student Name ---> Marks
    //
    //==========================================================================

    map<string, int> stringIntMap;

    stringIntMap["Riya"] = 92;
    stringIntMap["Amit"] = 95;
    stringIntMap["Rahul"] = 88;
    stringIntMap["Neha"] = 85;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "3. map<string, int>" << endl;
    cout << "==================================================" << endl;

    for (map<string, int>::iterator it =
             stringIntMap.begin();
         it != stringIntMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    IMPORTANT:

        For string keys, map sorts keys lexicographically.

    Example:

        Amit
        Neha
        Rahul
        Riya

    So keys are arranged according to their ordering.
    */

    //==========================================================================
    // 4. map<string, string>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      string
    //
    // Example:
    //
    //      Country Code ---> Country Name
    //
    //==========================================================================

    map<string, string> stringStringMap;

    stringStringMap["us"] = "United States";
    stringStringMap["in"] = "India";
    stringStringMap["jp"] = "Japan";
    stringStringMap["br"] = "Brazil";
    stringStringMap["uk"] = "United Kingdom";

    cout << endl;
    cout << "==================================================" << endl;
    cout << "4. map<string, string>" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::iterator it =
             stringStringMap.begin();
         it != stringStringMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    COMMON USES:

        country code -> country name

        username -> email

        abbreviation -> full form

        word -> meaning

        employee code -> department
    */

    //==========================================================================
    // 5. map<char, int>
    //==========================================================================
    //
    // KEY:
    //      char
    //
    // VALUE:
    //      int
    //
    // Common use:
    //
    //      character ---> frequency
    //
    //==========================================================================

    map<char, int> charIntMap;

    charIntMap['d'] = 40;
    charIntMap['a'] = 10;
    charIntMap['c'] = 30;
    charIntMap['b'] = 20;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "5. map<char, int>" << endl;
    cout << "==================================================" << endl;

    for (map<char, int>::iterator it =
             charIntMap.begin();
         it != charIntMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    Since char values have an ordering:

        'a'
        'b'
        'c'
        'd'

    map keeps them in sorted order.
    */

    //==========================================================================
    // 6. map<char, string>
    //==========================================================================
    //
    // KEY:
    //      char
    //
    // VALUE:
    //      string
    //
    // Example:
    //
    //      Grade ---> Description
    //
    //==========================================================================

    map<char, string> charStringMap;

    charStringMap['C'] = "Good";
    charStringMap['A'] = "Excellent";
    charStringMap['D'] = "Average";
    charStringMap['B'] = "Very Good";

    cout << endl;
    cout << "==================================================" << endl;
    cout << "6. map<char, string>" << endl;
    cout << "==================================================" << endl;

    for (map<char, string>::iterator it =
             charStringMap.begin();
         it != charStringMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 7. map<int, char>
    //==========================================================================
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      char
    //
    // Example:
    //
    //      Number ---> Character
    //
    //==========================================================================

    map<int, char> intCharMap;

    intCharMap[3] = 'C';
    intCharMap[1] = 'A';
    intCharMap[4] = 'D';
    intCharMap[2] = 'B';

    cout << endl;
    cout << "==================================================" << endl;
    cout << "7. map<int, char>" << endl;
    cout << "==================================================" << endl;

    for (map<int, char>::iterator it =
             intCharMap.begin();
         it != intCharMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 8. map<int, double>
    //==========================================================================
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      double
    //
    // Example:
    //
    //      Product ID ---> Price
    //
    //==========================================================================

    map<int, double> intDoubleMap;

    intDoubleMap[103] = 2499.75;
    intDoubleMap[101] = 999.99;
    intDoubleMap[102] = 1499.50;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "8. map<int, double>" << endl;
    cout << "==================================================" << endl;

    for (map<int, double>::iterator it =
             intDoubleMap.begin();
         it != intDoubleMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 9. map<string, double>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      double
    //
    // Example:
    //
    //      Product Name ---> Price
    //
    //==========================================================================

    map<string, double> stringDoubleMap;

    stringDoubleMap["Laptop"] = 55000.50;
    stringDoubleMap["Phone"] = 25000.75;
    stringDoubleMap["Tablet"] = 18000.25;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "9. map<string, double>" << endl;
    cout << "==================================================" << endl;

    for (map<string, double>::iterator it =
             stringDoubleMap.begin();
         it != stringDoubleMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 10. map<int, float>
    //==========================================================================
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      float
    //
    // Example:
    //
    //      Product ID ---> Rating
    //
    //==========================================================================

    map<int, float> intFloatMap;

    intFloatMap[103] = 4.9f;
    intFloatMap[101] = 4.5f;
    intFloatMap[102] = 3.8f;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "10. map<int, float>" << endl;
    cout << "==================================================" << endl;

    for (map<int, float>::iterator it =
             intFloatMap.begin();
         it != intFloatMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 11. map<string, float>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      float
    //
    // Example:
    //
    //      Player ---> Rating
    //
    //==========================================================================

    map<string, float> stringFloatMap;

    stringFloatMap["Amit"] = 9.5f;
    stringFloatMap["Rahul"] = 8.7f;
    stringFloatMap["Riya"] = 9.1f;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "11. map<string, float>" << endl;
    cout << "==================================================" << endl;

    for (map<string, float>::iterator it =
             stringFloatMap.begin();
         it != stringFloatMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 12. map<long long, long long>
    //==========================================================================
    //
    // KEY:
    //      long long
    //
    // VALUE:
    //      long long
    //
    // Useful when both key and value can be very large.
    //
    //==========================================================================

    map<long long, long long> longLongMap;

    longLongMap[30000000000LL] = 90000000000LL;
    longLongMap[10000000000LL] = 50000000000LL;
    longLongMap[20000000000LL] = 70000000000LL;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "12. map<long long, long long>" << endl;
    cout << "==================================================" << endl;

    for (map<long long, long long>::iterator it =
             longLongMap.begin();
         it != longLongMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 13. map<long long, int>
    //==========================================================================
    //
    // KEY:
    //      long long
    //
    // VALUE:
    //      int
    //
    //==========================================================================

    map<long long, int> longLongIntMap;

    longLongIntMap[30000000000LL] = 30;
    longLongIntMap[10000000000LL] = 10;
    longLongIntMap[20000000000LL] = 20;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "13. map<long long, int>" << endl;
    cout << "==================================================" << endl;

    for (map<long long, int>::iterator it =
             longLongIntMap.begin();
         it != longLongIntMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    //==========================================================================
    // 14. map<bool, int>
    //==========================================================================
    //
    // KEY:
    //      bool
    //
    // VALUE:
    //      int
    //
    // bool has only two possible values:
    //
    //      false
    //      true
    //
    //==========================================================================

    map<bool, int> boolIntMap;

    boolIntMap[true] = 100;
    boolIntMap[false] = 200;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "14. map<bool, int>" << endl;
    cout << "==================================================" << endl;

    for (map<bool, int>::iterator it =
             boolIntMap.begin();
         it != boolIntMap.end();
         ++it)
    {
        cout << boolalpha;

        cout << it->first
             << " -> "
             << it->second
             << endl;

        cout << noboolalpha;
    }

    //==========================================================================
    // 15. map<string, bool>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      bool
    //
    // Example:
    //
    //      Student ---> Present / Absent
    //
    //==========================================================================

    map<string, bool> stringBoolMap;

    stringBoolMap["Amit"] = true;
    stringBoolMap["Rahul"] = false;
    stringBoolMap["Riya"] = true;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "15. map<string, bool>" << endl;
    cout << "==================================================" << endl;

    for (map<string, bool>::iterator it =
             stringBoolMap.begin();
         it != stringBoolMap.end();
         ++it)
    {
        cout << it->first
             << " -> ";

        if (it->second)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }

        cout << endl;
    }

    //==========================================================================
    // 16. map<int, pair<int, int>>
    //==========================================================================
    //
    // VERY IMPORTANT FOR DSA.
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      pair<int, int>
    //
    //
    // Meaning:
    //
    //      Student ID ---> (Math Marks, Physics Marks)
    //
    //==========================================================================

    map<int, pair<int, int>> intPairMap;

    intPairMap[103] = make_pair(95, 89);
    intPairMap[101] = make_pair(90, 85);
    intPairMap[102] = make_pair(88, 92);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "16. map<int, pair<int, int>>" << endl;
    cout << "==================================================" << endl;

    for (map<int, pair<int, int>>::iterator it =
             intPairMap.begin();
         it != intPairMap.end();
         ++it)
    {
        cout << "ID = "
             << it->first
             << " | First = "
             << it->second.first
             << " | Second = "
             << it->second.second
             << endl;
    }

    /*
    IMPORTANT:

        it->first

    is the map KEY.

        it->second

    is the pair.

    Therefore:

        it->second.first

    means first value inside pair.

    And:

        it->second.second

    means second value inside pair.
    */

    //==========================================================================
    // 17. map<string, pair<string, int>>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      pair<string, int>
    //
    // Example:
    //
    //      Student Name ---> (City, Age)
    //
    //==========================================================================

    map<string, pair<string, int>> stringPairMap;

    stringPairMap["Riya"] = make_pair("Mumbai", 20);
    stringPairMap["Amit"] = make_pair("Kanpur", 21);
    stringPairMap["Rahul"] = make_pair("Delhi", 22);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "17. map<string, pair<string, int>>" << endl;
    cout << "==================================================" << endl;

    for (map<string, pair<string, int>>::iterator it =
             stringPairMap.begin();
         it != stringPairMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second.first
             << ", "
             << it->second.second
             << endl;
    }

    //==========================================================================
    // 18. map<int, vector<int>>
    //==========================================================================
    //
    // VERY IMPORTANT FOR GRAPH DSA.
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      vector<int>
    //
    // Meaning:
    //
    //      Node ---> List of connected nodes
    //
    //==========================================================================

    map<int, vector<int>> intVectorMap;

    intVectorMap[1].push_back(2);
    intVectorMap[1].push_back(3);

    intVectorMap[2].push_back(1);
    intVectorMap[2].push_back(4);

    intVectorMap[3].push_back(1);

    intVectorMap[4].push_back(2);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "18. map<int, vector<int>>" << endl;
    cout << "==================================================" << endl;

    for (map<int, vector<int>>::iterator it =
             intVectorMap.begin();
         it != intVectorMap.end();
         ++it)
    {
        cout << it->first
             << " -> ";

        for (vector<int>::iterator vit =
                 it->second.begin();
             vit != it->second.end();
             ++vit)
        {
            cout << *vit << " ";
        }

        cout << endl;
    }

    //==========================================================================
    // 19. map<string, vector<string>>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      vector<string>
    //
    // Example:
    //
    //      Country ---> Cities
    //
    //==========================================================================

    map<string, vector<string>> stringVectorMap;

    stringVectorMap["India"].push_back("Kanpur");
    stringVectorMap["India"].push_back("Delhi");
    stringVectorMap["India"].push_back("Mumbai");

    stringVectorMap["USA"].push_back("New York");
    stringVectorMap["USA"].push_back("Chicago");

    cout << endl;
    cout << "==================================================" << endl;
    cout << "19. map<string, vector<string>>" << endl;
    cout << "==================================================" << endl;

    for (map<string, vector<string>>::iterator it =
             stringVectorMap.begin();
         it != stringVectorMap.end();
         ++it)
    {
        cout << it->first
             << " -> ";

        for (vector<string>::iterator vit =
                 it->second.begin();
             vit != it->second.end();
             ++vit)
        {
            cout << *vit << " ";
        }

        cout << endl;
    }

    //==========================================================================
    // 20. map<char, vector<int>>
    //==========================================================================
    //
    // KEY:
    //      char
    //
    // VALUE:
    //      vector<int>
    //
    // Example:
    //
    //      Character ---> Positions
    //
    //==========================================================================

    map<char, vector<int>> charVectorMap;

    charVectorMap['a'].push_back(0);
    charVectorMap['a'].push_back(2);
    charVectorMap['a'].push_back(5);

    charVectorMap['b'].push_back(1);
    charVectorMap['b'].push_back(4);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "20. map<char, vector<int>>" << endl;
    cout << "==================================================" << endl;

    for (map<char, vector<int>>::iterator it =
             charVectorMap.begin();
         it != charVectorMap.end();
         ++it)
    {
        cout << it->first
             << " -> ";

        for (vector<int>::iterator vit =
                 it->second.begin();
             vit != it->second.end();
             ++vit)
        {
            cout << *vit << " ";
        }

        cout << endl;
    }

    //==========================================================================
    // 21. map<int, vector<pair<int, int>>>
    //==========================================================================
    //
    // ADVANCED DSA COMBINATION.
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      vector<pair<int,int>>
    //
    //
    // Commonly used for:
    //
    //      Weighted Graph
    //
    //
    // Example:
    //
    //      1 -> {(2,5), (3,10)}
    //
    // Meaning:
    //
    //      Edge 1 -> 2 has weight 5
    //      Edge 1 -> 3 has weight 10
    //
    //==========================================================================

    map<int, vector<pair<int, int>>> weightedGraph;

    weightedGraph[1].push_back(make_pair(2, 5));
    weightedGraph[1].push_back(make_pair(3, 10));

    weightedGraph[2].push_back(make_pair(4, 7));
    weightedGraph[3].push_back(make_pair(4, 3));

    cout << endl;
    cout << "==================================================" << endl;
    cout << "21. map<int, vector<pair<int,int>>>" << endl;
    cout << "==================================================" << endl;

    for (map<int, vector<pair<int, int>>>::iterator it =
             weightedGraph.begin();
         it != weightedGraph.end();
         ++it)
    {
        cout << it->first
             << " -> ";

        for (vector<pair<int, int>>::iterator vit =
                 it->second.begin();
             vit != it->second.end();
             ++vit)
        {
            cout << "("
                 << vit->first
                 << ","
                 << vit->second
                 << ") ";
        }

        cout << endl;
    }

    //==========================================================================
    // 22. map<string, pair<int, double>>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      pair<int, double>
    //
    // Example:
    //
    //      Product ---> (Quantity, Price)
    //
    //==========================================================================

    map<string, pair<int, double>> productMap;

    productMap["Laptop"] = make_pair(2, 55000.50);
    productMap["Phone"] = make_pair(5, 25000.75);
    productMap["Tablet"] = make_pair(3, 18000.25);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "22. map<string, pair<int, double>>" << endl;
    cout << "==================================================" << endl;

    for (map<string, pair<int, double>>::iterator it =
             productMap.begin();
         it != productMap.end();
         ++it)
    {
        cout << it->first
             << " -> Quantity = "
             << it->second.first
             << ", Price = "
             << it->second.second
             << endl;
    }

    //==========================================================================
    // 23. NESTED map
    //==========================================================================
    //
    // A map can contain another map as its VALUE.
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      map<string, int>
    //
    //
    // Example:
    //
    //      Country ---> City ---> Population
    //
    //==========================================================================

    map<string, map<string, int>> nestedMap;

    nestedMap["India"]["Delhi"] = 20000000;
    nestedMap["India"]["Mumbai"] = 21000000;
    nestedMap["India"]["Kanpur"] = 3000000;

    nestedMap["USA"]["NewYork"] = 8000000;
    nestedMap["USA"]["Chicago"] = 2700000;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "23. NESTED map" << endl;
    cout << "==================================================" << endl;

    for (map<string, map<string, int>>::iterator outer =
             nestedMap.begin();
         outer != nestedMap.end();
         ++outer)
    {
        cout << outer->first << ":" << endl;

        for (map<string, int>::iterator inner =
                 outer->second.begin();
             inner != outer->second.end();
             ++inner)
        {
            cout << "    "
                 << inner->first
                 << " -> "
                 << inner->second
                 << endl;
        }
    }

    //==========================================================================
    // 24. ALL IMPORTANT COMBINATIONS AT ONE PLACE
    //==========================================================================
    //
    // BASIC:
    //
    //      map<int, int>
    //
    //      map<int, string>
    //
    //      map<string, int>
    //
    //      map<string, string>
    //
    //      map<char, int>
    //
    //      map<char, string>
    //
    //      map<int, float>
    //
    //      map<int, double>
    //
    //      map<string, float>
    //
    //      map<string, double>
    //
    //      map<long long, int>
    //
    //      map<long long, long long>
    //
    //      map<bool, int>
    //
    //      map<string, bool>
    //
    //
    // ADVANCED:
    //
    //      map<int, pair<int,int>>
    //
    //      map<string, pair<string,int>>
    //
    //      map<int, vector<int>>
    //
    //      map<string, vector<string>>
    //
    //      map<char, vector<int>>
    //
    //      map<int, vector<pair<int,int>>>
    //
    //
    // NESTED:
    //
    //      map<string, map<string,int>>
    //
    //==========================================================================

    //==========================================================================
    // 25. MOST IMPORTANT DSA COMBINATIONS
    //==========================================================================
    //
    // FREQUENCY:
    //
    //      map<int, int>
    //
    //      map<char, int>
    //
    //      map<string, int>
    //
    //
    // ID MAPPING:
    //
    //      map<int, string>
    //
    //
    // GRAPH:
    //
    //      map<int, vector<int>>
    //
    //
    // WEIGHTED GRAPH:
    //
    //      map<int, vector<pair<int,int>>>
    //
    //
    // MULTIPLE VALUES:
    //
    //      map<int, pair<int,int>>
    //
    //
    // NESTED DATA:
    //
    //      map<string, map<string,int>>
    //
    //==========================================================================

    //==========================================================================
    // 26. map VS unordered_map
    //==========================================================================
    //
    // map:
    //
    //      map<Key, Value>
    //
    //      Keys are sorted.
    //
    //      Search:
    //          O(log n)
    //
    //
    // unordered_map:
    //
    //      unordered_map<Key, Value>
    //
    //      Keys are not sorted.
    //
    //      Average search:
    //          O(1)
    //
    //
    // Example:
    //
    //      map<int,string>
    //
    //      unordered_map<int,string>
    //
    //
    // Both can use many of the same KEY/VALUE data type combinations.
    //
    // The major difference is their internal organization and ordering.
    //
    //==========================================================================

    //==========================================================================
    // 27. VERY IMPORTANT CONCEPT
    //==========================================================================
    //
    // map is a TEMPLATE.
    //
    // General form:
    //
    //      map<Key, Value>
    //
    //
    // KEY and VALUE do NOT need to be the same.
    //
    //
    // Valid:
    //
    //      map<int, string>
    //
    // Valid:
    //
    //      map<string, int>
    //
    // Valid:
    //
    //      map<char, double>
    //
    // Valid:
    //
    //      map<long long, string>
    //
    // Valid:
    //
    //      map<int, pair<int,int>>
    //
    // Valid:
    //
    //      map<int, vector<int>>
    //
    //==========================================================================

    //==========================================================================
    // 28. FINAL TYPE CHEAT SHEET
    //==========================================================================
    //
    //                      map<Key, Value>
    //
    //
    // INTEGER:
    //
    //      map<int, int>
    //
    //      map<int, long long>
    //
    //      map<long long, int>
    //
    //      map<long long, long long>
    //
    //
    // STRING:
    //
    //      map<int, string>
    //
    //      map<string, int>
    //
    //      map<string, string>
    //
    //
    // CHARACTER:
    //
    //      map<char, int>
    //
    //      map<char, string>
    //
    //      map<int, char>
    //
    //
    // DECIMAL:
    //
    //      map<int, float>
    //
    //      map<int, double>
    //
    //      map<string, float>
    //
    //      map<string, double>
    //
    //
    // BOOLEAN:
    //
    //      map<bool, int>
    //
    //      map<string, bool>
    //
    //
    // PAIR:
    //
    //      map<int, pair<int,int>>
    //
    //      map<string, pair<string,int>>
    //
    //      map<string, pair<int,double>>
    //
    //
    // VECTOR:
    //
    //      map<int, vector<int>>
    //
    //      map<string, vector<string>>
    //
    //      map<char, vector<int>>
    //
    //
    // ADVANCED:
    //
    //      map<int, vector<pair<int,int>>>
    //
    //
    // NESTED:
    //
    //      map<string, map<string,int>>
    //
    //==========================================================================

    return 0;
}

/*
===============================================================================
                           FINAL REVISION NOTES
===============================================================================

GENERAL SYNTAX:

    map<Key, Value>


KEY:
    The first template parameter.

VALUE:
    The second template parameter.


EXAMPLE:

    map<int, string> students;

means:

    int ---> string

    101 ---> "Amit"
    102 ---> "Rahul"


IMPORTANT:

    KEY and VALUE can be DIFFERENT types.


COMMON DATA TYPES:

    int
    long long
    char
    bool
    float
    double
    string


COMPLEX DATA TYPES:

    pair
    vector
    another map


MOST IMPORTANT DSA TYPES:

    map<int, int>
        Frequency / counting / mapping numbers

    map<char, int>
        Character frequency

    map<string, int>
        Word frequency

    map<int, string>
        ID -> Name

    map<int, vector<int>>
        Graph adjacency list

    map<int, pair<int,int>>
        Key -> two associated values

    map<int, vector<pair<int,int>>>
        Weighted graph

    map<string, map<string,int>>
        Nested mapping


KEY DIFFERENCE FROM unordered_map:

    map:
        ORDERED

    unordered_map:
        UNORDERED


map maintains keys in sorted order.

Example:

    Insert:

        50
        10
        40
        20
        30

    Iteration:

        10
        20
        30
        40
        50


TIME COMPLEXITY:

    Search:
        O(log n)

    Insert:
        O(log n)

    Erase:
        O(log n)


===============================================================================
*/