#include <stdio.h>

#define MACRO1  0
#define MACRO2  0


int main(int argc, char const *argv[])
{

#ifdef  DE_BUG
    printf("__%s__%s__%d__\n", __FUNCTION__ , __FILE__ , __LINE__ );
#endif

#ifndef  DE_BUG
      printf("__%s__%s__%d__\n", __FUNCTION__ , __FILE__ , __LINE__ );
#endif
  

#if MACRO1
    printf("__%s__%s__%d__\n", __FUNCTION__ , __F25 ILE__ , __LINE__ );
#elif MACRO2
    printf("__%s__%s__%d__\n", __FUNCTION__ , __FILE__ , __LINE__ );
#else
    printf("__%s__%s__%d__\n", __FUNCTION__ , __FILE__ , __LINE__ );
#endif



    return 0;
}
