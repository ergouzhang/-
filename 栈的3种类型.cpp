//
//  c++.cpp
//  c++
//
//  Created by zwj on 16/5/20.
//  Copyright © 2016年 zwj. All rights reserved.


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//双指针表示，top指向最高元素的后一位
#define STACKSIZE 100
typedef int EmelentType;
typedef struct stackList
{
    EmelentType *top, *base;
    int stackSize[STACKSIZE];
    }stackList;


void init(stackList *s)
{

    s->base=(EmelentType*)malloc(STACKSIZE*sizeof(EmelentType));
    if (!s->base) {
        return;
    }

    s->top=s->base;
    s->stackSize=STACKSIZE;
}


void push(stackList*s, EmelentType e)
{
 
    if (s->top-s->base>=STACKSIZE) {
        
        s->base=(EmelentType*)realloc(s->base, s->stackSize+20);
        s->top=s->base+s->stackSize;
        s->stackSize=s->stackSize+20;
    }
    
    *(s->top)=e;
    s->top++;
    
}

void pop(stackList *s,EmelentType *e)
{
    if (s->top<=s->base) {
        return;
    }
    
    s->top--;
    e=*(s->top);
}

//---------------------------
//top指向最高元素 ,非指针表示
typedef struct stackNode
{
    EmelentType data[STACKSIZE];
    int stackTop;
}stackNode;

void init2(stackNode *s)
{

    s->stackTop=-1;

}

void push2(stackNode *s,EmelentType e)
{

    if (s->stackTop>STACKSIZE-1) {
        return;
    }

    s->data[++s->stackTop]=e;


}
void pop2(stackNode *s,EmelentType *e)
{

    if (s->stackTop<=-1) {
        return;
    }
    *e=s->data[s->top--];
  
}

//－－－－－－－－－－－－－－－－
//链栈

typedef struct listNode
{
    EmelentType data;
    struct listNode* next;
} listNode;


typedef struct listStack
{
   struct listNode *top;
    int size;
}
listStack;


void push3(listStack *s, EmelentType e)
{


    listNode *p=(listNode *)malloc(sizeof(listNode));
    p->data=e;
    p->next=s->top;
    s->top=p;
    
}

void pop3(listStack *s,EmelentType *e)
{
    if (s->top==nullptr) {
        return;
    }
    listNode *p=s->top;
    *e=s->top->data;
    s->top=s->top->next;
    free(p);


}

