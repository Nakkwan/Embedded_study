#include <stdio.h>
#include <stdlib.h>

int glob;

int main(void){
	int local, *dynamic;
	dynamic = malloc(1383);

	printf("Local = %p\n", &local);
	printf("Dynamic = %p\n", dynamic);
	printf("Global = %p\n", &glob);
	printf("Main = %p\n", main);

	return 0;
}
