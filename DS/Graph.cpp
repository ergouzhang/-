//
//  main.cpp
//  graph
//
//  Created by zwj on 16/6/2.
//  Copyright © 2016年 zwj. All rights reserved.
//

// －－－－－－－－图－－－－－－－－－－－－－－－－－－－－
//---------------------
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>





//－－－－－－－－－－－－－－－－－－图的临接矩阵表示－－－－－－－－－－－－－－－－－－
#define  MaxVertexNum 100
#define  INFINITY 65535
typedef int Vertex;         //顶点序号表示顶点
typedef int  WeightType;   //权值
typedef char  DataType;


//边的定义
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1,V2;  //有向边<v1 ,v2>;
    WeightType Weight;
};
typedef  PtrToENode Edge;

// 邻接矩阵的定义
typedef struct GNode *ptrToGNode;

struct GNode
{
    int Nv;//顶点数
    int Ne;//边数
    WeightType G[MaxVertexNum][MaxVertexNum]; //邻接矩阵
   
 };
typedef  ptrToGNode MGraph;



//创建一个G: 有vertexnum个顶点但是没有边的图
MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    
    for (V=0; V<Graph->Nv; V++)
    {
        for (W=0; W<Graph->Nv; W++)
        {
            Graph->G[V][W]=INFINITY;
        }
        
        
        
    }

return Graph;
}


//边的插入
void InsertEdge(MGraph graph, Edge e)
{
    graph->G[e->V1][e->V2]=e->Weight;
    //若是无向图:
    //graph->G[e->V2][e->V1]=e->Weight;
}

//通过输入建立图
MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    
    scanf("%d",&Nv);//读入顶点个数
    Graph=CreateGraph(Nv);
    
    scanf("%d",&(Graph->Ne));//读入边的数量
    if (Graph->Ne!=0)
    {
        E=(Edge)malloc(sizeof(ENode));
        
        for (i=0; i<Graph->Ne; i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph, E); //插入边
        }
    }
    return Graph;

}

//－－－－－－－－－－－－－－－－－－图的临接点表示－－－－－－－－－－－－－－－－－－

//边的定义
typedef struct ENode2* ptrToENode2;
struct ENode2
{
    Vertex V1,V2;
    WeightType weigh;
};

typedef ptrToENode2 Edge2;

//邻接点的定义
typedef  struct AdjVNode * ptrToAdjVNode;
struct AdjVNode
{
    Vertex adjV;  //邻接点的下标
    WeightType weight; //边的权重
    ptrToAdjVNode* Next; //指向下一个邻接点
};

//顶点表头结点的定义
typedef struct VNOde
{
    ptrToAdjVNode FirstEdge;
    
}AdjList[MaxVertexNum];

//图的定义
typedef struct GNode2 *ptrToGNode2;
struct GNode2
{
    int Nv;
    int Ne;
    AdjList G;

};
typedef ptrToGNode2 LGraph;


//初始化
LGraph createLGraph2(int vertexNum)
{
    Vertex V;
    LGraph Graph;
    Graph=(LGraph)malloc(sizeof(GNode2));
    Graph->Nv=vertexNum;
    Graph->Ne=0;
    
    for (V=0; V<Graph->Nv; V++)
    {
        Graph->G[V].FirstEdge=NULL;
    }

    return Graph;
}

//插入边
void insertEdge2(LGraph graph, Edge2 E)
{
    ptrToAdjVNode NewNode;
    
    NewNode=(ptrToAdjVNode)malloc(sizeof(AdjVNode));
    NewNode->adjV=E->V2;
    NewNode->weight=E->weigh;
    NewNode->Next=&graph->G[E->V2].FirstEdge; //V2的next指向V2节点的first
    graph->G[E->V1].FirstEdge=NewNode;

}

//建立
LGraph buildGraphList()
{
    LGraph graph;
    Edge2 E;
    Vertex V;
    int Nv,i;
    
    scanf("%d",&Nv);
    graph=createLGraph2(Nv);
    
    scanf("%d",&graph->Ne);
    if (graph->Ne!=0)
    {
        E=(Edge2)malloc(sizeof(ENode2));
        
        for (i=0; i<graph->Ne; i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->weigh);
            insertEdge2(graph, E);
        }
    }

    return graph;

}

//－－－－－－－－－－－－－－－－－－图的遍历－－－－－－－－－－－－－－－－－－
//邻接表的DFS－－－－－－－－－－－－－－－－－－

void Visit(Vertex V)
{
    printf("访问了V");
}
void DFS(LGraph Graph, Vertex V)
{
    bool visited[Graph->Nv];
    ptrToAdjVNode W; //W为邻接点
    Visit(V);
    visited[V]=true;
    
    for (W=Graph->G->FirstEdge; W; W->Next)
    {
        if (!visited[W->adjV])
        {
            DFS(Graph, W->adjV);
        }
    }
}


//邻接矩阵的BFS－－－－－－－－－－－－－－－－－－
//有权图
bool IsEgde(MGraph Graph,Vertex V,Vertex W)
{

    return Graph->G[V][W]<INFINITY?true:false;  //假设最大权重为infinity

}



void BFS(MGraph Graph,Vertex S)
{
    bool visited[Graph->Nv];
    Queue Q;
    Vertex V,W;
    Q=createQueue(Maxsie);
    
    Visit(S);
    visited[s]=true;
    Add(Q,S);
    
    while (!IsEmpty(Q))
    {
        V=DeleteQ(S);
        for (W=0; W<Graph->Nv; W++)
        {
            if (!visited[W]&&IsEgde(Graph, V, W))
            {
                Visit(W);
                visited[W]=true;
                AddQ(Q,W);
            }
        }
    }


}