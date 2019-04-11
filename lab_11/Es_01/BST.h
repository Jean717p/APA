#ifndef BST_H_DEFINED
#define BST_H_DEFINED

typedef struct alberodiricercabinario *BST;

BST	    BSTinit();
void 	BSTinsert_leafR(BST);
void 	BSTinsert_root(BST);
void	BSTsearch(BST,int);
void    BSTmin_max(BST);
void    stampa(BST);
void	BSTcount(BST);
void    BSTnumnodi(BST);
void    BSTnumfoglie(BST);
void    BSTsave(BST,FILE*);
void    BSTupload(BST,FILE*);
void    BSTdestruction(BST);

#endif
