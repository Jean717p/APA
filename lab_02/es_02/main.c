#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
int main(int argc,char* argv[])
{
    if(argc!=3)exit(-1);
    FILE* fp=NULL;FILE* fr=NULL;
    int i,num_p=1,flag,pos=0; char confr[N*7];
    if((fp=fopen(argv[1],"r"))==NULL)exit(-2);
    if((fr=fopen(argv[2],"r"))==NULL)exit(-3);
    fscanf(fr,"%d",&num_p);
    int v[num_p][N*2+2];
    char parola[num_p][N];
    for(i=0;i<num_p;i++){
        fscanf(fr,"%s",parola[i]);
        v[i][0]=0;
        v[i][1]=2;
    }
    fclose(fr);
    while((fscanf(fp,"%s",confr))!=EOF){
        pos++;
        for(i=flag=0;flag==0&&i<num_p;i++){
            if((strncmp(parola[i],confr,strlen(parola[i])))==0){
                v[i][0]++;
                v[i][v[i][1]]=pos;
                v[i][1]++;
                flag=1;
            }
        }
    }
    fclose(fp);
    for(i=0;i<num_p;i++){
        printf("%s - %d occorrenza/e ",parola[i],v[i][0]);
        if(v[i][1]>2){
                printf("- posizioni: ");
        for(flag=2;flag<v[i][1];flag++){
            printf("%d ",v[i][flag]);
        }}
        printf("\n");
    }
    return 0;
}
