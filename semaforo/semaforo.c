/*
Aluna: Gabriela Barrozo Guedes
Matricula: 16/0121612
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>

int tickets_created[100] = {0};
pthread_t id, id2;
sem_t S;


int get_ticket(){
    int t = rand() % 100;
    while(tickets_created[t] != 0){
        get_ticket();
    }
    sem_wait(&S);
    tickets_created[t] = 1;
    printf("Ticket criado: %d\n", t);
    sem_post (&S);
    return t;
}

void return_ticket(int t){
    sem_wait(&S);
    tickets_created[t] = 0;
    printf("Ticket liberado: %d\n", t);
    sem_post (&S);
}

void * thread_to_create(void * a){
    get_ticket();
    pthread_exit(NULL);
}

void * thread_to_destroy(void * a){
    for(int i = 0; i < 100 ; i++){
        if(tickets_created[i] == 1){
            return_ticket(i);
        }
    }
    pthread_exit(NULL);
}

int main(){
    char enter;
    srand(time(NULL));
    int threads;
    printf("Quantas tickets quer criar? ");
    scanf("%d", &threads);
    printf("\n\n");
    pthread_t ids[threads];
    sem_init (&S,0,1);
    
    for(int i=0;i<threads;i++){
        pthread_create (&id, NULL, (void *) thread_to_create, NULL);
        pthread_create (&id2, NULL, (void *) thread_to_destroy,NULL);
    }
    pause();
    return 0;    
}