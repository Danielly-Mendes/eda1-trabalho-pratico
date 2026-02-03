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