#ifndef CLIENTES_H
#define CLIENTES_H

#include "estruturas.h"

void limparCPF(char *cpf);
void limparTel(char *tel);
Clientes * CriarListaCliente();
void cadastrarCliente(Clientes *lista);
void listarClientes(Clientes *cabeca);
Clientes * BuscarCliente(char busca[15], Clientes *le);
void editarCliente(Clientes *cliente);
void removerCliente(Clientes *cabeca, Clientes *cliente);

#endif