/*
CS378: Exercise #2
*/

/* -----------------------------------------------------------------------
Define the function my_fill() such that it behaves as follows:
*/

// http://www.cplusplus.com/reference/algorithm/fill/

#include <algorithm> // all_of, fill
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <vector>    // vector

template <typename FI, typename T>
void my_fill (FI b, FI e, const T& v) {
    while (b != e) {
        *b = v;
        ++b;}}

int main () {
    using namespace std;
    cout << "Fill.c++" << endl;

    {
    const size_t s = 3;
    const int    v = 5;
    int a[s];
    my_fill(a, a + s, v);
    assert(all_of(a, a + s, [] (int w) {return v == w;}));
    }

    {
    const size_t s = 3;
    const int    v = 5;
    int a[s];
    fill(a, a + s, v);
    assert(all_of(a, a + s, [] (int w) {return v == w;}));
    }

    {
    const size_t s = 3;
    const int    v = 5;
    vector<int>  x(s);
    my_fill(x.begin(), x.end(), v);
    assert(all_of(x.begin(), x.end(), [] (int w) {return v == w;}));
    }

    {
    const size_t s = 3;
    const int    v = 5;
    vector<int>  x(s);
    fill(x.begin(), x.end(), v);
    assert(all_of(x.begin(), x.end(), [] (int w) {return v == w;}));
    }

    cout << "Done." << endl;
    return 0;}
