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
#include <tuple>
#include <iostream>
#include <complex>
#include <string>
using namespace std;

int main()
{
    // create a four-element tuple
    // - elements are initialized with default value (0 for fundamental types)
	//tuple<string, int, int, complex<double>> t("tuple test", 30, 175, complex<double>(3.5, 4.0));     // complex写法1
	tuple<string, int, int, complex<double>> t("tuple test", 30, 175, (3.5 + 4.0i));                    // complex写法2
	cout << "tuple::t :" << get<0>(t) << ", " << get<1>(t) << ", " 
		<< get<2>(t) << ", " << get<3>(t) << '\n';

    // create and initialize a tuple explicitly
    tuple<int,float,string> t1(41,6.3,"nico");

    // "iterate" over elements:
    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " ";
    cout << endl;

    // create tuple with make_tuple()
    // - auto declares t2 with type of right-hand side
    // - thus, type of t2 is tuple
    auto t2 = make_tuple(22,44,"nico");

    // assign second value in t2 to t1
    get<1>(t1) = get<1>(t2); 

    // comparison and assignment
    // - including type conversion from tuple<int,int,const char*>
    //   to tuple<int,float,string>
    if (t1 < t2) {  // compares value for value
        t1 = t2;    // OK, assigns value for value
    }
}
