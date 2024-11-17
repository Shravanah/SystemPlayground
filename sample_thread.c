#include <stdio.h>
#include <unistd.h> //for sleep()
#include <pthread.h> // to implement thread
void *print_no(void* args){    //Since pthread functions don’t need to return a specific value, void* is often used to satisfy the requirement of returning a pointer, even if it’s just NULL. void* arg is a generic pointer that allows the function to accept any data type as input. void* arg can later be cast to the appropriate data type within the function, though in this case, we dont use it
	for(int i=0; i<=5; i++){
		printf("%d\n",i);
		sleep(1);
	}
	return NULL;
}
void* print_letter(void* args){
	char letters[] = { 'A','B','C','D','E'};
	for(int i=0; i<5; i++){
		printf("%c\n",letters[i]);
		sleep(1);
	}
	return NULL;
}


int main(){
	pthread_t th1,th2; //Declares two variables of type pthread_t, which will store the thread IDs for thread1 and thread2.

	if(pthread_create(&th1, NULL, print_no, NULL)!=0){ //&thread1: A pointer to thread1, where the thread ID will be stored. NULL: Default thread attributes (like priority or stack size). print_numbers: The function that the thread will run. NULL: Arguments passed to print_numbers, which is NULL since print_numbers doesn’t require arguments.
		perror("thread creation failed");
		return 1;
	}

	if(pthread_create(&th2, NULL, print_letter, NULL)!=0){
			perror("thread creation failed");
			return 1;
			}
	pthread_join(th1, NULL); //Waits for thread1 to complete. This function blocks the main program until thread1 finishes.
	pthread_join(th2, NULL); //Waits for thread2 to complete.
	printf("finished");
	return 0;
}

//Ensure you link the pthread library during compilation by using the -pthread flag.  <gcc -pthread <name of the program> -o <name of the executable>>



