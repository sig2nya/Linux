open
====
```c
#include<fcntl.h>
int open(const char *FILENAME, int FLAGS[, mode_t MODE]);
// char *FILENAME : 대상 파일 이름 (ex) "./text.txt"
// int FLAGS : 파일에 대한 열기 옵션
// options : O_RDONLY, O_WRONLY, O_PDWR, O_CREAT(접근 권한을 추가해야함), O_EXCL(O_CREAT를 사용했을 때, 파일이 이미 있어도 열기가 가능하며 쓰기를 하면 이전 내용 삭제)
// O_NOCITTY, O_NONBLOCK, O_SYNC
// return value : unsigned integer - 성공시 / -1 - 실패시
```

write
=====
```c
#include<unistd.h>
ssize_t write(int fd, const void *buf, size_t n);
// argument가 직관적이라 생략

char *tmp = "쓰고 싶은 내용\n";
int fd = open("./text.txt", O_WRONLY | O_CREAT | O_EXCL, 0644));
write(fd, tmp, strlen(tmp));
close(fd);
```
