
#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "estruturas.h" 

Produtos* CriarListaProduto();

void cadastrarProduto(Produtos* lista);

void listarProdutos(Produtos* lista);

Produtos* buscarProduto(Produtos* lista, int codigo);

void editarProduto(Produtos* lista, int codigo);

void removerProduto(Produtos* lista, int codigo);

void liberarProdutos(Produtos* lista);

Produtos* buscarProduto2(Produtos* lista, int codigo);

#endif