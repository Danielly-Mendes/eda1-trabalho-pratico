#ifndef CARRINHO_H
#define CARRINHO_H

ItemCarrinho * criarCarrinho();
void adicionarProduto(ItemCarrinho *destino, Produtos * produto, int qtde); 
void fazerPedido(Clientes *listaClientes, Produtos * listaProdutos);

#endif