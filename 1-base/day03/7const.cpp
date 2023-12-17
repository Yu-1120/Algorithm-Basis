/*07-const对象和const成员*/
#include <iostream>
#include <cstring>

using namespace std;

class A{
public:
    A(int n=0,int m=0):num(n),x(m){}

    void show()
    {
        //this->num = 111;
        cout<<"show()"<<endl;
    }


    void show()const//const成员函数
    {
        this->x = 100;
        cout<<"x:"<<x<<endl;
        cout<<"show()const"<<endl;
    }

    //加了const有什么用

    /*


    const关键字用于声明常量，表示该变量的值在程序运行期间不可改变。

    对于成员变量，如果一个类声明了const成员变量，那么这个成员变量的值只能在构造函数中进行初始化，

    并且在对象的整个生命周期中，其值是不可修改的。这保证了对象的状态的不变性，同时也提供了一些额外的安全性。

    在上述代码中，num成员变量被声明为const，因此它的值只能在构造函数中初始化，并且不能被修改。

    这确保了num成员变量的值在整个对象的生命周期中保持不变。

    另外，在const成员函数中，可以通过mutable关键字来修改成员变量的值。这意味着即使成员变量是const的，

    我们仍然可以在const成员函数中修改它。在上述代码中，x成员变量被声明为mutable，因此我们可以在show()const函数中修改它的值。

        在const成员函数中，我们可以通过mutable关键字来修饰要修改的成员变量，以允许在函数中对其进行修改。


        class MyClass {
        private:
            int myVar;
        public:
            MyClass(int value) : myVar(value) {}

            void modifyVar() const {
                myVar = 42; // 在const成员函数中修改myVar的值
            }
        };

        int main() {
            MyClass obj(10);
            obj.modifyVar(); // 调用const成员函数修改myVar的值  !!!!
            return 0;
        }





    */

private:
    const int num;//const成员变量
    mutable int x;//允许在const成员函数中修改
};

int main()
{
    A a(10,20);
    const A b(66,88);//const对象

    a.show();
    // show()

    b.show();
    //x:100
    // show()const
 /*
     outcome：
    // show()
    //x:100
    // show()const



    */



    return 0;
}
