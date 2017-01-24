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
#include "MyTimer.hpp"
#include <thread>
#include <chrono>
#include <assert.h>
using namespace std;

void test1()
{
    vector<int> coll;
    vector<int>::iterator pos;

    INSERT_ELEMENTS(coll,1,9);
    PRINT_ELEMENTS(coll,"coll: ");

    // define an object for the predicate (using a lambda)
    auto isEven = [](int elem) {
                      return elem%2==0;
                  };

    MyTimer tt;

    // print whether all, any, or none of the elements are/is even
    cout << boolalpha << "all even?:  "
         << all_of(coll.cbegin(),coll.cend(), isEven) << endl;
    cout << "any even?:  "
         << any_of(coll.cbegin(),coll.cend(), isEven) << endl;
    cout << "none even?: "
         << none_of(coll.cbegin(),coll.cend(), isEven) << endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    cout << "tt:" << tt.Elapsed() << " ms\n";
}

void test2()
{
    vector<int> coll;

    const int LastNum = 90000000;
    MyTimer tt;

    //coll.reserve(LastNum);
    INSERT_ELEMENTS(coll,1,LastNum);
    cout << "tt:" << tt.Elapsed() << " ms\n";

    // 打印尾部10个数据
    assert(LastNum >= 10);
    copy(coll.cbegin()+LastNum-10, coll.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // define an object for the predicate (using a lambda)
    auto isEven = [](int elem) {
                      return elem%2==0;
                  };


    tt.Reset();

    // print whether all, any, or none of the elements are/is even
    cout << boolalpha << "all even?:  "
         << all_of(coll.cbegin(),coll.cend(), isEven) << endl;
    cout << "any even?:  "
         << any_of(coll.cbegin(),coll.cend(), isEven) << endl;
    cout << "none even?: "
         << none_of(coll.cbegin(),coll.cend(), isEven) << endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::this_thread::sleep_for(std::chrono::milliseconds(33));

    cout << "tt:" << tt.Elapsed() << " ms\n";
}

int main()
{
    cout << "test1 >>>\n";
    test1();

    cout << "\n\ntest2 >>>\n";
    test2();
}
