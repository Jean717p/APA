#ifndef BST_H_DEFINED
#define BST_H_DEFINED

typedef struct  binarysearchtree *BST;

BST	    BSTinit() ;
int		BSTcount(BST) ;
int     BSTempty(BST) ;
Item    BSTmin(BST) ;
Item    BSTmax(BST) ;
void 	BSTinsert_leafI(BST,Item) ;
void 	BSTinsert_leafR(BST,Item) ;
void 	BSTinsert_root(BST,Item) ;
Item	BSTsearch(BST,Key) ;
void	BSTdelete(BST,Item) ;
Item 	BSTselect(BST,int) ;
void	BSTsortinorder(BST,void (*visit) (Item)) ;
void	BSTsortpreorder(BST,void (*visit) (Item)) ;
void	BSTsortpostorder(BST,void (*visit) (Item)) ;
Item	BSTsucc(BST,Item) ;
Item	BSTpred(BST,Item) ;

#endif
