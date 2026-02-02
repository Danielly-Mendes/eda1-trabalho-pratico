#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "carrinho.h"

void editarCliente(Clientes *cliente);

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

    if (BuscarCliente(cliente->CPF, lista) != NULL) {
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
    printf("\n\nCliente não encontrado.\n\n");
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
