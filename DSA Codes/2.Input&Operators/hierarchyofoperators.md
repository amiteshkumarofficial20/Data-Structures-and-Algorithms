HIERARCHY OF OPERATORS IN C++

    == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

    The hierarchy of operators refers to the order in which different
        operators are evaluated in an expression.

    When an expression contains more than one
    operator,
    C++ follows a
        specific order to decide which operation should be performed first.

    This order is called Operator Precedence or Hierarchy of Operators.

    Example :

    int result = 10 + 5 * 2;

Here, both '+' and '*' operators are present.

      Multiplication has higher precedence than addition.

      Therefore :

      5 * 2 = 10

              Then :

              10 +
              10 = 20

      So :

    result = 20

             == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

             WHY IS OPERATOR HIERARCHY IMPORTANT
    ?

    Operator hierarchy is important because it determines the result of an expression containing multiple operators.

    Without a fixed order of evaluation,
          the same expression could
              produce different results.

          For example
    :

    10 + 5 * 2

        If addition were performed first :

        10 +
        5 = 15 15 * 2 = 30

                        But C++ gives multiplication higher precedence than addition.

                        Therefore :

                        5 * 2 = 10 10 + 10 = 20

                                             The correct result is :

                                             20

                                             == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

                                             COMMON HIERARCHY OF OPERATORS

                                                 The following is a simplified hierarchy commonly used while learning basic C++ :

                                             1. Parentheses 2. Unary Operators 3. Multiplication,
          Division and Modulus 4. Addition and Subtraction 5. Relational Operators 6. Equality Operators 7. Logical AND 8. Logical OR 9. Conditional / Ternary Operator 10. Assignment Operators

              == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

              1. PARENTHESES

                  Parentheses have very high precedence and are used to explicitly
                      control the order of operations.

              Example :

    int result = (10 + 5) * 2;

First :

    10 + 5 = 15

    Then :

    15 * 2 = 30

    Therefore :

    result = 30

    Without parentheses :

    int result = 10 + 5 * 2;

First :

    5 * 2 = 10

            Then :

            10 +
            10 = 20

    Therefore :

    result = 20

             Parentheses can therefore change the result of an expression.

             == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

             2. UNARY OPERATORS

                     Unary operators work on only one operand.

                 Examples :

    ++Increment-- Decrement !Logical NOT -
                 Unary minus + Unary plus

                                   Example :

    int a = 5;

++a;

After this :

    a = 6

    Another example :

    bool value = true;

cout << !value;

The result becomes :

    false

    == ==
    == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

    3. MULTIPLICATION,
    DIVISION AND MODULUS

            These operators have higher precedence than addition and
                subtraction.

        Operators :

            * /
        %

        Example :

    int result = 20 + 10 * 2;

First :

    10 * 2 = 20

             Then :

             20 +
             20 = 40

    Therefore :

    result = 40

    Another example :

    int result = 20 - 10 / 2;

First :

    10 / 2 = 5

             Then :

             20 -
             5 = 15

                 == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

                 4. ADDITION AND SUBTRACTION

                         Operators :

    +-

    These operators have lower precedence than :

        * /
    %

    Example :

    int result = 10 + 20 * 3;

First :

    20 * 3 = 60

             Then :

             10 +
             60 = 70

    Therefore :

    result = 70

             == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

             5. RELATIONAL OPERATORS

                     Relational operators are used to compare values.

                 Operators :

                 >
                 <
                 >=
                 <=

                 Example :

    int a = 10;
int b = 20;

bool result = a < b;

Since 10 is less than 20 :

    result = true

             Relational operators are generally evaluated after arithmetic
                 operations.

             Example :

    int result = 10 + 5 > 12;

First :

    10 + 5 = 15

             Then :

             15 > 12

             Therefore :

    result = true

                 == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

                 6. EQUALITY OPERATORS

                     Equality operators are :

    ==
    !=

    They are used to check whether two values are equal or
             different.

             Example :

    int a = 10;
int b = 10;

bool result = a == b;

Result :

    true

    Example :

    int a = 10;
int b = 20;

