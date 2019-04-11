#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph *Graph;

Graph GRAPHinit(char*);
void GRAPHlinkMIN(Graph,int,int);
void GRAPHlinkMAX(Graph,int,int);
void GRAPHlinkTOT(Graph,int,int);
void GRAPHscc(Graph);
void GRAPHshow(Graph);

#endif
