#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct points{
    int x;
    int y;
}punti;
void aggmin(float v_min[],punti *xy,int i,int j); //aggiorna la coppia di punti del massimo
void aggmax(float v_max[],punti *xy,int i,int j); //aggiorna la coppia di punti del minimo
void distanza(punti *xy,float* dist,int i,int j); //calcola la distanza
void BubbleSortmodificato(punti *xy,int r);
int main()
{
    punti *xy;//*partenza;
    int nump=0,i=0,numd=0,flag=1,j=0;
    float dist,max=0,min=999999,v_min[4],v_max[4],d;
    FILE* fp=NULL; //partenza=&xy[0];
    if((fp=fopen("dati.txt","r"))==NULL)exit(-1);
    while(feof(fp)==0)
    {
        fscanf(fp,"%d %d",&nump,&numd);//le ho messe tanto per, solo per usarne 2 gia esistenti, ma le inizializzo poi
        i++;
    }
    nump=0;
    numd=0;
      xy = (punti*) malloc((i+1)*sizeof(punti));
    i=0;
    rewind(fp);
    while((fscanf(fp,"%d %d",&xy[i].x,&xy[i].y))!=EOF){ //leggo il file
        i++;
    }
    fclose(fp);
    xy[i+1].x=0; xy[i+1].y=0; //origine
    nump=i; i=0;
    while(i<nump){
        printf("%d %d struttura no. %d\n",xy[i].x,xy[i].y,i); //stampa di prova
        i++;
    }
    printf("Numero punti: %d\n",nump);
    printf("\nInserire distanza d richiesta: ");
    scanf("%f",&d); printf("\n\n");
    while((flag-nump)!=0){ //riemprio i dati
    for(i=0;i<nump;i++){
    distanza(xy,&dist,i,j);
    if(dist>0){
        if(dist<d){
            numd++;}
        if(dist>max){
            max=dist;
            aggmax(v_max,xy,i,j);
            }
        if(dist<min){
            min=dist;
            aggmin(v_min,xy,i,j);
        }}}
    flag++; j++;}
    printf("Distanza minima: %.3f\nPunti:\n",min); //stampe
    for(i=0;i<3;i+=2){printf("%.0f %.0f\n",v_min[i],v_min[i+1]);}
    printf("Distanza massima: %.3f\nPunti:\n",max);
    for(i=0;i<3;i+=2){printf("%.0f %.0f\n",v_max[i],v_max[i+1]);}
    printf("Numero distanze sotto limite %.3f : %d.\n\n",d,numd);
    BubbleSortmodificato(xy,nump);
    fp=fopen("Ordinato.txt","w");
    for(i=0;i<nump;i++){
        fprintf(fp,"%d %d\n",xy[i].x,xy[i].y);
    }
    fclose(fp);
    system("pause");
    free(xy);
    return 0;
}
void distanza(punti *xy,float* dist,int i,int j){ //calcolo distanza
    *dist=sqrt((((xy[j].x)-(xy[i].x))*((xy[j].x)-(xy[i].x)))+(((xy[j].y)-(xy[i].y))*((xy[j].y)-(xy[i].y))));
    return;
}
void aggmin(float v_min[],punti *xy,int i,int j){ //aggiornamento minimo
    v_min[0]=xy[j].x; v_min[1]=xy[j].y;
    v_min[2]=xy[i].x; v_min[3]=xy[i].y;
    return;
 }
void aggmax(float v_max[],punti *xy,int i,int j){ //aggiornamento massimo
    v_max[0]=xy[j].x; v_max[1]=xy[j].y;
    v_max[2]=xy[i].x; v_max[3]=xy[i].y;
    return;
    }
void BubbleSortmodificato(punti *xy, int r)
{
    punti temp;//strutture tempoiranea
    int i, j;
    float vdist[r],vtemp;
    for(i=0;i<r;i++){
        distanza(xy,&vdist[i],(r+1),i); //acquisizione distanze dall'origine
        }
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if(vdist[j]>vdist[j+1]){
                temp=xy[j]; //Per associare l'indirizzo di un puntatore struttura
                xy[j]=xy[j+1];
                xy[j+1]=temp;
                vtemp = vdist[j];
                vdist[j] = vdist[j+1];
                vdist[j+1] = vtemp;
            }}
        }
    for(i=0;i<r;i++){
        printf("Punto: %d %d - distanza %.3f dall'origine\n",xy[i].x,xy[i].y,vdist[i]);
    }
return;
}

