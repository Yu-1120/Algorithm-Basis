/*03-多重映射的使用*/
#include <iostream>
#include <map>

using namespace std;

int main()
{

    multimap<char,int> ci;
    typedef multimap<char,int>::iterator IT;

    ci.insert(make_pair('B',300));
    ci.insert(make_pair('A',100));
    ci.insert(make_pair('B',200));
    ci.insert(make_pair('C',500));
    ci.insert(pair<char,int>('B',400));

    //遍历
    for(IT it=ci.begin();it!=ci.end();it++){
        cout<<it->first<<":"<<it->second<<endl;
    }

    cout<<"---------------------------------"<<endl;
    //匹配B的上限 --- 第一个大于B
    IT upper = ci.upper_bound('B');
    cout<<upper->first<<":"<<upper->second<<endl;

    cout<<"---------------------------------"<<endl;
    //匹配B的下限 --- 第一个不小于B
    IT lower = ci.lower_bound('B');
    cout<<lower->first<<":"<<lower->second<<endl;

    cout<<"---------------------------------"<<endl;
    //匹配B的上下限
    pair<IT,IT> res = ci.equal_range('B');
    cout<<"下限:"<<res.first->first<<":"<<res.first->second<<endl;
    cout<<"上限:"<<res.second->first<<":"<<res.second->second<<endl;

    return 0;
}
