#include <iostream>
#include <fstream>

using namespace std;

void escreverArquivo(fstream &arquivo, string mensagem)
{
    cout << "escrevendo no arquivo..." << endl;
    arquivo << mensagem << endl;
}

bool lerArquivo(fstream &arquivo, string &linha)
{
    cout << "lendo arquivo..." << endl;
    return getline(arquivo, linha) ? true : false;
}

void abrirArquivo(fstream &arquivo, string nome)
{
    cout << "abrindo arquivo..." << endl;
    arquivo.open(nome + ".txt", ios::app | ios::in);
}

bool removerArquivo(string nome)
{
    cout << "removendo arquivo..." << endl;
    return remove(nome.c_str());
}

void fecharArquivo(fstream &arquivo)
{
    cout << "fechando arquivo..." << endl;
    arquivo.close();
}

bool verificarArquivo(fstream &arquivo)
{
    cout << "verifcando arquivo..." << endl;
    return arquivo.is_open();
}

int main()
{
    fstream arquivo;
    abrirArquivo(arquivo, "meu_arquivo");
    if (verificarArquivo(arquivo))
    {
        cout << "Arquivo aberto com sucesso!" << endl;
        while (arquivo.good()) {
            cout << "Digite uma linha para escrever no arquivo (ou 'sair' para encerrar): ";
            string input;
            getline(cin, input);
            if (input == "sair") {
                break;
            }
            escreverArquivo(arquivo, input);
        }
        arquivo.clear(); // Limpa o estado de erro para permitir a leitura
        arquivo.seekg(0); // Move o ponteiro de leitura para o início do arquivo
        string linha;
        while (lerArquivo(arquivo, linha)) {
            cout << linha << endl;
        }
        fecharArquivo(arquivo);
        abrirArquivo(arquivo, "meu_arquivo");
        escreverArquivo(arquivo, "Esta linha não será escrita porque o arquivo já foi fechado.");
        fecharArquivo(arquivo);
    }
    else {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
    return 0;
}