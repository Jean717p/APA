#include <stdio.h>
#include <stdlib.h>

void riempimatrice(FILE* fp,int righe,int colonne,int ***matrice,int);

int main(int argc,char* argv[])
{
    int r,r2,c,c2,i=0,j,k=0,**matrice[3]={NULL};
    FILE* fp=NULL;
    if(argc!=3)exit(1);
    if((fp=fopen(argv[1],"r"))==NULL)exit(-1);
    if((fscanf(fp,"%d %d",&r,&c))==EOF)exit(-2);
    if(r<=0&&c<=0)exit(-3);
    riempimatrice(fp,r,c,matrice,i);
    fclose(fp);
    if((fp=fopen(argv[2],"r"))==NULL)exit(-4);
    if((fscanf(fp,"%d %d",&r2,&c2))==EOF)exit(-2);
    if(c!=r2){
        printf("Impossibile moltiplicare le matrici.\n");
        exit(-5);
        }
    if(r2<=0&&c2<=0)exit(-3);
    i=1;
    riempimatrice(fp,r2,c2,matrice,i);
    fclose(fp);
    matrice[2] =(int**) malloc(r*sizeof(int*));
    fp=fopen("Output.txt","wt");
    fprintf(fp,"%d %d\n",r,c2);
    for(i=0;i<r;i++){ //prodotto righe per colonne
        matrice[2][i] =(int*) malloc(c2*sizeof(int));
        for(j=0;j<c2;j++){
            matrice[2][i][j]=0;
            for(k=0;k<c;k++){
                matrice[2][i][j]+=(matrice[0][i][k]*matrice[1][k][j]);
            }
            fprintf(fp,"%d ",matrice[2][i][j]);
        }
        fprintf(fp,"\n");
    }

    return 0;
}
void riempimatrice(FILE* fp,int righe,int colonne,int ***matrice,int k){
    int j,i;
    (matrice)[k] =(int**) malloc(righe*sizeof(int*));
    for(i=0;i<righe;i++){
        (matrice)[k][i] =(int*) malloc(colonne*sizeof(int));
        for(j=0;j<colonne;j++){
            fscanf(fp,"%d",&((matrice)[k][i][j]));
            printf("%d ",(matrice)[k][i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}
