// liuhhaiffeng@163.com

#include <cstdlib>
#include "algostuff_lhf.hpp"
using namespace std;

int main()
{
	list<int> coll;
	
	generate_n(back_inserter(coll), 5, rand);
	PRINT_ELEMENTS(coll);

	generate(coll.begin(), coll.end(), rand);
	PRINT_ELEMENTS(coll);
	
}