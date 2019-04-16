# Exercicio de Semaforo

## Enunciado:
Faca duas funcoes em linguagem C, que possam ser usada por THREADS COOPERANTES ou por PROCESSOS COOPERANTES. A funcao `get_ticket()` retornar um numero inteiro positivo UNICO a qualquer thread ou processo cooperante que chama-la.  

Prototipo:

``` c
    int get_ticket();
```

A funcao `return_ticket( int )` deve receber "de volta" um ticket (numero inteiro), supostamente obtido anteriormente via get_ticket, de modo que esse ticket possa ser "reutilizado" por get_tickets subsequentes.

Prototipo:  
``` c
    void return_ticket( int t );
```

## Solução:

Para executar rode os comando:
``` sh
$ gcc semaforo.c -lpthread -o a
$ ./a
```