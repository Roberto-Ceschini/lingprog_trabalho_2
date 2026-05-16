Sistema Financeiro
Descrição
Sistema desenvolvido em C++ para monitoramento de ativos financeiros e análise de registros históricos.

O programa permite:

cadastro de ativos financeiros;
inserção de registros de valores;
cálculo de média móvel;
ordenação de ativos;
detecção de variações anormais;
previsão do próximo valor utilizando regressão linear simples.
O projeto foi desenvolvido utilizando orientação a objetos, modularização com arquivos .h/.cpp e compilação automatizada com Makefile.

Estrutura do Projeto
Classes
RegistroValor
Responsável por representar um registro de valor associado a um ativo.

Atributos principais:

nome do registro;
valor numérico.
Ativo
Representa um ativo financeiro monitorado pelo sistema.

Cada ativo armazena:

registros históricos;
médias móveis;
previsão do próximo valor;
variação percentual entre médias móveis.
SistemaFinanceiro
Classe responsável pelo gerenciamento geral do sistema e pelo menu interativo.

Funcionalidades
O sistema possui as seguintes funcionalidades disponíveis via menu:

1. Criar Novo Ativo
Permite cadastrar um novo ativo financeiro no sistema.

2. Adicionar Registro a Ativo
Permite adicionar novos registros de valor a um ativo já existente.

Após a inserção, o sistema realiza automaticamente:

cálculo da média móvel;
cálculo da previsão do próximo valor;
cálculo da variação percentual.
3. Exibir Ativos Ordenados
Exibe os ativos ordenados com base no último valor da média móvel.

4. Exibir Média Móvel
Exibe a média móvel calculada para o ativo selecionado.

A média móvel utiliza janela de tamanho 3.

5. Exibir Próximo Valor Previsto
Exibe a previsão do próximo valor do ativo utilizando regressão linear simples.

6. Detectar Variação Anormal
Detecta variações superiores a 10% entre médias móveis consecutivas.

7. Encerrar Sistema
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