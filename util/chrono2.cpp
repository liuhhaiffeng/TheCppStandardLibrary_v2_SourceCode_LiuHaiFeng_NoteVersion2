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
#include <iostream>
#include <string>
#include <system_error>
using namespace std;

string asString (const chrono::system_clock::time_point& tp)
{
    time_t t = chrono::system_clock::to_time_t(tp); // convert to system time
    string ts = ctime(&t);                          // convert to calendar time
    ts.resize(ts.size()-1);                         // skip trailing newline
    return ts; 
}

string asString2 (const chrono::system_clock::time_point& tp)
{
    time_t t = chrono::system_clock::to_time_t(tp); // convert to system time
    if (t <= 0)
    {
        //std::error_code ec (-1, std::system_category());
        std::error_code ec (-1, std::generic_category());
        throw std::system_error(ec, "error time");
    }
    string ts = ctime(&t);                          // convert to calendar time
    ts.resize(ts.size()-1);                         // skip trailing newline
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
    // define type for durations that represent day(s):
    typedef chrono::duration<int,ratio<3600*24>> Days;

    // process the epoch of this system clock
    chrono::time_point<chrono::system_clock> tp;
    cout << "epoch:     " << asString(tp) << endl;

    // add one day, 23 hours, and 55 minutes
    tp += Days(1) + chrono::hours(23) + chrono::minutes(55);
    cout << "later:     " << asString(tp) << endl;

    // process difference from epoch in minutes and days:
    auto diff = tp - chrono::system_clock::time_point();
    cout << "diff:      "
         << chrono::duration_cast<chrono::minutes>(diff).count()
         << " minute(s)" << endl;
    Days days = chrono::duration_cast<Days>(diff);
    cout << "diff:      " << days.count() << " day(s)" << endl;

    // subtract one year (hoping it is valid and not a leap year)
    tp -= chrono::hours(24*365);
    cout << "-1 year:   " << asString(tp) << endl;

    // subtract 50 years (hoping it is valid and ignoring leap years)
    tp -= chrono::duration<int,ratio<3600*24*365>>(50);
    cout << "-50 years: " << asString(tp) << endl;

    // subtract 50 years (hoping it is valid and ignoring leap years)
    tp -= chrono::duration<int,ratio<3600*24*365>>(50);
    cout << "-50 years: " << asString(tp) << endl;
}

void test2()
{
    // define type for durations that represent day(s):
    typedef chrono::duration<int,ratio<3600*24>> Days;

    try
    {
        // process the epoch of this system clock
        chrono::time_point<chrono::system_clock> tp;
        cout << "epoch:     " << asString2(tp) << endl;

        // add one day, 23 hours, and 55 minutes
        tp += Days(1) + chrono::hours(23) + chrono::minutes(55);
        cout << "later:     " << asString2(tp) << endl;

        // process difference from epoch in minutes and days:
        auto diff = tp - chrono::system_clock::time_point();
        cout << "diff:      "
            << chrono::duration_cast<chrono::minutes>(diff).count()
            << " minute(s)" << endl;
        Days days = chrono::duration_cast<Days>(diff);
        cout << "diff:      " << days.count() << " day(s)" << endl;

        // subtract one year (hoping it is valid and not a leap year)
        tp -= chrono::hours(24*365);
        cout << "-1 year:   " << asString2(tp) << endl;

        // subtract 50 years (hoping it is valid and ignoring leap years)
        tp -= chrono::duration<int,ratio<3600*24*365>>(50);
        cout << "-50 years: " << asString2(tp) << endl;

        // subtract 50 years (hoping it is valid and ignoring leap years)
        tp -= chrono::duration<int,ratio<3600*24*365>>(50);
        cout << "-50 years: " << asString2(tp) << endl;
    }
    catch (std::system_error& err)
    {
        cout << "ERROR:\n";
        cout << "\tCODE: " << err.code() << '\n';
        cout << "\tMSG : " << err.what() << '\n';
    }
}
