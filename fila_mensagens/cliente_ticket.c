/*
Aluna: Gabriela Barrozo Guedes
Matricula: 16/0121612
*/
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/stat.h>
#define QUEUE "/my_queue"

int main(){
    mqd_t queue;
    struct mq_attr attr;
    int msg;

    attr.mq_maxmsg = 10; // capacidade para 10 mensagens
    attr.mq_msgsize = sizeof(msg) ; // tamanho de cada mensagem
    attr.mq_flags = 0 ;

    if ((queue = mq_open(QUEUE, O_RDWR | O_CREAT, 0666, &attr)) < 0){
        perror("mq_open");
        exit(1);
    }

    // recebe cada mensagem e imprime seu conteudo
    for (;;){
        if ((mq_receive(queue, (void *)&msg, sizeof(msg), 0)) < 0){
            perror("mq_receive:");
            exit(1);
        }
        printf("Received msg value %d\n", msg);
    }
    return 0;
}