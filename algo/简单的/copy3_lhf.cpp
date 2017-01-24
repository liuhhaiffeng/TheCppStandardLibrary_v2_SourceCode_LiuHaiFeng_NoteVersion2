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
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> args;
    for (int i = 0; i < argc; ++i)
    {
        args.push_back(argv[i]);
    }

    copy(args.begin(), args.end(), ostream_iterator<string>(cout, ", "));
    cout << '\n';
}
