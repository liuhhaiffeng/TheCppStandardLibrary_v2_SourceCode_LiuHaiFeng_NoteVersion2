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
    int nums[]{1, 2, 3, 4, 4, 5, 5, 6, 7, 8, 8, 8, 8, 8, 9};
    cout << count(std::begin(nums), std::end(nums), 8) << '\n';

    cout << count_if(std::begin(nums), std::end(nums), [](int elem){
            return elem % 2 != 0;
            }) << '\n';
}
