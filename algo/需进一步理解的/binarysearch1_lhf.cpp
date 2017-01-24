// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
#include <random>

using namespace std;

int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll);

    if (binary_search(coll.cbegin(), coll.cend(), 5)) {
        cout << "5 is present" << endl;
    }
    else {
        cout << "5 is not present" << endl;
    }

    return 0;
}
