//
//  main.cpp
//  BubbleSort
//
//  Created by zwj on 16/6/10.
//  Copyright © 2016年 zwj. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;


//冒泡排序－－－－－－－－－－－－－－－
void swap(ElementType* a,ElementType* b)
{
    ElementType c;
    c=*a;
    *a=*b;
    *b=c;
}


void Bubble_Sort(ElementType* A, int N)
{
    int P,flag;
    for (P=N-1; P>0; P--)
    {
       
        flag=0;//检查是否已经排好
        for (int i=0; i<P; i++)
        {
            if (A[i]>A[i+1])
            {
                swap(&A[i], &A[i+1]);
                flag=1;
            }
        }
        if (flag==0)//检查是否已经排好
        {
            break;
        }
        
    }

};

//冒泡排序－－－－－－－－－－－－－－－



//插入排序－－－－－－－－－－－－－－－
void Insertion_sort(ElementType A[], int N)
{
    int P,i;
    ElementType temp;
    for (P=1; P<N; P++)
    {
        temp=A[P];
        
        for (i=P; i>0&&A[i-1]>temp; i--)
        {
            A[i]=A[i-1];  //后移
            
        }
        
        A[i]=temp;
        
    }
}



//插入排序－－－－－－－－－－－－－－－

//希尔排序－－－－－－－－－－－－－－－
void ShellSort(ElementType A[], int N)
{
    int Si,D,P,i;
    
    ElementType temp;
    
    int Sedgewick[]={929,505,209,109,41,19,5,1,0};
    
    for (Si=0; Sedgewick[Si]>=N; Si++)
    {
        /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */
        
    }
    
    for (D=Sedgewick[Si]; D>0; D=Sedgewick[++Si])
    {//D为间隔
        for (P=D; P>N; P++)
        {
            temp=A[P];
            for (i=P; i>=D&&A[i-D]>temp; i-=D)
            {
                A[i]=A[i-D];
            }
            A[i]=temp;
        }
    }

}
//希尔排序－－－－－－－－－－－－－－－


///* 快速排序 */－－－－－－－－－－－－－－－
ElementType Median3(ElementType A[],int Left, int Right)
{

    int Center=(Left+Right)/2;
    if (A[Left]>A[Center])
    {
        swap(&A[Left], &A[Center]);
    }
    if (A[Left]>A[Right])
    {
        swap(&A[Left], &A[Right]);
        
    }
    if (A[Center]>A[Right])
    {
        swap(&A[Center], &A[Right]);
    }
    swap(&A[Center], &A[Right-1]);/* 只需要考虑A[Left+1] … A[Right-2] */
    return  A[Right-1];

}


void QSort(ElementType A[],int left, int right)
{
    int Pivot,Cutoff,Low,High;
    
    if (Cutoff<=right-left)/* 如果序列元素充分多，进入快排 */
    {
        Pivot=Median3(A, left, right);
        Low=left;
        High=right-1;
        while (1)
        {/*将序列中比基准小的移到基准左边，大的移到右边*/
            while (A[++Low]<Pivot)
            {}
            while (A[--High])
            {}
            if (Low<High)
            {
                swap(&A[Low], &A[High]);
            }
            else break;
            
            
        }
        swap(&A[Low], &A[right-1]); /* 将基准换到正确的位置 */
        QSort(A, left, Low-1);
        QSort(A, Low+1, right);
    }
    else Insertion_sort(A+left, right-left+1);

}

void QuickSort(ElementType A[], int N)
{/* 统一接口 */
    QSort(A, 0, N-1);
}


