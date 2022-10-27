1.thread
========
 * 개념 : LINUX 프로세스는 단 하나의 제어 줄기를 가진다. 그러나, 하나의 프로세스에 여러 제어줄기를 둔다면 프로세스가 동시에 여러 일을 하도록 프로그램을 설계할 수 있다.
 * 장점 : 비동기적 사건들을 처리하는 코드의 단순화 / 다중 프로세스 접근 방식에서는 프로세스들이 메모리 혹은 fd를 공유하려면 운영체제가 제공하는 복잡한 매커니즘을 사용해야 하지만, 한 프로세스의 스레드들은 특별한 처리 없이 동일 메모리 주소 공간과 fd에 접근 가능 / 프로그램이 해결해야할 문제들을 작은 문제로 분할하여 산출량을 높힐 수 있다. 독립적인 과제들을 개별 스레드에 배정하며, 동시 진행이 가능
   ![image](https://user-images.githubusercontent.com/70207093/197119993-9516fa3f-8b9a-4156-a8be-14954fab8ace.png)

2.thread 식별
=============
```c
#include<pthread.h>
int pthread_equal(pthread_t tid1, pthread_t tid2);
// return value : 같으면 0이 아닌 정수, 다르면 0

pthread_t pthread_self(void);
// return value : pthread_self를 호출한 thread의 thread id

int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);
```

3.thread 생성
=============
 * 특성 : thread 생성시, 새 thread와 그것을 생성한 thread 중 어느 것이 먼저 실행되는지 알 수 없다. 새로 생성된 thread는 process 주소 공간에 접근 가능하다.</br>
   ![image](https://user-images.githubusercontent.com/70207093/198217481-1b0311f2-5803-4952-a756-a47710933b59.png)

```c
#include "apue.h"
#include<pthread.h>


pthread_t ntid;

void printids(const char *s){
        pid_t pid;
        pthread_t tid;

        pid = getpid();
        tid = pthread_self();
        printf("%s pid %u tid %u(0x%x)\n", s, pid, tid, tid);
}

void *thr_fn(void *arg){
        printids("new thread : ");
        return((void *)0);
}

int main(void){
        int err;
        err = pthread_create(&ntid, NULL, thr_fn, NULL);
        if(err != 0) printf("can't create thread : %s\n", strerror(err));
        printids("main thread : ");
        sleep(1);
        exit(0);
}
```

4.thread 종료
=============
 - 프로세스 종료를 야기시키지 않고 thread가 종료되는 경우는 다음의 경우이다
 - - thread 시동 routine이 정상적으로 반환.
 - - 같은 프로세스의 다른 thread의 취소 요청에 의해 thread가 취소
 - - thread가 pthread_exit 호출

```c
#include<pthread.h>
void pthread_exit(void *rval_ptr);
int pthread_join(pthread_t thread, void **rval_ptr);
```
```c

```
