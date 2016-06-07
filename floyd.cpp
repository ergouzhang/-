//
//  floyd.cpp
//  graph
//
//  Created by zwj on 16/6/7.
//  Copyright © 2016年 zwj. All rights reserved.
//

#include "Graph.cpp"
/* 邻接矩阵存储 - 多源最短路算法 */

bool Floyd(MGraph Graph)
{
    WeightType D[Graph->Nv][Graph->Nv];
    Vertex path[Graph->Nv][Graph->Nv];
    Vertex i,j,k;
    
      /* 初始化 */
    for (i=0; i<Graph->Nv; i++)
    {
        for (j=0; j<Graph->Nv; j++)
        {
            D[i][j]=Graph->G[i][j];
            path[i][j]=-1;
        }
    }
    
    
    for (k=0; k<Graph->Nv; k++)
    {
        for (i=0; i<Graph->Nv; i++) {
            for (j=0; j<Graph->Nv; j++) {
                if (D[i][k]+D[k][j]<D[i][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    
        return true;


};