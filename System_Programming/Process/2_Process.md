1. pid_t fork(void)
 - 프로세스의 생성 및 복제 수행 API
 - fork를 호출하는 프로세스는 부모 프로세스이며 새롭게 생성되는 프로세스는 자식
```c
#include <unistd.h>

pid_t fork(void); 
// 성공 - 부모 process는 자식 process의 pid(process id)를 리턴받으며, 자식 process는 0을 리턴
// 실패 - 그 외의 값 반환
// 파라미터 - 없음

pid_t getpid(void); // 현재 프로세스의 pid(process id)
pid_t getppid(void); // 현재 프로세스의 부모 프로세스 pid(process id)
```

2. exec APIs
 - 새로운 프로세스 호출(실행) - exec계 함수
```c
int execl(const char *path, const char *arg, ... /* (char *) NULL */);
int execlp(const char *file, const char *arg, ... /* (char *) NULL */);
int execle(const char *path, const char *arg, ... /* (char *) NULL, char *const envp[] */);

int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execve(const char *path, char *const argv[], char *const envp[]);
int execvpe(const char *file, char *const argv[], char *const envp[]);

execl : list based arguments
execv : vector(char pointer array) based arguments
suffix 'p' : $PATH 에서 경로를 찾음
suffix 'e' : 새로운 환경 변수 설정
실패시에만 return -1
```

3. void exit(int status);
 - 프로세스 종료
 - argument : status -> exit status

4. SIGCHLD
 - 부모 프로세스는 좀비 프로세스의 발생을 위해 신호 수신 대기
 - 즉, 부모 프로세스는 SIGCHLD에 대해 수신 대기
 - SIGCHLD를 수신하면 자식 프로세스 상태 확인 -> 종료된 자식 프로세스 처리
 - '자식 프로세스'가 종료 되었을 때, '부모 프로세스'에게 'SIGCHLD' signal 전송

5. pid_t wait(int *wstatus);
 - arguments : wstatus -> child process의 종료 상태
```c
WIFEXITED(wstatus)
WEXITSTATUS(wstatus)

WIFSIGNALED(wstatus)
WTERMSIG(wstatus)

WCOREDUMP(wstatus)

WIFSTOPPED(wstatus)
WSTOPSIG(wstatus)
WIFCONTINUED(wstatus)
```

6. pid_t waitpid(pid_t pid, int *status, int optiones) / pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage)
 - 자식 프로세스 종료 대기
 - arguments : pid -> 종료 대기할 프로세스의 pid / status -> 자식 프로세스의 종료 코드 / opteions -> WNOHANG, WUNTRACED, WCONTINUED / rusage -> resource 사용량

```c
struct rusage {
    struct timeval ru_utime; /* user CPU time used */
    struct timeval ru_stime; /* system CPU time used */
    long ru_maxrss; /* maximum resident set size */
    long ru_ixrss; /* integral shared memory size */
    long ru_idrss; /* integral unshared data size */
    long ru_isrss; /* integral unshared stack size */
    long ru_minflt; /* page reclaims (soft page faults) */
    long ru_majflt; /* page faults (hard page faults) */
    long ru_nswap; /* swaps */
    long ru_inblock; /* block input operations */
    long ru_oublock; /* block output operations */
    long ru_msgsnd; /* IPC messages sent */
    long ru_msgrcv; /* IPC messages received */
    long ru_nsignals; /* signals received */
    long ru_nvcsw; /* voluntary context switches */
    long ru_nivcsw; /* involuntary context switches */
};
```
