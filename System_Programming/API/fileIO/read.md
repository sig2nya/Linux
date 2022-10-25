read
====
```c
#include<unistd.h>
ssize_t read(int fd, void *buf, size_t nbytes);

// return value : 읽은 바이트 수 - 성공시 / 0 - 파일 끝인 경우 / -1 - 실패시
// 파일 끝까지 30바이트가 남은 상황에서 100바이트를 읽으려 한다면 read는 30 return
```
