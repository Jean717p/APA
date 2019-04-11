#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc,char* argv[])
{
    int op=1;
    if(argc!=2)
        exit(-1);
    Graph G=GRAPHinit(argv[1]);
    do{
        op=0;
        do{
            printf("\t\t***Menu'***\n");
            printf("Digita 1 per visualizzare il grado di ogni nodo\n");
            printf("Digita 2 per visualizzare le citta'\n");
            printf("Digita 3 per visualizzare il numero di collegamenti di una citta'\n");
            printf("Digita 4 per generare la matrice di adiacenza\n");
            printf("Digita 5 per visualizzare i flussi intraregionali ed interregionali globali\n");
            printf("Digita 6 per uscire\n");
            scanf("%d",&op);
            fflush(stdin);
            if(op<1||op>6){
                printf("Operazione non valida.\n\n");
                op=0;
            }
        }while(op==0);
        switch(op){
            case 1: GRAPHgradenodeshow(G); break;
            case 2: GRAPHcityshow(G); break;
            case 3: printf("Inserire il nodo da visualizzare: "); scanf("%d",&op);
                    GRAPHnexttonode(G,op); op=3; break;
            case 4: GRAPHmatrgen(G); break;
            case 5: GRAPHflux(G); break;
            default:  op=0;
        }
        system("PAUSE");
        system("cls");
    }while(op!=0);
    printf("\n\t\t\t*****Arrivederci!*****\n");
    return 0;
}
