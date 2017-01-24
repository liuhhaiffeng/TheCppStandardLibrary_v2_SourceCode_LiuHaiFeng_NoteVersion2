// liuhhaiffeng@163.com

#include "algostuff_lhf.hpp"
using namespace std;

class MeanValue {
private:
	long num;	// 元素的个数
	long sum;	// 所有元素值的和
public:
	MeanValue() : num(0), sum(0) {
		cout << "MeanValue() constructor" << endl;
	}

	MeanValue(int num) : sum(0) {
		this->num = num;
		cout << "MeanValue(int num) constructor" << endl;
	}

	void operator() (int elem) {
		++num;
		sum += elem;
	}

	operator double() {
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll, 1, 8);
	PRINT_ELEMENTS(coll);

	MeanValue mvalue;
	MeanValue mvalue2(2);
	// for_each执行结束后会返回一个"MeanValue"类的实例
	// 这个实例是有状态的, 它里面包含了for_each()操作过程
	// 的状态

#if 1

	mvalue = for_each(coll.begin(), coll.end(), mvalue);
	mvalue2 = for_each(coll.begin(), coll.end(), mvalue2);
#else
	// mvalue = for_each(coll.begin(), coll.end(), MeanValue()); 等价于如下代码:
	// MeanValue tmp;
	// mvalue = for_each(coll.begin(), coll.end(), tmp);

	mvalue = for_each(coll.begin(), coll.end(), MeanValue());
	mvalue2 = for_each(coll.begin(), coll.end(), MeanValue(2));
#endif

	// mvalue是一个类实例, 由于类中重载了"operator double()",
	// 所以mvalue执行到double的转换时, 重载的"operator double()"
	// 的方法被调用(计算平均值)
	double mv = mvalue;
	cout << "mean value: " << mv << endl;

	double mv2 = mvalue2;
	cout << "mean value2: " << mv2 << endl;
}