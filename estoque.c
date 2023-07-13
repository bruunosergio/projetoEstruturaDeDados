#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "autopecas.h"

Produto* criar_no(){//Cria a lista simplesmente encadeada
    Produto *novo=(Produto*)malloc(sizeof(Produto));
    return novo;
};
Produto* inserir_inicio(Produto* Lista){// Insere os produtos no estoque
	Produto *novo_no=criar_no();
			
        int  qtd;
        char desc[100];
        char tipo[100];
        int cod;
        float pre;
	    
        printf("  *** Insira os dados do produto: ***\n");
        fflush(stdin);
        printf("  Codigo ( SOMENTE NUMEROS): ");
        scanf("%d", &cod);
        fflush(stdin);
        printf("\n  Quantidade: ");
        scanf("%d", &qtd);
        fflush(stdin);
        printf("\n  Descricao: ");
        scanf("%s", desc);
        fflush(stdin);
        printf("\n  Tipo do produto (SUSPENÇÃO - FREIO - MOTOR): ");
        scanf("%s",tipo);
        fflush(stdin);
        printf("\n  Preco: ");
        scanf("%f", &pre);
        fflush(stdin);
        
	novo_no->codigo=cod;
        novo_no->qtdestoque=qtd;
        strcpy(novo_no->descricao,desc);
        strcpy(novo_no->tpproduto,tipo);
        novo_no->preco=pre;
		    
	if(Lista == NULL){
            Lista=novo_no;
            novo_no->prox=NULL;
	}else{
            novo_no->prox=Lista;
            Lista=novo_no;
	}
	return Lista;
}
void imprimir(Produto* Lista){ //USANDO RECURSIVIDADE//
	if(Lista==NULL){
            return;
	}else{
            printf("\n ------------ \n O codigo do produto : %d \n ------------ \n Descricao do produto: %s \n ------------ \n Preco: %f \n ------------ \n Tipo : %s \n", Lista->codigo,Lista->descricao,Lista->preco,Lista->tpproduto);
            imprimir(Lista->prox);
        }
}
void busca_tipo(Produto *Lista, char *chave) {// Buscar por tipo

        printf("\n -------------- \n");
        printf ("\n   Busca por tipo de produto  \n");
        printf("\n -------------- \n");
        for (; Lista != NULL; Lista = Lista->prox) {
            if (strcmp(chave, Lista->tpproduto) == 0) {

                fprintf(stdout, "------------------------\n");
                fprintf(stdout, "Codigo : %d\n", Lista->codigo);
                fprintf(stdout, "Quantidade: %d\n", Lista->qtdestoque);
                fprintf(stdout, "Descricao: %s\n", Lista->descricao);
                fprintf(stdout, "Tipo: %s\n", Lista->tpproduto);
                fprintf(stdout, "Preco: %f\n", Lista->preco);

                fprintf(stdout, "------------------------\n");
                }
        }
}
void menuprincipal(){// Menu principal
    printf("\n   >>>>> BRUNO AUTO PEÇAS <<<<< \n  Digite a opcao que corresponde ao seu perfil: (1) Funcionario (2) Cliente \n");
}
void imprimemenu(){// Menu do Funcionario
	printf("\n     *** MENU FUNCIONARIO ***\n >>>>> BRUNO AUTO PEÇAS <<<<<\n");
	printf("     1 - Cadastrar produto \n");
	printf("     2 - Ver codigos de produtos cadastrados \n");
	printf("     3 - Pesquisar produto por tipo \n\n");
	printf("  Escolher opcao: ");
}	
int buscaProdutoEstoque(Produto *Lista, int cod){// verifica se o produto esta cadastrado
	Produto *aux=criar_no(); 
	aux=Lista;
	while(aux!=NULL){
            if(aux->codigo == cod){
                if(aux->qtdestoque>=1){
                    return aux->qtdestoque;
		}
		else{
		return 0;
		}
	}
		aux=aux->prox;
    }
}
Produto* retornarProdutocodigo(Produto *Lista, int codigo){// Retorna o codigo do produto desejado 
        Produto *aux=criar_no(); 
        aux=Lista;
        Produto produtodesejado;
	while(aux!=NULL){
            if(aux->codigo == codigo){
		return aux;
            }
            aux=aux->prox;
	}
}

