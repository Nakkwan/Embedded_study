#include <sys/types.h>  		//header for pid_t
#include <unistd.h> 			//header for fork()
#include <stdio.h>
#include <stdlib.h>

int g = 2;

int main(void){
	pid_t pid;
	int l = 3;

	printf("PID(%d): Parent g = %d. l = %d, \n", getpid(), g, l);

	if((pid = fork())<0){			//when error, fork() return error num
		perror("fork error");
		exit(1);
	}
	else if (pid == 0){				//fork() return 0 for child process
		g++;
		l++;
	}
	else {							//fork() return pid of child to parent
		wait();						//wait until child process finish
	}


	/*print parent's after child's becuase of wait function */
	printf("PID(%d): g = %d. l = %d, \n", getpid(), g, l);

	return 0;
}

