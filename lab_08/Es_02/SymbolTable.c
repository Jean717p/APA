#include <stdio.h>
#include <stdlib.h>
#include "SymbolTable.h"
#include "Item.h"
struct tavola{
    item head,tail; //indici di lista
};
table tav=NULL;
void inizzializza(FILE* fp){
    int i=0,N;
    tav=malloc(sizeof(struct tavola));
    tav->head=tav->tail=NULL;
    fscanf(fp,"%d",&N); //if N<=0 exit-4
    init(&fp,&tav->head,&tav->tail,tav->head,N,i);
    return;
}
void ricerca(){
    char codice[10+1]; item ris=NULL;
    printf("Inserisci (10 caratteri) codice chiave: ");
    fflush(stdin); scanf("%s",codice);
    ris=found(tav->head,tav->tail,NULL,codice);
    if(ris!=NULL)
        stampa(ris);
    return;
}
void stamp(){
    mainstampa(tav->head,tav->tail);
    return;
}
void ins(){
    inserisci(&tav->tail);
    return;
}
void del(){
    char codice[10+1];
    printf("Inserisci codice chiave per eliminare l'individuo associato: ");
    fflush(stdin); scanf("%s",codice);
    delit(&tav->head,tav->head,&tav->tail,tav->head,codice);
    return;
}
void mod(){
    char codice[10+1]; item ris=NULL;
    printf("Inserire codice chiave per modificare l'individuo associato: ");
    fflush(stdin); scanf("%s",codice);
    ris=found(tav->head,tav->tail,NULL,codice);
    if(ris!=NULL)
        itemmod(ris);
    return;
}
void distruggi(){
    ItemDestruction(tav->head);
    tav->head=tav->tail=NULL;
    return;
}
