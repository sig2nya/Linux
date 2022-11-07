fseek
=====
```c
#include<stdio.h>
int fseek(FILE *stream, long offset, int whence);
 - stream : 대상 파일 stream
 - offset : 이동할 바이트 수
 - whence : 시작 시점 / SEEK_SET - 파일의 시작 / SEEK_CUR - 현재 읽기 / 쓰기 포인터 위치
 - SEEK_END : 파일의 끝
```
