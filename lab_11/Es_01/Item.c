#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#define MAX 25+1

struct Item{
    int x;
    char str[MAX];
};

int eq(int t,item s){
    if(t==(s->x))
        return 1;
    return 0;
}
int less(int t,item s){
    if(t<(s->x))
        return 1;
    return 0;
}
int ITEMless(item t,item s){
    if((t->x)<(s->x))
        return 1;
    return 0;
}
item ITEMscan(){
    item s=malloc(sizeof(struct Item));
    printf("Intero = ");
    scanf("%d", &s->x);
    printf("Stringa = ");
    scanf("%s", s->str);
    return s;
}
void ITEMshow(item t){
    printf("valore = %d  Stringa = %s\n", t->x, t->str);
    return;
}
void ITEMwrite(item t,FILE* fp){
    fprintf(fp,"%d %s\n",t->x,t->str);
    return;
}
void ITEMcount(int* i,FILE* fp){
    struct Item t;
    while((fscanf(fp,"%d %s",&t.x,t.str))!=EOF)
        (*i)++;
    return;
}
item ITEMupload(FILE* fp){
    item t=malloc(sizeof(struct Item));
    fscanf(fp,"%d %s",&(t->x),t->str);
    return t;
}
void ITEMfree(item t){
    free(t);
    return;
}
