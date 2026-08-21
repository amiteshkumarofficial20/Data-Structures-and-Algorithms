/*
===============================================================================
                    C++ STL - UNORDERED_MAP
                    DIFFERENT DATA TYPES
===============================================================================

TOPIC:
    Different Data Types That Can Be Used With unordered_map

HEADER:
    #include <unordered_map>

BASIC SYNTAX:

    unordered_map<KeyType, ValueType> mapName;

Example:

    unordered_map<int, string> mp;

Here:

    int
    ↓
    KEY TYPE

    string
    ↓
    VALUE TYPE


===============================================================================
WHAT IS unordered_map?
===============================================================================

unordered_map is an associative container of the C++ STL.

It stores data in the form:

        KEY  --->  VALUE

For example:

        101 ---> "Amit"
        102 ---> "Rahul"
        103 ---> "Riya"


IMPORTANT:

    Key and Value can have different data types.

For example:

    unordered_map<int, string>

    unordered_map<string, int>

    unordered_map<char, double>

    unordered_map<long long, string>

    unordered_map<int, pair<int, int>>

    unordered_map<int, vector<int>>


===============================================================================
IMPORTANT RULE
===============================================================================

The first template parameter is the KEY.

The second template parameter is the VALUE.

General form:

    unordered_map<Key, Value>


Example:

    unordered_map<int, string> students;

means:

    KEY:
        int

    VALUE:
        string


So:

    students[101] = "Amit";

means:

    101 ---> "Amit"


===============================================================================
IMPORTANT KEY RULE
===============================================================================

For unordered_map, the key type must have suitable hashing support.

Common built-in types that can be used as keys include:

    int
    long long
    char
    bool
    float
    double
    string

and other types when an appropriate hash is available.

For custom user-defined types, we may need to provide:

    custom hash

and usually:

    equality comparison


===============================================================================
IMPORTANT VALUE RULE
===============================================================================

The VALUE can be many different types.

For example:

    int
    long long
    float
    double
    char
    bool
    string
    pair
    vector
    etc.


===============================================================================
                    PART 1
              INTEGER KEY + INTEGER VALUE
===============================================================================
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{

    //==========================================================================
    // 1. unordered_map<int, int>
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
    //      1 ---> 1
    //      2 ---> 4
    //      3 ---> 9
    //      4 ---> 16
    //
    //==========================================================================

    unordered_map<int, int> intIntMap;

    intIntMap[1] = 1;
    intIntMap[2] = 4;
    intIntMap[3] = 9;
    intIntMap[4] = 16;
    intIntMap[5] = 25;

    cout << "==================================================" << endl;
    cout << "1. unordered_map<int, int>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, int>::iterator it = intIntMap.begin();
         it != intIntMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    NOTE:

        intIntMap[1]

    means:

        KEY = 1

    and:

        intIntMap[1] = 1

    means:

        VALUE associated with key 1 = 1
    */

    //==========================================================================
    // 2. unordered_map<int, string>
    //==========================================================================
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      string
    //
    // This is one of the most common combinations.
    //
    // Example:
    //
    //      Student ID ---> Student Name
    //
    //==========================================================================

    unordered_map<int, string> intStringMap;

    intStringMap[101] = "Amit";
    intStringMap[102] = "Rahul";
    intStringMap[103] = "Riya";
    intStringMap[104] = "Neha";

    cout << endl;
    cout << "==================================================" << endl;
    cout << "2. unordered_map<int, string>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, string>::iterator it = intStringMap.begin();
         it != intStringMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    IMPORTANT:

        Here the key is integer.

        The value is string.

    Therefore:

        101 ---> "Amit"
        102 ---> "Rahul"
        103 ---> "Riya"


    This is commonly used for:

        Student ID -> Name
        Employee ID -> Name
        Product ID -> Product Name
        Roll Number -> Student Name
    */

    //==========================================================================
    // 3. unordered_map<string, int>
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

    unordered_map<string, int> stringIntMap;

    stringIntMap["Amit"] = 95;
    stringIntMap["Rahul"] = 88;
    stringIntMap["Riya"] = 92;
    stringIntMap["Neha"] = 85;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "3. unordered_map<string, int>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, int>::iterator it = stringIntMap.begin();
         it != stringIntMap.end();
         ++it)
    {
        cout << it->first
             << " -> "
             << it->second
             << endl;
    }

    /*
    COMMON USE:

        string -> frequency

    Example:

        "apple" -> 5
        "banana" -> 3
        "mango" -> 7
    */

    //==========================================================================
    // 4. unordered_map<string, string>
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

    unordered_map<string, string> stringStringMap;

    stringStringMap["in"] = "India";
    stringStringMap["us"] = "United States";
    stringStringMap["uk"] = "United Kingdom";
    stringStringMap["jp"] = "Japan";
    stringStringMap["br"] = "Brazil";

    cout << endl;
    cout << "==================================================" << endl;
    cout << "4. unordered_map<string, string>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, string>::iterator it =
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
    EXAMPLES:

        Country Code -> Country Name

        "in" -> "India"
        "us" -> "United States"

    Other possible uses:

        username -> email
        username -> password-hash
        word -> meaning
        abbreviation -> full form
    */

    //==========================================================================
    // 5. unordered_map<char, int>
    //==========================================================================
    //
    // KEY:
    //      char
    //
    // VALUE:
    //      int
    //
    // This is extremely important for:
    //
    //      CHARACTER FREQUENCY
    //
    //==========================================================================

    unordered_map<char, int> charIntMap;

    charIntMap['a'] = 10;
    charIntMap['b'] = 20;
    charIntMap['c'] = 30;
    charIntMap['d'] = 40;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "5. unordered_map<char, int>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<char, int>::iterator it =
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
    MOST IMPORTANT USE:

        Frequency of characters.

    Example:

        string s = "banana";

    We can count:

        b -> 1
        a -> 3
        n -> 2

    using:

        unordered_map<char, int>
    */

    //==========================================================================
    // 6. unordered_map<char, string>
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

    unordered_map<char, string> charStringMap;

    charStringMap['A'] = "Excellent";
    charStringMap['B'] = "Very Good";
    charStringMap['C'] = "Good";
    charStringMap['D'] = "Average";

    cout << endl;
    cout << "==================================================" << endl;
    cout << "6. unordered_map<char, string>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<char, string>::iterator it =
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
    // 7. unordered_map<int, char>
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

    unordered_map<int, char> intCharMap;

    intCharMap[1] = 'A';
    intCharMap[2] = 'B';
    intCharMap[3] = 'C';
    intCharMap[4] = 'D';

    cout << endl;
    cout << "==================================================" << endl;
    cout << "7. unordered_map<int, char>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, char>::iterator it =
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
    // 8. unordered_map<int, double>
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

    unordered_map<int, double> intDoubleMap;

    intDoubleMap[101] = 999.99;
    intDoubleMap[102] = 1499.50;
    intDoubleMap[103] = 2499.75;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "8. unordered_map<int, double>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, double>::iterator it =
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
    // 9. unordered_map<string, double>
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

    unordered_map<string, double> stringDoubleMap;

    stringDoubleMap["Laptop"] = 55000.50;
    stringDoubleMap["Mobile"] = 25000.75;
    stringDoubleMap["Tablet"] = 18000.25;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "9. unordered_map<string, double>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, double>::iterator it =
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
    // 10. unordered_map<int, float>
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

    unordered_map<int, float> intFloatMap;

    intFloatMap[101] = 4.5f;
    intFloatMap[102] = 3.8f;
    intFloatMap[103] = 4.9f;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "10. unordered_map<int, float>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, float>::iterator it =
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
    // 11. unordered_map<string, float>
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

    unordered_map<string, float> stringFloatMap;

    stringFloatMap["Amit"] = 9.5f;
    stringFloatMap["Rahul"] = 8.7f;
    stringFloatMap["Riya"] = 9.1f;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "11. unordered_map<string, float>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, float>::iterator it =
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
    // 12. unordered_map<long long, long long>
    //==========================================================================
    //
    // long long is useful when values can be very large.
    //
    // Example:
    //
    //      Large ID ---> Large Value
    //
    //==========================================================================

    unordered_map<long long, long long> longLongMap;

    longLongMap[10000000000LL] = 50000000000LL;
    longLongMap[20000000000LL] = 90000000000LL;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "12. unordered_map<long long, long long>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<long long, long long>::iterator it =
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
    // 13. unordered_map<long long, int>
    //==========================================================================
    //
    // KEY:
    //      long long
    //
    // VALUE:
    //      int
    //
    //==========================================================================

    unordered_map<long long, int> longLongIntMap;

    longLongIntMap[10000000000LL] = 10;
    longLongIntMap[20000000000LL] = 20;
    longLongIntMap[30000000000LL] = 30;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "13. unordered_map<long long, int>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<long long, int>::iterator it =
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
    // 14. unordered_map<bool, int>
    //==========================================================================
    //
    // KEY:
    //      bool
    //
    // VALUE:
    //      int
    //
    // bool has two possible values:
    //
    //      true
    //      false
    //
    //==========================================================================

    unordered_map<bool, int> boolIntMap;

    boolIntMap[true] = 100;
    boolIntMap[false] = 200;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "14. unordered_map<bool, int>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<bool, int>::iterator it =
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
    // 15. unordered_map<string, bool>
    //==========================================================================
    //
    // Example:
    //
    //      Student ---> Present/Absent
    //
    //==========================================================================

    unordered_map<string, bool> stringBoolMap;

    stringBoolMap["Amit"] = true;
    stringBoolMap["Rahul"] = false;
    stringBoolMap["Riya"] = true;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "15. unordered_map<string, bool>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, bool>::iterator it =
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
    // 16. unordered_map<int, pair<int, int>>
    //==========================================================================
    //
    // VERY IMPORTANT DSA DATA TYPE.
    //
    // Here:
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      pair<int, int>
    //
    //
    // Therefore:
    //
    //      int ---> pair<int,int>
    //
    //
    // Example:
    //
    //      Student ID ---> (Math Marks, Physics Marks)
    //
    //==========================================================================

    unordered_map<int, pair<int, int>> intPairMap;

    intPairMap[101] = make_pair(90, 85);
    intPairMap[102] = make_pair(88, 92);
    intPairMap[103] = make_pair(95, 89);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "16. unordered_map<int, pair<int, int>>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, pair<int, int>>::iterator it =
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

    is the unordered_map KEY.

    And:

        it->second

    is the pair.

    Therefore:

        it->second.first

    means first value of pair.

    And:

        it->second.second

    means second value of pair.
    */

    //==========================================================================
    // 17. unordered_map<string, pair<string, int>>
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

    unordered_map<string, pair<string, int>> stringPairMap;

    stringPairMap["Amit"] = make_pair("Kanpur", 21);
    stringPairMap["Rahul"] = make_pair("Delhi", 22);
    stringPairMap["Riya"] = make_pair("Mumbai", 20);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "17. unordered_map<string, pair<string, int>>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, pair<string, int>>::iterator it =
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
    // 18. unordered_map<int, vector<int>>
    //==========================================================================
    //
    // VERY IMPORTANT IN GRAPH DSA.
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      vector<int>
    //
    //
    // Meaning:
    //
    //      Node ---> List of connected nodes
    //
    //==========================================================================

    unordered_map<int, vector<int>> intVectorMap;

    intVectorMap[1].push_back(2);
    intVectorMap[1].push_back(3);

    intVectorMap[2].push_back(1);
    intVectorMap[2].push_back(4);

    intVectorMap[3].push_back(1);

    intVectorMap[4].push_back(2);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "18. unordered_map<int, vector<int>>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, vector<int>>::iterator it =
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
    // 19. unordered_map<string, vector<string>>
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

    unordered_map<string, vector<string>> stringVectorMap;

    stringVectorMap["India"].push_back("Kanpur");
    stringVectorMap["India"].push_back("Delhi");
    stringVectorMap["India"].push_back("Mumbai");

    stringVectorMap["USA"].push_back("New York");
    stringVectorMap["USA"].push_back("Chicago");

    cout << endl;
    cout << "==================================================" << endl;
    cout << "19. unordered_map<string, vector<string>>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, vector<string>>::iterator it =
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
    // 20. unordered_map<char, vector<int>>
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

    unordered_map<char, vector<int>> charVectorMap;

    charVectorMap['a'].push_back(0);
    charVectorMap['a'].push_back(2);
    charVectorMap['a'].push_back(5);

    charVectorMap['b'].push_back(1);
    charVectorMap['b'].push_back(4);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "20. unordered_map<char, vector<int>>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<char, vector<int>>::iterator it =
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
    // 21. unordered_map<int, vector<pair<int, int>>>
    //==========================================================================
    //
    // This is a more advanced combination.
    //
    // KEY:
    //      int
    //
    // VALUE:
    //      vector<pair<int,int>>
    //
    //
    // Common graph representation:
    //
    //      node ---> [(neighbor, weight), ...]
    //
    //
    // Example:
    //
    //      1 -> {(2,5), (3,10)}
    //
    // means:
    //
    //      1 to 2 has weight 5
    //      1 to 3 has weight 10
    //
    //==========================================================================

    unordered_map<int, vector<pair<int, int>>> weightedGraph;

    weightedGraph[1].push_back(make_pair(2, 5));
    weightedGraph[1].push_back(make_pair(3, 10));

    weightedGraph[2].push_back(make_pair(4, 7));
    weightedGraph[3].push_back(make_pair(4, 3));

    cout << endl;
    cout << "==================================================" << endl;
    cout << "21. unordered_map<int, vector<pair<int,int>>>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, vector<pair<int, int>>>::iterator it =
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
    // 22. unordered_map<string, pair<int, double>>
    //==========================================================================
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      pair<int,double>
    //
    // Example:
    //
    //      Product ---> (Quantity, Price)
    //
    //==========================================================================

    unordered_map<string, pair<int, double>> productMap;

    productMap["Laptop"] = make_pair(2, 55000.50);
    productMap["Phone"] = make_pair(5, 25000.75);
    productMap["Tablet"] = make_pair(3, 18000.25);

    cout << endl;
    cout << "==================================================" << endl;
    cout << "22. unordered_map<string, pair<int, double>>" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, pair<int, double>>::iterator it =
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
    // 23. NESTED unordered_map
    //==========================================================================
    //
    // An unordered_map can also have another unordered_map as its VALUE.
    //
    // KEY:
    //      string
    //
    // VALUE:
    //      unordered_map<string, int>
    //
    //
    // Example:
    //
    //      Country ---> City ---> Population
    //
    //==========================================================================

    unordered_map<string, unordered_map<string, int>> nestedMap;

    nestedMap["India"]["Delhi"] = 20000000;
    nestedMap["India"]["Mumbai"] = 21000000;
    nestedMap["India"]["Kanpur"] = 3000000;

    nestedMap["USA"]["NewYork"] = 8000000;
    nestedMap["USA"]["Chicago"] = 2700000;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "23. NESTED unordered_map" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string,
                       unordered_map<string, int>>::iterator outer =
             nestedMap.begin();
         outer != nestedMap.end();
         ++outer)
    {
        cout << outer->first << ":" << endl;

        for (unordered_map<string, int>::iterator inner =
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
    // 24. DIFFERENT COMBINATIONS AT ONE PLACE
    //==========================================================================
    //
    // The following are all valid and useful combinations.
    //
    //==========================================================================

    unordered_map<int, int> a;
    unordered_map<int, string> b;
    unordered_map<string, int> c;
    unordered_map<string, string> d;
    unordered_map<char, int> e;
    unordered_map<char, string> f;
    unordered_map<int, double> g;
    unordered_map<string, double> h;
    unordered_map<long long, int> i;
    unordered_map<long long, long long> j;
    unordered_map<int, pair<int, int>> k;
    unordered_map<string, pair<string, int>> l;
    unordered_map<int, vector<int>> m;
    unordered_map<string, vector<string>> n;
    unordered_map<char, vector<int>> o;
    unordered_map<int, vector<pair<int, int>>> p;

    //==========================================================================
    // 25. KEY + VALUE DATA TYPE CHEAT SHEET
    //==========================================================================
    //
    // BASIC DATA TYPES:
    //
    //      unordered_map<int, int>
    //
    //      unordered_map<int, string>
    //
    //      unordered_map<string, int>
    //
    //      unordered_map<string, string>
    //
    //      unordered_map<char, int>
    //
    //      unordered_map<char, string>
    //
    //      unordered_map<int, float>
    //
    //      unordered_map<int, double>
    //
    //      unordered_map<string, float>
    //
    //      unordered_map<string, double>
    //
    //      unordered_map<long long, int>
    //
    //      unordered_map<long long, long long>
    //
    //      unordered_map<bool, int>
    //
    //      unordered_map<string, bool>
    //
    //
    // COMBINATION TYPES:
    //
    //      unordered_map<int, pair<int,int>>
    //
    //      unordered_map<string, pair<string,int>>
    //
    //      unordered_map<int, vector<int>>
    //
    //      unordered_map<string, vector<string>>
    //
    //      unordered_map<char, vector<int>>
    //
    //      unordered_map<int, vector<pair<int,int>>>
    //
    //
    // NESTED:
    //
    //      unordered_map<
    //          string,
    //          unordered_map<string,int>
    //      >
    //
    //==========================================================================

    //==========================================================================
    // 26. VERY IMPORTANT CONCEPT
    //==========================================================================
    //
    // unordered_map does NOT mean:
    //
    //      same data type for key and value.
    //
    //
    // This is completely valid:
    //
    //      unordered_map<int, string>
    //
    //
    // This is also valid:
    //
    //      unordered_map<string, int>
    //
    //
    // This is also valid:
    //
    //      unordered_map<char, double>
    //
    //
    // Therefore:
    //
    //      KEY TYPE and VALUE TYPE
    //
    // can be different.
    //
    //==========================================================================

    //==========================================================================
    // 27. MOST IMPORTANT DSA COMBINATIONS
    //==========================================================================
    //
    // Frequency:
    //
    //      unordered_map<int, int>
    //
    //      unordered_map<char, int>
    //
    //      unordered_map<string, int>
    //
    //
    // ID Mapping:
    //
    //      unordered_map<int, string>
    //
    //
    // Graph:
    //
    //      unordered_map<int, vector<int>>
    //
    //
    // Weighted Graph:
    //
    //      unordered_map<int, vector<pair<int,int>>>
    //
    //
    // Multiple Information:
    //
    //      unordered_map<int, pair<int,int>>
    //
    //
    // Nested Data:
    //
    //      unordered_map<string,
    //                     unordered_map<string,int>>
    //
    //==========================================================================

    //==========================================================================
    // 28. FINAL IMPORTANT NOTE
    //==========================================================================
    //
    // unordered_map is a TEMPLATE.
    //
    // Its general form is:
    //
    //      unordered_map<Key, Value>
    //
    //
    // Key can be:
    //
    //      int
    //      long long
    //      char
    //      bool
    //      string
    //      etc.
    //
    //
    // Value can be:
    //
    //      int
    //      long long
    //      float
    //      double
    //      char
    //      bool
    //      string
    //      pair
    //      vector
    //      another unordered_map
    //      etc.
    //
    //
    // The most important thing to remember:
    //
    //      unordered_map<Key, Value>
    //                  ↑      ↑
    //                  |      |
    //                 KEY    VALUE
    //
    //==========================================================================

    return 0;
}

/*
===============================================================================
                         FINAL REVISION
===============================================================================

                    unordered_map<Key, Value>

Examples:

    unordered_map<int, int>

    unordered_map<int, string>

    unordered_map<string, int>

    unordered_map<string, string>

    unordered_map<char, int>

    unordered_map<char, string>

    unordered_map<int, float>

    unordered_map<int, double>

    unordered_map<string, float>

    unordered_map<string, double>

    unordered_map<long long, int>

    unordered_map<long long, long long>

    unordered_map<bool, int>

    unordered_map<string, bool>


Advanced:

    unordered_map<int, pair<int,int>>

    unordered_map<string, pair<string,int>>

    unordered_map<int, vector<int>>

    unordered_map<string, vector<string>>

    unordered_map<char, vector<int>>

    unordered_map<int, vector<pair<int,int>>>


Nested:

    unordered_map<
        string,
        unordered_map<string,int>
    >


MOST IMPORTANT DSA TYPES:

    Frequency:
        unordered_map<int,int>
        unordered_map<char,int>
        unordered_map<string,int>

    Graph:
        unordered_map<int,vector<int>>

    Weighted Graph:
        unordered_map<int,vector<pair<int,int>>>

    ID -> Name:
        unordered_map<int,string>

    Name -> Marks:
        unordered_map<string,int>

    ID -> Two Values:
        unordered_map<int,pair<int,int>>


GENERAL RULE:

    unordered_map<Key, Value>

    Key and Value do NOT have to be the same type.


===============================================================================
*/