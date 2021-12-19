/**
 * @file parser.h
 * @brief Esta biblioteca contém as funções relativas ao parser.
 * @copyright Orlando José da Cunha Palmeira A97755
 */

#include "operators.h"

/**
 * \brief Esta função calcula o tamanho de uma string.
 * @param s É a string cujo tamanho vai ser calculado.
 * 
 * Observações: <br>
 * - A implementação desta função já existe pré-definida. No entanto, a versão original estava a causar
 * erros pelo que usamos outra implementação. 
 */
int str_len (char *s);

/**
 * @brief Esta função verifica se um dado caracter pertence a uma dada string.
 * @param c O caracter a testar na string s.
 * @param s A string em que se testa a presença do caracter c.
 * @returns O valor booleano que indica se um carater pertence, ou não, à string.
 */
int belongs_to_string(char c, char *s);

/**
 * @brief Implementação (ligeiramente) diferente da função strtok (string.h).
 * @param string A string de onde iremos retirar o token
 * @param delims A string onde se encontram os delimitadores.
 * 
 * Esta implementação da função strtok apenas foi feita para evitar erros que derivam da maneira como
 * a strtok original funciona.
 * 
 * @returns A primeira parte da string onde nenhum dos caracteres pertence aos delimitadores.
 */
char *str_tok(char *string, char *delims);

/**
 * \brief Esta função retira o conteúdo de uma string e devolve-o.
 * @param str É o token de onde será retirado o conteúdo (string).
 * @param str_flag Este inteiro servirá para "avisar" a função apply_operation (operators.h) de como deve atuar.
 * 
 * Esta função serve para, quando o parser detetar aspas no input, retornar o token do input sem as aspas
 * para passá-lo para o apply_operation (operators.h) com o formato correto para poder ser armazenado na stack.
 */
char *first_string(char *str, int *str_flag);

/**
 * \brief Esta função retira da string todos os caracteres do seu início que ocorram na string chars.
 * @param string String sobre a qual a função irá atuar.
 * @param chars String que contém os caracteres a retirar da string original.
 */
void delete_firsts(char **string, char *chars);

/**
 * \brief Esta função retira os primeiro e último elementos da string original.
 * @param string String sobre a qual a função irá atuar 
 */
void dropfl(char **string);

/**
 * \brief Esta função retira a parte da string do input do utilizador referente à criação de um array.
 * @param string É o input do utilizador (ou o token do input completo).
 */
char *take_array_exp(char *string);

/**
 * \brief Esta função cria um array e coloca-o dentro da stack.
 * @param line A expressão referente ao array que a função está a criar.
 * @param stack Stack principal para a função colocar o array,
 * @param vars Array de variáveis caso se necessite de usar variáveis dentro do array. 
 */
