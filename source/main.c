/**
 * @file main.c
 * @brief Este é o ficheiro principal do programa. 
 * @copyright Orlando José da Cunha Palmeira A97755
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

/**
 * \brief Função principal do programa
 */
int main(){
    STACK stack; init_stack(&stack);
    STACK_ELEMENT vars[26]; initialize_vars(vars); // criação das variáveis e respetiva inicialização
    char line[10240];                              // string onde é armazenado o input do utilizador
    assert(fgets(line, 10240, stdin) != NULL);     // armazenamento do input na string
    assert(line[strlen(line) - 1] == '\n');  
    parse(line,&stack,vars);                       // parsing e execução de todas as operações
    PRINT_STACK(&stack);                           // impressão da stack no ecrã
    putchar('\n');
    return 0;
}