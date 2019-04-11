#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define vkgmax 23 //peso max valigie in stiva

struct cose{
    char* nome;
    float peso;
    int valaff,preso;
};

void powerset(int pos,struct cose **items,int *sol,int k,int cap,float curr_cap,float curr_value,float *bv,int *best_sol,int flag);

int main(int argc,char* argv[])
{
    int i,N,count,cap,*sol,*best_sol; float best_value=0; char temp[20+1];
    struct cose **v;
    FILE *fp=NULL;
    if(argc!=4)
        exit(-1);
    if((fp=fopen(argv[1],"r"))==NULL)
        exit(-2);
    fscanf(fp,"%d",&N);
    sol=malloc(N*sizeof(int));
    best_sol=malloc(N*sizeof(int));
    v=malloc(N*sizeof(struct cose*));
    printf("Inserire capacita' massima del bagaglio a mano: ");
    scanf("%d",&cap);
    for(i=count=0;i<N;i++){ //riempio il vettore di struct
        v[i]=malloc(sizeof(struct cose));
        sol[i]=best_sol[i]=v[i]->preso=0;
        fscanf(fp,"%s %f %d",temp,&v[i]->peso,&v[i]->valaff); //si presuppone che il file sia scritto correttamente
        if(v[i]->peso>vkgmax&&v[i]->peso>cap){ //virtualmente il bagaglio a mano potrebbe pesare più di quello in stiva
            if(count==0)
                printf("Oggetti troppo pesanti:\n");
            printf("%d Nome: %s  Peso: %f  Valore Affettivo: %d\n",i+1,temp,v[i]->peso,v[i]->valaff);
            v[i]->preso++;
            count++;
        }
        else
            v[i]->nome=strdup(temp);
    }
    fclose(fp);
    powerset(0,v,sol,N,cap,0,0,&best_value,best_sol,0);
    fp=fopen(argv[2],"w");
    for(i=cap=0;i<N;i++){
        if(best_sol[i]!=0){ //bagaglio a mano
            fprintf(fp,"%d Nome: %s\nPeso: %.3fKg\nValore affettivo: %d\n",i+1,v[i]->nome,v[i]->peso,v[i]->valaff);
            v[i]->preso++;
            count++;
            best_sol[i]=0;
        }
    }
    fclose(fp);
    fp=fopen(argv[3],"w");
    while(count<N){
        best_value=0;
        powerset(0,v,sol,N,vkgmax,0,0,&best_value,best_sol,1);
        fprintf(fp,"Valigia n. %d:\n",cap+1);
        for(i=0,cap++;i<N;i++){
            if(best_sol[i]!=0){ //scrittura su file 2
                fprintf(fp,"Oggetto n.%d\tNome: %s\nPeso: %.3f Kg\nValore affettivo: %d\n",i+1,v[i]->nome,v[i]->peso,v[i]->valaff);
                v[i]->preso++;
                count++;
            }
        }
    }
    printf("\nN. valigie minime da imbarcare in stiva: %d\n\n\t\t***Buon Viaggio!***\n",cap+1);
    fclose(fp);
    return 0;
}
void powerset(int pos,struct cose **items,int *sol,int k,int cap,float curr_cap,float curr_value,float *bv,int *best_sol,int flag){
    int j;
    if(pos>=k){ //terminazione
        if(flag==0&&curr_value>*bv){
            for(j=0;j<k;j++)
                best_sol[j]=sol[j]; //soluzione migliore
            *bv=curr_value; //valore più alto
        }
        else if(flag==1&&curr_cap>*bv){
            for(j=0;j<k;j++)
                best_sol[j]=sol[j]; //soluzione migliore
            *bv=curr_cap; //peso maggiore
        }
        return;
    }
    if((curr_cap+items[pos]->peso)>cap||items[pos]->preso!=0){ //pruning con controllo se è già stato preso
        sol[pos]=0;
        powerset(pos+1,items,sol,k,cap,curr_cap,curr_value,bv,best_sol,flag);
        return;
    }
    sol[pos]=1;
    curr_cap+=items[pos]->peso;
    curr_value+=items[pos]->valaff;
    powerset(pos+1,items,sol,k,cap,curr_cap,curr_value,bv,best_sol,flag);
    sol[pos]=0; //backtraking
    curr_cap-=items[pos]->peso;
    curr_value-=items[pos]->valaff;
    powerset(pos+1,items,sol,k,cap,curr_cap,curr_value,bv,best_sol,flag);
    return;
}
