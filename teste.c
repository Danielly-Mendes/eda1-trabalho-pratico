#include <stdio.h>
#include <stdlib.h>

// --- DEFINIÇÕES DE CORES (As mesmas do seu main.c) ---
#define COR_RESET    "\033[0m"
#define COR_VERMELHO "\033[1;31m"
#define COR_VERDE    "\033[1;32m"
#define COR_AMARELO  "\033[1;33m"
#define COR_CYAN     "\033[1;36m"
#define COR_BRANCO   "\033[1;37m"

int main() {
    // Limpa a tela para dar o efeito real
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("\n=== DEMONSTRACAO VISUAL DO SISTEMA ===\n\n");

    // 1. COMO VAI FICAR O MENU
    printf("1. Exemplo de Menu:\n");
    printf(COR_CYAN "=================================================\n");
    printf("      SISTEMA DE GESTÃO DE VENDAS\n");
    printf("=================================================\n" COR_RESET);
    
    printf(COR_AMARELO "  [1]" COR_RESET " Gerenciar Clientes\n");
    printf(COR_AMARELO "  [2]" COR_RESET " Gerenciar Produtos\n");
    printf(COR_AMARELO "  [3]" COR_RESET " Sair\n");
    
    printf(COR_CYAN "-------------------------------------------------\n" COR_RESET);
    printf(">> Escolha uma opcao: \n\n");

    // 2. MENSAGENS DE FEEDBACK
    printf("2. Exemplo de Mensagens:\n");
    
    // Sucesso (Verde)
    printf(COR_VERDE "||>> Sucesso: Cliente cadastrado com sucesso! <<||\n" COR_RESET);
    
    // Erro (Vermelho)
    printf(COR_VERMELHO "||>> Erro: CPF nao encontrado ou invalido!\n" COR_RESET);
    
    // Aviso / Pausa (Amarelo ou Branco)
    printf(COR_AMARELO "||>> Aviso: O estoque esta baixo.\n" COR_RESET);
    printf(COR_BRANCO "Pressione Enter para continuar..." COR_RESET);
    
    printf("\n\n");
    return 0;
}