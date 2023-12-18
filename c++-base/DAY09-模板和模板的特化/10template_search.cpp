/*10 - 使用模板实现查找*/
#include <iostream>
#include <cstring>

using namespace std;

//函数模板
template<typename T>
int mysearch(T *arr, int n, T dt) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == dt)
            return i;
    }

    return -1;
}

int main() {

    return 0;
}

