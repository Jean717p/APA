#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

struct Item{
    char *city,*regione;
    int idr,grado;
};

item* Iteminit(int i){
    int j;
    item* x=malloc(i*sizeof(item));
    for(j=0;j<i;j++)
        x[j]=malloc(sizeof(struct Item));
    return x;
}
item riempiitem(char* t1,char* t2,int N){
    item x=malloc(sizeof(*x));
    x->city=strdup(t1);
    x->regione=strdup(t2);
    x->idr=N; x->grado=0;
    return x;
}
int itemcheck(item* x,char* s){
    int i=0;
    while(strcmp(x[i]->city,s)!=0) //si suppone il file sia corretto
        i++;
    return i;
}
void itemgrade(item x){
    x->grado++;
    return;
}
void itemgradeshow(item x){
    printf("%d\n",x->grado);
    return;
}
void itemcityshow(item x){
    printf("%s\n",x->city);
    return;
}
int regcheck(item* x,int j,int i){
    if(x[i]->idr==x[j]->idr)
        return 0;
    return 1;
}
