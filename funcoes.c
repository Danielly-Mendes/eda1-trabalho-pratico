#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "carrinho.h"



//funçoes cliente

Clientes * BuscarCliente(char busca[15], Clientes *le);

Clientes * CriarListaCliente(){
    Clientes * cabeca;
    cabeca = malloc(sizeof(Clientes));

    if (cabeca != NULL) cabeca->proximo = NULL;
    return cabeca;
}

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


void cadastrarCliente(Clientes *lista){
    Clientes *cliente;
    cliente = malloc(sizeof(Clientes));

    printf("-----------------NOVO CLIENTE---------------\n");

    printf("Nome: ");
    scanf(" %[^\n]", cliente->nome);

    printf("\nCPF: ");
    scanf(" %[^\n]", cliente->CPF);
    limparCPF(cliente->CPF);

    if (BuscarCliente(cliente->CPF, lista) !=    NULL) {
        printf("Erro: CPF ja cadastrado!\n");
        free(cliente); // Libera memória alocada à toa
        return;
    }

    printf("\nData de nascimento [dd/mm/aa]: ");
    scanf(" %[^\n]", cliente->dt_nascimento);
    limparTel(cliente->telefone);

    printf("\nTelefone: ");
    scanf(" %[^\n]", cliente->telefone);

    cliente->carrinho = criarCarrinho();
    cliente->proximo = NULL;

    Clientes *p = lista;
    while (p->proximo != NULL) {
        p = p->proximo;
    }

    p->proximo = cliente;
    printf("\nCliente cadastrado com sucesso!\n");
}

void listarClientes(Clientes *cabeca){
    if (cabeca == NULL || cabeca->proximo == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    for(Clientes *p = cabeca->proximo; p != NULL; p = p->proximo){
        printf("- %s\n", p->nome);
    }
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
    printf("-----------------EDITAR CLIENTE---------------\n");
    printf("Nome: ");
    scanf(" %[^\n]", cliente->nome);

    printf("\nCPF: ");
    scanf(" %[^\n]", cliente->CPF);
    limparCPF(cliente->CPF);

    printf("\nData de nascimento [dd/mm/aa]: ");
    scanf(" %[^\n]", cliente->dt_nascimento);
    limparTel(cliente->telefone);

    printf("\nTelefone: ");
    scanf(" %[^\n]", cliente->telefone);
    
    printf("\nCliente editado com sucesso!\n");
}

void removerCliente(Clientes *cabeca, Clientes *cliente) {
    Clientes *anterior = cabeca;
    Clientes *atual = cabeca->proximo;

    // precisa liberar carrinho ANTES de liberar o cliente

    while (atual != NULL && atual != cliente) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        anterior->proximo = atual->proximo;
        printf("\nRemovendo %s...\n", atual->nome);
        free(atual);
        printf("\nCliente removido com sucesso!\n");
    }
}
//funçoes produto

#include "estruturas.h" 
#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

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
printf("/|----------- NOVO PRODUTO -----------|\\ \n");

printf("Codigo: \n");
scanf(" %d", &novo->codigo);


if(buscarProduto2(lista, novo->codigo) != NULL)
{
    printf("Codigo ja cadastrado!\n");
    free(novo);
    return;
}
printf("Nome: \n");

scanf(" %[^\n]", novo->nome);

printf("Preco: \n");
scanf(" %f", &novo->preco);

printf("Quantidade: \n");
scanf(" %d", &novo->qtde);

novo->proximo = lista->proximo;
lista->proximo = novo;

printf("||>> Produto cadastrado com sucesso! <<||\n");
}



void listarProdutos(Produtos* lista){
Produtos* atual = lista->proximo;
printf("|----------- LISTA DE PRODUTOS -----------|\n");
int i = 0;
if(atual == NULL){
    printf("Nenhum produto cadastrado!\n");
    return;
}
while(atual != NULL ){
printf("|----------- Produto %d -----------|\n", ++i);
printf("Codigo: %d\n", atual->codigo);
printf("Nome: %s\n", atual->nome);
printf("Preco: %.2f\n", atual->preco);
printf("Quantidade: %d\n", atual->qtde);
printf("|-------------------------------|\n");

atual = atual->proximo;
}
}

