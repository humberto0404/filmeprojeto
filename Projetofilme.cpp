
#include <iostream>
#define MAX 10

using namespace std;

struct cadastrarCliente {
    int idCliente;
    string nomeCliente;
    string telefone;
};

struct cadastrarFilme {
    int codigoFilme;
    string tituloFilme;
    string generoFilme;
    int anodoFilme;
    int idCliente;
};

void mostrarMenu() {
    cout << endl;
    cout << "___________ MENU ___________\n";
    cout << "1 - Cadastrar cliente.\n";
    cout << "2 - Cadastrar filme.\n";
    cout << "3 - Listar clientes.\n";
    cout << "4 - Listar filmes.\n";
    cout << "5 - Buscar filmes por cliente.\n";
    cout << "6 - Relatorio geral.\n";
    cout << "0 - Sair.\n";
    cout << "_____________________________\n\n";
    cout << "Digite sua opcao: ";
}

// Cadastrar cliente
void cadastrocliente(cadastrarCliente vet[], int &n) {

    if(n == MAX) {
        cout << "Limite de clientes atingido!\n";
        return;
    }

    int id;

    cout << "Digite o Id do cliente: ";
    cin >> id;

    for(int j = 0; j < n; j++) {
        if(id == vet[j].idCliente) {
            cout << "Id ja cadastrado!\n";
            return;
        }
    }

    vet[n].idCliente = id;

    cin.ignore();

    cout << "Digite o nome do cliente: ";
    getline(cin, vet[n].nomeCliente);

    cout << "Digite o numero do cliente: ";
    getline(cin, vet[n].telefone);

    n++;
}

// Mostrar clientes
void mostrarCliente(cadastrarCliente vet[], int n) {

    cout << "Usuarios cadastrados:\n";

    for(int i = 0; i < n; i++) {
        cout << "---------------------------\n";
        cout << "ID Cliente: " << vet[i].idCliente << endl;
        cout << "Nome Cliente: " << vet[i].nomeCliente << endl;
        cout << "Telefone do Cliente: " << vet[i].telefone << endl;
    }

}

// Cadastrar filme
void cadastrarFIRME(cadastrarFilme vetF[], cadastrarCliente vetC[], int &n, int contCliente) {

    if(n == MAX) {
        cout << "Limite de filmes atingido!\n";
        return;
    }

    cout << "Digite o codigo: ";
    cin >> vetF[n].codigoFilme;

    for(int j = 0; j < n; j++) {
        if(vetF[n].codigoFilme == vetF[j].codigoFilme) {
            cout << "Codigo ja cadastrado!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Digite o titulo do Filme: ";
    getline(cin, vetF[n].tituloFilme);

    cout << "Digite o genero do Filme: ";
    getline(cin, vetF[n].generoFilme);

    cout << "Digite o ano do Filme: ";
    cin >> vetF[n].anodoFilme;

    int id;
    int encontrado = 0;

    cout << "Digite o ID do cliente que alugou o filme (0 para disponivel): ";
    cin >> id;

    if(id == 0) {
        encontrado = 1;
    }

    for(int j = 0; j < contCliente; j++) {
        if(id == vetC[j].idCliente) {
            encontrado = 1;
        }
    }

    if(encontrado == 0) {
        cout << "Cliente nao encontrado! Filme nao cadastrado.\n";
        return;
    }

    vetF[n].idCliente = id;

    n++;
}

// Mostrar filmes
void mostrarFilme(cadastrarFilme vetF[], cadastrarCliente vetC[], int n, int contCliente) {

    cout << "Filmes cadastrados:\n";

    for(int i = 0; i < n; i++) {

        cout << "---------------------------\n";
        cout << "Codigo: " << vetF[i].codigoFilme << endl;
        cout << "Titulo: " << vetF[i].tituloFilme << endl;
        cout << "Genero: " << vetF[i].generoFilme << endl;
        cout << "Ano: " << vetF[i].anodoFilme << endl;

        if(vetF[i].idCliente == 0) {
            cout << "Cliente: Filme disponivel.\n";
        }

        for(int j = 0; j < contCliente; j++) {
            if(vetF[i].idCliente == vetC[j].idCliente) {
                cout << "Cliente: " << vetC[j].nomeCliente << endl;
            }
        }
    }

}

// Buscar filmes por cliente
void buscarFilme(cadastrarFilme vetF[], cadastrarCliente vetC[], int n, int contCliente) {

    int id;
    int encontrado = 0;

    cout << "Digite o ID do cliente: ";
    cin >> id;

    for(int i = 0; i < contCliente; i++) {

        if(vetC[i].idCliente == id) {

            encontrado = 1;

            cout << "Cliente: " << vetC[i].nomeCliente << endl;

            for(int j = 0; j < n; j++) {

                if(vetF[j].idCliente == id) {
                    cout << "---------------------------\n";
                    cout << "Codigo: " << vetF[j].codigoFilme << endl;
                    cout << "Filme: " << vetF[j].tituloFilme << endl;
                    cout << "Genero: " << vetF[j].generoFilme << endl;
                    cout << "Ano: " << vetF[j].anodoFilme << endl;
                }
            }
        }
    }

    if(encontrado == 0) {
        cout << "Cliente nao encontrado!\n";
    }
}

// Relatorio geral
void relatorioGeral(cadastrarCliente vetC[], cadastrarFilme vetF[], int contCliente, int contFilme) {

    for(int i = 0; i < contCliente; i++) {

        int quantidade = 0;

        for(int j = 0; j < contFilme; j++) {

            if(vetF[j].idCliente == vetC[i].idCliente) {
                quantidade++;
            }
        }

        cout << "---------------------------\n";
        cout << "Cliente: " << vetC[i].nomeCliente << endl;
        cout << "ID: " << vetC[i].idCliente << endl;
        cout << "Filmes alugados: " << quantidade << endl;
    }

}

int main() {

    cadastrarCliente listaCliente[MAX];
    cadastrarFilme listaFilme[MAX];

    int selecionaropcao;
    int contaCliente = 0;
    int contaFilme = 0;

    while(true) {

        mostrarMenu();

        cin >> selecionaropcao;

        if(selecionaropcao == 0)
            break;

        switch(selecionaropcao) {

        case 1:
            cadastrocliente(listaCliente, contaCliente);
            break;

        case 2:
            cadastrarFIRME(listaFilme, listaCliente, contaFilme, contaCliente);
            break;

        case 3:
            mostrarCliente(listaCliente, contaCliente);
            break;

        case 4:
            mostrarFilme(listaFilme, listaCliente, contaFilme, contaCliente);
            break;

        case 5:
            buscarFilme(listaFilme, listaCliente, contaFilme, contaCliente);
            break;

        case 6:
            relatorioGeral(listaCliente, listaFilme, contaCliente, contaFilme);
            break;

        default:
            cout << "Opcao invalida!\n";
            break;
        }
    }

    return 0;
}
