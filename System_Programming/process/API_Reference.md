pthread_create
==============
 1. int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
    - thread 생성을 위해 사용
    - thread : thread가 성공적으로 생성되었을 때, 생성된 thread를 식별하기 위한 식별자
    - attr : thread 특성을 위해 지정하며, 기본 thread 특성 사용을 위해서는 NULL을 지정하면 된다.
    - start_routine : 분기시켜 실행시킬 thread
    - arg : thread 함수의 인자
```c
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void *t_function(void *data){
    int id, i = 0;
    id = *((int *)data);
    
    while(i > 20){
        printf("%d : %d\n", id, i);
        i++;
        sleep(1);
    }
}

int main(){
    pthread_t pthread[2];
    int tid, status, a = 1, b = 2;
    
    tid = pthread_create(&pthread[0], NULL, t_function, (void *) &a);
    if(tid < 0){
        printf("thread error\n");
        exit(0);
    }
    
    tid = pthread_create(&pthread[1], NULL, t_function, (void *) &b);
    if(tid < 0){
         printf("thread error\n");
         exit(0);
     }
     
     pthread_join(pthread[0], (void **) &status);
     pthread_join(pthread[1], (void **) &status);
     return 0;
}
```

exec 함수
=========
1. exec류 함수
 - 기능 : 현재 프로세스를 대신하여 새로운 프로세스를 실행하는 함수
 - 함수 접미사 : l - list 형태로 이자 입력. 인자의 끝을 0으로 표시 / v - vector 형태로 인자 입력 / e - 맨 마지막 인자로 환경 변수 입력 / p - 프로세스를 현재 디렉토리(pwd)에서 찾는다.
 - exec() 함수는 입력받은 경로가 '/'로 시작하지 않으면 환경 변수에서 파일을 찾는다.

```c
#include<unistd.h>
int execl(const char *filepath, const char *arg0, ...);
int execv(const char *filepath, char *const argv[]);
int execle(const char *filepath, const char *arg0, ...);
int execve(const char *filepath, char *const argv[], char *const envpp[]);
int execlp(const char *filepath, const char *arg0, ...);
int execvp(const char *filepath, char *const argv[]);
```
 - filepath : 실행할 프로세스의 경로를 담은 문자열, p가 붙은 exec() 함수는 현재 작업 디렉토리 내에서 해당 프로세스를 찾는다.
 - arg0 : 실행할 프로세스에 넘길 첫번째 인자로, 프로세스의 이름을 담는 매개변수
 - ... : 실행할 프로세스에 넘길 이름을 제외한 매개변수로 그 끝을 0으로 표시
 - argv : 실행할 프로세스에 넘길 인자 배열
 - return value : 성공시 리턴하지 않으며, error시 -1을 return하고 errno를 설정