void create_array(char *line, STACK* stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função faz o parse exclusivamente para arrays.
 * @param token É a expressão/linha referente ao array
 * @param line_aux É o input inteiro do utilizador (apenas lhe é retirada a parte desnecessária)
 * @param stack Stack principal. Onde será armazenado o array
 * @param vars Array de variáveis no caso de necessidade de usar alguma das mesmas.
 */
void array_parsing(char **token, char **line_aux, STACK *stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função retira a parte da string do input do utilizador referente à criação de um bloco.
 * @param string É o input do utilizador (ou o token do input completo).
 */
char *take_bloco_exp(char *string);

/**
 * \brief Retira o interior do bloco (a parte dentro de { }) e coloca essa string na stack.
 * @param token É o endereço do token que contém o bloco.
 * @param line_aux Ésta é a linha principal do input e a função só a atualiza.
 * @param stack É a stack principal. Onde fazemos push do bloco.
 */
void bloco_parsing(char **token, char **line_aux, STACK *stack);

/**
 * \brief Esta função inicia o token. Retira a primeira parte útil do input.
 * @param token É onde será armazenado resultado.
 * @param line_aux É a linha de input de onde se retirará o token.
 * @param str_flag Este inteiro é "ativado" (passa a ser 1) caso se esteja a criar uma string (notifica a apply_operation (operators.h))
 * @param len É o número de elementos do line_aux
 */
void init_token(char **token, char **line_aux, int *str_flag ,int len);

/**
 * \brief Esta função serve para atualizar o token para um novo valor a operar.
 * @param token É o token que vai ser atualizado.
 * @param line_aux É a parte do input de onde se irá retirar o token.
 * @param str_flag É o inteiro que notifica a apply_operation (operators.h) se está a criar uma string.
 */
void update_token(char **token, char **line_aux, int *str_flag);

/**
 * \brief Esta função aplica um bloco a todos os elementos de um array.
 * @param stack Stack principal. Onde coloca o resultado.
 * @param vars O array de variáveis para o caso de haver necessidade de usar as mesmas.
 */
void map_array(STACK *stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função aplica um bloco a todos os elementos de uma string.
 * @param stack Stack principal. Onde coloca o resultado.
 * @param vars O array de variáveis para o caso de haver necessidade de usar as mesmas.
 */
void map_string(STACK *stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função aplica um bloco a um array ou a uma string.
 * @param stack Stack principal. Onde coloca o resultado.
 * @param vars O array de variáveis para o caso de haver necessidade de usar as mesmas.
 * 
 * Esta função usa a map_array e a map_string como auxiliares e decide qual delas usar comforme o tipo
 * ce dados que estamos a trabalhar.
 */
void map(STACK* stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função aplica um fold sobre um array
 * @param stack Stack principal. Onde coloca o resultado.
 * @param vars O array de variáveis para o caso de haver necessidade de usar as mesmas.
 */
void fold(STACK *stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função filtra os elementos de um array conforme o seu valor de verdade após lhes ser aplicado um bloco.
 * @param stack Stack principal. Onde coloca o resultado.
 * @param vars O array de variáveis para o caso de haver necessidade de usar as mesmas.
 */
void filter (STACK *stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função aplica um bloco ao elemento que está no topo da stack e, enquanto ele for verdadeiro, ela faz pop até ao valor da execução dar falso ou a stack acabar.
 * @param stack Stack principal. Onde coloca o resultado.
 * @param vars O array de variáveis para o caso de haver necessidade de usar as mesmas.
 */
void do_while(STACK *stack, STACK_ELEMENT vars[]);

/**
 * \brief Esta função permuta dois elementos num array de estruturas TEMP.
 * @param temps O array onde a função atua.
 * @param i Índice que troca com j
 * @param j Índice que troca com i 
 */
void swap(TEMP temps[], int i, int j);

/**
 * \brief Esta função rearranja um array de TEMP's de modo a que, no início, fiquem os elementos menores ou igual que o pivô e o resto com os maiores.
 * @param temps O array a atuar.
 * @param N O tamanho do array
 * 
 * Tomamos como pivô o último elemento do array, 
 */
int partition(TEMP temps[], int N);

/**
 * \brief Esta função implementa o algoritmo quicksort para arrays com estruturas TEMP,
 * @param temps O array a ordenar
 * @param N O tamanho do array 
 */
void qSort(TEMP temps[], int N);

/**
 * \brief Esta função ordena um array.
 * @param stack A stack principal. Onde guarda o array ordenado.
 * @param vars O array de variáveis para o caso de haver necessidade de usar as mesmas. 
 */
void sort(STACK *stack, STACK_ELEMENT vars[]);

/**
 * @brief Esta função efetua o parsing da expressão dada pelo utilizador e aplica as devidas operações.
 * @param line A linha do input do utilizador.
 * @param stack O endereço da stack.
 * @param vars O array das variáveis.
 *
 * A função parse analisa a expressão dada pelo utilizador e, a cada token (dado pela str_tok), aplica
 * a devida operação através da função apply_operation (operators.h)
 */
void parse(char *line, STACK *stack, STACK_ELEMENT vars[]);