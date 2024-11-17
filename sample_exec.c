#include <stdio.h>  // for printf() and perror()
#include <stdlib.h> // for exit() and NULL
#include <unistd.h> // for unix std functions like execvp()


int main(){
	char *args[]={"ls","-l",NULL}; //arguement array, NULL is required at the end to show arguements ended
	printf("executing 'ls -l'");    
	fflush(stdout); // ensures that anything buffered in stdout buffer is immediately written to terminal.[generally output is not immediately written to the terminal. instead it is held in the buffer and only written when the buffer is full. hence here it is been manually flushed.
	if (execvp("ls", args)==-1){ // execvp() is a sys call that replaces the current process image with new program. name of the program to execute is ls and args[] is an array of arguements to pass to that program. 
		perror("execvp failed"); // if execvp fails it will return -1 and hence it enters the condition where it prints the error. 
		exit(1); // exits the program with status of 1, indicating an error occured. 
	}
	printf("this will never be printed if exec() is successful");// because the ls replaced the old program.
return 0;
}

