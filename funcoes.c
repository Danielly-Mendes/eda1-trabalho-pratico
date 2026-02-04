#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes.h"

// ============================================================
//                   FUNÇÕES AUXILIARES
// ============================================================

void limparCPF(char *cpf) {
    int i, j = 0;
    char limpo[15];
    for (i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] != '.' && cpf[i] != '-') {
            limpo[j] = cpf[i];
            j++;
        }
    }
    limpo[j] = '\0';
    strcpy(cpf, limpo);
}

void limparTel(char *tel) {
    int i, j = 0;
    char limpo[15];
    for (i = 0; tel[i] != '\0'; i++) {
        if (tel[i] != ' ' && tel[i] != '(' && tel[i] != ')') {
            limpo[j] = tel[i];
            j++;
        }
    }
    limpo[j] = '\0';
    strcpy(tel, limpo);
}
void liberarCarrinho(ItemCarrinho* carrinho);

// ============================================================
//                   FUNÇÕES DE CLIENTES
// ============================================================

// Implementação que estava faltando
Clientes * BuscarCliente(char busca[15], Clientes *le){
    Clientes *p = le->proximo;
    limparCPF(busca);

    while (p != NULL){
        if (strcmp(busca, p->CPF) == 0) return p;
        p = p->proximo;        
    }   
    return NULL;
}

Clientes * CriarListaCliente(){
    Clientes * cabeca = malloc(sizeof(Clientes));
    if (cabeca != NULL) cabeca->proximo = NULL;
    return cabeca;
}

void cadastrarCliente(Clientes *lista){
    Clientes *cliente = malloc(sizeof(Clientes));

    printf(CIANO "\n .=======================================.\n");
    printf(" ||           NOVO CLIENTE              ||\n");
    printf(" '======================================='\n" RESET);

    printf("  >> Nome Completo: ");
    scanf(" %[^\n]", cliente->nome);

    printf("  >> CPF: ");
    scanf(" %[^\n]", cliente->CPF);
    limparCPF(cliente->CPF);

    if (BuscarCliente(cliente->CPF, lista) != NULL) {
        printf(VERMELHO "\n  [!] Erro: CPF ja cadastrado no sistema!\n" RESET);
        free(cliente);
        return;
    }

    printf("  >> Data Nasc. [dd/mm/aa]: ");
    scanf(" %[^\n]", cliente->dt_nascimento);
    
    printf("  >> Telefone: ");
    scanf(" %[^\n]", cliente->telefone);
    limparTel(cliente->telefone);

    cliente->carrinho = criarCarrinho();
    cliente->proximo = NULL;

    Clientes *p = lista;
    while (p->proximo != NULL) {
        p = p->proximo;
    }

    p->proximo = cliente;
    printf(VERDE "\n  [v] Sucesso: Cliente cadastrado!\n" RESET);
}

// Função que estava faltando
void listarClientes(Clientes *cabeca){
    printf(CIANO "\n .=======================================================.\n");
    printf(" ||                 LISTA DE CLIENTES                   ||\n");
    printf(" ||=====================================================||\n" RESET);
    
    if (cabeca == NULL || cabeca->proximo == NULL) {
        printf(CIANO " ||" RESET "             Nenhum cliente cadastrado.              " CIANO "||\n");
        printf(" '======================================================='\n" RESET);
        return;
    }

    printf(CIANO " ||" AMARELO " %-30s | %-16s " CIANO "||\n", "NOME", "CPF");
    printf(" ||--------------------------------|------------------||\n" RESET);

    for(Clientes *p = cabeca->proximo; p != NULL; p = p->proximo){
        printf(CIANO " ||" RESET " %-30s | %-16s " CIANO "||\n", p->nome, p->CPF);
    }
    printf(CIANO " '======================================================='\n" RESET);
}

void editarCliente(Clientes *cliente){
    printf(CIANO "\n .=======================================.\n");
    printf(" ||           EDITAR CLIENTE            ||\n");
    printf(" '======================================='\n" RESET);
    
    printf("  >> Novo Nome: ");
    scanf(" %[^\n]", cliente->nome);

    printf("  >> Novo CPF: ");
    scanf(" %[^\n]", cliente->CPF);
    limparCPF(cliente->CPF);

    printf("  >> Nova Data Nasc.: ");
    scanf(" %[^\n]", cliente->dt_nascimento);
    
    printf("  >> Novo Telefone: ");
    scanf(" %[^\n]", cliente->telefone);
    limparTel(cliente->telefone);

    printf(VERDE "\n  [v] Sucesso: Dados atualizados!\n" RESET);
}

