/**
 * @file operators.c
 * @brief Ficheiro com o código relativo à biblioteca operators.h 
 * @copyright Orlando José da Cunha Palmeira A97755
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"


STACK_ELEMENT *copy_element(STACK_ELEMENT tocopy);

STACK_ELEMENT sum(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    if (x.t == LONG && y.t == LONG){
        z = make_long(*(long*)x.dados + *(long*)y.dados);
    }
    else if (x.t == LONG && y.t == DOUBLE){
        z = make_double(*(long*)x.dados + *(double*)y.dados);
    }
    else if (x.t == DOUBLE && y.t == LONG){
        z = make_double(*(double*)x.dados + *(long*)y.dados);
    }
    else{
        z = make_double(*(double*)x.dados + *(double*)y.dados);
    }
    return z;
}

STACK_ELEMENT sub(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    if (x.t == LONG && y.t == LONG){
        z = make_long(*(long*)x.dados - *(long*)y.dados);
    }
    else if (x.t == LONG && y.t == DOUBLE){
        z = make_double(*(long*)x.dados - *(double*)y.dados);
    }
    else if (x.t == DOUBLE && y.t == LONG){
        z = make_double(*(double*)x.dados - *(long*)y.dados);
    }
    else{
        z = make_double(*(double*)x.dados - *(double*)y.dados);
    }
    return z;
}

STACK_ELEMENT mult(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    if (x.t == LONG && y.t == LONG){
        z = make_long(*(long*)x.dados * *(long*)y.dados);
    }
    else if (x.t == LONG && y.t == DOUBLE){
        z = make_double(*(long*)x.dados * *(double*)y.dados);
    }
    else if (x.t == DOUBLE && y.t == LONG){
        z = make_double(*(double*)x.dados * *(long*)y.dados);
    }
    else{
        z = make_double(*(double*)x.dados * *(double*)y.dados);
    }
    return z;
}

STACK_ELEMENT division(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    if (x.t == LONG && y.t == LONG){
        z = make_long(*(long*)x.dados / *(long*)y.dados);
    }
    else if (x.t == LONG && y.t == DOUBLE){
        z = make_double(*(long*)x.dados / *(double*)y.dados);
    }
    else if (x.t == DOUBLE && y.t == LONG){
        z = make_double(*(double*)x.dados / *(long*)y.dados);
    }
    else{
        z = make_double(*(double*)x.dados / *(double*)y.dados);
    }
    return z;
}

STACK_ELEMENT increase (STACK_ELEMENT *x){
    STACK_ELEMENT result;
    switch (x->t)
    {
    case LONG:
        result = make_long((*(long*)(x->dados))+1);
        break;

    case DOUBLE:
        result = make_double(*(double*)(x->dados) +1);
        break;

    case CHAR:
        result = make_char((char)((int)(*(char*)(x->dados)) +1));
        break;

    default:
        break;
    }
    return result;
}

STACK_ELEMENT decrease (STACK_ELEMENT *x){
    STACK_ELEMENT result;
    switch (x->t)
    {
    case LONG:
        result = make_long((*(long*)(x->dados))-1);
        break;

    case DOUBLE:
        result = make_double(*(double*)(x->dados) -1);
        break;

    case CHAR:
        result = make_char((char)((int)(*(char*)(x->dados)) -1));
        break;

    default:
        break;
    }
    return result;
}

STACK_ELEMENT rest(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    z = make_long(*(long*)x.dados % *(long*)y.dados);
    return z;
}

STACK_ELEMENT exponentiation(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    if (x.t == LONG && y.t == LONG){
        z = make_long(pow(*(long*)x.dados, *(long*)y.dados));
    }
    else if (x.t == LONG && y.t == DOUBLE){
        z = make_double(pow(*(long*)x.dados, *(double*)y.dados));
    }
    else if (x.t == DOUBLE && y.t == LONG){
        z = make_double(pow(*(double*)x.dados, *(long*)y.dados));
    }
    else{
       z = make_double(pow(*(double*)x.dados, *(double*)y.dados));
    }
    return z;
}

STACK_ELEMENT AND(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    z = make_long(*(long*)x.dados & *(long*)y.dados);
    return z;
}

STACK_ELEMENT OR(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    z = make_long(*(long*)x.dados | *(long*)y.dados);
    return z;
}

STACK_ELEMENT XOR(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT z;
    z = make_long(*(long*)x.dados ^ *(long*)y.dados);
    return z;
}

void NOT(STACK_ELEMENT *x){
    *(long*)x->dados = ~(*(long*)x->dados);
}

STACK_ELEMENT take(STACK *Stack, long index){
    return (Stack->stack[Stack->how_many -index -1]);
}

void toInt(STACK_ELEMENT *x){
    switch (x->t)
    {
    case DOUBLE:
        *x = make_long(*(double*)x->dados);
        break;
    
    case CHAR:
        *x = make_long((int)(*(char*)x->dados));
        break;

    case STRING:
        *x = make_long(strtol((char*)x->dados, NULL, 10));  
        break;  
    
    default:
        break;
    }
}

void toDouble(STACK_ELEMENT *x){
    switch (x->t)
    {
    case LONG:
        *x = make_double(*(long*)x->dados);
        break;

    case CHAR:
        *x = make_double((double)(*(char*)x->dados));
        break;

    case STRING:
        *x = make_double(strtod((char*)x->dados, NULL));  
        break;
        
    default:
        break;
    }
}

void toChar(STACK_ELEMENT *x){
    switch (x->t)
    {
    case LONG:
        *x = make_char((char)(*(long*)x->dados));
        break;
    
    case DOUBLE:
        *x = make_char((char)(*(double*)x->dados));
        break;
        
    default:
        break;
    }
    x->t = CHAR;
}

void toString(STACK_ELEMENT *x){
    int N;
    switch (x->t)
    {
    case CHAR:
        *x = make_string((char*)x->dados);
        break;  

    case LONG:
        N = *(long*)x->dados;
        sprintf(x->dados, "%d", N);
    default:
        break;
    }
    x->t = STRING;
}

void read_line(STACK *stack){
    char line[10240];
    assert(fgets(line, 10240, stdin) != NULL);
    int len = strlen(line);
    line[len - 1] = '\0';
    assert(line[len - 1] == '\0');
    PUSH(stack, make_string(line));
}

STACK_ELEMENT equal(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT result;
    if (x.t == LONG){
        switch (y.t){
        case LONG:
            result = make_long(*(long*)x.dados == *(long*)y.dados);
            break;
        
        case DOUBLE:
            result = make_long(*(long*)x.dados == *(double*)y.dados);
            break;
        
        default:
            break;
        }
    }
    else if (x.t == DOUBLE){
        switch (y.t){
        case LONG:
            result = make_long(*(double*)x.dados == *(long*)y.dados);
            break;
        
        case DOUBLE:
            result = make_long(*(double*)x.dados == *(double*)y.dados);
            break;

        default:
            break;
        }
    }
    else if (x.t == CHAR){
        switch (y.t){
        case CHAR:
            result = make_long(*(char*)x.dados == *(char*)y.dados);
            break;
        
        default:
            break;
        }
    }
    else if (x.t == STRING){
        switch (y.t){
        case STRING:
            result = make_long(strcmp((char*)x.dados,(char*)y.dados) == 0);
            break;
        
        default:
            break;
        }
    }
    return result;
}

STACK_ELEMENT greater(STACK_ELEMENT x, STACK_ELEMENT y){
    STACK_ELEMENT result;
    if (x.t == LONG){
        switch (y.t){
        case LONG:
            result = make_long(*(long*)x.dados > *(long*)y.dados);
            break;

        case DOUBLE:
            result = make_long(*(long*)x.dados > *(double*)y.dados);
            break;

        case CHAR:
            result = make_long(*(long*)x.dados > (int)(*(char*)y.dados));
            break;

        default:
            break;
        }
    }
    else if (x.t == DOUBLE){
        switch (y.t){
        case LONG:
            result = make_long(*(double*)x.dados > *(long*)y.dados);
            break;

        case DOUBLE:
            result = make_long(*(double*)x.dados > *(double*)y.dados);
            break;

        case CHAR:
            result = make_long(*(double*)x.dados > (int)(*(char*)y.dados));
            break;

        default:
            break;
        }
    }
    else if (x.t == CHAR){
        switch (y.t){
        case LONG:
            result = make_long((int)(*(char*)x.dados) > *(long*)y.dados);
            break;

        case DOUBLE:
            result = make_long((int)(*(char*)x.dados) > *(double*)y.dados);
            break;

        case CHAR:
            result = make_long((int)(*(char*)x.dados) > *(long*)y.dados);
            break;

        default:
            break;
        }
    }
    else if (x.t == STRING){
        switch (y.t){
        case STRING:
            result = make_long(strcmp((char*)x.dados,(char*)y.dados) > 0);
            break;

        default:
            break;
        }
    }
    return result;
}

void if_then_else(STACK *stack){
    STACK_ELEMENT x, y, z, w;
    z = POP(stack); y = POP(stack); x = POP(stack);
    switch (x.t){
    case LONG: w = *(long*)x.dados ? y : z; break;

    case DOUBLE: w = *(double*)x.dados ? y : z; break;

    case ARRAY: w = (*(STACK*)x.dados).how_many != 0 ? y : z; break;

    default: w = strlen((char*)x.dados) != 0 ? y : z; break;
    }
    PUSH(stack,w);
}

void negate(STACK *stack){
    STACK_ELEMENT elem = POP(stack);
    switch (elem.t)
    {
    case LONG:
        elem = make_long(*(long*)elem.dados ? 0 : 1);
        break;
    
    case CHAR:
        elem = make_long(*(char*)elem.dados ? 0 : 1);
        break;
    
    case DOUBLE: 
        elem = make_long(*(double*)elem.dados ? 0 : 1);
        break;
    
    case ARRAY:
        elem = make_long((*(STACK*)elem.dados).how_many > 0 ? 0 : 1);
        break;
    
    default:
        elem = make_long(strlen((char*)elem.dados) != 0 ? 0 : 1);
        break;
    }
    PUSH(stack,elem);
}

int not_zero(STACK_ELEMENT x){
    int result = 0;
    switch (x.t)
    {
    case LONG:
        result = *(long*)x.dados != 0;
        break;
    
    case DOUBLE:
        result = *(double*)x.dados != 0;
        break;
    
    case CHAR:
        result = (int)(*(char*)x.dados) != 0;
        break;

    default:
        break;
    }
    return result;
}

void range(STACK *stack, int num){
    STACK *array = (STACK*)malloc(sizeof(STACK)); init_stack(array);
    int i;
    for (i = 0; i < num; i++)
        PUSH(array,make_long(i));
    PUSH(stack,make_array(array));
}

void put_array(STACK *stack, STACK *array){
    int i;
    for (i = 0; i < array->how_many; i++)
        PUSH(stack,*copy_element(array->stack[i]));
}

STACK_ELEMENT *copy_element(STACK_ELEMENT tocopy){
    STACK_ELEMENT *copy = (STACK_ELEMENT*)malloc(sizeof(STACK_ELEMENT));
    STACK* arr;
    switch (tocopy.t)
    {
    case LONG:
        *copy = make_long(*(long*)tocopy.dados);
        break;

    case DOUBLE:
        *copy = make_double(*(double*)tocopy.dados);
        break;

    case CHAR:
        *copy = make_char(*(char*)tocopy.dados);
        break;

    case STRING:
        *copy = make_string((char*)tocopy.dados);
        break;

    case ARRAY:
        arr = (STACK*)malloc(sizeof(STACK)); init_stack(arr);
        put_array(arr, (STACK*)tocopy.dados);
        *copy = make_array(arr);
        break;
    
    default: // case BLOCO:
        *copy = make_bloco((char*)tocopy.dados);
        break;
    }
    return copy;
}

void insert_on_0(STACK *stack, STACK *array, STACK_ELEMENT x){
    PUSH(array,make_long(0));
    int i, i2 = array->how_many -1;
    for (i = 0; i < array->how_many; i++){
        array->stack[i2] = array->stack[i2-1]; i2--;
    }
    array->stack[0] = x;
    PUSH(stack, make_array(array));
}

void concat_array(STACK *stack, STACK_ELEMENT elem1, STACK_ELEMENT elem2){
    if (elem1.t == ARRAY && elem2.t == ARRAY){
        put_array(elem1.dados, elem2.dados);
        PUSH(stack,elem1);
    }
    else if (elem1.t == ARRAY){
        PUSH(elem1.dados, elem2);
        PUSH(stack,elem1);
    }
    else insert_on_0(stack,elem2.dados,elem1);
}

void concat_string(STACK *stack, STACK_ELEMENT elem1, STACK_ELEMENT elem2){
    if (elem1.t == STRING && elem2.t == STRING) {
        strcat(elem1.dados,elem2.dados);
        PUSH(stack, elem1);
    }
    else if (elem1.t == STRING) {
        char str[1]; str[0] = *(char*)elem2.dados;
        strcat(elem1.dados,str);
        PUSH(stack, elem1);
    }
    else{
        char str[strlen(elem2.dados)+1], *temp = elem2.dados; 
        str[0] = *(char*)elem1.dados;
        int i;
        for (i = 1; i <= (int)strlen(elem2.dados); i++){
            str[i] = temp[i-1];
        }
        str[strlen(elem2.dados)+1] = '\0';
        PUSH(stack, make_string(str));
    }
}

void multiconcat_array(STACK *stack, STACK *array, int num){
    STACK *copy = malloc(sizeof(STACK)); init_stack(copy);
    put_array(copy,array); int i;
    for (i = 0; i < num -1; i++)
        put_array(array, copy);
    free(copy->stack);
    free(copy);
    PUSH(stack, make_array(array));
}

void multiconcat_string(STACK *stack, STACK_ELEMENT string, int num){
    char copy[strlen(string.dados)]; strcpy(copy, string.dados);
    int nmemb = strlen(string.dados)*num, i;
    char *aux = (char *)calloc(nmemb,sizeof(char)); free(string.dados);
    for (i = 0; i < num; i++)
        strcat(aux, copy);
    aux[nmemb] = '\0';
    PUSH(stack, make_string(aux));
    free(aux);
}

void multiconcat(STACK *stack, STACK_ELEMENT elem, int num){
    switch (elem.t){
    case ARRAY:
        multiconcat_array(stack, elem.dados, num);
        break;
    
    default:
        multiconcat_string(stack, elem, num);
        break;
    }
}

STACK_ELEMENT delete_first_array(STACK *array){
    STACK_ELEMENT result = *copy_element(array->stack[0]);
    int i;
    for (i = 0; i < array->how_many-1; i++)
        array->stack[i] = array->stack[i+1];
    array->how_many--;
    return result;
}

STACK_ELEMENT delete_first_string(STACK_ELEMENT *string){
    char *s = string->dados, result = s[0];
    s++; string->dados = s;
    return make_char(result);
}

STACK_ELEMENT delete_first(STACK_ELEMENT *elem){
    if (elem->t == ARRAY) return delete_first_array(elem->dados);
    else return delete_first_string(elem);
}

STACK_ELEMENT delete_last_string(STACK_ELEMENT *string){
    int len = strlen(string->dados);
    char *s = string->dados, result = s[len-1];
    s[len-1] = '\0';
    string->dados = s;
    return make_char(result);
}

STACK_ELEMENT delete_last(STACK_ELEMENT *elem){
    if (elem->t == ARRAY) return POP(elem->dados);
    else return delete_last_string(elem);
}

void first_elements_array(STACK *array, int num){
    while (array->how_many != num)
        array->how_many--;
}

void first_elements_string(STACK_ELEMENT *string, int num){
    char *s = string->dados; s[num] = '\0';
    string->dados = s;
}

void first_elements(STACK_ELEMENT *elem, int num){
    if (elem->t == ARRAY) first_elements_array(elem->dados,num);
    else first_elements_string(elem,num);
}

void last_elements_array(STACK *array, int num){
    int i, i2 = 0;
    for (i = num; i > 0; i--){
        array->stack[i2] = array->stack[array->how_many -i];
        i2++;
    }
    array->how_many = num;
}

void last_elements_string(STACK_ELEMENT *string, int num){
    int len = strlen(string->dados); char *s = string->dados;
    while (len != num){
        s++; len--;
    }
    string->dados = s;
}

void last_elements(STACK_ELEMENT *elem, int num){
    if (elem->t == ARRAY) last_elements_array(elem->dados, num);
    else last_elements_string(elem, num);
}

int substring(char *string1, char *string2){
    char *pos = strstr(string1, string2);
    if (pos == NULL) return -1;
    int len_s1 = strlen(string1), len_pos = strlen(pos);
    return len_s1 - len_pos;
}

char *take_string(char **str, int n){
    int i; char *result = (char*)calloc(n+1,sizeof(char));
    for (i = 0; i < n; i++){
        result[i] = *(*str);
        (*str)++;
    }
    return result;
} 

int string_empty(char *str){
    return strcmp(str,"") == 0;
}

void separate_by_substring(STACK *stack, STACK_ELEMENT *string, STACK_ELEMENT *substr){
    char *str = string->dados, *auxs; 
    int subs_len = strlen(substr->dados); // tamanho da substring
    STACK *array = (STACK*)malloc(sizeof(STACK)); init_stack(array); // array onde se guarda a string partida
    if (string_empty((char*)substr->dados) != 0){ // se a substring for vazia ele separa a string principal nos seus caracteres
        while (*str != '\0'){
            PUSH(array, make_char(*str)); str++;
        }
    }
    else {
        while (string_empty(str) == 0){
            int aux = substring(str, substr->dados);
            if (aux == -1){ 
                PUSH(array, make_string(str)); break;
            }
            auxs = take_string(&str,aux);
            if (strcmp(auxs,"") != 0) PUSH(array, make_string(auxs));
            str += subs_len;
        }
    }
    PUSH(stack, make_array(array));
}

void replace_newline(char *str, char c){
    char *aux = str;
    while (*aux != '\0'){ 
        *aux = *aux == '\n' ? c : *aux; aux++;
    }
}

void separate_by_char(STACK *stack, STACK_ELEMENT *string, char *c, int *newline_flag){
    char *str = string->dados, *auxs, *oldstr = NULL;
    STACK *array = malloc(sizeof(STACK)); init_stack(array); // criação do array onde sao colocadas as partições da string
    int aux;
    if (*newline_flag){ // este if contém código que substitui os newlines da string por espacos.
        str = strdup((char*)string->dados);
        oldstr = str;
        replace_newline(str, ' ');
    }
    while (string_empty(str) == 0){
        aux = substring(str, c);
        if (aux == -1){
            PUSH(array, make_string(str)); break;
        }
        auxs = take_string(&str,aux); str++; 
        str = *str == '\n' ? str +1 : str; // se o inicio da string tiver \n, este é eliminado
        if (strcmp(auxs,"") != 0 && auxs[0] != *c) 
            PUSH(array, make_string(auxs));
    }
    if(*newline_flag){
        free(oldstr); *newline_flag = 0;
    }
    PUSH(stack, make_array(array));
}

void read_all_input(STACK *stack){
    char line[10240];
    int i = 0;
    while (fgets(line+i,10240-i-1,stdin) != NULL && i < 10240){
        i = strlen(line);
    }
    PUSH(stack, make_string(line));
}

int isTrue(STACK_ELEMENT elem){
    int r = 0;
    switch (elem.t)
    {
    case LONG:
        r = *(long*)elem.dados != 0;
        break;

    case DOUBLE:
        r = *(double*)elem.dados != 0;
        break;

    case ARRAY:
        r = ((STACK*)elem.dados)->how_many != 0;
        break;
    
    default: // case string
        r = strlen((char*)elem.dados) != 0;
        break;
    }
    return r;
}

void plus_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    if (x.t == ARRAY || y.t == ARRAY) concat_array(stack, x,y);
    else if (x.t == STRING || y.t == STRING) concat_string(stack,x,y);
    else PUSH(stack, sum(x,y));
}

void minus_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    PUSH(stack,sub(x,y));
}

void asterisk_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    if (x.t == ARRAY || x.t == STRING) multiconcat(stack,x,*(long*)y.dados);
    else PUSH(stack,mult(x,y));
}

void right_slash_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    if (x.t == STRING && y.t == STRING) separate_by_substring(stack, &x,&y);
    else PUSH(stack,division(x,y));
}

void open_parentheses_command(STACK *stack){
    STACK_ELEMENT x,y;
    x = POP(stack);
    if(x.t == ARRAY || x.t == STRING){
        y = delete_first(&x);
        PUSH(stack,x);
        PUSH(stack,y);
    }
    else PUSH(stack, decrease(&x));
}

void closed_parentheses_command(STACK *stack){
    STACK_ELEMENT x,y;
    x = POP(stack);
    if(x.t == ARRAY || x.t == STRING){
        y = delete_last(&x);
        PUSH(stack,x);
        PUSH(stack,y);
    }
    else PUSH(stack, increase(&x));
}

void percentage_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    PUSH(stack,rest(x,y));
}

void cardinal_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    if (x.t == STRING && y.t == STRING)
        PUSH(stack, make_long(substring(x.dados,y.dados)));
    else if (x.t == STRING && y.t == CHAR){
        char *s = (char*)calloc(2,sizeof(char)); s[0] = *(char*)y.dados;
        PUSH(stack, make_long(substring(x.dados,s)));
    }
    else PUSH(stack,exponentiation(x,y));
}

void bitwise_and_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    PUSH(stack, AND(x,y));
}

void bitwise_or_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    PUSH(stack, OR(x,y));
}

void bitwise_xor_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    PUSH(stack, XOR(x,y));
}

void tilde_command(STACK *stack){
    STACK_ELEMENT x;
    x = POP(stack);
    if(x.t == LONG){
        NOT(&x); PUSH(stack,x);
    }
    else put_array(stack,x.dados);
}

void at_command(STACK *stack){
    STACK_ELEMENT x,y,z;
    z = POP(stack); y = POP(stack); x = POP(stack);
    PUSH(stack,y);PUSH(stack,z);PUSH(stack,x);
}

void underscore_command(STACK *stack){
    STACK_ELEMENT x = POP(stack);
    PUSH(stack,*copy_element(x)); PUSH(stack,*copy_element(x));
}

void left_slash_command(STACK *stack){
    STACK_ELEMENT x,y; y = POP(stack);x = POP(stack);
    PUSH(stack,y);
    PUSH(stack,x);
}

void dollar_command(STACK *stack){
    STACK_ELEMENT x;
    long index = *(long*)POP(stack).dados;
    x = take(stack,index);
    PUSH(stack,*copy_element(x));
}

void i_command(STACK *stack){
    STACK_ELEMENT x;
    x = POP(stack);
    toInt(&x);
    PUSH(stack,x);
}

void f_command(STACK *stack){
    STACK_ELEMENT x;
    x = POP(stack);
    toDouble(&x);
    PUSH(stack,x);
}

void c_command(STACK *stack){
    STACK_ELEMENT x;
    x = POP(stack);
    toChar(&x);
    PUSH(stack,x);
}

void s_command(STACK *stack){
    STACK_ELEMENT x;
    x = POP(stack);
    toString(&x);
    PUSH(stack,x);
}

void equal_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    if (x.t == ARRAY && y.t == LONG){
        STACK *arr = x.dados; PUSH(stack, arr->stack[*(long*)y.dados]);
    }
    else if (x.t == STRING && y.t == LONG){
        char *s = x.dados; PUSH(stack, make_char(s[*(long*)y.dados]));
    }
    else PUSH(stack,equal(x,y));
}

void lower_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    if ((x.t == ARRAY || x.t == STRING) && y.t == LONG){
        first_elements(&x,*(long*)y.dados);
        PUSH(stack,x);
    }
    else PUSH(stack,greater(y,x));
}

void greater_command(STACK *stack){
    STACK_ELEMENT x,y;
    y = POP(stack); x = POP(stack);
    if ((x.t == ARRAY || x.t == STRING) && y.t == LONG){
        last_elements(&x,*(long*)y.dados);
        PUSH(stack,x);
    }
    else PUSH(stack,greater(x,y));
}

void N_command(STACK *stack, char *token, int *newline_flag, STACK_ELEMENT vars[]){
    STACK_ELEMENT x;
    switch (*(token+1)) {
    case '/':
        x = POP(stack);
        *newline_flag = 0;
        separate_by_char(stack, &x,"\n",newline_flag);
        break;
    
    default: PUSH(stack,*copy_element(vars[13])); break;
    }
}

void S_command(STACK *stack, char *token, int *newline_flag, STACK_ELEMENT vars[]){
    STACK_ELEMENT x;
    switch (*(token+1)) {
    case '/':
        x = POP(stack);
        *newline_flag = 1;
        separate_by_char(stack, &x," ",newline_flag);
        break;
    
    default: PUSH(stack,*copy_element(vars[18])); break;
    }
}

void e_command(STACK *stack, char *token){
    STACK_ELEMENT x,y,z;
    switch (*(token + 1)) {
    case '<': 
        y = POP(stack); x = POP(stack);
        z = *(long*)greater(y,x).dados ? x : y;
        PUSH(stack,z);
        break;

    case '>':
        y = POP(stack); x = POP(stack);
        z = *(long*)greater(x,y).dados ? x : y;
        PUSH(stack,z);
        break;

    case '&': 
        y = POP(stack); x = POP(stack); z.t = LONG;
        if (not_zero(x) && not_zero(y))
            z = y;
        else z = make_long(0);
        PUSH(stack,z);
        break;

    case '|': 
        y = POP(stack); x = POP(stack); z.t = LONG;
        if (not_zero(x))
            z = x;
        else if (not_zero(y))
            z = y;
        else z = make_long(0);
        PUSH(stack,z);
        break;

    default:
        break;
    }
}

void colon_command(STACK *stack, char *token ,STACK_ELEMENT vars[]){
    STACK_ELEMENT x;
    x = POP(stack);
    vars[(int)(*(token+1)) -65] = *copy_element(x);
    PUSH(stack,x);
}

void comma_command(STACK *stack){
    STACK_ELEMENT x = POP(stack);
    switch (x.t){
    case LONG:
        range(stack,*(long*)x.dados);
        break;

    case STRING:
        PUSH(stack, make_long(strlen(x.dados)));
        break;

    default: PUSH(stack, make_long(((STACK*)x.dados)->how_many)); break;
    }
}

int push_string(STACK *stack ,int str_flag, char *token){
    int r = 0;
    if (str_flag != 0){
        PUSH(stack,make_string(token));
        r = 1;
    }
    return r;
}

int push_long(STACK *stack, char *sobra_l, long valL){
    int r = 0;
    if (strlen(sobra_l) == 0){
        PUSH(stack, make_long(valL));
        r = 1;
    }
    return r;
}

int push_double(STACK *stack, char *sobra_d, double valD){
    int r = 0;
    if(strlen(sobra_d) == 0){
        PUSH(stack, make_double(valD));
        r = 1;
    }
    return r;
}

/**
 * \brief Esta macro devolve o valor de verdade relativo à execução de um pushing de um valor.
 * 
 * Serve para a apply_operation saber se foi feito um pushing de um valor e,
 * deste modo, a apply_operation saberá se deve procurar por um comando ou não.
 */
