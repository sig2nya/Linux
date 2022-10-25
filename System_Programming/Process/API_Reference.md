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
