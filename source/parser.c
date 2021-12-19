/**
 * @file parser.c
 * @brief Ficheiro com o código relativo à biblioteca parser.h
 * @copyright Orlando José da Cunha Palmeira A97755
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "operators.h"

void parse(char *line, STACK *stack, STACK_ELEMENT vars[]);

int str_len (char *s){
    int i = 0;
    while (*s != '\0'){
        s++;i++;
    }
    return i;
}

int belongs_to_string(char c, char *s){
    int result = 0, i = 0;
    while (*(s + i) != '\0'){
        if (c == *(s + i)){
            result = 1; return result;
        }
        i++;
    }
    return result;
}

char *str_tok(char *string, char *delims){
    char *result = (char*)calloc(str_len(string),sizeof(char));
    int i = 0;
    while(belongs_to_string(*string,delims) == 1)
        string++;
    while(belongs_to_string(*(string + i),delims) == 0 && strcmp(string,"") != 0 && i < str_len(string)){
        result[i] = *(string + i); i++;
    }
    result[i] = '\0';
    return strcmp(result,"\"") == 0 || strcmp(result,"") == 0 ||
           strcmp(result,"\0") == 0 ? NULL : result;
}

char *first_string(char *str, int *str_flag){
    *str_flag = 1;
    char *aux, *tofree, *result;
    if (*str == '\"' && *(str+1) == '\"'){
        result = (char*)calloc(2,sizeof(char));
        result[0] = '\0';
    }
    else{
        aux = strdup(str),
        tofree = aux,
        result = (char*)calloc(strlen(str), sizeof(char));
        int i = 0;
        while (*aux == ' ') aux++;
        while (*aux == '\"') aux++;
        while (*(aux+i) != '\"'){
            result[i] = *(aux+i); i++;
        }
        result[i] = '\0';
        free(tofree);
    }
    return result;
}

void delete_firsts(char **string, char *chars){
    while (belongs_to_string(*(*string),chars)) (*string)++;
}

void dropfl(char **string){
    (*string)++;
    int len = strlen(*string);
    (*string)[len-1] = '\0';
}

char *take_array_exp(char *string){
    int i = 0,index = 0;
    char *result = (char*)calloc(strlen(string), sizeof(char));
    do{
        if (*string == '['){
            i++; result[index] = *string;
        }
        else if (*string == ']'){
            i--; result[index] = *string;
        }
        else result[index] = *string;
        string++; index++;
    } while (i > 0);
    return result;
}

void create_array(char *line, STACK* stack, STACK_ELEMENT vars[]){
    STACK *array = (STACK*)malloc(sizeof(STACK)); init_stack(array);
    parse(line,array,vars);
    PUSH(stack,make_array(array));
}

void array_parsing(char **token, char **line_aux, STACK *stack, STACK_ELEMENT vars[]){
    *line_aux += strlen(*token);
    delete_firsts(line_aux," \t");
    dropfl(token); dropfl(token);
    delete_firsts(token, " \t");
    create_array(*token,stack,vars);
}

char *take_bloco_exp(char *string){
    int i = 0,index = 0;
    char *result = (char*)calloc(strlen(string), sizeof(char));
    do{
        if (*string == '{'){
            i++; result[index] = *string;
        }
        else if (*string == '}'){
            i--; result[index] = *string;
        }
        else result[index] = *string;
        string++; index++;
    } while (i > 0);
    return result;
}

void bloco_parsing(char **token, char **line_aux, STACK *stack){
    *line_aux += strlen(*token);
    delete_firsts(line_aux, " \t");
    dropfl(token); dropfl(token);
    delete_firsts(token, " \t");
    PUSH(stack, make_bloco(*token));
}

void init_token(char **token, char **line_aux, int *str_flag ,int len){
    if ((*line_aux)[0] == '\"') *token = first_string(*line_aux, str_flag);
    else if ((*line_aux)[0] == '[' ) *token = take_array_exp(*line_aux);
    else if (*(*line_aux) == '{') *token = take_bloco_exp(*line_aux);
    else *token = str_tok(*line_aux, " \n\t");
    (*line_aux)[len] = '\0';
}

void update_token(char **token, char **line_aux, int *str_flag){
    delete_firsts(line_aux, " \t");
    if (*(*line_aux) == '\"')  *token = first_string(*line_aux, str_flag);
    else if (*(*line_aux) == '[') *token = take_array_exp(*line_aux);
    else if (*(*line_aux) == '{') *token = take_bloco_exp(*line_aux);
    else{
        *token = str_tok(*line_aux, " \n\t"); *str_flag = 0;
    }
}

void map_array(STACK *stack, STACK_ELEMENT vars[]){
    STACK *new = (STACK*)calloc(1, sizeof(STACK)); init_stack(new);
    STACK_ELEMENT bloco = POP(stack), array = POP(stack), aux;
    int i, N = ((STACK*)array.dados)->how_many;
    for (i = 0; i < N; i++){
        aux = *copy_element(((STACK*)array.dados)->stack[i]);
        PUSH(new,aux);
        parse(bloco.dados, new, vars);
    }
    PUSH(stack, make_array(new));
}

void map_string(STACK *stack, STACK_ELEMENT vars[]){
    STACK *new = (STACK*)calloc(1,sizeof(STACK)); init_stack(new);
    STACK_ELEMENT bloco = POP(stack), string = POP(stack), aux;
    int i, N = strlen(string.dados); char *str = (char*)calloc(N+100, sizeof(char));
    for (i = 0; i < N; i++){
        aux = make_char(((char*)string.dados)[i]);
        PUSH(new, *copy_element(aux));
        parse(bloco.dados, new, vars);
    }
    for (i = 0; i < new->how_many; i++){
        str[i] = *(char*)new->stack[i].dados;
    }
    PUSH(stack, make_string(str));
}

void map(STACK* stack, STACK_ELEMENT vars[]){
    if (stack->stack[stack->how_many-2].t == STRING) map_string(stack, vars);
    else map_array(stack, vars);
}

void fold(STACK *stack, STACK_ELEMENT vars[]){
    STACK *new = (STACK*)calloc(1,sizeof(STACK)); init_stack(new);
    STACK_ELEMENT bloco = POP(stack), array = POP(stack), aux;
    PUSH(new, *copy_element(((STACK*)array.dados)->stack[0]));
    int i, N = ((STACK*)array.dados)->how_many;
    for (i = 1; i < N; i++){
        aux = *copy_element(((STACK*)array.dados)->stack[i]);
        PUSH(new,aux);
        parse(bloco.dados, new, vars);
    }
    PUSH(stack, make_array(new));
}

void filter (STACK *stack, STACK_ELEMENT vars[]){
    STACK *aux = (STACK*)calloc(1,sizeof(STACK)); init_stack(aux);
    STACK *new = (STACK*)calloc(1,sizeof(STACK)); init_stack(new);
    STACK_ELEMENT bloco = POP(stack), array = POP(stack);
    PUSH(aux, *copy_element(array)); PUSH(aux, bloco);
    map(aux,vars);
    int i, N = ((STACK*)(aux->stack[0].dados))->how_many;
    for (i = 0; i < N; i++){
        if (isTrue(((STACK*)(aux->stack[0].dados))->stack[i])) 
            PUSH(new, ((STACK*)array.dados)->stack[i]);
    }
    PUSH(stack, make_array(new));
}

void do_while(STACK *stack, STACK_ELEMENT vars[]){
    STACK_ELEMENT bloco = POP(stack);
    while (stack->how_many > 0){
        parse(bloco.dados, stack, vars);
        if (isTrue(stack->stack[stack->how_many-1])){
            POP(stack);
        }
        else{
            POP(stack); break;
        }
    }
}

void swap(TEMP temps[], int i, int j){
    TEMP aux = temps[i]; 
    temps[i] = temps[j];
    temps[j] = aux;
}

int partition(TEMP temps[], int N){
    int i, r = 0;
    for (i = 0; i < N - 1; i++){
        if (!isTrue(greater(temps[i].value,temps[N-1].value))){
            swap(temps, i, r); 
            r++;
        }
    }
    swap(temps,r,N - 1);
    return r;
}

void qSort(TEMP temps[], int N){
    int p;
    if (N > 1){
        p = partition(temps,N);
        qSort(temps,p);
        qSort(temps + p + 1, N - p - 1);   
    }
}

void sort(STACK *stack, STACK_ELEMENT vars[]){
    STACK_ELEMENT bloco = POP(stack), array = POP(stack), aux_arr = *copy_element(array);
    STACK *aux_s = (STACK*)calloc(1,sizeof(STACK)); init_stack(aux_s);
    PUSH(aux_s, aux_arr); PUSH(aux_s, bloco); map(aux_s, vars);
    int i, N = ((STACK*)array.dados)->how_many;
    TEMP temps[N];
    for (i = 0; i < N; i++){
        temps[i].elem = ((STACK*)array.dados)->stack[i];
        temps[i].value = ((STACK*)aux_s->stack[0].dados)->stack[i];
    }
    qSort(temps,N);
    for (i = 0; i < N; i++){
        ((STACK*)array.dados)->stack[i] = temps[i].elem; 
    }
    PUSH(stack,array);
}

/**
 * \brief Esta macro é de uso exclusivo da função parse e ordena-a a avisar a função apply_operation (operators.h) para fazer push de uma string.
 */
