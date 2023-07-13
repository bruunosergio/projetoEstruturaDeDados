#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

struct produto{// Parametros que vao formar os produtos e ponteiros para lista simplesmente encadeada
    int codigo;
    int qtdestoque;
    char descricao[100];
    char tpproduto[100];
    float preco;
    struct produto *prox;
};
typedef struct produto Produto;

struct carrinho{// Necessaria para execuçao e criaçao da lista duplamente encadeada
    int codigo;
    int qtditens;
    char descricao[100];
    char tpproduto[100];
    float preco;
    Produto *produto;
    struct carrinho *ant;
    struct carrinho *prox;
};
typedef struct carrinho Carrinho;

//--------- FUNÇÕES -----------//
//CARRINHO

Carrinho* inicializar();// inicializa a lista duplamente encadeada

int buscarProdutoCarrinho (Carrinho *lista, Produto *produto);// faz a busca do produto no carrinho

Carrinho* inserir (Carrinho *lista, Produto *produto);// insere elementos na lista duplamente encadeada

void exibir(Carrinho *lista);// Exibe elementos criados na lista duplamente encadeada

int calcularQuantidade(Carrinho *lista); // Calcula a quantidade de itens no carrinho

float FinalizarCompra(Carrinho *lista);// Finaliza e soma o valor total

void menucliente();// Menu do Cliente

//----------------------- FUNCOES ESTOQUE -----------------------

Produto* criar_no();//Cria a lista simplesmente encadeada

Produto* inserir_inicio(Produto* Lista);// Insere os produtos no estoque

void imprimir(Produto* Lista); // Imprimir produtos cadastrados, escolhidos

void busca_tipo(Produto *Lista, char *chave) ;// Buscar produto por tipo

void menuprincipal();// Menu principal

void imprimemenu();// Menu do Funcionario

int buscaProdutoEstoque(Produto *Lista, int cod);// Faz a verificacao se o produto esta cadastrado

Produto* retornarProdutocodigo(Produto *Lista, int codigo);// Retorna o codigo do produto desejado 


