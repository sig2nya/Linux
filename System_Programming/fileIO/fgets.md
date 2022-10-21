fgets
=====
 * fgets : file get string, 파일에 String 얻어오기
 * API : char *fgets(char *str, int num, FILE *fp);
 * return value : value >= 0
 * ex)
 ```c
FILE *fp = fopen("test.txt", "r");
char str[100];
fgets(str, 100, fp);
fclose(fp);
```
