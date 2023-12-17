#include <iostream>
#include "employer.hpp"

using namespace std;

int main()
{
    Employer ep("五虎上将","张飞","蜀国",300000.0);
    ep.show();

    Employer ep1 = ep;

    return 0;
}
