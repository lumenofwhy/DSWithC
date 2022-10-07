/*
 * @Author: Lumen
 * @Date: 2021-12-12 14:14:01
 * @LastEditTime: 2022-02-27 21:23:31
 * @LastEditors: Lumen
 * @Description: 算法复杂度与时间的关系
 * 👻👻👻👻👻👻👻👻
 */
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

void function1(long long n)
{
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        k++;
    }
}

void function2(long long n)
{
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            k++;
        }
    }
}

void function3(long long n)
{
    long long k = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 1; j < n; j *= 2)
        {
            k++;
        }
    }
}

int main()
{
    long long n = 0;
    while (1)
    {
        cout << "输入n：";
        cin >> n;
        milliseconds start_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        function1(n);
        // function2(n);
        // function3(n);
        milliseconds end_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

        cout << "耗时：" << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
    }

    return 0;
}
