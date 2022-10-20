```c
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int a = 0; // thread 공유 자원

void *testfunction(void){
    while(a < 20){
        printf("a value : %d\n", a);
        a++;
        sleep(1);
    }
}

int main(){
    pthread_t pthread[2];
    int status, tid;
    
    tid = pthread_create(&pthread[0], NULL, testfunction, NULL);
    tid = pthread_create(&pthread[1], NULL, testfunction, NULL);
    
    pthread_join(pthread[0], (void **) &status);
    pthread_join(pthread[1], (void **) &status);
    
    return;
}
```

mutex 미처리
============
![image](https://user-images.githubusercontent.com/70207093/196887742-52da668b-8c3b-4764-9311-7d6f164c52df.png)

```c
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int a = 0; // thread 공유 자원

void *testfunction(void){
    while(a < 20){
        printf("a value : %d\n", a);
        pthread_mutex_lock(&mutex);
        a++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main(){
    pthread_t pthread[2];
    int status, tid;
    
    tid = pthread_create(&pthread[0], NULL, testfunction, NULL);
    tid = pthread_create(&pthread[1], NULL, testfunction, NULL);
    
    pthread_join(pthread[0], (void **) &status);
    pthread_join(pthread[1], (void **) &status);
    
    return;
}
```

mutex 처리
==========
![image](https://user-images.githubusercontent.com/70207093/196888516-12d862ca-7ac4-42a9-a7ba-5c265056bbbb.png)
