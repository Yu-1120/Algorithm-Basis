/*05 - 堆栈计算算数表达式*/
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;

//比较运算符优先级 高-真 不高-假
bool get_prio(char op1,char op2)
{
    return (op1=='*'||op1=='/')&&(op2=='+'||op2=='-');
}

//计算简单表达式
int cal(int a,int b,char op)
{
    switch (op) {
        case '+':
            return a+b;
            // break;
        case '-':
            return a-b;
            // break;
        case '*':
            return a*b;
            // break;
        default:
            return a/b;
    }
}

//传入算数表达式字符串
int calculate(const char *s)
{
    int a1 = 0,a2 = 0;
    char oper;//运算符

    //准备操作数栈和运算符栈
    stack<int> arg;//操作数栈
    stack<char> op;//运算符栈

    //遍历表达式处理
    while(*s){
        //1.遇到左括号
        if(*s=='('){
            op.push(*s);
            s++;
        }
        else if(*s>='0'&&*s<='9'){//2.遇到操作数
            arg.push(atoi(s));
            //
            //移动到下一个运算符 
            while(*s>='0'&&*s<='9')
                s++;//char * 是一个字符的，所以要加加遍历每一个字符
        }
        else if(*s==')'){//3.遇到右括号
            //一直取出两个操作数和一个运算符运算，直到遇到左括号
            do{
                a2 = arg.top();//第二操作数
                //
                arg.pop();
                a1 = arg.top();//第一操作数
                arg.pop();
                oper = op.top();//运算符
                op.pop();
                //结果放入操作数栈
                arg.push(cal(a1,a2,oper));
            }while(op.top()!='(');//没有遇到左括号一直去算
            //取出左括号
            op.pop();
            s++;
        }
        //****************************************
        else if(op.empty()||op.top()=='('||get_prio(*s,op.top())){
            //4.运算符 --- 运算符栈为空，优先级高于栈顶运算符，栈顶为左括号，直接入操作数栈
            op.push(*s);
            s++;
        }
        else{//运算符 - 优先级不高于栈顶运算符，取出两个操作数和一个运算符运算
            a2 = arg.top();//第二操作数
            arg.pop();
            a1 = arg.top();//第一操作数
            arg.pop();
            oper = op.top();//运算符
            op.pop();
            //结果放入操作数栈
            arg.push(cal(a1,a2,oper));
        }
        //****************************************
    }

    //一直取出两个操作数和一个运算符运算，直到运算符栈为空
    while(!op.empty()){
        a2 = arg.top();//第二操作数
        arg.pop();
        a1 = arg.top();//第一操作数
        arg.pop();
        oper = op.top();//运算符
        op.pop();
        //结果放入操作数栈
        arg.push(cal(a1,a2,oper));
    }

    //结果在操作数栈
    return arg.top();
}

int main()
{
    //const char *expr = "(10+2)/3+6*5";
    const char *expr = "(10+8)/(3+6)*5+100/5";

    cout<<calculate(expr)<<endl;

    return 0;
}
