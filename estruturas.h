#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define RESET   "\033[0m"
#define VERMELHO "\033[1;31m"
#define VERDE   "\033[1;32m"
#define AMARELO "\033[1;33m"
#define AZUL    "\033[1;34m"
#define ROXO    "\033[1;35m"
#define CIANO   "\033[1;36m"
#define BRANCO  "\033[1;37m"

typedef struct _ItemCarrinho ItemCarrinho;
typedef struct _Produtos Produtos;
typedef struct _Clientes Clientes;

typedef struct _Clientes {
    char  CPF[15], telefone[20], dt_nascimento[11];
    char nome[101];
    char email[101];
    struct _Clientes* proximo;
    ItemCarrinho* carrinho;

} Clientes;

typedef struct _Produtos {
    int codigo, qtde;
    float preco;
    char nome[101];
    struct _Produtos* proximo;
} Produtos;

typedef struct _ItemCarrinho{
    int codigo, qtde;
    float preco;
    char nome[101];
    struct _ItemCarrinho* proximo;
} ItemCarrinho;


#endif