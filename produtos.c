
#include "estruturas.h" 
#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>


Produtos* CriarListaProdut(Produtos* lista){
   
    Produtos * cabeça = (Produtos*) malloc (sizeof(Produtos));
   
    if(cabeça != NULL){
        cabeça->proximo = NULL;
    
    }
return ;
}


void cadastrarProduto(Produtos** lista){

Produtos* novo = (Produtos*) malloc (sizeof(Produtos));
printf("/|----------- NOVO PRODUTO -----------|\\n");
printf("Codigo: ");

scanf("%d", &novo->codigo);
printf("Nome: ");

if(buscarProduto(lista, novo->codigo) != NULL)
{
    printf("Codigo ja cadastrado!\n");
    free(novo);
    return;
}

scanf("%[^\n]", novo->nome);
printf("Preco: ");
scanf("%f", &novo->preco);

printf("Quantidade: ");
scanf("%d", &novo->qtde);

novo->proximo = lista;
*lista = novo;

printf("||>> Produto cadastrado com sucesso! <<||\n");
}



void listarProdutos(Produtos* lista){
Produtos* atual = lista;
printf("|----------- LISTA DE PRODUTOS -----------|\n");
if(atual == NULL){
    printf("Nenhum produto cadastrado!\n");
    return;
}
while(atual != NULL ){

printf("Codigo: %d\n", atual->codigo);
printf("Nome: %s\n", atual->nome);
printf("Preco: %.2f\n", atual->preco);
printf("Quantidade: %d\n", atual->qtde);
printf("|-------------------------------|\n");

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
}
printf("Produto nao encontrado!\n");

return NULL;
}


void editarProduto(Produtos* lista, int codigo){
    while(lista != NULL ){
        
        if(lista->codigo == codigo){
         
        printf("Novo nome: ");
        scanf("%[^\n]", lista->nome);
        
        printf("Novo preco: ");
        scanf("%f", &lista->preco);
    
        printf("Nova quantidade: ");
        scanf("%d", &lista->qtde);
        
        printf("||>> Produto editado com sucesso!<<||\n");

        return;
        }
    

    lista = lista->proximo;
}
printf("Produto nao encontrado!\n");

}

void removerProduto(Produtos** lista,int codigo){
   Produtos* lixo = buscarProduto(*lista, codigo);
    if(lixo == NULL){
        printf("Produto nao encontrado!\n");
        return;
    }
    Produtos* atual = *lista;

    if(atual == lixo){
        *lista = (*lista)->proximo;
        free(lixo);
        return;
    }
        while(atual->proximo != lixo){
            atual = atual->proximo;
    }
    
    atual->proximo = lixo->proximo;
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

