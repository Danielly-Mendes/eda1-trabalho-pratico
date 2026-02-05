#ifndef FUNCOES_H
#define FUNCOES_H

#include "estruturas.h"
// ============================================================
//                  FUNÇÕEOS CLIENTES
// ============================================================

Clientes* CriarListaCliente();
void cadastrarCliente(Clientes* lista);
void listarClientes(Clientes* lista);
Clientes* BuscarCliente(char busca[15], Clientes* lista);
void editarCliente(Clientes* cliente);
void removerCliente(Clientes* lista, Clientes* cliente);

// ============================================================
//                  FUNÇÕES PRODUTOS
// ============================================================

Produtos* CriarListaProduto();
void cadastrarProduto(Produtos* lista);
void listarProdutos(Produtos* lista);
void editarProduto(Produtos* lista, int codigo);
void removerProduto(Produtos* lista, int codigo);
Produtos* buscarProduto(Produtos* lista, int codigo);

// ============================================================
//                  FUNÇÕES CARRINHO / PEDIDO
// ============================================================


ItemCarrinho* criarCarrinho();
void fazerPedido(Clientes* listaClientes, Produtos* listaProdutos);
void listarCarrinho(Clientes* listaClientes);
void editarPedido(Clientes* listaClientes);

// ============================================================
//                 MENU PRINCIPAL
// ============================================================

void menu_trabalho();
#endif