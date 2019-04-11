#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 35+1
typedef struct studenti{
    char *nome,*cognome;
    int gg,mm,aa;
    char sex;
}stud;
void riempistruct(stud **v,FILE* fp,int i);
void ordina(stud **v,int i);
int main(int argc,char* argv[])
{
    int i,j; stud *v=NULL;
    FILE* fp=NULL; FILE* fmale=NULL;
    if(argc!=4){exit(-1);}
    if((fp=fopen(argv[1],"r"))==NULL){exit(-2);}
    fscanf(fp,"%d",&i);
    v=(stud*)malloc(i*sizeof(stud));
    riempistruct(&v,fp,i); fclose(fp);
    fp=fopen(argv[3],"w"); fmale=fopen(argv[2],"w");
    ordina(&v,i);
    for(j=0;j<i;j++){ //stampo nei vari file
        if(v[j].sex=='M'){
            fprintf(fmale,"%s %s %d/%d/%d %c\n",v[j].nome,v[j].cognome,v[j].gg,v[j].mm,v[j].aa,v[j].sex);
        }
        else
            fprintf(fp,"%s %s %d/%d/%d %c\n",v[j].nome,v[j].cognome,v[j].gg,v[j].mm,v[j].aa,v[j].sex);
    }
    fclose(fp); fclose(fmale);
    for(j=0;j<i;j++){
        free(v[j].nome);
        free(v[j].cognome);
    }
    free(v); //libero il vettore
    return 0;
}
void riempistruct(stud **v,FILE* fp,int i){
    int j; char stringa[2][N]; //riempio la struct
    for(j=0;j<i;j++){
        fscanf(fp,"%s %s %d/%d/%d %c",stringa[0],stringa[1],&(*v)[j].gg,&(*v)[j].mm,&(*v)[j].aa,&(*v)[j].sex);
        (*v)[j].nome=strdup(stringa[0]); (*v)[j].cognome=strdup(stringa[1]);
    }
    return;
}
void ordina(stud **v,int i){ //bubblesort
    int j,flag,k; stud temp;//ordino il vettore
    for(k=0;k<i-1;k++){
        for(j=0,flag=0;j<i-1-k;j++,flag=0){
            if((*v)[j].aa>(*v)[j+1].aa){
                flag=1;
            }
            else if((*v)[j].aa==(*v)[j+1].aa&&(*v)[j].mm>(*v)[j+1].mm){
                flag=1;
            }
            else if((*v)[j].aa==(*v)[j+1].aa&&(*v)[j].mm==(*v)[j+1].mm&&(*v)[j].gg>(*v)[j+1].gg){
                flag=1;
            }
            if(flag!=0){ //ordino
                temp = (*v)[j];
                (*v)[j] = (*v)[j+1];
                (*v)[j+1] = temp;
            }
        }
    }
    for(j=0;j<i;j++){ //stampa di controllo
            printf("%s %s %d/%d/%d %c\n",(*v)[j].nome,(*v)[j].cognome,(*v)[j].gg,(*v)[j].mm,(*v)[j].aa,(*v)[j].sex);
    }
    return;
    }
