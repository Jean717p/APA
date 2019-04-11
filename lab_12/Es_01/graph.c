#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Graph.h"
#include "item.h"
#define MAX 10+1

typedef struct node *link;

struct node{
    int wt;
    char* v;
    link next;
};
struct graph{
    int V,**matr_adj;
    char** regioni;
    item *x;
    link *adj;
};

link NEW(char* v,int wt,link next);

Graph GRAPHinit(char* file){
    int V,i; FILE* fp=NULL;
    char **reg,temp[MAX],temp1[MAX];
    if((fp=fopen(file,"r"))==NULL)
        exit(-2);
    fscanf(fp,"%d",&V);
    Graph G=malloc(sizeof *G);
    G->V=V;
    G->x=Iteminit(V);
    reg=malloc(V*sizeof(char*));
    G->adj=malloc(V*sizeof(link));
    G->matr_adj=NULL;
    for(V=i=0;V<G->V;V++,i=0){
        reg[V]=NULL; G->adj[V]=NULL;
        fscanf(fp,"%s %s",temp,temp1);
        while(reg[i]!=NULL){
            if(strcmp(temp1,reg[i])==0)
                break;
            i++;
        }
        if(reg[i]==NULL)
            reg[i]=strdup(temp1);
        G->x[V]=riempiitem(temp,temp1,i);
    }
    G->regioni=reg;
    while((fscanf(fp,"%s %s %d",temp,temp1,&V))!=EOF){
        i=itemcheck(G->x,temp);
        itemgrade(G->x[i]);
        G->adj[i]=NEW(temp1,V,G->adj[i]); //inserimenti in testa dopo il primo
        i=itemcheck(G->x,temp1);
        itemgrade(G->x[i]);
        G->adj[i]=NEW(temp,V,G->adj[i]);
    }
    fclose(fp);
    return G;
}
link NEW(char* v,int wt,link next){
    link x=malloc(sizeof *x);
    x->v=strdup(v);
    x->wt=wt;
    x->next=next;
    return x;
}
void GRAPHgradenodeshow(Graph G){
    int v;
    for(v=0;v<G->V;v++){
        printf("Nodo %2d grado ",v);
        itemgradeshow(G->x[v]);
    }
}
void GRAPHcityshow(Graph G){
    int i;
    printf("Numero citta': %d\n",G->V);
    for(i=0;i<G->V;i++){
        printf("Nodo %2d citta' ",i);
        itemcityshow(G->x[i]);
    }
    return;
}
void GRAPHnexttonode(Graph G,int N){
    link t;
    if(N>G->V||N<0){
        printf("Nodo inesistente\n");
        return;
    }
    printf("Nodo %d, citta' ",N); itemcityshow(G->x[N]);
    printf("Numero di collegamenti: "); itemgradeshow(G->x[N]);
    printf("Citta' collegate:\n");
    for(t=G->adj[N];t!=NULL;t=t->next)
        printf("%s\n",t->v);
    return;
}
void GRAPHmatrgen(Graph G){
    int i,j; link t;
    if(G->matr_adj==NULL){
        G->matr_adj=malloc(G->V*sizeof(int*));
        for(i=0;i<G->V;i++){
            G->matr_adj[i]=malloc(G->V*sizeof(int));
            for(j=0;j<G->V;j++)
                G->matr_adj[i][j]=0;
        }
        for(i=0;i<G->V;i++){
            for(t=G->adj[i];t!=NULL;t=t->next){
                j=itemcheck(G->x,t->v); //è come se G->x perdesse dei pezzi per strada nonostante dopo
                if(G->matr_adj[i][j]==0){ //esser stato riempito correttamente non lo si tocchi più
                    G->matr_adj[i][j]=t->wt; //e la sua stampa (Graphcityshow) funzioni bene
                    G->matr_adj[j][i]=t->wt;
                }
            }
        }
    }
    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++)
            printf("%3d ",G->matr_adj[i][j]);
        printf("\n");
    }
    return;
}
void GRAPHflux(Graph G){
    int i,j,traregioni,inregione,v[G->V][G->V];
    link t;
    for(i=0;i<G->V;i++)
        for(j=0;j<G->V;j++)
            v[i][j]=0;
    for(traregioni=i=inregione=0;i<G->V;i++){
        for(t=G->adj[i];t!=NULL;t=t->next){
            j=itemcheck(G->x,t->v);
            if(v[i][j]==0){
                if(regcheck(G->x,j,i)==0)
                    inregione+=t->wt;
                else
                    traregioni+=t->wt;
                v[i][j]=v[j][i]=1;
            }
        }
    }
    printf("Flusso interregionale: %d\nFlusso intraregionale: %d\n",inregione,traregioni);
    return;
}
