#ifndef REMOCAO_HPP
#define REMOCAO_HPP

#include "shared.hpp"
#include "avl.hpp"
#include "rb.hpp"
#include "binaria.hpp"

void remocaoGeral(int tamanho, TreeAVL **avl, TreeBIN **bin, TreeRB **rb,
	vector<float> *vetor, map<float, int> *valor_map, unordered_map<float, int> *valor_umap, vector<string> vetor_pesq);

#endif