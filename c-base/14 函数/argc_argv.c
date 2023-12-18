#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{

    if (argc != 3  )
    {
        printf("小伙子出手太中了！！\n");
        return -1 ;
    }

    int sum = atoi(argv[1]) + atoi(argv[2]);

    printf("sum:%d\n" , sum );
    



    return 0;
}
