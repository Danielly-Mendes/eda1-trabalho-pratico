#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "clientes.h"
#include "clientes.c"
#include "produtos.h"
#include "produtos.c"

ItemCarrinho * criarCarrinho(){
    ItemCarrinho * cabeca;
    cabeca = malloc(sizeof(ItemCarrinho));

    if (cabeca != NULL) cabeca->proximo = NULL;
    return cabeca;
}

void adicionarProduto(ItemCarrinho *destino, Produtos * produto, int qtde){
    if (destino != NULL && produto != NULL){
        destino->codigo = produto->codigo;
        // destino->nome = produto->nome;
        destino->preco = produto->preco * qtde;
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

    printf("Quantos produtos diferentes deseja adicionar ao carrinho? ");
    scanf(" %d", &i);

    for (int j = 0; j < i; j++){
        printf("Insira o código do produto: ");
        scanf(" %d", &codigoProduto);

        int qtde;
        printf("Quantos deste produto deseja adicionar? ");
        scanf(" %d", &qtde);

        ItemCarrinho *item = (ItemCarrinho *) malloc(sizeof(ItemCarrinho));
        adicionarProduto(item, buscarProduto(listaProdutos, codigoProduto), qtde);


        ItemCarrinho * c = cliente->carrinho;
        while (c->proximo != NULL){
            c = c->proximo;
        }
        c-> proximo = item;
        printf("\nProduto adicionado ao carrinho.\n");
    }

}