#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
typedef struct studente *link;
struct carriera{
    int crediti;
    float media;
    };
struct studente{
    char *nome;
    char *cognome;
    char *matricola;
    struct carriera status;
    link next;
    };

void cardinalita(link stud);
void inseriscitesta(link *stud,link *head,link *tail);
void inseriscicoda(link *stud,link *head,link *tail);
void stampa(link v);
void dealloc(link *testa);
void exhead(link *stud,link *head,link *tail);

void cardinalita(link stud){
    int count=0;
    while(stud!=NULL){
        count++;
        stud=stud->next;
    }
    printf("Cardinalita': %d\n",count);
    return;
}
void inseriscitesta(link *stud,link *head,link *tail){
    char temp[35+1]; link t;
    *stud=*head;
    if(*head!=NULL){
        t=malloc(sizeof (struct studente));
        printf("Inserire i dati dello studente\nNome: "); fflush(stdin);
        gets(temp); t->nome=strdup(temp); fflush(stdin);
        printf("Cognome: "); fflush(stdin); gets(temp); t->cognome=strdup(temp);
        printf("Matricola: "); fflush(stdin); gets(temp); t->matricola=strdup(temp);
        printf("Crediti: "); fflush(stdin); scanf("%d",&t->status.crediti);
        printf("Media: "); fflush(stdin); scanf("%f",&t->status.media);
        t->next=*head;
        *head=t;
    }
    else{
        inseriscicoda(stud,head,tail);
    }
    return;
}
void inseriscicoda(link *stud,link *head,link *tail){
    char temp[35+1];
    if(*stud!=NULL){
        *stud=(*stud)->next;
        inseriscicoda(stud,head,tail);
        }
    else{
        *stud=malloc(sizeof (struct studente));
        (*stud)->next=NULL;
        printf("Inserire i dati dello studente\n");
        printf("Nome: ");
        fflush(stdin); gets(temp); (*stud)->nome=strdup(temp);
        printf("Cognome: "); fflush(stdin); gets(temp); (*stud)->cognome=strdup(temp);
        printf("Matricola: "); fflush(stdin); gets(temp); (*stud)->matricola=strdup(temp);
        printf("Crediti: "); fflush(stdin); scanf("%d",&(*stud)->status.crediti);
        printf("Media: "); fflush(stdin); scanf("%f",&(*stud)->status.media);
        if(*head==NULL)
            *head = *tail = *stud; //primo elemento
        else
            (*tail)->next=*stud; *tail=*stud; //gli altri
        }
    return;
}
void stampa(link v){ //stampa
    if(v!=NULL){
        printf("%s %s %s ",v->nome,v->cognome,v->matricola);
        printf("Crediti: %d  Media: %.2f\n",v->status.crediti,v->status.media);
        stampa(v->next);
    }
    return;
}
void dealloc(struct studente **testa){
    link temp;
    if(*testa==NULL)
    {
        printf("Elenco vuoto\n");
        return;
    }
    while((*testa)!=NULL)
    {
        temp=(*testa);
        free((*testa)->nome); free((*testa)->cognome); free((*testa)->matricola);
        *testa=(*testa)->next;
        free(temp);
    }
}
void exhead(link *stud,link *head,link *tail){
    link t=*head;
    if(*head==NULL)
        return;
    if(*head==*tail)
        dealloc(head);
    else{
        *stud=*head=(*head)->next;
        free(t->nome); free(t->cognome); free(t->matricola);
        free(t);
        t=(*head);
    }
    return;
}
