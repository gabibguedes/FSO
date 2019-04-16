/*
Gabriela Barrozo Guedes
16/0121612

Exercício do Pickachu

Árvore Gerada:
            1
            |
            2
      /   /     \    \
     3   4      5     6
              /  |  \
              7  8  9
                    |
                    10

*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    char enter;

    printf("1st Process ID: %d\n", getpid()); // 1

    if(fork()){ //2
        printf("\nPress ENTER to exit");
    }else{
        if(fork()){ //3
            if(fork()){// 4
                if(fork()){//5
                    fork(); //6
                }
            }
        }else{
            if (fork()){// 7
                if (fork()){// 8
                    fork();// 9
                }
            }else{
                fork();// 10
            }
        }
    }
    scanf("%c", &enter);

    return 0;
}


