/*11-��const��Ա�������޸�myVar��ֵ*/
#include <iostream>
#include <cstring>

using namespace std;

class MyClass {

public:
    MyClass(int value) : myVar(value) {}

    void modifyVar(int value) const {
        myVar = value; // ��const��Ա�������޸�myVar��ֵ
    }

    void show(){
        cout<<this->myVar<<endl;
    }


private:

   mutable int myVar;


};

int main() {
    MyClass obj(10);
    obj.modifyVar(100); // ����const��Ա�����޸�myVar��ֵ  !!!!
    obj.show();  //42



    return 0;
}

