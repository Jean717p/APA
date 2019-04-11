#include <stdio.h>
#include <stdlib.h>
typedef int item;
void MergeSort(item *A, int l, int r);
void Merge(item *A, int l, int q, int r);
int main()
{
    item *A=NULL; FILE* fp; //uso p per segnarmi il punto di partenza
    int N,i; char nomef[25];
    printf("Inserire nome file in input: ");
    gets(nomef);
    if((fp=fopen(nomef,"r"))==NULL)exit(-1);
    fscanf(fp,"%d",&N);
    A=(item*)malloc(N*sizeof(item)); //alloco il vettore
    for(i=0;i<N;i++){
        fscanf(fp,"%d",&A[i]);
        }
    i=0;
    MergeSort(A,i,N-1);
    for(i;i<N;i++){
        printf("%d ",A[i]);
        free(A[i]);
        }
    free(A); //libero il vettore dinamico
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
void Merge(item *A, int l, int q, int r){
    int i, j, k,max=r;
    item *B;
    B=malloc((r-l+1)*sizeof(item));
    i=l; j=q+1;
    for(k=l;k<=r;k++){
        if(i>q)
            B[k-l]=A[j++];
        else if(j>r)
            B[k-l]=A[i++];
        else if(A[i]<=A[j])
            B[k-l]=A[i++];
        else
            B[k-l]=A[j++];
    }
    for (k=l;k<=r;k++)
        A[k]=B[k-l];
    return;
}
