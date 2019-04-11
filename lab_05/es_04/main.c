#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct attesasala* link;
typedef struct attesasala{
    char pers[10+1];
    link next;
}attesa;
void agg(link *v,link *head,link *tail);
void ext(link *v,link *head,link *tail);
void stampa(link v);
void dealloc(link *v,link *head,link *tail);
int main()
{
    link v=NULL,head=NULL,tail=NULL;
    int op=1;
    while(op!=0){
        do{printf("\n\t\t\t***Menu'***\n"); //menù
        printf("Digita 1 per aggiungere una persona in fondo alla fila\n");
        printf("Digita 2 per estrarre una persona dall'inizio della fila\n");
        printf("Digita 3 per stampare l'elenco di persone in attesa dal primo all'ultimo\n");
        printf("Digita 4 per uscire.\n");
        scanf("%d",&op);
        if(op>4||op<=0){
            printf("Inserimento non valido.\n");
            op=0;}
        }while(op==0);
        switch(op){
            case 1: printf("Inserire codice persona(es: GVNRSS1967): ");
                    agg(&v,&head,&tail);
                    break;
            case 2: ext(&v,&head,&tail);
                    break;
            case 3: if(head==NULL)
                        printf("Lista vuota.\n");
                    else{
                        v=head;
                        stampa(v);}
                    break;
            default: op=0;
        }
    }
    if(v!=NULL)
    dealloc(&v,&head,&tail);
    return 0;
}
void agg(link *v,link *head,link *tail){
    //if(*tail==NULL){
        if(*v!=NULL){
            *v=(*v)->next;
            agg(v,head,tail);
        }
        else{
            *v=malloc(sizeof *v);
            (*v)->next=NULL;
            fflush(stdin); gets((*v)->pers);
            if(*head==NULL)
                *head = *tail = *v; //primo elemento
            else
                (*tail)->next=*v; *tail=*v; //gli altri
        }
    /*}
    else{ //era per non ciclare sempre ma mi dava errori
        *v = *tail;
        *v=(*v)->next;
        *v=malloc(sizeof *v);
        (*v)->next=NULL;
        fflush(stdin); gets((*v)->pers);
        *tail = *v;
    }*/
    return;
}
void ext(link *v,link *head,link *tail){ //estrazione
    if(*head==NULL){ //se è vuota
        printf("Fila vuota.\n");
    }
    else if(*head==*tail){ //in caso ci sia solo uno
        free(*head);
        *head = *tail = *v = NULL;
    }
    else{ //gli altri casi
        *v = *head;
        *head = (*head)->next;
        free(*v);
        *v=*head;
    }
    return;
}
void stampa(link v){ //stampa
    if(v!=NULL){
        printf("%s\n",v->pers);
        stampa(v->next);
    }
    return;
}
void dealloc(link *v,link *head,link *tail){ //deallocazione della memoria
    if(*v!=*tail){
        *v=(*v)->next;
        dealloc(v,head,tail);}
    (*v)->next=NULL;
    free(*v);
    return;
}
