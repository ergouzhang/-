//
//  prim.cpp
//  graph
//
//  Created by zwj on 16/6/8.
//  Copyright © 2016年 zwj. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "Graph.cpp"

/* 邻接矩阵存储 - Prim最小生成树算法 */
Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
/* 返回未被收录顶点中dist最小者 */
    
    Vertex MinV,V;
    WeightType MinDist=INFINITY;
    
    for (V=0; V<Graph->Nv; V++)
    {
        if (dist[V]!=0 && dist[V]<MinDist)
        {
            MinDist=dist[V];
            MinV=V;
        }
    }

    if (MinDist<INFINITY)
    {
        return  MinV;
    }
    return ERROR;

}

int Prim(MGraph Graph,LGraph MST)
{
/* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
    
    WeightType dist[Graph->Nv];
    WeightType TotalWeight;
    Vertex parent[Graph->Nv],V,W;
    int VCount;
    Edge E;
    
    //dist指节点到树的边的权重
    /* 初始化。默认初始点下标是0 */
    for (V=0; V<Graph->Nv; V++)
    {
        dist[V]=Graph->G[0][V];
        parent[V]=0;
    }

    TotalWeight=0;
    VCount=0;
    
    MST=createLGraph2(Graph->Nv);
    E=(Edge)malloc(sizeof(ENode2));
    
    
    //收录第一个节点
    dist[0]=0;
    VCount++;
    parent[0]=-1;
    
    while (1)
    { /* V = 未被收录顶点中dist最小者 */
        V=FindMinDist(Graph, dist);
        if (V==ERROR)
        {
            break;
        }
         /* 将V及相应的边<parent[V], V>收录进MST */
        E->V1=parent[V];
        E->V2=V;
        E->Weight=dist[V];
        insertEdge2(MST, E);
        TotalWeight+=dist[V];
        dist[V]=0;
        VCount++;
        for (W=0; W<Graph->Nv; W++)/* 对图中的每个顶点W */
        {
            /* 若W是V的邻接点并且未被收录 */
            if (dist[W]!=0 && Graph->G[V][W]<INFINITY)
            {
                
                /* 若收录V使得dist[W]变小 */
                if (Graph[V][W]<dist[W])
                {
                    dist[W]=Graph->G[V][W];/* 更新dist[W] */
                    parent[W]=V; /* 更新树 */
                }
            }
        }
        
    }
    if (VCount<Graph->Nv)
    {
        TotalWeight=ERROR;/* MST中收的顶点不到|V|个 ，图不联通*/
    }
    return TotalWeight;
}
