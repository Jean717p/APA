#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#define max 5+1

struct Item{
    int pr;
    char str[max];
};

item ITEMscan(){
    item x=malloc(sizeof(*x));
    printf("Indice di priorita': ");
    scanf("%d",&x->pr);
    printf("Codice: "); scanf("%s",x->str);
    return x;
}
int ITEMless(item x,item t){
    if((x->pr)<=(t->pr))
        return 1;
    return 0;
}
void ITEMshow(item x){
    printf("Codice: %s\tPriorita': %d\n",x->str,x->pr);
    return;
}
void ITEMfree(item x){
    free(x);
    return;
}
void ITEMcount(int* i,FILE* fp){
    item t=malloc(sizeof(*t));
    while((fscanf(fp,"%s %d",t->str,&t->pr))!=EOF)
        (*i)++;
    free(t);
    return;
}
item ITEMupload(FILE* fp){
    item t=malloc(sizeof(struct Item));
    fscanf(fp,"%s %d",t->str,&t->pr);
    return t;
}

