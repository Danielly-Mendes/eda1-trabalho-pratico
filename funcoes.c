#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "carrinho.h"
#include "clientes.h"
#include "produtos.h"


//                   FUNÇÕES AUXILIARES

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
        if (tel[i] != ' ' && tel[i] != '(' && tel[i] == ')') {
            limpo[j] = tel[i];
            j++;
        }
    }
    limpo[j] = '\0';
    strcpy(tel, limpo);
}


//                   FUNÇÕES DE CLIENTES


Clientes * BuscarCliente(char busca[15], Clientes *le);

Clientes * CriarListaCliente(){
    Clientes * cabeca;
    cabeca = malloc(sizeof(Clientes));
    if (cabeca != NULL) cabeca->proximo = NULL;
    return cabeca;
}

void cadastrarCliente(Clientes *lista){
    Clientes *cliente;
    cliente = malloc(sizeof(Clientes));

    printf("\n .=======================================.\n");
    printf(" ||           NOVO CLIENTE              ||\n");
    printf(" '======================================='\n");

    printf("  >> Nome Completo: ");
    scanf(" %[^\n]", cliente->nome);

    printf("  >> CPF: ");
    scanf(" %[^\n]", cliente->CPF);
    limparCPF(cliente->CPF);

    if (BuscarCliente(cliente->CPF, lista) != NULL) {
        printf("\n  [!] Erro: CPF ja cadastrado no sistema!\n");
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
    printf("\n  [v] Sucesso: Cliente cadastrado!\n");
}

void listarClientes(Clientes *cabeca){
    printf("\n .=======================================================.\n");
    printf(" ||                 LISTA DE CLIENTES                   ||\n");
    printf(" ||=====================================================||\n");
    
    if (cabeca == NULL || cabeca->proximo == NULL) {
        printf(" ||             Nenhum cliente cadastrado.              ||\n");
        printf(" '======================================================='\n");
        return;
    }

    printf(" || %-30s | %-16s ||\n", "NOME", "CPF");
    printf(" ||--------------------------------|------------------||\n");

    for(Clientes *p = cabeca->proximo; p != NULL; p = p->proximo){
        printf(" || %-30s | %-16s ||\n", p->nome, p->CPF);
    }
    printf(" '======================================================='\n");
}

Clientes * BuscarCliente(char busca[15], Clientes *le){
    Clientes *p;
    p = le->proximo;
    limparCPF(busca);

    while (p != NULL){
        if (strcmp(busca, p->CPF) == 0) return p;
        p = p->proximo;        
    }   
    return NULL;
}

void editarCliente(Clientes *cliente){
    printf("\n .=======================================.\n");
    printf(" ||           EDITAR CLIENTE            ||\n");
    printf(" '======================================='\n");
    
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

    printf("\n  [v] Sucesso: Dados atualizados!\n");
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
        printf("\n  >> Removendo: %s...\n", atual->nome);
        free(atual);
        printf("  [v] Sucesso: Cliente removido!\n");
    }
}


//                   FUNÇÕES DE PRODUTOS


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
        if(atual->codigo == codigo){
            return atual;}
        atual = atual->proximo;
    }
    return NULL;
}

void cadastrarProduto(Produtos* lista){
    Produtos* novo = (Produtos*) malloc (sizeof(Produtos));
    
    printf("\n .=======================================.\n");
    printf(" ||           NOVO PRODUTO              ||\n");
    printf(" '======================================='\n");

    printf("  >> Codigo: ");
    scanf(" %d", &novo->codigo);

    if(buscarProduto2(lista, novo->codigo) != NULL) {
        printf("\n  [!] Erro: Codigo ja cadastrado!\n");
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

    printf("\n  [v] Sucesso: Produto cadastrado!\n");
}

void listarProdutos(Produtos* lista){
    Produtos* atual = lista->proximo;
    printf("\n .=======================================================.\n");
    printf(" ||                  ESTOQUE DE PRODUTOS                ||\n");
    printf(" ||=====================================================||\n");
    
    if(atual == NULL){
        printf(" ||              Nenhum produto cadastrado.             ||\n");
        printf(" '======================================================='\n");
        return;
    }

    printf(" || %-6s | %-25s | %-6s | %-8s ||\n", "COD", "NOME", "QTD", "PRECO");
    printf(" ||--------|---------------------------|--------|----------||\n");

    while(atual != NULL ){
        printf(" || %-6d | %-25s | %-6d | R$ %-5.2f ||\n", 
               atual->codigo, atual->nome, atual->qtde, atual->preco);
        atual = atual->proximo;
    }
    printf(" '======================================================='\n");
}

Produtos* buscarProduto(Produtos* lista, int codigo){
    Produtos* atual = lista->proximo;
    while(atual != NULL){  
        if(atual->codigo == codigo){
            printf("\n .---------------------------------------.\n");
            printf(" | PRODUTO ENCONTRADO                    |\n");
            printf(" |---------------------------------------|\n");
            printf(" | Codigo:     %-4d                      |\n", atual->codigo);
            printf(" | Nome:       %-25s |\n", atual->nome);
            printf(" | Preco:      R$ %-22.2f |\n", atual->preco);
            printf(" | Quantidade: %-4d                      |\n", atual->qtde);
            printf(" '---------------------------------------'\n");
            return atual;
        }
        atual = atual->proximo;
    }
    printf("\n  [!] Produto nao encontrado!\n");
    return NULL;
}

void editarProduto(Produtos* lista, int codigo){
    Produtos* editar = buscarProduto2(lista, codigo);
    if(editar != NULL){
        if(editar->codigo == codigo){
            printf("\n .=======================================.\n");
            printf(" ||           EDITAR PRODUTO            ||\n");
            printf(" '======================================='\n");
            
            printf("  >> Novo Nome: ");
            scanf(" %[^\n]", editar->nome);
            
            printf("  >> Novo Preco: ");
            scanf(" %f", &editar->preco);
        
            printf("  >> Nova Quantidade: ");
            scanf(" %d", &editar->qtde);
            
            printf("\n  [v] Sucesso: Produto atualizado!\n");
            return;
        }
        lista = lista->proximo;
    }
    printf("\n  [!] Produto nao encontrado!\n");
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
       printf("\n  [v] Sucesso: Produto removido!\n");
       return;
   }
   printf("\n  [!] Produto nao encontrado!\n");
}

