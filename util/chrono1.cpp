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
#include <chrono>
#include <ctime>
#include <string>
#include <iostream>

std::string asString (const std::chrono::system_clock::time_point& tp)
{
    // convert to system time:
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::cout << "t:" << t << std::endl; // 刘海峰 add
    std::string ts = std::ctime(&t);    // convert to calendar time
    ts.resize(ts.size()-1);             // skip trailing newline
    return ts; 
}

std::string asString2(const std::chrono::system_clock::time_point& tp)
{
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    if (t <= 0)
    {
        return "";
    }
    std::string ts = std::ctime(&t);
    ts.resize(ts.size()-1);
    return ts;
}

void test1();
void test2();   // 刘海峰 add

int main()
{
    test2();
}

void test1()
{
    try
    {
        // print the epoch of this system clock:
        std::chrono::system_clock::time_point tp;
        std::cout << "epoch: " << asString(tp) << std::endl << std::endl;

        // print current time:
        tp = std::chrono::system_clock::now();
        std::cout << "now:   " << asString(tp) << std::endl << std::endl;

        // print maximum time of this system clock:
        tp = std::chrono::system_clock::time_point::max();
        std::cout << "max:   " << asString(tp) << std::endl << std::endl;

        // print minimum time of this system clock:
        tp = std::chrono::system_clock::time_point::min();
        // time_point::min()返回值是错误的, 原因未知?
         std::cout << "hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                   tp.time_since_epoch()).count() 
              << '\n';  // 刘海峰 add
        std::cout << "min:   " << asString(tp) << std::endl << std::endl;
    }
    catch(std::exception& ex)
    {
        std::cout << "err:" << ex.what() << '\n';
    }
}

void test2()
{
    try
    {
        // print the epoch of this system clock:
        std::chrono::system_clock::time_point tp;
        std::cout << "epoch: " << asString2(tp) << std::endl << std::endl;

        // print current time:
        tp = std::chrono::system_clock::now();
        std::cout << "now:   " << asString2(tp) << std::endl << std::endl;

        // print maximum time of this system clock:
        tp = std::chrono::system_clock::time_point::max();
        std::cout << "max:   " << asString2(tp) << std::endl << std::endl;

        // print minimum time of this system clock:
        tp = std::chrono::system_clock::time_point::min();
        // time_point::min()返回值是错误的, 原因未知?
         std::cout << "hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                   tp.time_since_epoch()).count() 
              << '\n';  // 刘海峰 add
        std::cout << "min:   " << asString2(tp) << std::endl << std::endl;
    }
    catch(std::exception& ex)
    {
        std::cout << "err:" << ex.what() << '\n';
    }
}
