#ifndef TREE_HPP
#define TREE_HPP

#include "shared.hpp"

typedef struct TreeBIN {
	Record reg;
	TreeBIN *esq, *dir;
} TreeBIN;

TreeBIN *CreateTreeBIN();
bool TVazia(TreeBIN **t);
void insertTreeBIN(TreeBIN **t, Record r);
void pesquisaBIN(TreeBIN **t, TreeBIN **aux, Record r);
int isInTreeBIN(TreeBIN *t, Record r);

void removeTreeBIN(TreeBIN **t, Record r);
void antecessorBIN(TreeBIN **t, TreeBIN *aux);

void preordemBIN(TreeBIN *t);
void centralBIN(TreeBIN *t);
void posordemBIN(TreeBIN *t);

#endif