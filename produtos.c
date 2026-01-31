
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
printf("/|----------- NOVO PRODUTO -----------|\\n");

printf("Codigo: ");
scanf("%d", &novo->codigo);

printf("Nome: ");

if(buscarProduto2(lista, novo->codigo) != NULL)
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

novo->proximo = lista->proximo;
lista->proximo = novo;

printf("||>> Produto cadastrado com sucesso! <<||\n");
}



void listarProdutos(Produtos* lista){
Produtos* atual = lista->proximo;
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
        scanf("%[^\n]", editar->nome);
        
        printf("Novo preco: ");
        scanf("%f", &editar->preco);
    
        printf("Nova quantidade: ");
        scanf("%d", &editar->qtde);
        
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

