#include <cstring>

template <typename T>
Comparetor<T>::Comparetor(T mx,T my):x(mx),y(my)
{

}

template <typename T>
T Comparetor<T>::max()const
{
    return x>y?x:y;
}

template <typename T>
T Comparetor<T>::min()const
{
    return x<y?x:y;
}

//成员特化
template<>
const char *Comparetor<const char *>::max()const
{
    return strcmp(x,y)>0?x:y;
}

template<>
const char *Comparetor<const char *>::min()const
{
    return strcmp(x,y)<0?x:y;
}
