#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	char *args[][4] = { 
		{"ls","-l",NULL},
		{"echo", "Hello",NULL},
		{"date",NULL},
		{NULL}
	};
	for (int i=0; args[i][0]!=NULL; i++){
		pid_t p=fork();
		if (p==0){
			printf("child %d here, I execute %s\n",i,args[i][0]);
			execvp(args[i][0], args[i]);
			perror("failed to exec\n");
		}
		else if(p>0){
			wait(NULL);
			printf("parent for child %d, child pid: %d, parent pid : %d\n",i,p,getpid());
		}
		else{
			perror("failed to fork\n");
			}
	}
	return 0;
}

