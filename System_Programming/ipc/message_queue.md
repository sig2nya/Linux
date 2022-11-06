Message Queue
=============
```c
#include<sys/types.h>
#include<sys/ipc.h>
#include<ys/msg.h>
int msgget(key_t key, int msgflg);
 - key : msg queue 번호
 - msgflg : IPC_CREAT - key에 해당하는 msg queue가 없으면 생성 / IPC_EXCL - msg queue가 이미 존재하면 실패

int msgsnd(int msgqid, struct msgbuf *msgp, size_t msgsz, int msgflg);
 - msgqid : msg queue 식별자
 - msgp : 전송할 메시지
 - msgsz : 메시지 크기
 - msgflg : 동작 옵션 / IPC_NOWAIT - msg queue가 가득 차면 동작 실패 

ssize_t msgrcv(int msqid, struct msgbuf *msgp, size_t msgsz, long msgtype, int msgflg);
 - msgqid : msg queue 식별자
 - msgp : 메시지 수신 버퍼
 - msgsz : 수신할 메시지 크기
 - msgflg : 동작 옵션 / IPC_NOWAIT - msg queue에 메시지 없으면 실패 / MSG_NOERROR - msg queue가 msgsz 보다 클 때, 초과 부분 버림

int msgctl(int msqid, int cmd, struct msqid_ds *buf);
 - msqid : msg queue 식별자
 - cmd : 제어 종류 / IPC_STAT - msg queue 정보를 얻어 buffer에 저장 / IPC_SET - msg queue 정보를 buf에 저장한 값으로 변경 / IPC_RMID - msg queue 제거 
 - buf : msg queue 정보 포인터
```
