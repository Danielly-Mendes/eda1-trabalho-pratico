#include "estruturas.h" 
//#include "produtos.h"
//#include "clientes.h"
//#include "carrinho.h"
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i = 0;
    //Produtos* listaProdutos = NULL;
    //Clientes* listaClientes = NULL;
    
    Clientes * listaClientes = CriarListaCliente();
    Produtos* listaProdutos = CriarListaProduto();
    

    while(i != 4){
        
        printf("\n .=======================================.\n");
        printf(" ||           MENU PRINCIPAL            ||\n");
        printf(" ||=====================================||\n");
        printf(" ||  [1] Gerenciar Clientes             ||\n");
        printf(" ||  [2] Gerenciar Produtos             ||\n");
        printf(" ||  [3] Modo Compra                    ||\n");
        printf(" ||  [4] Sair do Sistema                ||\n");
        printf(" '======================================='\n");
        printf("  Opcao: ");
        scanf("%d", &i);
        
        switch (i) {
            case 1: {
                int j = 0;
                while(j != 5){
                    printf("\n .=======================================.\n");
                    printf(" ||         GESTAO DE CLIENTES          ||\n");
                    printf(" ||=====================================||\n");
                    printf(" ||  [1] Cadastrar Cliente              ||\n");
                    printf(" ||  [2] Listar Clientes                ||\n");
                    printf(" ||  [3] Editar Cliente                 ||\n");
                    printf(" ||  [4] Remover Cliente                ||\n");
                    printf(" ||  [5] Voltar ao Menu Anterior        ||\n");
                    printf(" '======================================='\n");
                    printf("  Opcao: ");

                    scanf("%d", &j);
                    switch(j){
                        case 1:
                            cadastrarCliente(listaClientes);
                            break;
                        case 2:
                        
                            listarClientes(listaClientes);
                            break;
                        
                        case 3:
                            {
                            char busca[15];
                            printf("\nDigite o cpf: ");
                            scanf(" %[^\n]", busca);
                            Clientes * temp = BuscarCliente(busca, listaClientes);

                            if(temp == NULL) printf("\n\n[!] Cliente nao encontrado.\n\n");
                            editarCliente(temp);
                            break;
                            }
                        case 4:
                            char busca[15];
                            printf("\nDigite o cpf: ");
                            scanf(" %[^\n]", busca);
                            Clientes * temp = BuscarCliente(busca, listaClientes);

                            if(temp == NULL) printf("\n\n[!] Cliente nao encontrado.\n\n");
                            removerCliente(listaClientes, temp);
                            break;
                        case 5:
                            printf("\nVoltando ao menu anterior...\n");
                            break;
                            default:
                            printf("\n[!] Opcao invalida! Tente novamente.\n");
                            break;
                    }
                }
                break; 
            }

            case 2: {
                int k = 0;
                while(k != 5){
                    printf("\n .=======================================.\n");
                    printf(" ||         GESTAO DE PRODUTOS          ||\n");
                    printf(" ||=====================================||\n");
                    printf(" ||  [1] Cadastrar Produto              ||\n");
                    printf(" ||  [2] Listar Produtos                ||\n");
                    printf(" ||  [3] Editar Produto                 ||\n");
                    printf(" ||  [4] Remover Produto                ||\n");
                    printf(" ||  [5] Voltar ao Menu Anterior        ||\n");
                    printf(" '======================================='\n");
                    printf("  Opcao: ");

                    scanf("%d", &k);
                    switch(k){
                        case 1:
                            cadastrarProduto(listaProdutos);
                            break;

                        case 2:
                        
                            listarProdutos(listaProdutos);
                            break;
                        
                            case 3:
                            {
                            int codigo;
                            printf("\nDigite o codigo do produto a ser editado: ");
                            scanf("%d", &codigo);
                            editarProduto(listaProdutos, codigo);
                            break;
                        }
                            break;
                        case 4:
                            {
                            int codigo;
                            printf("\nDigite o codigo do produto a ser removido: ");
                            scanf("%d", &codigo);
                            removerProduto(listaProdutos, codigo);
                        }
                            break;
                        case 5:
                            printf("\nVoltando ao menu anterior...\n");
                            break;
                        default:
                            printf("\n[!] Opcao invalida! Tente novamente.\n");
                            break;
                    }
                }
                break;
            }

            case 3: {
                int l = 0;
                printf("\n .=======================================.\n");
                printf(" ||           MODO DE COMPRAS           ||\n");
                printf(" ||=====================================||\n");
                printf(" ||  [1] Fazer Pedido de Cliente        ||\n");
                printf(" ||  [2] Listar Produtos de Cliente     ||\n");
                printf(" ||  [3] Editar Pedido                  ||\n");
                printf(" ||  [4] Voltar ao Menu Anterior        ||\n");
                printf(" '======================================='\n");
                printf("  Opcao: ");

                scanf("%d", &l);
                switch(l){
                    case 1:
                        fazerPedido(listaClientes, listaProdutos);
                        break;
                    case 2:
                        listarCarrinho(listaClientes, listaProdutos);
                        break;
                    case 3:
                        {
                        editarPedido(listaClientes, listaProdutos);
                        }
                        break;
                    case 4:
                        printf("\nVoltando ao menu anterior...\n");
                        break;
                    default:
                       printf("\n[!] Opcao invalida! Tente novamente.\n");
                    break;
                }
            }
                break;

            case 4:
                printf("\nSaindo do programa... Ate logo!\n");
                break;
            
            default:
                printf("\n[!] Opcao invalida! Tente novamente.\n");
                break;
            }
    }
    return 0;
}