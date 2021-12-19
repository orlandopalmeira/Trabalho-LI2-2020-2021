/**
 * @file stack.h
 * @brief Esta biblioteca contém todas as estruturas e funções relativas à stack.
 * @copyright Orlando José da Cunha Palmeira A97755
 */

/**
 * \brief Este tipo de dados serve como identificador do tipo de elemento da stack.
 *
 * O TIPO servirá como uma espécie de "etiqueta" que serve para determinar que tipo de elemento é armazenado
 * num dado local da stack.
 */
typedef enum{/** Elementos do tipo long */
    LONG,
    /** Elementos do tipo double */
    DOUBLE,
    /** Elementos do tipo char */
    CHAR,
    /** Elementos do tipo string */
    STRING,
    /** Elementos do tipo array */
    ARRAY,
    /** Elementos do tipo bloco */
    BLOCO
}TIPO;


/**
 * \brief Tipo de dados que representa cada elemento da stack.
 *
 * O STACK_ELEMENT é um tipo de dados que contém uma variável (TIPO) que identifica o tipo de valor armazenado
 * e variáveis que só serão utilizadas caso conforme o valor armazenado na variável t.
 * Exs: t == LONG, o elemento é do tipo long; t == string, o elemento é do tipo string.
 */
typedef struct STACK_ELEMENT{
    /** @brief Indica o tipo do elemento. */
    TIPO t;
    /** @brief Apontador genérico que armazena qualquer valor*/
    void *dados;
}STACK_ELEMENT;


/**
 * \brief STACK é uma estrutura de dados que armazena todos os elementos da stack e algumas informações sobre a mesma.
 */
typedef struct stack{
    /** \brief Esta variável serve para saber quantas células estão disponíveis na stack. Evita alocações desnecessárias de memória.*/
    int stack_size;
    /** \brief Esta variável indica os elementos "em vigor" na stack. Sucintamente, é o nº de elementos que ainda estão a ser utilizados.*/
    int how_many;
    /** \brief Este apontador serve para armazenar um array (a stack) de elementos genéricos.*/
    STACK_ELEMENT *stack;
}STACK;

/**
 * \brief TEMP é uma estrutura de dados auxiliar que armazena um elemento e o resultado de aplicar um bloco a esse elemento. (Usada para ordenação)
 */
typedef struct TEMP{
    /** \brief Este campo armazena o elemento */
    STACK_ELEMENT elem;
    /** \brief Este campo armazena o resultado de aplicar um bloco ao elemento*/
    STACK_ELEMENT value;
}TEMP;

/**
 * \brief Esta função inicia a stack ou um array.
 * @param Stack Stack ou array a ser iniciado.
 *
 * A função coloca o stack_size a 100 (uma vez que já aloca espaço, já temos 1oo células disponíveis) e o how_many a 0
 * (uma vez que ainda não tem elementos a ser utilizados).
 */
void init_stack(STACK *Stack);

/**
 * \brief Esta função transforma um inteiro num tipo válido (STACK_ELEMENT) para colocar na stack.
 * @param l O inteiro a ser convertido
 * @returns O inteiro dado sob a forma de STACK_ELEMENT
 */
STACK_ELEMENT make_long(long l);

/**
 * \brief Esta função transforma um double num tipo válido (STACK_ELEMENT) para colocar na stack.
 * @param d O double a ser convertido
 * @returns O double dado sob a forma de STACK_ELEMENT
 */
STACK_ELEMENT make_double(double d);

/**
 * \brief Esta função transforma um char num tipo válido (STACK_ELEMENT) para colocar na stack.
 * @param c O char a ser convertido
 * @returns O char dado sob a forma de STACK_ELEMENT
 */
STACK_ELEMENT make_char(char c);

/**
 * \brief Esta função transforma uma string num tipo válido (STACK_ELEMENT) para colocar na stack.
 * @param str A string a ser convertida
 * @returns A string dada sob a forma de STACK_ELEMENT
 */
STACK_ELEMENT make_string(char *str);

/**
 * \brief Esta função transforma um array num tipo válido (STACK_ELEMENT) para colocar na stack.
 * @param array O array a ser convertido
 * @returns O array dado sob a forma de STACK_ELEMENT
 */
STACK_ELEMENT make_array(STACK *array);

/**
 * \brief Esta função transforma uma string correspondente a um bloco num tipo válido (STACK_ELEMENT) para colocar na stack.
 * @param bloco A string a ser convertida
 * @returns A string dada sob a forma de STACK_ELEMENT (neste caso, do tipo bloco)
 */
STACK_ELEMENT make_bloco(char *bloco);

/**
 * \brief Esta função inicia todas as variáveis.
 * @param vars O array das variáveis.
 *
 * A função initialize_vars coloca todos os elementos do array vars (que armazena as variáveis)
 * com os valores padrão impostos pelo enunciado.
 */
void initialize_vars(STACK_ELEMENT vars[]);

/**
 * \brief Este procedimento imprime um elemento da stack.
 * @param elem Um elemento do tipo STACK_ELEMENT
 *
 * O print_element examina um dado STACK_ELEMENT e, conforme o tipo armazenado, irá decidir como imprimir
 * esse elemento.
 */
void print_element(STACK_ELEMENT elem);

/**
 * \brief Esta função imprime a stack no ecrã.
 * @param Stack A stack
 */
void PRINT_STACK(STACK *Stack);

/**
 * \brief Esta função coloca um elemento no topo da stack
 * @param Stack O endereço da stack.
 * @param new_element O elemento a ser colocado.
 *
 * A função PUSH vai verificar se a stack tem uma célula disponível na stack para colocar o novo elemento.
 * Se tal não acontecer, a função aloca mais espaço na stack, incrementa o stack_size, coloca o elemento no topo
 * e incrementa o how_many.
 */
void PUSH(STACK *Stack, STACK_ELEMENT new_element);

/**
 * \brief Esta função retira o elemento do topo da stack.
 * @param Stack O endereço da da stack.
 *
 * A função POP guarda o valor que está no topo da stack e decrementa o how_many (mas não o stack_size).
 *
 * @returns O elemento que estava no topo da stack.
 */
STACK_ELEMENT POP(STACK *Stack);