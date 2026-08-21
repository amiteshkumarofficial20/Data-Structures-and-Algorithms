#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    // ============================================================
    // PAIR + ITERATION IN C++
    // ============================================================
    //
    // IMPORTANT:
    //
    // std::pair khud ek container nahi hai.
    //
    // Isliye pair ke paas:
    //
    //      begin()
    //      end()
    //      iterator
    //
    // jaise functions nahi hote.
    //
    // Example:
    //
    // pair<int, string> p = {10, "Rahul"};
    //
    // Is pair mein sirf DO values hain:
    //
    //      p.first
    //      p.second
    //
    // Pair ko directly iterator se traverse nahi kar sakte.
    //
    // Lekin map ke andar har element ek pair hota hai.
    //
    // Example:
    //
    // map<int, string>
    //
    // internally conceptually:
    //
    //      {1, "Aman"}
    //      {2, "Rahul"}
    //      {3, "Riya"}
    //
    // Har element:
    //
    //      pair<const int, string>
    //
    // hota hai.
    //
    // Isliye map ko iterate karte waqt
    // hum pair ko access karte hain.
    //
    // ============================================================

    // ============================================================
    // CREATING A PAIR
    // ============================================================

    // pair ka syntax:
    //
    // pair<data_type_1, data_type_2> variable_name;
    //
    // Example:
    //
    // pair<int, string> p;
    //
    // Iska matlab:
    //
    // first  -> int
    // second -> string

    pair<int, string> p;

    // ============================================================
    // ASSIGNING VALUES TO PAIR
    // ============================================================

    // Pair ke andar do members hote hain:
    //
    //      first
    //      second
    //
    // first  -> first value
    // second -> second value

    p.first = 101;
    p.second = "Rahul";

    // Current pair:
    //
    //      first
    //      |
    //      v
    //     101
    //
    //      second
    //      |
    //      v
    //    "Rahul"

    // ============================================================
    // ACCESSING FIRST
    // ============================================================

    // p.first
    //
    // pair ki first value deta hai.

    cout << "First value: " << p.first << endl;

    // ============================================================
    // ACCESSING SECOND
    // ============================================================

    // p.second
    //
    // pair ki second value deta hai.

    cout << "Second value: " << p.second << endl;

    // ============================================================
    // CREATING PAIR DIRECTLY
    // ============================================================

    // Pair ko directly values ke saath bhi create kar sakte hain.

    pair<int, string> p2 = {102, "Aman"};

    cout << "\nSecond pair:" << endl;
    cout << "First value: " << p2.first << endl;
    cout << "Second value: " << p2.second << endl;

    // ============================================================
    // make_pair()
    // ============================================================

    // C++ mein make_pair() function bhi hota hai.
    //
    // Syntax:
    //
    //      make_pair(value1, value2)
    //
    // Compiler automatically appropriate pair type
    // create kar deta hai.

    pair<int, string> p3 = make_pair(103, "Riya");

    cout << "\nThird pair:" << endl;
    cout << "First value: " << p3.first << endl;
    cout << "Second value: " << p3.second << endl;

    // ============================================================
    // IMPORTANT:
    // PAIR IS NOT ITERABLE
    // ============================================================

    /*
        Agar hum likhen:

            pair<int, string> p = {10, "Hello"};

            p.begin();

        to ye WRONG hai.

        Reason:

        pair ek container nahi hai.

        pair mein sirf:

            first
            second

        do members hote hain.

        Pair mein:

            begin()
            end()
            iterator

        nahi hote.


        Isliye pair ko directly aise traverse nahi kar sakte:

            for(auto x : p)

        Ye bhi WRONG hai.

        Correct way:

            cout << p.first;
            cout << p.second;
    */

    // ============================================================
    // MAP
    // ============================================================

    // Ab actual IMPORTANT concept:
    //
    // MAP.
    //
    // std::map ek associative container hai.
    //
    // Ismein data KEY-VALUE form mein store hota hai.
    //
    // Example:
    //
    //      101 -> Rahul
    //      102 -> Aman
    //      103 -> Riya
    //      104 -> Neha
    //
    // Syntax:
    //
    //      map<key_type, value_type> map_name;

    map<int, string> students;

    // ============================================================
    // INSERTING ELEMENTS INTO MAP
    // ============================================================

    // Map mein pair insert kar sakte hain.

    students.insert({101, "Rahul"});
    students.insert({102, "Aman"});
    students.insert({103, "Riya"});
    students.insert({104, "Neha"});

    // Map conceptually:
    //
    //      KEY       VALUE
    //
    //      101  ->   Rahul
    //      102  ->   Aman
    //      103  ->   Riya
    //      104  ->   Neha
    //
    // Har element internally ek pair hai:
    //
    //      {101, "Rahul"}
    //      {102, "Aman"}
    //      {103, "Riya"}
    //      {104, "Neha"}

    // ============================================================
    // ACCESSING MAP ELEMENT USING KEY
    // ============================================================

    // map[key]
    //
    // key ke corresponding value return karta hai.

    cout << "\nValue of key 101: "
         << students[101]
         << endl;

    // ============================================================
    // MAP ITERATOR
    // ============================================================

    // Map ko iterator se traverse kar sakte hain.
    //
    // Iterator type:
    //
    //      map<int, string>::iterator
    //
    // Same concept jo list iterator mein tha:
    //
    //      list<int>::iterator
    //
    // Lekin yahan container map hai:
    //
    //      map<int, string>::iterator
    //
    // Iterator ek map element par point karega.
    //
    // Aur map ka ek element pair hota hai.

    map<int, string>::iterator it;

    // ============================================================
    // begin()
    // ============================================================

    // students.begin()
    //
    // map ke FIRST element par iterator return karta hai.

    it = students.begin();

    // ============================================================
    // DEREFERENCING MAP ITERATOR
    // ============================================================

    // *it
    //
    // current map element ko represent karta hai.
    //
    // Aur current map element ek pair hai.
    //
    // Conceptually:
    //
    //      *it
    //
    // is something like:
    //
    //      pair<const int, string>
    //
    //
    // Isliye hum:
    //
    //      (*it).first
    //
    // aur:
    //
    //      (*it).second
    //
    // use kar sakte hain.

    cout << "\nFirst map element:" << endl;

    cout << "Key: "
         << (*it).first
         << endl;

    cout << "Value: "
         << (*it).second
         << endl;

    // ============================================================
    // ARROW OPERATOR WITH ITERATOR
    // ============================================================

    // Iterator ke through pair ke members access karne ka
    // easier syntax hai:
    //
    //      it->first
    //      it->second
    //
    // Ye:
    //
    //      (*it).first
    //
    // ke equivalent hai.
    //
    // Aur:
    //
    //      (*it).second
    //
    // ke equivalent hai.

    cout << "\nUsing arrow operator:" << endl;

    cout << "Key: "
         << it->first
         << endl;

    cout << "Value: "
         << it->second
         << endl;

    // ============================================================
    // ++it
    // ============================================================

    // ++it iterator ko next map element par move karta hai.
    //
    // Suppose current:
    //
    //      it
    //      |
    //      v
    //   {101, Rahul}
    //
    // After:
    //
    //      ++it
    //
    // it next pair par chala jayega:
    //
    //      {102, Aman}

    ++it;

    cout << "\nAfter ++it:" << endl;

    cout << "Key: "
         << it->first
         << endl;

    cout << "Value: "
         << it->second
         << endl;

    // ============================================================
    // MOVING ITERATOR AGAIN
    // ============================================================

    ++it;

    cout << "\nAfter another ++it:" << endl;

    cout << "Key: "
         << it->first
         << endl;

    cout << "Value: "
         << it->second
         << endl;

    // ============================================================
    // MOVING ITERATOR BACKWARD
    // ============================================================

    // Map iterator bidirectional hota hai.
    //
    // Isliye:
    //
    //      ++it
    //
    // next element par ja sakta hai.
    //
    // Aur:
    //
    //      --it
    //
    // previous element par ja sakta hai.

    --it;

    cout << "\nAfter --it:" << endl;

    cout << "Key: "
         << it->first
         << endl;

    cout << "Value: "
         << it->second
         << endl;

    // ============================================================
    // end()
    // ============================================================

    // students.end()
    //
    // LAST element ko point nahi karta.
    //
    // Ye last element ke JUST AFTER position ko represent karta hai.
    //
    // Conceptually:
    //
    //
    //      {101, Rahul}
    //             |
    //      {102, Aman}
    //             |
    //      {103, Riya}
    //             |
    //      {104, Neha}
    //             |
    //           [END]
    //               ^
    //               |
    //             end()
    //
    //
    // IMPORTANT:
    //
    //      *students.end()
    //
    // INVALID hai.
    //
    // end() ko directly dereference nahi karna.

    it = students.end();

    // ============================================================
    // LAST ELEMENT USING end()
    // ============================================================

    // Since end() last element ke baad hota hai,
    // ek step backward jaana padega.

    --it;

    // Ab iterator last actual pair par hai:
    //
    //      {104, Neha}
    //            ^
    //            |
    //            it

    cout << "\nLast map element:" << endl;

    cout << "Key: "
         << it->first
         << endl;

    cout << "Value: "
         << it->second
         << endl;

    // ============================================================
    // FORWARD ITERATION USING ITERATOR
    // ============================================================

    // Iterator ko beginning par reset karte hain.

    it = students.begin();

    cout << "\nForward traversal using iterator:\n";

    // Jab tak iterator end() tak nahi pahunchta,
    // tab tak loop chalega.

    while (it != students.end())
    {
        // it->first
        // current pair ki key hai.

        cout << "Key = "
             << it->first;

        // it->second
        // current pair ki value hai.

        cout << ", Value = "
             << it->second
             << endl;

        // Iterator ko next pair par move karo.

        ++it;
    }

    // ============================================================
    // HOW THE LOOP WORKS
    // ============================================================

    /*
        Suppose map:

            101 -> Rahul
            102 -> Aman
            103 -> Riya
            104 -> Neha


        Initially:

            it = begin()

            it
            |
            v
          {101, Rahul}


        First iteration:

            print 101 Rahul

            ++it


        Now:

            it
            |
            v
          {102, Aman}


        Second iteration:

            print 102 Aman

            ++it


        Now:

            it
            |
            v
          {103, Riya}


        Third iteration:

            print 103 Riya

            ++it


        Now:

            it
            |
            v
          {104, Neha}


        Fourth iteration:

            print 104 Neha

            ++it


        Now:

            it == students.end()


        Condition:

            it != students.end()

        becomes FALSE.


        Therefore loop stops.
    */

    // ============================================================
    // RANGE-BASED FOR LOOP
    // ============================================================

    // Map ko range-based for loop se bhi iterate kar sakte hain.
    //
    // Syntax:
    //
    //      for(auto x : students)
    //
    // Har iteration mein x ek map element hoga.
    //
    // Aur map ka element pair hota hai.
    //
    // Isliye:
    //
    //      x.first
    //      x.second
    //
    // use kar sakte hain.

    cout << "\nRange-based traversal:\n";

    for (auto x : students)
    {
        cout << "Key = "
             << x.first
             << ", Value = "
             << x.second
             << endl;
    }

    // ============================================================
    // WHY auto?
    // ============================================================

    // Map ke element ka actual type thoda long hota hai:
    //
    //      pair<const int, string>
    //
    // Isko manually likhne ki zarurat nahi.
    //
    // auto compiler ko type automatically determine
    // karne deta hai.

    // ============================================================
    // const auto&
    // ============================================================

    // Agar hume sirf READ karna hai,
    // to:
    //
    //      const auto&
    //
    // ek achha option hai.
    //
    // const:
    //      element ko modify nahi karenge.
    //
    // auto:
    //      compiler type determine karega.
    //
    // &:
    //      unnecessary copy nahi banegi.

    cout << "\nUsing const auto&:\n";

    for (const auto &x : students)
    {
        cout << "Key = "
             << x.first
             << ", Value = "
             << x.second
             << endl;
    }

    // ============================================================
    // STRUCTURED BINDING
    // ============================================================

    // Modern C++ mein pair ko directly unpack kar sakte hain.
    //
    // Example:
    //
    //      for (auto &[key, value] : students)
    //
    // Yahan:
    //
    //      key
    //      value
    //
    // directly pair ke first aur second ko represent karenge.
    //
    // Ye C++17 feature hai.

    cout << "\nUsing structured binding:\n";

    for (const auto &[key, value] : students)
    {
        cout << "Key = "
             << key
             << ", Value = "
             << value
             << endl;
    }

    // ============================================================
    // STRUCTURED BINDING KA CONCEPT
    // ============================================================

    /*
        Suppose current pair:

            {101, "Rahul"}


        Normally:

            x.first
            x.second


        Structured binding:

            const auto &[key, value]


        Conceptually:

            key   -> 101
            value -> "Rahul"


        So:

            cout << key;
            cout << value;

        likhna easier ho jata hai.
    */

    // ============================================================
    // MAP REVERSE ITERATION
    // ============================================================

    // Since map iterator bidirectional hai,
    // hum backward bhi traverse kar sakte hain.
    //
    // Start:
    //
    //      students.end()
    //
    // Then:
    //
    //      --it
    //
    // karke last actual element par ja sakte hain.

    it = students.end();

    cout << "\nBackward traversal using iterator:\n";

    while (it != students.begin())
    {
        // Pehle iterator ko previous actual element par le jao.

        --it;

        // Ab iterator valid element par hai.

        cout << "Key = "
             << it->first
             << ", Value = "
             << it->second
             << endl;
    }

    // ============================================================
    // WHY --it BEFORE PRINTING?
    // ============================================================

    /*
        Suppose:

            students:

            {101, Rahul}
            {102, Aman}
            {103, Riya}
            {104, Neha}


        Initially:

            it = end()


        Agar hum directly:

            cout << it->first;

        karein,

        to WRONG hai.

        Kyunki:

            it == end()

        aur end() kisi actual element ko point nahi karta.


        Correct:

            while (it != students.begin())
            {
                --it;
                cout << it->first;
            }


        First iteration:

            it = end()

            --it

            it -> {104, Neha}

            print 104


        Second iteration:

            --it

            it -> {103, Riya}

            print 103


        Third iteration:

            --it

            it -> {102, Aman}

            print 102


        Fourth iteration:

            --it

            it -> {101, Rahul}

            print 101


        Now:

            it == students.begin()


        Loop stops.
    */

    // ============================================================
    // IMPORTANT DIFFERENCE:
    // PAIR vs MAP
    // ============================================================

    /*
        PAIR:

            pair<int, string> p;

        Pair mein:

            p.first
            p.second

        hote hain.

        Pair directly iterable nahi hai.


        MAP:

            map<int, string> students;

        Map ke andar multiple pairs hote hain:

            {101, Rahul}
            {102, Aman}
            {103, Riya}
            {104, Neha}


        Isliye map iterable hai.


        Map ka iterator:

            map<int, string>::iterator


        Current element:

            *it


        Current pair ki key:

            it->first


        Current pair ki value:

            it->second
    */

    // ============================================================
    // MOST IMPORTANT SYNTAX
    // ============================================================

    /*
        1. Iterator declaration:

            map<int, string>::iterator it;


        2. Start:

            it = students.begin();


        3. End condition:

            it != students.end()


        4. Current key:

            it->first


        5. Current value:

            it->second


        6. Next element:

            ++it


        7. Previous element:

            --it


        8. Range-based loop:

            for (auto x : students)


        9. Read-only efficient loop:

            for (const auto &x : students)


        10. Structured binding:

            for (const auto &[key, value] : students)
    */

    // ============================================================
    // RANDOM ACCESS DOES NOT WORK
    // ============================================================

    /*
        Map iterator ko vector iterator ki tarah
        random access nahi kar sakte.

        Ye WRONG hai:

            it + 2
            it - 2
            it[2]


        Example:

            it = students.begin();

            it + 2;

        WRONG.


        Agar 2 positions aage jaana hai,
        std::advance() use kar sakte hain:

            advance(it, 2);


        Lekin yaad rakho:

            std::map ka iterator random-access iterator
            nahi hota.
    */

    // ============================================================
    // advance()
    // ============================================================

    // Iterator ko multiple positions move karne ke liye:
    //
    //      advance(iterator, positions);
    //
    // Example:
    //
    // begin()
    //
    // {101, Rahul}
    //      |
    //      0 positions
    //
    // {102, Aman}
    //      |
    //      1 position
    //
    // {103, Riya}
    //      |
    //      2 positions

    it = students.begin();

    advance(it, 2);

    cout << "\nElement after advancing 2 positions:\n";

    cout << "Key = "
         << it->first
         << ", Value = "
         << it->second
         << endl;

    // ============================================================
    // PAIR AS A RETURN VALUE
    // ============================================================

    // Functions bhi pair return kar sakti hain.
    //
    // Example:
    //
    // Ek function student ID aur name return kare.

    // Is example ko hum lambda se demonstrate karenge.

    auto getStudent = []()
    {
        return make_pair(105, string("Karan"));
    };

    pair<int, string> result = getStudent();

    cout << "\nPair returned from function/lambda:\n";

    cout << "ID: "
         << result.first
         << endl;

    cout << "Name: "
         << result.second
         << endl;

    // ============================================================
    // FINAL SUMMARY
    // ============================================================

    /*
        ===================== PAIR =====================

        pair<int, string> p = {101, "Rahul"};

        First value:

            p.first


        Second value:

            p.second


        Pair DIRECTLY ITERABLE nahi hai.


        ===================== MAP =====================

        map<int, string> students;


        Map ka har element ek pair hai:

            {key, value}


        Iterator:

            map<int, string>::iterator it;


        Start:

            it = students.begin();


        End:

            students.end();


        Current pair:

            *it


        Current key:

            it->first


        Current value:

            it->second


        Next:

            ++it


        Previous:

            --it


        Forward traversal:

            while (it != students.end())
            {
                cout << it->first;
                cout << it->second;
                ++it;
            }


        Backward traversal:

            it = students.end();

            while (it != students.begin())
            {
                --it;
                cout << it->first;
                cout << it->second;
            }


        Range-based:

            for (auto x : students)
            {
                cout << x.first;
                cout << x.second;
            }


        Structured binding:

            for (const auto &[key, value] : students)
            {
                cout << key;
                cout << value;
            }


        ====================================================

        MOST IMPORTANT LINE:

            MAP KE ANDAR ELEMENT PAIR HOTA HAI.

        Isliye:

            map iterator
                    |
                    v
                  *it
                    |
                    v
                  pair
                 /    \
                /      \
             first    second
              |          |
             key        value

        Example:

            map:
                101 -> Rahul
                102 -> Aman
                103 -> Riya

        Iterator:

            it
            |
            v
          {101, Rahul}

        Therefore:

            it->first  = 101
            it->second = Rahul
    */

    return 0;
}