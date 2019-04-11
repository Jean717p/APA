#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

struct Item{
    char codice[10+1];
    char *nome,*cognome;
    char data[10+1];
};

item init(FILE** fp){
    char temp[30+1];
    item t=malloc(sizeof(struct Item));
    fscanf(*fp,"%s",t->codice);
    fscanf(*fp,"%s",temp); t->nome=strdup(temp);
    fscanf(*fp,"%s",temp); t->cognome=strdup(temp);
    fscanf(*fp,"%s",t->data);
    return t;
}
int itemlook(item a,item b){
    return strcmp(a->codice,b->codice);
}
int itemdico(item a,char* b){
    return strcmp(a->codice,b);
}
void stampa(item v){
    printf("Codice: %s\nNome: %s\nCognome: %s\nData di nascita: %s\n",v->codice,v->nome,v->cognome,v->data);
    return;
}
void ItemDestruction(item v){
    free(v->nome); free(v->cognome);
    return;
}
