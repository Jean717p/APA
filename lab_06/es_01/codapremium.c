#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib4.h"
#include "base.h"

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

void menu4();
void inseriscivip(link *stud,link *head,link *tail);
//void estraivipplus(link *stud,link *head,link *tail);

void funzione4(){
    link stud=NULL,head=NULL,tail=NULL;
    int op=0;
    system("cls");
    do{
        do{
            menu4();
            scanf("%d",&op);
            if(op<1||op>6){
                printf("Operazione non valida.\n\n");
                op=0;
                system("pause");
                system("cls");
            }
        }while(op==0);
        switch(op){
        case 1: stud=head;
                cardinalita(stud);
                break;
        case 2: inseriscivip(&stud,&head,&tail);
                break;
        case 3: exhead(&stud,&head,&tail);
                //estraivipplus(&stud,&head,&tail);
                break;
        case 4: stampa(head); break;
        case 5: dealloc(&head);
                system("cls");
                break;
        }
    }while(op!=6);
    return;
}
void menu4(){
    printf("\t\t***Menu'***\n");
    printf("Digitare 1 per visualizzare la cardinalita' della coda\n");
    printf("Digitare 2 per inserire un V.I.P.\n");
    printf("Digitare 3 per estrarre V.I.P. PLATINUM\n");
    printf("Digitare 4 per visualizzare la coda premium\n");
    printf("Digitare 5 per distruggere la coda premium\n");
    printf("Digitare 6 per uscire.\n");
    return;
}
void inseriscivip(link *stud,link *head,link *tail){
    link t=NULL,past=NULL; char temp[35+1];
    past=*stud=*head;
    if(*head==NULL){
        inseriscicoda(stud,head,tail);
    }
    else{
        t=malloc(sizeof (struct studente));
        printf("Inserire i dati dello studente\nNome: "); fflush(stdin);
        gets(temp); t->nome=strdup(temp); fflush(stdin);
        printf("Cognome: "); fflush(stdin); gets(temp); t->cognome=strdup(temp);
        printf("Matricola: "); fflush(stdin); gets(temp); t->matricola=strdup(temp);
        printf("Crediti: "); fflush(stdin); scanf("%d",&t->status.crediti);
        printf("Media: "); fflush(stdin); scanf("%f",&t->status.media);
        while((t->status.media)<=((*stud)->status.media)){
            past=(*stud);
            *stud=(*stud)->next;
            if(*stud==NULL)
                break;
        }
        if(*stud==NULL){
            t->next=NULL;
            *stud=past->next=t;
        }
        else if(past!=*head){
            t->next=*stud;
            past->next=*stud=t; //inutile *stud=t;
        }
        else{
            t->next=*head;
            *head=t;
        }
    }
    return;
}
//void estraivipplus(link *stud,link *head,link *tail){
//      non so se è disordinata o ordinata, in caso sia ordinata ho già finito
//    return;
//}
