#include "./include/pesquisa.hpp"

void pesquisaGeral(int tamanho, TreeAVL **avl, TreeBIN **bin, TreeRB **rb,
	vector<float> *vetor, map<float, int> *valor_map, unordered_map<float, int> *valor_umap, vector<string> vetor_pesq) {

	vector<duration<double>> tempos;
	vector<string >tempos_nome = { "AVL", "RB", "BINÁRIA", "MAP", "UMAP", "VECTOR" };
	steady_clock::time_point inicio = steady_clock::now();
	steady_clock::time_point fim = steady_clock::now();

	Record r;
	TreeAVL *aux;
	TreeBIN *aux1;
	//TreeRB *aux2;
	//CreateTreeRB(&aux2); - Não é possível fazer outro CreateTreeRB em variaveis diferentes

	aux = CreateTreeAVL();
	aux1 = CreateTreeBIN();
	//aux2 = CreateTreeRB();

	for (int i = 0; i < tempos_nome.size(); i++) {
		tempos.push_back(inicio - inicio);
	}
	for (auto item : vetor_pesq) {
		r.key = stof(item);

		inicio = steady_clock::now();
		pesquisaAVL(avl, &aux, r);
		fim = steady_clock::now();
		tempos.at(0) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		pesquisaRB(rb, r);
		fim = steady_clock::now();
		tempos.at(1) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		pesquisaBIN(bin, &aux1, r);
		fim = steady_clock::now();
		tempos.at(2) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		if (valor_map->find(r.key) != valor_map->end()) {
			cout << "Map encontrou " << r.key << endl;
		}
		fim = steady_clock::now();
		tempos.at(3) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		if (valor_umap->find(r.key) != valor_umap->end()) {
			cout << "Umap encontrou " << r.key << endl;
		}
		fim = steady_clock::now();
		tempos.at(4) += duration_cast<duration<double>>(fim - inicio);

		inicio = steady_clock::now();
		if (binary_search(vetor->begin(), vetor->end(), r.key)) {
			cout << "Vector encontrou " << r.key << endl << endl;
		}
		fim = steady_clock::now();
		tempos.at(5) += duration_cast<duration<double>>(fim - inicio);
		//cout << endl;
	}

	for (int i = 0; i < tempos_nome.size(); i++) {
		cout << "Tempo de pesquisa: " << tempos_nome.at(i) << " : " << tempos.at(i).count() << endl;
	}
}
