#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fifo.h"
#include "Item.h"
//#include "Item2.h" //Quasi ADT
static int n=0,head=-1,tail=-1;
static link* v=NULL;

void crea(){
    link t=NULL; int count;
    if(n!=0){
        printf("La coda e' gia' stata creata.\nDistruggere prima la coda precedente.\n");
        return;
    }
    head=tail=-1;
    printf("Inserire il numero massimo di elementi della coda: ");
    scanf("%d",&(n));
    v=(link*)malloc(n*sizeof(link));
    for(count=0;count<n;count++){
        //t=malloc(sizeof(item)); Quasi ADT
        make(&t); //ADT first class
        v[count]=t;
    }
    return;
}
void cardinalita(){
    int i,count=0;
    if(n==0){
        printf("Coda inesistente.\n");
        return;
    }
    else if(head==-1){
        printf("Coda vuota.\n");
        return;
    }
    if(tail>=head){
        for(i=head;i<=tail;i++){
            count++;
        }
    }
    else{
        for(i=head;i<n;i++){
            count++;
        }
        for(i=0;i<tail;i++){
            count++;
        }
    }
    printf("Cardinalita': %d\n",count);
    return;
}

void inserisci(){
    if(n==0){
        printf("Coda inesistente.\n");
        return;
    }
    if(tail>=head){
        if((tail+1)<n){
            tail+=1;
            riempi(&v,tail); //riempi2(v,*tail); //Quasi ADT
        }
        else if(head>0){
            tail=0;
            riempi(&v,tail); //riempi2(v,*tail); //Quasi ADT
        }
        else{
            printf("Coda piena\n");
            return;
        }
    }
    else if((tail+1)<head){
        tail+=1;
        riempi(&v,tail); //riempi2(v,*tail); //Quasi ADT
    }
    else{
        printf("Coda piena\n");
    }
    if(tail==0&&head==-1)
        head=0;
    return;
}

void estrai(){
    if(n==0){
        printf("Coda inesistente.\n");
        return;
    }
    else if(head==-1){
        printf("Coda vuota.\n");
        return;
    } //Per il Quasi ADT commenta //ex();
    ex(&v,head); //ADT first class
    if(head==tail)
        head=tail=-1;
    else if((head+1)<n)
        head+=1;
    else
        head=0;
    return;
}

void stampa(){
    int i;
    if(n==0){
        printf("Coda inesistente.\n");
        return;
    }
    else if(head==-1){
        printf("Coda vuota.\n");
        return;
    }
    if(tail>=head){
        for(i=head;i<=tail;i++){
            //printf("%s %d\n",v[i]->frase,v[i]->numero); //Quasi ADT
            scrivi(v[i]); //ADT first class
        } //scrivi2(v[i]); //Quasi ADT
    }
    else{
        for(i=head;i<n;i++){
            //printf("%s %d\n",v[i]->frase,v[i]->numero); //Quasi ADT
            scrivi(v[i]); //ADT first class
        } //scrivi2(v[i]); //Quasi ADT
        for(i=0;i<=tail;i++){
            //printf("%s %d\n",v[i]->frase,v[i]->numero); //Quasi ADT
            scrivi(v[i]); //ADT first class
        } //scrivi2(v[i]); //Quasi ADT
    }
    return;
}

void save(){
    FILE* fp=NULL; char temp[N]; int i;
    if(n==0){
        printf("Coda inesistente.\n");
        return;
    }
    else if(head==-1){
        printf("Attenzione coda vuota!\n");
        return;
    }
    printf("Inserire il nome del file.txt: ");
    fflush(stdin); gets(temp);
    fp=fopen(temp,"wt");
    if(tail>=head){ //numero elementi in coda
        i=tail-head;}
    else{
        i=n-head+tail;}
    fprintf(fp,"%d %d\n",n,i);
    if(tail>=head){
        for(i=head;i<=tail;i++){
            incidi(v[i],&fp); //ADT first class
        } //incidi2(v[i],&fp); //Quasi ADT
    }
    else{
        for(i=head;i<n;i++){
            incidi(v[i],&fp); //ADT first class
        } //incidi2(v[i],&fp); //Quasi ADT
        for(i=0;i<=tail;i++){
            incidi(v[i],&fp); //ADT first class
        } //incidi2(v[i],&fp); //Quasi ADT
    }
    fclose(fp);
    return;
}

void upload(){
    FILE* fp=NULL; link t=NULL; int count; char temp[N];
    if(n!=0){
        printf("E' già in esecuzione un'altra coda.\n");
        printf("Distruggere la coda in esecuzione per caricarne un'altra.\n");
        return;
    }
    printf("Inserire il nome del file: ");
    fflush(stdin); gets(temp);
    if((fp=fopen(temp,"r"))==NULL){
        printf("File non trovato.\n");
        return;
    }
    fscanf(fp,"%d %d",&n,&count);
    if(n<=0){
        n=0;
        head=tail=-1;
        return;
    }
    head=0; tail=count;
    v=malloc(n*sizeof(link));
    for(count=0;count<n;count++){
        //t=malloc(sizeof(item)); Quasi ADT
        make(&t); //ADT first class
        load(&t,&fp); //riempio i campi dal file
        v[count]=t;
    } //load2(&t,&fp); //Quasi ADT
    fclose(fp);
    return;
}

void distruggi(){
    link t=NULL; int count;
    if(n==0){
        printf("Coda inesistente.\n");
        return;}
    for(count=0;count<n;count++){
        t=v[count];
        libera(&t); //Non serve per il Quasi ADT
        free(t);
    }
    free(v);
    n=0;
    tail=head=-1;
    return;
}
