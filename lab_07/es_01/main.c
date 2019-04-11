#include <stdio.h>
#include <stdlib.h>
#include "Fifo.h"
#include "Item.h" //ADT first class
//#include "Item2.h" //Quasi ADT
#define N 35+1
void menu();
int main()
{
    int op=0;
    do{
        do{
            menu();
            scanf("%d",&op);
            if(op<1||op>9){
                op=0;
                printf("Operazione errata\n");
                system("PAUSE"); system("cls");
            }
        }while(op==0);
        switch(op){
            case 1: crea();
                    break;
            case 2: cardinalita();
                    break;
            case 3: inserisci();
                    break;
            case 4: estrai();
                    break;
            case 5: stampa();
                    break;
            case 6: save();
                    break;
            case 7: upload();
                    break;
            case 8: distruggi();
                    break;
            default: op=0;
        }
        system("PAUSE"); system("cls");
    }while(op!=0);
    return 0;
}

void menu(){
    printf("\t\t***Menu'***\n");
    printf("Digita 1 per creare una nuova coda\n");
    printf("Digita 2 per stampare il numero di dati in coda\n");
    printf("Digita 3 per inserire un nuovo elemento in coda\n");
    printf("Digita 4 per estrarre un elemento dalla coda\n");
    printf("Digita 5 per visualizzare la coda\n");
    printf("Digita 6 per salvare la coda su file\n");
    printf("Digita 7 per caricare una coda da file\n");
    printf("Digita 8 per distruggere la coda\n");
    printf("Digita 9 per uscire.\n");
}
