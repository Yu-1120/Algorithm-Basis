#include <iostream>
#include <unistd.h>
#include "mytime.hpp"
#include <chrono>
#include <ctime>
using namespace std;

int main()
{


    // 获取当前时间点
    auto now = std::chrono::system_clock::now();
    // 将时间点转换为time_t类型
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    // 将本地时间转换为tm结构体
    std::tm* localTime = std::localtime(&currentTime);

    // 提取各个时间部分
    int year = localTime->tm_year + 1900; // 年份需要加上1900
    int month = localTime->tm_mon + 1;    // 月份从0开始，需要加1
    int day = localTime->tm_mday;         // 日期
    int hour = localTime->tm_hour;        // 小时
    int minute = localTime->tm_min;       // 分钟
    int second = localTime->tm_sec;       // 秒

    mytime t(hour,minute,second);

    while(1){
        t.print_time();
        sleep(1);
        t.run();
    }

    return 0;
}
