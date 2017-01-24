// ¡ı∫£∑Â 2017-1-12

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

class AddValue
{
    public:
       explicit AddValue(int v) : theValue(v) {}

       void operator() (int& elem) const
       {
            elem += theValue;
       }

    private:
        int theValue;
};

int main()
{
    list<int> coll;
    for (int i = 1; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    auto myBegin = coll.begin();
    advance(myBegin, coll.size()-1);
    copy(coll.begin(), myBegin, ostream_iterator<int>(cout, ", "));
    cout << coll.back() << '\n';

    for_each(coll.begin(), coll.end(), AddValue(10));
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, ", "));
    cout << '\n';

}
