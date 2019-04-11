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
//Commenti al fondo
void powerset(int pos,struct compiti **items,int *sol,int k,int cap,int curr_cap,int *bv,int *best_sol,int* flag);
void media(int*,int);

int main(int argc,char* argv[])
{   /* ***Dichiarazione variabili e lettura dai file*** */
    int i,N=0,num_ris=0,count,med,*sol,*best_sol,*best_value,flag=0,pos; char temp[20+1];
    struct compiti **v; struct risorse **s;
    FILE *fp=NULL;
    if(argc!=3)
        exit(-1);
    if((fp=fopen(argv[2],"r"))==NULL)
        exit(-2);
    while(fscanf(fp,"%s",temp)!=EOF)
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
    med=flag; //flag memorizza la somma dei jobs
    media(&med,num_ris); //calcolo della media: somma lavori / numero risorse +0.9
    sol=malloc(N*sizeof(int));
    best_sol=malloc(N*sizeof(int));
    v=malloc(N*sizeof(struct compiti*));
    rewind(fp);
    for(i=count=0;i<N;i++){ //riempio il vettore di struct
        v[i]=malloc(sizeof(struct compiti));
        sol[i]=best_sol[i]=0;
        v[i]->preso=-1;
        fscanf(fp,"%s %d",temp,&v[i]->lavoro); //si presuppone che il file sia scritto correttamente
        v[i]->nome=strdup(temp);
        if(v[i]->lavoro>=med){ //pruning: se supera la media gli associo direttamente una risorsa
            best_value[count]+=v[i]->lavoro; //aggiorno il carico complessivo
            v[i]->preso=count++; //risorse già utilizzate da lavori al di sopra o uguali alla media
            flag-=v[i]->lavoro; med=flag; //flag memorizza al momento la somma dei jobs
            media(&med,num_ris-count);
        }
    } //flag memorizza la posizione del vettore risorse
    fclose(fp); flag=count; pos=0;
    /* ***FASE 1 : Powerset ***  */
    while(count<num_ris){ //assegno i lavori alle risorse col powerset permutazioni semplici
        powerset(0,v,sol,N,med,0,&best_value[count],best_sol,&pos);
        for(i=pos=0;i<N;i++){
            if(best_sol[i]!=0){
                v[i]->preso=count;
                best_sol[i]=0;
            }
        }
        count++;
    }
    printf("Fase 1 Completata...\n\n");
    /* ***FASE 2 : Gestione casi particolari*** es: numero risorse = numero dei jobs con un job al di sopra della media */
    for(i=0,count=flag;i<N;i++){ //controllo se ha assegnato tutti i compiti
        if(v[i]->preso==-1){ //se manca un elemento
            for(med=count,flag=best_value[med];med<num_ris;med++){
                if(best_value[med]<flag){ //nel caso ne manca 1 calcolo il carico minimo
                    flag=best_value[med];
                    pos=med;
                }
            }
            best_value[pos]+=v[i]->lavoro;
            v[i]->preso=pos;
        }
    }
    printf("Fase 2 Completata...\n\n");
    for(count=0;count<num_ris;count++){ //stampa
        printf("\n%s = { ",s[count]->ris);
        free(s[count]->ris);
        free(s[count]);
        for(i=pos=0;i<N;i++){
            if(v[i]->preso==count){
                printf("%s ",v[i]->nome);
                free(v[i]->nome);
                free(v[i]);
                pos++;
                if(pos%8==0) //per visualizzare meglio l'output
                    printf("\n");
            }
        }
        printf("}\nCarico complessivo: %d\n-------------\n",best_value[count]);
    }
    free(best_value);
    free(s); free(v);
    printf("Fase 3 Completata...\n\n");
    printf("Ended with 0 errors\n");
    return 0;
}
void powerset(int pos,struct compiti **items,int *sol,int k,int cap,int curr_cap,int *bv,int *best_sol,int* flag){
    int j; //cap sta per med ovvero limite superiore del powerset
    if(pos>=k){ //terminazione
        if(curr_cap>*bv){
            for(j=0;j<k;j++)
                best_sol[j]=sol[j]; //soluzione migliore locale
            *bv=curr_cap; //massimo locale
        }
        if(*bv==cap) //cap = limite superiore = valore ottimale
            *flag=1; //Non prendo conto delle soluzioni simmetriche
        return;
    }
    if((curr_cap+items[pos]->lavoro)>cap||items[pos]->preso!=-1){ //pruning con controllo se è già stato preso
        sol[pos]=0;
        powerset(pos+1,items,sol,k,cap,curr_cap,bv,best_sol,flag);
        return;
    }
    if(*flag!=0) //pruning: controllo se siamo già arrivati al valore ottimale
        return;
    sol[pos]=1;
    curr_cap+=items[pos]->lavoro;
    powerset(pos+1,items,sol,k,cap,curr_cap,bv,best_sol,flag);
    sol[pos]=0; //backtraking
    curr_cap-=items[pos]->lavoro;
    powerset(pos+1,items,sol,k,cap,curr_cap,bv,best_sol,flag);
    return;
}
void media(int* med,int numr){ /* ***Media dei jobs pesata sulle risorse*** */
    float temp=*med; //Calcolo della media in float in modo da evitare troncamenti
    temp/=numr;
    temp+=0.9; //arrotondiamo per eccesso (32.1-->33)
    *med=temp; //riassegnazione della media pesata
    return; //Sarebbe stato più elegante usare una funzione inline ma non conosco ancora il loro funzionamento
}
/* COMMENTI:
La condizione di ottimalità sembra più che rispettata ma non avendo termini di paragone non posso giudicare efficacemente.
Se si utilizzassero variabili floating point si otterrebbe una più alta precisione nel calcolo e nella gestione dei
valori ottimali, soprattutto nel pruning del powerset e nell'utilizzo della media in generale.
Il programma sul mio i3 di casa utilizzando circa il 25% della cpu impiega più o meno 30 secondi per l'esecuzione con
1000 jobs, generati a random precendentemente, da associare a 26 risorse.
*/

