accept
======
```c
#include<sys/socket.h>
int accept(int sock, struct sockaddr *addr, socklen_t *addrlen);
 - sock : server socket의 fd
 - addr : request를 수행한 client의 주소 정보를 담을 변수의 주소 값 전달. 
          함수 호출이 완료되면, 인자로 전달된 주소 변수에는 client의 주소 정보 저장
 - addrlen : addr에 전달된 주소의 변수 크기를 byte 단위로 전달
   * return value : 호출 성공시, 내부적으로 데이터 입출력에 사용할 socket 생성 및 해당 socket에 fd 반환
```
