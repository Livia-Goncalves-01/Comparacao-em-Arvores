#include "./include/binaria.hpp"

TreeBIN *CreateTreeBIN() {
	return NULL;
}

bool TVazia(TreeBIN **t) {
	return *t == NULL;
}

void insertTreeBIN(TreeBIN **t, Record r) {

	if (TVazia(t)) {
		*t = (TreeBIN *)malloc(sizeof(TreeBIN));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;

	} else {

		if (r.key < (*t)->reg.key) {
			insertTreeBIN(&(*t)->esq, r);
		}

		if (r.key > (*t)->reg.key) {
			insertTreeBIN(&(*t)->dir, r);
		}

	}

}

void pesquisaBIN(TreeBIN **t, TreeBIN **aux, Record r) {

	if (*t == NULL) {
		//printf("[ERROR]: Node not found!");
		return;
	}

	if ((*t)->reg.key > r.key) { pesquisaBIN(&(*t)->esq, aux, r); return; }
	if ((*t)->reg.key < r.key) { pesquisaBIN(&(*t)->dir, aux, r); return; }
	cout << "Binária encontrou " << r.key << endl;

	*aux = *t;
}


int isInTreeBIN(TreeBIN *t, Record r) {

	if (t == NULL) {
		return 0;
	}

	return t->reg.key == r.key || isInTreeBIN(t->esq, r) || isInTreeBIN(t->dir, r);
}


void antecessorBIN(TreeBIN **t, TreeBIN *aux) {

	if ((*t)->dir != NULL) {
		antecessorBIN(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}


void removeTreeBIN(TreeBIN **t, Record r) {
	TreeBIN *aux;

	if (*t == NULL) {
		//printf("[ERROR]: Record not found!!!\n");
		return;
	}

	if (r.key < (*t)->reg.key) { removeTreeBIN(&(*t)->esq, r); return; }
	if (r.key > (*t)->reg.key) { removeTreeBIN(&(*t)->dir, r); return; }
	//cout << "Binária removeu " << r.key << endl;

	if ((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);
		return;
	}

	if ((*t)->esq != NULL) { antecessorBIN(&(*t)->esq, *t); return; }

	aux = *t;
	*t = (*t)->dir;
	free(aux);
}


void preordemBIN(TreeBIN *t) {
	if (!(t == NULL)) {
		printf("%f ", t->reg.key);
		preordemBIN(t->esq);
		preordemBIN(t->dir);
	}
}


void centralBIN(TreeBIN *t) {
	if (!(t == NULL)) {
		centralBIN(t->esq);
		printf("%f ", t->reg.key);
		centralBIN(t->dir);
	}
}

void posordemBIN(TreeBIN *t) {
	if (!(t == NULL)) {
		posordemBIN(t->esq);
		posordemBIN(t->dir);
		printf("%f ", t->reg.key);
	}
}

