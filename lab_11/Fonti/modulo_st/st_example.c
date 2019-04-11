/**CFile***********************************************************************
  FileName    [st_example.c]
  PackageName [st]
  Synopsis    [Symbol table example.]
  Description [Esempio di utilizzo del pacchetto ST.
               Questo semplice programma legge delle stringhe da tastiera,
               fino a quando non viene inserita la stringa FINE. Per ogni
               parola, viene effettuata una ricerca in una tabella di hash,
               gestita dal pacchetto ST. Se la parola non viene individuata,
               essa viene aggiunta nella tabella stessa, assieme ad una
               variabile intera ("num") inizializzata al valore 1. Altrimenti 
               (ovvero, se la stringa era stata precedentemente inserita), il 
               valore di questa stessa variabile viene incrementato.
               Si noti che la stringa usata come chiave per la funzione
               di hash e' anche uno dei campi della struttura che viene 
               salvata nella tabella. Questo, in generale, non e' necessario.
               Infine, prima di terminare l'esecuzione, il programma stampa
               tutte le chiavi e i valori presenti nella tabella di hash.]
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "st.h"

typedef struct data_s {
        char *str;
        int num;
} data_t;

int main(int argc, char *argv[])
{
  char buf[100], *key;
  data_t *data;
  st_table *st;
  st_generator *gen;
   
  /* inizializza una ST utilizzando una stringa come chiave */
  st = st_init_table(strcmp, st_strhash);
  do {
     printf("Inserisci una parola ");
     printf("(FINE per finire): ");
     scanf("%s", buf);
     if (strcmp(buf, "FINE") != 0) {
        /* cerca la chiave nella ST */
        if (st_lookup(st, (void *)buf, (void *)&data)) {
           printf("Parola trovata ");
           printf("(inserita in tutto %d volte)\n\n", ++data->num);
        } else {
           /* inserisce un elemento nella ST corrispondente alla chiave */
           printf("Parola NON trovata --> memorizzo\n");
           data = (data_t *)malloc(sizeof(data_t));
           data->str = strdup(buf);
           data->num = 1;
           st_insert(st, data->str, data);
           printf("Totale parole memorizzate: %d\n\n", st_count(st));
        }
     } 
  } while (strcmp(buf, "FINE") != 0);

  /* ciclo per stampare tutti gli elementi e liberare la memoria */
  printf("\nContenuto della tabella:\n");
  st_foreach_item(st, gen, &key, &data) {
     printf("Chiave \"%s\"  ---  contatore %d\n", (char *)key, data->num);
     free(data->str); 
     free(data);
  }
  printf("\n");
  st_free_table(st);

  system("PAUSE");	
  return 0;
}
