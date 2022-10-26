shmget
======
```c
#include<sys/ipc.h>
#include<sys/shm.h>

int shmget(key_t key, size_t size, int shmflg);
// key : 공유 메모리 할당을 위한 고유 key 값
// size : memory의 최소 size, 만약 이미 존재하는 메모리면 0값을 주면 된다.
// shmflg : IPC_CREAT - 새로운 메모리 세그먼트 생성 / IPC_EXCL - IPC_CREAT와 함게 쓰이는 FLAG이며 만약 세그먼트가 존재하면 memory 생성 fail
```
