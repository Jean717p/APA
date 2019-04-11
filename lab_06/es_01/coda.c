#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib3.h"
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

void menu3();

void funzione3(){
    link stud=NULL,head=NULL,tail=NULL;
    int op=0;
    system("cls");
    do{
        do{
            menu3();
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
        case 2: inseriscicoda(&stud,&head,&tail);
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
void menu3(){
    printf("\t\t***Menu'***\n");
    printf("Digitare 1 per visualizzare la cardinalita' della coda\n");
    printf("Digitare 2 per inserire un elemento in coda\n");
    printf("Digitare 3 per estrarre un elemento dalla testa\n");
    printf("Digitare 4 per visualizzare la coda\n");
    printf("Digitare 5 per distruggere la coda\n");
    printf("Digitare 6 per uscire.\n");
    return;
}
