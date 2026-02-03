#ifndef CARRINHO_H
#define CARRINHO_H

ItemCarrinho * criarCarrinho();
void adicionarProduto(ItemCarrinho *destino, Produtos * produto, int qtde); 
void fazerPedido(Clientes *listaClientes, Produtos * listaProdutos);
void listarCarrinho(Clientes * cliente, Produtos *listarProdutos);
<<<<<<< HEAD
=======
void editarPedido(Clientes * cliente, Produtos * listaProdutos);
>>>>>>> 8836682 (melhorando o menu, terminando a biblioteca de pedidos, juntando tudo em uma funçao so e criando um makefike)

#endif