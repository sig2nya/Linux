pipe
====
#include<unistd.h></br>
int pipe(int filedes[2]);
 - filedes : 두 개의 file description으로 된 배열 지정
 - pipe는 공통 조상을 가진 process에서만 사용 가능
 - pipe는 반이중 방식
 - pipe는 filedes[0]을 읽기 모드로 열고, filedes[1]을 쓰기 모드로 연다.
 - pipe의 자료 흐름은 system의 kernel을 거친다. 이는 message queue도 마찬가지이다.
 - 하나의 프로세스에서 pipe를 사용 하는 것은 의미가 없으며, 보통 부모 프로세스>    에서 pipe를 만들고, fork로 자식을 생성하여 부모 - 자식 간의 통신이 이루어진다.
 - pipe는 fork로 복사되지 않는다
```c
#include<unistd.h>
int main(){
        int n;
        int fd[2];
        pid_t pid;
        char line[MAXLINE];
        pipe(fd);
        if(pid = fork() > 0){
                close(fd[0]);
                write(fd[1], "Hello, Child\n", 13);
        } else {
                close(fd[1]);
                n = read(fd[0], line, MAXLINE);
                write(STDOUT_FILENO, line, n);
        }
        exit(0);
}
```
