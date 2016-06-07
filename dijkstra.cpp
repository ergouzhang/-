//
//  shortestPath.cpp
//  graph
//
//  Created by zwj on 16/6/7.
//  Copyright © 2016年 zwj. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "Graph.cpp"


/* 邻接矩阵存储 - 有权图的单源最短路算法 */
Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{//返回未被收录顶点中dist最小者
    Vertex MinV,V;
    int MinDist=INFINITY;
    for (V=0; V<Graph->Nv; V++)
    {
        if (collected[V]==false&&dist[V]<MinDist)
        {
            MinDist=dist[V];
            MinV=V;
        }
     }
    if (MinDist<INFINITY)
    {
        return MinV;
        
    }
    else return NULL;

};


bool Dijkstra(MGraph Graph, int dist[], int path[],Vertex S)
{
    int collected[Graph->Nv];
    Vertex V,W;
    
    /* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */

    for (V=0; V<Graph->Nv; V++)
    {
        dist[V]=Graph->G[S][V];
        path[V]=-1;
        collected[V]=false;
    }
  /* 先将起点收入集合 */
    dist[S]=0;
    collected[S]=true;
    
    while (1)
    {/* V = 未被收录顶点中dist最小者 */
        V=FindMinDist(Graph, dist, collected);
        collected[V]=true;
        for (W=0; W<Graph->Nv; W++)/* 对图中的每个顶点W */
        /* 若W是V的邻接点并且未被收录 */
        {
             /* 若收录V使得dist[W]变小 */
            if (collected[W]==false&&Graph->G[V][W]<INFINITY)
            {
                if (dist[V]+Graph->G[V][W]<dist[W])
                {
                    dist[W]=dist[V]+Graph->G[V][W];* 更新dist[W] */
                    path[W]=V;/* 更新S到W的路径 */
                }
            }
        }
    }
    return  true;

};