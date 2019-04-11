#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void instringa(char frase[],char **stringhe,int i);
void delstringa(char frase[],char **stringhe,int* i);
void stampa(char **stringhe,int i);
int ricerca(char** stringhe,int i,char astr[]);
int main()
{
    char op,astr[25+1],**stringhe={NULL};
    int flag=0,numstr=0;
    stringhe=(char**)malloc(100);
    while(flag==0){
        printf("***Menu***\n\n");
        printf("Digitare:\nn  -per introdurre una nuova stringa\n");
        printf("e  -per eliminare una stringa\n");
        printf("c  -per effettuare ricerche binarie (dicotomiche)\n");
        printf("p  -per stampare\n");
        printf("q  -per uscire.\n");
        fflush(stdin);
        printf("\nComando: "); scanf("%c",&op);
        switch(op){
            case 'n': { if(numstr>=99){
                        printf("Vettore stringhe pieno\n"); break;}
                        printf("Inserire una frase: ");
                        fflush(stdin); gets(astr);
                        if(strlen(astr)>0&&strlen(astr)<=25){
                            numstr++;
                            instringa(astr,(stringhe),numstr);
                        }
                        else printf("\nInserimento non valido.\n");
                        break;}

            case 'e':   printf("Inserire la frase da eliminare: ");
                        fflush(stdin); gets(astr);
                        if(strlen(astr)>0&&strlen(astr)<25&&numstr>0)
                        delstringa(astr,stringhe,&numstr);
                        else printf("\nInserimento non valido.\n");
                        break;

            case 'c':   printf("Inserisci la stringa da cercare: ");
                        scanf("%s",astr); printf("\n");
                        flag = ricerca(stringhe,numstr,astr);
                        if(flag!=-1)
                            printf("L'elemento e' stato trovato in posizione %d\n", flag-1);
                        else printf("Valore non trovato\n");
                        flag=0; break;

            case 'p':   if(numstr<=0){
                            printf("Nessuna parola in elenco.\n");}
                        else{
                            fflush(stdout); fflush(stdin);
                            stampa(stringhe,numstr);
                        }
                        break;

            case 'q': flag=1; break;

            default: printf("Inserimento non valido.\n");
        }
        printf("\n");
        system("pause");
        printf("\n\n");
    }
    return 0;
}
void instringa(char frase[],char **stringhe,int i){
    char *temp;
    int j,k;
    (stringhe)[i] =(char*)malloc((strlen(frase)+1)*sizeof(char));
    strcpy((stringhe)[i],frase);
    if((stringhe)[i]!=NULL){
    printf("\nInserita con successo!\n");
    for(j=0;j<i-1;j++){
        for(k=j+1;k<i;k++){
            if((strcmp((stringhe)[j],(stringhe)[k]))>0){
                temp = (stringhe)[j];
                (stringhe)[j]= (stringhe)[k];
                (stringhe)[k]= temp;
            }
        }
    }}
    return;
}
void delstringa(char frase[],char **stringhe,int* i){ //cancella stringa
    int j,numdeleted=0,k;
    for(j=0;j<=*i;j++){
        if(strcmp(frase,(stringhe)[j])==0){
            for(k=j;k<(*i);k++){
                (stringhe)[k]=(stringhe)[k+1];
                }
            numdeleted++;}
        }
    if(numdeleted!=0){
    *i -= numdeleted;
    printf("\n%d frase/i cancellata/e con successo!\n",numdeleted);}
    else printf("Frase non trovata.\n");
    return;
}
void stampa(char **stringhe,int i){ //stampa
    int j;
    for(j=0;j<=i;j++){
        printf("%s\n",(stringhe)[j]);
    }
    return;
}
int ricerca(char** stringhe,int i,char astr[]){ //ricerca dicotomica (binaria)
    int sx=0,dx=i,trovato=0,md;
    while(sx<=dx && (!trovato)){
        md=(sx+dx)/2;
        if(strcmp(stringhe[md],astr)==0)
            trovato=1;
        else if(strcmp(astr,stringhe[md])>0)
            sx=md+1;
        else
            dx=md-1;
    }
    if(trovato)
        return md;
    else
        return -1;
}
