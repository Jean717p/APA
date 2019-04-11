#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph *Graph;

Graph GRAPHinit(char*);
//int   GRAPHedges(Edge [], Graph G);
void  GRAPHgradenodeshow(Graph);
void  GRAPHspD(Graph, int, int*, int*);
void  GRAPHspBF(Graph, int, int*, int*);
void  GRAPHcityshow(Graph);
void  GRAPHnexttonode(Graph,int);
void  GRAPHmatrgen(Graph);
void  GRAPHflux(Graph);

#endif
