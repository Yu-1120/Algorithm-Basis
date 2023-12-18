/*06-C++的文件流*/
#include <iostream>
#include <fstream>

using namespace std;

class Date {
public:
    Date(int y = 2022, int m = 3, int d = 21) : year(y), month(m), day(d) {}

    friend ostream &operator<<(ostream &os, const Date &dt)  //可以直接写在前面
    {
        return os << dt.year << " " << dt.month << " " << dt.day;
    }

    //sprintf sscanf  fprintf fscanf
    friend istream &operator>>(istream &is, Date &dt) {
        return is >> dt.year >> dt.month >> dt.day;
    }

private:
    int year;
    int month;
    int day;
};


int main() {
    //ofstream ofs("a.txt");//默认打开out+trunc
    ofstream ofs;
    ofs.open("b.txt", ios::out | ios::trunc);
    // ios::in ----- 读打开
    // ios::out ---- 写打开
    // ios::app ---- 追加打开
    // ios::trunc --- 清空打开
    if (!ofs.is_open()) {
        cout << "打开失败!" << endl;
        exit(-1);
    }

    //-----------------------------写数据------------------------------
//    cout<<dt<<endl;
//    ofs << dt;
    //ofs<<dt.year<<"-"<<dt.month<<"-"<<dt.day;
    //-----------------------------------------------------------------
    return 0;
}
