/*07-列表存储对象的使用*/
#include <iostream>
#include <list>

using namespace std;

class Product {
public:
    Product(double p = 0.0, size_t c = 0) : price(p), count(c) {}

    //支持按值删除 查找 去重，重载==运算符
    bool operator==(const Product &p) {
        return this->price - p.price >= -1e-15 && this->price - p.price <= 1e-15;
    }

    //支持默认排序，合并,提供<重载
    bool operator<(const Product &p) {
        //按单价排
        return this->price < p.price;
    }

    friend ostream &operator<<(ostream &os, const Product &p) {
        return os << p.price << "X" << p.count;
    }

    //比较器友元
    friend bool comp(const Product &p1, const Product &p2);

    friend class Compare;

private:
    double price;
    size_t count;
};

//提供函数比较器
bool comp(const Product &p1, const Product &p2) {
    //按数量从大到小
    return p1.count > p2.count;
}

//提供函数对象比较器
class Compare {
public:
    bool operator()(const Product &p1, const Product &p2) {
        //按总价从小到大
        return p1.price * p1.count < p2.price * p2.count;
    }
};

int main() {
    list<Product> lp;
    lp.push_back(Product(12.5, 10));
    lp.push_back(Product(3.2, 40));
    lp.push_back(Product(55.7, 31));
    lp.push_back(Product(113.3, 98));
    lp.push_back(Product(0.6, 6));

    cout << "list正向迭代:";
    for (list<Product>::iterator itt = lp.begin(); itt != lp.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;

    //lp.remove(Product(3.2));
    lp.sort();
    //lp.sort(comp);
//    lp.sort(Compare());

    cout << "list排序后:";
    for (list<Product>::iterator itt = lp.begin(); itt != lp.end(); itt++) {
        cout << *itt << " ";
    }
    cout << endl;

    return 0;
}
