//
//  Graph.h
//  DataStructure
//
//  Created by Daniel on 15/10/9.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#ifndef __DataStructure__Graph__
#define __DataStructure__Graph__

#include <stdio.h>
#include "Status.h"
#define MVNum 10
//-------图的邻接矩阵存储表示
typedef char VerTexType;
typedef int ArcType;
typedef struct {
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

//-------图的邻接表存储表示
typedef int OtherInfo;
typedef struct  ArcNode {   //边节点
    int adjvex;
    struct ArcNode *nextarc;
    OtherInfo weight;
}ArcNode;

typedef struct VNode{      //顶点节点
    VerTexType data;
    ArcNode *firstarc;
}VNode,AdjList[MVNum];     //AdjList表示邻接表类型

typedef struct {           //邻接表
    AdjList vertices;
    int vexnum,arcnum;     //图的当前点数与边数
}ALGraph;

typedef struct {
    VerTexType adjvex;
    ArcType lowcost;
}Closedge[MVNum];

//克鲁斯卡尔算法辅助结构
typedef struct{
    VerTexType Head;
    VerTexType Tail;
    ArcType lowcost;
}OneEdge,Edge[MVNum];

int LocateVex(AMGraph *G,VerTexType v);
AMGraph *CreateUDN(AMGraph *G,Edge edge);
AMGraph *CreateYDN(AMGraph *G,Edge edge);
Status PrintGraph(AMGraph *G);

//采用邻接表表示法，创建无向图G
ALGraph *CreateUDG(ALGraph *G);
//采用邻接表表示法，创建有向图G
ALGraph *CreateYDG(ALGraph *G);
Status PrintLGraph(ALGraph *G);

//采用邻接矩阵表示图的深度优先搜索遍历
void DFSM(AMGraph G,int v,int *visited);
//采用邻接表表示图的深度优先搜索遍历
void DFST(ALGraph G,int v,int *visited);
//最小生成树 普里姆算法
AMGraph *MiniSpanTree_Prim(AMGraph *G,VerTexType u);
//最小生成树 克鲁斯卡尔算法
void MiniSpanTree_Kruskal(AMGraph *G,Edge edge);

//最短路径 迪杰斯特拉算法
void ShortestPath_DIJ(AMGraph *G,int v0);

//拓扑排序
Status TopologicalSort(ALGraph *G,int topo[]);
//关键路径
Status CriticalPath(ALGraph *G);
#endif /* defined(__DataStructure__Graph__) */
