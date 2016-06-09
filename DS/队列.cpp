//
//  main.cpp
//  duilie
//
//  Created by zwj on 16/5/24.
//  Copyright © 2016年 zwj. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
typedef int ElementType;



//顺序队列的定义
//front 指向当前第一个元素的前一个元素
//rear指向最后一个元素
//从rear进，front出。
typedef struct sequence
{
    ElementType data[MAXSIZE];
    int front,rear;

}sequence;

sequence *sq;

//入队
void insert(sequence *s, ElementType e)
{

    s->rear++;
    s->data[s->rear]=e;

}

//出队
void out(sequence *s,ElementType *e)
{


    s->front++;
    *e=s->data[s->front];
}

int length(sequence s)
{
    return  s.rear-s.front;
}


//————————————————————————————————————
//链队列:带有无效头链节点
//链
typedef struct linkList
{
    ElementType data;
    struct linkList *next;
    

}linkList;

//队列
typedef struct linkSequence
{
    linkList* front, *rear;
    
}linkSequence;

linkSequence *q;


//初始化
void init(linkSequence *s)
{

    s->front=(linkList*)malloc(sizeof(linkList));
    if (!s->front) {
        exit(0);
    }
    s->front->next=NULL;
    s->rear=s->front;
    
}


//入队
void inser2(linkSequence *s, ElementType e)
{

    
    linkList *q=(linkList *)malloc(sizeof(linkList));
    
    q->data=e;
    q->next=NULL;
    s->rear->next=q;
    s->rear=q;

}

void out2(linkSequence *s,ElementType *e)
{
    linkList *p=s->front->next;
    if (s->front == s->rear)
    {
        return;
    }
        
    *e=p->data;
    s->front->next=p->next;
    if (s->rear==p) {
        s->rear=s->front;
    }
    free(p);


}












