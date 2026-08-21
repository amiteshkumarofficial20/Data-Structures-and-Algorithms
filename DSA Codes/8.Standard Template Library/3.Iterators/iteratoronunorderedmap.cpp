#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    // ============================================================
    //              ITERATION ON unordered_map
    // ============================================================
    //
    // unordered_map ek STL associative container hai.
    //
    // Isme data KEY-VALUE pair ke form mein store hota hai.
    //
    // Example:
    //
    //      Key        Value
    //      -------------------
    //      "in"       "India"
    //      "en"       "England"
    //      "br"       "Brazil"
    //
    //
    // unordered_map internally hashing ka use karta hai.
    //
    // IMPORTANT:
    //
    // unordered_map ke elements ki koi guaranteed sorted order
    // nahi hoti.
    //
    // Isliye agar output aaye:
    //
    //      br Brazil
    //      en England
    //      in India
    //
    // ya:
    //
    //      en England
    //      in India
    //      br Brazil
    //
    // dono possible hain.
    //
    // unordered_map mein iteration order ko rely nahi karna chahiye.
    //
    // ============================================================

    // ============================================================
    // 1. CREATE unordered_map
    // ============================================================
    //
    // Syntax:
    //
    //      unordered_map<KeyType, ValueType> name;
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
    //      unordered_map<string, string>
    //
    // means:
    //
    //      string key
    //      string value
    //
    // ============================================================

    unordered_map<string, string> ump;

    // ============================================================
    // 2. INSERT SOME DATA
    // ============================================================
    //
    // Iteration samajhne ke liye pehle kuch elements insert
    // kar dete hain.
    //
    // ============================================================

    ump["in"] = "India";
    ump["en"] = "England";
    ump["br"] = "Brazil";
    ump["us"] = "United States";
    ump["jp"] = "Japan";

    // ============================================================
    // 3. BASIC ITERATOR
    // ============================================================
    //
    // unordered_map ka iterator type:
    //
    //      unordered_map<string, string>::iterator
    //
    //
    // Iterator ko hum ek pointer-like object samajh sakte hain
    // jo container ke current element ko point karta hai.
    //
    // ============================================================

    unordered_map<string, string>::iterator it;

    // ============================================================
    // 4. begin()
    // ============================================================
    //
    // ump.begin() ek iterator return karta hai jo unordered_map
    // ke kisi valid first element ko point karta hai.
    //
    //
    // IMPORTANT:
    //
    // unordered_map mein "first" ka matlab sorted/smallest key
    // nahi hai.
    //
    // begin() jis bucket/order mein implementation element provide
    // karta hai, us position ko point karta hai.
    //
    // ============================================================

    it = ump.begin();

    // ============================================================
    // 5. DEREFERENCE ITERATOR
    // ============================================================
    //
    // Iterator current element ko point karta hai.
    //
    // Current element key-value pair hota hai.
    //
    //
    // Therefore:
    //
    //      *it
    //
    // current pair ko represent karta hai.
    //
    //
    // Aur pair ke:
    //
    //      first
    //      second
    //
    // members hote hain.
    //
    //
    // Isliye:
    //
    //      (*it).first
    //
    // key deta hai.
    //
    //
    //      (*it).second
    //
    // value deta hai.
    //
    // ============================================================

    cout << "==================================================" << endl;
    cout << "1. DEREFERENCE ITERATOR" << endl;
    cout << "==================================================" << endl;

    cout << "Key   = "
         << (*it).first
         << endl;

    cout << "Value = "
         << (*it).second
         << endl;

    // ============================================================
    // 6. ARROW OPERATOR ->
    // ============================================================
    //
    // (*it).first aur (*it).second ko short form mein:
    //
    //      it->first
    //      it->second
    //
    // likh sakte hain.
    //
    //
    // These two are equivalent:
    //
    //      (*it).first
    //      it->first
    //
    //
    // And:
    //
    //      (*it).second
    //      it->second
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "2. ARROW OPERATOR" << endl;
    cout << "==================================================" << endl;

    cout << "Key   = "
         << it->first
         << endl;

    cout << "Value = "
         << it->second
         << endl;

    // ============================================================
    // 7. ++it
    // ============================================================
    //
    // Iterator ko next element par move karne ke liye:
    //
    //      ++it
    //
    // use karte hain.
    //
    //
    // IMPORTANT:
    //
    // unordered_map mein next element ka order predictable/sorted
    // nahi hota.
    //
    // So:
    //
    //      ++it
    //
    // simply unordered_map ke iteration sequence mein next element
    // par move karega.
    //
    // ============================================================

    ++it;

    // ============================================================
    // 8. SECOND ELEMENT
    // ============================================================
    //
    // Ab iterator next element ko point kar raha hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "3. AFTER ++it" << endl;
    cout << "==================================================" << endl;

    cout << "Key   = "
         << it->first
         << endl;

    cout << "Value = "
         << it->second
         << endl;

    // ============================================================
    // 9. COMPLETE ITERATION USING for LOOP
    // ============================================================
    //
    // Sabse common iterator traversal:
    //
    //
    //      for
    //      (
    //          unordered_map<string,string>::iterator it = ump.begin();
    //          it != ump.end();
    //          ++it
    //      )
    //
    //
    // Breakdown:
    //
    //      ump.begin()
    //          -> first iteration position
    //
    //      it != ump.end()
    //          -> jab tak end tak nahi pahunchte
    //
    //      ++it
    //          -> next element
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "4. COMPLETE ITERATION USING ITERATOR" << endl;
    cout << "==================================================" << endl;

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

    // ============================================================
    // 10. begin() AND end()
    // ============================================================
    //
    // begin():
    //
    //      first valid element ko point karta hai.
    //
    //
    // end():
    //
    //      LAST ELEMENT ko point nahi karta.
    //
    // end() ek special position hai jo last element ke BAAD
    // hoti hai.
    //
    //
    // Conceptually:
    //
    //
    //      [element] [element] [element] [element] [END]
    //          ^
    //          |
    //        begin
    //
    //
    //                              ^
    //                              |
    //                             end
    //
    //
    // IMPORTANT:
    //
    //      *ump.end()
    //
    // nahi karna chahiye.
    //
    // end() ko sirf comparison ke liye use karte hain.
    //
    // ============================================================

    // ============================================================
    // 11. ITERATION WITH const_iterator
    // ============================================================
    //
    // Agar humein sirf data READ karna hai aur modify nahi karna,
    // to const_iterator use kar sakte hain.
    //
    //
    // Type:
    //
    //      unordered_map<string,string>::const_iterator
    //
    //
    // const_iterator ke through:
    //
    //      it->first
    //      it->second
    //
    // read kar sakte hain.
    //
    // But values ko modify nahi kar sakte.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "5. const_iterator" << endl;
    cout << "==================================================" << endl;

    unordered_map<string, string>::const_iterator cit;

    for (cit = ump.begin();
         cit != ump.end();
         ++cit)
    {
        cout << cit->first
             << " -> "
             << cit->second
             << endl;
    }

    // ============================================================
    // 12. RANGE-BASED FOR LOOP
    // ============================================================
    //
    // unordered_map ko range-based for loop se bhi iterate kar
    // sakte hain.
    //
    //
    // Syntax:
    //
    //      for (const auto &x : ump)
    //
    //
    // Yahan x ek key-value pair ko represent karta hai.
    //
    //
    // x.first
    //      -> key
    //
    // x.second
    //      -> value
    //
    //
    // const auto&:
    //
    //      const
    //          -> modify nahi karna
    //
    //      auto
    //          -> compiler type determine karega
    //
    //      &
    //          -> unnecessary copy avoid karta hai
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "6. RANGE-BASED FOR LOOP" << endl;
    cout << "==================================================" << endl;

    for (const auto &x : ump)
    {
        cout << "Key = "
             << x.first
             << ", Value = "
             << x.second
             << endl;
    }

    // ============================================================
    // 13. RANGE-BASED LOOP WITHOUT const
    // ============================================================
    //
    // Agar pair/value ko modify karna ho, const hata sakte hain.
    //
    //
    //      for (auto &x : ump)
    //
    //
    // But IMPORTANT:
    //
    // unordered_map mein:
    //
    //      x.first
    //
    // key hoti hai aur key ko modify nahi kar sakte.
    //
    // Key ko const treat kiya jata hai.
    //
    // Value:
    //
    //      x.second
    //
    // modify kar sakte ho.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "7. MODIFY VALUE DURING ITERATION" << endl;
    cout << "==================================================" << endl;

    for (auto &x : ump)
    {
        if (x.first == "in")
        {
            x.second = "Hindustan";
        }
    }

    for (const auto &x : ump)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ============================================================
    // 14. ITERATION + KEY
    // ============================================================
    //
    // Agar sirf keys print karni hain:
    //
    //      it->first
    //
    // use karo.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "8. ONLY KEYS" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, string>::iterator iter = ump.begin();
         iter != ump.end();
         ++iter)
    {
        cout << iter->first << endl;
    }

    // ============================================================
    // 15. ITERATION + VALUES
    // ============================================================
    //
    // Agar sirf values print karni hain:
    //
    //      it->second
    //
    // use karo.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "9. ONLY VALUES" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, string>::iterator iter = ump.begin();
         iter != ump.end();
         ++iter)
    {
        cout << iter->second << endl;
    }

    // ============================================================
    // 16. ITERATION WITH INDEX?
    // ============================================================
    //
    // IMPORTANT:
    //
    // unordered_map mein:
    //
    //      ump[0]
    //
    // ka matlab "first element" nahi hota.
    //
    // unordered_map vector nahi hai.
    //
    // Isliye:
    //
    //      ump[0]
    //
    // key = 0 search/insert karega (agar key type compatible ho).
    //
    //
    // Correct traversal:
    //
    //      iterator
    //      range-based for loop
    //
    // ============================================================

    // ============================================================
    // 17. ITERATOR SE PARTICULAR KEY SEARCH
    // ============================================================
    //
    // Agar kisi key ko search karke us element ko iterate/access
    // karna ho:
    //
    //      find()
    //
    // use kar sakte hain.
    //
    //
    // Example:
    //
    //      unordered_map<string,string>::iterator found;
    //
    //      found = ump.find("en");
    //
    //
    // Agar key milti hai:
    //
    //      found != ump.end()
    //
    //
    // Agar nahi milti:
    //
    //      found == ump.end()
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "10. find() + ITERATOR" << endl;
    cout << "==================================================" << endl;

    unordered_map<string, string>::iterator found = ump.find("en");

    if (found != ump.end())
    {
        cout << "Found key = "
             << found->first
             << endl;

        cout << "Found value = "
             << found->second
             << endl;
    }
    else
    {
        cout << "Key not found." << endl;
    }

    // ============================================================
    // 18. ITERATOR AFTER find()
    // ============================================================
    //
    // find() se returned iterator directly use kar sakte hain.
    //
    // Example:
    //
    //      auto it = ump.find("br");
    //
    //      if (it != ump.end())
    //      {
    //          cout << it->second;
    //      }
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "11. find() FOR BRAZIL" << endl;
    cout << "==================================================" << endl;

    unordered_map<string, string>::iterator brazilIt = ump.find("br");

    if (brazilIt != ump.end())
    {
        cout << "Key   = " << brazilIt->first << endl;
        cout << "Value = " << brazilIt->second << endl;
    }

    // ============================================================
    // 19. ITERATE FROM A PARTICULAR ITERATOR
    // ============================================================
    //
    // Iterator ko kisi found element par set karke wahan se
    // आगे iterate kar sakte hain.
    //
    // But unordered_map mein iteration order arbitrary hota hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "12. ITERATE FROM FOUND POSITION" << endl;
    cout << "==================================================" << endl;

    unordered_map<string, string>::iterator startIt = ump.find("br");

    if (startIt != ump.end())
    {
        for (unordered_map<string, string>::iterator iter = startIt;
             iter != ump.end();
             ++iter)
        {
            cout << iter->first
                 << " -> "
                 << iter->second
                 << endl;
        }
    }

    // ============================================================
    // 20. ITERATOR + ERASE
    // ============================================================
    //
    // Iterator se current element erase kar sakte hain:
    //
    //      ump.erase(it);
    //
    //
    // IMPORTANT:
    //
    // erase ke baad wahi iterator invalid ho sakta hai.
    //
    // Modern C++ mein safe pattern:
    //
    //      it = ump.erase(it);
    //
    //
    // unordered_map::erase(iterator) next iterator return karta hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "13. ERASE WHILE ITERATING" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, string>::iterator iter = ump.begin();
         iter != ump.end();)
    {
        if (iter->first == "jp")
        {
            // Erase current element.
            //
            // Returned iterator next valid element ko point karega.

            iter = ump.erase(iter);
        }
        else
        {
            // Only move forward when we did NOT erase.

            ++iter;
        }
    }

    // Print remaining elements.

    for (const auto &x : ump)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ============================================================
    // 21. IMPORTANT: DO NOT INVALIDATE ITERATOR CARELESSLY
    // ============================================================
    //
    // WRONG pattern:
    //
    //      for (auto it = ump.begin(); it != ump.end(); ++it)
    //      {
    //          if (...)
    //          {
    //              ump.erase(it);
    //          }
    //      }
    //
    // Problem:
    //
    // erase(it) ke baad loop ka ++it invalid iterator par
    // operate kar sakta hai.
    //
    //
    // Better:
    //
    //      for (auto it = ump.begin(); it != ump.end();)
    //      {
    //          if (...)
    //              it = ump.erase(it);
    //          else
    //              ++it;
    //      }
    //
    // ============================================================

    // ============================================================
    // 22. ITERATOR AND at()
    // ============================================================
    //
    // Iterator se value access:
    //
    //      it->second
    //
    //
    // at() se:
    //
    //      ump.at(key)
    //
    //
    // Example:
    //
    //      ump.at("in")
    //
    // key ki value deta hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "14. ITERATOR vs at()" << endl;
    cout << "==================================================" << endl;

    unordered_map<string, string>::iterator indiaIt = ump.find("in");

    if (indiaIt != ump.end())
    {
        cout << "Using iterator: "
             << indiaIt->second
             << endl;

        cout << "Using at(): "
             << ump.at("in")
             << endl;
    }

    // ============================================================
    // 23. ITERATOR AND []
    // ============================================================
    //
    // [] operator key ki value access karta hai.
    //
    // But:
    //
    //      ump[key]
    //
    // Agar key exist nahi karti,
    // to new element create kar sakta hai.
    //
    //
    // Iterator:
    //
    //      find()
    //
    // better hai jab humein sirf check/search karna ho aur
    // accidental insertion nahi chahiye.
    //
    // ============================================================

    // ============================================================
    // 24. count() WITH ITERATION CONCEPT
    // ============================================================
    //
    // unordered_map mein keys unique hoti hain.
    //
    // Therefore:
    //
    //      ump.count(key)
    //
    // result normally:
    //
    //      0 -> key absent
    //      1 -> key present
    //
    //
    // count() iterator return nahi karta.
    // Lekin count se existence check karke find/iteration kar
    // sakte hain.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "15. count() + find()" << endl;
    cout << "==================================================" << endl;

    if (ump.count("en"))
    {
        unordered_map<string, string>::iterator enIt = ump.find("en");

        if (enIt != ump.end())
        {
            cout << enIt->first
                 << " -> "
                 << enIt->second
                 << endl;
        }
    }

    // ============================================================
    // 25. EMPTY MAP ITERATION
    // ============================================================
    //
    // Agar unordered_map empty hai:
    //
    //      begin() == end()
    //
    //
    // Isliye:
    //
    //      for (it = begin(); it != end(); ++it)
    //
    // automatically zero times chalega.
    //
    // ============================================================

    unordered_map<int, int> emptyMap;

    cout << "\n==================================================" << endl;
    cout << "16. EMPTY unordered_map ITERATION" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, int>::iterator iter = emptyMap.begin();
         iter != emptyMap.end();
         ++iter)
    {
        cout << iter->first
             << " -> "
             << iter->second
             << endl;
    }

    cout << "Loop completed because map is empty." << endl;

    // ============================================================
    // 26. ITERATION OF int -> int unordered_map
    // ============================================================

    unordered_map<int, int> numbers;

    numbers[1] = 100;
    numbers[2] = 200;
    numbers[3] = 300;
    numbers[4] = 400;

    cout << "\n==================================================" << endl;
    cout << "17. unordered_map<int,int> ITERATION" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, int>::iterator iter = numbers.begin();
         iter != numbers.end();
         ++iter)
    {
        cout << "Key = "
             << iter->first
             << ", Value = "
             << iter->second
             << endl;
    }

    // ============================================================
    // 27. ITERATION + MODIFY VALUE
    // ============================================================
    //
    // Value modify kar sakte hain:
    //
    //      iter->second = newValue;
    //
    // Key modify nahi kar sakte:
    //
    //      iter->first = newKey;   // ERROR
    //
    // Because unordered_map ka key const nature ka hota hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "18. ITERATOR SE VALUE MODIFY" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<int, int>::iterator iter = numbers.begin();
         iter != numbers.end();
         ++iter)
    {
        iter->second += 10;
    }

    for (unordered_map<int, int>::iterator iter = numbers.begin();
         iter != numbers.end();
         ++iter)
    {
        cout << iter->first
             << " -> "
             << iter->second
             << endl;
    }

    // ============================================================
    // 28. const_iterator SE MODIFY NAHI KAR SAKTE
    // ============================================================
    //
    // Ye READ-only traversal ke liye hai.
    //
    //      const_iterator
    //
    // ke through:
    //
    //      iter->second = 100;
    //
    // invalid hoga.
    //
    // ============================================================

    // ============================================================
    // 29. ITERATION WITH PAIR TYPE
    // ============================================================
    //
    // unordered_map ka element pair-like object hota hai.
    //
    // Conceptually:
    //
    //      unordered_map<string,string>
    //
    // element:
    //
    //      pair<const string, string>
    //
    //
    // first:
    //      const string key
    //
    // second:
    //      string value
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "19. MAP ELEMENT = KEY-VALUE PAIR" << endl;
    cout << "==================================================" << endl;

    for (unordered_map<string, string>::const_iterator iter = ump.begin();
         iter != ump.end();
         ++iter)
    {
        cout << "first  (key)   = "
             << iter->first
             << endl;

        cout << "second (value) = "
             << iter->second
             << endl;

        cout << "------------------------" << endl;
    }

    // ============================================================
    // 30. FINAL ITERATION SUMMARY
    // ============================================================
    //
    /*
        MOST IMPORTANT WAYS TO ITERATE unordered_map:

        ------------------------------------------------------------
        METHOD 1: Explicit iterator
        ------------------------------------------------------------

        unordered_map<string,string>::iterator it;

        for (it = ump.begin(); it != ump.end(); ++it)
        {
            cout << it->first;
            cout << it->second;
        }


        ------------------------------------------------------------
        METHOD 2: const_iterator
        ------------------------------------------------------------

        unordered_map<string,string>::const_iterator it;

        for (it = ump.begin(); it != ump.end(); ++it)
        {
            cout << it->first;
            cout << it->second;
        }


        ------------------------------------------------------------
        METHOD 3: Range-based for loop
        ------------------------------------------------------------

        for (const auto &x : ump)
        {
            cout << x.first;
            cout << x.second;
        }


        ------------------------------------------------------------
        METHOD 4: Search + iterator
        ------------------------------------------------------------

        auto it = ump.find("in");

        if (it != ump.end())
        {
            cout << it->first;
            cout << it->second;
        }


        ------------------------------------------------------------
        METHOD 5: Erase while iterating
        ------------------------------------------------------------

        for (auto it = ump.begin(); it != ump.end();)
        {
            if (condition)
            {
                it = ump.erase(it);
            }
            else
            {
                ++it;
            }
        }


        ============================================================

        KEY POINTS:

        1. begin()
              -> valid first iteration position

        2. end()
              -> one position after last element

        3. *it
              -> current key-value pair

        4. it->first
              -> key

        5. it->second
              -> value

        6. ++it
              -> next element

        7. unordered_map order
              -> NOT sorted
              -> NOT guaranteed

        8. Key
              -> cannot be modified through iterator

        9. Value
              -> can be modified through non-const iterator

        10. find()
              -> returns iterator

        11. find() == end()
              -> key not found

        12. erase(iterator)
              -> removes current element and returns next iterator

        13. range-based for
              -> easiest way to traverse

        14. const_iterator
              -> read-only traversal

        ============================================================
    */

    cout << "\n==================================================" << endl;
    cout << "           unordered_map ITERATION COMPLETE" << endl;
    cout << "==================================================" << endl;

    return 0;
}