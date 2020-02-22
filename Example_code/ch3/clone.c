#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>


int g=2;

int sub_func(void *arg){
	g++;
	printf("PID(%d): Child g = %d \n", getpid(), g);
	sleep(2);

	return 0;
}

int main(void){
	int pid;
	int child_stack[4096];
	int l = 3;
	printf("PID(%d): Parent g = %d, l = %d \n", getpid(), g, l);
	clone(sub_func, (void *)(child_stack+4095), CLONE_VM | CLONE_THREAD | CLONE_SIGHAND, NULL);
	sleep(1);
	printf("PID(%d): Parnet g = %d, l = %d \n", getpid(), g, l);
	
	return 0;
}
