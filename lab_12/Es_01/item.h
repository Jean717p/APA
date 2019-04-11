#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

typedef struct Item *item;

item* Iteminit(int);
item riempiitem(char*,char*,int);
int itemcheck(item*,char*);
void itemgrade(item);
void itemgradeshow(item);
void itemcityshow(item);
int regcheck(item*,int,int);

#endif // ITEM_H_INCLUDED
