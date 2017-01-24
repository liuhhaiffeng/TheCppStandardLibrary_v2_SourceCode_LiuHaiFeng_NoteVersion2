/*
   liuhhaiffeng@163.com
*/
#ifndef ALGOSTUFF_LHF_HPP
#define ALGOSTUFF_LHF_HPP

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>

// 向coll集合插入[first,last]的连续元素(注意:包括last元素)
template <typename T>
inline void INSERT_ELEMENTS (T &coll, int first, int last)
{
    for (int i = first; i <= last; ++i) {
        coll.insert(coll.end(), i);
    }
}

// 在控制台上打印(或输出)coll集合中的元素, 第2个参数允许在打印
// 的时候输出一个"说明性"的字符串
template <typename T>
inline void PRINT_ELEMENTS (const T &coll, const std::string &optcstr="")
{
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
inline void PRINT_MAPPED_ELEMENTS (const T &coll, const std::string &optcstr="")
{
    std::cout << optcstr;
    for (auto elem : coll) {
        std::cout << '[' << elem.first
                << ',' << elem.second << "] ";
    }
    std::cout << std::endl;
}

#endif /*ALGOSTUFF_LHF_HPP*/
