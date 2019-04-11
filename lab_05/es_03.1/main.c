#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* item;
void MergeSort(item *A, int l, int r);
void Merge(item A[], int l, int q, int r);
int main()
{
    item *A=NULL; FILE* fp;
    int N,i;
    char temp[50+1]; //frase temporanea in cui memorizzare la stringa
    printf("Inserire nome file in input: ");
    gets(temp);
    if((fp=fopen(temp,"r"))==NULL){exit(-1);}
    fscanf(fp,"%d",&N);
    A=malloc(N*sizeof(char)); //alloco il vettore
        for(i=0;i<N;i++){
            fscanf(fp,"%s",temp);
            A[i]=strdup(temp);
        }
    i=0;
    MergeSort(A,i,N-1);
    for(i=0;i<N+1;i++){
        printf("%s\n",A[i]);
        free(A[i]);
        }//libero il vettore dinamico
    return 0;
}
void MergeSort(item *A, int l, int r){
    int q=(l+r)/2;
    if(r<=l)
        return;
    MergeSort(A,l,q);
    MergeSort(A,q+1,r);
    Merge(A,l,q,r);
    return;
}
void Merge(item A[], int l, int q, int r){
    int i,j,k; item *B;
    B=malloc((r-l+1)*sizeof(item));
    i=l; j=q+1;
    for(k=l;k<=r;k++){
        if(i>q)
            B[k-l]=A[j++];
        else if(j>r)
            B[k-l]=A[i++];
        else if((strcmp(A[i],A[j]))<=0)
            B[k-l]=A[i++];
        else
            B[k-l]=A[j++];
    }
    for(k=l;k<=r;k++){
        A[k]=B[k-l];}
    return;
}
