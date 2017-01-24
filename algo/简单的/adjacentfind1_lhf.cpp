/*
 * liuhhaiffeng@163.com
 */

 #include "algostuff_lhf.hpp"
 using namespace std;

int main()
{
    vector<int> coll = {1, 3, 2, 4, 5, 5, 0};
    PRINT_ELEMENTS(coll, "coll: ");

    vector<int>::iterator pos;
    pos = adjacent_find(coll.begin(), coll.end());
    if (pos != coll.end()) {
        cout << "两个相邻并且值相等的元素Pair第一次出现的位置为: "
             << distance(coll.begin(), pos) + 1
             << endl;
    }

    pos = adjacent_find (coll.begin(), coll.end(),
                         [](int elem1, int elem2) {
                            return elem1 * 2 == elem2;
                         });
    if (pos != coll.end()) {
        cout << "输出结果为: "
             << distance(coll.begin(), pos) + 1
             << endl;
    }

    return 0;


}
