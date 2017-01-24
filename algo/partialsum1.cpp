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

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll,1,6);
    PRINT_ELEMENTS(coll);

    // print all partial sums
    // 局部和算法
    /*
    If x represents an element in [first,last) and y represents
    an element in result, the ys can be calculated as:

    y0 = x0
    y1 = x0 + x1
    y2 = x0 + x1 + x2
    y3 = x0 + x1 + x2 + x3
    y4 = x0 + x1 + x2 + x3 + x4
    ... ... ...
    */
    partial_sum (coll.cbegin(), coll.cend(),        // source range
                 ostream_iterator<int>(cout," "));  // destination
    cout << endl;

    // print all partial products
    partial_sum (coll.cbegin(), coll.cend(),        // source range
                 ostream_iterator<int>(cout," "),   // destination
                 multiplies<int>());                // operation
    cout << endl;
}
