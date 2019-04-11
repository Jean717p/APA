#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

#define EMPTYitem { -1, " " }
#define eq(A, B) (A == B)
#define neq(A, B) (A != B)
#define less(A, B) (A < B)
#define key(A) (A.x)
#define MAX 10

typedef struct { int x; char str[MAX]; } Item;
typedef int Key;

Item ITEMscan();
void ITEMshow(Item x);

#endif