#define PUSH_STRING \
if (str_flag == 1) goto string_entry;

/**
 * \brief Esta macro é de uso exclusivo da função parse e chama esta função recursivamente para executar um bloco.
 */
#define EXECUTE_BLOCO \
if (stack->stack[stack->how_many-1].t == BLOCO && *token == '~'){\
    STACK_ELEMENT bloco = POP(stack);\
    parse(bloco.dados,stack, vars);\
    line_aux += strlen(token) + (str_flag == 1 ? 2 : 0);\
    free(token);\
    goto out;\
}

/**
 * \brief Esta macro é de uso exclusivo da função parse e utiliza a função map para executar um bloco nos elementos de um array/string.
 */
#define MAP \
if(stack->stack[stack->how_many-1].t == BLOCO && *token == '%'){\
    map(stack, vars);\
    line_aux += strlen(token) + (str_flag == 1 ? 2 : 0);\
    free(token); token = NULL; goto out;\
}\

/**
 * \brief Esta macro é de uso exclusivo da função parse e utiliza a função fold para usar um bloco como operador entre os elementos de um array.
 */
#define FOLD \
if (stack->stack[stack->how_many-1].t == BLOCO && *token == '*'){\
    fold(stack, vars);\
    line_aux += strlen(token) + (str_flag == 1 ? 2 : 0);\
    free(token); token = NULL; goto out;\
}\

