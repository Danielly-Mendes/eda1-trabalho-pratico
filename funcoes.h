#ifndef FUNCOES_H
#define FUNCOES_H

#include "estruturas.h"

//funçoes produto 
Produtos* CriarListaProduto();

void cadastrarProduto(Produtos* lista);

void listarProdutos(Produtos* lista);

Produtos* buscarProduto(Produtos* lista, int codigo);

void editarProduto(Produtos* lista, int codigo);

void removerProduto(Produtos* lista, int codigo);

void liberarProdutos(Produtos* lista);

Produtos* buscarProduto2(Produtos* lista, int codigo);

//funçoes cliente

void limparCPF(char *cpf);
void limparTel(char *tel);
Clientes * CriarListaCliente();
void cadastrarCliente(Clientes *lista);
void listarClientes(Clientes *cabeca);
Clientes * BuscarCliente(char busca[15], Clientes *le);
void editarCliente(Clientes *cliente);
void removerCliente(Clientes *cabeca, Clientes *cliente);

//funçoes carrinho/pedido


ItemCarrinho * criarCarrinho();
void adicionarProduto(ItemCarrinho *destino, Produtos * produto, int qtde); 
void fazerPedido(Clientes *listaClientes, Produtos * listaProdutos);
void listarCarrinho(Clientes * cliente, Produtos *listarProdutos);















#endif