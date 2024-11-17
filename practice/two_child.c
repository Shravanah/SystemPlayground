#include <stdio.h>
#include <unistd.h> // for sys level calls like fork(),exec(),sleep()
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait()
int main(){
	pid_t p1=fork();
	
	if (p1 == -1){
		perror("failed to create child1\n");
		return 1;
	}
	else if (p1 ==0){
		int esum=0;
		printf("Child1 here\n");
		for(int i=0; i<100; i+=2){
			esum=esum+i;
		}
		printf("even sum by child1 : %d\n",esum);
		return 0;
	}
	else{
		pid_t p2=fork();
		if (p2 == -1){
			perror("failed to create child2\n");
			return 1;
		}
		else if(p2==0){
			int osum=0;
			printf("Child2 here\n");
			for (int i=1; i<100; i+=2){
				osum=osum+i;
			}
			printf("odd sum by child2 : %d\n",osum);
			return 0;
		}
		wait(NULL);
		wait(NULL);
		printf("parent here: both finished\n");
		return 0;
	}
}

