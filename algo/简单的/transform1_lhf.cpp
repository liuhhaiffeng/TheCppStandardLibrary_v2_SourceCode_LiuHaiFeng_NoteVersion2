// 刘海峰 liuhhaiffeng@163.com 2017-01-12
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <functional>
#include <iterator>

template <typename T>
inline void InsertElements(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

template <typename T>
inline void PrintElements(const T& coll, const std::string& optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> collVec;
    std::list<int> collList;

    InsertElements(collVec, 1, 9);
    PrintElements(collVec, "collVec:");

    std::transform(collVec.cbegin(), collVec.cend(), collVec.begin(), std::negate<int>());
    PrintElements(collVec, "negated:");

    std::transform(collVec.cbegin(), collVec.cend(), std::back_inserter(collList),
            std::bind(std::multiplies<int>(), std::placeholders::_1, 10));
    PrintElements(collList, "collList:");

    std::transform(collList.crbegin(), collList.crend(), std::ostream_iterator<int>(std::cout, " "),
            [](int elem ) {
                return -elem;
            });
    std::cout << std::endl;
}
