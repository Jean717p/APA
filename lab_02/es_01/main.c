#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10
int main(int argc,char* argv[])
{
    if(argc!=2)exit(-1);
    FILE* fp=NULL;
    char frase[N*3],frase2[N*3];
    int i,j=0,k[N],v[N][N+1]={{0}},flag=0;
    if((fp=fopen(argv[1],"r"))==NULL)exit(-2);
    for(i=0;i<N;i++)k[i]=1;
    while((fscanf(fp,"%s",frase))!=EOF){
        j++;
        for(i=flag=0;(i<strlen(frase))&&flag==0;i++){
            if(!isalpha(frase[i])){
                if(i<strlen(frase)-1){
                    j++; flag=1;
                    strncpy(frase2,frase,i);
                    for(i+=1;i<strlen(frase2);i++){
                    frase[i-strlen(frase2)-1]=frase[i];
                    }
                    i=strlen(frase2)-2;
                    if(i<=N){
                    v[i-1][0]++;
                    if(k[i-1]<N){
                        v[i-1][k[i-1]]=j;
                        k[i-1]++;}
                    }
                    i=strlen(frase)-strlen(frase2)-1;
                    break;
                }
                else{
                    i=strlen(frase)-1-1; flag=1;break;}
            }
            }
        if(flag==0){
        i=strlen(frase)-1;}
        if(i<=N){
            v[i][0]++; //conteggio parole per lunghezza
            if(k[i]<N){ //posizione di max 10 parole
            v[i][k[i]]=j;
            k[i]++;}
        }}
    for(i=0;i<N;i++){
        if(v[i][0]!=0){
        printf("%d - %d - ",i+1,v[i][0]);
        for(j=1;j<k[i];j++){
            if(v[i][j]==0)break;
            printf("%d ",v[i][j]);
        }
        printf("\n");}
    }
    return 0;
}
