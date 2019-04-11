#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
typedef struct studente *link;
void cardinalita(link stud);
void inseriscitesta(link *stud,link *head,link *tail);
void inseriscicoda(link *stud,link *head,link *tail);
void stampa(link v);
void dealloc(link *testa);
void exhead(link *stud,link *head,link *tail);


#endif // BASE_H_INCLUDED
