#include <iostream>
#include <list>

using namespace std;

class student {
public:
    student(int id = 0, string name = "", int age = 0) : id(id), name(name), age(age) {}

    //按名字去重，==判断name,想要去重哪个值就要去重那个
    bool operator==(const student &s) const {  //为什么是返回布尔值的
        return this->name == s.name;
    }

    //默认按id从小到大排序
    bool operator<(const student &s) const {
        return this->id < s.id;
    }

    bool operator>(const student &s) const {
        return this->age > s.age;
    }

    //自己作为函数对象用作比较器 name排序
    bool operator()(const student &s1, const student &s2) {
        return s1.name < s2.name;
    }

    //重载输出
    friend ostream &operator<<(ostream &os, const student &s) {
        return os << s.id << ":" << s.name << ":" << s.age;
    }

private:
    int id;
    string name;
    int age;
};

//函数比较器 T-student ===> 年龄从大到小
template<typename T>
bool comp(const T &a, const T &b) {
    return a > b;
}

int main() {
    list<student> ban;
    list<student> xue;

    ban.push_back(student(4, "张飞", 23));
    ban.push_back(student(2, "关羽", 26));
    ban.push_back(student(5, "赵云", 19));
    ban.push_back(student(1, "刘备", 31));
    ban.push_back(student(6, "黄忠", 50));

    xue.push_back(student(9, "曹操", 35));
    xue.push_back(student(7, "张辽", 27));
    xue.push_back(student(11, "关羽", 26));
    xue.push_back(student(8, "典韦", 24));
    xue.push_back(student(10, "刘备", 31));

    //合并
    ban.splice(ban.end(), xue);
    //合并结果
    cout << "合并后:" << endl;
    for (list<student>::iterator it = ban.begin(); it != ban.end(); it++) {
        cout << *it << endl;
    }
    cout << "------------------------------------------------" << endl;

    //去除重名 ----- 按名字排序(函数对象比较器),去重
    ban.sort(student());
    ban.unique();//需要去重载---operator==
    cout << "姓名排序去重后:" << endl;
    for (list<student>::iterator it = ban.begin(); it != ban.end(); it++) {
        cout << *it << endl;
    }
    cout << "------------------------------------------------" << endl;

    //按学号升序排序
    ban.sort(); //需要去重载  operator<
    cout << "学号升序排序后:" << endl;
    for (list<student>::iterator it = ban.begin(); it != ban.end(); it++) {
        cout << *it << endl;
    }
    cout << "------------------------------------------------" << endl;

    //按年龄降序排序 
    ban.sort(comp<student>);  //需要去重载  operator>
    cout << "年龄降序排序后:" << endl;
    for (list<student>::iterator it = ban.begin(); it != ban.end(); it++) {
        cout << *it << endl;
    }
    cout << "------------------------------------------------" << endl;

    return 0;
}
