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

    INSERT_ELEMENTS(coll,3,7);
    INSERT_ELEMENTS(coll,5,9);
    INSERT_ELEMENTS(coll,1,4);

    PRINT_ELEMENTS (coll, "on entry:           ");

    // convert collection into a heap
    // Constructs a max heap in the range [first, last).
    // 在集合中构造一个"最大堆"
    make_heap (coll.begin(), coll.end());

    PRINT_ELEMENTS (coll, "after make_heap():  ");

    // pop next element out of the heap
    /**
     * Swaps the value in the position first and the value in the position last-1 and 
     *    makes the subrange [first, last-1) into a max heap. This has the effect of 
     *    removing the first (largest) element from the heap defined by the range [first, last).
     */
    pop_heap (coll.begin(), coll.end());
    PRINT_ELEMENTS (coll, "after pop_heap():  ");

    // Inserts the element at the position last-1 into the max heap defined by 
    // the range [first, last-1). 
    coll.pop_back();
    PRINT_ELEMENTS (coll, "after pop_back():   ");

    // push new element into the heap
    coll.push_back (17);
    push_heap (coll.begin(), coll.end());

    PRINT_ELEMENTS (coll, "after push_heap():  ");

    // convert heap into a sorted collection
    // - NOTE: after the call it is no longer a heap
    // Converts the max heap [first, last) into a sorted range in ascending order. 
    //    The resulting range no longer has the heap property.
    sort_heap (coll.begin(), coll.end());

    PRINT_ELEMENTS (coll, "after sort_heap():  ");
}
