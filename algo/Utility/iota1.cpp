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
#include "algostuff.hpp"
using namespace std;

// 算法库新增了iota用来方便的生成有序序列，比如我们需要一个定长数组，
// 这个数组中的元素都是在某一个数值的基础之上递增的，那么用iota可以
// 很方便的生成这个数组了。
int main()
{
    array<int,10> coll;

    iota (coll.begin(), coll.end(),  // destination range
          42);                       // start value

    PRINT_ELEMENTS(coll,"coll: ");
}
