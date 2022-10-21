#include "./include/rb.hpp"

TreeRB *nill;
// TreeRB *CreateTreeRB() {
// 	return nill;
// }

void CreateTreeRB(TreeRB **root) {
	nill = (TreeRB *)malloc(sizeof(TreeRB));
	nill->cor = true;
	nill->esq = NULL;
	nill->dir = NULL;
	nill->pai = NULL;
	nill->reg.key = 0;
	(*root) = nill;
}


void insertFixUp(TreeRB **raiz, TreeRB *child) {
	TreeRB *tio;

	while ((child != *raiz) && (child->pai->cor == false)) {

		if (child->pai == child->pai->pai->esq) {

			tio = child->pai->pai->dir;

			//caso 1:
			if ((tio != nill) && (tio->cor == false)) {
				child->pai->cor = true;
				tio->cor = true;
				child->pai->pai->cor = false;
				child = child->pai->pai;

			} else {

				//caso 2
				if (child == child->pai->dir) {
					child = child->pai;
					rotacaoEsquerda(raiz, child);
				}

				//caso 3
				child->pai->cor = true;
				child->pai->pai->cor = false;
				rotacaoDireita(raiz, child->pai->pai);
			}

		} else {

			tio = child->pai->pai->esq;

			//caso 1
			if ((tio != nill) && (tio->cor == false)) {
				child->pai->cor = true;
				tio->cor = true;
				child->pai->pai->cor = false;
				child = child->pai->pai;

			} else {

				//caso 2
				if (child == child->pai->esq) {
					child = child->pai;
					rotacaoDireita(raiz, child);
				}

				//caso 3
				child->pai->cor = true;
				child->pai->pai->cor = false;
				rotacaoEsquerda(raiz, child->pai->pai);
			}

		}

	}

	(*raiz)->cor = true;
}


void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, Record r) {

	if (*t == nill) {
		*t = (TreeRB *)malloc(sizeof(TreeRB));
		(*t)->esq = nill;
		(*t)->dir = nill;
		(*t)->pai = pai != t ? *pai : nill;
		(*t)->cor = false; //false: vermelho  true:preto
		(*t)->reg = r;
		insertFixUp(raiz, *t);

	} else {

		if (r.key < (*t)->reg.key) {
			insertTreeRB(&(*t)->esq, t, raiz, r);
			return;
		}

		if (r.key > (*t)->reg.key) {
			insertTreeRB(&(*t)->dir, t, raiz, r);
			return;
		}

	}

}


void pesquisaRB(TreeRB **t, Record r) {

	if (*t == nill) {
		//printf("[ERROR]: Node not found!");
		return;
	}

	if ((*t)->reg.key > r.key) { pesquisaRB(&(*t)->esq, r); return; }
	if ((*t)->reg.key < r.key) { pesquisaRB(&(*t)->dir, r); return; }
	cout << "RedBlack encontrou " << r.key << endl;
	//*aux = *t;
}

void rotacaoEsquerda(TreeRB **raiz, TreeRB *child) {
	TreeRB *x, *y;

	x = child;
	y = child->dir;
	x->dir = y->esq;

	if (y->esq != nill)
		y->esq->pai = x;

	y->pai = x->pai;

	if (x->pai == nill)
		*raiz = y;

	else {

		if (x == x->pai->esq)
			x->pai->esq = y;

		else
			x->pai->dir = y;

	}

	y->esq = x;
	x->pai = y;
}


void rotacaoDireita(TreeRB **raiz, TreeRB *child) {
	TreeRB *x, *y;

	x = child;
	y = child->esq;
	x->esq = y->dir;

	if (y->dir != nill)
		y->dir->pai = x;

	y->pai = x->pai;

	if (x->pai == nill) {
		*raiz = y;
	}

	else {

		if (x == x->pai->dir)
			x->pai->dir = y;

		else
			x->pai->esq = y;

	}

	y->dir = x;
	x->pai = y;

}


