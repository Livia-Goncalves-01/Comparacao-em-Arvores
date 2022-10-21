#include "./include/remocao.hpp"

void remocaoGeral(int tamanho, TreeAVL **avl, TreeBIN **bin, TreeRB **rb,
	vector<float> *vetor, map<float, int> *valor_map, unordered_map<float, int> *valor_umap, vector<string> vetor_pesq) {

	map<float, int>::iterator it_map;
	unordered_map<float, int>::iterator it_umap;
	vector<float>::iterator it_vector;

	vector<duration<double>> tempos;
	vector<string >tempos_nome = { "AVL", "RB", "BINÁRIA", "MAP", "UMAP", "VECTOR" };
	steady_clock::time_point inicio = steady_clock::now();
	steady_clock::time_point fim = steady_clock::now();

	Record r;
	TreeAVL *aux;
	TreeBIN *aux1;
	TreeRB *aux2;

	aux = CreateTreeAVL();
	aux1 = CreateTreeBIN();
	//aux2 = CreateTreeRB();

	for (int i = 0; i < tempos_nome.size(); i++) {
		tempos.push_back(inicio - inicio);
	}
	for (auto item : vetor_pesq) {
		r.key = stof(item);

		inicio = steady_clock::now();
		removeTreeAVL(avl, avl, r);
		fim = steady_clock::now();
		tempos.at(0) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		search_delete(rb, *rb, r);
		fim = steady_clock::now();
		tempos.at(1) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		removeTreeBIN(bin, r);
		fim = steady_clock::now();
		tempos.at(2) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		it_map = valor_map->find(r.key);
		if (it_map != valor_map->end()) {
			valor_map->erase(it_map);
			//cout << "Map removeu " << r.key << endl;
		}
		fim = steady_clock::now();
		tempos.at(3) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		it_umap = valor_umap->find(r.key);
		if (valor_umap->find(r.key) != valor_umap->end()) {
			valor_umap->erase(it_umap);
			//cout << "Umap removeu " << r.key << endl;
		}
		fim = steady_clock::now();
		tempos.at(4) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		if (binary_search(vetor->begin(), vetor->end(), r.key)) {
			it_vector = find(vetor->begin(), vetor->end(), r.key);
			if (it_vector != vetor->end()) {
				vetor->erase(it_vector);
				//cout << "Vector removeu " << r.key << endl;
			}
		}
		fim = steady_clock::now();
		tempos.at(5) += duration_cast<duration<double>>(fim - inicio);
	}
	cout << endl;
	for (int i = 0; i < tempos_nome.size(); i++) {
		cout << "Tempo de Remoção: " << tempos_nome.at(i) << " : " << tempos.at(i).count() << endl;
	}
}
