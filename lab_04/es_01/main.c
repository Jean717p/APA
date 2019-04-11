#include <stdio.h>
#include <stdlib.h>
typedef struct matr{
    int pos;
    int valore;
}matr;
void riempimatrici(FILE* fp,int ***matrice,matr ***vettR,int *r,int *c,int** v_r);
void accesso(int **matrice,matr **vettR,int* v_r);
void simmetria(int **matrice,matr **vettR,int r,int c,int* v_r);
void stampa(int **matrice,matr **vettR,int righe,int colonne,int* v_r);
int main(int argc,char* argv[])
{
    matr **vettR={NULL};
    int flag=0,op,**matrice={NULL},r,c,*v_r=NULL;
    FILE* fp=NULL;
    if(argc!=2)exit(-2);
    if((fp=fopen(argv[1],"r"))==NULL)exit(-1);
    riempimatrici(fp,&matrice,&vettR,&r,&c,&v_r);
    fclose(fp);
    do{printf("\t***Menu'***\n\n");
    printf("\tPer accedere alla matrice digitare: 1\n");
    printf("\tPer verificare la simmetricita' digitare: 2\n");
    printf("\tPer stampare le rappresentazioni digitare: 3\n");
    printf("\tPer uscire digitare: 4\n\n");
    scanf("%d",&op);
    switch(op){
    case 1: accesso(matrice,vettR,v_r); break;
    case 2: simmetria(matrice,vettR,r,c,v_r);break;
    case 3: stampa(matrice,vettR,r,c,v_r); break;
    case 4: flag=1; break;
    default: printf("Operazione non valida\n");
    }
    }while(flag==0);
    for(op=0;op<r;op++){
        free(matrice[op]);
        free(vettR[op]);
    }
    free(matrice);
    free(vettR);
    return 0;
}
void riempimatrici(FILE* fp,int ***matrice,matr ***vettR,int *r,int *c,int** v_r){
    int righe,colonne,i,j,null,k;
    if((fscanf(fp,"%d %d",&righe,&colonne))==EOF)exit(-2);
    if(righe<=0&&colonne<=0)exit(-3);
    (*matrice) =(int**) malloc(righe*sizeof(int*));
    (*vettR)=(matr**)malloc(righe*sizeof(matr*));
    (*v_r)=(int*)malloc(righe*sizeof(int*));
    for(i=0;i<righe;i++){
        (*matrice)[i] =(int*) malloc(colonne*sizeof(int));
        printf("\t");
        for(j=0,null=0;j<colonne;j++){
            fscanf(fp,"%d",&((*matrice)[i][j]));
            printf("%d ",(*matrice)[i][j]);
            if(((*matrice)[i][j])!=0)null++;
        }
        (*v_r)[i]=null;
        (*vettR)[i]=(matr*)malloc(null*sizeof(matr*)); //alloco solo ciò che serce ovvero matrice ridotta
        printf("\n");
    }
    rewind(fp); printf("\n");
    fscanf(fp,"%d %d",&righe,&colonne);
    for(i=0;i<righe;i++){
        for(j=0,k=0;j<colonne;j++){
            fscanf(fp,"%d",&null);
            if(null!=0){
                (*vettR)[i][k].valore=null; (*vettR)[i][k].pos=j;
                printf("Valore - %d\tPosizione <%d,%d>\n",(*vettR)[i][k].valore,i,(*vettR)[i][k].pos);
                k++;
            }
        }
    }
    *r=righe; *c=colonne;
    return;
}
void accesso(int **matrice,matr **vettR,int* v_r){ //accedo leggo nel punto indicato
    int i,j,k=0,flag=0;
    printf("Inserire l'elemnto in posizione <i,j> a cui accedere.\n");
    printf("i: "); scanf("%d",&i);
    printf("j: "); scanf("%d",&j);
    printf("Valore nella matrice <%d,%d>: %d\n",i,j,(matrice)[i][j]);
    while(flag==0&&k<v_r[i]){
            if((vettR)[i][k].pos==j)
                flag=1;
            else
                k++;
    }
    if(flag!=0){
    printf("Valore del vettore <%d,%d>: posizione <%d,%d>\tValore %d\n",i,j,i,k,(vettR)[i][k].valore);}
    else {printf("Valore non presente nel vettore.\n");}
    printf("\n");
    return;
}
void simmetria(int **matrice,matr **vettR,int r,int c,int* v_r){
    int op,i,j,flag=0;
    do{printf("Verifca simmetria su:\n");
    printf("1 -->Matrice\t2 -->Vettore\t3 -->Annulla\n");
    scanf("%d",&op);
    switch(op){
        case 1: if(c!=r){flag=1; break;}
                for(i=0;i<r&&flag==0;i++){
                    for(j=0;j<c&&flag==0;j++){
                        if(i<j){
                            if((matrice)[i][j]!=(matrice)[j][i]){ //semplice confronto triang sup con triang inf senza diagonale
                                flag++; break;
                            }
                        }
                    }
                }
                if(flag==0)printf("La matrice e' simmetrica!\n");
                else printf("La matrice non e' simmetrica.\n");
                flag=1; break;
        case 2: if(c!=r){flag=1; break;}
                for(i=0;i<r&&flag==0;i++){
                    for(j=0;j<v_r[i]&&flag==0;j++){
                        if(i<vettR[i][j].pos){ //guardo solo la triangolaro superiore senza diagonale e confronto con l'inferiore
                            if((vettR)[i][j].valore!=(vettR)[vettR[i][j].pos][i].valore)
                                flag=1;
                    }}
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
void stampa(int **matrice,matr **vettR,int righe,int colonne,int* v_r){//semplice stampa
    int i,j;
    for(i=0;i<righe;i++){
        printf("\t");
        for(j=0;j<colonne;j++){
            printf("%d ",(matrice)[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<righe;i++){
        for(j=0;j<v_r[i];j++){
            printf("Valore - %d\tPosizione <%d,%d>\n",(vettR)[i][j].valore,i,(vettR)[i][j].pos);
        }
        printf("\n");
    }

    return;
}
