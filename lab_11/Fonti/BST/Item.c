#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

Item ITEMscan()
{
    Item item;
    printf("integer = ");
    scanf("%d", &item.x);
    printf("string = ");
    scanf("%s", item.str);
    return item;

}

void ITEMshow(Item item)
{
    printf("integer = %4d  string = %s \n", item.x, item.str);
}
