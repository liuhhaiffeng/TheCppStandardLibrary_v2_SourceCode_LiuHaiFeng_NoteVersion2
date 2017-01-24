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
using namespace std::placeholders;

int main()
{
    vector<int> collOne;
    list<int> collTwo;

    INSERT_ELEMENTS(collOne,1,9);
    PRINT_ELEMENTS(collOne,"collOne:   ");

    // negate all elements in collOne
    transform (collOne.cbegin(), collOne.cend(),    // source range
            collOne.begin(),                        // destination range
            negate<int>());                         // operation
    PRINT_ELEMENTS(collOne,"negated: ");

    // transform elements of collOne into collTwo with ten times their value
    transform (collOne.cbegin(), collOne.cend(),    // source range
            back_inserter(collTwo),                 // destination range
            bind(multiplies<int>(),_1,10));         // operation
    PRINT_ELEMENTS(collTwo,"collTwo:   ");

    // print collTwo negatively and in reverse order
    transform (collTwo.crbegin(), collTwo.crend(),  // source range
            ostream_iterator<int>(cout," "),        // destination range
            [](int elem){                           // operation
            return -elem;
            });
    cout << endl;
}
