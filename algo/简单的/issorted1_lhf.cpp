// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
using namespace std;

int main()
{
    vector<int> coll1 = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    PRINT_ELEMENTS(coll1, "coll1: ");

    if (is_sorted(coll1.begin(), coll1.end())) {
        cout << "coll1 is sored" << endl;
    }
    else {
        cout << "coll1 is not sorted" << endl;
    }

    map<int, string> coll2;
    coll2 = { {1, "Bill"}, {2, "Jim"}, {3, "Nico"}, {4, "Liu"}, {5, "Ai"} };
    PRINT_MAPPED_ELEMENTS(coll2, "coll2: ");

    map<int, string> coll3;
    coll3 = { {1, "Bill"}, {2, "Jim"}, {3, "Nico"}, {4, "Qiu"}, {5, "Ti"} };
    PRINT_MAPPED_ELEMENTS(coll3, "coll2: ");

    auto compareName = [](const pair<int, string> &e1,
                          const pair<int, string> &e2) {
                          return e1.second < e2.second;
                          };
    if (is_sorted(coll2.cbegin(), coll2.cend(),
                  compareName)) {
        cout << "names in coll2 are sorted" << endl;
    }
    else {
        cout << "names in coll2 are not sorted" << endl;
    }

    if (is_sorted(coll3.cbegin(), coll3.cend(),
                  compareName)) {
        cout << "names in coll3 are sorted" << endl;
    }
    else {
        cout << "names in coll3 are not sorted" << endl;
    }
}
