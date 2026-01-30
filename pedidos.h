
#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "estruturas.h" 

void cadastrarProduto(Produtos** lista);

void listarProdutos(Produtos* lista);

Produtos* buscarProduto(Produtos* lista, int codigo);

void editarProduto(Produtos* lista);

void removerProduto(Produtos** lista);

void liberarProdutos(Produtos** lista);

#endif