void liberarProdutos(Produtos* lista){
    Produtos* atual = lista->proximo;
    Produtos* proximo;
    while(atual != NULL){
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->proximo = NULL;
}


//                   FUNÇÕES CARRINHO / PEDIDO


ItemCarrinho * criarCarrinho(){
    ItemCarrinho * cabeca;
    cabeca = malloc(sizeof(ItemCarrinho));
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
    
    printf("\n .=======================================.\n");
    printf(" ||            NOVO PEDIDO              ||\n");
    printf(" '======================================='\n");
    
    printf("  >> Digite o CPF do Cliente: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente;
    cliente = BuscarCliente(cpf, listaClientes);

 if(cliente == NULL) {
        printf("\n  [!] Cliente nao encontrado. Cadastre-o primeiro.\n");
        return;
    }

    printf("  >> Quantos produtos diferentes deseja adicionar? ");
    scanf(" %d", &i);

    for (int j = 0; j < i; j++){
        printf("\n  --- Adicionando Item %d de %d ---\n", j+1, i);
        
        listarProdutos(listaProdutos);

        printf("\n  >> Insira o codigo do produto: ");
        scanf(" %d", &codigoProduto);
        
        Produtos* prodEncontrado = buscarProduto(listaProdutos, codigoProduto);
        
        if(prodEncontrado != NULL) {
            int qtde;
            printf("  >> Quantidade desejada: ");
            scanf(" %d", &qtde);

            ItemCarrinho *item = (ItemCarrinho *) malloc(sizeof(ItemCarrinho));
            adicionarProduto(item, prodEncontrado, qtde);

            ItemCarrinho * c = cliente->carrinho;
            while (c->proximo != NULL){
                c = c->proximo;
            }
            c->proximo = item;
            printf("  [v] Produto adicionado ao carrinho!\n");
        }
    }
}

void listarCarrinho(Clientes * listaClientes, Produtos *listaProdutos){
    char cpf[15];
    printf("\n  >> Digite o CPF para ver o carrinho: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente;
    cliente = BuscarCliente(cpf, listaClientes);
    
    if(cliente == NULL) {
        printf("\n  [!] Cliente nao encontrado.\n");
        return;
    }

    ItemCarrinho * carrinho = cliente->carrinho;
    float total = 0;

    printf("\n .===================================================================.\n");
    printf(" ||                    CARRINHO DE COMPRAS                          ||\n");
    printf(" || Cliente: %-46s ||\n", cliente->nome);
    printf(" ||=================================================================||\n");

    if (carrinho == NULL || carrinho->proximo == NULL) {
        printf(" ||                   O carrinho esta vazio.                        ||\n");
        printf(" '==================================================================='\n");
        return;
    }
    
    printf(" || %-6s | %-25s | %-5s | %-10s | %-8s ||\n", "COD", "PRODUTO", "QTD", "UNITARIO", "SUBTOTAL");
    printf(" ||--------|---------------------------|-------|------------|----------||\n");

    for(ItemCarrinho *p = carrinho->proximo; p != NULL; p = p->proximo){
        float subtotal = p->preco * p->qtde;
        printf(" || %-6d | %-25s | %-5d | R$ %-6.2f | R$ %-5.2f||\n", 
               p->codigo, p->nome, p->qtde, p->preco, subtotal);
        total += subtotal;
    }
    printf(" ||-----------------------------------------------------------------||\n");
    printf(" || TOTAL DO PEDIDO:                                   R$ %-9.2f||\n", total);
    printf(" '==================================================================='\n");
}

void editarPedido(Clientes * listaClientes, Produtos * listaProdutos){
    char cpf[15];
    printf("\n  >> Digite o CPF: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente;
    cliente = BuscarCliente(cpf, listaClientes);
    
    if(cliente == NULL) {
        printf("\n  [!] Cliente nao encontrado.\n");
        return;
    }
    
    ItemCarrinho * carrinho = cliente->carrinho;

    if (carrinho == NULL || carrinho->proximo == NULL) {
        printf("\n  [!] O carrinho esta vazio.\n");
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
            printf("\n  [v] Sucesso: Quantidade atualizada.\n");
            return;
        }
        p = p->proximo;
    }
    printf("\n  [!] Produto nao encontrado no carrinho.\n");
}