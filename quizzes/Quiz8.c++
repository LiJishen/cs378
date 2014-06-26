/*
CS378: Quiz #8 (10 pts) <Sam>
*/

/* -----------------------------------------------------------------------
 1. In the paper, "A Bug and a Crash" about the Ariane 5, what was the
    software bug?
    (3 pts)

the conversion of a 64-bit number to a 16-bit number
*/

/* -----------------------------------------------------------------------
 2. In the paper, "Mariner 1", what was the software bug?
    (3 pts)

the ommission of a hyphen
*/

/* -----------------------------------------------------------------------
 3. What is the output of the following?
    (3 pts)

false
true
false
*/

#include <iostream> // cout, endl

template <typename II1, typename II2>
bool f (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b == *c)
            return false;
        ++b;
        ++c;}
    return true;}

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    const int a[] = {2, 3, 4};
    const int s   = sizeof(a) / sizeof(a[0]);

    const int b[] = {2, 3, 4, 5};
    cout << f(a, a + s, b) << endl;

    const int c[] = {5, 4, 3, 2};
    cout << f(a, a + s, c) << endl;

    const int d[] = {5, 2, 4, 3};
    cout << f(a, a + s, d) << endl;

    return 0;}
