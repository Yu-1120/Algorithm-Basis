/*07-列表的使用*/
#include <iostream>
#include <list>

using namespace std;

//函数比较器
template<typename T>
bool comp(const T &a, const T &b) {
    return a > b;
}

//函数对象比较器
template<typename T>
class Compare {
public:
    bool operator()(const T &a, const T &b) {
        return a > b;
    }
};


int main() {
    list<int> li1;
    li1.push_back(1);
    li1.push_back(2);
    li1.push_back(3);
    li1.push_back(4);
    li1.push_back(5);
    li1.push_back(6);
    li1.push_back(5);
    li1.push_back(8);
    li1.push_back(9);
    li1.push_back(10);
    li1.push_back(11);

    list<int> li2;
    li2.push_back(31);
    li2.push_back(52);
    li2.push_back(63);
    li2.push_back(14);
    li2.push_back(95);
    li2.push_back(5);
    li2.push_back(87);
    li2.push_back(78);
    li2.push_back(59);
    li2.push_back(111);

    //遍历
//    cout<<"list1正向迭代:";
//    for(list<int>::iterator itt=li1.begin();itt!=li1.end();itt++){
//        cout<<*itt<<" ";
//    }
//    cout<<endl;
//    cout<<"list2正向迭代:";
//    for(list<int>::iterator itt=li2.begin();itt!=li2.end();itt++){
//        cout<<*itt<<" ";
//    }
//    cout<<endl;
//
//    //插入删除
//    li1.insert(++li1.begin(),100);
//    li1.erase(--li1.end());
//    cout<<"插入删除后:";
//    for(list<int>::iterator itt=li1.begin();itt!=li1.end();itt++){
//        cout<<*itt<<" ";
//    }
//    cout<<endl;
//
//    //按值删除
//    //li1.remove(5);
//    //li1.unique();
//    cout<<"remove删除后:";
//    for(list<int>::iterator itt=li1.begin();itt!=li1.end();itt++){
//        cout<<*itt<<" ";
//    }
//    cout<<endl;

    //排序
    //li1.sort();
    //li2.sort();
    //使用函数比较器
    //li1.sort(comp<int>);
    //使用函数对象比较器
    li1.sort(Compare<int>());
    li2.sort(Compare<int>());
    cout << "list1排序后:";
    for (list<int>::iterator itt = li1.begin(); itt != li1.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;

    cout << "list2排序后:";
    for (list<int>::iterator itt = li2.begin(); itt != li2.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;

    //剪切
    //li1.splice(++li1.begin(),li2);
    //li1.splice(++li1.begin(),li2,++li2.begin(),--li2.end());

    //合并
    //li1.merge(li2);
    li1.merge(li2, Compare<int>());//合并的比较方法要和排序的比较方法一致

    cout << "list1正向迭代:";
    for (list<int>::iterator itt = li1.begin(); itt != li1.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;
    cout << "list2正向迭代:";
    for (list<int>::iterator itt = li2.begin(); itt != li2.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;

    //删除li1中相邻的重复元素
    li1.unique();

    cout << "list1正向迭代:";
    for (list<int>::iterator itt = li1.begin(); itt != li1.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;

    return 0;
}
