#ifndef CLIENTES_H
#define CLIENTES_H

#include "estruturas.h"

Clientes * CriarListaCliente();
void cadastrarCliente(Clientes *lista);
void listarClientes(Clientes *cabeca);
Clientes * BuscarCliente(char busca[15], Clientes *le);


#endif