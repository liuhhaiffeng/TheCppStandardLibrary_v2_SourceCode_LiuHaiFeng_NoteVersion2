// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
using namespace std;
// 归并排序是建立在归并操作上的一种有效的排序算法，该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
// 
// 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。
int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 1, 7);
    INSERT_ELEMENTS(coll, 1, 8);
    PRINT_ELEMENTS(coll);

    list<int>::iterator pos;
    pos = find(coll.begin(), coll.end(), 7);
    ++pos;

    inplace_merge(coll.begin(), pos, coll.end());

    PRINT_ELEMENTS(coll);
}
