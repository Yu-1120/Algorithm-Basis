/*03-ัฦิช*/
#include <iostream>

using namespace std;

void print()
{
    cout<<"print()"<<endl;
}

void print(int/*ัฦิช*/)
{
    cout<<"print(int)"<<endl;
}

int main()
{
    print();
    print(1);

    return 0;
}
