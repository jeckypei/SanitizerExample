#include <stdio.h>
#include <unistd.h>
#include <sanitizer/asan_interface.h>

int main ( int argc, char argv[])
{
	char poison[1024] = {0};
	printf("poison memory \n");
	ASAN_POISON_MEMORY_REGION(poison, 1024);		
	poison[1] = 1;
	sleep(20000);
}
