#include <stdlib.h>
#include "Item.h"
#include "BST.h"


typedef struct BSTnode* link;
struct BSTnode { Item item; link p; link l; link  r; int N; } ;

struct binarysearchtree { link head; int N; link z; };

Item NULLitem = EMPTYitem;

link NEW(Item item, link p, link l, link r, int N)
{
    link x = malloc(sizeof *x);
    x->item = item; x->p = p; x->l = l; x->r = r; x->N = N;
    return x;
}

BST BSTinit( )
{
    BST bst = malloc(sizeof *bst) ;
    bst->N = 0;
    bst->head = ( bst->z = NEW(NULLitem, NULL, NULL, NULL, 0));
    return bst;
}

int BSTcount(BST bst)
{
    return bst->N;
}

int BSTempty(BST bst)
{
    if ( BSTcount(bst) == 0)
        return 1;
    else
        return 0;
}

Item minR(link h, link z)
{
    if (h == z)
        return NULLitem;
    if (h->l == z)
        return (h->item);
    return minR(h->l, z);
}

Item BSTmin(BST bst)
{
    return minR(bst->head, bst->z);
}

Item maxR(link h, link z)
{
    if (h == z)
        return NULLitem;
    if (h->r == z)
        return (h->item);
    return maxR(h->r, z);
}

Item BSTmax(BST bst)
{
    return maxR(bst->head, bst->z);
}

Item searchR(link h, Key k, link z)
{
    if (h == z)
        return NULLitem;
    if (eq(k, key(h->item)))
        return h->item;
    if (less(k, key(h->item)))
        return searchR(h->l, k, z);
    else
        return searchR(h->r, k, z);
  }

Item BSTsearch(BST bst, Key k)
{
    return searchR(bst->head, k, bst->z);
}

link insertR(link h, Item x, link z)
{
    if (h == z)
        return NEW(x, z, z, z, 1);
    if (less(key(x), key(h->item)))
    {
        h->l = insertR(h->l, x, z);
        h->l->p = h;
    }
    else
    {
        h->r = insertR(h->r, x, z);
        h->r->p = h;
    }
    (h->N)++;
    return h;
}

void BSTinsert_leafR(BST bst, Item x)
{
    bst->head = insertR(bst->head, x, bst->z);
    bst->N++;
}

void BSTinsert_leafI(BST bst, Item x)
{
    link p = bst->head, h = p;
    if (bst->head == bst->z)
    {
        bst->head = NEW(x, bst->z, bst->z, bst->z, 1);
        bst->N++;
        return;
    }
    while (h != bst->z)
    {
        p = h;
        h->N++;
        h = less(key(x), key(h->item))? h->l : h->r;
    }
    h = NEW(x, p, bst->z, bst->z, 1);
    bst->N++;
    if (less(key(x), key(p->item)))
        p->l = h;
    else
        p->r = h;
}

link rotR(link h)
{
    link x = h->l;
    h->l = x->r;
    x->r->p = h;
    x->r = h;
    x->p = h->p;
    h->p = x;
    x->N = h->N;
    h->N = h->r->N + h->l->N +1;
    return x;
}

link rotL(link h)
{
    link x = h->r;
    h->r = x->l;
    x->l->p = h;
    x->l = h;
    x->p = h->p;
    h->p = x;
    x->N = h->N;
    h->N = h->l->N + h->r->N +1;
    return x;
}

//  STinsert in root recursive version

link insertT(link h, Item x, link z)
{
    if ( h == z)
        return NEW(x, z, z, z, 1);
    if (less(key(x), key(h->item)))
    {
        h->l = insertT(h->l, x, z);
        h = rotR(h);
        h->N++;
    }
    else
    {
        h->r = insertT(h->r, x, z);
        h = rotL(h);
        h->N++;
    }
    return h;
}

void BSTinsert_root(BST bst, Item x)
{
    bst->head = insertT(bst->head, x, bst->z);
    bst->N++;
}

