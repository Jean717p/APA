#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"
#include "lib2.h"
#include "lib3.h"
#include "lib4.h"
void lista();
void pila();
void coda();
void codapremium();
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
                system("pause");
                system("cls");
                }
        }while(op==0);
        switch(op){
            case 1: lista();
                    break;
            case 2: pila();
                    break;
            case 3: coda();
                    break;
            case 4: codapremium();
                    break;
            default: op=0;
        }
    }while(op!=0);
    return 0;
}
void lista(){
    funzione1();
    system("cls");
    return;
}
void pila(){
    funzione2();
    system("cls");
    return;
}
void coda(){
    funzione3();
    system("cls");
    return;
}
void codapremium(){
    funzione4();
    system("cls");
    return;
}
