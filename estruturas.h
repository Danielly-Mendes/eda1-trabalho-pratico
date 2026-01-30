#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct _Clientes {
    int CPF, telefone, dt_nascimento;
    char nome[101];
    char email[101];
} Clientes;

typedef struct _Produtos {
    int codigo, preco, qtde;
    char nome[101];
} Produtos;

typedef struct _ItemCarrinho{
    int codigo, qtde, preco;
    char nome[101];
} ItemCarrinho;


#endif