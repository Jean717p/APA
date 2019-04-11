#ifndef PQ_H_DEFINED
#define PQ_H_DEFINED

typedef struct pqueue *PQ;

PQ      PQUEUEinit();
void    PQUEUEnewinsert(PQ);
void    PQUEUEextractMax(PQ);
void    PQUEUEprinf(PQ);
void    PQUEUEupload(PQ,FILE*);
void    PQUEUEdestruction(PQ);

#endif
