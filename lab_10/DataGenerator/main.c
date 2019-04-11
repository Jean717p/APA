#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j=1000;
    FILE *fp=fopen("compiti.txt","w");
    for(i=0;i<j;i++){
        fprintf(fp,"Job_%d %d\n",i+1,rand()%1000);
    }
    fclose(fp);
    fp=fopen("risorse.txt","w");
    j='Z';
    for(i='A';i<=j;i++){
        fprintf(fp,"risorsa_%c\n",i);
    }
    fclose(fp);
    return 0;
}
