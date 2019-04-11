#include <stdio.h>
#include <stdlib.h>

int main()
{
    char diz[100][20],word;
    int i=0;
    FILE* fp=NULL;
    FILE* fo=NULL;
    FILE* fc=NULL;
    if((fc=fopen("codificato.txt","r"))==NULL)exit(-1);
    if((fp=fopen("dizionario.txt","r"))==NULL)exit(-2);
    fo=fopen("decodificato.txt","wt");
    while((fscanf(fp,"%d",&i))!=EOF)
    {
        fscanf(fp,"%s",diz[i]);
    }
    fclose(fp);
    while((fscanf(fc,"%c",&word))!=EOF)
    {
        if(word=='$')
        {
            fscanf(fc,"%d",&i);
            fprintf(fo,"%s ",diz[i]);
        }
        else
            fprintf(fo,"%c",word);
    }
    fclose(fc);
    fclose(fo);
    return 0;
}
