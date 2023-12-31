#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5 ;
    int b = 3 ;
    int c = a ^ b ; 

    printf("c:%d\n" , c );  // 6 
    printf("c^a:%d\n" , c^a );  // 3 --> b 
    printf("c^b:%d\n" , c^b );  // 5 --> a 

    int k = -3 ;
    // 1000   0000    0000   0000    0000   0000    0000   0011 
    // 1111   1111    1111   1111    1111   1111    1111   1100  取反
    // 1111   1111    1111   1111    1111   1111    1111   1101  加一

    int l = k << 4 ;//运算的时候是用补码来进行运算的
    // 1111   1111    1111   1111    1111   1111    1101  0000  加一
    printf("l: %d\n" , l );
    // 1000   0000    0000   0000    0000   0000    0011  0000 -48
    // 1111   1111    1111   1111    1111   1111    1100  1111  取反
    // 1111   1111    1111   1111    1111   1111    1101  0000  加一



    return 0;
}
