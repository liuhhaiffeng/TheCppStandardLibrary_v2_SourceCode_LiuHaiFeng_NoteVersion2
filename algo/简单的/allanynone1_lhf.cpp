// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
using namespace std;

int main()
{
    vector<int> coll;
    vector<int>::iterator pos;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    auto isEven = [](int elem) {
                        return elem %2 == 0;
                    };

    cout << boolalpha << "all even?: "
         << all_of(coll.cbegin(), coll.cend(), isEven) << endl;
    cout << "any even?: "
         << any_of(coll.cbegin(), coll.cend(), isEven) << endl;
    cout << "none even?: "
         << none_of(coll.cbegin(), coll.cend(), isEven) << endl;

    return 0;
}
