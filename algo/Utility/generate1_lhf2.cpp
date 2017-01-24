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
#include <cstdlib>
#include "algostuff.hpp"
using namespace std;
// 与fill或fill_n不同, 前者是提供一个固定value来填充
// 而generate_n()需要提供一个"value生成器"函数/仿函数/lambda
// 用例1: 利用C++11 "随机数引擎"来产生随机数
int main()
{
    list<int> coll;

    // insert five random numbers
    generate_n (back_inserter(coll),      // beginning of destination range
                5,                        // count
                rand);                    // new value generator
    PRINT_ELEMENTS(coll);

    // overwrite with five new random numbers
    generate (coll.begin(), coll.end(),   // destination range
              rand);                      // new value generator
    PRINT_ELEMENTS(coll);
}
