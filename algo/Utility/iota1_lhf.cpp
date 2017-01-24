// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
using namespace std;

int main()
{
    array<int, 10> coll;
    // Assigns to every element in the range [first,last)
    // successive values of val, as if incremented with ++val
    // after each element is written.
    // C++11算法库算法库新增了iota用来方便的生成有序序列，
    // 比如我们需要一个定长数组，这个数组中的元素都是在
    // 某一个数值的基础之上递增的，那么用iota可以很方便
    // 的生成这个数组了
    iota(coll.begin(), coll.end(), 42);

    PRINT_ELEMENTS(coll, "coll: ");
}