/**
 * \brief Esta macro é de uso exclusivo da função parse e utiliza a função filter para manter num array os elementos que são verdadeiros.
 */
#define FILTER \
if (stack->stack[stack->how_many-1].t == BLOCO && *token == ','){\
    filter(stack,vars);\
    line_aux += strlen(token) + (str_flag == 1 ? 2 : 0);\
    free(token); token = NULL; goto out;\
}

/**
 * \brief Esta macro é de uso exclusivo da função parse e utiliza a função do_while para executar um bloco no topo da stack e manter essa execução até o resultado ser falso. 
 */
#define WHILE \
if (stack->stack[stack->how_many-1].t == BLOCO && *token == 'w'){\
    do_while(stack,vars);\
    line_aux += strlen(token) + (str_flag == 1 ? 2 : 0);\
    free(token); token = NULL; goto out;\
}

/**
 * \brief Esta macro é de uso exclusivo da função parse e utiliza a função sort para ordenar um array segundo um bloco.
 */
#define SORT \
if (stack->stack[stack->how_many-1].t == BLOCO && *token == '$'){\
    sort(stack,vars);\
    line_aux += strlen(token) + (str_flag == 1 ? 2 : 0);\
    free(token); token = NULL; goto out;\
}

/**
 * \brief Esta macro é de uso exclusivo da função parse e efetua as operações que não estão associadas aos de blocos e à PUSH_STRING.
 */
#define OTHER_CASES \
switch (*token){\
    case '[':\
        array_parsing(&token, &line_aux, stack, vars); free(token-2);\
        break;\
\
    case '{':\
        bloco_parsing(&token, &line_aux, stack); free(token-2);\
        break;\
    string_entry:\
    default:\
        apply_operation(token, stack, vars, str_flag);\
        line_aux += strlen(token) + (str_flag == 1 ? 2 : 0);\
        str_flag = 0;\
        free(token);\
        break;\
}

void parse(char *line, STACK *stack, STACK_ELEMENT vars[]){
    int len = strlen(line),
        str_flag = 0;
    char *line_aux = strdup(line),
         *token;
    delete_firsts(&line_aux, " \t");
    for (init_token(&token, &line_aux, &str_flag, len); token != NULL; update_token(&token, &line_aux, &str_flag)){
        PUSH_STRING
        EXECUTE_BLOCO
        MAP
        FOLD
        FILTER
        WHILE
        SORT
        OTHER_CASES
        out:;
    }
}