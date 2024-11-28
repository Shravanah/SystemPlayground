#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void sp_handler(int sig_no){
	fprintf(stderr, "Recieved SIGPIPE \n");
	fflush(stderr);
	if(getenv("EXIT_ON_BROKEN_PIPE")){
		fprintf(stderr, "exiting\n");
		exit(1);
	}}

int main(){
	if (getenv("HANDLE_BROKEN_PIPE")){
			struct sigaction action1={};
			action1.sa_handler=sp_handler;
			action1.sa_flags=SA_RESTART;
			sigaction(SIGPIPE, &action1, NULL);
			}
			
	for (int i=0; 1; i++){
		printf("%d\n", i);
		}
	return 0;
}

