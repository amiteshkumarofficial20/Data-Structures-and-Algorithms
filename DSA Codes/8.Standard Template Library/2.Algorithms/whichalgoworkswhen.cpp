/*
======================================================================
        STL ALGORITHMS vs STL CONTAINERS
        WHICH ALGORITHM WORKS WITH WHICH CONTAINER?
======================================================================


IMPORTANT RULE:

STL algorithms containers ke naam ke saath directly tied nahi hote.

Algorithms ITERATORS par kaam karte hain.

Isliye decide karne ke liye ki koi algorithm kisi container
par chalega ya nahi, hume dekhna hota hai:

        "Algorithm ko kis type ka iterator chahiye?"

----------------------------------------------------------------------
ITERATOR CATEGORIES
----------------------------------------------------------------------

1. Input Iterator
        ↓
    Read / forward traversal

2. Forward Iterator
        ↓
    Forward movement

3. Bidirectional Iterator
        ↓
    ++it
    --it

4. Random Access Iterator
        ↓
    ++it
    --it
    it + n
    it - n
    it[n]

5. Contiguous Iterator
        ↓
    Random access + elements contiguous memory mein


----------------------------------------------------------------------
COMMON CONTAINERS AND THEIR ITERATORS
----------------------------------------------------------------------

vector
    -> Random Access
    -> Contiguous

array
    -> Random Access
    -> Contiguous

deque
    -> Random Access

list
    -> Bidirectional

forward_list
    -> Forward

set
    -> Bidirectional

multiset
    -> Bidirectional

map
    -> Bidirectional

multimap
    -> Bidirectional

unordered_set
    -> Forward

unordered_multiset
    -> Forward

unordered_map
    -> Forward

unordered_multimap
    -> Forward


======================================================================
1. for_each()
======================================================================

Required iterator:

    Input Iterator

Works with:

    vector          -> YES
    array           -> YES
    deque           -> YES
    list            -> YES
    forward_list    -> YES
    set             -> YES
    multiset        -> YES
    map             -> YES
    multimap        -> YES
    unordered_set   -> YES
    unordered_map   -> YES


Why?

for_each() ko bas elements ko sequentially
visit karna hota hai.

It does NOT require:

    random access
    sorting
    modification of container structure


Example:

    for_each(
        v.begin(),
        v.end(),
        func
    );


======================================================================
2. find()
======================================================================

Required iterator:

    Input Iterator

Works with:

    vector          -> YES
    array           -> YES
    deque           -> YES
    list            -> YES
    forward_list    -> YES
    set             -> YES
    multiset        -> YES
    map             -> YES
    multimap        -> YES
    unordered_set   -> YES
    unordered_map   -> YES


Example:

    auto it = find(
        container.begin(),
        container.end(),
        value
    );


IMPORTANT:

find() kisi VALUE ko search karta hai.

Agar value milti hai:

    iterator to element

Agar nahi milti:

    container.end()


======================================================================
3. find_if()
======================================================================

Required iterator:

    Input Iterator

Works with:

    vector          -> YES
    array           -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> YES
    set              -> YES
    multiset         -> YES
    map              -> YES
    multimap         -> YES
    unordered_set    -> YES
    unordered_map    -> YES


Reason:

find_if() ko bas predicate/condition check karni hoti hai.

Example:

    find_if(
        v.begin(),
        v.end(),
        isEven
    );


======================================================================
4. count()
======================================================================

Required iterator:

    Input Iterator

Works with:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> YES
    set              -> YES
    multiset         -> YES
    map              -> YES
    multimap         -> YES
    unordered_set    -> YES
    unordered_map    -> YES


Reason:

count() simply har element ko compare karta hai.


======================================================================
5. count_if()
======================================================================

Required iterator:

    Input Iterator

Works with:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> YES
    set              -> YES
    multiset         -> YES
    map              -> YES
    multimap         -> YES
    unordered_set    -> YES
    unordered_map    -> YES


Reason:

Condition har element par check hoti hai.


======================================================================
6. reverse()
======================================================================

Required iterator:

    Bidirectional Iterator

Normally works with:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    set              -> NO
    multiset         -> NO
    map              -> NO
    multimap         -> NO


IMPORTANT:

Technically set/map iterators are bidirectional.

BUT:

    set/map ke elements modify nahi kiye ja sakte.

reverse() elements ko swap/rearrange karta hai.

set/map mein element values immutable hoti hain.

Therefore:

    reverse(set.begin(), set.end())
        -> NOT allowed


Example:

    vector<int> v = {
        1, 2, 3, 4
    };

    reverse(
        v.begin(),
        v.end()
    );

Result:

    4 3 2 1


======================================================================
7. sort()
======================================================================

Required iterator:

    Random Access Iterator

Works with:

    vector          -> YES
    array            -> YES
    deque            -> YES

Does NOT work with:

    list             -> NO
    forward_list      -> NO
    set               -> NO
    multiset          -> NO
    map               -> NO
    multimap          -> NO
    unordered_set     -> NO
    unordered_map     -> NO


WHY?

sort() ko Random Access Iterator chahiye.

It needs operations conceptually like:

    it + n
    it - n
    it[n]


vector:

    Random Access
        -> YES


array:

    Random Access
        -> YES


deque:

    Random Access
        -> YES


list:

    Bidirectional
        -> NO


forward_list:

    Forward
        -> NO


set/map:

    Bidirectional
        -> NO


For list, use:

    list.sort();


Example:

    list<int> li = {
        5, 2, 4, 1
    };

    li.sort();


======================================================================
8. rotate()
======================================================================

Required iterator:

    Forward Iterator

So iterator-category ke perspective se:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> YES
    set              -> NO
    multiset         -> NO
    map              -> NO
    multimap         -> NO
    unordered_set    -> NO
    unordered_map    -> NO


WHY set/map NO?

rotate() elements ki positions/value ordering ko
rearrange karta hai.

set/map apne elements ko modify/reorder nahi karne dete.

Isliye generic rotate() associative containers
par use nahi karna chahiye.


Example:

    vector:

        1 2 3 4 5

    rotate(
        v.begin(),
        v.begin() + 2,
        v.end()
    );

Result:

        3 4 5 1 2


LEFT ROTATE:

    rotate(
        begin,
        begin + k,
        end
    );


RIGHT ROTATE:

    rotate(
        begin,
        end - k,
        end
    );


======================================================================
9. unique()
======================================================================

Required iterator:

    Forward Iterator

Works with:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> YES


But NOT meaningfully usable for:

    set
    multiset

because these containers have their own ordering
and duplicate behavior.

IMPORTANT:

unique() CONSECUTIVE duplicates ko compact karta hai.

Example:

    1 1 2 2 3 3

After unique logical range:

    1 2 3


BUT:

    unique()

container ka size automatically reduce nahi karta.

Standard pattern:

    container.erase(
        unique(
            container.begin(),
            container.end()
        ),
        container.end()
    );


For ALL duplicates in a vector:

    sort(
        v.begin(),
        v.end()
    );

    v.erase(
        unique(
            v.begin(),
            v.end()
        ),
        v.end()
    );


======================================================================
10. partition()
======================================================================

Required iterator:

    Forward Iterator

Works with:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> YES


Does NOT work meaningfully with:

    set
    multiset
    map
    multimap
    unordered_set
    unordered_map

because partition rearranges elements.

Associative container elements cannot be rearranged
like a normal sequence.


Example:

    vector:

        1 2 3 4 5 6

Predicate:

    isEven


After partition:

        EVEN | ODD

Possible result:

        6 2 4 | 3 5 1


IMPORTANT:

partition() relative order preserve nahi karta.


======================================================================
11. stable_partition()
======================================================================

Required iterator:

    Bidirectional Iterator

Works with sequence containers that satisfy
the iterator/mutability requirements:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> NOT the normal iterator requirement


Purpose:

    partition + relative order preservation


Example:

    2 4 1 6 3

stable_partition(isEven)

    2 4 6 1 3


Even ka order:

    2 -> 4 -> 6

same raha.

Odd ka order:

    1 -> 3

same raha.


======================================================================
12. lower_bound()
======================================================================

IMPORTANT:

lower_bound() ko sorted range chahiye.

Iterator requirement:

    Forward Iterator

But complexity depends on iterator category.

Works with:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES

BUT:

    vector:
        O(log n)

    list:
        traversal ki wajah se O(n)


For set/map:

    Generic lower_bound() use karne ki jagah
    container ka MEMBER FUNCTION use karna better hai:

        s.lower_bound(x);

        mp.lower_bound(key);


Example:

    vector<int> v = {
        10, 20, 30, 40
    };

    auto it = lower_bound(
        v.begin(),
        v.end(),
        25
    );

Result:

    30


Meaning:

    first element >= target


======================================================================
13. upper_bound()
======================================================================

Similar to lower_bound().

Required:

    sorted range

Meaning:

    first element > target


Example:

    vector:

        10 20 30 30 40

    upper_bound(30)

    -> 40


For set/map:

    Prefer member function:

        s.upper_bound(x);

        mp.upper_bound(key);


======================================================================
14. binary_search()
======================================================================

Required:

    sorted range

Iterator requirement:

    Forward Iterator

Can work with sequence ranges having
appropriate iterators.

Example:

    vector<int> v = {
        10, 20, 30, 40
    };

    bool found =
        binary_search(
            v.begin(),
            v.end(),
            30
        );


IMPORTANT:

    binary_search()
    sorted range par use hota hai.


======================================================================
15. min_element()
======================================================================

Required:

    Forward Iterator

Works with:

    vector
    array
    deque
    list
    forward_list
    set
    map
    unordered containers


Returns:

    iterator to smallest element


Example:

    auto it = min_element(
        v.begin(),
        v.end()
    );


======================================================================
16. max_element()
======================================================================

Same concept as min_element().

Required:

    Forward Iterator

Works with basically all standard containers
that provide suitable traversal iterators.


Example:

    auto it = max_element(
        v.begin(),
        v.end()
    );


======================================================================
17. minmax_element()
======================================================================

Returns both:

    minimum
    maximum

as a pair of iterators.

Example:

    auto result =
        minmax_element(
            v.begin(),
            v.end()
        );

    cout << *result.first;
    cout << *result.second;


======================================================================
18. accumulate()
======================================================================

NOTE:

accumulate() <numeric> header mein hota hai,
<algorithm> mein nahi.

Required:

    Input Iterator

Works with:

    vector
    array
    deque
    list
    forward_list
    set
    map
    unordered_map
    etc.


Example:

    vector<int> v = {
        1, 2, 3, 4
    };

    int sum =
        accumulate(
            v.begin(),
            v.end(),
            0
        );


Result:

    10


======================================================================
19. transform()
======================================================================

Required:

    Input/Output style iterator requirements
    depending on the overload.

Common sequence containers:

    vector      -> YES
    array       -> YES
    deque       -> YES
    list        -> YES
    forward_list-> YES


Example:

    vector<int> v = {
        1, 2, 3
    };

    transform(
        v.begin(),
        v.end(),
        v.begin(),
        [](int x) {
            return x * 2;
        }
    );


Result:

    2 4 6


======================================================================
20. remove()
======================================================================

Required:

    Forward Iterator

Common mutable sequence containers:

    vector          -> YES
    array            -> YES
    deque            -> YES
    list             -> YES
    forward_list     -> YES


IMPORTANT:

remove() DOES NOT actually reduce vector size.

Standard pattern:

    v.erase(
        remove(
            v.begin(),
            v.end(),
            value
        ),
        v.end()
    );


For list:

    li.remove(value);

is usually preferred because list has its own
member function.


======================================================================
21. remove_if()
======================================================================

Same idea as remove(), but condition ke according.

Example:

    remove all even numbers:

    v.erase(
        remove_if(
            v.begin(),
            v.end(),
            isEven
        ),
        v.end()
    );


Works naturally with mutable sequence containers.


======================================================================
22. swap()
======================================================================

Generic swap() individual objects/containers ko swap
kar sakta hai when types support swapping.

Example:

    vector<int> a = {
        1, 2, 3
    };

    vector<int> b = {
        4, 5, 6
    };

    swap(a, b);


======================================================================
                    MASTER TABLE
======================================================================


Legend:

    ✅ = Works
    ❌ = Does not work / not appropriate
    ⭐ = Container has its own better/member operation


                         vector  array  deque  list  fwd_list
----------------------------------------------------------------
for_each                  ✅      ✅      ✅     ✅      ✅
find                      ✅      ✅      ✅     ✅      ✅
find_if                   ✅      ✅      ✅     ✅      ✅
count                     ✅      ✅      ✅     ✅      ✅
count_if                  ✅      ✅      ✅     ✅      ✅
min_element               ✅      ✅      ✅     ✅      ✅
max_element               ✅      ✅      ✅     ✅      ✅
lower_bound               ✅      ✅      ✅     ✅      ✅
upper_bound               ✅      ✅      ✅     ✅      ✅
binary_search             ✅      ✅      ✅     ✅      ✅

reverse                   ✅      ✅      ✅     ✅      ❌
sort                      ✅      ✅      ✅     ❌      ❌
rotate                    ✅      ✅      ✅     ✅      ✅
unique                    ✅      ✅      ✅     ✅      ✅
partition                 ✅      ✅      ✅     ✅      ✅
stable_partition          ✅      ✅      ✅     ✅      ❌


                         set   multiset  map  multimap
----------------------------------------------------------------
for_each                  ✅      ✅      ✅      ✅
find                      ✅      ✅      ✅      ✅
find_if                   ✅      ✅      ✅      ✅
count                     ✅      ✅      ✅      ✅
count_if                  ✅      ✅      ✅      ✅
min_element               ✅      ✅      ✅      ✅
max_element               ✅      ✅      ✅      ✅
lower_bound               ⭐      ⭐      ⭐      ⭐
upper_bound               ⭐      ⭐      ⭐      ⭐

reverse                   ❌      ❌      ❌      ❌
sort                      ❌      ❌      ❌      ❌
rotate                    ❌      ❌      ❌      ❌
unique                    ❌      ❌      ❌      ❌
partition                 ❌      ❌      ❌      ❌


======================================================================
                    MOST IMPORTANT EXCEPTIONS
======================================================================

1.

sort()

    vector   -> ✅
    array    -> ✅
    deque    -> ✅
    list     -> ❌

For list:

    list.sort();


---------------------------------------------------------------------

2.

find()

    vector   -> ✅
    list     -> ✅
    set      -> ✅
    map      -> ✅

But for set/map:

    container.find()

is usually better because it can exploit
the container's ordering/hash structure.


---------------------------------------------------------------------

3.

lower_bound()

Generic:

    lower_bound(
        begin,
        end,
        value
    )

works on suitable sorted ranges.

But:

    set.lower_bound()
    map.lower_bound()

are usually MUCH better choices.

Why?

Because set/map member functions use the
container's tree structure.


---------------------------------------------------------------------

4.

unordered_map

Generic:

    find()

works.

But:

    unordered_map.find()

is better.

Why?

Because it uses the hash table's lookup
instead of linearly scanning the entire container.


======================================================================
                    FINAL RULE TO MEMORIZE
======================================================================

Do NOT memorize:

    "sort = vector"

Instead memorize:

    sort
        -> Random Access Iterator

Then remember:

    vector  -> Random Access
    array   -> Random Access
    deque   -> Random Access


Similarly:

    find
        -> Input Iterator

Therefore many containers support it.


And:

    reverse
        -> Bidirectional Iterator

Therefore sequence containers like
vector/list support it, subject to mutability.


The CORE IDEA is:

            ALGORITHM
                ↓
        ITERATOR REQUIREMENT
                ↓
            CONTAINER
                ↓
        DOES IT SATISFY IT?


======================================================================
                    QUICK INTERVIEW REVISION
======================================================================

for_each()
    -> Input
    -> Almost all containers

find()
    -> Input
    -> Almost all containers

find_if()
    -> Input
    -> Almost all containers

count()
    -> Input
    -> Almost all containers

count_if()
    -> Input
    -> Almost all containers

reverse()
    -> Bidirectional
    -> Mutable sequence containers

sort()
    -> Random Access
    -> vector / array / deque

rotate()
    -> Forward
    -> Sequence containers

unique()
    -> Forward
    -> Mutable sequence containers

partition()
    -> Forward
    -> Mutable sequence containers

lower_bound()
    -> Forward + sorted range
    -> Prefer set/map member function for those containers

upper_bound()
    -> Forward + sorted range
    -> Prefer set/map member function for those containers

binary_search()
    -> Forward + sorted range

======================================================================
*/
/*
===============================================================================
                C++ STL ALGORITHMS — DETAILED REFERENCE
===============================================================================

This file explains:
    - What each algorithm does
    - Required iterator category
    - Which containers it works with
    - Which containers it does NOT work with / is not appropriate for
    - Why
    - Syntax, examples and complexity

CORE IDEA:
    STL algorithms usually work on iterator ranges:

        [first, last)

    Example:
        find(v.begin(), v.end(), 10);

    So ask:
        "Does this container provide the iterator required by
         this algorithm?"

===============================================================================
ITERATOR CATEGORIES
===============================================================================

Input Iterator
    -> Read and move forward.

Forward Iterator
    -> Move forward and support multiple passes.

Bidirectional Iterator
    -> Move both directions:
           ++it
           --it

Random Access Iterator
    -> Jump directly:
           it + n
           it - n
           it[n]
           it1 - it2

Contiguous Iterator
    -> Random-access style + elements stored contiguously.

===============================================================================
COMMON CONTAINER ITERATORS
===============================================================================

vector
    -> Random Access + Contiguous

array
    -> Random Access + Contiguous

deque
    -> Random Access

list
    -> Bidirectional

forward_list
    -> Forward

set / multiset
    -> Bidirectional

map / multimap
    -> Bidirectional

unordered_set / unordered_map
    -> Forward


===============================================================================
MASTER TABLE
===============================================================================

Legend:
    YES = normally works
    NO  = iterator requirement / mutability / semantics prevent it
    *   = important special note

Algorithm          vector array deque list fwd_list set/map unordered
----------------------------------------------------------------------
for_each             YES   YES   YES  YES    YES     YES      YES
find                 YES   YES   YES  YES    YES     YES      YES
find_if              YES   YES   YES  YES    YES     YES      YES
count                YES   YES   YES  YES    YES     YES      YES
count_if             YES   YES   YES  YES    YES     YES      YES
all_of               YES   YES   YES  YES    YES     YES      YES
any_of               YES   YES   YES  YES    YES     YES      YES
none_of              YES   YES   YES  YES    YES     YES      YES
min_element          YES   YES   YES  YES    YES     YES      YES
max_element          YES   YES   YES  YES    YES     YES      YES

reverse              YES   YES   YES  YES    NO      NO*      NO*
sort                 YES   YES   YES  NO     NO      NO       NO
stable_sort          YES   YES   YES  NO     NO      NO       NO
rotate               YES   YES   YES  YES    YES     NO*      NO*
unique               YES   YES   YES  YES    YES     NO*      NO*
partition            YES   YES   YES  YES    YES     NO*      NO*
stable_partition     YES   YES   YES  YES    NO      NO*      NO*
remove               YES   YES   YES  YES    YES     NO*      NO*
remove_if            YES   YES   YES  YES    YES     NO*      NO*
transform            YES   YES   YES  YES    YES     NO*      NO*
nth_element          YES   YES   YES  NO     NO      NO       NO
partial_sort         YES   YES   YES  NO     NO      NO       NO

lower_bound          YES   YES   YES  YES    YES     YES*     YES*
upper_bound          YES   YES   YES  YES    YES     YES*     YES*
binary_search        YES   YES   YES  YES    YES     YES*     YES*

accumulate           YES   YES   YES  YES    YES     YES      YES
inner_product        YES   YES   YES  YES    YES     YES      YES
partial_sum          YES   YES   YES  YES    YES     YES      YES
iota                 YES   YES   YES  YES    YES     NO*      NO*

NOTE:
"YES" means the generic algorithm's iterator/value requirements are
satisfied. It does not always mean it is the best operation for that
container.


===============================================================================
1. for_each()
===============================================================================

HEADER:
    <algorithm>

ITERATOR:
    Input Iterator

PURPOSE:
    Range ke har element par function call karna.

SYNTAX:
    for_each(first, last, function);

EXAMPLE:
    for_each(v.begin(), v.end(), printElement);

WORKS WITH:
    vector, array, deque, list, forward_list,
    set, map, unordered containers.

WHY?
    Sirf traversal chahiye; random access ki need nahi.

COMPLEXITY:
    O(n)


===============================================================================
2. find()
===============================================================================

ITERATOR:
    Input Iterator

PURPOSE:
    Specific value search karna.

RETURNS:
    Found     -> iterator to element
    Not found -> last

IMPORTANT:
    Returned iterator ko dereference karne se pehle:

        if (it != container.end())

    check karo.

WORKS WITH:
    Almost all standard containers.

IMPORTANT OPTIMIZATION:
    set/map/unordered containers mein member find() usually better hai:

        s.find(x);
        mp.find(key);
        us.find(x);
        um.find(key);

Generic find() normally linear traversal karta hai.

COMPLEXITY:
    Generic find -> O(n)


===============================================================================
3. find_if()
===============================================================================

ITERATOR:
    Input Iterator

PURPOSE:
    Predicate/condition satisfy karne wala first element.

Example:
    find_if(v.begin(), v.end(), isEven);

WORKS WITH:
    Almost all standard containers.

COMPLEXITY:
    O(n)


===============================================================================
4. count() / count_if()
===============================================================================

count:
    Specific value ki occurrences.

count_if:
    Predicate true hone wale elements.

ITERATOR:
    Input Iterator

WORKS WITH:
    Almost all standard containers.

COMPLEXITY:
    O(n)


===============================================================================
5. all_of() / any_of() / none_of()
===============================================================================

all_of:
    Kya ALL elements predicate satisfy karte hain?

any_of:
    Kya AT LEAST ONE element predicate satisfy karta hai?

none_of:
    Kya ZERO elements predicate satisfy karte hain?

ITERATOR:
    Input Iterator

WORKS WITH:
    Almost all standard containers.

COMPLEXITY:
    O(n), but may stop early.


===============================================================================
6. sort()
===============================================================================

HEADER:
    <algorithm>

REQUIRED:
    Random Access Iterator

WORKS:
    vector  -> YES
    array   -> YES
    deque   -> YES

DOES NOT WORK:
    list
    forward_list
    set/map
    unordered containers

WHY?
    Generic sort needs random-access operations such as:

        it + n
        it - n
        it[n]

list only has Bidirectional Iterator.

For list use:
    li.sort();

set/map are already ordered, so sorting is unnecessary.

COMPLEXITY:
    O(n log n) typical/required complexity for std::sort.

DESCENDING:
    sort(v.begin(), v.end(), greater<int>());


===============================================================================
7. stable_sort()
===============================================================================

REQUIRED:
    Random Access Iterator

WORKS:
    vector, array, deque

DOES NOT WORK:
    list, forward_list, associative/unordered containers.

DIFFERENCE:
    sort:
        Equal elements ka relative order preserve guaranteed nahi.

    stable_sort:
        Equal elements ka relative order preserve karta hai.

COMPLEXITY:
    Usually O(n log n), with implementation/storage details.


===============================================================================
8. reverse()
===============================================================================

REQUIRED:
    Bidirectional Iterator

WORKS:
    vector, array, deque, list

NOT APPROPRIATE:
    set/map/unordered containers

WHY?
    reverse() elements ko swap/rearrange karta hai.
    Associative container elements ki values arbitrarily modify nahi
    ki ja sakti because that could violate container invariants.

COMPLEXITY:
    O(n)


===============================================================================
9. rotate()
===============================================================================

REQUIRED:
    Forward Iterator

PURPOSE:
    Range ko circularly shift karna.

LEFT ROTATE BY k:
    rotate(v.begin(), v.begin() + k, v.end());

Example:
    1 2 3 4 5
    left rotate by 2
    -> 3 4 5 1 2

RIGHT ROTATE BY k:
    rotate(v.begin(), v.end() - k, v.end());

Sequence containers:
    vector / array / deque / list / forward_list -> YES

Associative containers:
    Not appropriate because their elements cannot be reordered.

COMPLEXITY:
    O(n)


===============================================================================
10. unique()
===============================================================================

REQUIRED:
    Forward Iterator + writable/mutable range

PURPOSE:
    CONSECUTIVE duplicates ko compact karta hai.

Example:
    1 1 2 2 3 3
    logical unique range -> 1 2 3

IMPORTANT:
    unique() vector ka size automatically reduce NAHI karta.

Use:
    v.erase(
        unique(v.begin(), v.end()),
        v.end()
    );

For ALL duplicates:
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

list has:
    li.unique();

set already unique hota hai.

COMPLEXITY:
    O(n)


===============================================================================
11. partition()
===============================================================================

REQUIRED:
    Forward Iterator + mutable range

PURPOSE:
    Predicate true elements ko ek side,
    false elements ko doosri side.

Example:
    1 2 3 4 5 6

    partition(isEven)

Possible:
    6 2 4 | 3 5 1

IMPORTANT:
    Relative order preserve guaranteed nahi.

RETURN:
    Partition point.

    [begin, point) -> predicate true
    [point, end)  -> predicate false

Works with mutable sequence containers:
    vector, array, deque, list, forward_list

Not appropriate for associative containers because their
elements cannot be rearranged.

COMPLEXITY:
    O(n)


===============================================================================
12. stable_partition()
===============================================================================

PURPOSE:
    partition + relative order preservation.

Example:
    2 4 1 6 3

    stable_partition(isEven)

    -> 2 4 6 1 3

REQUIRED:
    Bidirectional Iterator

Works:
    vector, array, deque, list

forward_list:
    NO, because it only provides Forward Iterator.

Associative containers:
    Not appropriate for rearranging.

COMPLEXITY:
    Depends on available memory/implementation; typically linear
    comparisons with possible extra movement.


===============================================================================
13. remove() / remove_if()
===============================================================================

REQUIRED:
    Forward Iterator + writable/mutable range

IMPORTANT:
    Generic remove() vector ka size reduce NAHI karta.

Use erase-remove idiom:

    v.erase(
        remove(v.begin(), v.end(), value),
        v.end()
    );

remove_if:
    Predicate ke basis par.

For list/forward_list, prefer member functions:

    li.remove(x);
    li.remove_if(pred);

WORKS:
    vector, array, deque, list, forward_list

NOT appropriate:
    set/map/unordered associative containers because their
    element values cannot be overwritten/rearranged this way.

COMPLEXITY:
    O(n)


===============================================================================
14. replace() / replace_if()
===============================================================================

REQUIRED:
    Forward Iterator + writable range

replace:
    Specific value ko another value se replace.

replace_if:
    Predicate true hone par replacement.

Example:
    replace(v.begin(), v.end(), 2, 99);

Works with mutable sequence containers.

Not appropriate for set/map keys/elements because they are not
arbitrarily assignable.


===============================================================================
15. transform()
===============================================================================

PURPOSE:
    Har element par transformation apply karna.

Example:
    transform(
        v.begin(),
        v.end(),
        v.begin(),
        [](int x) { return x * 2; }
    );

Result:
    1 2 3 -> 2 4 6

Works with mutable sequence ranges.

For associative containers:
    Read-only transformation into a separate output range may be
    possible, but modifying keys/elements in-place is not appropriate.


===============================================================================
16. lower_bound()
===============================================================================

REQUIREMENT:
    SORTED range.

ITERATOR:
    Forward Iterator minimum.

MEANING:
    First element >= target.

Example:
    10 20 30 40

    lower_bound(25) -> 30

WORKS:
    vector, array, deque, list, forward_list
    when range is sorted.

For set/map:
    Prefer member function:

        s.lower_bound(x);
        mp.lower_bound(key);

COMPLEXITY:
    With random-access iterators: O(log n) comparisons and logarithmic
    iterator movement.
    With weaker iterators, iterator movement can be O(n).


===============================================================================
17. upper_bound()
===============================================================================

REQUIREMENT:
    SORTED range.

MEANING:
    First element > target.

Example:
    10 20 30 30 40

    upper_bound(30) -> 40

For set/map:
    Prefer member function.


===============================================================================
18. binary_search()
===============================================================================

REQUIREMENT:
    SORTED range.

RETURNS:
    bool

Example:
    binary_search(v.begin(), v.end(), 30);

Works with suitable forward ranges.

For set/unordered containers, member lookup is usually preferred.


===============================================================================
19. min_element() / max_element()
===============================================================================

REQUIRED:
    Forward Iterator

PURPOSE:
    Minimum/maximum element ka iterator.

WORKS:
    Almost all readable standard containers.

COMPLEXITY:
    O(n)


===============================================================================
20. nth_element()
===============================================================================

REQUIRED:
    Random Access Iterator

WORKS:
    vector, array, deque

DOES NOT WORK:
    list, forward_list, set/map, unordered containers

PURPOSE:
    nth position par woh element aa jata hai jo sorted order mein
    nth position par hota.

Entire range sorted NAHI hota.

Useful for:
    kth smallest
    median

Average complexity:
    O(n)


===============================================================================
21. partial_sort()
===============================================================================

REQUIRED:
    Random Access Iterator

WORKS:
    vector, array, deque

DOES NOT WORK:
    list, forward_list, associative/unordered containers

PURPOSE:
    First k elements ko sorted form mein arrange karna.

Example:
    partial_sort(v.begin(), v.begin()+3, v.end());

COMPLEXITY:
    Approximately O(n log k).


===============================================================================
22. merge()
===============================================================================

REQUIREMENT:
    Input ranges SORTED honi chahiye.

PURPOSE:
    Do sorted ranges ko merge karna.

Example:
    A = 1 3 5
    B = 2 4 6

    result = 1 2 3 4 5 6

Works with suitable sequence ranges.


===============================================================================
23. SET RANGE ALGORITHMS
===============================================================================

These are range algorithms; "set" here does not mean std::set.

Algorithms:
    set_union
    set_intersection
    set_difference
    set_symmetric_difference

REQUIREMENT:
    Input ranges sorted honi chahiye.

Example:
    A = 1 2 3
    B = 2 3 4

    union:
        1 2 3 4

    intersection:
        2 3

    difference(A, B):
        1

    symmetric_difference:
        1 4


===============================================================================
24. ACCUMULATE()
===============================================================================

HEADER:
    <numeric>

PURPOSE:
    Range ko combine karke ONE final result.

Example:
    v = 1 2 3 4

    accumulate(v.begin(), v.end(), 0)
    -> 10

Works with many containers.

COMPLEXITY:
    O(n)


===============================================================================
25. INNER_PRODUCT()
===============================================================================

HEADER:
    <numeric>

PURPOSE:
    Two ranges ke corresponding elements ko combine karke
    final result.

Example:
    A = 1 2 3
    B = 4 5 6

    1*4 + 2*5 + 3*6
    = 32

Syntax:
    inner_product(
        A.begin(),
        A.end(),
        B.begin(),
        0
    );

IMPORTANT:
    Second range mein enough elements hone chahiye.

COMPLEXITY:
    O(n)


===============================================================================
26. PARTIAL_SUM()
===============================================================================

HEADER:
    <numeric>

PURPOSE:
    Prefix/running sums.

Input:
    1 2 3 4 5

Output:
    1 3 6 10 15

COMPLEXITY:
    O(n)


===============================================================================
27. IOTA()
===============================================================================

HEADER:
    <numeric>

PURPOSE:
    Consecutive values se range fill karna.

Example:
    vector<int> v(5);

    iota(v.begin(), v.end(), 10);

Result:
    10 11 12 13 14

Works with mutable output ranges.

Not appropriate for set/map because elements cannot be
arbitrarily assigned.


===============================================================================
28. reduce() — C++17
===============================================================================

HEADER:
    <numeric>

Similar to accumulate(), but reduction may regroup operations.

Useful for numeric reductions and parallel-friendly algorithms.

Example:
    reduce(v.begin(), v.end(), 0);

For simple left-to-right accumulation, accumulate() is often
easier to reason about.

===============================================================================
29. transform_reduce() — C++17
===============================================================================

Concept:
    transform + reduce.

Useful for:
    dot products
    numeric transformations followed by reduction.

===============================================================================
30. inclusive_scan() / exclusive_scan() — C++17
===============================================================================

inclusive_scan:
    Input:
        1 2 3 4
    Output:
        1 3 6 10

exclusive_scan:
    Input:
        1 2 3 4
    Output:
        0 1 3 6

===============================================================================
                    CONTAINER-SPECIFIC ALTERNATIVES
===============================================================================

LIST
----
Instead of generic algorithms where a list member exists, prefer:

    li.sort();
    li.unique();
    li.remove(x);
    li.remove_if(pred);
    li.merge(other);
    li.reverse();

Why?
    list can rearrange/unlink nodes without requiring random access.

FORWARD_LIST
------------
Has:
    fl.sort();
    fl.unique();
    fl.remove(x);
    fl.remove_if(pred);
    fl.reverse();
    fl.merge(other);

SET
---
Already sorted and unique.

Prefer:
    s.find(x);
    s.lower_bound(x);
    s.upper_bound(x);

MAP
---
Keys automatically sorted.

Prefer:
    mp.find(key);
    mp.lower_bound(key);
    mp.upper_bound(key);

UNORDERED_SET
-------------
Hash based.

Prefer:
    us.find(x);

UNORDERED_MAP
-------------
Hash based.

Prefer:
    um.find(key);

Generic find() on unordered containers is usually linear,
while member find() is average constant time.


===============================================================================
                    COMPLEXITY QUICK TABLE
===============================================================================

Algorithm               Typical complexity
------------------------------------------------
for_each                 O(n)
find                     O(n)
find_if                  O(n)
count                    O(n)
count_if                 O(n)
all_of                   O(n)
any_of                   O(n)
none_of                  O(n)
min_element              O(n)
max_element              O(n)

sort                     O(n log n)
stable_sort              O(n log n)
reverse                  O(n)
rotate                   O(n)
unique                   O(n)
partition                O(n)
remove                   O(n)
remove_if                O(n)
replace                  O(n)
replace_if               O(n)
transform                O(n)

binary_search            O(log n) comparisons on random access
lower_bound              O(log n) comparisons on random access
upper_bound              O(log n) comparisons on random access

nth_element              Average O(n)
partial_sort             O(n log k)

accumulate               O(n)
inner_product            O(n)
partial_sum              O(n)
iota                     O(n)


===============================================================================
                    IMPORTANT RULES TO MEMORIZE
===============================================================================

RULE 1:
    STL algorithms generally work on iterator ranges.

RULE 2:
    sort() requires Random Access Iterators.

        vector -> YES
        array  -> YES
        deque  -> YES
        list   -> NO

    For list:
        list.sort();

RULE 3:
    set/map are already ordered.
    Do not sort them.

RULE 4:
    Generic find() works broadly, but associative containers have
    optimized member find() functions.

RULE 5:
    unique() does not shrink a vector by itself.

        v.erase(unique(v.begin(), v.end()), v.end());

RULE 6:
    remove() does not shrink a vector by itself.

        v.erase(remove(v.begin(), v.end(), x), v.end());

RULE 7:
    lower_bound(), upper_bound(), binary_search() require sorted input.

RULE 8:
    set/map elements cannot be arbitrarily modified because doing so
    could violate their ordering invariants.

RULE 9:
    unordered containers use hashing, so member find() is normally
    preferred over generic linear find().

RULE 10:
    "Algorithm works with container" and "algorithm is the best
    operation for container" are two different questions.


===============================================================================
                    QUICK MEMORY MAP
===============================================================================

SIMPLE TRAVERSAL
    find
    count
    for_each
    all_of
    any_of
    none_of
        -> works with many containers

BIDIRECTIONAL
    reverse
        -> vector / array / deque / list

RANDOM ACCESS
    sort
    stable_sort
    nth_element
    partial_sort
        -> vector / array / deque

SORTED RANGE
    lower_bound
    upper_bound
    binary_search
    merge
    set_union
    set_intersection
        -> input range must be sorted

NUMERIC
    accumulate
    inner_product
    partial_sum
    iota
    reduce
        -> many iterator ranges

===============================================================================
                    FINAL CONCEPT
===============================================================================

Do NOT memorize:

    "sort = vector"

Memorize:

    "sort = Random Access Iterator"

Then:

    vector  -> Random Access -> sort YES
    array   -> Random Access -> sort YES
    deque   -> Random Access -> sort YES
    list    -> Bidirectional  -> generic sort NO

This iterator-based thinking is the correct way to understand
C++ STL algorithms.

===============================================================================
*/

