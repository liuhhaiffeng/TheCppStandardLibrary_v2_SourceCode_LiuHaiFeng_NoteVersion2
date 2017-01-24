// liuhhaiffeng@163.com

#include "algostuff.hpp"
using namespace std;

int main()
{
    vector<int> coll1 = { 9, 8, 7, 7, 7, 5, 4, 2, 1 };
    vector<int> coll2 = { 5, 3, 2, 1, 4, 7, 9, 8, 6 };
    PRINT_ELEMENTS(coll1,"coll1: ");
    PRINT_ELEMENTS(coll2,"coll2: ");

    // check whether the collections are heaps
	// 让流将bool解析成为字符串"true", "false", 否则默认为(1, 0)
	// 示例代码:
	/*
	void test_boolalpha()  
    {  
        std::cout << "true is " << true << std::endl;  
        std::cout << "false is " << false << std::endl;  
      
        // 运行下面这个语句, 在输出流中的bool值将发生变化  
        std::cout << std::boolalpha;  
        std::cout << "true is " << true << std::endl;  
        std::cout << "false is " << false << std::endl;  
      
        // 运行下面这个语句, 在输出流中的bool值将恢复成0, 1值  
        std::cout << std::noboolalpha;  
        std::cout << "true is " << true << std::endl;  
        std::cout << "false is " << false << std::endl;  
      
        // 输出如下: 
        true is 1 
        false is 0 
        true is true 
        false is false 
        true is 1 
        false is 0 
          
    }  
	*/
    cout << boolalpha << "coll1 is heap: "
         << is_heap (coll1.cbegin(), coll1.cend()) << endl;
    cout << "coll2 is heap: "
         << is_heap (coll2.cbegin(), coll2.cend()) << endl;

    // print the first element that is not a heap in coll2
    auto pos = is_heap_until (coll2.cbegin(), coll2.cend());
    if (pos != coll2.end()) {
        cout << "first non-heap element: " << *pos << endl;
    }
}
