#include <stdio.h>
#include <stdlib.h>
#define N 16
#define M 5
void gestisci(char*,char*,FILE**,int);
void disprip(int pos,char* alfabeto,int sol[],int n,int k,char* vocali,char* consonanti,FILE* fp);
int main(int argc,char* argv[])
{
    FILE* fp=NULL; int n=21,*sol,pos=0,k;
    char vocali[]={'a','e','i','o','u'};
    char consonanti[]={'b','c','d','f','g','h','l','m','n','p','q','r','s','t','v','z'};
    char alfabeto[]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    if(argc!=2)
        exit(-1);
    if((fp=fopen(argv[1],"w"))==NULL)
        exit(-2);
    printf("Legge: consonante-vocale-consonante-vocale\n");
    printf("Inserire la lunghezza (max 21) delle parole designate: ");
    scanf("%d",&k);
    if(k%4!=0||k>=n)
        exit(-3);
    //n=4;
    sol=malloc(n*sizeof(int));
    disprip(pos,alfabeto,sol,n,k,vocali,consonanti,fp);
    free(sol);
    fclose(fp);
    return 0;
}
void disprip(int pos,char* alfabeto,int sol[],int n,int k,char* vocali,char* consonanti,FILE* fp){
    int i,j,flag;
    if(pos>=k){
        for(i=flag=0;i<k&&flag==0;i++){
            if(i%2==0){
                for(j=0,flag=1;j<N;j++){
                    if(consonanti[j]==sol[i]){
                        flag=0;
                        break;
                    }
                }
            }
            else{
                for(j=0,flag=1;j<M;j++){
                    if(vocali[j]==sol[i]){
                        flag=0;
                        break;
                    }
                }
            }
        }
        if(flag==0){
            for(i=0;i<k;i++){
                fprintf(fp,"%c",sol[i]);
            }
            fprintf(fp,"\n");
        }
        return;
    }
    for(i=0;i<n;i++){
        sol[pos]=alfabeto[i];
        disprip(pos+1,alfabeto,sol,n,k,vocali,consonanti,fp);
    }
}
//void gestisci(char vocali[],char consonanti[],FILE** fp,int n){
//    int i,j,k,l,m,o;
//    for(o=i=j=k=l=0;o<6400;o++){
//        for(m=0;m<(n/4);m++){
//            fprintf(*fp,"%c%c%c%c",consonanti[i],vocali[j],consonanti[k],vocali[l]);
//            //printf("%c%c%c%c",consonanti[i],vocali[j],consonanti[k],vocali[l]);
//        }
//        l++;
//        if(i==N){
//            i=0;
//        }
//        else if(j==M){
//            j=0;
//            i++;
//        }
//        else if(k==N){
//            k=0;
//            j++;
//        }
//        else if(l==M){
//            l=0;
//            k++;
//            if(k==N){
//                k=0;
//                j++;
//                if(j==M){
//                    j=0;
//                    i++;
//                }
//            }
//        }
//        fprintf(*fp,"\n");
//        }
//    fclose(*fp);
//    return;
//}
//void gestisci(char vocali[],char consonanti[],FILE** fp,int n){
//    int i,j,k,l,m,o; char v[6400][n];
//    i=j=l=k=m=o=0;
//    while(o<6400){
//        for(m=0;m<(n/4);m++){
//            fprintf(*fp,"%c%c%c%c",consonanti[i],vocali[j],consonanti[k],vocali[l]);
//        }
//    }
//    fclose(*fp);
//}
//void gestisci(char vocali[],char consonanti[],FILE** fp,int n){
//    int i,j,k,l;
//    for(i=0;i<N;i++){
//        for(j=0;j<M;j++){
//            for(k=0;k<N;k++){
//                for(l=0;l<M;l++){
//                    fprintf(*fp,"%c%c%c%c\n",consonanti[i],vocali[j],consonanti[k],vocali[l]);
//                }
//            }
//        }
//    }
//    fclose(*fp);
//    return;
//}
//void gestisci(int i,int j,char vocali[],char consonanti[],FILE** fp,int n,int cost){ //ricorsivo
//    fprintf(*fp,"%c%c",consonanti[j],vocali[i]);
//    if(n/2!=1){
//        n/=2;
//        gestisci(i,j,vocali,consonanti,fp,n,cost);
//        for(++i;i<M;i++){
//            gestisci(i,j,vocali,consonanti,fp,n,cost);
//            n=cost;
//        }
//    }
//    else{
//        fprintf(*fp,"\n");
//        return;
//    }
//    return;
//}
