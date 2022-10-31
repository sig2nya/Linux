listen
======
```c
#include<sys/socket.h>
int listen(int sock, int backlog);
 - sock : 연결 요청 대기상태에 두고자 하는 socket의 fd 전달. 이 함수의 인자로 전달된 fd의 socket이 listening socket
 - backlog : 연결 요청 대기 queue의 크기 정보 전달. 5가 전달되면 queue의 크기가 5가 되어, 최대 client를 5개까지 대기
```
