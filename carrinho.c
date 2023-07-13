#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "autopecas.h"

Carrinho* inicializar(){// inicializa a lista duplamente encadeada

	return NULL;
};
int buscarProdutoCarrinho(Carrinho *lista,Produto *produto){
	Carrinho *aux=inicializar(); 
	aux=lista;
	while(aux!=NULL){
		if(aux->produto->codigo == produto->codigo){
			return 1;
		}
		aux=aux->prox;
	}
};
Carrinho* inserir(Carrinho *lista, Produto *produto){// insere elementos na lista duplamente encadeada
    Carrinho *c = (Carrinho*) malloc (sizeof(Carrinho));
	c->produto=(Produto*) malloc (sizeof(Produto));
	c->qtditens=0;
	
	if(buscarProdutoCarrinho(lista,produto)==1){
		Carrinho *aux = inicializar();
		aux=lista;
		int controle=0;
     	while(aux != NULL){
        	if(aux->produto->codigo == produto->codigo ){
				aux->qtditens++;
				produto->qtdestoque--;	
			}
			aux = aux->prox;
 		}
 	 }else{
	   if(lista==NULL) {
				strcpy(c->produto->descricao,produto->descricao);
				c->produto->preco=produto->preco;
				c->produto->qtdestoque=0; 
				c->qtditens++;
				produto->qtdestoque--;
				strcpy(c->produto->tpproduto,produto->tpproduto);
				c->ant=NULL;
				c->prox=NULL;
				return c;
     		}else{
                                strcpy(c->produto->descricao,produto->descricao);
				c->produto->preco=produto->preco;
				c->produto->qtdestoque=0;
				c->qtditens++;
				produto->qtdestoque--;
				strcpy(c->produto->tpproduto,produto->tpproduto);
				c->prox=lista;
				c->ant=NULL;
				lista->ant=c;
				return c;
	       }
	   }
       return lista;
}
void exibir(Carrinho *lista){//RECURSIVIDADE
	
    if(lista == NULL){
        return;
    }else{
         printf("\n ------------ \n Descricao do produto: %s \n ------------ \n Preco: %f \n ------------ \n Tipo : %s \n", lista->produto->descricao,lista->produto->preco,lista->produto->tpproduto);
         exibir(lista->prox);
    }
}
int calcularQuantidade(Carrinho *lista){// Calcula a quantidade de itens no carrinho // RECURSIVIDADE
    if(lista == NULL){
        return;
    }else{
        return(1 + calcularQuantidade(lista->prox));
    }
}
float FinalizarCompra(Carrinho *lista){// soma o valor total
	float soma=0.0;
	Carrinho *aux=inicializar();
	aux=lista;
	while(aux!=NULL){ 
		soma=soma+(aux->produto->preco*aux->qtditens);
		aux=aux->prox;
	}
	return soma;
	

}
void menucliente(){// Menu do Cliente
	printf("\n>>>> AREA CLIENTE <<<<\n");
        printf("    >>>>> BRUNO AUTO PEÇAS <<<<< \n\n");
	printf("      1 - Ver e Adicionar produtos ao carrinho \n");
	printf("      2 - Ver carrinho \n");
	printf("      3 - Finalizar Compra\n");
        printf("      4 - Ver quantidade de itens no carrinho \n");
	printf("      5 - Sair \n\nEscolher opcao:   ");
}

