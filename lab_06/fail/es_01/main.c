#include <stdio.h>
#include <stdlib.h>
#include "base.h"
void lista();
int main()
{
    int op=0;
    do{
        do{
        printf("\t\t***Menu'***\n");
        printf("Digitare 1 per gestire una lista (disordinata)\n");
        printf("Digitare 2 per gestire una pila\n");
        printf("Digitare 3 per gestire una coda\n");
        printf("Digitare 4 per gestire una coda premium\n");
        printf("Digitare 5 per uscire.\n");
        scanf("%d",&op);
        if(op<1||op>5){
            printf("Operazione non valida.\n\n");
            op=0;
            }
        }while(op==0);
        switch(op){
            case 1: lista();
                    break;
            case 2:
            case 3:
            case 4:
            default: op=0;
        }
    }while(op==0);
    return 0;
}
void lista(){
#include "lib1.h"
    Studente stud=NULL,head=NULL,tail=NULL;
    int op=0;
    printf("\n");
    do{
        do{
            menu1();
            scanf("%d",&op);
            if(op<1||op>8){
                printf("Operazione non valida.\n\n");
                op=0;
            }
        }while(op==0);
        scelta1(op,&stud,&head,&tail);
    }while(op!=8);
    //printf("%s",stud->nome);
    return;
}
