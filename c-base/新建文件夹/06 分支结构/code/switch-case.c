#include <stdio.h>

struct node
{
    int a ; //4
    char b ; // 1 
    double c ; // 8 
};


int main(int argc, char const *argv[])
{
    int num = 0 ; 

    printf("请你来几拳！！！\n");
    scanf("%d" , &num);
    while(getchar() != '\n'); // 清空标准输入缓冲区

    switch  ( num )
    {
        case 1 :
            printf("它一个左勾拳！！\n") ;
            break ;
            
        case 2 :
            printf("它一个左勾拳和一个右鞭腿！！\n") ;
            break ;
        
        case 3 :
            printf("一个不小心打我脸上了！！！！！\n") ;
            break ;
        
        default :
            printf("它怂了！！ ！！！\n") ; 
    }

    return 0;
}
