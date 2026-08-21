#include <iostream>
#include <map>

using namespace std;

int main()
{
    // ============================================================
    //                    ITERATION ON map
    // ============================================================
    //
    // map ek STL associative container hai.
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
    // IMPORTANT:
    //
    // std::map ORDERED container hai.
    //
    // Iske elements KEY ke according sorted order mein maintain
    // hote hain.
    //
    // Default ordering:
    //
    //      ASCENDING ORDER
    //
    //
    // Example:
    //
    // Agar hum insert karein:
    //
    //      "in"
    //      "en"
    //      "br"
    //
    // To iteration mein order hoga:
    //
    //      "br"
    //      "en"
    //      "in"
    //
    //
    // unordered_map se difference:
    //
    //      map
    //          -> ordered
    //          -> keys sorted
    //
    //      unordered_map
    //          -> unordered
    //          -> hashing based
    //
    //
    // map mein keys UNIQUE hoti hain.
    //
    // ============================================================

    // ============================================================
    // 1. CREATE map
    // ============================================================
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
    // ============================================================

    map<string, string> mp;

    // ============================================================
    // 2. INSERT DATA
    // ============================================================
    //
    // Iteration samajhne ke liye pehle kuch elements insert
    // karte hain.
    //
    // ============================================================

    mp["in"] = "India";
    mp["en"] = "England";
    mp["br"] = "Brazil";
    mp["us"] = "United States";
    mp["jp"] = "Japan";

    // ============================================================
    // 3. BASIC ITERATOR
    // ============================================================
    //
    // map ka iterator type:
    //
    //      map<string, string>::iterator
    //
    //
    // Iterator ek pointer-like object hota hai jo container ke
    // current element ko point karta hai.
    //
    // ============================================================

    map<string, string>::iterator it;

    // ============================================================
    // 4. begin()
    // ============================================================
    //
    // begin() ek iterator return karta hai jo map ke first
    // valid element ko point karta hai.
    //
    //
    // IMPORTANT:
    //
    // map ORDERED hai.
    //
    // Isliye begin() smallest key ko point karega
    // according to map ka comparison/order.
    //
    //
    // Example:
    //
    // Keys:
    //
    //      in
    //      en
    //      br
    //      us
    //      jp
    //
    //
    // Sorted order:
    //
    //      br
    //      en
    //      in
    //      jp
    //      us
    //
    //
    // Therefore:
    //
    //      mp.begin()
    //
    // "br" ko point karega.
    //
    // ============================================================

    it = mp.begin();

    // ============================================================
    // 5. DEREFERENCE ITERATOR
    // ============================================================
    //
    // Iterator current element ko point karta hai.
    //
    // Current element key-value pair hota hai.
    //
    //
    // Isliye:
    //
    //      *it
    //
    // current pair ko represent karta hai.
    //
    //
    // Pair ke:
    //
    //      first
    //          -> key
    //
    //      second
    //          -> value
    //
    //
    // Therefore:
    //
    //      (*it).first
    //          -> key
    //
    //      (*it).second
    //          -> value
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
    // (*it).first aur it->first same hain.
    //
    // Similarly:
    //
    //      (*it).second
    //
    // aur:
    //
    //      it->second
    //
    // same hain.
    //
    //
    // Arrow operator iterator ke through member access ko
    // short aur readable banata hai.
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
    // map ordered hone ki wajah se iterator next SMALLER TO
    // LARGER key order mein move karega.
    //
    //
    // Example:
    //
    //      br -> en -> in -> jp -> us
    //
    // Agar it "br" par hai:
    //
    //      ++it
    //
    // to "en" par move karega.
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
    // 9. COMPLETE ITERATION USING ITERATOR
    // ============================================================
    //
    // map ko complete iterate karne ka common method:
    //
    //
    //      for
    //      (
    //          iterator = mp.begin();
    //          iterator != mp.end();
    //          ++iterator
    //      )
    //
    //
    // Breakdown:
    //
    //      mp.begin()
    //          -> first valid element
    //
    //      iterator != mp.end()
    //          -> jab tak end tak nahi pahunchte
    //
    //      ++iterator
    //          -> next element
    //
    //
    // map ordered hone ke karan output sorted key order mein
    // aayega.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "4. COMPLETE ITERATION USING ITERATOR" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::iterator iter = mp.begin();
         iter != mp.end();
         ++iter)
    {
        // iter->first
        //      -> key

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
    // map mein begin() normally smallest key ko point karega.
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
    //      [br] [en] [in] [jp] [us] [END]
    //       ^
    //       |
    //     begin
    //
    //
    //                                      ^
    //                                      |
    //                                     end
    //
    //
    // IMPORTANT:
    //
    //      *mp.end()
    //
    // nahi karna chahiye.
    //
    // end() ko comparison ke liye use karte hain.
    //
    // ============================================================

    // ============================================================
    // 11. const_iterator
    // ============================================================
    //
    // Agar humein sirf map ko READ karna hai aur modify nahi
    // karna hai, to const_iterator use kar sakte hain.
    //
    //
    // Type:
    //
    //      map<string,string>::const_iterator
    //
    //
    // const_iterator ke through:
    //
    //      iter->first
    //      iter->second
    //
    // read kar sakte hain.
    //
    // Lekin element ko modify nahi kar sakte.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "5. const_iterator" << endl;
    cout << "==================================================" << endl;

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

    // ============================================================
    // 12. RANGE-BASED FOR LOOP
    // ============================================================
    //
    // C++11 se range-based for loop available hai.
    //
    // Syntax:
    //
    //      for (const auto &x : mp)
    //
    //
    // x current key-value pair ko represent karta hai.
    //
    //
    // x.first:
    //      key
    //
    // x.second:
    //      value
    //
    //
    // const:
    //      element ko modify nahi karna.
    //
    // auto:
    //      compiler automatically type determine karega.
    //
    // &:
    //      unnecessary copy avoid karta hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "6. RANGE-BASED FOR LOOP" << endl;
    cout << "==================================================" << endl;

    for (const auto &x : mp)
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
    // Agar value modify karni ho:
    //
    //      for (auto &x : mp)
    //
    // use kar sakte hain.
    //
    //
    // IMPORTANT:
    //
    // map mein:
    //
    //      x.first
    //
    // key hai.
    //
    // Key ko directly modify nahi kar sakte.
    //
    //
    // Lekin:
    //
    //      x.second
    //
    // value ko modify kar sakte hain.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "7. MODIFY VALUE DURING ITERATION" << endl;
    cout << "==================================================" << endl;

    for (auto &x : mp)
    {
        if (x.first == "in")
        {
            x.second = "Hindustan";
        }
    }

    // Updated map print.

    for (const auto &x : mp)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ============================================================
    // 14. ONLY KEYS
    // ============================================================
    //
    // Agar iteration ke time sirf keys print karni hain:
    //
    //      iter->first
    //
    // use karo.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "8. ONLY KEYS" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::iterator iter = mp.begin();
         iter != mp.end();
         ++iter)
    {
        cout << iter->first << endl;
    }

    // ============================================================
    // 15. ONLY VALUES
    // ============================================================
    //
    // Agar sirf values print karni hain:
    //
    //      iter->second
    //
    // use karo.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "9. ONLY VALUES" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::iterator iter = mp.begin();
         iter != mp.end();
         ++iter)
    {
        cout << iter->second << endl;
    }

    // ============================================================
    // 16. INDEXING?
    // ============================================================
    //
    // IMPORTANT:
    //
    // map vector/array nahi hai.
    //
    // Isliye:
    //
    //      mp[0]
    //
    // ka matlab "0th element" nahi hai.
    //
    //
    // map mein [] ka matlab:
    //
    //      given KEY ko access karna.
    //
    //
    // Example:
    //
    //      mp["in"]
    //
    // "in" key ki value access karega.
    //
    //
    // Agar key exist nahi karti:
    //
    //      mp["xyz"]
    //
    // new element create kar sakta hai.
    //
    //
    // Isliye iteration ke liye [] use nahi karte.
    //
    // Iteration ke liye:
    //
    //      iterator
    //      range-based for
    //
    // use karte hain.
    //
    // ============================================================

    // ============================================================
    // 17. find() + ITERATOR
    // ============================================================
    //
    // Kisi particular key ko search karne ke liye:
    //
    //      find()
    //
    // use kar sakte hain.
    //
    //
    // Example:
    //
    //      map<string,string>::iterator found;
    //
    //      found = mp.find("en");
    //
    //
    // Agar key milti hai:
    //
    //      found != mp.end()
    //
    //
    // Agar key nahi milti:
    //
    //      found == mp.end()
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "10. find() + ITERATOR" << endl;
    cout << "==================================================" << endl;

    map<string, string>::iterator found = mp.find("en");

    if (found != mp.end())
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
    // 18. find() FOR PARTICULAR KEY
    // ============================================================
    //
    // Example: "br" ko search karte hain.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "11. find() FOR BRAZIL" << endl;
    cout << "==================================================" << endl;

    map<string, string>::iterator brazilIt = mp.find("br");

    if (brazilIt != mp.end())
    {
        cout << "Key   = "
             << brazilIt->first
             << endl;

        cout << "Value = "
             << brazilIt->second
             << endl;
    }

    // ============================================================
    // 19. ITERATE FROM A PARTICULAR ITERATOR
    // ============================================================
    //
    // find() se kisi element ka iterator milne ke baad,
    // us position se end() tak iterate kar sakte hain.
    //
    //
    // Example:
    //
    //      startIt = mp.find("br");
    //
    //
    // Phir:
    //
    //      startIt -> next -> next -> ...
    //
    //
    // Since map ordered hai, traversal sorted key order mein
    // hi aage chalega.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "12. ITERATE FROM FOUND POSITION" << endl;
    cout << "==================================================" << endl;

    map<string, string>::iterator startIt = mp.find("br");

    if (startIt != mp.end())
    {
        for (map<string, string>::iterator iter = startIt;
             iter != mp.end();
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
    // Iterator ke through current element erase kar sakte hain:
    //
    //      mp.erase(it);
    //
    //
    // IMPORTANT:
    //
    // erase ke baad erased iterator invalid ho sakta hai.
    //
    //
    // Safe pattern:
    //
    //      it = mp.erase(it);
    //
    //
    // erase(iterator) next valid iterator return karta hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "13. ERASE WHILE ITERATING" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::iterator iter = mp.begin();
         iter != mp.end();)
    {
        if (iter->first == "jp")
        {
            // Current element delete.
            //
            // erase() next valid iterator return karega.

            iter = mp.erase(iter);
        }
        else
        {
            // Agar erase nahi kiya,
            // tab manually next element par move karo.

            ++iter;
        }
    }

    // Remaining elements print.

    for (const auto &x : mp)
    {
        cout << x.first
             << " -> "
             << x.second
             << endl;
    }

    // ============================================================
    // 21. WRONG ERASE PATTERN
    // ============================================================
    //
    // Ye pattern avoid karo:
    //
    //
    //      for (auto it = mp.begin();
    //           it != mp.end();
    //           ++it)
    //      {
    //          if (...)
    //          {
    //              mp.erase(it);
    //          }
    //      }
    //
    //
    // Problem:
    //
    // erase(it) ke baad it invalid ho sakta hai aur loop ka
    // ++it invalid iterator par operate kar sakta hai.
    //
    //
    // Correct:
    //
    //      for (auto it = mp.begin();
    //           it != mp.end();)
    //      {
    //          if (...)
    //              it = mp.erase(it);
    //          else
    //              ++it;
    //      }
    //
    // ============================================================

    // ============================================================
    // 22. ITERATOR AND at()
    // ============================================================
    //
    // Iterator se value:
    //
    //      it->second
    //
    //
    // at() se value:
    //
    //      mp.at("in")
    //
    //
    // Dono ka purpose existing value ko access karna ho sakta hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "14. ITERATOR vs at()" << endl;
    cout << "==================================================" << endl;

    map<string, string>::iterator indiaIt = mp.find("in");

    if (indiaIt != mp.end())
    {
        cout << "Using iterator: "
             << indiaIt->second
             << endl;

        cout << "Using at(): "
             << mp.at("in")
             << endl;
    }

    // ============================================================
    // 23. ITERATOR AND []
    // ============================================================
    //
    // [] operator:
    //
    //      mp[key]
    //
    // given key ki value access karta hai.
    //
    //
    // IMPORTANT:
    //
    // Agar key exist nahi karti, [] new element create kar
    // sakta hai.
    //
    //
    // Isliye sirf search karne ke liye:
    //
    //      find()
    //
    // better hai.
    //
    // ============================================================

    // ============================================================
    // 24. count() + ITERATION CONCEPT
    // ============================================================
    //
    // map mein keys UNIQUE hoti hain.
    //
    // Therefore:
    //
    //      mp.count(key)
    //
    // normally:
    //
    //      0 -> key absent
    //      1 -> key present
    //
    //
    // count() iterator return nahi karta.
    //
    // Agar actual element chahiye:
    //
    //      find()
    //
    // use karo.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "15. count() + find()" << endl;
    cout << "==================================================" << endl;

    if (mp.count("en"))
    {
        map<string, string>::iterator enIt = mp.find("en");

        if (enIt != mp.end())
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
    // Agar map empty hai:
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

    map<int, int> emptyMap;

    cout << "\n==================================================" << endl;
    cout << "16. EMPTY map ITERATION" << endl;
    cout << "==================================================" << endl;

    for (map<int, int>::iterator iter = emptyMap.begin();
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
    // 26. map<int,int> ITERATION
    // ============================================================
    //
    // map kisi bhi suitable key-value data type ke saath use
    // ho sakta hai.
    //
    // Example:
    //
    //      map<int,int>
    //
    // ============================================================

    map<int, int> numbers;

    numbers[4] = 400;
    numbers[1] = 100;
    numbers[3] = 300;
    numbers[2] = 200;

    // ============================================================
    // 27. INTEGER KEY AUTOMATIC SORTING
    // ============================================================
    //
    // Humne insertion kiya:
    //
    //      4
    //      1
    //      3
    //      2
    //
    //
    // Lekin map ordered hai.
    //
    // Iteration order:
    //
    //      1
    //      2
    //      3
    //      4
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "17. map<int,int> ITERATION" << endl;
    cout << "==================================================" << endl;

    for (map<int, int>::iterator iter = numbers.begin();
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
    // 28. ITERATION + MODIFY VALUE
    // ============================================================
    //
    // Value modify kar sakte hain:
    //
    //      iter->second = newValue;
    //
    //
    // Lekin:
    //
    //      iter->first = newKey;
    //
    // nahi kar sakte.
    //
    //
    // Reason:
    //
    // map key ke according ordered structure maintain karta hai.
    //
    // Key change karne se ordering structure break ho sakta hai.
    //
    // Isliye map element mein key effectively const hoti hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "18. ITERATOR SE VALUE MODIFY" << endl;
    cout << "==================================================" << endl;

    for (map<int, int>::iterator iter = numbers.begin();
         iter != numbers.end();
         ++iter)
    {
        iter->second += 10;
    }

    // Updated values print.

    for (map<int, int>::iterator iter = numbers.begin();
         iter != numbers.end();
         ++iter)
    {
        cout << iter->first
             << " -> "
             << iter->second
             << endl;
    }

    // ============================================================
    // 29. const_iterator SE MODIFY NAHI KAR SAKTE
    // ============================================================
    //
    // const_iterator READ-ONLY traversal ke liye hota hai.
    //
    //
    // Iske through:
    //
    //      iter->second = 100;
    //
    // nahi kar sakte.
    //
    // ============================================================

    // ============================================================
    // 30. MAP ELEMENT = KEY-VALUE PAIR
    // ============================================================
    //
    // map ka har element pair-like object hota hai.
    //
    //
    // Conceptually:
    //
    //      map<string,string>
    //
    // element:
    //
    //      pair<const string, string>
    //
    //
    // first:
    //
    //      key
    //
    // second:
    //
    //      value
    //
    //
    // IMPORTANT:
    //
    // key const hoti hai.
    //
    // value modify ki ja sakti hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "19. MAP ELEMENT = KEY-VALUE PAIR" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::const_iterator iter = mp.begin();
         iter != mp.end();
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
    // 31. REVERSE ITERATION
    // ============================================================
    //
    // map ko reverse order mein iterate karne ke liye:
    //
    //      rbegin()
    //      rend()
    //
    // use karte hain.
    //
    //
    // rbegin():
    //
    //      largest key ko point karta hai.
    //
    //
    // rend():
    //
    //      reverse traversal ke end ke BAAD wali position.
    //
    //
    // Example:
    //
    // Normal:
    //
    //      br -> en -> in -> us
    //
    // Reverse:
    //
    //      us -> in -> en -> br
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "20. REVERSE ITERATION" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::reverse_iterator rit = mp.rbegin();
         rit != mp.rend();
         ++rit)
    {
        cout << rit->first
             << " -> "
             << rit->second
             << endl;
    }

    // ============================================================
    // 32. lower_bound()
    // ============================================================
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
    //
    // "in" ya "in" se greater first key milegi.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "21. lower_bound()" << endl;
    cout << "==================================================" << endl;

    map<string, string>::iterator lb = mp.lower_bound("in");

    if (lb != mp.end())
    {
        cout << "Lower bound = "
             << lb->first
             << " -> "
             << lb->second
             << endl;
    }
    else
    {
        cout << "No lower bound found." << endl;
    }

    // ============================================================
    // 33. upper_bound()
    // ============================================================
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
    //
    // "in" se strictly greater first key milegi.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "22. upper_bound()" << endl;
    cout << "==================================================" << endl;

    map<string, string>::iterator ub = mp.upper_bound("in");

    if (ub != mp.end())
    {
        cout << "Upper bound = "
             << ub->first
             << " -> "
             << ub->second
             << endl;
    }
    else
    {
        cout << "No upper bound found." << endl;
    }

    // ============================================================
    // 34. equal_range()
    // ============================================================
    //
    // equal_range(key) do iterators return karta hai:
    //
    //      lower_bound(key)
    //
    //      upper_bound(key)
    //
    //
    // Return type:
    //
    //      pair<iterator, iterator>
    //
    //
    // map mein keys unique hoti hain, isliye normally ek key ke
    // liye range mein zero ya one matching element hota hai.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "23. equal_range()" << endl;
    cout << "==================================================" << endl;

    pair<
        map<string, string>::iterator,
        map<string, string>::iterator>
        range = mp.equal_range("in");

    for (map<string, string>::iterator iter = range.first;
         iter != range.second;
         ++iter)
    {
        cout << iter->first
             << " -> "
             << iter->second
             << endl;
    }

    // ============================================================
    // 35. FINAL COMPLETE ITERATION
    // ============================================================
    //
    // Ab poore map ko ek final time print karte hain.
    //
    // Ye output KEY ke sorted ascending order mein hoga.
    //
    // ============================================================

    cout << "\n==================================================" << endl;
    cout << "24. FINAL COMPLETE ITERATION" << endl;
    cout << "==================================================" << endl;

    for (map<string, string>::iterator iter = mp.begin();
         iter != mp.end();
         ++iter)
    {
        cout << iter->first
             << " -> "
             << iter->second
             << endl;
    }

    // ============================================================
    // 36. COMPLETE ITERATION SUMMARY
    // ============================================================
    //
    /*

        ============================================================
                    map ITERATION CHEAT SHEET
        ============================================================


        1. EXPLICIT ITERATOR

            map<string,string>::iterator it;

            for (it = mp.begin();
                 it != mp.end();
                 ++it)
            {
                cout << it->first;
                cout << it->second;
            }


        2. const_iterator

            map<string,string>::const_iterator it;

            for (it = mp.begin();
                 it != mp.end();
                 ++it)
            {
                cout << it->first;
                cout << it->second;
            }


        3. RANGE-BASED FOR LOOP

            for (const auto &x : mp)
            {
                cout << x.first;
                cout << x.second;
            }


        4. ONLY KEY

            for (auto it = mp.begin();
                 it != mp.end();
                 ++it)
            {
                cout << it->first;
            }


        5. ONLY VALUE

            for (auto it = mp.begin();
                 it != mp.end();
                 ++it)
            {
                cout << it->second;
            }


        6. REVERSE ITERATION

            for (auto it = mp.rbegin();
                 it != mp.rend();
                 ++it)
            {
                cout << it->first;
                cout << it->second;
            }


        7. SEARCH + ITERATOR

            auto it = mp.find("in");

            if (it != mp.end())
            {
                cout << it->first;
                cout << it->second;
            }


        8. ERASE WHILE ITERATING

            for (auto it = mp.begin();
                 it != mp.end();)
            {
                if (condition)
                {
                    it = mp.erase(it);
                }
                else
                {
                    ++it;
                }
            }


        ============================================================
                        IMPORTANT POINTS
        ============================================================


        1. map
               -> ordered associative container


        2. Keys
               -> unique


        3. Keys
               -> automatically sorted


        4. Default order
               -> ascending


        5. begin()
               -> first/smallest key


        6. end()
               -> one position after last element


        7. *it
               -> current key-value pair


        8. it->first
               -> key


        9. it->second
               -> value


        10. ++it
               -> next key in sorted order


        11. Key
               -> cannot be modified through iterator


        12. Value
               -> can be modified through non-const iterator


        13. find()
               -> iterator return karta hai


        14. find() == end()
               -> key not found


        15. count()
               -> 0 or 1 for map


        16. erase(iterator)
               -> current element remove karta hai


        17. range-based for
               -> easiest traversal method


        18. const_iterator
               -> read-only traversal


        19. rbegin()
               -> largest key


        20. rend()
               -> reverse traversal ke end ke baad


        21. lower_bound(key)
               -> first key >= given key


        22. upper_bound(key)
               -> first key > given key


        23. equal_range(key)
               -> {lower_bound, upper_bound}


        ============================================================
    */

    cout << "\n==================================================" << endl;
    cout << "              map ITERATION COMPLETE" << endl;
    cout << "==================================================" << endl;

    return 0;
}