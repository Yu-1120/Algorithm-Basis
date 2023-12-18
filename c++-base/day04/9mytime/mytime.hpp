#ifndef MYTIME_HPP
#define MYTIME_HPP

//类的声明
class mytime{
public:
    //函数只留下声明语句
    mytime(int h=15,int m=27,int s=30);//参数默认值写到声明中
    ~mytime();

    void print_time();
    void run();

private:
    int hour;
    int min;
    int sec;
};


#endif // MYTIME_HPP
