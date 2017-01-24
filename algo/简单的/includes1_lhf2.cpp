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
    list<int> coll;
    vector<int> search;

    INSERT_ELEMENTS(coll,1,9);
    PRINT_ELEMENTS(coll,"coll:   ");

    search.push_back(3);
    search.push_back(4);
    search.push_back(7);
    PRINT_ELEMENTS(search,"search: ");

    /**
     * std::includes 说明文档
     * C++  Algorithm library 
     * Defined in header <algorithm>
     * template< class InputIt1, class InputIt2 >
     * bool includes( InputIt1 first1, InputIt1 last1,
     *                InputIt2 first2, InputIt2 last2 );
     * (1)	
     * template< class ExecutionPolicy, class InputIt1, class InputIt2 >
     * bool includes( ExecutionPolicy&& policy, InputIt1 first1, InputIt1 last1,
     *                InputIt2 first2, InputIt2 last2 );
     * (2)	(since C++17)
     * template< class InputIt1, class InputIt2, class Compare >
     * bool includes( InputIt1 first1, InputIt1 last1,
     *                InputIt2 first2, InputIt2 last2, Compare comp );
     * (3)	
     * template< class ExecutionPolicy, class InputIt1, class InputIt2, class Compare >
     * bool includes( ExecutionPolicy&& policy, InputIt1 first1, InputIt1 last1,
     *                InputIt2 first2, InputIt2 last2, Compare comp );
     * (4)	(since C++17)
     * Returns true if every element from the sorted range [first2, last2) is found within the sorted 
     * range [first1, last1). Also returns true if [first2, last2) is empty.
     * 1) Both ranges must be sorted with operator<.
     * 3) Both ranges must be sorted with the given comparison function comp.
     * 2,4) Same as (1,3), but executed according to policy. These overloads do not participate in 
     * overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> is true
     */
    // check whether all elements in search are also in coll
    if (includes (coll.cbegin(), coll.cend(),
                  search.cbegin(), search.cend())) {
        cout << "all elements of search are also in coll"
             << endl;
    }
    else {
        cout << "not all elements of search are also in coll"
             << endl;
    }
}
