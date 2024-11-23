#include<stdio.h>
#include<signal.h>

void handler(int sig){
	printf("Signal %d recieved\n",sig);
	
}

int main(){
	signal(SIGINT, handler);
	raise(SIGINT);
	return 0;
}

