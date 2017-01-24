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
void test2();

int main()
{
    test2();
}

void test1()
{
    vector<int> coll;
    // 插入[1,9]的序列(包括9)
    INSERT_ELEMENTS(coll,1,9);
    PRINT_ELEMENTS(coll);

    // process sum of elements
    cout << "sum: "
        << accumulate (coll.cbegin(), coll.cend(),  // range
                0)                           // initial value
        << endl;

    // process sum of elements less 100
    cout << "sum: "
        << accumulate (coll.cbegin(), coll.cend(),  // range
                -100)                        // initial value
        << endl;

    // process product of elements
    cout << "product: "
        << accumulate (coll.cbegin(), coll.cend(),  // range
                1,                           // initial value
                multiplies<int>())           // operation
        << endl;

    // process product of elements (use 0 as initial value)
    cout << "product: "
        << accumulate (coll.cbegin(), coll.cend(),  // range
                0,                           // initial value
                multiplies<int>())           // operation
        << endl;
}

void test2()
{
    vector<int> coll;
    const int LastNum = 1000000;
    INSERT_ELEMENTS(coll, 1, LastNum);
    // 打印尾部10个数据
    copy(coll.cbegin()+LastNum-10, coll.cend(), ostream_iterator<int>(cout, ", "));
    cout << '\n';
    cout << "sum: " << accumulate(coll.cbegin(), coll.cend(), 0) << '\n';
    cout << "sum: " << accumulate(coll.cbegin(), coll.cend(), -LastNum) << '\n';

    vector<int> collTwo;
    const int LastNumTwo = 20;
    INSERT_ELEMENTS(collTwo, 1, LastNumTwo);
    // 打印尾部10个数据
    copy(collTwo.cbegin(), collTwo.cend(), ostream_iterator<int>(cout, ", "));
    cout << '\n';
    cout << "product: " << accumulate(collTwo.cbegin(), collTwo.cend(), 0, multiplies<int>()) << '\n';

    /**
     *  template< class InputIt, class T >
     *  T accumulate( InputIt first, InputIt last, T init );
     *
     *  template< class InputIt, class T, class BinaryOperation >
     *  T accumulate( InputIt first, InputIt last, T init, BinaryOperation op );
     */

    // accumulate()的返回类型与第3个参数 T init有关, 此处init为1, 默认为int
    // 所以计算20的内积值会溢出
    cout << "product: " << accumulate(collTwo.cbegin(), collTwo.cend(), 1, multiplies<int>()) << '\n';

    // 定义init类型为unsigned long long, 20的内积计算正常
    unsigned long long initValue = 1;
    cout << "product: " << accumulate(collTwo.cbegin(), collTwo.cend(), initValue, multiplies<int>()) << '\n';

    /// 总结: accumulate()的返回值类型由init的类型决定, 所以在使用accumulate()要注意可能的"值溢出"

}
