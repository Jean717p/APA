#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib1.h"
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

void menu1();
void ricerca(link stud,link head);
void estrarre(link *stud,link *head,link *tail);

void funzione1(){
    link stud=NULL,head=NULL,tail=NULL;
    int op=0;
    system("cls");
    do{
        do{
            menu1();
            scanf("%d",&op);
            if(op<1||op>8){
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
        case 2: inseriscitesta(&stud,&head,&tail);
                break;
        case 3: stud=head;
                inseriscicoda(&stud,&head,&tail);
                break;
        case 4: ricerca(stud,head); break;
        case 5: estrarre(&stud,&head,&tail); break;
        case 6: stampa(head); break;
        case 7: dealloc(&head);
                //if(head!=NULL){
//                    stud=head; dealloc(&stud,&tail); dealloc(&head,&head);}
                system("cls");
                break;
        }
    }while(op!=8);
    return;
}
void menu1(){
    printf("\t\t***Menu'***\n");
    printf("Digitare 1 per visualizzare la cardinalita' della lista\n");
    printf("Digitare 2 per inserire un elemento in testa\n");
    printf("Digitare 3 per inserire un elemento in coda\n");
    printf("Digitare 4 per ricercare un elemento attraverso una keyword\n");
    printf("Digitare 5 per estrarre un elemento attraverso una keyword\n");
    printf("Digitare 6 per visualizzare la lista\n");
    printf("Digitare 7 per distruggere la lista\n");
    printf("Digitare 8 per uscire.\n");
}
void ricerca(link stud,link head){
    int ap=0,flag=0; char temp[35+1];
    stud=head;
    if(head==NULL)
        return;
    do{
        printf("Digitare il campo di ricerca:\n");
        printf("1 per nome\n2 per cognome\n3 per matricola\n");
        scanf("%d",&ap);
        if(ap<1||ap>3)
            ap=0;
    }while(ap==0);
    printf("Inserire keyword: "); fflush(stdin); gets(temp);
    while(stud!=NULL){
        flag=0;
        if(ap==1){
            if(strcmp(stud->nome,temp)==0){
                flag=1;
            }
        }
        else if(ap==2){
            if(strcmp(stud->cognome,temp)==0){
                flag=1;
            }
        }
        else{
            if(strcmp(stud->matricola,temp)==0){
                flag=1;
            }
        }
        if(flag==1){
            printf("%s %s %s ",stud->nome,stud->cognome,stud->matricola);
            printf("Crediti: %d  Media: %.2f\n",stud->status.crediti,stud->status.media);
        }
        stud=stud->next;
    }
    return;
}
void estrarre(link *stud,link *head,link *tail){
    int ap=0,flag=0; char temp[35+1]; link t;
    (*stud)=t=(*head); //t=malloc(sizeof(link));
    if(*head==NULL)
        return;
    do{
        printf("Digitare il campo di ricerca:\n");
        printf("1 per nome\n2 per cognome\n3 per matricola\n");
        scanf("%d",&ap);
        if(ap<1||ap>3)
            ap=0;
    }while(ap==0);
    printf("Inserire keyword: "); fflush(stdin); gets(temp);
    while(*stud!=NULL){
        flag=0;
        if(ap==1){
            if(strcmp((*stud)->nome,temp)==0){
                flag=1;
            }
        }
        else if(ap==2){
            if(strcmp((*stud)->cognome,temp)==0){
                flag=1;
            }
        }
        else{
            if(strcmp((*stud)->matricola,temp)==0){
                flag=1;
            }
        }
        if(flag==1){
            if(*stud==*head){
                *head=*stud=(*stud)->next;
            }
            else{
                (*stud)=t;
                t=t->next;
                (*stud)=(*stud)->next=t->next;
            }
            free(t->nome); free(t->cognome); free(t->matricola);
            free(t);
            t=(*stud);
        }
        else{
            t=(*stud);
            *stud=(*stud)->next;
        }
    }
    return;
}
