msgctl
======
```c
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int msgctl(int msqid, int cmd, struct msqid_ds *buf);
 - msqid : message queue 식별자
 - cmd : 제어 명령 / IPC_STAT - message queue의 현재 상태 / IPC_SET - message queue의 상태를 현재 buf 값으로 변경 / IPC_RMID - message queue를 삭제
 - buf : message queue 정보를 받아올 버퍼
```
