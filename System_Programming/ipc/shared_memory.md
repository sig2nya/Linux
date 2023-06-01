Shared Memory
=============
> IPC Message에서 빠른 속도를 자랑한다.
* 먼저, Shared Memory를 생성하고, 해당 메모리에 데이터를 작성해보자.
```c:title=shm_write.c
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024

int main(){
        int   shmid;
        key_t key;
        char  *data;
        void  *shm;

        key = ftok(".", 0); // ftok 함수의 첫번째 인자와 두번째 인자값을 통해 shm의 key 값을 가져온다.
        if(key == -1){
                perror("ftok error");
                exit(1);
        }

        shmid = shmget(key, SHM_SIZE, IPC_EXCL | 0666);
        if (shmid == -1) {
                perror("shmget error");
                exit(1);
        }

        // 공유 메모리를 현재 프로세스에 연결
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *)-1) {
                perror("shmat error");
                exit(1);
        }

        printf("공유 메모리에 데이터를 입력하세요: ");
        fgets(shm, SHM_SIZE, stdin);  // 표준 입력으로 데이터를 입력 받아 공유 메모리에 저장

        // 공유 메모리 연결 해제
        if (shmdt(shm) == -1) {
                perror("shmdt error");
                exit(1);
        }
        return 0;
}
```
<img width="329" alt="image" src="https://github.com/sig2nya/Linux/assets/70207093/f5c2c0e1-b266-4dd8-b92b-43a73199218b">

```c:title=shm_read.c
#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>

#define SHM_SIZE 1024

int main(){
        key_t key = ftok(".", 0);
        int shmid = shmget(key, SHM_SIZE, 0666 | IPC_EXCL);

        if(shmid == -1){
                perror("shmget error");
                exit(1);
        }

        void *shm = shmat(shmid, NULL, 0);

        if(shm == (void *)-1){
                perror("shmat error");
                exit(1);
        }

        void *data = shm;
        printf("Data read from shared memory : %s\n", (char *) data);
        shmdt(shm);
        return 0;
}
```
<img width="333" alt="image" src="https://github.com/sig2nya/Linux/assets/70207093/1f5d75cd-1d26-4a5d-855d-bd2d26433497">
