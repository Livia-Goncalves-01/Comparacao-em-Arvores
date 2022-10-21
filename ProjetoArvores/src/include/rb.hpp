#ifndef RB_HPP
#define RB_HPP

#include "shared.hpp"

typedef struct TreeRB {
	Record reg;
	TreeRB *esq, *dir;
	TreeRB *pai;
	bool cor;
} TreeRB;


//TreeRB *CreateTreeRB();
void CreateTreeRB(TreeRB **root);

void rotacaoEsquerda(TreeRB **raiz, TreeRB *child);
void rotacaoDireita(TreeRB **raiz, TreeRB *child);

void insertFixUp(TreeRB **raiz, TreeRB *child);
void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, Record r);
void pesquisaRB(TreeRB **t, Record r);
void search_delete(TreeRB **root, TreeRB *aux, Record z);
void RB_delete_fix(TreeRB **root, TreeRB *x, TreeRB *w);
void RB_delete(TreeRB **root, TreeRB *z, TreeRB *y, TreeRB *x);
void RB_transplant(TreeRB **root, TreeRB *aux, TreeRB *auxchild);
TreeRB *tree_successor(TreeRB *aux_succ);

void preordemRB(TreeRB *t);
void centralRB(TreeRB *t);
void posordemRB(TreeRB *t);


#endif