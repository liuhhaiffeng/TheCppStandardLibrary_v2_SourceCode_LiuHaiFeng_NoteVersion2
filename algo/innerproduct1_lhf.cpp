// liuhhaiffeng@163.com
#include "algostuff_lhf.hpp"
using namespace std;

int main()
{
    list<int> coll;
    INSERT_ELEMENTS(coll, 1, 6);
    PRINT_ELEMENTS(coll);

    // (0 + 1*1 + 2*2 + 3*3 + 4*4 ...)
    cout << "inner product: "
         << inner_product(coll.cbegin(), coll.cend(),
                          coll.cbegin(), 0)
         << endl;

    // (0 + 1*6 + 2*5 + 3*4 ...)
    cout << "inner reverse product: "
         << inner_product(coll.cbegin(), coll.cend(),
                          coll.crbegin(), 0)
         << endl;

    /*
    template<class InputIterator1, class InputIterator2, class Type,
   class BinaryOperation1, class BinaryOperation2>
   Type inner_product(
      InputIterator1 _First1,
      InputIterator1 _Last1,
      InputIterator2 _First2,
      Type _Val,
      BinaryOperation1 _Binary_op1,
      BinaryOperation2 _Binary_op2
   );

   _Val _Binary_op1 ( a1 _Binary_op2 b1 ) _Binary_op1 ( a2 _Binary_op2 b2 ) _Binary_op1
   */
    // (1(init) * (1+1) * (2+2) * (3+3) * (4+4) * (5+5) * (6+6))
    cout << "prodct of sums: "
         << inner_product(coll.cbegin(), coll.cend(),
                          coll.cbegin(),
                          1,    // init value
                          multiplies<int>(),
                          plus<int>())
         << endl;
}
