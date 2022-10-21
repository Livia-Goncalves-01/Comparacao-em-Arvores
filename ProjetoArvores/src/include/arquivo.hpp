#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include "avl.hpp"
#include "binaria.hpp"
#include "rb.hpp"

#include <random>
#include <fstream>


void readFile(int tamanho, TreeAVL **avl, TreeBIN **bin, TreeRB **rb,
	vector<float> *vetor, map<float, int> *valor_map, unordered_map<float, int> *valor_umap);
void criarArquivo(int tamanho);
void criacaoPesquisa();
void lePesquisa(vector<string> *vetor);

#endif