#ifndef AVL_HPP
#define AVL_HPP

#include "shared.hpp"

typedef struct TreeAVL {
	Record reg;
	TreeAVL *left, *right;
	int weight;
}TreeAVL;

TreeAVL *CreateTreeAVL();
void insertTreeAVL(TreeAVL **t, Record r);
void pesquisaAVL(TreeAVL **t, TreeAVL **aux, Record r);
int isInTreeAVL(TreeAVL *t, Record r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTreeAVL(TreeAVL **t, TreeAVL **f, Record r);
void antecessorAVL(TreeAVL **t, TreeAVL *aux);
void rebalanceTreeAVL(TreeAVL **t);

void preordemAVL(TreeAVL *t);
void centralAVL(TreeAVL *t);
void posordemAVL(TreeAVL *t);


int getWeight(TreeAVL **t);
int getMaxWeight(int left, int right);


void rotacaoSimplesDireita(TreeAVL **t);
void rotacaoSimplesEsquerda(TreeAVL **t);
void rotacaoDuplaDireita(TreeAVL **t);
void rotacaoDuplaEsquerda(TreeAVL **t);


#endif