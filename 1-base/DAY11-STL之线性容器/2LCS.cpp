/*02-求最长公共子串*/
#include <iostream>

using namespace std;

//暴力求解
string getLCS(const string &str1,const string &str2)
{
    //记录最长子串在str1中的起始位置和长度
    size_t max_start = 0,max_len = 0;

    for(size_t i=0;i<str1.length();i++){
        for(size_t j=0;j<str2.length();j++){
            //计算当前最长公共子串
            size_t k,l;
            for(k=i,l=j;k<str1.length()&&l<str2.length();k++,l++){
                if(str1.at(k)!=str2.at(l))
                    break;
            }
            //记录最长长度的公共子串
            if(k-i>max_len){
                max_len = k-i;
                max_start = i;
            }

        }
    }

    return str1.substr(max_start,max_len);
}

//矩阵法求解
string getLCS1(const string &str1,const string &str2)
{
    //记录最长子串在str1中的结束位置和长度
    int max_end = 0,max_len = 0;

    //创建比较矩阵
    int **arr = new int *[str1.length()];
    for(size_t i=0;i<str1.length();i++){
        arr[i] = new int[str2.length()];
        for(size_t j=0;j<str2.length();j++){
            //比较字符，将比较结果写入矩阵
            if(str1.at(i)==str2.at(j)){//赋值  左上角+1
                //如果左上角不存在
                if(i==0||j==0)
                    arr[i][j] = 1;
                else
                    arr[i][j] = arr[i-1][j-1]+1;

                //记录最长长度和此时str1中最后一个字符的位置
                if(arr[i][j]>max_len){
                    max_len = arr[i][j];
                    max_end = i;
                }
            }
            else{
                arr[i][j] = 0;
            }
        }
    }

    //释放空间
    for(size_t i=0;i<str1.length();i++){
        delete[] arr[i];
    }
    delete[] arr;

    //返回最长公共子串
    return str1.substr(max_end-max_len+1,max_len);
}

int main()
{
    string str1 = "kkkhelaalowebyebye";
    string str2 = "kkkhelaalowebyebye111";

    cout<<getLCS(str1,str2)<<endl;
    cout<<getLCS1(str1,str2)<<endl;

    return 0;
}


