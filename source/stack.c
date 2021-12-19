/**
 * @file stack.c
 * @brief Ficheiro com o código relativo à biblioteca stack.h
 * @copyright Orlando José da Cunha Palmeira A97755
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"

void init_stack(STACK *Stack){
    Stack->stack_size = 100;
    Stack->how_many = 0;
    Stack->stack = (STACK_ELEMENT*)malloc(sizeof(STACK_ELEMENT)*100);
}

STACK_ELEMENT make_long(long l){
    long *pv = (long*)malloc(sizeof(long));
    *pv = l;
    STACK_ELEMENT elem = {LONG, pv};
    return elem;
}

STACK_ELEMENT make_double(double d){
    double *pv = (double*)malloc(sizeof(double));
    *pv = d;
    STACK_ELEMENT elem = {DOUBLE, pv};
    return elem;
}

STACK_ELEMENT make_char(char c){
    char *pv = (char*)malloc(sizeof(char));
    *pv = c;
    STACK_ELEMENT elem = {CHAR, pv};
    return elem;
}

STACK_ELEMENT make_string(char *str){
    char *ps = strdup(str);
    STACK_ELEMENT elem = {STRING, ps};
    return elem;
}

STACK_ELEMENT make_array(STACK *array){
    STACK_ELEMENT elem = {ARRAY, array};
    return elem;
}

STACK_ELEMENT make_bloco(char *bloco){
    char *b = strdup(bloco);
    STACK_ELEMENT elem = {BLOCO, b};
    return elem;
}

void initialize_vars(STACK_ELEMENT vars[]){
    for (int i = 0; i < 26; i++){
        vars[i] = make_long(i+10);
    }
    free(vars[13].dados);vars[13] = make_char('\n');
    free(vars[18].dados);vars[18] = make_char(' ');
    free(vars[23].dados);vars[23] = make_long(0);
    free(vars[24].dados);vars[24] = make_long(1);
    free(vars[25].dados);vars[25] = make_long(2);
}

void print_element(STACK_ELEMENT elem){
    switch (elem.t){
        case LONG:
            printf("%ld", *(long*)elem.dados);
            break;

        case DOUBLE:
            printf("%g", *(double*)elem.dados);
            break;

        case CHAR:
            putchar(*(char*)elem.dados);
            break;

        case STRING:
            printf("%s",(char*)elem.dados);
            break;

        case ARRAY:
            PRINT_STACK((STACK*)elem.dados);
            break;

        default: // case BLOCO:
            printf("{ %s }", (char*)elem.dados);
            break;
    }
}

void PRINT_STACK(STACK *Stack){
    for (int i = 0; i < Stack->how_many; i++)
        print_element(Stack->stack[i]);
}

void PUSH(STACK *Stack, STACK_ELEMENT new_element){
    if(Stack->how_many >= Stack->stack_size){
        Stack->stack = (STACK_ELEMENT*)realloc(Stack->stack, sizeof(STACK_ELEMENT)*(Stack->how_many+101));
        Stack->stack_size += 100;
    }
    Stack->stack[Stack->how_many] = new_element;
    Stack->how_many++;
}

STACK_ELEMENT POP(STACK *Stack){
    STACK_ELEMENT popped = Stack->stack[Stack->how_many -1];
    Stack->how_many--;
    return popped;
}