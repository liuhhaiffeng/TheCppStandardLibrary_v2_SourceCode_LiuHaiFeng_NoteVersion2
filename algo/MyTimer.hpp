/**
 * @file MyTimer.hpp
 * @synopsis  自定义计时器
 * @author drunkedcat, whitelilis@gmail.com
 * @version 1.0
 * @date 2017-01-22
 */

#include <time.h>

#ifndef _MYTIMER_H_
#define _MYTIMER_H_

class MyTimer
{
    public:
        MyTimer()
        {
            m_tStart = clock();
        }

        void Reset()
        {
            m_tStart = clock();
        }

        // 返回值精度: milliseconds (毫秒)
        double Elapsed() const
        {
            return 1000.0 * (clock() - m_tStart)/CLOCKS_PER_SEC;
        }

    private:
        clock_t m_tStart;
};

#endif // _MYTIMER_H_

