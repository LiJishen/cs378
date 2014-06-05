// -------------
// Coverage1.c++
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
    cout << "Coverage1.c++" << endl;

    assert(cycle_length(1) == 1);

    cout << "Done." << endl;
    return 0;}

/*
% g++ -std=c++11 -fprofile-arcs -ftest-coverage -pedantic -Wall -isystem /usr/local/include/gtest -pthread Coverage1.c++ -o Coverage1.app /usr/local/lib/gtest_main.a
Coverage1.app
Coverage1.c++
Done.



% gcov -b Coverage1.c++
File 'Coverage1.c++'
Lines executed:69.23% of 13
Branches executed:80.00% of 10
Taken at least once:40.00% of 10
No calls
Coverage1.c++:creating 'Coverage1.c++.gcov'
...



% cat Coverage1.c++.gcov
        -:    0:Source:Coverage1.c++
        -:    0:Graph:Coverage1.gcno
        -:    0:Data:Coverage1.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// -------------
        -:    2:// Coverage1.c++
        -:    3:// -------------
        -:    4:
        -:    5:// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html
        -:    6:
        -:    7:#include <cassert>  // assert
        -:    8:#include <iostream> // cout, endl
        -:    9:
function _Z12cycle_lengthi called 1 returned 100% blocks executed 50%
        -:   10:int cycle_length (int n) {
        2:   11:    assert(n > 0);
branch  0 taken 0%
branch  1 taken 100%
        1:   12:    int c = 1;
        2:   13:    while (n > 1) {
branch  0 taken 0%
branch  1 taken 100%
    #####:   14:        if ((n % 2) == 0)
branch  0 never executed
branch  1 never executed
    #####:   15:            n = (n / 2);
        -:   16:        else
    #####:   17:            n = (3 * n) + 1;
    #####:   18:        ++c;}
        2:   19:    assert(c > 0);
branch  0 taken 0%
branch  1 taken 100%
        1:   20:    return c;}
        -:   21:
function main called 1 returned 100% blocks executed 66%
        -:   22:int main () {
        -:   23:    using namespace std;
        1:   24:    cout << "Coverage1.c++" << endl;
        -:   25:
        2:   26:    assert(cycle_length(1) == 1);
branch  0 taken 0%
branch  1 taken 100%
        -:   27:
        1:   28:    cout << "Done." << endl;
        1:   29:    return 0;}
        -:   30:
*/
