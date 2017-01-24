/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <locale>
#include <iostream>
#include <string>

class germanBoolNames : public std::numpunct_byname<char> {
  public:
    germanBoolNames (const std::string& name)
      : std::numpunct_byname<char>(name) {
    }
  protected:
    virtual std::string do_truename () const {
        return "wahr";
    }
    virtual std::string do_falsename () const {
        return "falsch";
    }
};

int main()
{
    std::locale loc (std::locale(""), new germanBoolNames(""));
    // imbue函数是指对象引用,表示输出时,使用的区域语言对象。
    /**
     * imbue函数是指对象引用,表示输出时,使用的区域语言对象。
     * 中文名 imbue函数 
     * 原    型 locale basic_ios::imbue 返回值 之前的使用的区域语言 类    别 函数
     * 函数原型:
     * locale basic_ios::imbue( const locale& loc);
     * 参数说明:
     * loc: const 对象引用,表示输出时,使用的区域语言对象
     * 返回值:
     * 之前的使用的区域语言
     * 示例:
     * #include <iostream>
     * using namespace std;
     * int main()
     * {
     * wcout.imbue(locale("chs"));//使用中文区域语言
     * wcout<<L"English中文"<<endl;
     * return 0;
     * }
     */
    std::cout.imbue(loc);
    std::cout << std::boolalpha << true << std::endl;
}
