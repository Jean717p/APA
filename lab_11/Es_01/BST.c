#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "BST.h"

typedef struct BSTnodo* link;

struct BSTnodo{
    item obj;
    link p,l,r;
    int N; //Numero figli
    };

struct alberodiricercabinario{
    link head,z;
    int N; //Altezza totale albero
    };

item NULLitem=NULL;

link NEW(item t,link p,link l,link r,int N);
item minR(link h, link z);
item maxR(link h, link z);
item searchR(link h,int t,link z);
link insertR(link h,item x,link z);
link insertT(link h,item x,link z);
link rotR(link h);
link rotL(link h);
void stampainorderR(link h,link z);
void stampapostorderR(link h,link z);
void stampapreorderR(link h,link z);
int height(link h, link z);
void contafoglie(link h,link z,int* foglie);
void BSTscrivi(link h,link z,FILE* fp);
void Nodedestruction(link h,link z);

BST BSTinit(){ //Inizializzazione albero
    BST bst=malloc(sizeof *bst) ;
    bst->N=0;
    bst->head=(bst->z=NEW(NULLitem,NULL,NULL,NULL,0));
    return bst;
}
link NEW(item t,link p,link l,link r,int N){
    link x=malloc(sizeof *x);
    x->obj=t; x->p=p; x->l=l; x->r=r; x->N=N;
    return x;
}
void BSTmin_max(BST bst){ //Trovare minimo
    item t=minR(bst->head,bst->z);
    printf("Minimo: ");
    ITEMshow(t);
    t=maxR(bst->head,bst->z);
    printf("Massimo: ");
    ITEMshow(t);
    return;
}
item minR(link h, link z){ //ricerca minimo
    if(h==z)
        return NULLitem;
    if(h->l==z)
        return (h->obj);
    return minR(h->l,z);
}
item maxR(link h, link z){
    if(h==z)
        return NULLitem;
    if (h->r==z)
        return (h->obj);
    return maxR(h->r, z);
}
void BSTsearch(BST bst,int t){ //Ricerca
    item x=searchR(bst->head,t,bst->z);
    if(x!=NULLitem){
        printf("Elemento trovato!\n");
        ITEMshow(x);}
    else
        printf("Elemento non trovato.\n");
    return;
}
item searchR(link h,int t,link z){
    if(h==z)
        return NULLitem;
    if(eq(t,h->obj)==1)
        return h->obj;
    if(less(t,h->obj)==1)
        return searchR(h->l,t,z);
    else
        return searchR(h->r,t,z);
  }
void BSTinsert_leafR(BST bst){ //Inserimento in foglia ricorsivo
    item x=ITEMscan();
    bst->head=insertR(bst->head,x,bst->z);
    (bst->N)++;
}
link insertR(link h,item x,link z){
    if(h==z)
        return NEW(x,z,z,z,1);
    if(ITEMless(x,h->obj)){
        h->l=insertR(h->l,x,z);
        h->l->p=h;
    }
    else{
        h->r=insertR(h->r,x,z);
        h->r->p=h;
    }
    (h->N)++;
    return h;
}
void BSTinsert_root(BST bst){ //Inserimento in radice ricorsivo
    item x=ITEMscan();
    bst->head = insertT(bst->head,x,bst->z);
    (bst->N)++;
}
link insertT(link h,item x,link z){
    if(h==z)
        return NEW(x,z,z,z,1);
    if(ITEMless(x,h->obj)){
        h->l=insertT(h->l,x,z);
        h=rotR(h);
        (h->N)++;
    }
    else{
        h->r=insertT(h->r, x, z);
        h=rotL(h);
        (h->N)++;
    }
    return h;
}
link rotR(link h){ //Ruota destro
    link x = h->l;
    h->l = x->r;
    x->r->p = h;
    x->r = h;
    x->p = h->p;
    h->p = x;
    x->N = h->N;
    h->N = h->r->N + h->l->N +1;
    return x;
}
link rotL(link h){ //Ruota sinistro
    link x = h->r;
    h->r = x->l;
    x->l->p = h;
    x->l = h;
    x->p = h->p;
    h->p = x;
    x->N = h->N;
    h->N = h->l->N + h->r->N +1;
    return x;
}
void stampa(BST bst){
    int t=0;
    do{
        printf("Stampa in:\n1 Inorder\n2 Postorder\n3 Preorder\n4 Annulla\n");
        scanf("%d",&t);
        if(t<1||t>4){
            printf("Operazione non valida.\n"); t=0;}
    }while(t==0);
    switch(t){
        case 1: stampainorderR(bst->head,bst->z); break;
        case 2: stampapostorderR(bst->head,bst->z); break;
        case 3: stampapreorderR(bst->head,bst->z); break;
    }
    return;
}
void stampainorderR(link h,link z){
    if(h==z)
        return;
    stampainorderR(h->l,z);
    ITEMshow(h->obj);
    stampainorderR(h->r,z);
    return;
}
void stampapostorderR(link h,link z){
    if(h==z)
        return;
    stampapostorderR(h->l,z);
    stampapostorderR(h->r,z);
    ITEMshow(h->obj);
    return;
}
void stampapreorderR(link h,link z){
    if(h==z)
        return;
    ITEMshow(h->obj);
    stampapreorderR(h->l,z);
    stampapreorderR(h->r,z);
    return;
}
void BSTcount(BST bst){ //Altezza albero
    int altezza=height(bst->head,bst->z);
    printf("Altezza BST: %d\n",altezza);
}
int height(link h, link z){
    int u,v;
    if(h==z)
        return -1;
    u=height(h->l,z); v=height(h->r,z);
    if(u>v)
        return u+1;
    else
        return v+1;
}
void BSTnumnodi(BST bst){ //Numero nodi
    printf("Numero nodi: %d\n",bst->N);
    return;
}
void BSTnumfoglie(BST bst){ //Numero foglie
    int foglie=0;
    contafoglie(bst->head,bst->z,&foglie);
    printf("Numero foglie: %d\n",foglie);
    return;
}
void contafoglie(link h,link z,int* foglie){
    if(h==z){
        return;
    }
    contafoglie(h->l,z,foglie);
    contafoglie(h->r,z,foglie);
    if(h->r==z&&h->l==z)
        (*foglie)++;
    return;
}
void BSTsave(BST bst,FILE* fp){
    BSTscrivi(bst->head,bst->z,fp);
    return;
    }
void BSTscrivi(link h,link z,FILE* fp){
    if(h==z)
        return;
    ITEMwrite(h->obj,fp);
    BSTscrivi(h->l,z,fp);
    BSTscrivi(h->r,z,fp);
    return;
}
void BSTupload(BST bst,FILE* fp){
    int i,n=0; item x;
    ITEMcount(&n,fp);
    rewind(fp);
    for(i=0,bst->N=n;i<n;i++){
        x=ITEMupload(fp);
        bst->head=insertR(bst->head,x,bst->z);
        ITEMshow(x);
    }
    return;
}
void BSTdestruction(BST bst){
    if(bst!=NULL){
        Nodedestruction(bst->head,bst->z);
        free(bst->head);
        free(bst->z);
        free(bst);
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
