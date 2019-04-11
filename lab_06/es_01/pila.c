#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib2.h"
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

void menu2();

void funzione2(){
    link stud=NULL,head=NULL,tail=NULL;
    int op=0;
    system("cls");
    do{
        do{
            menu2();
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
        case 2: inseriscitesta(&stud,&head,&tail);
                break;
        case 3: exhead(&stud,&head,&tail); break;
        case 4: stampa(head); break;
        case 5: dealloc(&head);
                system("cls");
                break;
        }
    }while(op!=6);
    return;
}
void menu2(){
    printf("\t\t***Menu'***\n");
    printf("Digitare 1 per visualizzare la cardinalita' della pila\n");
    printf("Digitare 2 per inserire un elemento in testa\n");
    printf("Digitare 3 per estrarre un elemento dalla testa\n");
    printf("Digitare 4 per visualizzare la pila\n");
    printf("Digitare 5 per distruggere la pila\n");
    printf("Digitare 6 per uscire.\n");
    return;
}
