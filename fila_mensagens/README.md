# Como executar com docker:

1. Crie o docker e entre nele com o comando:
    ``` sh
    docker run -itv ~/path/to/folder/fila_mensagens:/docs gcc
    ```
1. No docker, entre na pasta `/docs` e execute os comandos para inicializar o **recebedor de mensagens**: 
    * Para compilar:
        ``` sh
        gcc -o mq-recv -lrt cliente_ticket.c
        ```
    * Para executar:
        ``` sh
        ./mq-recv
        ```

1. Abra outro terminal e encontre o id do docker que está rodando com o comando `docker ps`

1. Abra o container criado em outro terminal com o comando:
    ``` sh
    docker exec -it [DOCKER-ID] bash
    ```
1. Dentro do docker, entre na pasta `/docs` e execute os comandos para inicializar o **mandador de mensagens**:
    * Para compilar:
        ``` sh
        gcc -o mq-send -lrt api_ticket.c
        ```
    * Para executar:
        ``` sh
        ./mq-send
        ```