bool result = a != b;

Result :

    true

    == ==
    == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

    7. LOGICAL AND OPERATOR

        The logical AND
        operator is :

    &&

    It is used to combine two or more conditions.

    Example :

    int age = 25;

bool result = age >= 18 && age <= 60;

First :

    age >= 18

    Then :

    age <= 60

    Both conditions are true,
    so the final result is :

    true

    == ==
    == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

    8. LOGICAL OR OPERATOR

        The logical OR
        operator is :

    ||

    It returns true when at least one condition is true.

    Example :

    int age = 15;

bool result = age < 18 || age > 60;

The first condition is true :

    age < 18

    Therefore :

    result = true

                     == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

                     9. CONDITIONAL / TERNARY OPERATOR

                                          The ternary
                                          operator is :

                 ?:

                 It is generally used as a short form of a simple if - else statement.

                 Example :

    int age = 20;

string result = (age >= 18) ? "Adult" : "Minor";

The condition :

    age >= 18

           is checked first.

           If it is true :

    "Adult"

    is selected.

    If it is false :

    "Minor"

    is selected.

    == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

    10. ASSIGNMENT OPERATORS

        Assignment operators are used to assign values to variables.

    Common assignment operators :

    =
        +=
    -=
    *=
    /=
    %=

    Example :

    int a;

a = 10;

Here, 10 is assigned to a.

      Example :

    a += 5;

This is equivalent to :

    a = a + 5;

Assignment operators generally have lower precedence than most
    arithmetic,
    relational and logical operators.

        == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

        IMPORTANT EXAMPLE

            Consider :

    int result = 10 + 5 * 2 > 15 && 20 > 10;

C++ evaluates the expression according to operator precedence.

    Step 1 :

    5 * 2 = 10

                Expression becomes :

                10 +
                10 >
            15 && 20 > 10

                           Step 2 :

                           10 +
                           10 = 20

                                Expression becomes :

                                20 > 15 && 20 > 10

                                Step 3 :

                                20 > 15 = true

                                          20 > 10 = true

    Expression becomes :

    true &&true

    Step 4 :

    true &&true = true

    Therefore :

    result = true

             == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

             USE OF PARENTHESES

                 Although C++ has a defined operator hierarchy,
        parentheses should
            be used when an expression is difficult to understand.

        Example :

    int result = (a + b) * c;

This clearly tells the compiler and the programmer that :

    a +
    b

        must be evaluated before multiplication.

    Another example :

    int result = a + (b * c);

This makes the intended order clear.

    Using parentheses improves :

    1. Readability 2. Understanding 3. Maintainability 4. Prevention of logical mistakes

    == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

    IMPORTANT POINT

        Operator precedence determines which
        operator is considered first.

    However,
operator precedence should not be confused with
    evaluation order.

    Precedence tells us how an expression is grouped.

    It does not mean that every part of an expression is necessarily
        executed from left to right.

    For beginners,
    it is safest to avoid complicated expressions
            with many operators and use parentheses to clearly express the
                intended calculation.

        == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

        SIMPLE ORDER TO REMEMBER

            For basic C++ expressions,
    remember :

    ()

        Then :

    ++,
    --,
    !,
    unary +
    , unary -

          Then :

              *,
    /
    , %

          Then :

    +,
    -

        Then :

        >,
    <,
    >=,
    <=

            Then :

        ==
    , !=

                  Then :

                      &&

    Then :

              ||

              Then :

          ?:

          Then :

    =,
    +=,
    -=,
    *=,
    /=,
    %=

    == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

        CONCLUSION

        The hierarchy of operators is the set of precedence rules that C++ uses to determine how an expression is grouped
    and evaluated.

        Arithmetic operators such as *,
    / and% have higher precedence than + and-.

                                             Relational and logical operators are generally evaluated after arithmetic operations.

                                             Assignment operators have relatively low precedence.

                                             Parentheses can be used to explicitly control the order of operations and make expressions easier to understand.

                                             Understanding operator hierarchy is important for writing correct C++ expressions and avoiding unexpected results.

                                             == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
        ==