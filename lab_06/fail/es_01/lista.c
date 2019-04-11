#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib1.h"
#include "base.h"
//void ricerca(studente stud,studente head);
void menu1(){
    printf("\t\t***Menu'***\n");
    printf("Digitare 1 per visualizzare la cardinalita' della lista\n");
    printf("Digitare 2 per inserire un elemento in testa\n");
    printf("Digitare 3 per inserire un elemento in coda\n");
    printf("Digitare 4 per ricercare un elemento attraverso una keyword\n");
    printf("Digitare 5 per estrarre un elemento attraverso una keyword\n");
    printf("Digitare 6 per visualizzare la lista\n");
    printf("Digitare 7 per distruggere la lista\n");
    printf("Digitare 8 per uscire.\n");
}
void scelta1(int op,Studente *stud,Studente *head,Studente *tail){
    switch(op){
        case 1: *stud=*head;
                cardinalita((*stud));
                break;
        case 2: inserisci(&(*stud),&(*head),&(*tail));
                break;
        case 3: inseriscicoda(&(*stud),&(*head),&(*tail));
                break;
        case 4: //ricerca(*stud,*head);
        case 5:
        case 6: stampa(*head); break;
        case 7: dealloc(&(*stud),&(*tail));
                break;
        }
    return;
}
//void ricerca(studente stud,studente head){
//    int ap=0,flag=0; char temp[35+1];
//    stud=head;
//    if(head==NULL)
//        return;
//    do{
//        printf("Digitare il campo di ricerca:\n");
//        printf("1 per nome\n2 per cognome\n3 per matricola\n");
//        scanf("%d",&ap);
//        if(ap<1||ap>3)
//            ap=0;
//    }while(ap==0);
//    printf("Inserire keyword:"); fflush(stdin); gets(temp);
//    while(stud!=NULL){
//        flag=0;
//        if(ap==1){
//            if(strcmp(stud->nome,temp)==0){
//                flag=1;
//            }
//        }
//        else if(ap==2){
//            if(strcmp(stud->cognome,temp)==0){
//                flag=1;
//            }
//        }
//        else{
//            if(strcmp(stud->matricola,temp)==0){
//                flag=1;
//            }
//        }
//        if(flag==1){
//            printf("%s %s %s ",stud->nome,stud->cognome,stud->matricola);
//            printf("%d %.2f\n",stud->status.crediti,stud->status.media);
//        }
//    }
//    return;
//}
