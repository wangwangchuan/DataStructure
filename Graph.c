//
//  Graph.c
//  DataStructure
//
//  Created by Daniel on 15/10/9.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#define True 1
#define False 0

#include "Graph.h"
#include "Stack.h"

void Sort(Edge edge,AMGraph *G)
{
    OneEdge one;
    for (int i =0; i<G->arcnum; ++i) {
        for (int j=i; j<G->arcnum; ++j) {
            if (edge[i].lowcost > edge[j].lowcost) {
                one = edge[i];
                edge[i] = edge[j];
                edge[j]=one;
            }
        }
    }
}
int Min(AMGraph *G,Closedge closedge)
{
    int k=0;
    int min=INT16_MAX;
    for (int i = 0; i< G->vexnum; ++i) {
        if (closedge[i].lowcost != 0 && min > closedge[i].lowcost)
        {
            min = closedge[i].lowcost;
            k = i;
        }
    }
    return k;
}

int LocateVex(AMGraph *G,VerTexType v)
{
    int index = INT16_MAX;
    for(int i=0;i<G->vexnum;++i)
        if (G->vexs[i] == v)
            index = i;
    return index;
}
int LocateVexL(ALGraph *G,VerTexType v)
{
    int index = INT16_MAX;
    for(int i=0;i<G->vexnum;++i)
        if (G->vertices[i].data == v)
            index = i;
    return index;
}

void FindInDegree(ALGraph *G,int *indegree)
{
    int i,j;
    ArcNode *p;
    for (i=0;i<G->vexnum; ++i) {
        for (p = G->vertices[i].firstarc; p != NULL; p= p->nextarc) {
            j = p->adjvex;
            indegree[j] ++;
        }
    }
}

//采用邻接矩阵表示法，创建无向网G
AMGraph *CreateUDN(AMGraph *G,Edge edge)
{
    int w;
    int i,j,k;
    VerTexType v1,v2;
    printf("input number");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    for (i=0; i<G->vexnum; ++i) {
        printf("input a new vex name");
        scanf(" %c",&G->vexs[i]);
    }
    for(i=0;i<G->vexnum;++i)
        for(j=0;j<G->vexnum;++j)
            G->arcs[i][j] = INT16_MAX;
    for(k=0;k<G->arcnum;++k)
    {
        printf("input edge info");
        scanf(" %c%c%d",&v1,&v2,&w);
        edge[k].Head =v1;
        edge[k].Tail =v2;
        edge[k].lowcost =w;
        i = LocateVex(G,v1);
        j = LocateVex(G,v2);
        G->arcs[i][j] = w;
        G->arcs[j][i] = G->arcs[i][j]; //可修改为有向网
    }
    return G;
}

//采用邻接矩阵表示法，创建有向网G
AMGraph *CreateYDN(AMGraph *G,Edge edge)
{
    int w;
    int i,j,k;
    VerTexType v1,v2;
    printf("input number");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    for (i=0; i<G->vexnum; ++i) {
        printf("input a new vex name");
        scanf(" %c",&G->vexs[i]);
    }
    for(i=0;i<G->vexnum;++i)
        for(j=0;j<G->vexnum;++j)
            G->arcs[i][j] = INT16_MAX;
    for(k=0;k<G->arcnum;++k)
    {
        printf("input edge info");
        scanf(" %c%c%d",&v1,&v2,&w);
        edge[k].Head =v1;
        edge[k].Tail =v2;
        edge[k].lowcost =w;
        i = LocateVex(G,v1);
        j = LocateVex(G,v2);
        G->arcs[i][j] = w;
    }
    return G;
}

