#include <iostream>
#include "search.h"

using namespace std;

int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    const char *ca[] = {"Japan","UK","byebye","template","welcome"};
    const char buf[] = "UK";

    Searcher<int> sc;
    cout<<sc(a,0,9,11)<<endl;
    Searcher<const char *> ss;
    cout<<ss(ca,0,6,buf)<<endl;

    return 0;
}
