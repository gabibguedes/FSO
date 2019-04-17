**Aluna:** Gabriela Barrozo Guedes  
**Matrícula:** 16/0121612

# Exercicio de Semforo

## Enunciado:
Faça duas funções em linguagem C, que possam ser usada por THREADS COOPERANTES ou por PROCESSOS COOPERANTES. A função `get_ticket()` deve retornar um número inteiro positivo ÚNICO a qualquer thread ou processo cooperante que chama-la.  

Protótipo:

``` c
    int get_ticket();
```

A função `return_ticket( int )` deve receber "de volta" um ticket (número inteiro), supostamente obtido anteriormente via get_ticket, de modo que esse ticket possa ser "reutilizado" por get_tickets subsequentes.

Protótipo:  
``` c
    void return_ticket( int t );
```

## Solução:

Para executar rode os comando:
``` sh
$ gcc semaforo.c -lpthread -o a
$ ./a
```

Escolha o número de tickets desejados e veja o resultado.

A função `get_ticket()` sempre gera um ticket de 0 a 99, com o valor de um ticket liberado. Com auxílio de um vetor de 100 posições, onde todos os tickets disponíveis estão com o valor `0`, e os ocupados com `1`, ao gerar um novo valor randomicamente, ele verifica a posição do vetor, se o valor estiver `1`, então o número está sendo usado, e gera um novo número aleatório. Caso todos os tickets estejam ocupados, a função retorna o valor `-1`.