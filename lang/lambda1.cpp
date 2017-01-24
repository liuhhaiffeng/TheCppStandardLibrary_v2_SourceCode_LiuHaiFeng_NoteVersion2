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
#include<functional>
#include<iostream>
#include<string>
#include<sstream>

std::function<int(int,int)> returnLambda ()
{
    return [] (int x, int y) {
               return x*y;
           };
}

// lhf add
// 1
std::function<std::string(std::string name, int age, int height, int weight)> returnPersonInfo ()
{
    return [] (std::string name, int age, int height, int weight) {
        std::ostringstream oss;
        oss << "My name is : " << name << ", age:" << age << ", height:"
            << height << ", weight:" << weight << std::endl;
        return oss.str();
    };
}
// !1

int main()
{
    auto lf = returnLambda();
    std::cout << lf(6,7) << std::endl;

    auto personInfo = returnPersonInfo();
    std::cout << personInfo("liuhaifeng", 28, 173, 73) << std::endl;
}
