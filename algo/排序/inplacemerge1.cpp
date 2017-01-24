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

// inplace_merge 归并排序
// inplace_merge函数的作用和merge函数差不多，只不过是在一个容器中进行归并。
// 函数参数：inplace_merge(first,mid,last,compare);//将[first,mid) 和 [mid,last)
// 这两个区间进行归并成一个有序序列。
// 
// 注意：[first,mid)和[mid,last)都要呈升序或降序排列！
// 
// 还记得归并排序的写法么？归并排序利用了分治的思想，将一个容器分割，然后再将它
//     们一个个合并起来，最后形成一个有序的序列。归并排序的核心代码就在于合并两
//     个序列，不过STL的开发人员已经为我们完成了，我们直接调用就可以了。
int main()
{
    list<int> coll;

    // insert two sorted sequences
    INSERT_ELEMENTS(coll,1,7);
    INSERT_ELEMENTS(coll,1,8);
    PRINT_ELEMENTS(coll);

    // find beginning of second part (element after 7)
    list<int>::iterator pos;
    pos = find (coll.begin(), coll.end(),    // range
                7);                          // value
    ++pos;

    // merge into one sorted range
    inplace_merge (coll.begin(), pos, coll.end());

    PRINT_ELEMENTS(coll);
}
