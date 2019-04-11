#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

typedef struct Item* item;

item ITEMscan();
int ITEMless(item,item);
void ITEMshow(item);
void ITEMfree(item);
void ITEMcount(int*,FILE*);
item ITEMupload(FILE*);

#endif
