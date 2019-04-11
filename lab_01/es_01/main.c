#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    if(argc!=3)exit(-1);
    FILE* fp=NULL;
    FILE* fo=NULL;
    int nr,nc,tot,i,j,flag,h=0,k=0;
    float num,matrice1[20+1][20+1]= {{0}};
    if((fp=fopen(argv[1],"r"))==NULL)exit(-2);
    if((fo=fopen(argv[2],"wt"))==NULL)exit(-3);
    fscanf(fp,"%d %d",&nr,&nc);
    for(i=1; i<nr+1; i++)
    {
        for(j=1; j<nc+1; j++)
        {
            fscanf(fp,"%f",&matrice1[i][j]);
        }
    }
    fclose(fp);
    fo=fopen("ris.txt","wt");
    fprintf(fo,"%d %d\n",nr,nc);
    i=0;
    j=0;
    for(h=0; h<nr; h++,i++,j=0)
    {
        for(k=0; k<nc; k++,j++)
        {
            for(flag=0,tot=0, num=0; flag<2; flag++,j++)
            {
                num+=matrice1[i][j];
                if(matrice1[i][j]!=0)
                {
                    tot++;
                }
            }
            for(flag=0; flag<2; flag++,i++)
            {
                num+=matrice1[i][j];
                if(matrice1[i][j]!=0)
                {
                    tot++;
                }
            }
            for(flag=0; flag<2; flag++,j--)
            {
                num+=matrice1[i][j];
                if(matrice1[i][j]!=0)
                {
                    tot++;
                }
            }
            for(flag=0; flag<2; flag++,i--)
            {
                num+=matrice1[i][j];
                if(matrice1[i][j]!=0)
                {
                    tot++;
                }
            }
            matrice1[0][0]=num/tot;
            fprintf(fo,"%.1f ",matrice1[0][0]);
        }
        fprintf(fo,"\n");
    }
    return 0;
}
