#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "autopecas.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	int i;// para verificar se é cliente ou funcionario
    // --- CARRINHO ---
	Carrinho *lista=NULL;
	lista = inicializar();// Inicializa a lista encadeada dupla
    // ---- ESTOQUE ----
    Produto *Lista=NULL;
    char chavetipo[100];// procurar produto por tipo
    // --- FUNCIONARIO -----
    int opcao=0;//opcao escolhida pelo funcionario no menu	
	//--- CLIENTE ----
    int opcaoc=0;// opcao escolhida pelo cliente no menu
	// ---- INICIO DO PROGRAMA ----
	menuprincipal();
	scanf("%d", &i);// esoolha cliente ou funcionario
	
	if(i==1){// Opcao funcionario
    	do{
            imprimemenu();
            scanf("%d", &opcao);
            
            switch(opcao){
		case 1:// Cadastro
                    Lista=inserir_inicio(Lista);			
                    menuprincipal();
                    scanf("%d", &i);
		break;
		
                case 2: // Exibir
                    imprimir(Lista);
                    menuprincipal();
                    scanf("%d", &i);
		break;
		
		case 3: // Exibir produtos por tipo
                    printf("Tipo do produto que deseja encontrar: ");
                    scanf("%s",&chavetipo);
                    busca_tipo(Lista,chavetipo);
                    menuprincipal();
                    scanf("%d", &i);
		break;
			}
		}while(i==1);
	}
	if(i==2){// Opcao Cliente
		do{
                    menucliente();
                    scanf("%d",&opcaoc);
                    int cod;
                    float valor;
			
                    switch(opcaoc){
                       case 1:
                            printf("\n\n ------------ \n Produtos Disponiveis Em Estoque \n ------------ \n");
                            imprimir(Lista);
                            printf("\n Digite o codigo desejado: ");
                            scanf("%d",&cod);
                            if(buscaProdutoEstoque(Lista,cod)!=0){ // Verifica se o produto ainda esta disponivel no estoque
                            lista=inserir(lista,retornarProdutocodigo(Lista,cod));// Insere produto no carrinho
                            }
                            else{
                                printf("\n\n ATENCAO : Produto nao disponivel \n");
                            }							
                        break;
			case 2:
                            exibir(lista);	// Mostra carrinho
			break;	
			case 3: 
                            valor=FinalizarCompra(lista);
                            printf(" Total R$ %.2f \n",valor);
                            exit(0);
			break;
			case 4:
                            printf("A quantidade de itens no carrinho: %d \n", calcularQuantidade(lista));
                        break;
                        case 5:
                            exit(0);    
                        break;
                    }
		}while(i==2);
	}
}
