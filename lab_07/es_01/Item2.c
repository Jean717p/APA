#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item2.h"

void riempi2(link** v,int tail){
    printf("Inserisci stringa: "); fflush(stdin);
    gets(((*v)[tail])->frase);
    printf("Inserisci numero: ");
    scanf("%d",&((*v)[tail])->numero);
    return;
}
void scrivi2(link v){
    printf("%s ",v->frase);
    printf("%d\n",v->numero);
    return;
}
void incidi2(link v,FILE** fp){
    fprintf(*fp,"%s %d\n",v->frase,v->numero);
    return;
}
void load2(link* t,FILE** fp){
    fscanf(*fp,"%s",(*t)->frase);
    fscanf(*fp,"%d",&(*t)->numero);
    return;
}
