fputs
=====
 * fputs : file put string, 파일에 String 작성
 * API : int fputs(const char *str, FILE *fp);
 * return value : value >= 0
 * ex)
 ```c
FILE *fp = fopen("test.txt", "w");
fputs("blockdamsk", fp);
fclose(fp);
```
