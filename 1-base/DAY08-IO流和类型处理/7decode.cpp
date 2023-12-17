/*07-异或加解密*/
#include <iostream>
#include <fstream>

using namespace std;

//将原始文件的每一个字符读出来异或给定的key之后写入目标文件
void _xor(const char *srcpath, const char *destpath, unsigned char key) {
    char buf[100] = {};
    int res = 0;

    //读打开原文件
    ifstream ifs(srcpath, ios::in | ios::binary);
    if (!ifs.is_open()) {
        cout << "打开原文件失败!" << endl;
        exit(0);
    }

    //写打开目标文件
    ofstream ofs(destpath, ios::out | ios::trunc | ios::binary);
    if (!ofs.is_open()) {
        cout << "打开目标文件失败!" << endl;
        ifs.close();
        exit(0);
    }

    //读---加密---写
    while (1) {
        //读
        ifs.read(buf, sizeof(buf));
        res = ifs.gcount();
        cout << res << endl;
        if (res == 0)//读完了
            break;

        //加密
        for (int i = 0; i < res; i++)
            buf[i] ^= key;

        //加密
        ofs.write(buf, res);
    }

    ifs.close();
    ofs.close();
}


int main() {
    unsigned char key = 0;

    cout << "请输入加密的key:";
    cin >> key;

    _xor("./a.txt", "./b.txt", key);

    cout << "请输入解密的key:";
    cin >> key;

//    _xor("./b.txt","./c.txt",key);

    return 0;
}

