#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H


typedef struct _ItemCarrinho ItemCarrinho;
typedef struct _Produtos Produtos;
typedef struct _Clientes Clientes;

typedef struct _Clientes {
    char  CPF[15], telefone[20], dt_nascimento[11];
    char nome[101];
    char email[101];
    struct _Clientes* proximo;
    ItemCarrinho* carrinho;
    int id;

} Clientes;

typedef struct _Produtos {
    int codigo, qtde;
    float preco;
    char nome[101];
    struct _Produtos* proximo;
    int id;
} Produtos;

typedef struct _ItemCarrinho{
    int codigo, qtde;
    float preco;
    char nome[101];
    struct _ItemCarrinho* proximo;
    int id ;
} ItemCarrinho;


#endif