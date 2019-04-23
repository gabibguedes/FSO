/*
Aluna: Gabriela Barrozo Guedes
Matricula: 16/0121612
*/
// Arquivo mq-send.c: envia mensagens para uma fila de mensagens POSIX.
// Em Linux, compile usando: cc -o mq-send -lrt mq-send.c
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#define QUEUE "/my_queue"
int main(int argc, char *argv[])
{
    mqd_t queue; // descritor da fila int msg; // mensagem a enviar
                 // abre a fila de mensagens, se existir
    if ((queue = mq_open(QUEUE, O_RDWR)) < 0)
    {
        perror("mq_open");
        exit(1);
    }
    for (;;)
    {
        int msg = random() % 100; // valor entre 0 e 99
                              // envia a mensagem
        if (mq_send(queue, (void *)&msg, sizeof(msg), 0) < 0)
        {
            perror("mq_send");
            exit(1);
        }
        printf("Sent message with value %d\n", msg);
        sleep(1);
    }
}