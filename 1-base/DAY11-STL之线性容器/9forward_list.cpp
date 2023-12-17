/*07-单向列表的使用*/
#include <iostream>
#include <forward_list>

using namespace std;

template<typename T>
bool comp(const T &a, const T &b) {
    return a > b;
}

template<typename T>
class Compare {
public:
    bool operator()(const T &a, const T &b) {
        return a > b;
    }
};

int main() {
    forward_list<int> flt;

    flt.push_front(1);
    flt.push_front(23);
    flt.push_front(3);
    flt.push_front(36);
    flt.push_front(5);
    flt.push_front(51);
    flt.push_front(51);
    flt.push_front(51);

    cout << "正向迭代:";
    for (forward_list<int>::iterator itt = flt.begin(); itt != flt.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;
    flt.sort();
//    flt.sort(comp<int>);
    for (forward_list<int>::iterator itt = flt.begin(); itt != flt.end(); itt++) {
        cout << *itt << " ";
    }
    flt.unique();
    cout << endl;
    for (forward_list<int>::iterator itt = flt.begin(); itt != flt.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;
    return 0;
}
