#include <stdio.h>

int main(void)
{
	int (*p)[5] = NULL; 
	int arr[5] = {1,2,4,5,7};
	p = &arr;

	printf("arr    = %p\n",arr );  		
	printf("&arr   = %p\n",&arr );    
	printf("p      = %p\n",p);        
	printf("*p     = %p\n",*p );      
	printf("p+1    = %p\n",p+1 );    
	printf("(*p)+1 = %p\n",(*p)+1);  
	printf("(**p = %p\n",**p);  


	int a = 0x123456 ;
	printf("%p\n%p\n",a,&a );
	
	return 0;
}