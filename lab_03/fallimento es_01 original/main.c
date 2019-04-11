#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct points{
    int x;
    int y;
}punti;
void aggmin(float v_min[],punti *xy,int i); //aggiorna la coppia di punti del massimo
void aggmax(float v_max[],punti *xy,int i); //aggiorna la coppia di punti del minimo
void distanza(punti *xy,float* dist,int i); //calcola la distanza
//void BubbleSortmodificato(punti *xy,int r);
int main()
{
    punti *xy;
    int nump=0,i=0,numd=0,flag=1;
    float dist,max=0,min=999999,v_min[4],v_max[4],d;
    xy = (punti*) malloc(sizeof(punti));
    FILE* fp=NULL;
    if((fp=fopen("dati.txt","r"))==NULL)exit(-1);
    while((fscanf(fp,"%d %d",&xy->x,&xy->y))!=EOF){ //leggo il file
        xy++; nump++;
    }
    xy->x=0; xy->y=0;
    fclose(fp);
    //if(nump<=5)exit(-2); //in caso le coppie siano soltanto 2
    xy-=(nump);
    for(i=0;i<nump+1;i++){
        printf("%d %d struttura no. %d\n",xy->x,xy->y,i); //stampa di prova
        xy++;}
    printf("Numero punti: %d\n",nump);
    xy-=nump; //rimetto il puntatore alla struttura 0
    printf("\nInserire distanza d richiesta: ");
    scanf("%f",&d); printf("\n\n");
    while((flag-nump)!=0){ //riemprio i dati
    for(i=0;i<nump;i++){
    distanza(xy,&dist,i);
    if(dist!=0){
        if(dist<d){
            numd++;}
        if(dist>max){ //qui dopo un paio di giri mi va palla nel senso che prende una dist a cavolo e va a fuori
            max=dist; //probabilmente è un problema di overflow ma non capisco dove possa nascere
            aggmax(v_max,xy,i);
            }
        if(dist<min){
            min=dist;
            aggmin(v_min,xy,i);
        }}}
    flag++; xy++;}
    printf("Distanza minima: %.3f\nPunti:\n",min); //stampe
    for(i=0;i<3;i+=2){printf("%.0f %.0f\n",v_min[i],v_min[i+1]);}
    printf("Distanza massima: %.3f\nPunti:\n",max);
    for(i=0;i<3;i+=2){printf("%.0f %.0f\n",v_max[i],v_max[i+1]);}
    printf("Numero distanze sotto limite %.3f : %d.\n",d,numd);
    //printf("Il vettore ordinato e':\n");
    //BubbleSortmodificato(xy,nump);
    free(xy);
    system("pause");
    return 0;
}
void distanza(punti *xy,float* dist,int i){ //calcolo distanza
    *dist=sqrt((((xy->x)-(xy[i].x))*((xy->x)-(xy[i].x)))+(((xy->y)-(xy[i].y))*((xy->y)-(xy[i].y))));
    printf("%f\n",*dist);
    return;
}
void aggmin(float v_min[],punti *xy,int i){ //aggiornamento minimo
    v_min[0]=xy->x; v_min[1]=xy->y;
    v_min[2]=xy[i].x; v_min[3]=xy[i].y;
    return;
 }
void aggmax(float v_max[],punti *xy,int i){ //aggiornamento massimo
    v_max[0]=xy->x; v_max[1]=xy->y;
    v_max[2]=xy[i].x; v_max[3]=xy[i].y;
    return;
    }
/*void BubbleSortmodificato(punti *xy, int r)
{
    punti temp;
    int i, j;
    float vdist[r],vtemp;
    for(i=0;i<r;i++,xy++){
        distanza(xy,&vdist[i],(r+1));
        }
    xy-=r;
    for(i=0;i<r;i++){
        for(j=0;j<(r-i);j++){
            if(vdist[j]>vdist[j+1]){
                temp = xy[j];
                xy[j] = xy[j+1];
                xy[j+1] = temp;
                vtemp = vdist[j];
                vdist[j] = vdist[j+1];
                vdist[j+1] = vtemp;
            }}
        }
    for(i=0;i<r;i++,xy++){
        printf("Punto: %d %d - distanza %f dall'origine\n",xy->x,xy->y,vdist[i]);
    }
return;
}*/
