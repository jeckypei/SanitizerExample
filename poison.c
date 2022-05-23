#include <stdio.h>
#include <unistd.h>
#include <sanitizer/asan_interface.h>

int main ( int argc, char argv[])
{
	char poison[1024] = {0};
#if __has_feature(address_sanitizer) || defined(__SANITIZE_ADDRESS__)
	printf("sanitizer enabled\n");
#else
	printf("sanitizer disabled\n");
	printf("poison memory ...\n");
#endif
	ASAN_POISON_MEMORY_REGION(poison, 1024); /*if SAN is not enabled, no operation*/
	poison[1] = 1;
	sleep(20000);
}
