#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE_STACK 100;

typedef struct sqStack
{
    char *top,*base;
    int stackSize;

}sqStack;


void initStack(sqStack *s)
{

    s->base=(char *)malloc(100*sizeof(char));
    if (!s->base) {
        exit(0);
    }
    
    s->top=s->base;
    s->stackSize=MAX_SIZE_STACK;

}

//top指向最后一个元素的后一个位置
void push(sqStack *s,char a)
{
    if (s->top-s->base>=s->stackSize) {
        s->base=(char *)realloc(s->base, s->stackSize+10);
        if (!s->base) {
            exit(0);
        }
        
        s->top=s->base+s->stackSize;
        s->stackSize=s->stackSize+10;
        
    }
    
    
    *(s->top)=a;
    s->top++;

}

void pop(sqStack *s, char *data)
{
    if (s->top==s->base) {
        exit(0);
    }
    s->top--;
    *data=*(s->top);
}

//清空
void clearStack(sqStack *s)
{
    s->top=s->base;
}


//销毁
void destroyStack(sqStack *s)
{

    int i,len;
    len=s->stackSize;
    for (i=0; i<len; i++) {
        free(s->base);
        s->base++;
    }
    s->base=s->top=NULL;
    s->stackSize=0;

}
//长度
int StackLen(sqStack s)
{


    return (s.top-s.base);
}


//2 转10
int binarytoTen()
{
    sqStack s;
    char c;
    int len,i,sum=0;
    initStack(&s);
    printf("输入二进制，输入#结束\n");
    scanf("%c",&c);
    while (c != '#') {
        push(&s, c);
        scanf("%c",&c);
    }
    
    getchar();
    
    len=StackLen(s);
    printf("stack length is : %d\n",len);
    
    for (i=0; i<len; i++) {
        pop(&s, &c);
        sum=sum+(c-48)*pow(2, i);
    }
    printf("10 is :  %d",sum);
    return  sum;
}


//2转8
int  main()
{
    sqStack *s;
    char c;
    int len,sum=0;
    initStack(s);
    printf("输入二进制：\n");
    scanf("%c",&c);
    while (c!='#') {

        push(s, c);
        scanf("%c",&c);
    }
    getchar();
    
    len=StackLen(*s);
    
    sqStack *l;
    initStack(l);
    
    for (int i=0; i<len/3; i++) {
        
        for (int j=0; j<3; j++) {
            pop(s, &c);
            sum=sum+(c-'0')*pow(2,j);
          
        }
          push(l, sum+'0');  //数字转换成char
        sum=0;
    }

    int lens=StackLen(*l);
      char a;
    for (int i=0; i<lens; i++) {
      
        pop(l, &a);
        printf("===%c \n",a);
    }

    
    return 0;
}

//2-16
int nomain()
{
    
    sqStack *s;
    char c;
    int len,sum=0;
    initStack(s);
    printf("输入二进制：\n");
    scanf("%c",&c);
    while (c!='#') {
        
        push(s, c);
        scanf("%c",&c);
    }
    getchar();
    
    len=StackLen(*s);
    
    sqStack *l;
    initStack(l);
    char e;
    for (int i=0; i<len/3; i++) {
        
        for (int j=0; j<4; j++) {
            pop(s, &c);
            sum=sum+(c-'0')*pow(2,j);
            if (sum>=10) {
                e=(sum-10)+'A';
            }
            else{  e=sum+48;}
            
        }
        push(l, e);
        sum=0;
    }
    
    int lens=StackLen(*l);
    char a;
    for (int i=0; i<lens; i++) {
        
        pop(l, &a);
        printf("= %c \n",a);
    }
    

    return 0;
}

