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

void test1();
void test2();   // 刘海峰 add

int main()
{
    test2();
}

void test1()
{
    list<int> coll;

    INSERT_ELEMENTS(coll,1,9);
    INSERT_ELEMENTS(coll,1,9);
    coll.sort ();
    PRINT_ELEMENTS(coll);

    // print first and last position 5 could get inserted
    auto pos1 = lower_bound (coll.cbegin(), coll.cend(),
                             5);
    auto pos2 = upper_bound (coll.cbegin(), coll.cend(),
                             5);

    cout << "5 could get position "
         << distance(coll.cbegin(),pos1) + 1
         << " up to "
         << distance(coll.cbegin(),pos2) + 1
         << " without breaking the sorting" << endl;

    // insert 3 at the first possible position without breaking the sorting
    coll.insert (lower_bound(coll.begin(),coll.end(),
                             3),
                 3);

    // insert 7 at the last possible position without breaking the sorting
    coll.insert (upper_bound(coll.begin(),coll.end(),
                             7),
                 7);

    PRINT_ELEMENTS(coll);
}

#include <numeric>  // std::iota()

void test2()
{
    vector<int> coll(10);

    std::iota(coll.begin(), coll.end(), 1);
    PRINT_ELEMENTS(coll);
    INSERT_ELEMENTS(coll, 1, 10);
    INSERT_ELEMENTS(coll, 1, 10);
    PRINT_ELEMENTS(coll);    
    // std::sort默认升序, 这里采用降序
    //std::sort(coll.begin(), coll.end(), std::greater<int>());
    // 默认升序
    std::sort(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll);

    // lower_bound(), upper_bound() 处理的序列必须满足以下2个条件:
    // (1) 序列是有序的, 否则: 返回错误值
    // (2) 序列必须是升序, 否则: 两个函数均返回end()
    auto pos1 = lower_bound(coll.begin(), coll.end(), 9);
    auto pos2 = upper_bound(coll.begin(), coll.end(), 9);
    cout << "9 could get pos:" << distance(coll.begin(), pos1) + 1 << " up to: "
        << distance(coll.begin(), pos2) + 1 << '\n';
}
