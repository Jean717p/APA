#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
/*****Symbol Table with Linear Chaining*****/
typedef struct nodoST* link;
struct dati{
    char *id,*nome,*cognome,*cat;
    int datatot,duratatot,n_conn;
};
struct nodoST{
    sobj item;
    link next;
};
struct st{
    link *heads; link z;
    int M;
};

int key(char v[],int M);

link NEW(sobj item,link next){
    link h=malloc(sizeof(*h));
    h->item=item;
    h->next=next;
    return h;
}
sytab STinit(int n_clienti){
    int i;
    sytab st=malloc(sizeof(*st));
    st->M=((n_clienti*2)+1)/5;
    st->heads=malloc(st->M*sizeof(link));
    st->z=NEW(NULL,NULL);
    for(i=0;i<st->M;i++){
        st->heads[i]=st->z;
    }
    return st;
}
char** getdata(sytab st,FILE* fp,int n_clienti,char** cat){
    char temp[MAX],**cl; int i,j,k;
    sobj* x=malloc(n_clienti*sizeof(*x));
    cl=malloc(n_clienti*sizeof(char*));
    for(i=0;i<n_clienti;i++)
        cat[i]=NULL;
    for(i=k=0;i<n_clienti;i++){
        x[i]=malloc(sizeof(**x));
        fscanf(fp,"%s",temp); x[i]->id=cl[i]=strdup(temp);
        fscanf(fp,"%s",temp); x[i]->nome=strdup(temp);
        fscanf(fp,"%s",temp); x[i]->cognome=strdup(temp);
        fscanf(fp,"%s",temp); x[i]->cat=strdup(temp);
        x[i]->datatot=x[i]->n_conn=x[i]->duratatot=0;
        j=key(cl[i],st->M);
        st->heads[j]=NEW(x[i],st->heads[j]);
        for(j=0;j<k;j++){
            if(strcmp(temp,cat[j])==0)
                break;
        }
        if(j==k)
            cat[k++]=x[i]->cat;
    }
    return cl;
}
int key(char v[],int M){
    int h=0,base=127,i;
    for(i=0;v[i]!='\0';i++)
        h=(base*h+v[i])%M;
    return h;
}
void getfile2(sytab st,FILE* fp){
    int data,durata,t; char temp[MAX]; link appoggio=NULL;
    while((fscanf(fp,"%s %d %d",temp,&data,&durata))!=EOF){
        t=key(temp,st->M); appoggio=st->heads[t];
        while(appoggio!=st->z){
            if(strcmp(appoggio->item->id,temp)==0){
                appoggio->item->datatot+=data;
                appoggio->item->duratatot+=durata;
                appoggio->item->n_conn+=1;
            }
            appoggio=appoggio->next;
        }
    }
    return;
}
void scrivipercat(sytab st,char** cat,FILE* f1,FILE* f2){
    int i=0,j,data; link temp;
    while(cat[i]!=NULL){
        fprintf(f1,"%s:\n",cat[i]);
        fprintf(f2,"%s:\n",cat[i]);
        for(j=data=0;j<st->M;j++){
            temp=st->heads[j];
            while(temp!=st->z){
                if((strcmp(cat[i],temp->item->cat))==0){
                    data+=temp->item->datatot;
                    fprintf(f2,"%s %s %s\n",temp->item->id,temp->item->nome,temp->item->cognome);
                }
                temp=temp->next;
            }
        }
        fprintf(f1,"%d KB\n_________\n",data);
        fprintf(f2,"_________________________________\n");
        i++;
    }
    return;
}
void STprintdata(sytab st,FILE* fp,char *v){ //Scrivi dati per ogni cliente
    int t=key(v,st->M); link temp;
    temp=st->heads[t];
    while(temp!=st->z){
        if(strcmp(temp->item->id,v)==0) //In caso di collisioni controllo che sia l'id corretto
            fprintf(fp,"%s - %d accessi - %dKB - %d secondi\n",temp->item->id,temp->item->n_conn,temp->item->datatot,temp->item->duratatot);
        temp=temp->next;
    }
    return;
}
