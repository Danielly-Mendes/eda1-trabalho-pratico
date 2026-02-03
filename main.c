#include "estruturas.h" 
<<<<<<< HEAD
#include "produtos.h"
#include "clientes.h"
#include "carrinho.h"
=======
//#include "produtos.h"
//#include "clientes.h"
//#include "carrinho.h"
#include "funcoes.h"
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
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
<<<<<<< HEAD
      
        printf("|>>------------MENU-------------<<|\n");
        printf("| (1) Clientes                    |\n");
        printf("| (2) Produtos                    |\n");
        printf("| (3) Modo Compra (Pedido)        |\n");
        printf("| (4) Sair                        |\n");
        printf("|>>-----------------------------<<|\n\n");
=======
        
        // -- MENU PRINCIPAL --
        printf("\n .=======================================.\n");
        printf(" ||           MENU PRINCIPAL            ||\n");
        printf(" ||=====================================||\n");
        printf(" ||  [1] Gerenciar Clientes             ||\n");
        printf(" ||  [2] Gerenciar Produtos             ||\n");
        printf(" ||  [3] Modo Compra (PDV)              ||\n");
        printf(" ||  [4] Sair do Sistema                ||\n");
        printf(" '======================================='\n");
        printf("  Opcao: ");
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
        scanf("%d", &i);
        
        switch (i) {
            case 1: {
                int j = 0;
                while(j != 5){
<<<<<<< HEAD
                    printf("\n|>>------ Area de Clientes--------<<|\n");
                    printf("|>> (1) Cadastrar Cliente          |<<\n");
                    printf("|>> (2) Listar Clientes            |<<\n");
                    printf("|>> (3) Editar Cliente             |<<\n");
                    printf("|>> (4) Remover Cliente            |<<\n");
                    printf("|>> (5) Voltar ao Menu Anterior    |<<\n\n");
                    printf("|>>---------------------------------<<|\n\n");

=======
                    // -- MENU CLIENTES --
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
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)

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
<<<<<<< HEAD
                            printf("Digite o cpf: ");
                            scanf(" %[^\n]", busca);
                            Clientes * temp = BuscarCliente(busca, listaClientes);

                            if(temp == NULL) printf("\n\nCliente nao encontrado.\n\n");
=======
                            printf("\nDigite o cpf: ");
                            scanf(" %[^\n]", busca);
                            Clientes * temp = BuscarCliente(busca, listaClientes);

                            if(temp == NULL) printf("\n\n[!] Cliente nao encontrado.\n\n");
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
                            editarCliente(temp);
                            break;
                            }
                        case 4:
                            char busca[15];
<<<<<<< HEAD
                            printf("Digite o cpf: ");
                            scanf(" %[^\n]", busca);
                            Clientes * temp = BuscarCliente(busca, listaClientes);

                            if(temp == NULL) printf("\n\nCliente nao encontrado.\n\n");
                            removerCliente(listaClientes, temp);
                            break;
                        case 5:
                            printf("Voltando ao menu anterior...\n");
                            break;
                            default:
                            printf("Opção inválida! Tente novamente.\n");
=======
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
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
                            break;
                    }
                }
                break; 
            }

            case 2: {
                int k = 0;
                while(k != 5){
<<<<<<< HEAD
                    printf("\n|>>------ Area de Produtos--------<<|\n");
                    printf("|>> (1) Cadastrar Produto           |<<\n");
                    printf("|>> (2) Listar Produtos            |<<\n");
                    printf("|>> (3) Editar Produto             |<<\n");
                    printf("|>> (4) Remover Produto            |<<\n");
                    printf("|>> (5) Voltar ao Menu Anterior    |<<\n\n");
                    printf("|>>-----------------------------<<|\n\n");
=======
                    // -- MENU PRODUTOS --
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
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)

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
<<<<<<< HEAD
                            printf("Digite o codigo do produto a ser editado: ");
=======
                            printf("\nDigite o codigo do produto a ser editado: ");
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
                            scanf("%d", &codigo);
                            editarProduto(listaProdutos, codigo);
                            break;
                        }
                            break;
                        case 4:
                            {
                            int codigo;
<<<<<<< HEAD
                            printf("Digite o codigo do produto a ser removido: ");
=======
                            printf("\nDigite o codigo do produto a ser removido: ");
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
                            scanf("%d", &codigo);
                            removerProduto(listaProdutos, codigo);
                        }
                            break;
                        case 5:
<<<<<<< HEAD
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");
=======
                            printf("\nVoltando ao menu anterior...\n");
                            break;
                        default:
                            printf("\n[!] Opcao invalida! Tente novamente.\n");
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
                            break;
                    }
                }
                break;
            }

            case 3: {
                int l = 0;
<<<<<<< HEAD
                printf("|>>-------- Modo Compra-----------<<|\n");
                printf("|>> (1) Fazer Pedido de Cliente     |<<\n");
                printf("|>> (2) Listar Produtos de Cliente  |<<\n");
                printf("|>> (3) Editar Pedido               |<<\n");
                printf("|>> (4) Voltar ao Menu Anterior     |<<\n\n");
                printf("|>>-------------------------------<<|\n\n");
=======
                // -- MENU COMPRAS --
                printf("\n .=======================================.\n");
                printf(" ||           MODO DE COMPRAS           ||\n");
                printf(" ||=====================================||\n");
                printf(" ||  [1] Fazer Pedido de Cliente        ||\n");
                printf(" ||  [2] Listar Produtos de Cliente     ||\n");
                printf(" ||  [3] Editar Pedido                  ||\n");
                printf(" ||  [4] Voltar ao Menu Anterior        ||\n");
                printf(" '======================================='\n");
                printf("  Opcao: ");
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)

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
                        //editarPedido(&listaClientes, listaProdutos);
                        }
                        break;
                    case 4:
<<<<<<< HEAD
                        printf("Voltando ao menu anterior...\n");
                        break;
                    default:
                       printf("Opção inválida! Tente novamente.\n");
                    break;
                }
                break;
            }

            case 4:
                printf("Saindo do programa...\n");
                break;
            
            default:
                printf("Opção inválida! Tente novamente.\n");
=======
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
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)
                break;
            }
    }
    return 0;
}