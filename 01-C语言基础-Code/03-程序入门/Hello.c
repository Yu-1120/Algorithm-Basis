#include <stdio.h>
#include <unistd.h>




int main(int argc, char const *argv[])
{
    printf("%s--%s--%d\n" , __FILE__ , __FUNCTION__ , __LINE__ );

        printf("Hello Even\n"); // 在屏幕上打印一句话 "Hello Even"
        // 把 "Hello Even" 字符串 输出到 标准输出文件中（需要缓冲）
        sleep(1);
        printf("%s--%s--%d\n" , __FILE__ , __FUNCTION__ , __LINE__ );


    
    return 0;
}
