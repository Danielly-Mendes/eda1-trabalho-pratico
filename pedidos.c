
#include "estruturas.h" 
#include "pedidos.h"
#include <stdio.h>
#include <stdlib.h>


void cadastrarProduto(Produtos** lista){
Produtos* novo = (Produtos*)malloc(sizeof(Produtos));
printf("/|----------- NOVO PRODUTO -----------|\\n");
printf("codigo: ");
scanf("%d", &novo->codigo);
if(buscarProduto(*lista, novo->codigo) != NULL) {
        printf(">> Erro: Código já existe!\n");
        free(novo);
        return;

}
}

void listarProdutos(Produtos* lista){
Produtos* atual = lista;
printf("----------- LISTA DE PRODUTOS -----------\n");
while(atual != NULL){
printf("Codigo: %d\n", atual->codigo);
printf("Nome: %s\n", atual->nome);
printf("Preco: %d\n", atual->preco);
printf("Quantidade: %d\n", atual->qtde);
printf("-------------------------------\n");
atual = atual->proximo;
}
}

Produtos* buscarProduto(Produtos* lista, int codigo){
    
Produtos* atual = lista;
while(atual != NULL){  
if(atual->codigo == codigo){
return atual;
}
atual = atual->proximo;

else {
    printf(">> Erro: Produto não encontrado!\n");
    free(novo);
    return NULL;
}
}
}

void editarProduto(Produtos* lista){
while(lista != NULL){
    if(lista->codigo == codigo){
        printf("Novo nome: ");
        scanf("%s", lista->nome);
        printf("Novo preco: ");
        scanf("%d", &lista->preco);
        printf("Nova quantidade: ");
        scanf("%d", &lista->qtde);
        printf(">> Produto editado com sucesso!\n");
        return;
    }
    lista = lista->proximo;
}




}

void removerProduto(Produtos** lista){
    Produtos* lixo = *lista;
    *lista = (*lista)->proximo;
    free(lixo);

}


void liberarProdutos(Produtos** lista){
    Produtos* atual = *lista;
    Produtos* proximo;
    while(atual != NULL){
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

