#include "./include/arquivo.hpp"
#include "./include/pesquisa.hpp"
#include "./include/remocao.hpp"

int main() {

	// criarArquivo(500);
	// criarArquivo(5000);
	// criarArquivo(50000);
	// criarArquivo(500000);
	// criacaoPesquisa();

	TreeAVL *avl;
	TreeBIN *bin;
	TreeRB *rb;
	vector<float> vetor;
	vector<string> vetor_pesq;
	map<float, int> valor_map;
	unordered_map<float, int> valor_umap;
	int menu;
	lePesquisa(&vetor_pesq);

	cout << "Escolha uma opção de volume de dados : 1- 500 valores; 2 - 5.000 valores; 3 - 50.000 valores; 4 - 500.000 valores." << endl;
	cin >> menu;
	switch (menu) {
	case 1:
		readFile(500, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap);
		pesquisaGeral(500, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		remocaoGeral(500, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		break;
	case 2:
		readFile(5000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap);
		pesquisaGeral(5000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		remocaoGeral(5000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		break;
	case 3:
		readFile(50000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap);
		pesquisaGeral(50000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		remocaoGeral(50000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		break;
	case 4:
		readFile(500000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap);
		pesquisaGeral(500000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		remocaoGeral(500000, &avl, &bin, &rb, &vetor, &valor_map, &valor_umap, vetor_pesq);
		break;
	default:
		cout << "Opção inválida." << endl;
		break;
	}


	// centralAVL(avl);
	// cout << endl;
	// centralBIN(bin);
	// cout << endl;
	// centralRB(rb);
	// cout << endl;


}
