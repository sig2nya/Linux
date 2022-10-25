kill
====
```c
#include<signal.h>
int kill(pid_t pid, int sig);
// return value : 0 - success / -1 - fail
// pid : 양수 - 지정한 process id에만 해당 시그널 전송 / 0 - 호출한 프로세스와 같은 그룹에 있는 모든 프로세스에게 해당 시그널 전송 / 
// -1 - 함수를 호출하는 프로세스가 전송할 수 있는 권한을 가진 모든 프로세스에 해당 시그널을 전송 / -1 외의 음수 - 첫 번째 인수 pid의 절대값 프로세스 그룹에 속하는 모든 프로세스에게 
// 시그널 전송
```
