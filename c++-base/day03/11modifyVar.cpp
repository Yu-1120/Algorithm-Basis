/*11-在const成员函数中修改myVar的值*/
#include <iostream>
#include <cstring>

using namespace std;

class MyClass {

public:
    MyClass(int value) : myVar(value) {}

    void modifyVar(int value) const {
        myVar = value; // 在const成员函数中修改myVar的值
    }

    void show(){
        cout<<this->myVar<<endl;
    }


private:

   mutable int myVar;


};

int main() {
    MyClass obj(10);
    obj.modifyVar(100); // 调用const成员函数修改myVar的值  !!!!
    obj.show();  //42



    return 0;
}

