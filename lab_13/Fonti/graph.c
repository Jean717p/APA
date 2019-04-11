#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#define maxV 100

typedef struct node *link;
struct node { int v; link next; } ;
struct graph { int V; int E; link *adj; int *scc; } ;

static int time, pre[maxV], post[maxV], st[maxV], postR[maxV], time0, time1;

link NEW(int v, link next)
  { link x = malloc(sizeof *x);
    x->v = v; x->next = next;
    return x;
  }

Edge EDGE(int v, int w)
{
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}

Graph GRAPHinit(int V)
{
    int v;
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = malloc(G->V*sizeof(link));
    for (v = 0; v < G->V; v++)
        G->adj[v] = NULL;
    return G;
}

void  GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w;

    G->adj[v] = NEW(w, G->adj[v]);
    G->E++;
}

int   GRAPHedges(Graph G, Edge a[])
{
    int v, E = 0;
    link t;
    for (v=0; v < G->V; v++)
        for (t=G->adj[v]; t != NULL; t = t->next)
            a[E++] = EDGE(v, t->v);
    return E;
}

void  GRAPHshow(Graph G)
{
    int v;
    link t;
    printf("%d vertices, %d edges \n", G->V, G->E);
    for (v=0; v < G->V; v++)
    {
        printf("%2d:", v);
        for (t=G->adj[v]; t != NULL; t = t->next)
            printf("%2d  ", t->v);
        printf("\n");
    }
}

int randV(Graph G)
{
    return G->V * (rand() / (RAND_MAX + 1.0));
}

/* random edges

Graph GRAPHrand(Graph G, int V, int E)
{
    while (G->E < E)
       GRAPHinsertE(G, EDGE(randV(G), randV(G)));
    return G;
}
*/

// edges with probability p
Graph GRAPHrand(Graph G, int V, int E)
{
    int i, j;
    double p = 2.0 * E / (V * (V-1));
    for ( i = 0; i < V; i++)
        for ( j = i+1; j < V; j++)
            if (rand() < p * RAND_MAX)
                GRAPHinsertE(G, EDGE(i, j));
    return G;
}

void dfsR(Graph G, Edge e)
{
    link t; int v, w = e.w; Edge x;
    if (e.v != e.w)
        printf("edge (%d, %d) is tree \n", e.v, e.w) ;
    st[e.w] = e.v;
    pre[w] = time++;
    for (t = G->adj[w]; t != NULL; t = t->next)
      if (pre[t->v] == -1)
        dfsR(G, EDGE(w, t->v));
      else {
        v = t->v;
        x = EDGE(w, v);
        if (post[v] == -1)
            printf("edge (%d, %d) is back \n", x.v, x.w) ;
        else
            if(pre[v]>pre[w])
                printf("edge (%d, %d) is forward \n", x.v, x.w) ;
            else
                printf("edge (%d, %d) is cross \n", x.v, x.w) ;
      }
    post[w] = time++;
}

void GRAPHdfs(Graph G)
{
    int v;
    time = 0;
    for (v=0; v < G->V; v++)
    {
      pre[v] = -1;
      post[v] = -1;
      st[v] =  -1;
    }
    for (v=0; v < G->V; v++)
      if (pre[v]== -1)
        dfsR(G, EDGE(v,v));

    printf("discovery/endprocessing time labels \n");
    for (v=0; v < G->V; v++)
        printf("vertex %d : %d/%d \n", v, pre[v], post[v]);

    printf("resulting DFS tree \n");
    for (v=0; v < G->V; v++)
        printf("parent of vertex %d is vertex  %d \n", v, st[v]);

}

Graph GRAPHreverse(Graph G)
{
      int v;
      link t;
      Graph R = GRAPHinit(G->V);
      for (v=0; v < G->V; v++)
          for (t= G->adj[v]; t != NULL; t = t->next)
              GRAPHinsertE(R, EDGE(t->v, v));
      return R;
}

void SCCdfsR(Graph G, int w)
{
    link t;
    G->scc[w] = time1;
    for (t = G->adj[w]; t != NULL; t = t->next)
      if (G->scc[t->v] == -1)
        SCCdfsR(G, t->v);
    post[time0++]= w;
}

int GRAPHscc(Graph G)
{
    int v;
    Graph R;

    R = GRAPHreverse(G);

    time0 = 0;
    time1 = 0;

    G->scc = malloc(G->V * sizeof(int));
    R->scc = malloc(G->V * sizeof(int));

    for (v=0; v < G->V; v++)
        R->scc[v] = -1;

    for (v=0; v < G->V; v++)
      if (R->scc[v] == -1)
        SCCdfsR(R, v);

    time0 = 0;
    time1 = 0;

    for (v=0; v < G->V; v++)
        G->scc[v] = -1;

    for (v=0; v < G->V; v++)
        postR[v] = post[v];

    for (v = G->V-1; v >= 0; v--)
      if (G->scc[postR[v]] == -1)
      {
          SCCdfsR(G, postR[v]);
          time1++;
      }

    printf("\n Strongly connected components \n");
    for (v = 0; v < G->V; v++)
        printf("node %d belongs to scc %d \n", v, G->scc[v]);

    return time1;
 }

int GRAPHstrongconnect(Graph G, int s, int t)
{
    return G->scc[s] == G->scc[t];
}

