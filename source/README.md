# Source code

Esta é a pasta onde se encontra o código fonte.

## Descrição dos ficheiros presentes

### main.c
- Este ficheiro contém a função main, i.e., inicia o programa.

<br>

### operators.h
- Esta biblioteca contém todas as funções que operam com os elementos da stack.<br /> Contém também um procedimento denominado apply_operation que usa como funções auxiliares as funções elementares presentes no ficheiro e utiliza-as quando for solicitado.

<br>

### parser.h
 - Esta biblioteca contém o procedimento parse que reconhece a linha escrita pelo utilizador e, para além disso, utiliza o apply_operation (operators.h) para efetuar as operações solicitadas.

<br>

### stack.h
- Esta biblioteca contém todas as estruturas, funções e procedimentos relativos à stack.