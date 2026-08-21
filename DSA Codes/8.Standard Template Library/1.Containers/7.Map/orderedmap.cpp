#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    // ========================================================================
    //                         STL : map
    // ========================================================================
    //
    // map ek ASSOCIATIVE CONTAINER hai.
    //
    // Iska use KEY-VALUE pairs ko store karne ke liye hota hai.
    //
    // Example:
    //
    //      "br" -> "Brazil"
    //      "en" -> "England"
    //      "in" -> "India"
    //
    //
    // IMPORTANT:
    //
    // std::map ko ORDERED ASSOCIATIVE CONTAINER kaha jata hai.
    //
    // Ismein elements KEY ke according SORTED ORDER mein maintain hote hain.
    //
    // Default ordering:
    //
    //      ascending order
    //
    //
    // Example:
    //
    //      map<int, string>
    //
    // Keys:
    //
    //      5
    //      2
    //      10
    //      1
    //
    // Map internally order maintain karega:
    //
    //      1
    //      2
    //      5
    //      10
    //
    //
    // ========================================================================
    // map vs unordered_map
    // ========================================================================
    //
    // map:
    //
    //      - keys sorted hoti hain
    //      - generally balanced tree based implementation
    //      - search    -> O(log n)
    //      - insertion -> O(log n)
    //      - deletion  -> O(log n)
    //
    //
    // unordered_map:
    //
    //      - keys sorted nahi hoti
    //      - hashing based
    //      - average search    -> O(1)
    //      - average insertion -> O(1)
    //      - average deletion  -> O(1)
    //
    //
    // map mein iteration deterministic sorted order mein hoti hai
    // according to its comparison object.
    //
    // ========================================================================

    // ========================================================================
    // 1. CREATING map
    // ========================================================================
    //
    // Syntax:
    //
    //      map<KeyType, ValueType> variableName;
    //
    //
    // Example:
    //
    //      map<string, string> mp;
    //
    //
    // Yahan:
    //
    //      KeyType   = string
    //      ValueType = string
    //
    //
    // So:
    //
    //      map<string, string>
    //
    // key aur value dono string hongi.
    //
    // ========================================================================

    map<string, string> mp;

    // ========================================================================
    // 2. INSERTION USING [] OPERATOR
    // ========================================================================
    //
    // map mein insertion ka easiest way:
    //
    //      mp[key] = value;
    //
    //
    // Example:
    //
    //      mp["in"] = "India";
    //
    //
    // Yahan:
    //
    //      key   = "in"
    //      value = "India"
    //
    // ========================================================================

    mp["in"] = "India";

    // ========================================================================
    // 3. INSERTION USING insert(make_pair())
    // ========================================================================
    //
    // map ke elements key-value pair ke form mein stored hote hain.
    //
    // Isliye make_pair() use karke insert kar sakte hain.
    //
    //
    //      make_pair("en", "England")
    //
    // ek pair create karega:
    //
    //      {"en", "England"}
    //
    //
    // Aur:
    //
    //      mp.insert(...)
    //
    // us pair ko map mein insert karega.
    //
    // ========================================================================

    mp.insert(make_pair("en", "England"));

    // ========================================================================
    // 4. INSERTION USING pair OBJECT
    // ========================================================================
    //
    // Hum manually pair object bana kar bhi map mein insert kar sakte hain.
    //
    // ========================================================================

    pair<string, string> p;

    // ========================================================================
    // 5. SET pair.first
    // ========================================================================
    //
    // pair ka first member key ko represent karega.
    //
    // ========================================================================

    p.first = "br";

    // ========================================================================
    // 6. SET pair.second
    // ========================================================================
    //
    // pair ka second member value ko represent karega.
    //
    // ========================================================================

    p.second = "Brazil";

    // ========================================================================
    // 7. INSERT pair INTO map
    // ========================================================================
    //
    // Ab p:
    //
    //      first  = "br"
    //      second = "Brazil"
    //
    //
    // So:
    //
    //      p = {"br", "Brazil"}
    //
    //
    // Is pair ko map mein insert karenge.
    //
    // ========================================================================

    mp.insert(p);

    // ========================================================================
    // 8. ORDER OF map
    // ========================================================================
    //
    // Ab humne insertion kiya:
    //
    //      "in" -> "India"
    //      "en" -> "England"
    //      "br" -> "Brazil"
    //
    //
    // Lekin map insertion order follow nahi karega.
    //
    // Keys automatically sorted hongi:
    //
    //      "br"
    //      "en"
    //      "in"
    //
    //
    // Therefore iteration ke time output approximately:
    //
    //      br -> Brazil
    //      en -> England
    //      in -> India
    //
    //
    // Ye unordered_map se major difference hai.
    //
    // ========================================================================

    // ========================================================================
    // 9. size()
    // ========================================================================
    //
    // size() total number of key-value pairs return karta hai.
    //
    // Current map mein:
    //
    //      br
    //      en
    //      in
    //
    // Total = 3
    //
    // ========================================================================

    cout << "Size of Map is : "
         << mp.size()
         << endl;

    // ========================================================================
    // 10. ACCESS VALUE USING at()
    // ========================================================================
    //
    // at(key) existing key ki value return karta hai.
    //
    //
    //      mp.at("in")
    //
    // returns:
    //
    //      India
    //
    //
    // IMPORTANT:
    //
    // Agar key map mein nahi hai, at() exception throw karega.
    //
    // at() missing key ko automatically insert nahi karta.
    //
    // ========================================================================

    cout << mp.at("in") << endl;

    // ========================================================================
    // 11. ACCESS VALUE USING [] OPERATOR
    // ========================================================================
    //
    // [] se bhi value access kar sakte hain.
    //
    //
    //      mp["en"]
    //
    // returns:
    //
    //      England
    //
    // ========================================================================

    cout << mp["en"] << endl;

    // ========================================================================
    // 12. UPDATE VALUE USING at()
    // ========================================================================
    //
    // Existing key ki value update kar sakte hain:
    //
    //      mp.at("in") = "Hindustan";
    //
    //
    // Before:
    //
    //      in -> India
    //
    // After:
    //
    //      in -> Hindustan
    //
    // ========================================================================

    mp.at("in") = "Hindustan";

    // Updated value print.

    cout << mp.at("in") << endl;

    // ========================================================================
    // 13. UPDATE VALUE USING [] OPERATOR
    // ========================================================================
    //
    // Existing key ko [] se bhi update kar sakte hain.
    //
    // ========================================================================

    mp["en"] = "England";

    cout << mp.at("en") << endl;

    // ========================================================================
    // 14. IMPORTANT: [] CAN INSERT
    // ========================================================================
    //
    // map mein [] operator ka ek important behavior hai.
    //
    //
    // Agar key already exist karti hai:
    //
    //      mp["in"]
    //
    // existing value return karega.
    //
    //
    // Agar key exist nahi karti:
    //
    //      mp["fr"]
    //
    // to map mein new key create ho sakti hai aur value default
    // construct hoti hai.
    //
    //
    // Example:
    //
    //      map<string,string> mp;
    //
    //      cout << mp["fr"];
    //
    // "fr" missing hai, to new element create ho sakta hai:
    //
    //      "fr" -> ""
    //
    //
    // Isliye sirf search karne ke liye [] use karna avoid karna better hai.
    //
    // Search ke liye:
    //
    //      find()
    //
    // use karo.
    //
    // ========================================================================

    // ========================================================================
    // 15. clear()
    // ========================================================================
    //
    // clear() map ke SAARE elements remove kar deta hai.
    //
    //
    // Before:
    //
    //      br -> Brazil
    //      en -> England
    //      in -> Hindustan
    //
    //
    // After:
    //
    //      {}
    //
    // ========================================================================

    mp.clear();

    // ========================================================================
    // 16. size() AFTER clear()
    // ========================================================================
    //
    // clear() ke baad:
    //
    //      size = 0
    //
    // ========================================================================

    cout << "Size of Map is : "
         << mp.size()
         << endl;

    // ========================================================================
    // 17. empty()
    // ========================================================================
    //
    // empty() check karta hai ki map empty hai ya nahi.
    //
    //
    // Return:
    //
    //      true  -> empty
    //      false -> not empty
    //
    // ========================================================================

    if (mp.empty())
    {
        cout << "Map is Empty" << endl;
    }
    else
    {
        cout << "Map is not Empty" << endl;
    }

    // ========================================================================
    // 18. REINSERT DATA
    // ========================================================================
    //
    // clear() ke baad map empty tha.
    //
    // Ab dobara elements insert karte hain.
    //
    // ========================================================================

    mp["in"] = "India";
    mp["en"] = "England";
    mp["br"] = "Brazil";
    mp["us"] = "United States";
    mp["jp"] = "Japan";

    // ========================================================================
    // 19. size() AFTER MULTIPLE INSERTION
    // ========================================================================

    cout << "Size of Map is : "
         << mp.size()
         << endl;

    // ========================================================================
    // 20. ITERATION OF map
    // ========================================================================
    //
    // map ko iterator se iterate kar sakte hain.
    //
    //
    // Syntax:
    //
    //      map<string,string>::iterator it;
    //
    //
    // map ke element mein:
    //
    //      first  -> key
    //      second -> value
    //
    //
    // IMPORTANT:
    //
    // map ordered hai.
    //
    // Isliye keys sorted order mein milengi.
    //
    // ========================================================================

    cout << "\n========== MAP ITERATION ==========" << endl;

    for (map<string, string>::iterator it = mp.begin();
         it != mp.end();
         ++it)
    {
        cout << "Key = "
             << it->first
             << ", Value = "
             << it->second
             << endl;
    }

    // ========================================================================
    // 21. RANGE-BASED FOR LOOP
    // ========================================================================
    //
    // Modern C++ mein:
    //
    //      for (const auto &x : mp)
    //
    // use kar sakte hain.
    //
    //
    // x.first:
    //      key
    //
    // x.second:
    //      value
    //
    // ========================================================================

    cout << "\n========== RANGE BASED LOOP ==========" << endl;

    for (const auto &x : mp)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ========================================================================
    // 22. erase() BY KEY
    // ========================================================================
    //
    // Kisi particular key ko delete karne ke liye:
    //
    //      mp.erase(key);
    //
    //
    // Example:
    //
    //      mp.erase("jp");
    //
    //
    // "jp" wala key-value pair remove ho jayega.
    //
    // ========================================================================

    mp.erase("jp");

    cout << "\nAfter erase(\"jp\"):" << endl;

    for (const auto &x : mp)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ========================================================================
    // 23. erase() USING ITERATOR
    // ========================================================================
    //
    // Pehle iterator se element find karo:
    //
    //      auto it = mp.find("br");
    //
    //
    // Agar mil gaya:
    //
    //      mp.erase(it);
    //
    //
    // Ye "br" wala element remove karega.
    //
    // ========================================================================

    map<string, string>::iterator it = mp.find("br");

    if (it != mp.end())
    {
        mp.erase(it);
    }

    // ========================================================================
    // 24. erase() RANGE
    // ========================================================================
    //
    // Map mein iterator range ko bhi erase kar sakte hain.
    //
    //
    //      mp.erase(mp.begin(), mp.end());
    //
    //
    // Isse poora map empty ho jayega.
    //
    //
    // IMPORTANT:
    //
    // Ye clear() jaisa result dega.
    //
    // ========================================================================

    mp.erase(mp.begin(), mp.end());

    cout << "\nSize after erase(begin(), end()) = "
         << mp.size()
         << endl;

    // ========================================================================
    // 25. REINSERT DATA
    // ========================================================================

    mp["in"] = "India";
    mp["en"] = "England";
    mp["br"] = "Brazil";
    mp["us"] = "United States";
    mp["jp"] = "Japan";

    // ========================================================================
    // 26. find()
    // ========================================================================
    //
    // find(key) given key ko search karta hai.
    //
    //
    // Return:
    //
    //      iterator
    //
    //
    // Found:
    //
    //      iterator != mp.end()
    //
    //
    // Not found:
    //
    //      iterator == mp.end()
    //
    //
    // IMPORTANT:
    //
    // find() missing key ko insert nahi karta.
    //
    // ========================================================================

    if (mp.find("in") != mp.end())
    {
        cout << "\nKey is Found" << endl;
    }
    else
    {
        cout << "\nKey is not Found" << endl;
    }

    // ========================================================================
    // 27. find() + ITERATOR
    // ========================================================================
    //
    // find() se returned iterator ko variable mein store kar sakte hain.
    //
    // ========================================================================

    map<string, string>::iterator found = mp.find("br");

    if (found != mp.end())
    {
        cout << "Found Key   : "
             << found->first
             << endl;

        cout << "Found Value : "
             << found->second
             << endl;
    }

    // ========================================================================
    // 28. count()
    // ========================================================================
    //
    // count(key) check karta hai ki key present hai ya nahi.
    //
    //
    // map mein keys UNIQUE hoti hain.
    //
    // Therefore:
    //
    //      count(key) == 0
    //          -> key absent
    //
    //      count(key) == 1
    //          -> key present
    //
    // ========================================================================

    if (mp.count("in") != 0)
    {
        cout << "Key is Found" << endl;
    }
    else
    {
        cout << "Key is not Found" << endl;
    }

    // ========================================================================
    // 29. count() WITH MISSING KEY
    // ========================================================================

    if (mp.count("xyz") == 0)
    {
        cout << "xyz Key is not Found" << endl;
    }
    else
    {
        cout << "xyz Key is Found" << endl;
    }

    // ========================================================================
    // 30. MODIFY VALUE DURING ITERATION
    // ========================================================================
    //
    // map ke iterator/reference ke through VALUE modify kar sakte hain.
    //
    //
    //      it->second = newValue;
    //
    //
    // Lekin:
    //
    //      it->first
    //
    // ko modify nahi kar sakte.
    //
    //
    // Reason:
    //
    // map key ordering maintain karta hai.
    //
    // Agar key directly change karne di jaye to tree ki ordering
    // break ho sakti hai.
    //
    // Isliye key effectively const hoti hai.
    //
    // ========================================================================

    for (auto &x : mp)
    {
        if (x.first == "us")
        {
            x.second = "USA";
        }
    }

    cout << "\nUpdated US value = "
         << mp.at("us")
         << endl;

    // ========================================================================
    // 31. INSERT DUPLICATE KEY
    // ========================================================================
    //
    // map mein keys UNIQUE hoti hain.
    //
    //
    // Existing key:
    //
    //      "in"
    //
    // ko insert karne ki try:
    //
    //      mp.insert({"in", "Hindustan"});
    //
    //
    // Existing element ko replace nahi karegi.
    //
    // insert() duplicate key ke case mein insertion fail kar sakta hai.
    //
    //
    // Agar value update karni hai:
    //
    //      mp["in"] = "Hindustan";
    //
    // use karo.
    //
    // ========================================================================

    pair<map<string, string>::iterator, bool> result;

    result = mp.insert(make_pair("in", "Hindustan"));

    // result.second:
    //
    //      true  -> insertion successful
    //      false -> insertion unsuccessful
    //
    // Duplicate key ke case mein false ho sakta hai.

    if (result.second)
    {
        cout << "\nDuplicate insertion successful." << endl;
    }
    else
    {
        cout << "\nDuplicate key: insertion failed." << endl;
    }

    // ========================================================================
    // 32. insert() RETURN VALUE
    // ========================================================================
    //
    // map::insert() generally pair return karta hai:
    //
    //      pair<iterator, bool>
    //
    //
    // first:
    //
    //      iterator
    //
    // second:
    //
    //      bool
    //
    //
    // bool:
    //
    //      true  -> inserted
    //      false -> insertion failed
    //
    // ========================================================================

    // ========================================================================
    // 33. insert_or_assign()
    // ========================================================================
    //
    // C++17 mein:
    //
    //      insert_or_assign()
    //
    // useful hai.
    //
    //
    // Agar key exist nahi karti:
    //
    //      insert karega.
    //
    //
    // Agar key already exist karti:
    //
    //      value replace/update karega.
    //
    // ========================================================================

    // ========================================================================
    // 33. UPDATE EXISTING KEY
    // ========================================================================
    //
    // Agar key already exist karti hai, [] operator se uski value update
    // kar sakte hain.
    //
    // "in" key already map mein present hai.
    //
    // Isliye:
    //      mp["in"] = "Hindustan";
    //
    // existing value ko replace karega.
    //
    // ========================================================================

    mp["in"] = "Hindustan";

    cout << "\nAfter updating value:" << endl;
    cout << mp.at("in") << endl;

    // ========================================================================
    // 34. INSERT NEW KEY-VALUE PAIR
    // ========================================================================
    //
    // Agar humein ek NEW key-value pair insert karna hai,
    // to emplace() use kar sakte hain.
    //
    // Syntax:
    //
    //      mp.emplace(key, value);
    //
    //
    //
    // Yahan:
    //
    //      key   = "fr"
    //      value = "France"
    //
    // Isse:
    //
    //      "fr" -> "France"
    //
    // map mein insert hoga.
    //
    // ========================================================================

    mp.emplace("fr", "France");

    // Check inserted value.

    cout << "\nAfter emplace:" << endl;
    cout << mp.at("fr") << endl;

    // ========================================================================
    // 35. emplace()
    // ========================================================================
    //
    // emplace() element ko construct karke map mein insert karta hai.
    //
    // ========================================================================

    mp.emplace("de", "Germany");

    // ========================================================================
    // 36. COMPLETE MAP ITERATION AGAIN
    // ========================================================================
    //
    // Ab final map ko print karte hain.
    //
    // IMPORTANT:
    //
    // Keys sorted order mein print hongi.
    //
    // Example:
    //
    //      br
    //      de
    //      en
    //      fr
    //      in
    //      us
    //
    // Exact order values par depend karega, but key ordering
    // ascending hogi.
    //
    // ========================================================================

    cout << "\n========== FINAL MAP ==========" << endl;

    for (map<string, string>::iterator iter = mp.begin();
         iter != mp.end();
         ++iter)
    {
        cout << iter->first
             << " -> "
             << iter->second
             << endl;
    }

    // ========================================================================
    // 37. reverse iteration
    // ========================================================================
    //
    // map ko reverse order mein bhi iterate kar sakte hain.
    //
    //
    // Use:
    //
    //      rbegin()
    //      rend()
    //
    //
    // rbegin():
    //
    //      largest key se start.
    //
    //
    // rend():
    //
    //      reverse sequence ke end ke baad.
    //
    // ========================================================================

    cout << "\n========== REVERSE ITERATION ==========" << endl;

    for (map<string, string>::reverse_iterator rit = mp.rbegin();
         rit != mp.rend();
         ++rit)
    {
        cout << rit->first
             << " -> "
             << rit->second
             << endl;
    }

    // ========================================================================
    // 38. lower_bound()
    // ========================================================================
    //
    // lower_bound(key) first element ka iterator return karta hai
    // jiska key:
    //
    //      >= given key
    //
    //
    // Example:
    //
    //      mp.lower_bound("in")
    //
    // "in" ya uske baad ka first key return karega.
    //
    // ========================================================================

    map<string, string>::iterator lb = mp.lower_bound("in");

    cout << "\n========== lower_bound ==========" << endl;

    if (lb != mp.end())
    {
        cout << lb->first
             << " -> "
             << lb->second
             << endl;
    }

    // ========================================================================
    // 39. upper_bound()
    // ========================================================================
    //
    // upper_bound(key) first element ka iterator return karta hai
    // jiska key:
    //
    //      > given key
    //
    //
    // Example:
    //
    //      mp.upper_bound("in")
    //
    // "in" se strictly greater first key return karega.
    //
    // ========================================================================

    map<string, string>::iterator ub = mp.upper_bound("in");

    cout << "\n========== upper_bound ==========" << endl;

    if (ub != mp.end())
    {
        cout << ub->first
             << " -> "
             << ub->second
             << endl;
    }

    // ========================================================================
    // 40. equal_range()
    // ========================================================================
    //
    // equal_range(key) ek pair of iterators return karta hai:
    //
    //      {lower_bound(key), upper_bound(key)}
    //
    //
    // map mein unique keys hoti hain, isliye range normally
    // zero ya one matching element ko cover karti hai.
    //
    // ========================================================================

    pair<
        map<string, string>::iterator,
        map<string, string>::iterator>
        range = mp.equal_range("in");

    cout << "\n========== equal_range ==========" << endl;

    for (map<string, string>::iterator iter = range.first;
         iter != range.second;
         ++iter)
    {
        cout << iter->first
             << " -> "
             << iter->second
             << endl;
    }

    // ========================================================================
    // 41. swap()
    // ========================================================================
    //
    // map ke do maps ke contents swap kar sakte hain.
    //
    //
    //      mp1.swap(mp2);
    //
    // ========================================================================

    map<int, string> mapA;
    map<int, string> mapB;

    mapA[1] = "One";
    mapA[2] = "Two";

    mapB[10] = "Ten";
    mapB[20] = "Twenty";

    cout << "\n========== BEFORE SWAP ==========" << endl;

    cout << "mapA size = "
         << mapA.size()
         << endl;

    cout << "mapB size = "
         << mapB.size()
         << endl;

    mapA.swap(mapB);

    cout << "\n========== AFTER SWAP ==========" << endl;

    cout << "mapA size = "
         << mapA.size()
         << endl;

    cout << "mapB size = "
         << mapB.size()
         << endl;

    // ========================================================================
    // 42. map with INTEGER KEY
    // ========================================================================
    //
    // map sirf string keys ke liye nahi hai.
    //
    // Example:
    //
    //      map<int, string>
    //
    // ========================================================================

    map<int, string> students;

    students[103] = "Riya";
    students[101] = "Amit";
    students[102] = "Rahul";

    // ========================================================================
    // 43. INTEGER KEY AUTOMATIC SORTING
    // ========================================================================
    //
    // Insertion:
    //
    //      103
    //      101
    //      102
    //
    //
    // Iteration:
    //
    //      101
    //      102
    //      103
    //
    // ========================================================================

    cout << "\n========== INTEGER KEY MAP ==========" << endl;

    for (const auto &x : students)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ========================================================================
    // 44. map<pair<int,int>, string>
    // ========================================================================
    //
    // Pair khud bhi key ban sakta hai.
    //
    // Example:
    //
    //      map<pair<int,int>, string>
    //
    //
    // Pair ki lexicographical ordering ke according keys sorted hongi.
    //
    // ========================================================================

    map<pair<int, int>, string> pairMap;

    pairMap[{2, 20}] = "B";
    pairMap[{1, 10}] = "A";
    pairMap[{2, 10}] = "C";

    cout << "\n========== PAIR AS MAP KEY ==========" << endl;

    for (const auto &x : pairMap)
    {
        cout << "("
             << x.first.first
             << ", "
             << x.first.second
             << ") -> "
             << x.second
             << endl;
    }

    // ========================================================================
    // 45. map DOES NOT ALLOW DUPLICATE KEYS
    // ========================================================================
    //
    // Example:
    //
    //      map<int,string> m;
    //
    //      m[1] = "A";
    //      m[1] = "B";
    //
    //
    // Yahan two separate elements nahi banenge.
    //
    // Same key 1 ki value update ho jayegi:
    //
    //      1 -> B
    //
    //
    // Agar duplicate keys chahiye:
    //
    //      multimap
    //
    // use karo.
    //
    // ========================================================================

    // ========================================================================
    // 46. map vs multimap
    // ========================================================================
    //
    // map:
    //
    //      unique keys
    //
    //
    // multimap:
    //
    //      duplicate keys allowed
    //
    //
    // Example:
    //
    //      map<int,string>
    //
    //      1 -> Amit
    //      1 -> Rahul
    //
    // allowed as separate elements nahi.
    //
    //
    // multimap<int,string>:
    //
    //      1 -> Amit
    //      1 -> Rahul
    //
    // possible.
    //
    // ========================================================================

    // ========================================================================
    // 47. map ITERATOR MEMBER ACCESS
    // ========================================================================
    //
    // Iterator:
    //
    //      it
    //
    //
    // Current element:
    //
    //      *it
    //
    //
    // Key:
    //
    //      it->first
    //
    //
    // Value:
    //
    //      it->second
    //
    //
    // Equivalent:
    //
    //      (*it).first
    //      it->first
    //
    //
    //      (*it).second
    //      it->second
    //
    // ========================================================================

    // ========================================================================
    // 48. map DOES NOT SUPPORT [] WITH ITERATOR
    // ========================================================================
    //
    // Important:
    //
    //      it[0]
    //
    // map iterator ke liye normal indexing nahi hoti.
    //
    // map random-access container nahi hai.
    //
    // Iterator move karne ke liye:
    //
    //      ++it
    //      --it
    //
    // use kar sakte hain.
    //
    // ========================================================================

    // ========================================================================
    // 49. const_iterator
    // ========================================================================
    //
    // Read-only traversal ke liye const_iterator use kar sakte hain.
    //
    // ========================================================================

    cout << "\n========== CONST ITERATOR ==========" << endl;

    map<string, string>::const_iterator cit;

    for (cit = mp.begin();
         cit != mp.end();
         ++cit)
    {
        cout << cit->first
             << " -> "
             << cit->second
             << endl;
    }

    // ========================================================================
    // 50. map CHEAT SHEET
    // ========================================================================
    //
    /*

        ======================== map CHEAT SHEET ========================

        CREATE:

            map<string,string> mp;


        INSERT USING []:

            mp["in"] = "India";


        INSERT USING make_pair():

            mp.insert(make_pair("en", "England"));


        INSERT USING pair:

            pair<string,string> p;
            p.first = "br";
            p.second = "Brazil";
            mp.insert(p);


        INSERT USING initializer_list:

            mp.insert({"fr", "France"});


        EMPLACE:

            mp.emplace("de", "Germany");


        C++17 try_emplace:

            mp.try_emplace("jp", "Japan");


        C++17 insert_or_assign:

            mp.insert_or_assign("in", "Hindustan");


        ACCESS:

            mp["in"];
            mp.at("in");


        UPDATE:

            mp["in"] = "Hindustan";
            mp.at("in") = "Hindustan";


        SIZE:

            mp.size();


        EMPTY:

            mp.empty();


        CLEAR:

            mp.clear();


        ERASE BY KEY:

            mp.erase("in");


        ERASE BY ITERATOR:

            mp.erase(mp.begin());


        ERASE RANGE:

            mp.erase(mp.begin(), mp.end());


        SEARCH:

            mp.find("in");


        COUNT:

            mp.count("in");


        ITERATOR:

            map<string,string>::iterator it;


        BEGIN:

            it = mp.begin();


        END:

            it = mp.end();


        FORWARD ITERATION:

            for (auto it = mp.begin();
                 it != mp.end();
                 ++it)
            {
                cout << it->first;
                cout << it->second;
            }


        RANGE-BASED LOOP:

            for (const auto &x : mp)
            {
                cout << x.first;
                cout << x.second;
            }


        REVERSE ITERATION:

            for (auto it = mp.rbegin();
                 it != mp.rend();
                 ++it)
            {
                cout << it->first;
                cout << it->second;
            }


        LOWER BOUND:

            mp.lower_bound(key);


        UPPER BOUND:

            mp.upper_bound(key);


        EQUAL RANGE:

            mp.equal_range(key);


        SWAP:

            mp1.swap(mp2);
            swap(mp1, mp2);


        KEY:

            it->first


        VALUE:

            it->second


        IMPORTANT:

            map keys UNIQUE hoti hain.

            map keys SORTED ORDER mein hoti hain.

            Default order ASCENDING hota hai.

            [] missing key ko insert kar sakta hai.

            at() missing key par exception throw karta hai.

            find() iterator return karta hai.

            count() 0/1 existence batata hai.

            clear() all elements remove karta hai.

            erase() selected element/range remove karta hai.

            lower_bound() >= key wala first element deta hai.

            upper_bound() > key wala first element deta hai.

        ==================================================================
    */

    return 0;
}