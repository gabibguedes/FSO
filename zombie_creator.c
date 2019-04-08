#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	if (fork()> 0){
		scanf("%*d\n");
	}else{
		printf("brainzzzzz\n");
	}
	return 0;
}
