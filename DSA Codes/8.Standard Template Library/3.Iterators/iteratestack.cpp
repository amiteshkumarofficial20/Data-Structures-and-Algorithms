#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    // ============================================================
    // ITERATORS ON STACK
    // ============================================================
    //
    // IMPORTANT:
    //
    // std::stack DOES NOT provide public begin() and end()
    // functions.
    //
    // Therefore, unlike vector and list:
    //
    // stack<int>::iterator it;   // ❌ Not available
    //
    // and:
    //
    // st.begin();                // ❌ Not available
    // st.end();                  // ❌ Not available
    //
    // This is because stack is a CONTAINER ADAPTOR.
    //
    // Its interface is intentionally limited to stack operations:
    //
    // push()
    // pop()
    // top()
    // size()
    // empty()
    // swap()
    //
    // ------------------------------------------------------------
    // VECTOR:
    //
    // vector<int> v = {10,20,30};
    //
    // auto it = v.begin();       // ✅
    // v.end();                   // ✅
    //
    //
    // LIST:
    //
    // list<int> l = {10,20,30};
    //
    // auto it = l.begin();       // ✅
    // l.end();                   // ✅
    //
    //
    // STACK:
    //
    // stack<int> st;
    //
    // st.begin();                // ❌
    // st.end();                  // ❌
    //
    // ============================================================

    // ============================================================
    // CREATING A STACK
    // ============================================================

    stack<int> st;

    // Adding elements to the stack.

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Stack:
    //
    //        TOP
    //         ↓
    //       [40]
    //       [30]
    //       [20]
    //       [10]

    // ============================================================
    // CAN WE CREATE A STACK ITERATOR?
    // ============================================================

    // This would be WRONG:
    //
    // stack<int>::iterator it = st.begin();
    //
    // ❌ Compilation error
    //
    // Why?
    //
    // Because std::stack does not define iterator types
    // or expose begin()/end() in its public interface.

    // ============================================================
    // WRONG CODE EXAMPLE
    // ============================================================

    /*
        stack<int> st;

        st.push(10);
        st.push(20);
        st.push(30);

        // ❌ INVALID
        auto it = st.begin();

        // ❌ INVALID
        auto endIt = st.end();
    */

    // ============================================================
    // THEN HOW DO WE TRAVERSE A STACK?
    // ============================================================
    //
    // The normal way is:
    //
    // top()
    //   ↓
    // pop()
    //
    // We repeatedly process the TOP element until
    // the stack becomes empty.
    //
    // ============================================================

    cout << "Stack elements: ";

    while (!st.empty())
    {
        // top() gives the current top element.

        cout << st.top() << " ";

        // pop() removes the current top element.

        st.pop();
    }

    cout << endl;

    // Output:
    //
    // 40 30 20 10
    //
    // IMPORTANT:
    //
    // After this loop:
    //
    // st is EMPTY.
    //
    // Because every element was removed using pop().

    // ============================================================
    // HOW TO TRAVERSE WITHOUT DESTROYING ORIGINAL STACK
    // ============================================================
    //
    // If we don't want to destroy the original stack,
    // create a copy.

    stack<int> original;

    original.push(10);
    original.push(20);
    original.push(30);
    original.push(40);

    // Make a copy.

    stack<int> temp = original;

    cout << "Copied stack elements: ";

    // Work with temp instead of original.

    while (!temp.empty())
    {
        cout << temp.top() << " ";

        temp.pop();
    }

    cout << endl;

    // temp is now empty.
    //
    // original is still unchanged.
    //
    // original:
    //
    //        TOP
    //         ↓
    //       [40]
    //       [30]
    //       [20]
    //       [10]

    cout << "Original stack size: "
         << original.size() << endl;

    // ============================================================
    // WHY DOES STACK NOT HAVE ITERATORS?
    // ============================================================
    //
    // A stack is designed to enforce the LIFO abstraction.
    //
    // It allows us to interact with:
    //
    // TOP
    //
    // only.
    //
    // Example:
    //
    //        TOP
    //         ↓
    //       [40]  ← accessible
    //       [30]  ← not directly accessible
    //       [20]  ← not directly accessible
    //       [10]  ← not directly accessible
    //
    // If general iterators were exposed, we could directly
    // walk through all internal elements.
    //
    // The standard stack interface therefore keeps the
    // abstraction restricted.

    // ============================================================
    // STACK IS A CONTAINER ADAPTOR
    // ============================================================
    //
    // A container adaptor provides a restricted interface
    // over an underlying container.
    //
    // By default, std::stack is commonly implemented using
    // std::deque.
    //
    // Conceptually:
    //
    // stack
    //   ↓
    // underlying container
    //   ↓
    // deque
    //
    // But the stack itself does NOT expose deque's iterators
    // through its public interface.

    // ============================================================
    // EXPLICIT UNDERLYING CONTAINER
    // ============================================================
    //
    // We can explicitly specify the underlying container.
    //
    // Example:
    //
    // stack<int, vector<int>> st;
    //
    // Here vector<int> becomes the underlying container.
    //
    // IMPORTANT:
    //
    // Even though vector has iterators,
    // std::stack still does NOT expose:
    //
    // st.begin()
    // st.end()
    //
    // So this is still invalid:
    //
    // st.begin();     // ❌

    // ============================================================
    // IF YOU NEED ITERATORS, USE VECTOR OR LIST
    // ============================================================
    //
    // If your main requirement is:
    //
    // "I want to traverse elements using iterators"
    //
    // then use vector or list instead of stack.
    //
    // ------------------------------------------------------------
    //
    // VECTOR:
    //
    // vector<int> v = {10,20,30,40};
    //
    // auto it = v.begin();
    //
    // while (it != v.end())
    // {
    //     cout << *it << " ";
    //     ++it;
    // }
    //
    // ✅ Works
    //
    // ------------------------------------------------------------
    //
    // LIST:
    //
    // list<int> l = {10,20,30,40};
    //
    // auto it = l.begin();
    //
    // while (it != l.end())
    // {
    //     cout << *it << " ";
    //     ++it;
    // }
    //
    // ✅ Works
    //
    // ------------------------------------------------------------
    //
    // STACK:
    //
    // stack<int> st;
    //
    // auto it = st.begin();
    //
    // ❌ Does NOT work

    // ============================================================
    // STACK TRAVERSAL PATTERN
    // ============================================================
    //
    // This is the standard pattern:
    //
    // while (!st.empty())
    // {
    //     int x = st.top();
    //
    //     // Process x
    //
    //     st.pop();
    // }
    //
    // In DSA, this pattern is very important.

    // ============================================================
    // EXAMPLE: PROCESSING STACK
    // ============================================================

    stack<int> processStack;

    processStack.push(100);
    processStack.push(200);
    processStack.push(300);

    while (!processStack.empty())
    {
        // Read top element.

        int current = processStack.top();

        // Process it.

        cout << "Processing: "
             << current << endl;

        // Remove processed element.

        processStack.pop();
    }

    // ============================================================
    // STACK ITERATOR VS VECTOR ITERATOR VS LIST ITERATOR
    // ============================================================

    /*
        VECTOR
        ------------------------------------------------------------
        begin()        -> ✅
        end()          -> ✅
        iterator       -> ✅
        random access  -> ✅
        v[i]           -> ✅


        LIST
        ------------------------------------------------------------
        begin()        -> ✅
        end()          -> ✅
        iterator       -> ✅
        random access  -> ❌
        l[i]           -> ❌


        STACK
        ------------------------------------------------------------
        begin()        -> ❌
        end()          -> ❌
        public iterator-> ❌
        random access  -> ❌
        st[i]          -> ❌
    */

    // ============================================================
    // VERY IMPORTANT EXAM / INTERVIEW POINT
    // ============================================================
    //
    // std::stack does not expose iterators because it is a
    // container adaptor with a restricted LIFO interface.
    //
    // If traversal is required, use:
    //
    // top() + pop()
    //
    // or work with the underlying container directly instead
    // of using std::stack.

    return 0;
}