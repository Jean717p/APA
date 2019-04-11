#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct compiti{
    char* nome;
    int lavoro,preso;
};
struct risorse{
    char *ris;
};

void media(int*,int);

int main(int argc,char* argv[])
{
    int i,N=0,num_ris=0,count,med=0,*best_value,pos,flag=0; char temp[20+1];
    struct compiti **v; struct risorse **s;
    FILE *fp=NULL;
    if(argc!=3)
        exit(-1);
    if((fp=fopen(argv[2],"r"))==NULL)
        exit(-2);
    while(fscanf(fp,"%s",temp)!=EOF) //inizializzazione
        num_ris++;
    s=malloc(num_ris*sizeof(struct risorse*));
    best_value=malloc(num_ris*sizeof(int));
    rewind(fp);
    for(i=0;i<num_ris;i++){
        s[i]=malloc(sizeof(struct risorse));
        fscanf(fp,"%s",temp);
        s[i]->ris=strdup(temp);
        best_value[i]=0;
    }
    fclose(fp);
    fp=NULL;
    if((fp=fopen(argv[1],"r"))==NULL)
        exit(-3);
    while(fscanf(fp,"%s %d",temp,&i)!=EOF){
        N++; flag+=i;}
    med=flag;
    media(&med,num_ris); //calcolo della media: somma lavori / numero risorse +0.9
    v=malloc(N*sizeof(struct compiti*));
    rewind(fp);
    for(i=count=0;i<N;i++){ //riempio il vettore di struct
        v[i]=malloc(sizeof(struct compiti));
        v[i]->preso=-1;
        fscanf(fp,"%s %d",temp,&v[i]->lavoro); //si presuppone che il file sia scritto correttamente
        v[i]->nome=strdup(temp);
        if(v[i]->lavoro>=med){ //pruning - se supera la media gli associo direttamente una risorsa
            best_value[count]+=v[i]->lavoro; //aggiorno il carico complessivo
            v[i]->preso=count++; //risorse già utilizzate da lavori al di sopra o uguali alla media
            flag-=v[i]->lavoro; med=flag;
            media(&med,num_ris-count);
        }
    }
    fclose(fp); flag=count;
    while(count<num_ris){
        for(i=0;i<N;i++){
            if(v[i]->preso==-1&&(v[i]->lavoro+best_value[count])<=med){ //bagaglio a mano
                v[i]->preso=count;
                best_value[count]+=v[i]->lavoro;
            }
        }
        count++;
    }
    for(i=0,count=flag;i<N;i++){ //controllo se ha assegnato tutti i compiti
        if(v[i]->preso==-1){ //se manca più di un elemento
            for(med=count,flag=best_value[med];med<num_ris;med++){
                if(best_value[med]<flag){ //nel caso ne manca 1 calcolo il carico minimo
                    flag=best_value[med];
                    pos=med;
                }
            } //aggiungo al carico minimo l'elemento che non era stato preso
            best_value[pos]+=v[i]->lavoro;
            v[i]->preso=pos;
        }
    }
    for(count=0;count<num_ris;count++){ //stampa
        printf("%s = { ",s[count]->ris);
        free(s[count]->ris);
        free(s[count]);
        for(i=0;i<N;i++){
            if(v[i]->preso==count){
                printf("%s ",v[i]->nome);
                free(v[i]->nome);
                free(v[i]);
                if(best_value[count]==0)
                    best_value[count]+=v[i]->lavoro;
            }
        }
        printf("} Carico complessivo: %d\n-------------\n",best_value[count]);
    }
    free(best_value);
    free(s); free(v);
    return 0;
}
void media(int* med,int numr){
    float temp=*med;
    temp/=numr;
    temp+=0.9;
    *med=temp;
    return;
}
