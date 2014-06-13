/*
CS378: Quiz #3 (10 pts) <Thanh>
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (9 pts)

g1 f1 f2 g2 g3
g1 f1 catch g3
g1 f1
*/

#include <iostream>  // cout, endl
#include <stdexcept> // domain_error, range_error

using namespace std;

void f (int n) {
    cout << "f1 ";
    if (n == 1)
        throw domain_error("");
    else if (n == 2)
    	throw range_error("");
    cout << "f2 ";}

void g (int n) {
    try {
        cout << "g1 ";
        f(n);
        cout << "g2 ";}
    catch (domain_error& e) {
        cout << "catch ";}
    cout << "g3 " << endl;}

int main () {
    try {
        for (int n : {0, 1, 2})
        	g(n);}
    catch (exception& e) {
        cout << endl;}
    return 0;}
