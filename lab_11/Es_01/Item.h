#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

typedef struct Item* item;

item EMPTYitem();
int eq(int,item);
int less(int,item);
int ITEMless(item,item);
item ITEMscan();
void ITEMshow(item);
void ITEMwrite(item,FILE*);
void ITEMcount(int*,FILE*);
item ITEMupload(FILE*);
void ITEMfree(item);

#endif