void preordemRB(TreeRB *t) {
	if (!(t == nill)) {
		printf("%f - %s\t", t->reg.key, t->cor ? "true" : "false");
		preordemRB(t->esq);
		preordemRB(t->dir);
	}
}


void centralRB(TreeRB *t) {
	if (!(t == nill)) {
		centralRB(t->esq);
		printf("%f - %s\t", t->reg.key, t->cor ? "true" : "false");
		centralRB(t->dir);
	}
}

void posordemRB(TreeRB *t) {
	if (!(t == nill)) {
		posordemRB(t->esq);
		posordemRB(t->dir);
		printf("%f - %s\t", t->reg.key, t->cor ? "true" : "false");
	}
}

void search_delete(TreeRB **root, TreeRB *aux, Record z) {
	while (aux != nill && z.key != aux->reg.key) {
		if (z.key < aux->reg.key)
			aux = aux->esq;
		else
			aux = aux->dir;
	}
	if (aux->reg.key == z.key) {
		//se entrar aqui é pq achou
		RB_delete(root, aux, aux, aux);
	}
}

void RB_delete_fix(TreeRB **root, TreeRB *x, TreeRB *w) {
	while (x != (*root) && x->cor == true) {
		if (x == x->pai->esq) {
			w = x->pai->dir;
			if (w->cor == false) {
				w->cor = true;
				x->pai->cor = false;
				rotacaoEsquerda(root, x->pai);
				w = x->pai->dir;
			} else if (w->esq->cor == true && w->dir->cor == true) {
				w->cor = false;
				x = x->pai;
			} else if (w->dir->cor == true) {
				w->esq->cor = true;
				w->cor = false;
				rotacaoDireita(root, w);
				w = x->pai->dir;
			} else {
				w->cor = x->pai->cor;
				x->pai->cor = true;
				w->dir->cor = true;
				rotacaoEsquerda(root, x->pai);
				x = (*root);
			}
		} else {
			w = x->pai->esq;
			if (w->cor == false) {
				w->cor = true;
				x->pai->cor = false;
				rotacaoDireita(root, x->pai);
				w = x->pai->esq;
			} else if (w->dir->cor == true && w->esq->cor == true) {
				w->cor = false;
				x = x->pai;
			} else if (w->esq->cor == true) {
				w->dir->cor = true;
				w->cor = false;
				rotacaoEsquerda(root, w);
				w = x->pai->esq;
			} else {
				w->cor = x->pai->cor;
				x->pai->cor = true;
				w->esq->cor = true;
				rotacaoDireita(root, x->pai);
				x = (*root);
			}
		}
	}
	x->cor = true;
}

void RB_delete(TreeRB **root, TreeRB *z, TreeRB *y, TreeRB *x) {
	//enum type originalcolor;
	bool originalcolor = y->cor;

	//case 1
	if (z->esq == nill) {
		x = z->dir;
		RB_transplant(root, z, z->dir);
	}
	//case 2
	else if (z->dir == nill) {
		x = z->esq;
		RB_transplant(root, z, z->esq);
	}

	else {
		y = tree_successor(z->dir);
		originalcolor = y->cor;
		x = y->dir;

		if (y->pai == z) {
			x->pai = y;
		}

		else {
			RB_transplant(root, y, y->dir);
			y->dir = z->dir;
			y->dir->pai = y;
		}

		RB_transplant(root, z, y);
		y->esq = z->esq;
		y->esq->pai = y;
		y->cor = z->cor;
	}

	if (originalcolor == true)
		RB_delete_fix(root, x, x);
	free(z);
}


void RB_transplant(TreeRB **root, TreeRB *aux, TreeRB *auxchild) {
	if (aux->pai == nill)
		(*root) = auxchild;
	else if (aux == aux->pai->esq)
		aux->pai->esq = auxchild;
	else
		aux->pai->dir = auxchild;
	auxchild->pai = aux->pai;
}

TreeRB *tree_successor(TreeRB *aux_succ) {
	while (aux_succ->esq != nill)
		aux_succ = aux_succ->esq;
	return aux_succ;
}
