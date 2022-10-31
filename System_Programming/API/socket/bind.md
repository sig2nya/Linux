bind
====
```c
#include<sys/socket.h>
int bind(int sockfd, struct socketaddr *myaddr, socklen_t addrlen);
 - sockfd : IP / PORT 할당을 위한 socket의 fd
 - myaddr : 할당하고자하는 주소 정보를 지니는 구조체 변수의 주소 값
   * struct sockaddr_in{
                        sa_family sin_family; -> AF_INET / AF_INET6 / AF_LOCAL
                        unit16_t sin_port; -> 16bit PORT 번호 저장, network byte order로 저장
                        struct in_addr sin_addr; -> 32bit IP주소정보 저장
                        char sin_zero[8]; // 미사용
     };
     
     struct in_addr{
                        int_addr_t s_addr; // 32bit IPv4 주소
     };
```