//采用邻接表表示法，创建无向图G
ALGraph *CreateUDG(ALGraph *G)
{
    int i,j,k;
    VerTexType v1,v2;
    printf("input number");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    for (i = 0; i<G->vexnum; ++i) {
        printf("input a new vex name");
        scanf(" %c",&G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    for (k =0; k<G->arcnum; ++k) {
        printf("input edge info");
        scanf(" %c%c",&v1,&v2);
        i = LocateVexL(G, v1);
        j = LocateVexL(G,v2);
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = j;
        p1->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = p1;
        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = i;
        p2->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = p2;
    }
    return G;
}

//采用邻接表表示法，创建有向图G
ALGraph *CreateYDG(ALGraph *G)
{
    int i,j,k;
    int w;
    VerTexType v1,v2;
    printf("input number");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    for (i = 0; i<G->vexnum; ++i) {
        printf("input a new vex name");
        scanf(" %c",&G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    for (k =0; k<G->arcnum; ++k) {
        printf("input edge info");
        scanf(" %c%c%d",&v1,&v2,&w);
        i = LocateVexL(G, v1);
        j = LocateVexL(G,v2);
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = j;
        p1->weight = w;
        p1->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = p1;
       }
    return G;
}

void DFSM(AMGraph G,int v,int *visited)
{
    int w;
    printf("%d",v);
    visited[v] = 1;
    for (w =0; w<G.vexnum; w++) {
        if ((G.arcs[v][w] != 0) && (!visited[w])) {
            DFSM(G, w,visited);
        }
    }
}

void DFST(ALGraph G,int v,int *visited)
{
    int w;
    printf("%d",v);
    visited[v] = 1;
    ArcNode *p = G.vertices[v].firstarc;
    while (p!=NULL) {
        w = p->adjvex;
        if (!visited[w]) {
            DFST(G, w, visited);
        }
        p= p->nextarc;
    }
}

//输出邻接矩阵表示图
Status PrintGraph(AMGraph *G)
{
    for(int i=0;i<G->vexnum;++i)
    {
        for(int j=0;j<G->vexnum;++j)
            printf("%d  ",G->arcs[i][j]);
        printf("\n");
    }
    return SUCCESS;
}
//输出邻接表表示图
Status PrintLGraph(ALGraph *G)
{
    for(int i=0;i<G->vexnum;++i)
    {
        printf("%c->",G->vertices[i].data);
        for (ArcNode *p = G->vertices[i].firstarc; p != NULL; p= p->nextarc) {
            printf("%d->",p->adjvex);
        }
        printf("\n");
    }
    return SUCCESS;
}


AMGraph *MiniSpanTree_Prim(AMGraph *G,VerTexType u)
{
    int k,i,j;
    VerTexType u0,v0;
    Closedge closedge;
    k = LocateVex(G,u);
    for(j=0;j<G->vexnum;++j)
        if(j!=k)
            {
                closedge[j].adjvex = u;
                closedge[j].lowcost = G->arcs[k][j];
            }
    closedge[k].lowcost = 0;
    for(i=1;i<G->vexnum;++i)
    {
        k=Min(G,closedge);
        u0 = closedge[k].adjvex;
        v0 = G->vexs[k];
        printf("%c--%c--%d",u0,v0,closedge[k].lowcost);
        closedge[k].lowcost = 0;
        for (j=0; j<G->vexnum; ++j) {
            if(G->arcs[k][j] < closedge[j].lowcost)
            {
                closedge[j].adjvex = G->vexs[k];
                closedge[j].lowcost = G->arcs[k][j];
            }
        }
    }
    return G;
}

void MiniSpanTree_Kruskal(AMGraph *G,Edge edge)
{
    int i,j;
    int Vexset[MVNum];
    VerTexType v1,v2;
    int vs1,vs2;
    Sort(edge,G);
    for (i =0;i<G->vexnum;++i)
    {
        Vexset[i] = i;
    }
    for (i =0;i<G->arcnum;++i)
    {
        v1=LocateVex(G, edge[i].Head);
        v2=LocateVex(G, edge[i].Tail);
        vs1=Vexset[v1];
        vs2=Vexset[v2];
        if (vs1 != vs2)
        {
            printf("%c--%c--%d",edge[i].Head,edge[i].Tail,edge[i].lowcost);
            for (j=0; j<G->vexnum; ++j) {
                if (Vexset[j] == vs2) {
                    Vexset[j] = vs1;
                }
            }
        }
    }
}

void ShortestPath_DIJ(AMGraph *G,int v0)
{
    //用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径
    int v,w;
    int n = G->vexnum;
    int S[n],D[n],Path[n];
    for (v=0; v<n; ++v) {
        S[v]=False;
        D[v] = G->arcs[v0][v];
        if (D[v] < INT16_MAX)
            Path[v] = v0;
        else
            Path[v] = -1;
    }
    
    S[v0] =True;
    D[v0] = 0;
    for (int i = 1; i<n; ++i) {
        int min = INT16_MAX;
        for (w = 0; w<n; ++w) {
            if (!S[w] && (D[w] < min)) {
                v = w;min = D[w];
            }
        }
        
        S[v] = True;
        for (w= 0; w<n; ++w) {
            if (!S[w]&&(D[v] + G->arcs[v][w] < D[w])) {
                D[w] = D[v] + G->arcs[v][w];
                Path[w] = v;
            }
        }
    }
}

Status TopologicalSort(ALGraph *G,int topo[])
{
    //有向图G采用邻接表存储结构
    //若G无回路，则生成G的一个拓扑序列topo[]并返回OK,否则ERROR
    int i,j,k;
    int indegree[MVNum] ={0};
    FindInDegree(G,indegree);
    int *S = (int *)malloc(sizeof(int)*(G->vexnum));
    for (int i = 0; i<G->vexnum; ++i) {
        if (!indegree[i]) {
            push(S,i);
        }
    }
    int m = 0;
    while (!(stackEmpty(S))) {
        j=pop(S);
        topo[m]=j;
        ++m;
        ArcNode *p = G->vertices[j].firstarc;
        while (p!= NULL) {
            k = p->adjvex;
            --indegree[k];
            if (indegree[k]==0) {
                push(S,k);
            }
            p = p->nextarc;
        }
    }
    if (m<G->vexnum) {
        return ERROR;
    }
    else {
        for (i=0; i<G->vexnum; ++i) {
            printf("%d->",topo[i]);
        }
        printf("\n");
        return SUCCESS;
    }
}


Status CriticalPath(ALGraph *G)
{
    //G为邻接表存储的有向网，输出G的各项关键活动
    int i,j,k,e,l;
    int *ve=(int *)malloc(sizeof(int)*MVNum);
    int *vl=(int *)malloc(sizeof(int)*MVNum);
    int *topo=(int *)malloc(sizeof(int)*MVNum);
    ArcNode *p;
    if (!TopologicalSort(G, topo)) {
        return ERROR;
    }
    int n = G->vexnum;
    for (i=0; i<n; i++) {
        ve[i]=0;
    }
    //按拓扑次序求每个事件的最早发生时间
    for (i=0; i<n; i++) {
        k = topo[i];
        p = G->vertices[k].firstarc;
        while (p!=NULL) {
            j = p->adjvex;
            if (ve[j] <ve[k]+p->weight) {
                ve[j] = ve[k]+p->weight;
            }
            p=p->nextarc;
        }
    }
    for (i=0; i<n; i++) {
        vl[i] = ve[n-1];
    }
    //按逆拓扑次序求每个事件的最迟发生时间
    for (i=n-1; i>=0; i--) {
        k=topo[i];
        p=G->vertices[k].firstarc;
        while (p!=NULL) {
            j=p->adjvex;
            if (vl[k]>vl[j]-p->weight) {
                vl[k] = vl[j]-p->weight;
            }
            p=p->nextarc;
        }
    }
    
    //判断每一活动是否为关键活动
    for (i=0; i<n; i++) {
        p=G->vertices[i].firstarc;
        while (p!=NULL) {
            j=p->adjvex;
            e=ve[i];
            l=vl[j]-p->weight;
            if (e==l) {
                printf("%c--%c--",G->vertices[i].data,G->vertices[j].data);
            }
            p=p->nextarc;
        }
    }
    return SUCCESS;
}