// #include <iostream>
// #include <algorithm>
// #include <numeric>
// #include <vector>
// #include <array>
// #include <deque>
// #include <list>
// #include <forward_list>
// #include <set>
// #include <map>
// #include <unordered_set>
// #include <unordered_map>

// using namespace std;

// bool isEven(int x)
// {
//     return x % 2 == 0;
// }

// void printElement(int x)
// {
//     cout << x << ' ';
// }

// int main()
// {
//     /*
//     A small compilable demonstration.

//     The large section above is the actual detailed reference.
//     */

//     vector<int> v = {
//         10, 20, 30, 40, 50
//     };

//     // find() works with vector.
//     auto it = find(
//         v.begin(),
//         v.end(),
//         30
//     );

//     if (it != v.end())
//     {
//         cout << "find(): " << *it << '\n';
//     }

//     // accumulate() comes from <numeric>.
//     int sum = accumulate(
//         v.begin(),
//         v.end(),
//         0
//     );

//     cout << "accumulate(): "
//          << sum
//          << '\n';

//     // vector has Random Access Iterators, so sort() works.
//     sort(
//         v.begin(),
//         v.end()
//     );

//     cout << "sort(): ";

//     for (int x : v)
//     {
//         cout << x << ' ';
//     }

//     cout << '\n';

//     return 0;
// }