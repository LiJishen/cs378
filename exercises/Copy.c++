/*
CS378: Exercise #3
*/

/* -----------------------------------------------------------------------
Define the function my_copy() such that it behaves as follows:
*/

// http://www.cplusplus.com/reference/algorithm/copy/

#include <algorithm> // copy, equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

int main () {
    using namespace std;
    cout << "copy.c++" << endl;

    {
    const int    a[]   = {2, 3, 4};
          int    b[5];
    const size_t s     = sizeof(a) / sizeof(a[0]);
    const int*   p     = my_copy(a, a + s, b + 1);
    assert(equal(a, a + s, b + 1));
    assert(p == b + 4);
    }

    {
    const int    a[]   = {2, 3, 4};
          int    b[5];
    const size_t s     = sizeof(a) / sizeof(a[0]);
    const int*   p     = copy(a, a + s, b + 1);
    assert(equal(a, a + s, b + 1));
    assert(p == b + 4);
    }

    {
    const int             a[] = {2, 3, 4};
    const size_t          s   = sizeof(a) / sizeof(a[0]);
    const list<int>       x(a, a + s);
    vector<int>           y(5);
    vector<int>::iterator p   = my_copy(x.begin(), x.end(), y.begin() + 1);
    assert(equal(x.begin(), x.end(), y.begin() + 1));
    assert(p == y.begin() + 4);
    }

    {
    const int             a[] = {2, 3, 4};
    const size_t          s   = sizeof(a) / sizeof(a[0]);
    const list<int>       x(a, a + s);
    vector<int>           y(5);
    vector<int>::iterator p   = copy(x.begin(), x.end(), y.begin() + 1);
    assert(equal(x.begin(), x.end(), y.begin() + 1));
    assert(p == y.begin() + 4);
    }

    cout << "Done." << endl;
    return 0;}
