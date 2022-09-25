1.Signal
========
 - 비동기 이벤트를 처리하기 위한 메커니즘
 - SW Interrupt
 - ex) Ctrl + C / Child Process Termination / Alarm / Devied by 0 / Inter-Process Communication
 - Signal Number + 추가적인 정보 + 사용자 정의 데이터 등을 담음

2.Signal의 처리
===============
 1) 무시 : 아무런 동작도 미수행 / SIGKILL, SIGSTOP은 무시 불가능
 2) 처리 : Signal 별 처리함수를 수행
 3) 기본 동작 : 시그널 종류 별 기본 동작 수행 -> 프로세스 종료 / 코어덤프 생성 후 종료 / 무시 / 정지

3.주요 Signal 번호
==================
 - SIGHUP : 종료 / 프로세스의 제어 터미널이 닫히며 설정 리로드
 - SIGINI : 종료 / 사용자가 Ctrl + C 발생
 - SIGKILL : 종료 / 붙잡을 수 없는 프로세스 종료
 - SIGSEGV : 코어 덤프 / 메모리 접근 위반
 - SIGALARM : 종료 / 알람 발생
 - SIGTERM : 종료 / 붙잡을 수 있는 프로세스 종료
 - SIGUSR1/2 : 종료 / 사용자 정의 시그널
 - SIGCHLD : 종료 / 자식 프로세스 종료
 - SIGCOUNT : 진행 / 프로세스를 정지하였다가 계속 수행
 - SIGSTOP : 정지 / 프로세스 실행 보류

4.Signal 실행 및 상속
=====================
 - fork() : 자식 프로세스는 부모 프로세스의 시그널 동작 상속
 - exec() : 부모 프로세스가 붙잡아 처리하는 시그널은 기본 동작으로 변경
   ![image](https://user-images.githubusercontent.com/70207093/192130393-a22c31d9-24d8-4710-b6b7-faa9926637ca.png)

5.Signal 처리 설정
==================
```c
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

arguments : signum -> 처리 대상 시그널 번호 / handler -> 시그널 핸들러(SIG_IGN : 해당 시그널 무시 / SIG_DFL : 해당 시그널을 기본 동작 처리)
```
