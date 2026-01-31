#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

Clientes * CriarListaCliente(){
    Clientes * cabeca;
    cabeca = malloc(sizeof(Clientes));
    cabeca->proximo;
    return cabeca;
}

void cadastrarCliente(Clientes *lista){
    Clientes *cliente;
    cliente = malloc(sizeof(Clientes));

    printf("-----------------NOVO CLIENTE---------------\n");

    printf("Nome: ");
    scanf("%s", cliente->nome);

    printf("CPF [XXX.XXX.XXX-XX]: ");
    scanf("%s", cliente->CPF);

    printf("Data de nascimento [dd/mm/aa]: ");
    scanf("%s", cliente->dt_nascimento);

    printf("Telefone [(xx) y yyyy-yyyy]: ");
    scanf("%s", cliente->telefone);

    cliente->carrinho = NULL;
    cliente->proximo = NULL;

    lista->proximo = cliente;
    lista = cliente;
}

void listarClientes(Clientes *cabeca){
    for(Clientes *p = cabeca->proximo; p != NULL; p = p->proximo){
        printf("- %s\n", p->nome);
    }
}

Clientes * BuscarCliente(char busca[15], Clientes *le){
    Clientes *p, *q;
    p = le;
    q = le->proximo;

    while (q != NULL && strcmp(busca, q->CPF) != 0){
        p = q;
        q = q->proximo;
    }
    if (strcmp(busca, p->CPF) == 0) return p;
}


