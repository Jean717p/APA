#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 9

int trovasoluzione(int* comb,int L,char ad1[],char ad2[],char ris[]);
int perm(int pos,int val[],int* sol,int mark[],int L,char ad1[],char ad2[],char ris[]);
int main(int argc,char* argv[])
{
    int vett[]={1,2,3,4,5,6,7,8,9};
    int vf[9]={0},L,i,fat,*comb;
    if(argc!=5)
        exit(-1);
    L=atoi(argv[1]);
    for(i=fat=0;i<L;i++){
        if(argv[3][i]=='_')
            fat++;
        else
	    fat+=2;
    }
    if(fat>N)
        exit(-2);
    comb=malloc(N*sizeof(int*)); i=0;
    fat=perm(i,vett,comb,vf,L,argv[2],argv[3],argv[4]);
    if(fat==0)
        printf("Fallimento Totale.\n");
    return 0;
}
int perm(int pos,int val[],int* sol,int mark[],int L,char ad1[],char ad2[],char ris[]){
    int i,flag=0;
    if(pos>=N){
        flag=0;
        flag=trovasoluzione(sol,L,ad1,ad2,ris);
        return flag;
        }
        for(i=0;i<N;i++){
            if(mark[i]==0){
                mark[i]=1; //marcamento
                sol[pos]=val[i];
                flag=perm(pos+1,val,sol,mark,L,ad1,ad2,ris); //ricorsione con backtracking
                if(flag!=0)
                    return flag;
                mark[i]=0; //smarcamento
            }
        }
    return flag;
}
int trovasoluzione(int* comb,int L,char ad1[],char ad2[],char ris[]){
    int i,flag=0,j=N-1,r=0,t,v[L]; char temp1[L],temp2[L],temp3[L];
    for(i=L-1;i>=0&&flag==0;i--){
        v[i]=0;
        if(ad1[i]=='_'){
            temp1[i]=comb[j]+48;
            t=comb[j--]+(ad2[i]-48)+r;
            r=0;
            if(t>=10){
                t-=10;
                r++;
            }
            if(t!=0&&t==comb[j--]){
                temp3[i]=t+48;
                temp2[i]=ad2[i];
            }
            else
                flag+=1;
        }
        else{
            temp2[i]=comb[j]+48;
            t=(ad1[i]-48)+comb[j--]+r;
            r=0;
            if(t>=10){
                t-=10;
                r++;
            }
            if(t!=0&&t==(ris[i]-48)){
                temp1[i]=ad1[i];
                temp3[i]=ris[i];
            }
            else
                flag+=1;
        }
        if(flag==0)
            v[i]++;
    }
    flag=0;
    for(i=t=0;i<L&&t==0;i++){
        if(v[i]!=1)
            t++;
    }
    if(t==0){
        printf("Una soluzione e':\n\n\t%s +\n\n\t%s =\n\t",temp1,temp2);
        for(i=0;i<L+1;i++)
            printf("_");
        printf("\n\n\t%s\n",temp3);
        flag+=1;
    }
    return flag;
}
