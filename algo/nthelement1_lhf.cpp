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
    deque<int> coll;

    INSERT_ELEMENTS(coll,3,7);
    INSERT_ELEMENTS(coll,2,6);
    INSERT_ELEMENTS(coll,1,5);
    PRINT_ELEMENTS(coll, "coll: ");
    cout << endl;

    // extract the four lowest elements
    nth_element (coll.begin(),     // beginning of range
                 coll.begin()+3,   // element that should be sorted correctly
                 coll.end());      // end of range

    // print them
    cout << "the four lowest elements are:  ";
    copy (coll.cbegin(), coll.cbegin()+4,
          ostream_iterator<int>(cout," "));
    cout << endl;
    PRINT_ELEMENTS(coll, "coll: ");
    cout << endl;

    // extract the four highest elements
    // nth_element��partial_sort������:
    // �ο���վ:
    // Title: ��������������(stable_sort,sort,partial_sort,nth_element,stable_partition,partition)
    // Address: http://www.cnblogs.com/qlee/archive/2011/05/25/2057281.html
    nth_element (coll.begin(),     // beginning of range
                 coll.end()-4,     // element that should be sorted correctly
                 coll.end());      // end of range

    // print them
    cout << "the four highest elements are: ";
    copy (coll.cend()-4, coll.cend(),
          ostream_iterator<int>(cout," "));
    cout << endl;
    PRINT_ELEMENTS(coll, "coll: ");
    cout << endl;

    // extract the four highest elements (second version)
    nth_element (coll.begin(),     // beginning of range
                 coll.begin()+3,   // element that should be sorted correctly
                 coll.end(),       // end of range
                 greater<int>());  // sorting criterion

    // print them
    cout << "the four highest elements are: ";
    copy (coll.cbegin(), coll.cbegin()+4,
          ostream_iterator<int>(cout," "));
    cout << endl;
    PRINT_ELEMENTS(coll, "coll: ");
}