snprintf
========
```c
#include<stdio.h>
int snprintf(char *str, size_t size, const char *format, ...);

char buffer[200];
int i, j = 0;
double fp;
char *s = "baltimore";
char c;

int main(void){
        c = 'l';
        i = 35;
        fp = 1.7320408;

        snprintf(buffer, 4, "%s", s);
        printf("%s\n", buffer);
        snprintf(buffer, 10, "%s", s);
        printf("%s\n", buffer);
        return 0;
}
```
