#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc,char* argv[])
{
    int op=1,w;
    if(argc!=2)
        exit(-1);
    Graph G=GRAPHinit(argv[1]);
    do{
        op=0;
        do{
            printf("\t\t***Menu'***\n");
            printf("Digita 1 per calcolare il cammino semplice minimo dati due vertici\n");
            printf("Digita 2 per calcolare il cammino semplice massimo dati due vertici\n");
            printf("Digita 3 per calcolare il numero di cammini semplici dati due vertici\n");
            printf("Digita 4 per calcolare le componenti fortemente connesse\n");
            printf("Digita 5 per individuare il numero minimo di archi per rendere il grafo SCC\n");
            printf("Digita 6 per visualizzare i vertici e i rispettivi archi\n");
            printf("Digita 7 per uscire\n");
            scanf("%d",&op);
            fflush(stdin);
            if(op<1||op>7){
                printf("Operazione non valida.\n\n");
                op=0;
            }
        }while(op==0);
        switch(op){
            case 1: printf("Inserire i nodi di 'partenza arrivo': "); scanf("%d %d",&op,&w);
                    GRAPHlinkMIN(G,op,w); op=1; break;
            case 2: printf("Inserire i nodi di 'partenza arrivo': "); scanf("%d %d",&op,&w);
                    GRAPHlinkMAX(G,op,w); op=2; break;
            case 3: printf("Inserire i nodi di 'partenza arrivo': "); scanf("%d %d",&op,&w);
                    GRAPHlinkTOT(G,op,w); op=3; break;
            case 4: GRAPHscc(G); break;
            case 5:  break;
            case 6: GRAPHshow(G); break;
            default:  op=0;
        }
        system("PAUSE");
        system("cls");
    }while(op!=0);
    printf("\n\t\t\t*****Arrivederci!*****\n");
    return 0;
}
