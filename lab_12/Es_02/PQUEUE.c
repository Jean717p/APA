#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "PQUEUE.h"

typedef struct nodo* link;

struct pqueue{
    link head,z;
    int heapsize;
};
struct nodo{
    item obj;
    link p,l,r;
    };

link NEW(item t,link p,link l,link r);
link insertR(link h,item x,link z);
link insertT(link h,item x,link z);
link rotR(link h);
link rotL(link h);
void stampapreorderR(link h,link z);
void Nodedestruction(link h,link z);

PQ PQUEUEinit(){
    PQ pq=malloc(sizeof(*pq));
    pq->head=(pq->z=NEW(NULL,NULL,NULL,NULL));
    pq->heapsize=0;
    return pq;
}
link NEW(item t,link p,link l,link r){
    link x=malloc(sizeof *x);
    x->obj=t; x->p=p; x->l=l; x->r=r;
    return x;
}
void PQUEUEnewinsert(PQ pq){
    item x=ITEMscan();
    pq->head=insertR(pq->head,x,pq->z);
    (pq->heapsize)++;
    return;
}
link insertR(link h,item x,link z){
    if(h==z)
        return NEW(x,z,z,z);
    if(ITEMless(h->obj,x)){
        h=insertT(h,x,z);
    }
    else if(h->l!=z){
        if(ITEMless(x,h->l->obj)){
            h->l=insertR(h->l,x,z);
            h->l->p=h;
        }
        else if(h->r!=z){
            if(ITEMless(x,h->r->obj)){
                h->r=insertR(h->r,x,z);
                h->r->p=h;
            }
            else
                h->r=insertT(h->r,x,z);
        }
        else
            h->r=NEW(x,z,z,z);
    }
    else
        h->l=NEW(x,z,z,z);
    return h;
}
link insertT(link h,item x,link z){
    if(h==z)
        return NEW(x,z,z,z);
    if(ITEMless(x,h->obj)){
        h->l=insertT(h->l,x,z);
        h=rotR(h);
    }
    else{
        h->r=insertT(h->r,x,z);
        h=rotL(h);
    }
    return h;
}
link rotR(link h){ //Ruota destro
    link x=h->l;
    h->l=x->r;
    x->r->p=h;
    x->r=h;
    x->p=h->p;
    h->p=x;
    return x;
}
link rotL(link h){ //Ruota sinistro
    link x=h->r;
    h->r=x->l;
    x->l->p=h;
    x->l=h;
    x->p=h->p;
    h->p=x;
    return x;
}
void PQUEUEextractMax(PQ pq){
    link r=pq->head->r,h=pq->head;
    if(pq->heapsize==0){
        printf("Coda vuota!\n");
        return;
    }
    if(r!=pq->z){
        if(h->l!=pq->z){
            while(r->l!=pq->z){
                if(ITEMless(r->l->obj,h->l->obj))
                    break;
                r=r->l;
            }
            if(r->l!=pq->z)
                h->l=insertR(h->l,r->l->obj,pq->z);
            r->l=h->l;
            h->l->p=r;
        }
        h->r->p=NULL;
        pq->head=h->r;
    }
    else{
        h->l->p=NULL;
        pq->head=h->l;
    }
    printf("Cliente: "); ITEMshow(h->obj);
    printf("Completato.\n");
    ITEMfree(h->obj);
    free(h);
    (pq->heapsize)--;
	return;
}
void PQUEUEprinf(PQ pq){
    if(pq->heapsize==0){
        printf("Coda vuota!\n");
        return;
    }
    printf("Numero elementi in coda: %d\n",pq->heapsize);
    stampapreorderR(pq->head,pq->z);
    return;
}
void stampapreorderR(link h,link z){
    if(h==z)
        return;
    ITEMshow(h->obj);
    stampapreorderR(h->r,z);
    stampapreorderR(h->l,z);
    return;
}
void PQUEUEupload(PQ pq,FILE* fp){
    int i,n=0; item x;
    ITEMcount(&n,fp);
    rewind(fp);
    for(i=0;i<n;i++){
        x=ITEMupload(fp);
        pq->head=insertR(pq->head,x,pq->z);
        ITEMshow(x);
        (pq->heapsize)++;
    }
    return;
}
void PQUEUEdestruction(PQ pq){
    if(pq!=NULL){
        Nodedestruction(pq->head,pq->z);
        free(pq->head);
        free(pq->z);
        free(pq);
    }
    return;
}
void Nodedestruction(link h,link z){
    if(h==z)
        return;
    Nodedestruction(h->l,z);
    Nodedestruction(h->r,z);
    ITEMfree(h->obj);
    free(h);
    return;
}

