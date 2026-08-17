// null_char_pointer.cpp
// Use of Null Character '\0' with Character Pointer

#include <iostream>
using namespace std;

int main()
{
    // A character array containing a string
    // '\0' is automatically added at the end of a string
    char str[] = "Hello";

    // Pointer points to the first character of the string
    char *p = str;

    // Display the complete string
    // cout stops printing when it finds '\0'
    cout << "String: " << p << endl;

    // Display characters one by one using pointer
    cout << "Characters: ";

    while (*p != '\0')
    {
        // *p gives the character stored at the current address
        cout << *p;

        // Move pointer to the next character
        p++;
    }

    cout << endl;

    return 0;
}

/*
DESCRIPTION:

'\0' is called the null character.

It has ASCII value 0 and is used to mark the
end of a C-style string.

Example:

char str[] = "Hello";

Memory:

H   e   l   l   o   \0
                    ↑
               String ends here

When the pointer reaches '\0', the loop stops.

IMPORTANT:

'\0'     -> Null character used to mark string end
nullptr  -> Null pointer used when pointer points to nothing
*/