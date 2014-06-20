// -------------
// Factorial.c++
// -------------

// http://www.cplusplus.com/articles/D2N36Up4/

#include <cassert>  // assert
#include <ctime>    // clock, clock_t, CLOCKS_PER_SEC
#include <iomanip>  // setprecision, setw
#include <iostream> // cout, endl
#include <string>   // string

int factorial_recursion (int n) {
    assert(n >= 0);
    if (n < 2)
        return 1;
    return n * factorial_recursion(n - 1);}

int factorial_iteration (int n) {
    assert(n >= 0);
    int x = 1;
    while (n > 1) {
        x *= n;
        --n;}
    return x;}

template <typename F>
void test (F f, const std::string& s) {
    std::cout << s << std::endl;
    assert(f(0) ==   1);
    assert(f(1) ==   1);
    assert(f(2) ==   2);
    assert(f(3) ==   6);
    assert(f(4) ==  24);
    assert(f(5) == 120);

    const clock_t b = clock();
    std::cout << f(16) << std::endl;
    const clock_t e = clock();
    std::cout << std::fixed << std::setprecision(3) << std::setw(5);
    std::cout << ((e - b) * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << std::endl;
    std::cout << std::endl;}

int main () {
    using namespace std;
    cout << "Factorial.c++" << endl << endl;

    test(factorial_recursion, "factorial_recursion");
    test(factorial_iteration, "factorial_iteration");

    cout << "Done." << endl;
    return 0;}

/*
Factorial.c++

factorial_recursion
2004189184
0.005 milliseconds

factorial_iteration
2004189184
0.003 milliseconds

Done.
*/
