snprintf
========
```c
#include<stdio.h>
int snprintf(char *buffer, int buf_size, const char *format, ...);
// buffer 변수에 형식에 따라 만들어진 문자열 저장
// int형의 정수를 쉽게 char * 형식으로 전환

int main(){
    int a = 10, b = 20;
    char *buffer;
    sprintf(buffer, "%d%d", a, b);
    printf("%s\n", buffer);
    return 0;
}
```
