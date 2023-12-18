#include <stdio.h>

int main(void)
{
    // 输入一个字母
	char ch;
	scanf("%c", &ch);
		
	if((ch<'A') || (ch>'Z'))
	{
		printf("只接受大写字母\n");
        exit(0); // 在任何地方都会直接结束进程
	}

    // 总行数
	int line = ch - 'A' + 1;

	int i, j;
	for(i=1; i<=line; i++)
	{
        // 输出若干个空格
		for(j=0; j<line-i; j++)
		{
			printf(" ");
		}

        // 输出若干个升序字母
		for(j=0; j<i; j++)
		{
			printf("%c", 'A'+j);
		}

        // 输出若干个降序字母
		for(j-=2; j>=0; j--)
		{
			printf("%c", 'A'+j);
		}
		printf("\n");
	}
	return 0;
}