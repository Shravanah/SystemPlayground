#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for fork()
#include <sys/types.h> // defines types used in system calls, such as pid_t, the type returned by fork()
#include <sys/wait.h> // for wait(). When you call wait(), it triggers a system call to the kernel. The kernel will manage the process scheduling and notify the parent process when its child has finished execution.

int main(){
	pid_t pid = fork(); // pid_t is a type that holds process IDs (PIDs). fork() returns a pid_t value.fork() creates a child process. The return value can be:0 in the child process.A positive integer (the PID of the child) in the parent process.-1 if fork() fails (e.g., due to system limits on the number of processes).

if (pid==-1){
	perror("fork failed");
	exit(1);
}
else if (pid==0){
	printf("Child POV: child pid : %d, parent pid : %d\n,",getpid(), getppid());
	// You can replace the child process with another program using exec()
    // execvp("ls", (char *[]){ "ls", "-l", NULL }); this would replace the child process with the ls -l command, if you wanted to run a different program in the child process.
    exit(0);  // Exit child process
}
else{
	// this will be executed by parent
	printf("parent pov parent pid : %d, child pid : %d\n", getpid(), pid);
	wait(NULL);
	printf("parent process finished\n");

}
return 0;
}

