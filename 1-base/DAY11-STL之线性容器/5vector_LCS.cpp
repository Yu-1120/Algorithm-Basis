/*04-使用vector实现子最长公共子串*/
#include <iostream>
#include <vector>

using namespace std;

string getLCS(const string &str1,const string &str2)
{
    //记录最长子串在str1中的结束位置和长度
    int max_end = 0,max_len = 0;

    //创建比较矩阵(二维向量)
    vector<vector<int>> arr(str1.length(),vector<int>(str2.length()));
    for(size_t i=0;i<str1.length();i++){
        for(size_t j=0;j<str2.length();j++){
            //比较字符，将比较结果写入矩阵
            if(str1.at(i)==str2.at(j)){//赋值  左上角+1
                //如果左上角不存在
                if(i==0||j==0)
                    arr.at(i).at(j) = 1;
                else
                    arr.at(i).at(j) = arr.at(i-1).at(j-1)+1;

                //记录最长长度和此时str1中最后一个字符的位置
                if(arr.at(i).at(j)>max_len){
                    max_len = arr.at(i).at(j);
                    max_end = i;
                }
            }
            else{
                arr.at(i).at(j) = 0;
            }
        }
    }

    //返回最长公共子串
    return str1.substr(max_end-max_len+1,max_len);
}

int main()
{
    string str1 = "kkkhellowebyebye";
    string str2 = "ghsasabyehellod";

    cout<<getLCS(str1,str2)<<endl;

    return 0;
}

