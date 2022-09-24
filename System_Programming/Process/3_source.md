```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void test_func(void)
{
	printf("this is a test function(pid %d)\n", getpid());
}

int main(int argc, char **argv)
{
	pid_t pid;
		
	printf("origin process pid: %d\n", getpid());

	pid = fork(); // fork 함수가 호출된 시점부터 '자식 프로세스'의 생성
	if (pid == 0) {
		/* child process */
		printf("child process pid: %d\n", getpid());
	} else if(pid > 0) {
		/* parent process */
		printf("parent process pid: %d, child pid %d\n", 
				getpid(), pid);
	}
	test_func();

	return 0;
}
```
