#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(int argc,char* argv[])
{
    FILE* f_1=NULL; FILE* f_2=NULL; sytab st=NULL;
    char *Output[]={"Traff_X_Cat.txt","Clienti_X_Cat.txt","Traff_X_Cliente.txt"};
    char **clienti,**categorie,temp[MAX];
    int n_clienti=0,i;
    if(argc!=3)
        exit(-1);
    if((f_1=fopen(argv[1],"r"))==NULL||(f_2=fopen(argv[2],"r"))==NULL)
        exit(-2);
    while(fscanf(f_1,"%s %s %s %s",temp,temp,temp,temp)!=EOF){
        n_clienti++;
    }
    rewind(f_1);
    clienti=malloc(n_clienti*sizeof(char*));
    categorie=malloc(n_clienti*sizeof(char*));
    st=STinit(n_clienti);
    clienti=getdata(st,f_1,n_clienti,categorie);
    fclose(f_1);
    getfile2(st,f_2);
    fclose(f_2);
    f_1=fopen(Output[0],"w"); f_2=fopen(Output[1],"w");
    scrivipercat(st,categorie,f_1,f_2);
    fclose(f_1); fclose(f_2); f_1=fopen(Output[2],"w");
    fprintf(f_1,"Clienti:\n");
    for(i=0;i<n_clienti;i++){
        STprintdata(st,f_1,clienti[i]);
    }
    printf("\n******* Tutto completato con successo! Arrivederci! *******\n\n");
    return 0;
}
