# Comparação das Estruturas em Árvores

## Objetivo

Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) - Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2) - Qual o tempo necessário para montar a estrutura em memória. 

3) - Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4) - Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?

Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise. 

## Resultados das comparações

Para obter um tempo médio dos resultados e tornar mais acertivo as comparações foi realizado 10 medições de cada volume de dados, tanto inserção, remoção e pesquisa de cada árvore. Esses testes foram realizados em um computador com Intel (R) Core (TM) i5-11400F @ 2.60GHz com 16 GB de RAM no Visual Studio utilizando-se o WSL do Ubuntu. 
Como resultados obteve-se:

### 500 dados

![image](https://user-images.githubusercontent.com/95262005/197090791-0f6124c5-d6f8-4cd9-b54c-fef0008439a7.png)

### 5000 dados

![image](https://user-images.githubusercontent.com/95262005/197091096-586311c1-8a86-487d-bb5b-546f58df4837.png)

### 50000 dados

![image](https://user-images.githubusercontent.com/95262005/197091135-c011cbce-2a6c-4570-82e0-09e21a324f54.png)

### 500000 dados

![image](https://user-images.githubusercontent.com/95262005/197091190-75031368-5004-466d-99b5-5e3786a9ee29.png)
