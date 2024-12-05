#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#include<sys/wait.h>

int main(){
	int pipefd[2];
	char buffer[10];
	memset(buffer, 0, sizeof(buffer));  //sets all bytes of buffer to zero
	
	if (pipe(pipefd)<0){
		printf("Error creating pipe\n");
		exit(1);
	}

	pid_t child_pid=fork();
	assert(child_pid>=0);
		if (child_pid==0){
			close(pipefd[1]);
			ssize_t toread=read(pipefd[0],buffer,10);
			printf("child recieved: %s\n",buffer);
			exit(0);
		}
		close(pipefd[0]);

		strcpy(buffer, "hello");
		printf("Parent is sending: %s\n",buffer);
		write(pipefd[1], buffer, sizeof(buffer));
		wait(NULL);
		printf("Done\n");
	
return 0;
}