void removerCliente(Clientes *cabeca, Clientes *cliente) {
    Clientes *anterior = cabeca;
    Clientes *atual = cabeca->proximo;

    while (atual != NULL && atual != cliente) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        anterior->proximo = atual->proximo;
        printf(VERMELHO "\n  >> Removendo: %s...\n" RESET, atual->nome);
        liberarCarrinho(atual->carrinho);
        free(atual);
        printf(VERDE "  [v] Sucesso: Cliente removido!\n" RESET);
    }
}

void liberarClientes(Clientes* lista){
    Clientes* atual = lista->proximo;
    while(atual != NULL){
        Clientes* proximo = atual->proximo;
        liberarCarrinho(atual->carrinho);
        free(atual);
        atual = proximo;
    }
    lista->proximo = NULL;
}

// ============================================================
//                   FUNÇÕES DE PRODUTOS
// ============================================================

Produtos* CriarListaProduto(){
    Produtos* cabeca = malloc (sizeof(Produtos));
    if(cabeca != NULL){
        cabeca->proximo = NULL;
        cabeca->codigo = -1;
    }
    return cabeca;
}

Produtos* buscarProduto2(Produtos* lista, int codigo){
    Produtos* atual = lista->proximo;
    while(atual != NULL){  
        if(atual->codigo == codigo) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void cadastrarProduto(Produtos* lista){
    Produtos* novo = malloc (sizeof(Produtos));
    
    printf(ROXO "\n .=======================================.\n");
    printf(" ||           NOVO PRODUTO              ||\n");
    printf(" '======================================='\n" RESET);

    printf("  >> Codigo: ");
    scanf(" %d", &novo->codigo);

    if(buscarProduto2(lista, novo->codigo) != NULL) {
        printf(VERMELHO "\n  [!] Erro: Codigo ja cadastrado!\n" RESET);
        free(novo);
        return;
    }

    printf("  >> Nome: ");
    scanf(" %[^\n]", novo->nome);

    printf("  >> Preco (R$): ");
    scanf(" %f", &novo->preco);

    printf("  >> Quantidade: ");
    scanf(" %d", &novo->qtde);

    novo->proximo = lista->proximo;
    lista->proximo = novo;

    printf(VERDE "\n  [v] Sucesso: Produto cadastrado!\n" RESET);
}

void listarProdutos(Produtos* lista){
    Produtos* atual = lista->proximo;
    
    printf(ROXO "\n .===========================================================.\n");
    printf(" ||                  ESTOQUE DE PRODUTOS                    ||\n");
    printf(" ||=========================================================||\n" RESET);
    
    if(atual == NULL){
        printf(ROXO " ||" RESET "              Nenhum produto cadastrado.                 " ROXO "||\n");
        printf(" '==========================================================='\n" RESET);
        return;
    }

    printf(ROXO " ||" AMARELO " %-6s | %-25s | %-6s | %-10s " ROXO "||\n", "COD", "NOME", "QTD", "PRECO");
    printf(" ||--------|---------------------------|--------|------------||\n" RESET);

    while(atual != NULL ){
        printf(ROXO " ||" RESET " %-6d | %-25s | %-6d | R$ %-8.2f " ROXO "||\n", 
               atual->codigo, atual->nome, atual->qtde, atual->preco);
        atual = atual->proximo;
    }
    printf(ROXO " '==========================================================='\n" RESET);
}

Produtos* buscarProduto(Produtos* lista, int codigo){
    Produtos* atual = lista->proximo;
    while(atual != NULL){  
        if(atual->codigo == codigo){
            printf(VERDE "\n .---------------------------------------.\n");
            printf(" | PRODUTO ENCONTRADO                    |\n");
            printf(" |---------------------------------------|\n" RESET);
            printf(" | Codigo:     %-4d                      |\n", atual->codigo);
            printf(" | Nome:       %-25s |\n", atual->nome);
            printf(" | Preco:      R$ %-22.2f |\n", atual->preco);
            printf(" | Quantidade: %-4d                      |\n", atual->qtde);
            printf(VERDE " '---------------------------------------'\n" RESET);
            return atual;
        }
        atual = atual->proximo;
    }
    printf(VERMELHO "\n  [!] Produto nao encontrado!\n" RESET);
    return NULL;
}

void editarProduto(Produtos* lista, int codigo){
    Produtos* editar = buscarProduto2(lista, codigo);
    if(editar != NULL){
        printf(ROXO "\n .=======================================.\n");
        printf(" ||           EDITAR PRODUTO            ||\n");
        printf(" '======================================='\n" RESET);
        
        printf("  >> Novo Nome: ");
        scanf(" %[^\n]", editar->nome);
        
        printf("  >> Novo Preco: ");
        scanf(" %f", &editar->preco);
    
        printf("  >> Nova Quantidade: ");
        scanf(" %d", &editar->qtde);
        
        printf(VERDE "\n  [v] Sucesso: Produto atualizado!\n" RESET);
    } else {
        printf(VERMELHO "\n  [!] Produto nao encontrado!\n" RESET);
    }
}

void removerProduto(Produtos* cabeca, int codigo){
   Produtos* anterior = cabeca;
   Produtos* atual = cabeca->proximo;

   while(atual != NULL && atual->codigo != codigo){
       anterior = atual;
       atual = atual->proximo;
   }
   if(atual != NULL && atual->codigo == codigo){
       anterior->proximo = atual->proximo;
       free(atual);
       printf(VERDE "\n  [v] Sucesso: Produto removido!\n" RESET);
       return;
   }
   printf(VERMELHO "\n  [!] Produto nao encontrado!\n" RESET);
}

void liberarProdutos(Produtos* lista){
    Produtos* atual = lista->proximo;
    while(atual != NULL){
        Produtos* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->proximo = NULL;
}

// ============================================================
//                   FUNÇÕES CARRINHO / PEDIDO
// ============================================================

ItemCarrinho * criarCarrinho(){
    ItemCarrinho * cabeca = malloc(sizeof(ItemCarrinho));
    if (cabeca != NULL) cabeca->proximo = NULL;
    return cabeca;
}

void adicionarProduto(ItemCarrinho *destino, Produtos * produto, int qtde){
    if (destino != NULL && produto != NULL){
        destino->codigo = produto->codigo;
        destino->preco = produto->preco;
        strcpy(destino->nome, produto->nome);
        destino->qtde = qtde;
        destino->proximo = NULL;
    }
}

void fazerPedido(Clientes *listaClientes, Produtos * listaProdutos){
    char cpf[15];
    int codigoProduto, i;
    
    printf(VERDE "\n .=======================================.\n");
    printf(" ||            NOVO PEDIDO              ||\n");
    printf(" '======================================='\n" RESET);
    
    printf("  >> Digite o CPF do Cliente: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente = BuscarCliente(cpf, listaClientes);

    if(cliente == NULL) {
        printf(VERMELHO "\n  [!] Cliente nao encontrado. Cadastre-o primeiro.\n" RESET);
        return;
    }

    printf("  >> Quantos produtos diferentes deseja adicionar? ");
    scanf(" %d", &i);

    for (int j = 0; j < i; j++){
        printf(AMARELO "\n  --- Adicionando Item %d de %d ---\n" RESET, j+1, i);
        
        listarProdutos(listaProdutos);

        printf("\n  >> Insira o codigo do produto: ");
        scanf(" %d", &codigoProduto);
        
        Produtos* prodEncontrado = buscarProduto(listaProdutos, codigoProduto);
        
        if(prodEncontrado != NULL) {
            int qtde;
            printf("  >> Quantidade desejada: ");
            scanf(" %d", &qtde);

            ItemCarrinho *item = malloc(sizeof(ItemCarrinho));
            adicionarProduto(item, prodEncontrado, qtde);

            ItemCarrinho * c = cliente->carrinho;
            while (c->proximo != NULL) c = c->proximo;
            c->proximo = item;
            printf(VERDE "  [v] Produto adicionado ao carrinho!\n" RESET);
        }
    }
}

void listarCarrinho(Clientes * listaClientes){
    char cpf[15];
    printf("\n  >> Digite o CPF para ver o carrinho: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente = BuscarCliente(cpf, listaClientes);
    
    if(cliente == NULL) {
        printf(VERMELHO "\n  [!] Cliente nao encontrado.\n" RESET);
        return;
    }

    ItemCarrinho * carrinho = cliente->carrinho;
    float total = 0;

    printf(VERDE "\n .=======================================================================.\n");
    printf(" ||                        CARRINHO DE COMPRAS                          ||\n");
    printf(" || Cliente: %-50s ||\n", cliente->nome);
    printf(" ||=====================================================================||\n" RESET);

    if (carrinho == NULL || carrinho->proximo == NULL) {
        printf(VERDE " ||" RESET "                       O carrinho esta vazio.                        " VERDE "||\n");
        printf(" '======================================================================='\n" RESET);
        return;
    }
    
    printf(VERDE " ||" AMARELO " %-6s | %-25s | %-5s | %-10s | %-10s " VERDE "||\n", "COD", "PRODUTO", "QTD", "UNITARIO", "SUBTOTAL");
    printf(" ||--------|---------------------------|-------|------------|------------||\n" RESET);

    for(ItemCarrinho *p = carrinho->proximo; p != NULL; p = p->proximo){
        float subtotal = p->preco * p->qtde;
        printf(VERDE " ||" RESET " %-6d | %-25s | %-5d | R$ %-7.2f | R$ %-7.2f " VERDE "||\n", 
               p->codigo, p->nome, p->qtde, p->preco, subtotal);
        total += subtotal;
    }
    printf(VERDE " ||---------------------------------------------------------------------||\n");
    printf(" || TOTAL DO PEDIDO:                                       R$ %-9.2f||\n", total);
    printf(" '======================================================================='\n" RESET);
}

void editarPedido(Clientes * listaClientes){
    char cpf[15];
    printf("\n  >> Digite o CPF: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente = BuscarCliente(cpf, listaClientes);
    
    if(cliente == NULL) {
        printf(VERMELHO "\n  [!] Cliente nao encontrado.\n" RESET);
        return;
    }
    
    ItemCarrinho * carrinho = cliente->carrinho;

    if (carrinho == NULL || carrinho->proximo == NULL) {
        printf(VERMELHO "\n  [!] O carrinho esta vazio.\n" RESET);
        return;
    }

    int codigoProduto, novaQtde;
    printf("  >> Codigo do produto para editar: ");
    scanf(" %d", &codigoProduto);

    ItemCarrinho * p = carrinho->proximo;
    while (p != NULL){
        if (p->codigo == codigoProduto){
            printf("  >> Nova quantidade: ");
            scanf(" %d", &novaQtde);
            p->qtde = novaQtde;
            printf(VERDE "\n  [v] Sucesso: Quantidade atualizada.\n" RESET);
            return;
        }
        p = p->proximo;
    }
    printf(VERMELHO "\n  [!] Produto nao encontrado no carrinho.\n" RESET);
}

void liberarCarrinho(ItemCarrinho* carrinho){
    ItemCarrinho* atual = carrinho->proximo;
    while(atual != NULL){
        ItemCarrinho* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(carrinho);
}



//                  FUNÇAO DO MENU 

void menu_trabalho(){
   Clientes * listaClientes = CriarListaCliente();
    Produtos* listaProdutos = CriarListaProduto();
 int i = 0;
    while(i != 4){
        
        
        printf(CIANO "\n .=======================================.\n");
        printf(" ||" AMARELO "           MENU PRINCIPAL            " CIANO "||\n");
        printf(" ||=====================================||\n");
        printf(" ||" RESET "  [1] Gerenciar Clientes             " CIANO "||\n");
        printf(" ||" RESET "  [2] Gerenciar Produtos             " CIANO "||\n");
        printf(" ||" RESET "  [3] Modo Compra (PDV)              " CIANO "||\n");
        printf(" ||" RESET "  [4] Sair do Sistema                " CIANO "||\n");
        printf(" '======================================='\n" RESET);
        printf(AMARELO "  Opcao: " RESET);
        scanf("%d", &i);
        
        switch (i) {
            case 1: {
                int j = 0;
                while(j != 5){
                    
                    
                    printf(CIANO "\n .=======================================.\n");
                    printf(" ||" AMARELO "         GESTAO DE CLIENTES          " CIANO "||\n");
                    printf(" ||=====================================||\n");
                    printf(" ||" RESET "  [1] Cadastrar Cliente              " CIANO "||\n");
                    printf(" ||" RESET "  [2] Listar Clientes                " CIANO "||\n");
                    printf(" ||" RESET "  [3] Editar Cliente                 " CIANO "||\n");
                    printf(" ||" RESET "  [4] Remover Cliente                " CIANO "||\n");
                    printf(" ||" RESET "  [5] Voltar ao Menu Anterior        " CIANO "||\n");
                    printf(" '======================================='\n" RESET);
                    printf(AMARELO "  Opcao: " RESET);

                    scanf("%d", &j);

                    switch(j){
                        case 1:
                            cadastrarCliente(listaClientes);
                            break;
                        case 2:
                            listarClientes(listaClientes);
                            break;
                        case 3: {
                            char busca[15];
                            printf("\nDigite o cpf: ");
                            scanf(" %[^\n]", busca);
                            Clientes * temp = BuscarCliente(busca, listaClientes);

                            if(temp == NULL) printf(VERMELHO "\n\n[!] Cliente nao encontrado.\n\n" RESET);
                            else editarCliente(temp);
                            break;
                        }
                        case 4: {
                            char busca[15];
                            printf("\nDigite o cpf: ");
                            scanf(" %[^\n]", busca);
                            Clientes * temp = BuscarCliente(busca, listaClientes);

                            if(temp == NULL) printf(VERMELHO "\n\n[!] Cliente nao encontrado.\n\n" RESET);
                            else removerCliente(listaClientes, temp);
                            break;
                        }
                        case 5:
                            break;
                        default:
                            printf(VERMELHO "\n[!] Opcao invalida! Tente novamente.\n" RESET);
                            break;
                    }
                }
                break; 
            }

            case 2: {
                int k = 0;
                while(k != 5){
                    
                    
                    printf(ROXO "\n .=======================================.\n");
                    printf(" ||" AMARELO "         GESTAO DE PRODUTOS          " ROXO "||\n");
                    printf(" ||=====================================||\n");
                    printf(" ||" RESET "  [1] Cadastrar Produto              " ROXO "||\n");
                    printf(" ||" RESET "  [2] Listar Produtos                " ROXO "||\n");
                    printf(" ||" RESET "  [3] Editar Produto                 " ROXO "||\n");
                    printf(" ||" RESET "  [4] Remover Produto                " ROXO "||\n");
                    printf(" ||" RESET "  [5] Voltar ao Menu Anterior        " ROXO "||\n");
                    printf(" '======================================='\n" RESET);
                    printf(AMARELO "  Opcao: " RESET);

                    scanf("%d", &k);

                    switch(k){
                        case 1:
                            cadastrarProduto(listaProdutos);
                            break;
                        case 2:
                            listarProdutos(listaProdutos);
                            break;
                        case 3: {
                            int codigo;
                            printf("\nDigite o codigo do produto a ser editado: ");
                            scanf("%d", &codigo);
                            editarProduto(listaProdutos, codigo);
                            break;
                        }
                        case 4: {
                            int codigo;
                            printf("\nDigite o codigo do produto a ser removido: ");
                            scanf("%d", &codigo);
                            removerProduto(listaProdutos, codigo);
                            break;
                        }
                        case 5:
                            break;
                        default:
                            printf(VERMELHO "\n[!] Opcao invalida! Tente novamente.\n" RESET);
                            break;
                    }
                }
                break;
            }

            case 3: {
                int l = 0;
                while(l != 4){
                    
                    
                    printf(VERDE "\n .=======================================.\n");
                    printf(" ||" AMARELO "           MODO DE COMPRAS           " VERDE "||\n");
                    printf(" ||=====================================||\n");
                    printf(" ||" RESET "  [1] Fazer Pedido de Cliente        " VERDE "||\n");
                    printf(" ||" RESET "  [2] Listar Produtos de Cliente     " VERDE "||\n");
                    printf(" ||" RESET "  [3] Editar Pedido                  " VERDE "||\n");
                    printf(" ||" RESET "  [4] Voltar ao Menu Anterior        " VERDE "||\n");
                    printf(" '======================================='\n" RESET);
                    printf(AMARELO "  Opcao: " RESET);

                    scanf("%d", &l);

                    switch(l){
                        case 1:
                            fazerPedido(listaClientes, listaProdutos);
                            break;
                        case 2:
                            listarCarrinho(listaClientes);
                            break;
                        case 3:
                            editarPedido(listaClientes);
                            break;
                        case 4:
                            break;
                        default:
                        printf(VERMELHO "\n[!] Opcao invalida! Tente novamente.\n" RESET);
                        break;
                    }
                }
                break;
            }

            case 4:
                liberarClientes(listaClientes);
                liberarProdutos(listaProdutos);
                free(listaClientes);
                free(listaProdutos);
                printf(VERDE "\nSaindo do programa... Ate logo!\n" RESET);
                break;
            
            default:
                printf(VERMELHO "\n[!] Opcao invalida! Tente novamente.\n" RESET);
                break;
            }
    }
}
