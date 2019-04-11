#include <stdio.h>
#include <stdlib.h>
typedef struct matr{
    int pos;
    int valore;
}matr;
void riempimatrici(FILE* fp,int ***matrice,matr ***vettR,int *r,int *c);
void accesso(int ***matrice,matr ***vettR,int c);
void stampa(int ***matrice,int r,int c,matr ***vettR);
void simmetria(int ***matrice,matr ***vettR,int r,int c);
int main(int argc,char* argv[])
{
    matr **vettR={NULL};
    int flag=0,op,**matrice={NULL},r,c;
    FILE* fp=NULL;
    if(argc!=2)exit(1);
    if((fp=fopen(argv[1],"r"))==NULL)exit(-1);
    riempimatrici(fp,&matrice,&vettR,&r,&c);
    fclose(fp);
    do{printf("\n\t***Menu'***\n\n");
    printf("\tPer accedere alla matrice digitare: 1\n");
    printf("\tPer verificare la simmetricità digitare: 2\n");
    printf("\tPer stampare la matrice digitare: 3\n");
    printf("\tPer uscire digitare: 4\n\n");
    scanf("%d",&op);
    switch(op){
    case 1: accesso(&matrice,&vettR,c); break;
    case 2: simmetria(&matrice,&vettR,r,c);
    case 3: stampa(&matrice,r,c,&vettR); break;
    case 4: flag=1; break;
    default: printf("Operazione non valida\n");
    }
    }while(flag==0);
    return 0;
}
void riempimatrici(FILE* fp,int ***matrice,matr ***vettR,int *r,int *c){
    int righe,colonne,i,j;
    if((fscanf(fp,"%d %d",&righe,&colonne))==EOF)exit(-2);
    if(righe<=0&&colonne<=0)exit(-3);
    (*matrice) =(int**) malloc(righe*sizeof(int*));
    (*vettR)=(matr**)malloc(righe*sizeof(matr*));
    for(i=0;i<righe;i++){
        (*matrice)[i] =(int*) malloc(colonne*sizeof(int));
        (*vettR)[i] =(matr*) malloc(colonne*sizeof(matr*));
        printf("\t");
        for(j=0;j<colonne;j++){
            fscanf(fp,"%d",&((*matrice)[i][j]));
            printf("%d ",(*matrice)[i][j]);
            (*vettR)[i][j].pos=j;
            (*vettR)[i][j].valore=((*matrice)[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<righe;i++){
        for(j=0;j<colonne;j++){
            if((*vettR)[i][j].valore!=0){
                printf("\tValore - %d\tPosizione <%d,%d>\n",(*vettR)[i][j].valore,i,(*vettR)[i][j].pos);
            }
        }
    }
    *r=righe; *c=colonne;
    return;
}
void stampa(int ***matrice,int righe,int colonne,matr ***vettR){
    int i,j; printf("\n\n");
    for(i=0;i<righe;i++){
        printf("\t");
        for(j=0;j<colonne;j++){
            printf("%d ",(*matrice)[i][j]);
        }
        printf("\n");
    }
    printf("\nVettore:\n");
    for(i=0;i<righe;i++){
        for(j=0;j<colonne;j++){
            if((*vettR)[i][j].valore!=0){
                printf("\tValore - %d\tPosizione <%d,%d>\n",(*vettR)[i][j].valore,i,(*vettR)[i][j].pos);
            }
        }
    }
    return;
}
void accesso(int ***matrice,matr ***vettR,int c){
    int i,j,op,flag=0;
    printf("Inserire l'elemnto in posizione <i,j> a cui accedere.\n");
    printf("i: "); scanf("%d",&i); printf("\n");
    printf("j: "); scanf("%d",&j); printf("\n");
    printf("Valore nella matrice <%d,%d>: %d",i,j,(*matrice)[i][j]);
    do{printf("Modificare il valore?\n1 -->si'\t\t2 -->no.\n");
        scanf("%d",&op);
        switch(op){
            case 1:     printf("Inserire il nuovo valore: ");
                        scanf("%d",&flag);
                        (*matrice)[i][j]=flag;
                        (*vettR)[i][j].valore=(*matrice)[i][j];
                        flag=1; break;
            case 2:     flag=1; break;
            default:    printf("Operazione non valida.\n");
        }
    }while(flag==0);
    return;
}
void simmetria(int ***matrice,matr ***vettR,int r,int c){
    int op,i,j,flag=0;
    do{printf("Verifca simmetria su:\n");
    printf("1 -->Matrice\t2 -->Vettore\t3 -->Annulla\n");
    scanf("%d",&op);
    switch(op){
        case 1: if(c!=r){flag=1; break;}
                for(i=0;i<r&&flag==0;i++){
                    for(j=0;j<c&&flag==0;j++){
                        if((*matrice)[i][j]!=(*matrice)[j][i]){
                            flag++; break;
                        }
                    }
                }
                if(flag==0)printf("La matrice e' simmetrica!\n");
                else printf("La matrice non e' simmetrica.\n");
                flag=1; break;
        case 2: if(c!=r){flag=1; break;}
                for(i=0;i<r&&flag==0;i++){
                    for(j=0;j<c&&flag==0;j++){
                        if(!(*vettR)[i][j].valore){
                            if((*vettR)[i][j].valore!=(*vettR)[j][i].valore)
                                flag=1;
                        }
                    }
                }
                if(flag==0)printf("Il vettore della matrice e' simmetrico!\n");
                else printf("Il vettore della matrice non e' simmetrico.\n");
                flag=1; break;
        case 3: flag=1; break;
        default: printf("Operazione non valida.\n");
    }
    }while(flag==0);
    return;
}
