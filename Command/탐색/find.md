find
====
* 명령어
```
1. find [경로][옵션][조건][action] : 기본 파일 찾기
 - [옵션] : -name, -user, -newer, -perm, -size
 - [action] : -print, -exec
 - 사용 예
   # find /etc -name "*.conf"
   # find /bin -size +10k -size -100k
   # find /home -name "*.swp" -exec rm {} \;
```
