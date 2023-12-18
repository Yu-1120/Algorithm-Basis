#include <iostream>
#include <unistd.h>
#include "mytime.hpp"
#include <chrono>
#include <ctime>
using namespace std;

int main()
{


    // ��ȡ��ǰʱ���
    auto now = std::chrono::system_clock::now();
    // ��ʱ���ת��Ϊtime_t����
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    // ������ʱ��ת��Ϊtm�ṹ��
    std::tm* localTime = std::localtime(&currentTime);

    // ��ȡ����ʱ�䲿��
    int year = localTime->tm_year + 1900; // �����Ҫ����1900
    int month = localTime->tm_mon + 1;    // �·ݴ�0��ʼ����Ҫ��1
    int day = localTime->tm_mday;         // ����
    int hour = localTime->tm_hour;        // Сʱ
    int minute = localTime->tm_min;       // ����
    int second = localTime->tm_sec;       // ��

    mytime t(hour,minute,second);

    while(1){
        t.print_time();
        sleep(1);
        t.run();
    }

    return 0;
}
