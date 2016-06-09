//
//  tree2.cpp
//  tree
//
//  Created by zwj on 16/5/30.
//  Copyright © 2016年 zwj. All rights reserved.
//
//浙大数据结构教程


#include <iostream>
#include <stdlib.h>


#define MaxSize 100


//二叉树的定义
typedef char  ElementType;

typedef struct BinTree
{
    ElementType data;
    struct BinTree *lchild,*rchild;
    

}BinTree;

//栈==========================
typedef struct Stack
{
    BinTree* data[MaxSize];
    int top;
    
}Stack;

void initStack(Stack *s)
{

    s->top=-1;

}

void push(Stack *s,BinTree *T)
{
    s->top++;
    s->data[s->top]=T;

}


BinTree *pop(Stack *s)
{


    return s->data[s->top--];
}

//栈==========================





//二叉树树的非递归中序遍历 ： 中序是第二次遇到时访问
void InOrderTraversal(BinTree *BT)
{
    
    BinTree *T=BT;
    Stack *s;
    initStack(s);
    while (T|| s->top>=0)  //结束条件为 T和S都为空
    {
        
        while (T)
        {
            push(s,T);
            // printf("%c\n",T->data); 即为前序遍历，第一次遇到即访问
            T=T->lchild;
        }
        if (s->top>=0)
        {
            T=pop(s);
            printf("%c\n",T->data);
            T=T->rchild;
        }
        
        
    }
  
}
//-----------------------------------------------------------------
//二叉树树的层序遍历


//队列==========================
typedef struct Queue
{
    BinTree* data[MaxSize];
    int front,rear;
}Queue;

void initQueue(Queue *Q)
{
    Q->rear=Q->front=-1;  //front指向1号元素的前一个，rear指向最后一个好元素

}

void AddQ(Queue*Q,BinTree *BT)
{

    Q->rear++;
    Q->data[Q->rear]=BT;
    
}

BinTree* DeleteQ(Queue *Q)
{
    Q->front++;
    return Q->data[Q->front];
}

bool IsEmptyQ(Queue *Q)
{
    if (Q->front==Q->rear) {
        return true;
    }

    return false;
}
//队列==========================

//二叉树的非递归层序遍历
void LevelOrderTraversal(BinTree *BT)
{

    Queue *Q;
    BinTree *T;
    if (!BT)
    {
        return;
    }
    initQueue(Q);
    AddQ(Q, BT);
    while (!IsEmptyQ(Q))  //队列为空结束
    {
        T=DeleteQ(Q);
        printf("%c\n",T->data);
        if (T->lchild)
        {
            AddQ(Q, T->lchild);
        }
        if (T->rchild) {
            AddQ(Q, T->rchild);
        }
        
    }
}

//二叉排序树------------------------------------------
//二叉排序树的查找
BinTree *IterFinde( BinTree* BST, ElementType X)
{
    BinTree* p=BST;
    
   while (p)
    if (p->data==X)
    {
        return p;
    }
    
    if (p->data<X)
    {
        p=p->rchild;
    }
    if (p->data>X)
    {
        p=p->lchild;
    }
    return  nullptr;
    
}

//二叉排序树的最大值
BinTree* FindMax(BinTree* BST)
{
    BinTree *p=BST;
    
    if (p)
    {
        
    
    while (p->rchild)
    {
        p=p->rchild;
        
    }

    return p;
}
    return  nullptr;
}
//堆－－－－－－－－－－－－－－－－－－－－－－－
//堆：（1）完全二叉树（2）根节点大于（小于）左右子树
typedef  struct Heap
{

    ElementType* data;
    int size;
    int capacity;

} Heap;

//最大堆
void createHeap(int MaxSizeHeap)
{

    Heap*H =(Heap*)malloc(sizeof(Heap));
    H->data=(ElementType*)malloc((MaxSizeHeap+1)*sizeof(ElementType));
    H->size=0;
    H->capacity=MaxSizeHeap;
    H->data[0]=MAXDATA;//哨兵
}

//最大堆的插入
void insertHeap(Heap *H,ElementType item)
{
    int i;
    i=++H->size;
    for (; H->data[i/2]<item; i/=2)  //若插入的元素比根大，则因为有data[0]的存在，循环会停止
    {
        H->data[i]=H->data[i/2];
    }
    H->data[i]=item;
    
}
//最大堆的删除
ElementType deleteMax(Heap *H)
{
    int Parent,Child;
    ElementType Maxitem,temp;
    
    Maxitem=H->data[1];
    temp=H->data[H->size--];
    for (Parent=1; Parent*2<=H->size; Parent=Child)
    {
        
        Child=Parent*2;
        if ((Child!=H->size)&&H->data[Child]<H->data[Child+1])
        {
            Child++;
        }
        if (temp>=H->data[Child])
        {
            break;
        }
        else
        {
        
            H->data[Parent]=H->data[Child];
        
        }
        
        H->data[Parent]=temp;
        
        
        
        
        
    }





}
