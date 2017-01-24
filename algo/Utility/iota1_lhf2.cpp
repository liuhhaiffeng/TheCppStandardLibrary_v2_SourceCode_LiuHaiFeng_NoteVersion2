// 算法库新增了iota用来方便的生成有序序列，比如我们需要一个定长数组，
// 这个数组中的元素都是在某一个数值的基础之上递增的，那么用iota可以
// 很方便的生成这个数组了。下面是它的基本用法：
#include <numeric>
#include <array>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v(4) ;
    //循环遍历赋值来初始化数组
    //for(int i=1; i<=4; i++)
    //{
    //  v.push_back(i);
    //}

    //直接通过iota初始化数组，更简洁
    std::iota(v.begin(), v.end(), 1);
    for(auto n: v) {
        cout << n << ' ';
    }
    cout << endl;

    std::array<int, 4> array;
    std::iota(array.begin(), array.end(), 1);
    for(auto n: array) {
        cout << n << ' ';
    }
    std::cout << endl;
}
