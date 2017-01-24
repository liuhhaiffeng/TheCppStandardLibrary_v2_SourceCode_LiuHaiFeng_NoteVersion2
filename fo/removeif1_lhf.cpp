/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <list>
#include <algorithm>
#include "print.hpp"
using namespace std;

class Nth {    // function object that returns true for the nth call
  private:
    int nth;       // call for which to return true
    int count;     // call counter
  public:
    Nth (int n) : nth(n), count(0) {
    }
    // base from 1
    bool operator() (int) {
        return ++count == nth;
    }
};

void test1()
{
    list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    PRINT_ELEMENTS(coll,"coll:        ");

    // remove third element
    list<int>::iterator pos;
    pos = remove_if(coll.begin(),coll.end(),  // range
                    Nth(3));                  // remove criterion
    coll.erase(pos,coll.end());

    PRINT_ELEMENTS(coll,"3rd removed: ");
}

void test2()
{
    list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    PRINT_ELEMENTS(coll,"coll:        ");

    // remove third element
    list<int>::iterator pos;
    int count = 0;
    int nth = 3;
    pos = remove_if(coll.begin(), coll.end(),
            [&count, nth](int){
                return ++count == nth;
            });
    coll.erase(pos,coll.end());

    PRINT_ELEMENTS(coll,"3rd removed: ");
}

int main()
{
    test2();
}

// 总结: 通过对比发现, 对于带有多个状态值的函数, 仿函数比lbmda要好一些
