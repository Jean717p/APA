#include <stdio.h>
#include <stdlib.h>
void conversione(int num,int b,int *count,long int* ris);
int main()
{
    int numero,base,count=1;
    long int ris=0;
    printf("Inserire un numero in base 10 da convertire: ");
    scanf("%d",&numero);
    printf("Inserire la base (2<=base<10) in cui convertirlo: ");
    scanf("%d",&base);
    if(base<2||base>10){
        printf("Base non valida.\n");
        exit(-1);
    }
    conversione(numero,base,&count,&ris);
    printf("%d in base %d e' %li",numero,base,ris);
    return 0;
}
void conversione(int num,int b,int *count,long int* ris){
    if(num==1){
        *ris+=(num%b)*(*count);
        //printf("%d\n",*ris);
        //printf("%d\n",num%b);
    }
    else if(num!=0){
        *ris+=(num%b)*(*count);
        //printf("%d\n",*ris);
        *count=(*count)*10;
        num=(num/b);
        conversione(num,b,count,ris);
    }
    return;
}
