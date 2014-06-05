// -------------
// Coverage3.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

int main () {
    using namespace std;
    cout << "Coverage3.c++" << endl;

    assert(cycle_length(1) == 1);
    assert(cycle_length(2) == 2);
    assert(cycle_length(3) == 8);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -std=c++11 -fprofile-arcs -ftest-coverage -pedantic -Wall -isystem /usr/local/include/gtest -pthread Coverage3.c++ -o Coverage3.app /usr/local/lib/gtest_main.a
Coverage3.app
Coverage3.c++
Done.



% gcov -b Coverage3.c++
File 'Coverage3.c++'
Lines executed:100.00% of 15
Branches executed:100.00% of 14
Taken at least once:64.29% of 14
No calls
Coverage3.c++:creating 'Coverage3.c++.gcov'
...



% cat Coverage3.c++.gcov
        -:    0:Source:Coverage3.c++
        -:    0:Graph:Coverage3.gcno
        -:    0:Data:Coverage3.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// -------------
        -:    2:// Coverage3.c++
        -:    3:// -------------
        -:    4:
        -:    5:// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html
        -:    6:
        -:    7:#include <cassert>  // assert
        -:    8:#include <iostream> // cout, endl
        -:    9:
function _Z12cycle_lengthi called 3 returned 100% blocks executed 75%
        -:   10:int cycle_length (int n) {
        6:   11:    assert(n > 0);
branch  0 taken 0%
branch  1 taken 100%
        3:   12:    int c = 1;
       14:   13:    while (n > 1) {
branch  0 taken 73%
branch  1 taken 27%
        8:   14:        if ((n % 2) == 0)
branch  0 taken 75%
branch  1 taken 25%
        6:   15:            n = (n / 2);
        -:   16:        else
        2:   17:            n = (3 * n) + 1;
        8:   18:        ++c;}
        6:   19:    assert(c > 0);
branch  0 taken 0%
branch  1 taken 100%
        3:   20:    return c;}
        -:   21:
function main called 1 returned 100% blocks executed 57%
        -:   22:int main () {
        -:   23:    using namespace std;
        1:   24:    cout << "Coverage3.c++" << endl;
        -:   25:
        2:   26:    assert(cycle_length(1) == 1);
branch  0 taken 0%
branch  1 taken 100%
        2:   27:    assert(cycle_length(2) == 2);
branch  0 taken 0%
branch  1 taken 100%
        2:   28:    assert(cycle_length(3) == 8);
branch  0 taken 0%
branch  1 taken 100%
        -:   29:
        1:   30:    cout << "Done." << endl;
        1:   31:    return 0;}
*/
