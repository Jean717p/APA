#include <stdio.h>
#include <stdlib.h>
void num_catalan(int* cat,int n,int i);
int main()
{
    int *Catalan,n,i=0;
    printf("Inserire un numero n >=0 per calcolare il numero di Catalan: ");
    scanf("%d",&n);
    if(n<0){printf("n minore di zero.\n"); exit(-1);}
    Catalan = (int*)malloc(n*sizeof(int));
    Catalan[0]=1;
    num_catalan(Catalan,n,i);
    printf("Il numero di Catalan(n) e': %d",Catalan[n]);
    free(Catalan);
    return 0;
}
void num_catalan(int* cat,int n,int i){
    int j,temp=0;
    if(i<=n){
        for(j=0;j<i;j++){
            temp+=(cat[j])*(cat[i-j-1]);
        }
        if(i!=0){
        cat[i]=temp;}
        i++;
        num_catalan(cat,n,i);
    }
    return;
}