Produtos* buscarProduto(Produtos* lista, int codigo){
    
Produtos* atual = lista->proximo;

while(atual != NULL){  

    if(atual->codigo == codigo){
      printf("||>> Produto encontrado! <<||\n");
      printf("Codigo: %d\n", atual->codigo);
      printf("Nome: %s\n", atual->nome);
      printf("Preco: %.2f\n", atual->preco);     
      printf("Quantidade: %d\n", atual->qtde);
      return atual;}
atual = atual->proximo;
}
printf("Produto nao encontrado!\n");

return NULL;
}


void editarProduto(Produtos* lista, int codigo){
        
    Produtos* editar = buscarProduto2(lista, codigo);
    if(editar != NULL){
        
        if(editar->codigo == codigo){
         
        printf("Novo nome: ");
        scanf(" %[^\n]", editar->nome);
        
        printf("Novo preco: ");
        scanf(" %f", &editar->preco);
    
        printf("Nova quantidade: ");
        scanf(" %d", &editar->qtde);
        
        printf("||>> Produto editado com sucesso!<<||\n");

        return;
        }
    

    lista = lista->proximo;
}
printf("Produto nao encontrado!\n");

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
       printf("||>> Produto removido com sucesso! <<||\n");
       return;
       }
   
   printf("Produto nao encontrado!\n");
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

//funçoes carrinho/pedido

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "clientes.h"
#include "produtos.h"

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
    printf("Digite o cpf: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente;
    cliente = BuscarCliente(cpf, listaClientes);

    printf("\nQuantos produtos diferentes deseja adicionar ao carrinho? ");
    scanf(" %d", &i);

    for (int j = 0; j < i; j++){
        listarProdutos(listaProdutos);

        printf("\nInsira o código do produto: ");
        scanf(" %d", &codigoProduto);

        int qtde;
        printf("\nQuantos deste produto deseja adicionar? ");
        scanf(" %d", &qtde);
        

        ItemCarrinho *item = (ItemCarrinho *) malloc(sizeof(ItemCarrinho));
        adicionarProduto(item, buscarProduto(listaProdutos, codigoProduto), qtde);


        ItemCarrinho * c = cliente->carrinho;
        while (c->proximo != NULL){
            c = c->proximo;
        }
        c-> proximo = item;
        printf("\nProduto adicionado ao carrinho.\n\n");
    }

}

void listarCarrinho(Clientes * listaClientes, Produtos *listaProdutos){
    char cpf[15];
    printf("Digite o cpf: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente;
    cliente = BuscarCliente(cpf, listaClientes);
    ItemCarrinho * carrinho = cliente->carrinho;

    float total = 0;

    if (carrinho == NULL || carrinho->proximo == NULL) {
        printf("O carrinho está vazio.\n");
        return;
    }
    printf("Codigo  | produto              | quantidade | Preco unitario\n");
    for(ItemCarrinho *p = carrinho->proximo; p != NULL; p = p->proximo){
        printf("%d    | %s       | %d | %f \n", p->codigo, p->nome, p->qtde, p->preco * p->qtde);
        total += p->qtde * p->preco;
    }
    printf("Total: %f\n", total);
}

void editarPedido(Clientes * listaClientes, Produtos * listaProdutos){
    char cpf[15];
    printf("Digite o cpf: ");
    scanf(" %[^\n]", cpf);

    Clientes * cliente;
    cliente = BuscarCliente(cpf, listaClientes);
    ItemCarrinho * carrinho = cliente->carrinho;

    if (carrinho == NULL || carrinho->proximo == NULL) {
        printf("O carrinho está vazio.\n");
        return;
    }

    int codigoProduto, novaQtde;
    printf("Digite o codigo do produto que deseja editar: ");
    scanf(" %d", &codigoProduto);

    ItemCarrinho * p = carrinho->proximo;
    while (p != NULL){
        if (p->codigo == codigoProduto){
            printf("Digite a nova quantidade: ");
            scanf(" %d", &novaQtde);
            p->qtde = novaQtde;
            printf("Quantidade atualizada com sucesso.\n");
            return;
        }
        p = p->proximo;
    }
    printf("Produto nao encontrado no carrinho.\n");
}