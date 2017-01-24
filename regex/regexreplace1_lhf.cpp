// 由于示例中并没有"regexreplace1.cpp", 所以自己手写 刘海峰
#include <string>
#include <regex>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    string data = "<person>\n"
                "<first>Nico</first>\n"
                "<last>Josuttis</last>\n"
                "</persion>\n";

    regex reg("<(.*)>(.*)</(\\1)>");

    // print data with replacement for matched patterns
    cout << regex_replace (data,                // data
                            reg,                // regular expression
                            "<$1 value=\"$2\"/>")    // replacement
        << endl;

    // same using sed syntax
    cout << regex_replace (data,
                            reg,
                            "<\\1 value=\"\\2\"/>",
                            regex_constants::format_sed)
        << endl;

    // use iterator interface, and
    // - format_no_copy: don't copy characters that don't match
    // - format_first_only: replace only the first match found
    string res2;
    regex_replace (back_inserter(res2),
                data.begin(), data.end(),
                reg,
                "<$1 value=\"$2\"/>",
                regex_constants::format_no_copy
                | regex_constants::format_first_only);

    cout << res2 << endl;

}
