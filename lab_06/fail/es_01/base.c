#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
typedef struct studente *Studente;
struct carriera{
	int crediti;
	float media;};
struct studente{
	char *nome;
	char *cognome;
	char *matricola;
	struct carriera status;
	Studente next;
};
void cardinalita(Studente stud){
    int count=0;
    while(stud!=NULL){
        count++;
        stud=stud->next;
    }
    printf("Cardinalita': %d\n",count);
    return;
}
void inserisci(Studente *stud,Studente *head,Studente *tail){
    char temp[35+1];
    *stud=*head;
    *head=NULL;
    *head=malloc(sizeof *stud);
    (*head)->next=*stud;
    *stud=*head;
    printf("Inserire i dati dello studente\nNome: ");
    fflush(stdin); gets(temp); (*stud)->nome=strdup(temp);
    printf("Cognome: "); gets(temp); (*stud)->cognome=strdup(temp);
    printf("Matricola: "); gets(temp); (*stud)->matricola=strdup(temp);
    printf("Crediti: "); scanf("%d",&((*stud)->status.crediti));
    printf("Media: "); scanf("%f",&(*stud)->status.media);
    return;
}
void inseriscicoda(Studente *stud,Studente *head,Studente *tail){
    char temp[35+1];
    if(*stud!=NULL){
            *stud=(*stud)->next;
            inseriscicoda(stud,head,tail);
        }
    else{
        *stud=malloc(sizeof *stud);
        (*stud)->next=NULL;
        printf("Inserire il nome dello studente: ");
        fflush(stdin); gets(temp); (*stud)->nome=strdup(temp);
        printf("Cognome: "); gets(temp); (*stud)->cognome=strdup(temp);
        printf("Matricola: "); gets(temp); (*stud)->matricola=strdup(temp);
        printf("Crediti: "); scanf("%d",&(*stud)->status.crediti);
        printf("Media: "); scanf("%f",&(*stud)->status.media);
        if(*head==NULL)
            *head = *tail = *stud; //primo elemento
        else
            (*tail)->next=*stud; *tail=*stud; //gli altri
        }
    return;
}
void stampa(Studente v){ //stampa
    if(v!=NULL){
        printf("%s %s %s ",v->nome,v->cognome,v->matricola);
        printf("%d %.2f\n",v->status.crediti,v->status.media);
        stampa(v->next);
    }
    return;
}
void dealloc(Studente *v,Studente *tail){ //deallocazione della memoria
    if(*v!=*tail){
        *v=(*v)->next;
        dealloc(v,tail);}
    (*v)->next=NULL;
    free((*v)->nome); free((*v)->cognome); free((*v)->matricola);
    free(*v);
    return;
}
