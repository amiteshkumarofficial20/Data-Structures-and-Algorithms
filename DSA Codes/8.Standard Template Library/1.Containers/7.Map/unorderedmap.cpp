#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    // ========================================================================
    //                    STL : unordered_map
    // ========================================================================
    //
    // unordered_map ek ASSOCIATIVE CONTAINER hai.
    //
    // Iska use KEY-VALUE pairs ko store karne ke liye hota hai.
    //
    //
    // General Syntax:
    //
    //      unordered_map<KeyType, ValueType> variableName;
    //
    //
    // Example:
    //
    //      unordered_map<string, string> ump;
    //
    //
    // Yahan:
    //
    //      KeyType   = string
    //      ValueType = string
    //
    //
    // So hum aise data store kar sakte hain:
    //
    //      "in" -> "India"
    //      "en" -> "England"
    //      "br" -> "Brazil"
    //
    //
    // Conceptually:
    //
    //      KEY              VALUE
    //      -------------------------
    //      "in"       --->  "India"
    //      "en"       --->  "England"
    //      "br"       --->  "Brazil"
    //
    //
    // ========================================================================
    // IMPORTANT CHARACTERISTICS OF unordered_map
    // ========================================================================
    //
    // 1. Data KEY-VALUE pair mein store hota hai.
    //
    // 2. Keys UNIQUE hoti hain.
    //
    // 3. Same key ke multiple elements normally store nahi hote.
    //
    // 4. unordered_map hashing ka use karta hai.
    //
    // 5. Elements SORTED ORDER mein nahi hote.
    //
    // 6. Iteration order guaranteed nahi hota.
    //
    // 7. Average case mein search/insertion/deletion approximately O(1)
    //    hota hai.
    //
    // 8. Worst case theoretically O(n) ho sakta hai.
    //
    // ========================================================================

    // ========================================================================
    // 1. CREATING unordered_map
    // ========================================================================
    //
    // Syntax:
    //
    //      unordered_map<string, string> ump;
    //
    //
    // Iska matlab:
    //
    //      Key   = string
    //      Value = string
    //
    //
    // Initially:
    //
    //      ump = {}
    //
    // yani unordered_map empty hai.
    //
    // ========================================================================

    unordered_map<string, string> ump;

    // ========================================================================
    // 2. INSERTION USING [] OPERATOR
    // ========================================================================
    //
    // unordered_map mein data insert karne ka easiest way:
    //
    //      ump[key] = value;
    //
    //
    // Example:
    //
    //      ump["in"] = "India";
    //
    //
    // Yahan:
    //
    //      "in"    -> key
    //      "India" -> value
    //
    //
    // Map:
    //
    //      "in" ---> "India"
    //
    // ========================================================================

    ump["in"] = "India";

    // ========================================================================
    // 3. INSERTION USING insert(make_pair())
    // ========================================================================
    //
    // unordered_map ke andar pair store hota hai.
    //
    // Isliye hum:
    //
    //      make_pair(key, value)
    //
    // bana kar insert kar sakte hain.
    //
    //
    // Example:
    //
    //      ump.insert(make_pair("en", "England"));
    //
    //
    // make_pair:
    //
    //      {"en", "England"}
    //
    // banata hai.
    //
    // Phir insert():
    //
    //      unordered_map mein us pair ko insert karta hai.
    //
    // ========================================================================

    ump.insert(make_pair("en", "England"));

    // ========================================================================
    // 4. INSERTION USING pair OBJECT
    // ========================================================================
    //
    // Hum manually pair bana kar bhi unordered_map mein insert kar sakte hain.
    //
    //
    // pair<string, string> p;
    //
    // means:
    //
    //      first  -> string
    //      second -> string
    //
    // ========================================================================

    pair<string, string> p;

    // ========================================================================
    // 5. SETTING pair.first
    // ========================================================================
    //
    // pair ka first member first value ko store karta hai.
    //
    // Yahan:
    //
    //      p.first = "br";
    //
    // means:
    //
    //      key = "br"
    //
    // ========================================================================

    p.first = "br";

    // ========================================================================
    // 6. SETTING pair.second
    // ========================================================================
    //
    // pair ka second member second value ko store karta hai.
    //
    // Yahan:
    //
    //      p.second = "Brazil";
    //
    // means:
    //
    //      value = "Brazil"
    //
    // ========================================================================

    p.second = "Brazil";

    // ========================================================================
    // 7. INSERT pair INTO unordered_map
    // ========================================================================
    //
    // Ab p ke andar:
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
    // Is pair ko unordered_map mein insert karenge.
    //
    // ========================================================================

    ump.insert(p);

    // ========================================================================
    // CURRENT unordered_map
    // ========================================================================
    //
    // Ab unordered_map ke andar logically:
    //
    //      "in" ---> "India"
    //      "en" ---> "England"
    //      "br" ---> "Brazil"
    //
    //
    // IMPORTANT:
    //
    // Output mein order exactly isi order mein aaye, ye guaranteed nahi hai.
    //
    // unordered_map SORTED nahi hota.
    //
    // ========================================================================

    // ========================================================================
    // 8. size()
    // ========================================================================
    //
    // size() unordered_map mein currently kitne key-value pairs hain,
    // wo batata hai.
    //
    //
    // Syntax:
    //
    //      ump.size();
    //
    //
    // Current elements:
    //
    //      in
    //      en
    //      br
    //
    // Total:
    //
    //      3
    //
    // ========================================================================

    cout << "Size of Unordered Map is : "
         << ump.size()
         << endl;

    // ========================================================================
    // 9. ACCESS VALUE USING at()
    // ========================================================================
    //
    // at(key) given key ki value return karta hai.
    //
    //
    // Example:
    //
    //      ump.at("in")
    //
    //
    // returns:
    //
    //      "India"
    //
    //
    // IMPORTANT:
    //
    // Agar key exist nahi karti hai,
    // to at() exception throw karta hai.
    //
    // at() missing key ko automatically insert nahi karta.
    //
    // ========================================================================

    cout << ump.at("in") << endl;

    // ========================================================================
    // 10. ACCESS VALUE USING [] OPERATOR
    // ========================================================================
    //
    // Another way:
    //
    //      ump["en"]
    //
    //
    // Ye "en" key ki value return karega.
    //
    // Current:
    //
    //      "en" ---> "England"
    //
    // So output:
    //
    //      England
    //
    // ========================================================================

    cout << ump["en"] << endl;

    // ========================================================================
    // 11. at() SE VALUE UPDATE KARNA
    // ========================================================================
    //
    // at() sirf value read karne ke liye nahi hai.
    //
    // Existing value ko modify bhi kar sakte hain.
    //
    //
    // Example:
    //
    //      ump.at("in") = "Hindustan";
    //
    //
    // Before:
    //
    //      "in" ---> "India"
    //
    // After:
    //
    //      "in" ---> "Hindustan"
    //
    // ========================================================================

    ump.at("in") = "Hindustan";

    // Updated value print karna.

    cout << ump.at("in") << endl;

    // ========================================================================
    // 12. [] SE VALUE UPDATE KARNA
    // ========================================================================
    //
    // Existing key ki value ko [] se bhi update kar sakte hain.
    //
    //
    // Example:
    //
    //      ump["en"] = "Englaandd";
    //
    //
    // Before:
    //
    //      "en" ---> "England"
    //
    // After:
    //
    //      "en" ---> "Englaandd"
    //
    //
    // NOTE:
    //
    // "Englaandd" yahan sirf tumhare original example ko follow
    // karne ke liye rakha gaya hai.
    //
    // Correct spelling normally:
    //
    //      England
    //
    // ========================================================================

    ump["en"] = "Englaandd";

    // ========================================================================
    // 13. at() WITH UPDATED VALUE
    // ========================================================================
    //
    // Ab "en" ki updated value print karenge.
    //
    // IMPORTANT:
    //
    // Tumhare original code mein:
    //
    //      ump.at("en  ")
    //
    // tha.
    //
    // Yahan "en" ke baad EXTRA SPACES hain.
    //
    //
    //      "en"
    //
    // aur:
    //
    //      "en  "
    //
    // DIFFERENT keys hain.
    //
    //
    // unordered_map mein exact key match hoti hai.
    //
    // Isliye:
    //
    //      ump.at("en")
    //
    // correct hai.
    //
    // ========================================================================

    cout << ump.at("en") << endl;

    // ========================================================================
    // 14. clear()
    // ========================================================================
    //
    // clear() unordered_map ke SAARE elements remove kar deta hai.
    //
    //
    // Before clear():
    //
    //      "in"  ---> "Hindustan"
    //      "en"  ---> "Englaandd"
    //      "br"  ---> "Brazil"
    //
    //
    // After:
    //
    //      {}
    //
    //
    // Syntax:
    //
    //      ump.clear();
    //
    // ========================================================================

    ump.clear();

    // ========================================================================
    // 15. clear() KE BAAD size()
    // ========================================================================
    //
    // clear() ke baad size:
    //
    //      0
    //
    // ========================================================================

    cout << "Size of Unordered Map is : "
         << ump.size()
         << endl;

    // ========================================================================
    // 16. empty()
    // ========================================================================
    //
    // empty() check karta hai ki unordered_map empty hai ya nahi.
    //
    //
    // Return:
    //
    //      true  -> map empty hai
    //      false -> map empty nahi hai
    //
    //
    // Syntax:
    //
    //      ump.empty()
    //
    // ========================================================================

    if (ump.empty())
    {
        cout << "Unordered Map is Empty" << endl;
    }
    else
    {
        cout << "Unordered Map is not Empty" << endl;
    }

    // ========================================================================
    // 17. CLEAR KE BAAD DOBARA INSERTION
    // ========================================================================
    //
    // clear() karne ke baad unordered_map completely empty ho gaya tha.
    //
    // Ab hum dobara elements insert kar rahe hain.
    //
    // ========================================================================

    ump["in"] = "India";
    ump["en"] = "England";
    ump["br"] = "Brazil";
    ump["us"] = "United States";
    ump["jp"] = "Japan";

    // ========================================================================
    // 18. size() AFTER MULTIPLE INSERTIONS
    // ========================================================================

    cout << "Size of Unordered Map is : "
         << ump.size()
         << endl;

    // ========================================================================
    // 19. erase(begin(), end())
    // ========================================================================
    //
    // unordered_map mein range of elements erase kar sakte hain.
    //
    //
    //      ump.erase(ump.begin(), ump.end());
    //
    //
    // begin():
    //      first valid element
    //
    // end():
    //      one position after the last element
    //
    //
    // begin() se end() tak poora range erase karne ka matlab:
    //
    //      SAARE ELEMENTS DELETE.
    //
    //
    // Ye practically clear() jaisa result dega.
    //
    // ========================================================================

    ump.erase(ump.begin(), ump.end());

    // ========================================================================
    // 20. erase() KE BAAD size()
    // ========================================================================

    cout << "Size of Unordered Map is : "
         << ump.size()
         << endl;

    // ========================================================================
    // 21. DOBARA DATA INSERT KARNA
    // ========================================================================

    ump["in"] = "India";
    ump["en"] = "England";
    ump["br"] = "Brazil";
    ump["us"] = "United States";
    ump["jp"] = "Japan";

    // ========================================================================
    // 22. find()
    // ========================================================================
    //
    // find(key) given key ko search karta hai.
    //
    //
    // Syntax:
    //
    //      ump.find("in")
    //
    //
    // find() return karta hai:
    //
    //      iterator
    //
    //
    // Agar key mil gayi:
    //
    //      iterator != ump.end()
    //
    //
    // Agar key nahi mili:
    //
    //      iterator == ump.end()
    //
    //
    // IMPORTANT:
    //
    // find() missing key ko insert nahi karta.
    //
    // Isliye existence checking ke liye find() bahut useful hai.
    //
    // ========================================================================

    if (ump.find("in") != ump.end())
    {
        cout << "Key is Found" << endl;
    }
    else
    {
        cout << "Key is not Found" << endl;
    }

    // ========================================================================
    // 23. find() SE ITERATOR STORE KARNA
    // ========================================================================
    //
    // find() ka result directly iterator variable mein store kar sakte hain.
    //
    //
    // Syntax:
    //
    //      unordered_map<string,string>::iterator it;
    //
    //      it = ump.find("br");
    //
    //
    // Agar found:
    //
    //      it->first
    //      it->second
    //
    // se key/value access kar sakte hain.
    //
    // ========================================================================

    unordered_map<string, string>::iterator it = ump.find("br");

    if (it != ump.end())
    {
        cout << "Found Key   : "
             << it->first
             << endl;

        cout << "Found Value : "
             << it->second
             << endl;
    }

    // ========================================================================
    // 24. count()
    // ========================================================================
    //
    // count(key) batata hai ki given key unordered_map mein present hai
    // ya nahi.
    //
    //
    // unordered_map mein keys UNIQUE hoti hain.
    //
    // Therefore:
    //
    //      count(key)
    //
    // normally:
    //
    //      0 -> key NOT present
    //      1 -> key PRESENT
    //
    //
    // IMPORTANT:
    //
    // Tumhare original code mein:
    //
    //      if (ump.count("in") == 0)
    //      {
    //          cout << "Key is Found";
    //      }
    //
    // tha.
    //
    // Ye LOGICALLY WRONG hai.
    //
    //
    // count("in") == 0
    //
    // means:
    //
    //      "in" key NOT FOUND.
    //
    //
    // Correct condition:
    //
    //      count("in") != 0
    //
    // ya simply:
    //
    //      if (ump.count("in"))
    //
    // ========================================================================

    if (ump.count("in") != 0)
    {
        cout << "Key is Found" << endl;
    }
    else
    {
        cout << "Key is not Found" << endl;
    }

    // ========================================================================
    // 25. count() FOR A KEY THAT DOES NOT EXIST
    // ========================================================================
    //
    // Example:
    //
    //      "xyz"
    //
    // map mein nahi hai.
    //
    // So:
    //
    //      ump.count("xyz") == 0
    //
    // ========================================================================

    if (ump.count("xyz") == 0)
    {
        cout << "xyz Key is not Found" << endl;
    }
    else
    {
        cout << "xyz Key is Found" << endl;
    }

    // ========================================================================
    // 26. COMPLETE ITERATION
    // ========================================================================
    //
    // unordered_map ko iterator se traverse kar sakte hain.
    //
    //
    // IMPORTANT:
    //
    // unordered_map ka order FIXED/SORTED nahi hota.
    //
    // Output order:
    //
    //      in
    //      en
    //      br
    //
    // zaroori nahi.
    //
    // Hashing ki wajah se different order aa sakta hai.
    //
    // ========================================================================

    cout << "\n========== ITERATION ==========" << endl;

    for (unordered_map<string, string>::iterator iter = ump.begin();
         iter != ump.end();
         ++iter)
    {
        // iter->first
        //      -> key
        //
        // iter->second
        //      -> value

        cout << "Key = "
             << iter->first
             << ", Value = "
             << iter->second
             << endl;
    }

    // ========================================================================
    // 27. RANGE-BASED FOR LOOP
    // ========================================================================
    //
    // Modern C++ mein unordered_map ko easily:
    //
    //      for (const auto &x : ump)
    //
    // se iterate kar sakte hain.
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

    for (const auto &x : ump)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ========================================================================
    // 28. VALUE UPDATE DURING ITERATION
    // ========================================================================
    //
    // Non-const iterator/reference ke through value modify kar sakte hain.
    //
    // Key ko modify nahi kar sakte.
    //
    //
    // Example:
    //
    //      x.second = "New Value";
    //
    // ========================================================================

    for (auto &x : ump)
    {
        if (x.first == "us")
        {
            x.second = "USA";
        }
    }

    // Check updated value.

    cout << "\nUpdated US value = "
         << ump.at("us")
         << endl;

    // ========================================================================
    // 29. IMPORTANT DIFFERENCE: [] vs at()
    // ========================================================================
    //
    // ------------------------------------------------------------
    // [] OPERATOR
    // ------------------------------------------------------------
    //
    //      ump["in"]
    //
    // Existing key:
    //      value return karega.
    //
    // Missing key:
    //      NEW ELEMENT create kar sakta hai.
    //
    //
    // ------------------------------------------------------------
    // at()
    // ------------------------------------------------------------
    //
    //      ump.at("in")
    //
    // Existing key:
    //      value return karega.
    //
    // Missing key:
    //      exception throw karega.
    //
    //
    // Isliye:
    //
    // INSERT/UPDATE:
    //      [] convenient hai.
    //
    // SAFE ACCESS when key must exist:
    //      at() useful hai.
    //
    // SEARCH:
    //      find() useful hai.
    //
    // EXISTENCE CHECK:
    //      find() / count() useful hain.
    //
    // ========================================================================

    // ========================================================================
    // 30. FINAL SUMMARY
    // ========================================================================
    //
    /*

        ================= unordered_map CHEAT SHEET =================

        CREATE:

            unordered_map<string,string> ump;


        INSERT USING []:

            ump["in"] = "India";


        INSERT USING make_pair():

            ump.insert(make_pair("en", "England"));


        INSERT USING pair:

            pair<string,string> p;
            p.first = "br";
            p.second = "Brazil";
            ump.insert(p);


        ACCESS:

            ump["in"];
            ump.at("in");


        UPDATE:

            ump["in"] = "Hindustan";
            ump.at("in") = "Hindustan";


        SIZE:

            ump.size();


        EMPTY:

            ump.empty();


        CLEAR:

            ump.clear();


        ERASE BY KEY:

            ump.erase("in");


        ERASE BY ITERATOR:

            ump.erase(ump.begin());


        ERASE RANGE:

            ump.erase(ump.begin(), ump.end());


        SEARCH:

            ump.find("in");


        CHECK FOUND:

            if (ump.find("in") != ump.end())


        COUNT:

            ump.count("in");


        COUNT LOGIC:

            count == 0
                -> NOT FOUND

            count != 0
                -> FOUND


        ITERATOR:

            unordered_map<string,string>::iterator it;


        BEGIN:

            it = ump.begin();


        END:

            it = ump.end();


        ITERATION:

            for (auto it = ump.begin();
                 it != ump.end();
                 ++it)
            {
                cout << it->first;
                cout << it->second;
            }


        RANGE LOOP:

            for (const auto &x : ump)
            {
                cout << x.first;
                cout << x.second;
            }


        KEY:

            it->first


        VALUE:

            it->second


        IMPORTANT:

            unordered_map keys unique hoti hain.

            unordered_map sorted nahi hota.

            iteration order guaranteed nahi hota.

            [] missing key ko insert kar sakta hai.

            at() missing key par exception throw karta hai.

            find() iterator return karta hai.

            count() 0/1 existence batata hai.

            clear() all elements remove karta hai.

            erase() selected element/range remove karta hai.

        ============================================================
    */

    return 0;
}