#define PUSHING (push_string(stack, str_flag, token) || push_long(stack, sobra_l, valL) || push_double(stack, sobra_d, valD))

void apply_operation(char *token, STACK *stack, STACK_ELEMENT vars[], int str_flag){
    char *sobra_l, *sobra_d; 
    long valL = strtol(token, &sobra_l, 10);
    double valD = strtod(token, &sobra_d);
    int newline_flag;
    if (PUSHING) return;
    switch (*token){
        case '+': plus_command(stack); break;
        
        case '-': minus_command(stack); break;

        case '*': asterisk_command(stack); break;
        
        case '/': right_slash_command(stack); break;

        case '(': open_parentheses_command(stack); break;

        case ')': closed_parentheses_command(stack); break;

        case '%': percentage_command(stack); break;
        
        case '#': cardinal_command(stack); break;
        
        case '&': bitwise_and_command(stack); break;
        
        case '|': bitwise_or_command(stack); break;
        
        case '^': bitwise_xor_command(stack); break;

        case '~': tilde_command(stack); break;

        case '@': at_command(stack); break;

        case '_': underscore_command(stack); break;

        case ';': POP(stack); break;
        
        case '\\': left_slash_command(stack); break;

        case '$': dollar_command(stack); break;
        
        case 'i': i_command(stack); break;
        
        case 'f': f_command(stack); break;
        
        case 'c': c_command(stack); break;
        
        case 's': s_command(stack); break;
        
        case 'l': read_line(stack); break;
        
        case '=': equal_command(stack); break;
        
        case '<': lower_command(stack); break;
        
        case '>': greater_command(stack); break;
        
        case '?': if_then_else(stack); break;
        
        case '!': negate(stack); break;

        case 'N': N_command(stack, token, &newline_flag, vars); break;

        case 'S': S_command(stack, token, &newline_flag, vars); break;

        case 'e': e_command(stack,token); break;

        case ':': colon_command(stack, token, vars); break;

        case ',': comma_command(stack); break;

        case 't': read_all_input(stack); break;

        default: PUSH(stack, *copy_element(vars[(int)(*token) -65])); break;
    }
}