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
