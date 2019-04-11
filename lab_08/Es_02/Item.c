#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

struct Item{
    char codice[10+1];
    char *nome,*cognome;
    char data[10+1];
    item next;
};

void init(FILE** fp,item* head,item* tail,item t,int N,int i){
    char temp[30+1];
    t=malloc(sizeof(struct Item));
    t->next=NULL;
    fscanf(*fp,"%s",t->codice);
    fscanf(*fp,"%s",temp); t->nome=strdup(temp);
    fscanf(*fp,"%s",temp); t->cognome=strdup(temp);
    fscanf(*fp,"%s",t->data);
    if(*head==NULL)
        *head=*tail=t; //primo elemento
    else
        (*tail)->next=t; *tail=t; //gli altri
    if(i<N-1)
        init(fp,head,tail,t,N,i+1);
    return;
}
item found(item v,item tail,item ris,char code[]){
    if(strcmp(code,v->codice)==0){
        printf("L'individuo e' stato trovato!\n");
        return v;
    }
    else if(v!=tail)
        ris=found(v->next,tail,ris,code);
    else{
        printf("Corrispondenza codice non trovata.\n");
        return NULL;
    }
    return ris;
}
void mainstampa(item v,item fine){
    stampa(v);
    if(v!=fine)
        mainstampa(v->next,fine);
    return;
}
void stampa(item v){
    printf("\nCodice: %s\nNome: %s\nCognome: %s\nData di nascita: %s\n",v->codice,v->nome,v->cognome,v->data);
    printf("____________________________________________________\n");
    return;
}
void inserisci(item *tail){
    item t=malloc(sizeof(struct Item)); char temp[30+1];
    t->next=NULL;
    printf("Inserisci codice: ");
    scanf("%s",t->codice); fflush(stdin);
    printf("Nome: ");
    scanf("%s",temp); t->nome=strdup(temp);
    printf("Cognome: ");
    scanf("%s",temp); t->cognome=strdup(temp);
    printf("Data di nascita (gg/mm/aaaa): ");
    scanf("%s",t->data);
    (*tail)->next=t;
    *tail=t;
    return;
}
void delit(item *head,item v,item* tail,item t,char cod[]){
    if(strcmp(v->codice,cod)==0){
        free(v->nome); free(v->cognome);
        if(*head==v)
            *head=v->next;
        if(*tail==v){
            *tail=t;
        }
        t->next=v->next;
        free(v);
    }
    t=v; //t è la precedente necessaria per spostare tail in caso sia l'ultima da cancellare
    v=v->next;
    if(v!=NULL)
        delit(head,v,tail,t,cod);
    return;
}
void itemmod(item t){
    char temp[30+1];
    printf("Inserire nuovi parametri:\n");
    printf("Codice: "); free(t->nome);
    scanf("%s",t->codice); fflush(stdin);
    printf("Nome: "); free(t->cognome);
    scanf("%s",temp); t->nome=strdup(temp);
    printf("Cognome: ");
    scanf("%s",temp); t->cognome=strdup(temp);
    printf("Data di nascita (gg/mm/aaaa): ");
    scanf("%s",t->data);
    return;
}
void ItemDestruction(item v){
    free(v->nome); free(v->cognome);
    v=v->next;
    if(v!=NULL)
        ItemDestruction(v);
    free(v);
    return;
}
