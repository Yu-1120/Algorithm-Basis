/*08 - 映射的使用*/
#include <iostream>
#include <map>


using namespace std;

int main()
{
    map<char,string> cs;

    //给迭代器类型起别名
    typedef map<char,string>::iterator IT;

    //插入
    cs.insert(pair<char,string>('A',"李逵"));
    cs.insert(pair<char,string>('C',"武松"));
    cs.insert(pair<char,string>('F',"宋江"));
    cs.insert(pair<char,string>('D',"西门庆"));
    cs.insert(pair<char,string>('B',"潘金莲"));

    //通过key下标访问value
    cs['A'] = "晁盖";
    cs['E'] = "时迁";

    //判断插入是否成功
    pair<IT,bool> res = cs.insert(make_pair('X',"林冲"));
    if(res.second){
        cout<<"插入成功！"<<endl;
    }
    else{
        cout<<"插入失败！"<<endl;
    }

    //遍历
    for(IT it=cs.begin();it!=cs.end();it++){  //不允许重复的key
        cout<<it->first<<":"<<it->second<<endl;
    }

    //查找 ------ 通过key查找value
    char key;
    cout<<"请输入要查找的key:";
    cin>>key;
    IT itt = cs.find(key);
    if(itt==cs.end()){
        cout<<"没有该数据"<<endl;
    }
    else{
        cout<<"value="<<itt->second<<endl;
    }

    return 0;
}
