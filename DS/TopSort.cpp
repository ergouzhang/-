//
//  TopSort.cpp
//  graph
//
//  Created by zwj on 16/6/8.
//  Copyright © 2016年 zwj. All rights reserved.
//

#include "Graph.cpp"

bool TopSort(LGraph Graph, Vertex TopOrder[])
{

    int Indegree[Graph->Ne];
    int cnt;
    Vertex V;
    ptrToAdjVNode W;
    
    Queue Q=CreateQueue(Graph->Nv);
    
    for (V=0; V<Graph->Nv; V++)
    {
        Indegree[V]=0;
    }
    
    for (V=0; V<Graph->Nv; V++)
    {
        for (W=Graph->G[V].FirstEdge; W; W=*W->Next)
        {
            Indegree[W->adjV]++;
            
        }
    }





}
