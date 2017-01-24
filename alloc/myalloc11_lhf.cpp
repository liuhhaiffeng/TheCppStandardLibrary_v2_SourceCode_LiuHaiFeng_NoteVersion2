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
#include "myalloc11.hpp"
#include "algostuff_lhf.hpp"
#include <vector>
#include <map>
#include <string>
#include <functional>

int main()
{
    // a vector with special allocator
    std::vector<int,MyAlloc<int>> v;
    INSERT_ELEMENTS(v, 1, 20);
    PRINT_ELEMENTS(v, "v:");

    // an int/float map with special allocator
    std::map<int,float,std::less<int>,
             MyAlloc<std::pair<const int,float>>> m{{1, 1.0f}, {2, 2.0f}, {3, 3.0f}};
    PRINT_MAPPED_ELEMENTS(m, "m:");

    // a string with special allocator
    std::basic_string<char,std::char_traits<char>,MyAlloc<char>> s{"This is a test"};
    std::cout << "s:" << s << '\n';


    // special string type that uses special allocator
    typedef std::basic_string<char,std::char_traits<char>,
                              MyAlloc<char>> MyStringT;
    MyStringT strTest{"This is test"};
    std::cout << "strTest:" << strTest << '\n';

    // special string/string map type that uses special allocator
    typedef std::map<MyStringT,MyStringT,std::less<MyStringT>,
                     MyAlloc<std::pair<const MyStringT,MyStringT>>> MyMapT;
    //// create object of this type
    MyMapT mymap{{"liu", "haifeng"}, {"duan", "zhiwei"}, {"yang", "bo"}};
    PRINT_MAPPED_ELEMENTS(mymap, "mymap:");
    //...
}