void sortinorderR(link h, void (*visit) (Item), link z)
{
    if (h == z)
        return;
    sortinorderR(h->l, visit, z);
    visit(h->item);
    sortinorderR(h->r, visit, z);
}

void BSTsortinorder(BST bst, void (*visit)(Item))
{
    sortinorderR(bst->head, visit, bst->z);
}

void sortpostorderR(link h, void (*visit) (Item), link z)
{
    if (h == z)
        return;
    sortpostorderR(h->l, visit, z);
    sortpostorderR(h->r, visit, z);
    visit(h->item);

}

void BSTsortpostorder(BST bst, void (*visit)(Item))
{
    sortpostorderR(bst->head, visit, bst->z);
}

void sortpreorderR(link h, void (*visit) (Item), link z)
{
    if (h == z)
        return;
    visit(h->item);
    sortpreorderR(h->l, visit, z);
    sortpreorderR(h->r, visit, z);
}

void BSTsortpreorder(BST bst, void (*visit)(Item))
{
    sortpreorderR(bst->head, visit, bst->z);
}

Item selectR(link h, int k, link z)
{
    int t;
    if (h == z)
        return NULLitem;
    t = (h->l == z) ? 0 : h->l->N;
    if (t > k)
        return selectR(h->l, k, z);
    if (t < k)
        return selectR(h->r, k-t-1, z);
    return h->item;
}

Item BSTselect(BST bst, int k)
{
    return selectR(bst->head, k, bst->z);
}

link partR(link h, int k)
{
    int t  = h->l->N;
    if ( t > k)
    {
        h->l = partR(h->l, k);
        h = rotR(h);
    }
    if ( t < k)
    {
        h->r = partR(h->r, k-t-1);
        h = rotL(h);
    }
   	return h;
}

link joinLR(link a, link b, link z)
{
    if (b == z)
        return a;
    b = partR(b, 0);
    b->l = a;
    a->p = b;
    b->N = a->N + b->r->N +1;
    return b;
}

link deleteR(link h, Item x, link z)
{
    link y, p;
    if (h == z)
        return z;
    if (less(key(x), key(h->item)))
        h->l = deleteR(h->l, x, z);
    if (less(key(h->item), key(x)))
        h->r = deleteR(h->r, x, z);
    (h->N)--;
    if (eq(key(x), key(h->item)))
    {
        y = h;
        p = h->p;
        h = joinLR(h->l, h->r, z);
        h->p = p;
        free(y);
    }
    return h;
}

void BSTdelete(BST bst, Item x)
{
    bst->head = deleteR(bst->head, x, bst->z);
    bst->N--;
}


Item searchSucc(link h, Item x, link z)
{
    link p;
    if (h == z)
        return NULLitem;
    if (eq(key(x), key(h->item)))
    {
        if (h->r != z)
            return minR(h->r, z);
        else
        {
            p = h->p;
            while (p != z && h == p->r)
            {
                h = p;
                p = p->p;
            }
            return p->item;
        }
    }
    if (less(key(x), key(h->item)))
        return searchSucc(h->l, x, z);
    else
        return searchSucc(h->r, x, z);

}

Item BSTsucc(BST bst, Item x)
{
    return searchSucc(bst->head, x, bst->z);
}

Item searchPred(link h, Item x, link z)
{
    link p;
    if (h == z)
        return NULLitem;
    if (eq(key(x), key(h->item)))
    {
        if (h->l != z)
            return maxR(h->l, z);
        else
        {
            p = h->p;
            while (p != z && h == p->l)
            {
                h = p;
                p = p->p;
            }
            return p->item;
        }
    }
    if (less(key(x), key(h->item)))
        return searchPred(h->l, x, z);
    else
        return searchPred(h->r, x, z);

}

Item BSTpred(BST bst, Item x)
{
    return searchPred(bst->head, x, bst->z);
}

