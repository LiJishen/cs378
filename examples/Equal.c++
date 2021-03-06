// ---------
// Equal.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/equal/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl

bool equal_1 (const int* b, const int* e, const int* x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

template <typename II1, typename II2>
bool equal_2 (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

int main () {
    using namespace std;
    cout << "Equal.c++" << endl;

    const int a[] = {2, 3, 4};
    const int s   = sizeof(a) / sizeof(a[0]);
    const int b[] = {2, 3, 4, 5};

    assert(equal_1(a, a + s, b));
    assert(equal_2(a, a + s, b));
    assert(equal  (a, a + s, b));

    cout << "Done." << endl;
    return 0;}
