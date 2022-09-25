1. Thread
 - 쓰레드의 생성 및 종료
```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

void pthread_exit(void *retval)

 - arguments : thread -> 생성된 thread ID / 
   attr -> thread 속성(pthread_attr_init()으로 초기화) / 
   start_routine -> thread main function / 
   arg -> thread main function 호출시 사용할 파라미터
```

 - 쓰레드 조인
```c
int pthread_join(pthread_t thread void **retval);

 - arguments : thread -> 기다릴 thread ID /
   retval -> 해당 thread의 exit status 지정
```

 - 쓰레드 떼어내기
```c
int pthread_detach(pthread_t thread); // 해당 쓰레드는 종료시 자동으로 리소스 해제(join 불필요)

 - arguments : thread -> 떼어낼 thread ID
```

 - 쓰레드 동기화
```c
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

 - arguments : mutex -> mutex instance /
   attr -> mutex 속성

int pthread_mutex_destroy(pthread_mutex_t *mutex);

 - arguments : mutex -> mutex instance
 
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

 - arguments : mutex -> mutex instance
```

