#include <stdio.h>
#include <stdlib.h>
#include "SymbolTable.h"
#include "Item.h"
struct tavola{
    item *v; //vettore di item
    int N; //numero elementi
};
void quicksort(int,int);
int dicotomica(item*,int,char*);
table tav=NULL;
void inizzializza(FILE* fp){
    int i;
    tav=malloc(sizeof(struct tavola));
    fscanf(fp,"%d",&tav->N); //if N<=0 exit-4
    tav->v=malloc(tav->N*sizeof(item));
    for(i=0;i<tav->N;i++)
        tav->v[i]=init(&fp);
    quicksort(0,tav->N-1);
    return;
}
void quicksort(int left,int right){
    item temp; int j,i,pivot;
    if(left<right){
        i=pivot=left;
        j=right;
        while(i<j){
            while(i<=right&&itemlook(tav->v[i],tav->v[pivot])<0){
                i++;
            }
            while(itemlook(tav->v[j],tav->v[pivot])>0&&j>=left){
                j--;
            }
            if(i<j){
                if(i!=j){
                    temp=tav->v[i];
                    tav->v[i]=tav->v[j];
                    tav->v[j]=temp;
                }
            }
        }
        temp=tav->v[j];
        tav->v[j]=tav->v[pivot];
        tav->v[pivot]=temp;
        quicksort(left,j-1);
        quicksort(j+1,right);
    }
    return;
}
void ricerca(){
    char codice[10+1]; int trovato;
    printf("Inserisci (10 caratteri) codice chiave: ");
    fflush(stdin); scanf("%s",codice);
    trovato=dicotomica(tav->v,tav->N,codice);
    if(trovato!=-1){
        printf("L'individuo e' stato trovato alla posizione %d\n",trovato+1);
        stampa(tav->v[trovato]);
       }
    else
        printf("Individuo non trovato\n");
    return;
}
int dicotomica(item* v,int n,char codice[]){
    int sx=0,dx=n-1,md,trovato=0;
    while(sx<=dx&&trovato==0){
        md=(sx+dx)/2;
        if(itemdico(tav->v[md],codice)==0)
            trovato=1;
        else if(itemdico(tav->v[md],codice)<0)
            sx=md+1;
        else
            dx=md-1;
        }
    if(trovato)
        return md;
    else
        return -1;
}
void pr(){
    int i;
    for(i=0;i<tav->N;i++){
        stampa(tav->v[i]);
        printf("\n");
    }
    return;
}
void distruggi(){
    int i;
    for(i=0;i<tav->N;i++){
        ItemDestruction(tav->v[i]);
        free(tav->v[i]);
    }
    free(tav->v);
    free(tav);
    return;
}
