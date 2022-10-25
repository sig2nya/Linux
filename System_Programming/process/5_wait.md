wait
====
 - 정의 : 자식 프로세스의 종료를 기다린다.

```c
#inlcude<sys/types.h>
#include<sys/wait.h>
pid_t wait(int *status);
```
 - status : 자식 프로세스가 종료될 때 상태 정보 저장
 - 정상종료 : status의 하위 8비트에는 0이 저장. 상위 8비트에는 프로세스가 종료되게 한 exit() 함수의 인수가 저장
 - 비정상 종료 : status의 하위 89비트에는 종료시킨 시그널의 번호가 저장되며 상위 8비트에는 0이 저장
