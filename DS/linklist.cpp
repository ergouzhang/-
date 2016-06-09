//
//  main.cpp
//  practice
//
//  Created by zwj on 16/5/17.
//  Copyright © 2016年 zwj. All rights reserved.
//

#include <iostream>
#include <stdio.h>


//定义
typedef struct student
{
    int data;
    struct student *next;

}node;


//创建无头链表
node * createList()
{

    node * head, *s,*p;
    
    head=(node*)malloc(sizeof(node));
    head->data=0;
    p=head;
  
    while (1) {
        int a;
        printf("输入数据： /n");
        scanf("%d",&a);
        if (a!=0) {
            s=(node*)malloc(sizeof(node));
            s->data=a;
            p->next=s;
            p=s;
            
        }
        else
        {
        
            break;
        
        }
     
    
        
    }
    p->next=NULL;
    head=head->next;
    return head;

};


//获取长度
int length(node *head)
{
    node *p;
    p=head;
    int i=0;
    while (p !=NULL)
    {
        p=p->next;
        ++i;
    }



    return i;
}


//遍历输出
void print(node *head)
{
    node *p=head;
    
    int n =length(head);
    
   
    while (p != NULL) {
        printf("%d",p->data);
        p=p->next;
    }



};


//删除第num个节点
//遍历 num-2 次得到前趋节点
//头节点需要单独操作
void deletelist(node *head,int num)
{

    node *p ,*s;
    p=head;
    int i=num-1;
    if (num==0) {
        head=head->next;
        free(p);
    }
    else
    {
    
        while (--i) {
            p=p->next;
        }
        p->next=p->next->next;
        free(p->next);
    
    }


};

//删除数据为num的节点
//遍历得到删除接点的前驱接点
//头节点需要单独操作
node *del(node *head,int num)
{

    node *p,*s;
    p=head;
    while (p->data !=num && p->next!=NULL) {
        s=p;
        p=p->next;
        
    }
    if (p->data==num) {
        if (p != head) {
             s->next=p->next;
            free(p);
        }
        else
        {
            head=head->next;
            free(p);
        }
       
        
    }


    return  head;
};

//插入数据为num，且顺序排列数据
//头节点需要单独操作
node *insertlist(node *head ,int num)
{

    node *p0,*p1,*p2;
    p0=(node*)malloc(sizeof(node));
    p0->data=num;
    p1=head;
    p2=head;
    if (p0->data>p1->data &&p1->next!=NULL) {
        p2=p1;
        p1=p1->next;
    }
    if (p0->data<=p1->data) {
        if (p1==head) {
            p0->next=head->next;
            head=p0;
        }
        if (p1 !=head) {
            p2->next=p0;
            p0->next=p1->next;
            
        }
        
        
    }
    else{
    
        p1->next=p0;
        p0->next=NULL;
    
    
    }
    
    return  head;
};



//排序:
//共有n-1次大循环。
//第j次大循环遍历前n－j个元素，将最大值置于最后。
node *sort(node *head)
{

    int n=10;
    node *p,*s,*t;
   
    int temp;
    
    for (int j=1;j<n;j++) {
         p=head;
        for (int i=0; i<n-j; i++) {
            
            
        if (p->data>=p->next->data) {
            temp=p->next->data;
            p->next->data=p->data;
            p->data=temp;
            
        }
                }
    
    
        p=p->next;
    }

    return head;
}