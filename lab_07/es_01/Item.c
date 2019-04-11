#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

struct item{
    char *frase;
    int numero;
};
void make(link *t){
    *t=malloc(sizeof(struct item));
    return;
}
void riempi(link** v,int tail){
    char temp[N];
    printf("Inserisci stringa: "); fflush(stdin);
    gets(temp); ((*v)[tail])->frase=strdup(temp);
    printf("Inserisci numero: ");
    scanf("%d",&((*v)[tail])->numero);
    return;
}
void ex(link** v,int head){
    free(((*v)[head])->frase);
    //free(*v[*head]);
    return;
}
void scrivi(link v){
    printf("%s ",v->frase);
    printf("%d\n",v->numero);
    return;
}
void incidi(link v,FILE** fp){
    fprintf(*fp,"%s %d\n",v->frase,v->numero);
    return;
}
void load(link* t,FILE** fp){
    char temp[N];
    fscanf(*fp,"%s",temp);
    (*t)->frase=strdup(temp);
    fscanf(*fp,"%d",&(*t)->numero);
    return;
}
void libera(link *t){
    free((*t)->frase);
    return;
}
