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
    int threads, i=0;
    srand(time(NULL));
    printf("Quantas tickets quer criar? ");
    scanf("%d", &threads);
    printf("\n\n");
    pthread_t ids[threads];
    sem_init (&S,0,1);
    
    while(i< (threads * 2)){
        pthread_create (&ids[i], NULL, (void *) thread_to_create, NULL);
        i++;
        pthread_create (&ids[i], NULL, (void *) thread_to_destroy,NULL);
        i++;
    }
    for(int i=0;i<threads;i++){
        pthread_join(ids[i],NULL);
    }
    return 0;    
}