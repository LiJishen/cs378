// -------------
// Coverage2.c++
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
    cout << "Coverage2.c++" << endl;

    assert(cycle_length(1) == 1);
    assert(cycle_length(2) == 2);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -std=c++11 -fprofile-arcs -ftest-coverage -pedantic -Wall -isystem /usr/local/include/gtest -pthread Coverage2.c++ -o Coverage2.app /usr/local/lib/gtest_main.a
Coverage2.app
Coverage2.c++
Done.



% gcov -b Coverage2.c++
File 'Coverage2.c++'
Lines executed:92.86% of 14
Branches executed:100.00% of 12
Taken at least once:58.33% of 12
No calls
Coverage2.c++:creating 'Coverage2.c++.gcov'
...



% cat Coverage2.c++.gcov
        -:    0:Source:Coverage2.c++
        -:    0:Graph:Coverage2.gcno
        -:    0:Data:Coverage2.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// -------------
        -:    2:// Coverage2.c++
        -:    3:// -------------
        -:    4:
        -:    5:// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html
        -:    6:
        -:    7:#include <cassert>  // assert
        -:    8:#include <iostream> // cout, endl
        -:    9:
function _Z12cycle_lengthi called 2 returned 100% blocks executed 68%
        -:   10:int cycle_length (int n) {
        4:   11:    assert(n > 0);
branch  0 taken 0%
branch  1 taken 100%
        2:   12:    int c = 1;
        5:   13:    while (n > 1) {
branch  0 taken 33%
branch  1 taken 67%
        1:   14:        if ((n % 2) == 0)
branch  0 taken 100%
branch  1 taken 0%
        1:   15:            n = (n / 2);
        -:   16:        else
    #####:   17:            n = (3 * n) + 1;
        1:   18:        ++c;}
        4:   19:    assert(c > 0);
branch  0 taken 0%
branch  1 taken 100%
        2:   20:    return c;}
        -:   21:
function main called 1 returned 100% blocks executed 60%
        -:   22:int main () {
        -:   23:    using namespace std;
        1:   24:    cout << "Coverage2.c++" << endl;
        -:   25:
        2:   26:    assert(cycle_length(1) == 1);
branch  0 taken 0%
branch  1 taken 100%
        2:   27:    assert(cycle_length(2) == 2);
branch  0 taken 0%
branch  1 taken 100%
        -:   28:
        1:   29:    cout << "Done." << endl;
        1:   30:    return 0;}
*/
