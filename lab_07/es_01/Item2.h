#ifndef ITEM2_H_INCLUDED
#define ITEM2_H_INCLUDED
#define N 35+1

typedef struct item *link;
typedef struct item{
    char frase[N];
    int numero;
}item;

void riempi2();
void scrivi2();
void incidi2();
void load2();
void libera2();

#endif // ITEM2_H_INCLUDED
