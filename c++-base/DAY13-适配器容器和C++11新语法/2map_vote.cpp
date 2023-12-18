/*02-映射实现投票*/
#include <iostream>
#include <map>

using namespace std;

class Cand
{
public:
    Cand(string name = "") : name(name), votes(0) {}

    //投票
    void vote()
    {
        this->votes++;
    }
    int get_votes() const
    {
        return this->votes;
    }

    string get_name() const
    {
        return this->name;
    }

    friend ostream &operator<<(ostream &os, const Cand &c)
    {
        return os << c.name << ":" << c.votes;
    }

private:
    string name;
    int votes;
};

int main()
{
    map<char, Cand> cc;
    typedef map<char, Cand>::iterator IT;
    //-----------------
    cc.insert(pair<char, Cand>('A', Cand("唐僧")));
    cc.insert(make_pair('B', Cand("孙悟空")));
    cc['C'] = Cand("猪八戒");
    cc['D'] = string("沙和尚");
    cc['E'] = Cand("白龙马");
    //-----------------
    //投票
    for (int i = 0; i < 20; i++) //可以投20票
    {
        for (IT it = cc.begin(); it != cc.end(); it++)
        {
            cout << it->first << "-" << it->second << endl;
        }

        char key;
        cout << "请投票:";
        cin >> key;

        IT it = cc.find(key);
        if (it == cc.end())
        {
            cout << "无效票" << endl;
            continue;
        }

        //票数+1
        it->second.vote();
    }
    cout << "---------------------------------------------" << endl;
    //输出选举结果
    IT win = cc.begin(); //默认第一个然后比值
    for (IT it = cc.begin(); it != cc.end(); it++)
    {
        cout << it->first << "-" << it->second << endl;
        //记录票数最多的人
        if (it->second.get_votes() > win->second.get_votes())
            win = it;
    }

    cout << "恭喜" << win->second.get_name() << "当选为本年度西游首席带盐人！" << endl;

    return 0;
}
