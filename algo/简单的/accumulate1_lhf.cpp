/*
 * liuhhaiffeng@163.com
 */

 #include "algostuff_lhf.hpp"
 using namespace std;

 int main()
 {
     vector<int> coll;

     INSERT_ELEMENTS(coll, 1, 9);
     PRINT_ELEMENTS(coll);

     cout << "sum: "
          << accumulate (coll.cbegin(), coll.cend(),
          0)
          << endl;

    cout << "sum: "
         << accumulate(coll.cbegin(), coll.cend(),
                       -100)
         << endl;

    cout << "product: "
         << accumulate (coll.cbegin(), coll.cend(),
                        1,
                        multiplies<int>())
         << endl;

    cout << "product: "
         << accumulate (coll.cbegin(), coll.cend(),
                        0,
                        multiplies<int>())
         << endl;

     return 0;
 }

