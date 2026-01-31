#include "estruturas.h" 
#include "produtos.h"
#include "clientes.h"
//#include "pedidos.c"
//#include "clientes.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i = 0;
    Produtos* listaProdutos = NULL;
    //Clientes* listaClientes = NULL;
    
    Clientes * listaClientes = CriarListaCliente();
    

    while(i != 4){
      
        printf("|>>------------MENU-------------<<|\n");
        printf("| (1) Clientes                    |\n");
        printf("| (2) Produtos                    |\n");
        printf("| (3) Modo Compra (Pedido)        |\n");
        printf("| (4) Sair                        |\n");
        printf("|>>-----------------------------<<|\n\n");
        scanf("%d", &i);
        
        switch (i) {
            case 1: {
                int j = 0;
                while(j != 5){
                    printf("\n|>>------ Area de Clientes--------<<|\n");
                    printf("|>> (1) Cadastrar Cliente           |<<\n");
                    printf("|>> (2) Listar Clientes            |<<\n");
                    printf("|>> (3) Editar Cliente             |<<\n");
                    printf("|>> (4) Remover Cliente            |<<\n");
                    printf("|>> (5) Voltar ao Menu Anterior    |<<\n\n");

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
                            int codigo;
                            printf("Digite o codigo do cliente a ser editado: ");
                            scanf("%d", &codigo);
                            //editarCliente(listaClientes, codigo);
                                                        break;
                            }
                        case 4:
                            //removerCliente(&listaClientes);
                            break;
                        case 5:
                            printf("Voltando ao menu anterior...\n");
                            break;
                            default:
                            printf("Opção inválida! Tente novamente.\n");
                            break;
                    }
                }
                break; 
            }

            case 2: {
                int k = 0;
                while(k != 5){
                    printf("\n|>>------ Area de Produtos--------<<|\n");
                    printf("|>> (1) Cadastrar Produto           |<<\n");
                    printf("|>> (2) Listar Produtos            |<<\n");
                    printf("|>> (3) Editar Produto             |<<\n");
                    printf("|>> (4) Remover Produto            |<<\n");
                    printf("|>> (5) Voltar ao Menu Anterior    |<<\n\n");
                    scanf("%d", &k);
                    switch(k){
                        case 1:
                            cadastrarProduto(&listaProdutos);
                            break;

                        case 2:
                        
                            listarProdutos(listaProdutos);
                            break;
                        
                            case 3:
                            {
                            int codigo;
                            printf("Digite o codigo do produto a ser editado: ");
                            scanf("%d", &codigo);
                            editarProduto(listaProdutos, codigo);
                        }
                            break;
                        case 4:
                            {
                            int codigo;
                            printf("Digite o codigo do produto a ser removido: ");
                            scanf("%d", &codigo);
                            removerProduto(&listaProdutos, codigo);
                        }
                            break;
                        case 5:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");
                            break;
                    }
                }
                break;
            }

            case 3: {
                int l = 0;
                printf("|>>-------- Modo Compra-----------<<|\n");
                printf("|>> (1) Fazer Pedido de Cliente     |<<\n");
                printf("|>> (2) Listar Produtos de Cliente  |<<\n");
                printf("|>> (3) Editar Pedido               |<<\n");
                printf("|>> (4) Voltar ao Menu Anterior     |<<\n\n");
                scanf("%d", &l);
                switch(l){
                    case 1:
                        //fazerPedido(&listaClientes, listaProdutos);
                        break;
                    case 2:
                        //listarPedidos(listaClientes);
                        break;
                    case 3:
                        {
                        //editarPedido(&listaClientes, listaProdutos);
                        }
                        break;
                    case 4:
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
                break;
        }
    }
    return 0;
}