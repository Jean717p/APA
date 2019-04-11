#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SymbolTable.h"

int main(int argc,char* argv[])
{
    FILE* fp=NULL; int op=-1;
    if(argc!=2)
        exit(-1);
    if((fp=fopen(argv[1],"r"))==NULL)
        exit(-2);
    inizzializza(fp);
    fclose(fp);
    do{
        do{
            op=0;
            printf("\t\t***Menu'***\n");
            printf("Digita 1 per effettuare una ricerca\n");
            printf("Digita 2 per visualizzare l'elenco\n");
            printf("Digita 3 per inserire un nuovo individuo\n");
            printf("Digita 4 per eliminare un individuo\n");
            printf("Digita 5 per modificare un profilo\n");
            printf("Digita 6 per cancellare la tabella ed uscire.\n");
            scanf("%d",&op);
            fflush(stdin);
            if(op<1||op>6){
                printf("Operazione non valida.\n\n");
                op=0;
            }
        }while(op==0);
        switch(op){
            case 1: ricerca(); break;
            case 2: stamp(); break;
            case 3: ins(); break;
            case 4: del(); break;
            case 5: mod(); break;
            default: distruggi(); op=0;
        }
        system("PAUSE");
        system("cls");
    }while(op!=0);
    printf("\n\t\t\t*****Arrivederci!*****\n");
    return 0;
}
