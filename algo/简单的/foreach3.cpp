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

// function object to process the mean value
class MeanValue {
  private:
    long num;    // number of elements
    long sum;    // sum of all element values
  public:
    // constructor
    MeanValue () : num(0), sum(0) {
    }

    // function call
    // - process one more element of the sequence
    void operator() (int elem) {
        num++;          // increment count
        sum += elem;    // add value
    }

    // return mean value (implicit type conversion)
    operator double() {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
};

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll,1,8);
    PRINT_ELEMENTS(coll);       // lhf add

#if 0       // lhf modify
    process and print mean value
    double mv = for_each (coll.begin(), coll.end(),  // range
                          MeanValue());              // operation
#else
    MeanValue mvalue;
    // for_each执行结束后会返回一个"MeanValue"类的实例
    // 这个实例是有状态的, 它里面包含了for_each()操作过程
    // 的状态
    mvalue = for_each (coll.begin(), coll.end(),  // range
                       MeanValue());              // operation

    // mvalue是一个类实例, 由于类中重载了"operator double()",
    // 所以mvalue执行到double的转换时, 重载的"operator double()"
    // 的方法被调用(计算平均值)
    double mv = mvalue;
#endif // 0

    cout << "mean value: " << mv << endl;
}
