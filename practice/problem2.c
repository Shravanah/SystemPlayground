#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t p1=fork();
	if (p1==-1){
		perror("failed to fork");
		return 1;
	}
	else if (p1==0){
		printf("started child process\n");
		char*args[]={"date",NULL};
		if (execvp("date", args)==-1){
			perror("error\n");
			return 1;
		}}

	else{
		wait(NULL);
		printf("done\n");
		return 0;
	}
	}
