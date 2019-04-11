//Esercizio 2 rifatto ponendo tutto nel main
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    int r,r2,c,c2,i=0,j,k=0,**matrice[3][][]={NULL};
    FILE* fp=NULL;
    if(argc!=3)exit(1);
    if((fp=fopen(argv[1],"r"))==NULL)exit(-1);
    if((fscanf(fp,"%d %d",&r,&c))==EOF)exit(-2);
    if(r<=0&&c<=0)exit(-3);
    matrice[0]=(int**) malloc(r*sizeof(int*));
    for(i=0;i<r;i++){
        matrice[0][i] =(int*) malloc(c*sizeof(int));
        for(j=0;j<c;j++){
            fscanf(fp,"%d",&(matrice[0][i][j]));
            printf("%d ",matrice[0][i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fclose(fp);
    if((fp=fopen(argv[2],"r"))==NULL)exit(-4);
    if((fscanf(fp,"%d %d",&r2,&c2))==EOF)exit(-2);
    if(c!=r2){
        printf("Impossibile moltiplicare le matrici.\n");
        exit(-5);
        }
    if(r2<=0&&c2<=0)exit(-3);
    matrice[1]=(int**) malloc(r2*sizeof(int*));
    for(i=0;i<r2;i++){
        matrice[1][i] =(int*) malloc(c2*sizeof(int));
        for(j=0;j<c2;j++){
            fscanf(fp,"%d",&(matrice[1][i][j]));
            printf("%d ",matrice[1][i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fclose(fp);
    matrice[2] =(int**) malloc(r*sizeof(int*));
    fp=fopen("Output.txt","wt");
    fprintf(fp,"%d %d\n",r,c2);
    for(i=0;i<r;i++){
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
