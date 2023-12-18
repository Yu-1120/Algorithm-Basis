/*06-C++的文件流*/
#include <iostream>
#include <fstream>

using namespace std;

class Date{
public:
    Date(int y=2022,int m=3,int d=21):year(y),month(m),day(d){}

    friend ostream& operator<<(ostream &os,const Date &dt)  //可以直接写在前面
    {
        return os<<dt.year<<" "<<dt.month<<" "<<dt.day;
    }

    //sprintf sscanf  fprintf fscanf
    friend istream& operator>>(istream &is,Date &dt)
    {
        return is>>dt.year>>dt.month>>dt.day;
    }

private:
    int year;
    int month;
    int day;
};


int main()
{
    //ofstream ofs("a.txt");//默认打开out+trunc
    ofstream ofs;
    ofs.open("a.txt",ios::out|ios::trunc); 
    // ios::in ----- 读打开
    // ios::out ---- 写打开
    // ios::app ---- 追加打开
    // ios::trunc --- 清空打开
    if(!ofs.is_open()){
        cout<<"打开失败!"<<endl;
        exit(-1);
    }

    //-----------------------------写数据--------------------------------
    //ofs.write("hello",5);
    //ofs.write("xiaoxiao",8);
    //ofs<<"byebye";
    Date dt;
    cout<<dt<<endl;
    ofs<<dt;//ofs<<dt.year<<"-"<<dt.month<<"-"<<dt.day;

    //关闭文件
    ofs.close();
   //---------------------------------------------------------------------
    //读文件
    ifstream ifs("a.txt");//默认ios::in打开
    if(!ifs.is_open()){  //1为文件不存在，打开失败
        cout<<"打开失败!"<<endl;
        exit(-1);
    }

    //--------------------------读数据----------------------------
    char buf[100] = {};
    int num = 0;

    //ifs.read(buf,sizeof(buf));
    //cout<<buf<<endl;
    //ifs>>num;
    //cout<<num<<endl;

    //清除流的错误
    //ifs.clear();

    //ifs>>buf;
    //cout<<buf<<endl;     .gcount()方法只能用read去读
    //cout<<"读到了"<<ifs.gcount()<<"字节"<<endl;

    Date dt1(1111,3,3);
    cout<<dt1<<endl;
    ifs>>dt1;//ifs>>dt1.year>>dt1.month>>dt1.day;
    cout<<dt1<<endl;

    ifs.close();
    //---------------------------------------------------------------------
    return 0;
}
