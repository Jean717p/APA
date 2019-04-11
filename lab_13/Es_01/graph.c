#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Graph.h"
#include "item.h"
#define MAX 35

typedef struct node *link;

struct node{
    int id;
    link next;
};
struct graph{
    int V,E,*scc;
    char **nodes;
    link *adj;
};
struct sol{
    int* result;
    struct sol* next;
};

static int *visited,*post,time0,time1;
link NEW(int i,link next);
int pathR(Graph G,int v,int w,struct sol* *head,int time[],int *N);
Graph GRAPHinit2(int V);
Graph GRAPHreverse(Graph G);
void SCCdfsR(Graph G,int w);

Graph GRAPHinit(char* file){
    int j,i; FILE* fp=NULL;
    char **nodi,temp[MAX],temp2[MAX];
    Graph G=malloc(sizeof *G);
    if((fp=fopen(file,"r"))==NULL)
        exit(-2);
    fscanf(fp,"%d",&j);
    nodi=malloc(j*sizeof(char*));
    G->adj=malloc(j*sizeof(link));
    visited=malloc(j*sizeof(int));
    post=malloc(j*sizeof(int));
    for(i=0;i<j;i++){
        G->adj[i]=NULL;
        nodi[i]=NULL;
    }
    G->E=0; G->V=j; G->scc=NULL;
    while((fscanf(fp,"%s %s",temp,temp2))!=EOF){
        G->E++; i=0;
        while(nodi[i]!=NULL){
            if(strcmp(nodi[i],temp)==0)
                break;
            i++;
        }
        if(nodi[i]==NULL)
            nodi[i]=strdup(temp);
        j=i;
        i=0;
        while(nodi[i]!=NULL){
            if(strcmp(nodi[i],temp2)==0)
                break;
            i++;
        }
        if(nodi[i]==NULL)
            nodi[i]=strdup(temp2);
        G->adj[j]=NEW(i,G->adj[j]);
    }
    fclose(fp);
    G->nodes=nodi;
    return G;
}
link NEW(int s,link next){
    link x=malloc(sizeof *x);
    x->id=s;
    x->next=next;
    return x;
}
void GRAPHlinkMIN(Graph G,int a,int b){
    int i,N,time[G->V];
    struct sol *head=NULL,*min,*t;
    if(a<0||a>G->V||b<0||b>G->V){
        printf("Input errato..\n"); return;}
    printf("Il Cammino semplice minimo tra %s e %s:\n",G->nodes[a],G->nodes[b]);
    if(a==b){
        printf("Non sono ammessi cappi.\n");
        return;
    }
    else{
        for(i=N=0;i<G->V;i++){
            visited[i]=0;
            time[i]=-1;
        }
        i=pathR(G,a,b,&head,time,&N);
        if(head==NULL){
            printf("Non esiste.\n");
            return;
        }
        N=G->V; t=head;
        while(head!=NULL){
            i=0;
            while(head->result[i++]>=0);
            if(i<N){
                min=head;
                N=i;
            }
            head=head->next;
        }
        i=0;
        while(min->result[i]>=0)
            printf("%s ",G->nodes[min->result[i++]]);
        printf("\n");
        while(t!=NULL){
            head=t;
            t=t->next;
            free(head->result);
            free(head);
        }
    }
    return;
}
void GRAPHlinkMAX(Graph G,int a,int b){
    int i,N,time[G->V];
    struct sol *head=NULL,*max,*t;
    if(a<0||a>G->V||b<0||b>G->V){
        printf("Input errato..\n"); return;}
    printf("Il Cammino semplice minimo tra %s e %s:\n",G->nodes[a],G->nodes[b]);
    if(a==b){
        printf("Non sono ammessi cappi.\n");
        return;
    }
    else{
        for(i=N=0;i<G->V;i++){
            visited[i]=0;
            time[i]=-1;
        }
        i=pathR(G,a,b,&head,time,&N);
        if(head==NULL){
            printf("Non esiste.\n");
            return;
        }
        N=-1; t=head;
        while(head!=NULL){
            i=0;
            while(head->result[i++]>=0);
            if(i>N){
                max=head;
                N=i;
            }
            head=head->next;
        }
        i=0;
        while(max->result[i]>=0)
            printf("%s ",G->nodes[max->result[i++]]);
        printf("\n");
        while(t!=NULL){
            head=t;
            t=t->next;
            free(head->result);
            free(head);
        }
    }
    return;
}
void GRAPHlinkTOT(Graph G,int a,int b){
    int i,N,time[G->V];
    struct sol *head=NULL,*t;
    if(a<0||a>G->V||b<0||b>G->V){
        printf("Input errato..\n"); return;}
    printf("I cammini semplici tra %s e %s sono:\n",G->nodes[a],G->nodes[b]);
    if(a==b){
        printf("Non sono ammessi cappi.\n");
        return;
    }
    else{
        for(i=N=0;i<G->V;i++){
            visited[i]=0;
            time[i]=-1;
        }
        i=pathR(G,a,b,&head,time,&N);
        if(head==NULL){
            printf("Non esiste.\n");
            return;
        }
        N=0; t=head;
        while(head!=NULL){
            i=0; N++;
            while(head->result[i]>=0)
                printf("%s ",G->nodes[head->result[i++]]);
            printf("\n"); head=head->next;
        }
        printf("Totale: %d\n",N);
        while(t!=NULL){
            head=t;
            t=t->next;
            free(head->result);
            free(head);
        }
    }
    return;
}
int pathR(Graph G,int v,int w,struct sol* *head,int time[],int *N){
    link x; int i; struct sol *soz,*t;
    visited[v]=1; time[(*N)++]=v; //funzione che ritorna tutti i cammini
    if(v==w){
        return 1;
    }
    if(G->adj[v]==NULL)
        visited[v]=2;
    for(x=G->adj[v];x!=NULL;x=x->next){
        if(visited[x->id]==0){
            if(pathR(G,x->id,w,head,time,N)){
                soz=*head;
                while(soz!=NULL)
                    soz=soz->next;
                soz=malloc(sizeof(*soz)); //creo nuova
                if(*head==NULL){
                    *head=soz;
                    soz->next=NULL; //solo la prima volta
                }
                else{ //inserimento in testa(->next)
                    t=(*head)->next;
                    (*head)->next=soz;
                    soz->next=t;
                }
                soz->result=malloc((*N+1)*sizeof(int));
                for(i=0;i<*N;i++)
                    soz->result[i]=time[i];
                soz->result[i]=-1;
                (*N)--;
                if(x->next==NULL){
                    visited[x->id]=0;
                    return 0;
                }
            }
            else
                (*N)--;
            if(visited[x->id]!=2)
                visited[x->id]=0;
        }
    }
    return 0;
}
void GRAPHscc(Graph G){
    int v; Graph R;
    if(G->scc==NULL){
        R=GRAPHreverse(G);
        time0=time1=0;
        G->scc = malloc(G->V * sizeof(int));
        R->scc = malloc(G->V * sizeof(int));
        for (v=0; v < G->V; v++)
            R->scc[v]=G->scc[v]=-1;
        for (v=0; v < G->V; v++)
          if (R->scc[v] == -1)
            SCCdfsR(R, v);
        time0=time1=0;
        for (v=0; v < G->V; v++)
            visited[v] = post[v];
        for (v=G->V-1;v>=0;v--)
          if (G->scc[visited[v]] == -1){
              SCCdfsR(G,visited[v]);
              time1++;
          }
    }
    printf("Strongly connected components \n");
    for (v = 0; v < G->V; v++)
        printf("%s belongs to scc %d \n",G->nodes[v],G->scc[v]);

    return;
 }
Graph GRAPHinit2(int V){
    int v; Graph G = malloc(sizeof *G);
    G->V = V; G->E = 0;
    G->adj = malloc(G->V*sizeof(link));
    for (v = 0; v < G->V; v++)
        G->adj[v] = NULL;
    return G;
}
Graph GRAPHreverse(Graph G){
      int v; link t;
      Graph R=GRAPHinit2(G->V);
      for (v=0;v<G->V;v++)
          for(t=G->adj[v];t!=NULL;t=t->next){
            R->adj[t->id]=NEW(v,R->adj[v]);
            R->E++;
          }
      return R;
}
void SCCdfsR(Graph G,int w){
    link t;
    G->scc[w]=time1;
    for(t=G->adj[w];t!=NULL;t=t->next)
      if(G->scc[t->id]==-1)
        SCCdfsR(G,t->id);
    post[time0++]=w;
}
void GRAPHshow(Graph G){
    int i; link t;
    for(i=0;i<G->V;i++){
        printf("Vertice: %s - pos: %d - archi:\n",G->nodes[i],i);
        for(t=G->adj[i];t!=NULL;t=t->next)
            printf("%s\n",G->nodes[t->id]);
    }
    return;
}
