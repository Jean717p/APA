#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main()
{
    FILE* fp=NULL;
    BST bst=NULL; char temp[30];
    int op=1;
    do{
        op=0;
        do{
            printf("\t\t***Menu'***\n");
            printf("Digita 1 per creare un nuovo BST(vuoto)\n");
            printf("Digita 2 per effettuare un inserimento in foglia\n");
            printf("Digita 3 per effettuare un inserimento in radice\n");
            printf("Digita 4 per ricercare un elemento nel BST\n");
            printf("Digita 5 per stampare gli elementi massimo e minimo\n");
            printf("Digita 6 per visualizzare gli elementi\n");
            printf("Digita 7 per calcolare l'altezza del BST\n");
            printf("Digita 8 per calcolare il numero totale di nodi\n");
            printf("Digita 9 per calcolare il numero di nodi foglia\n");
            printf("Digita 10 per salvare il BST su file\n");
            printf("Digita 11 per caricare un nuovo BST da file\n");
            printf("Digita 12 per uscire\n");
            scanf("%d",&op);
            fflush(stdin);
            if(op<1||op>12){
                printf("Operazione non valida.\n\n");
                op=0;
            }
        }while(op==0);
        switch(op){
            case 1: BSTdestruction(bst); bst=BSTinit(); break;
            case 2: BSTinsert_leafR(bst); break;
            case 3: BSTinsert_root(bst); break;
            case 4: printf("Inserire l'elemento da cercare: "); scanf("%d",&op);
                    BSTsearch(bst,op); op=4; break;
            case 5: BSTmin_max(bst); break;
            case 6: stampa(bst); break;
            case 7: BSTcount(bst); break;
            case 8: BSTnumnodi(bst); break;
            case 9: BSTnumfoglie(bst); break;
            case 10: fp=fopen("bstsave.txt","w"); BSTsave(bst,fp); fclose(fp); break;
            case 11: printf("Inserire il nome del file: "); gets(temp);
                     if((fp=fopen(temp,"r"))==NULL){
                        printf("File non trovato.\n");
                        break;}
                     BSTdestruction(bst);
                     bst=BSTinit();
                     BSTupload(bst,fp); break;
            default: BSTdestruction(bst); op=0;
        }
        system("PAUSE");
        system("cls");
    }while(op!=0);
    printf("\n\t\t\t*****Arrivederci!*****\n");
    return 0;
}
