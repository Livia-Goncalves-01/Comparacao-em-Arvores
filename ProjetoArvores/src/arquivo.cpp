#include "./include/arquivo.hpp"

void readFile(int tamanho, TreeAVL **avl, TreeBIN **bin, TreeRB **rb, vector<float> *vetor, map<float, int> *valor_map, unordered_map<float, int> *valor_umap) {
	*avl = CreateTreeAVL();
	*bin = CreateTreeBIN();
	//*rb = CreateTreeRB();
	CreateTreeRB(rb);
	vetor->clear();
	valor_map->clear();
	valor_umap->clear();

	string caminho;
	Record r;

	caminho.assign("src/arquivos/entrada").append(to_string(tamanho)).append(".txt");

	ifstream myfile(caminho);
	string line;

	vector<duration<double>> tempos;
	vector<string >tempos_nome = { "AVL", "RB", "BINÁRIA", "MAP", "UMAP", "VECTOR" , "VEC ORDENADO" };
	steady_clock::time_point inicio = steady_clock::now();
	steady_clock::time_point fim = steady_clock::now();

	for (int i = 0; i < 7; i++) {
		tempos.push_back(inicio - inicio);
	}

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			r.key = stof(line);

			inicio = steady_clock::now();
			insertTreeAVL(avl, r);
			fim = steady_clock::now();
			tempos.at(0) += duration_cast<duration<double>>(fim - inicio);

			inicio = steady_clock::now();
			insertTreeRB(rb, rb, rb, r);
			fim = steady_clock::now();
			tempos.at(1) += duration_cast<duration<double>>(fim - inicio);

			inicio = steady_clock::now();
			insertTreeBIN(bin, r);
			fim = steady_clock::now();
			tempos.at(2) += duration_cast<duration<double>>(fim - inicio);

			inicio = steady_clock::now();
			valor_map->insert({ r.key, 0 });
			fim = steady_clock::now();
			tempos.at(3) += duration_cast<duration<double>>(fim - inicio);

			inicio = steady_clock::now();
			valor_umap->insert({ r.key, 0 });
			fim = steady_clock::now();
			tempos.at(4) += duration_cast<duration<double>>(fim - inicio);

			inicio = steady_clock::now();
			vetor->push_back(r.key);
			fim = steady_clock::now();
			tempos.at(5) += duration_cast<duration<double>>(fim - inicio);

		}

		inicio = steady_clock::now();
		sort(vetor->begin(), vetor->end());
		fim = steady_clock::now();
		tempos.at(6) += duration_cast<duration<double>>(fim - inicio);



		for (int i = 0; i < 7; i++) {
			cout << "Tempo de inserção: " << tempos_nome.at(i) << " : " << tempos.at(i).count() << endl;
		}

		system("read -p \"\nPressione enter para continuar...\" continue");
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

void criarArquivo(int tamanho) {
	string caminho;
	caminho.assign("src/arquivos/entrada").append(to_string(tamanho)).append(".txt");

	ofstream myfile(caminho);
	string line;


	if (myfile.is_open()) {

		for (int i = 0; i < tamanho; i++) {
			random_device seed;
			mt19937 gen(seed());
			uniform_real_distribution<float> dis(0, 100);
			myfile << dis(seed) << endl;
		}

		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

void criacaoPesquisa() {
	string caminho;
	caminho.assign("src/arquivos/pesquisa.txt");//tem 10000 entradas README

	ofstream saida(caminho);
	string line;
	//unordered_map<float, int> resultado;

	if (saida.is_open()) {

		for (int i = 0; i < 3450; i++) {
			random_device seed;
			mt19937 gen(seed());
			uniform_real_distribution<float> dis(0, 100);
			saida << dis(seed) << endl;
		}


		caminho.assign("src/arquivos/entrada500.txt");

		ifstream entrada500(caminho);

		if (entrada500.is_open()) {
			int cont = 0;
			while (getline(entrada500, line) && cont++ < 50) {
				saida << line << endl;
			}

			entrada500.close();
		} else cout << "Nao foi possivel abrir o arquivo 500" << endl;

		caminho.assign("src/arquivos/entrada5000.txt");

		ifstream entrada5000(caminho);

		if (entrada5000.is_open()) {
			int cont = 0;
			while (getline(entrada5000, line) && cont++ < 500) {
				saida << line << endl;
			}

			entrada5000.close();
		} else cout << "Nao foi possivel abrir o arquivo 5.000" << endl;

		caminho.assign("src/arquivos/entrada50000.txt");

		ifstream entrada50000(caminho);

		if (entrada50000.is_open()) {
			int cont = 0;
			while (getline(entrada50000, line) && cont++ < 3000) {
				saida << line << endl;
			}

			entrada50000.close();
		} else cout << "Nao foi possivel abrir o arquivo 50.000" << endl;

		caminho.assign("src/arquivos/entrada500000.txt");

		ifstream entrada500000(caminho);

		if (entrada500000.is_open()) {
			int cont = 0;
			while (getline(entrada500000, line) && cont++ < 3000) {
				saida << line << endl;
			}

			entrada500000.close();
		} else cout << "Nao foi possivel abrir o arquivo 500.000" << endl;

		saida.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

void lePesquisa(vector<string> *vetor) {
	string caminho, line;

	caminho.assign("src/arquivos/pesquisa.txt");

	ifstream pesquisa(caminho);

	if (pesquisa.is_open()) {
		int cont = 0;
		while (getline(pesquisa, line)) {
			vetor->push_back(line);
		}

		pesquisa.close();
	} else cout << "Nao foi possivel abrir o arquivo de pesquisa" << endl;

}