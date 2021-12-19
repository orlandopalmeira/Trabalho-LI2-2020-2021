/**
 * @file operators.h
 * @brief Esta biblioteca contém todas as funções relativas às operações que se efetuam com os elementos da stack.
 * @copyright Orlando José da Cunha Palmeira A97755
 */

#include "stack.h"

/**
 * \brief A função sum efetua a soma de dois elementos.
 * @param x Um elemento do tipo STACK_ELEMENT
 * @param y Um elemento do tipo STACK_ELEMENT
 * @returns O resultado da soma dos dois elementos no topo da stack.
 */
STACK_ELEMENT sum(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função sub efetua a subtração de dois elementos.
 * @param x Um elemento do tipo STACK_ELEMENT 
 * @param y Um elemento do tipo STACK_ELEMENT
 * @returns O resultado da subtração dos dois elementos no topo da stack.
 */
STACK_ELEMENT sub(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função mult efetua a multiplicação de dois elementos.
 * @param x Um elemento do tipo STACK_ELEMENT 
 * @param y Um elemento do tipo STACK_ELEMENT 
 * @returns O resultado da multiplicação dos dois elementos no topo da stack.
 */
STACK_ELEMENT mult(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função division efetua a divisão de dois elementos.
 * @param x Um elemento do tipo STACK_ELEMENT 
 * @param y Um elemento do tipo STACK_ELEMENT 
 * @returns O resultado da divisão dos dois elementos no topo da stack.
 */
STACK_ELEMENT division(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função increase incrementa um elemento.
 * @param x Um endereço de um STACK_ELEMENT
 * @returns O resultado do incremento do elemento do topo da stack em uma unidade.
 */
void increase (STACK_ELEMENT *x);

/**
 * \brief A função decrease decrementa um elemento.
 * @param x Um endereço de um STACK_ELEMENT
 * @returns O resultado do decremento do elemento do topo da stack em uma unidade.
 */
void decrease (STACK_ELEMENT *x);

/**
 * \brief A função rest calcula o resto da divisão inteira entre dois elementos.
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @param y Um elemento do tipo STACK_ELEMENT. 
 * @returns O resto da divisão inteira dos dois elementos do topo da stack.
 */
STACK_ELEMENT rest(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função exponentiation calcula a exponenciação de dois elementos.
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @param y Um elemento do tipo STACK_ELEMENT.
 * @returns O resultado da exponenciação dos dois elementos do topo da stack.
 */
STACK_ELEMENT exponentiation(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função AND efetua a operação 'e' (bitwise).
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @param y Um elemento do tipo STACK_ELEMENT.
 * @returns O resultado da operação & com os dois elementos do topo da stack.
 */
STACK_ELEMENT AND(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função OR efetua a operação 'ou' (bitwise).
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @param y Um elemento do tipo STACK_ELEMENT.
 * @returns O resultado da operação | com os dois elementos do topo da stack.
 */
STACK_ELEMENT OR(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função XOR efetua a operação 'xor' (bitwise).
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @param y Um elemento do tipo STACK_ELEMENT.
 * @returns O resultado da operação ^ com os dois elementos do topo da stack.
 */
STACK_ELEMENT XOR(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief A função NOT efetua a operação 'não' (bitwise).
 * @param x Um elemento do tipo STACK_ELEMENT.
 */
void NOT(STACK_ELEMENT *x);

/**
 * \brief Esta função retorna um elemento da stack conforme o índice fornecido.
 * @param Stack A stack.
 * @param index O índice do elemento a retirar.
 * @returns O elemento no índice passado como argumento.
 */
STACK_ELEMENT take(STACK *Stack, long index);

/**
 * \brief Esta função converte o elemento do topo da stack no inteiro correspondente. 
 * @param x endereço de um STACK_ELEMENT.
 */
void toInt(STACK_ELEMENT *x);

/**
 * \brief Esta função converte o elemento do topo da stack no número com vírgula flutuante correspondente.
 * @param x endereço de um STACK_ELEMENT.
 */
void toDouble(STACK_ELEMENT *x);

/**
 * \brief Esta função converte o elemento do topo da stack no caracter correspondente. 
 * @param x endereço de um STACK_ELEMENT.
 */
void toChar(STACK_ELEMENT *x);

/**
 * \brief Esta função converte o elemento do topo da stack na string correspondente. 
 * @param x endereço de um STACK_ELEMENT.
 */
void toString(STACK_ELEMENT *x);

/**
 * \brief Esta função lê uma linha do utilizador.
 * @param stack Stack principal. Onde é armazenada a linha. 
 */
void read_line(STACK *stack);

/**
 * \brief Esta função verifica se dois elementos são iguais.
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @param y Um elemento do tipo STACK_ELEMENT.
 * @returns O valor de verdade correspondente à igualdade dos dois elementos.
 */
STACK_ELEMENT equal(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief Esta função indica se um dado elemento x é maior que um dado elemento y.
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @param y Um elemento do tipo STACK_ELEMENT.
 * @returns O valor de verdade correspondente à relação x > y.
 */
STACK_ELEMENT greater(STACK_ELEMENT x, STACK_ELEMENT y);

/**
 * \brief Esta função verifica 3 elementos do topo da stack. Se o 1º for diferente de 0/não vazio, então coloca-se o 2º. Caso contrário, coloca o 3º.
 * @param stack A stack principal.
 */
void if_then_else(STACK *stack);

/**
 * \brief Esta função nega um valor lógico (0->1 e 1->0).
 * @param stack Stack principal.
 */
void negate(STACK *stack);

/**
 * \brief Esta função indica se um dado elemento é diferente de zero.
 * @param x Um elemento do tipo STACK_ELEMENT.
 * @returns O valor de verdade correspondente à desigualdade do elemento com zero. 
 */
int not_zero(STACK_ELEMENT x);

/**
 * \brief Esta função insere na stack um range de um número inteiro.
 * @param stack A stack principal
 * @param num O número que limita o range
 * 
 * A função range irá criar um array de inteiros cujos elementos se encontram no intervalo [0,num[ por 
 * ordem crescente. 
 */
void range(STACK *stack, int num);

/**
 * \brief Esta função recebe um array da stack e coloca todos os seus elementos na stack.
 * @param array O array sobre o qual a função irá atuar.
 * @param stack Stack onde serão colocados os elementos do array (stack principal) 
 */
void put_array(STACK *stack, STACK *array);

/**
 * \brief Esta função copia um elemento e devolve-o.
 * @param tocopy O elemento a copiar. 
 */
STACK_ELEMENT *copy_element(STACK_ELEMENT tocopy);

/**
 * \brief Esta função coloca um elemento no início de um array (índice 0) e coloca o array alterado na stack.
 * @param stack Stack principal. É para recolocar o array alterado de volta nela.
 * @param x O elemento a colocar no array.
 * @param array O array no qual se irá inserir o elemento dado à função.
 */
void insert_on_0(STACK *stack, STACK *array, STACK_ELEMENT x);

/**
 * \brief Esta função concatena dois arrays e coloca o resultado na stack.
 * @param stack Stack principal. É onde será colocado o array principal.
 * @param elem1 O array onde se irá guardar o resultado da concatenação.
 * @param elem2 O array que será concatenado ao array designado elem1. 
 */
void concat_array(STACK *stack, STACK_ELEMENT elem1, STACK_ELEMENT elem2);

/**
 * \brief Esta função concatena duas strings e coloca o resultado na stack.
 * @param stack Stack principal.
 * @param elem1 É a string onde será guardado o resultado da concatecação.
 * @param elem2 É a string que será concatenada à string designada elem1. 
 */
void concat_string(STACK *stack, STACK_ELEMENT elem1, STACK_ELEMENT elem2);

/**
 * \brief Esta função concatena um array múltiplas vezes e coloca o resultado na stack.
 * @param stack Stack principal.
 * @param array O array que será replicado.
 * @param num O número de vezes que a função irá replicar o array.
 */
void multiconcat_array(STACK *stack, STACK *array, int num);

/**
 * \brief Esta função concatena uma string múltiplas vezes e coloca o resultado na stack.
 * @param stack Stack principal.
 * @param string A string que será replicada.
 * @param num O número de vezes que a função irá replicar a string.
 */
void multiconcat_string(STACK *stack, STACK_ELEMENT string, int num);

/**
 * \brief Esta função concatena um array ou uma string múltiplas vezes e coloca o resultado na stack.
 * @param stack Stack principal.
 * @param elem É o array/string que será replicado(a).
 * @param num Número de vezes que a função irá replicar o array/string.
 * 
 * Esta função utiliza as funções multiconcat_array e multiconcat_string como auxiliares. Ela apenas decide
 * qual função irá utilizar. Foi criada para efeitos de compactação de código.
 */
void multiconcat(STACK *stack, STACK_ELEMENT elem, int num);

/**
 * \brief Esta função retira o primeiro elemento de um array e devolve esse elemento.
 * @param array Array sobre o qual a função irá atuar.
 * @returns O elemento retirado.
 */
STACK_ELEMENT delete_first_array(STACK *array);

/**
 * \brief Esta função retira o primeiro elemento de uma string e devolve esse elemento.
 * @param string String sobre a qual a função irá atuar.
 * @returns O elemento retirado. 
 */
STACK_ELEMENT delete_first_string(STACK_ELEMENT *string);

/**
 * \brief Esta função retira o primeiro elemento de um array/string e devolve esse elemento.
 * @param elem Array/string sobre o(a) qual a função irá atuar.
 * @returns O elemento retirado.
 * 
 * Esta função utiliza as funções delete_first_array e delete_first_string como auxiliares e apenas
 * decide qual dessas funções irá utilizar. Foi feita apenas para efeitos de compactação do código. 
 */
STACK_ELEMENT delete_first(STACK_ELEMENT *elem);

/**
 * \brief Esta função retira o último elemento de uma string e devolve esse elemento.
 * @param string String sobre a qual a função irá atuar. 
 * @returns O elemento retirado.
 */
STACK_ELEMENT delete_last_string(STACK_ELEMENT *string);

/**
 * \brief Esta função retira o último elemento de um array/string e devolve esse elemento.
 * @param elem Array/string sobre o(a) qual a função irá atuar.
 * @returns O elemento retirado.
 * 
 * Esta função utiliza a função delete_last_string como auxiliar e, conforme o tipo do elemento, 
 * ela decide como irá atuar. Não foi feita uma função análoga para arrays uma vez que a implementação 
 * para essa estrutura é bastante simples. Esta função foi feita apenas para compactação de código. 
 */
STACK_ELEMENT delete_last(STACK_ELEMENT *elem);

/**
 * \brief Esta função mantém num array os primeiros n elementos que o utilizador decidir.
 * @param array Array sobre o qual a função irá atuar.
 * @param num Número de elementos que serão mantidos no array. 
 */
void first_elements_array(STACK *array, int num);

/**
 * \brief Esta função mantém numa string os primeiros n elementos que o utilizador decidir.
 * @param string String sobre a qual a função irá atuar.
 * @param num Número de elementos que serão mantidos na string. 
 */
void first_elements_string(STACK_ELEMENT *string, int num);

/**
 * \brief Esta função mantém num(a) array/string os primeiros n elementos que o utilizador decidir.
 * @param elem Array/string sobre o(a) qual a função irá atuar.
 * @param num Número de elementos que serão mantidos na string.
 * 
 * Esta função utiliza as funções first_elements_array e first_elements_array como auxiliares e irá decidir 
 * qual delas irá utilizar. Foi feita apenas para efeitos de compactação de código.
 */
void first_elements(STACK_ELEMENT *elem, int num);

/**
 * \brief Esta função mantém num array os últimos n elementos que o utilizador decidir.
 * @param array Array sobre o qual a função irá atuar.
 * @param num Número de elementos que serão mantidos no array. 
 */
void last_elements_array(STACK *array, int num);

/**
 * \brief Esta função mantém numa string os últimos n elementos que o utilizador decidir.
 * @param string String sobre a qual a função irá atuar.
 * @param num Número de elementos que serão mantidos na string. 
 */
void last_elements_string(STACK_ELEMENT *string, int num);

/**
 * \brief Esta função mantém num(a) array/string os últimos n elementos que o utilizador decidir.
 * @param elem Array/string sobre o(a) qual a função irá atuar.
 * @param num Número de elementos que serão mantidos na string.
 * 
 * Esta função utiliza as funções last_elements_array e last_elements_array como auxiliares e irá decidir 
 * qual delas irá utilizar. Foi feita apenas para efeitos de compactação de código
 */
void last_elements(STACK_ELEMENT *elem, int num);

/**
 * \brief Esta função irá verificar se uma certa string ocorre noutra string e devolve o seu índice. Se tal não ocorrer, devolve -1.
 * @param string1 String em que se verificará a existência da outra string.
 * @param string2 String que a função verifica a sua existência na string1. 
 * @returns Índice onde string2 ocorre em string1.
 */
int substring(char *string1, char *string2);

/**
 * \brief Esta função retorna os primeiros n elementos de uma string e retira esses elementos.
 * @param str Endereço da string sobre a qual a função atua.
 * @param n É o número de elementos que a função retira da string. 
 * @returns Os primeiros n elementos da string.
 */
char *take_string(char **str, int n);

/**
 * \brief Esta função indica se uma string está vazia.
 * @param str String a avaliar.
 */
int string_empty(char *str);

/**
 * \brief Esta função separa uma string em várias se existir dentro dela uma certa substring.
 * @param stack Stack principal. É onde será guardado o array com as strings derivadas da original.
 * @param string String que será repartida.
 * @param substr Substring que irá partir a string original.
 */
void separate_by_substring(STACK *stack, STACK_ELEMENT *string, STACK_ELEMENT *substr);

/**
 * \brief Esta função substitui os caracteres \a newline por outro numa string. 
 * @param str A string em que substituímos o \a newline
 * @param c O caracter usado na substituição.
 */
void replace_newline(char *str, char c);

/**
 * \brief Esta função separa uma string em várias se existir dentro dela um certo caracter.
 * @param stack Stack principal. É onde será guardado o array com as strings derivadas da original.
 * @param string String que será repartida.
 * @param c É o caracter que irá partir a string original.
 * @param newline_flag Esta flag serve para a função saber se deve substituir os caracteres \a newline na string por um espaco.
 * 
 * Observações: <br>
 * - O caracter c é passado sob a forma de string para facilitar a implementação da função.
 * - Se a newline_flag estiver com o valor 0, a função não faz a substituição acima referida.
 */
void separate_by_char(STACK *stack, STACK_ELEMENT *string, char *c, int *newline_flag);

/**
 * \brief Esta função corresponde ao comando t e apenas lê o input do utilizador e coloca-o na stack.
 * @param stack Stack principal.
 */
void read_all_input(STACK *stack);

/**
 * \brief Esta função verifica se um elemento é verdadeiro.
 * @param elem O elemento a avaliar
 * 
 * A função verifica se um elemento é diferente de 0 (se for um número) ou não vazio (se for string ou array) 
 */
int isTrue(STACK_ELEMENT elem);

/**
 * \brief Esta função decide qual operação associada ao comando '+' irá executar.
 * @param stack Stack principal 
 */
void plus_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '-'
 * @param stack Stack principal 
 */
void minus_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '*' irá executar.
 * @param stack Stack principal 
 */
void asterisk_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '/' irá executar.
 * @param stack Stack principal 
 */
void right_slash_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '(' irá executar.
 * @param stack Stack principal 
 */
void open_parentheses_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando ')' irá executar.
 * @param stack Stack principal 
 */
void closed_parentheses_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '%'.
 * @param stack Stack principal 
 */
void percentage_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '#' irá executar.
 * @param stack Stack principal 
 */
void cardinal_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '&'.
 * @param stack Stack principal 
 */
void bitwise_and_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '|'.
 * @param stack Stack principal 
 */
void bitwise_or_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '^'.
 * @param stack Stack principal 
 */
void bitwise_xor_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '~' irá executar.
 * @param stack Stack principal 
 */
void tilde_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '@'.
 * @param stack Stack principal 
 */
void at_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '_'.
 * @param stack Stack principal 
 */
void underscore_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '\'.
 * @param stack Stack principal 
 */
void left_slash_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando '$'.
 * @param stack Stack principal 
 */
void dollar_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando 'i'.
 * @param stack Stack principal 
 */
void i_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando 'f'.
 * @param stack Stack principal 
 */
void f_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando 'c'.
 * @param stack Stack principal 
 */
void c_command(STACK *stack);

/**
 * \brief Esta função executa a operação associada ao comando 's'.
 * @param stack Stack principal 
 */
void s_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '=' irá executar.
 * @param stack Stack principal 
 */
void equal_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '<' irá executar.
 * @param stack Stack principal 
 */
void lower_command(STACK *stack);

/**
 * \brief Esta função decide qual operação associada ao comando '>' irá executar.
 * @param stack Stack principal 
 */
void greater_command(STACK *stack);

/**
 * \brief Esta função decide se executa o comando 'N' ou 'N/'
 * @param stack Stack principal 
 * @param token Para saber qual o segundo caracter do comando.
 * @param newline_flag Argumento de bandeira para passar à função auxiliar para saber se deve substituir o caracter newline.
 * @param vars Array das variáveis. O N pode ser uma variável e, nesse caso, precisamos de consultar o array vars.
 */
void N_command(STACK *stack, char *token, int *newline_flag, STACK_ELEMENT vars[]);

/**
 * \brief Esta função decide se executa o comando 'S' ou 'S/'
 * @param stack Stack principal 
 * @param token Para saber qual o segundo caracter do comando.
 * @param newline_flag Argumento de bandeira para passar à função auxiliar para saber se deve substituir o caracter newline.
 * @param vars Array das variáveis. O S pode ser uma variável e, nesse caso, precisamos de consultar o array vars.
 */
void S_command(STACK *stack, char *token, int *newline_flag, STACK_ELEMENT vars[]);
 
/**
 * \brief Esta função decide se executa um dos seguintes comandos: e<, e>, e& ou e|.
 * @param stack A stack principal.
 * @param token Serve para saber qual o segundo caracter do token para decidir a operação a executar.
 */
void e_command(STACK *stack, char *token);

/**
 * \brief Esta função executa a operação associada ao comando ':'.
 * @param stack Stack principal 
 * @param token A função precisa de saber 0 2º caracter do token (nome da variável).
 * @param vars Esta função manipula variáveis pelo que precisamos de lhe fornecer o array das mesmas.
 */
void colon_command(STACK *stack, char *token ,STACK_ELEMENT vars[]);

/**
 * \brief Esta função executa a operação associada ao comando ','.
 * @param stack Stack principal 
 */
void comma_command(STACK *stack);

/**
 * \brief Esta função efetua o pushing de uma string se a str_flag for diferente de 0.
 * @param stack A stack principal
 * @param str_flag O uso deste argumento é explicado na descrição da função.
 * @param token O token é a string na qual queremos fazer push. 
 * 
 * A função retorna 1 se foi efetivamente executada e 0 caso contrário.
 */
int push_string(STACK *stack ,int str_flag, char *token);

/**
 * \brief Esta função efetua o pushing de um long se o comprimento de sobra_l for 0.
 * @param stack A stack principal.
 * @param sobra_l O uso deste argumento é explicado na descrição da função.
 * @param valL É o long que pretendemos fazer push (se for o caso).
 * 
 * A função retorna 1 se foi efetivamente executada e 0 caso contrário.
 */
int push_long(STACK *stack, char *sobra_l, long valL);

/**
 * \brief Esta função efetua o pushing de um double se o comprimento de sobra_d for 0.
 * @param stack A stack principal.
 * @param sobra_d O uso deste argumento é explicado na descrição da função.
 * @param valD É o double que pretendemos fazer push (se for o caso).
 * 
 * A função retorna 1 se foi efetivamente executada e 0 caso contrário.
 */
int push_double(STACK *stack, char *sobra_d, double valD);

/**
 * \brief Esta função efetua operações com os operandos da stack
 * @param token O operador ou operando sobre o qual se irá efetuar a operação.
 * @param stack O endereço da stack.
 * @param vars O array das variáveis.
 * @param str_flag Este inteiro serve para a função saber se o token recebido é uma string na qual se vai fazer um PUSH (o valor é 1 se for o caso).
 * 
 * A apply_operation, de acordo com o token recebido, averigua se este é um operando ou um operador,
 * Para o caso de ser um operando, apenas o acrescenta no topo da stack. Caso contrário, é porque o token
 * representa um operador e a função irá decidir qual a operação a aplicar.
 * 
 */
void apply_operation(char *token, STACK *stack, STACK_ELEMENT vars[], int str_flag);