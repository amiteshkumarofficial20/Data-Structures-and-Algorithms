#include <iostream>
using namespace std;

int main()
{
    int marks;
    cout << "Enter Marks: ";
    cin >> marks;

    string result = (marks > 33) ? "Pass" : "Fail";

    cout << "Result is :  " << result << endl;

    return 0;
}