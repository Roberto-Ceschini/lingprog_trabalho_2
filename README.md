Estrutura do Projeto
Classes
Vertice

Responsável por representar um vértice do grafo.

Cada vértice possui:

nome identificador.
Aresta

Representa uma conexão entre dois vértices do grafo.

Cada aresta armazena:

vértice de origem;
vértice de destino;
custo/peso da conexão.
Grafo

Classe principal responsável por armazenar o grafo e executar os algoritmos de análise.

A estrutura interna utiliza:

matriz de adjacência;
lista de vértices;
lista de arestas.
Arquivo

Classe responsável pela leitura do arquivo .txt de entrada.

Ela realiza:

abertura do arquivo;
leitura das linhas;
criação automática das arestas e vértices.
Formato do Arquivo de Entrada

O arquivo deve conter:

VERTICE_ORIGEM VERTICE_DESTINO PESO

Exemplo:

A B 2.2
B C 1.0
C D 3.1
A D 4.5

Cada linha representa:

origem destino custo
Funcionalidades

O sistema possui as seguintes funcionalidades disponíveis via menu:

1. Imprimir Matriz de Adjacência

Exibe a matriz de adjacência do grafo contendo os pesos das conexões entre os vértices.

Exemplo:

    A   B   C
A 0.0 2.0 1.0
B 2.0 0.0 3.0
C 1.0 3.0 0.0
2. Imprimir Grau dos Vértices

Exibe o grau de cada vértice do grafo.

O grau representa:

quantidade de conexões do vértice
3. Verificar se o Grafo é Conexo

Verifica se todos os vértices do grafo estão conectados.

O algoritmo utilizado é:

Busca em Profundidade (DFS).

O sistema informa se:

o grafo é conexo;
existem vértices isolados/desconectados.
4. Imprimir Caminho Mais Curto Entre Dois Vértices

Calcula os menores caminhos entre dois vértices informados pelo usuário utilizando o algoritmo de Dijkstra.

O sistema exibe:

todos os menores caminhos encontrados;
custo total de cada caminho.

Exemplo:

Caminho 1:
A -> B -> D | custo total = 2.00

Caminho 2:
A -> C -> D | custo total = 2.00
5. Imprimir Ordem de Centralidade dos Vértices

Calcula a centralidade de intermediação dos vértices do grafo.

A centralidade mede:

o quanto um vértice aparece nos menores caminhos do grafo

Os vértices são exibidos em ordem decrescente de importância.

Exemplo:

D -> 5.50
B -> 3.00
A -> 1.00
6. Sair

Finaliza a execução do programa.
Finaliza a execução do programa.

Requisitos
Para compilar o programa é necessário possuir:

g++
mingw32-make
Compilação
No terminal, execute:

mingw32-make
O comando irá gerar o executável do programa.

Execução
Após a compilação:

.\programa
Limpeza dos Arquivos Compilados
Para remover os arquivos objeto e o executável:

mingw32-make clean
Observações
Caso utilize o sistema Linux, é preciso modificar o arquivo Makefile com as instruções presentes no comentário da linha 1.
Autor
Roberto Ribeiro