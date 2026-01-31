#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

Clientes * CriarListaCliente(){
    Clientes * cabeca;
    cabeca = malloc(sizeof(Clientes));

    if (cabeca != NULL) cabeca->proximo = NULL;
    return cabeca;
}

void cadastrarCliente(Clientes *lista){
    Clientes *cliente;
    cliente = malloc(sizeof(Clientes));

    printf("-----------------NOVO CLIENTE---------------\n");

    printf("Nome: ");
    scanf(" %[^\n]", cliente->nome);

    printf("\nCPF [XXX.XXX.XXX-XX]: ");
    scanf(" %[^\n]", cliente->CPF);

    printf("\nData de nascimento [dd/mm/aa]: ");
    scanf(" %[^\n]", cliente->dt_nascimento);

    printf("\nTelefone [(xx) y yyyy-yyyy]: ");
    scanf(" %[^\n]", cliente->telefone);

    cliente->carrinho = NULL;
    cliente->proximo = NULL;

    Clientes *p = lista;
    while (p->proximo != NULL) {
        p = p->proximo;
    }

    p->proximo = cliente;
}

void listarClientes(Clientes *cabeca){
    for(Clientes *p = cabeca->proximo; p != NULL; p = p->proximo){
        printf("- %s\n", p->nome);
    }
}

Clientes * BuscarCliente(char busca[15], Clientes *le){
    Clientes *p;
    p = le->proximo;

    while (p != NULL){
        if (strcmp(busca, p->CPF) == 0) return p;
        p = p->proximo;        
    }   

    return NULL;
}


