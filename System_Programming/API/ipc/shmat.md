shmat
=====
```c
#include<sys/ipc.h>
#include<sys/shm.h>
void *shmat(int shmid, const void *shmaddr, int shmflg);
// shmid : shared memory의 id, shmget을 통해 얻어온다.
// shmaddr : NULL - Kernel에서 적절한 주소를 반환 / NULL이 아닐 경우 - shmflg로 SHM_RND일때 그 주소와 attch할 가장 가까운 주소 반환
// return value : 포인터 주소 - 성공시 / (void *) -1 - 실패시
```
