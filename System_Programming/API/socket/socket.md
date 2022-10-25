socket
======
```c
#include<sys/types.h>
#include<sys/socket.h>
int socket(int domain, int type, int protocol);
// domain : 네트워크 망 설정(인터넷 / 같은 시스템 등등) - PF_INET, AF_INET(IPv4) / PF_INET6(IPv6) / PF_LOCAL(동일 시스템 내의 통신) / PF_PACKET(Low level socket) / PF_IPX(IPX 프로토콜 사용)
// type : 데이터의 전송 형태 - SOCK_STREA(TCP/UDP) / SOCK_DGRAM(UDP/IP)
// protocol : 사용 프로토콜. 보통 0으로 지정
// return value : uint - success(socket descriptor) / -1 - fail
```

