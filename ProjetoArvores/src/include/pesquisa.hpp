#ifndef PESQUISA_HPP
#define PESQUISA_HPP

#include "shared.hpp"
#include "avl.hpp"
#include "rb.hpp"
#include "binaria.hpp"

void pesquisaGeral(int tamanho, TreeAVL **avl, TreeBIN **bin, TreeRB **rb,
	vector<float> *vetor, map<float, int> *valor_map, unordered_map<float, int> *valor_umap, vector<string> vetor_pesq);

#endif