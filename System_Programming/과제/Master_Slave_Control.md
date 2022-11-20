요구사항
========
1. 다음 형식의 PROCESS.txt 파일이 존재한다고 하자.</br>
   ![image](https://user-images.githubusercontent.com/70207093/200249806-a752d5e5-d7c3-4b4d-846c-386bc6d221aa.png)
2. Master Process는 최초기동 된다. 최초기동 시, PROCESS.txt 파일을 읽어들인다. 또한, Master Process는 해당 List를 읽어들여 Slave Process를 기동시킨다.
   - 단, Slave 기동 시, 프로세스 명을 인자로 넘겨준다. 각 Slave Process는 자신의 Process 명을 알아야 한다.
```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>

typedef struct{
        char name[50];
        char path[50];
        pid_t s_pid;
        int status;
        int live;
        int active;
} slave_info;

typedef struct{
        long msgtype;
        int ipcmsg_t;
        int pno;
} ipcMsg;

typedef enum{
        ACTIVE = 1,
        DEACTIVE,
        ACTIVE_ALL,
        DEACTIVE_ALL,
        STOP_ALL
} ipcMsgType;

int ssize = 0;
slave_info *s_info = NULL;

void get_time(void);

void get_ipcmsg(void);

void chld_handler(int signo){
        int status;
        int i = 0;
        pid_t child;

        child = waitpid(-1, &status, WNOHANG);
        WIFEXITED(status);

        for(i = 0; i < ssize; i++){
                if(s_info[i].s_pid == child) {
                        printf("Catch Signal Child Process Down (%s)\n", s_info[i].name);
                        s_info[i].status = 0;
                        s_info[i].s_pid = 0;

                        if(s_info[i].status == 0 && s_info[i].active == 1){
                                printf("Invoke Process (%s)\n", s_info[i].name);
                                if((child = fork()) > 0){
                                        s_info[i].s_pid = child;
                                if((child = fork()) > 0){
                                        s_info[i].s_pid = child;
                                        s_info[i].status = 1;
                                } else {
                                        execlp(s_info[i].path, s_info[i].name, NULL);
                                        exit(0);
                                }
                        }
                    break;
                }
        }
}

void main()
{
        FILE *fp = NULL;
        int i = 0;
        char buf[1024] = { 0, };
        char *name = NULL, *path = NULL;
        pid_t pid;
        int status;

        time_t timer;
        struct tm *t;

        memset(buf, 0, sizeof(buf));

        if((fp = fopen("./PROCESS.txt", "r")) == NULL){
                printf("fopen failed\n");
                return;
        }

        signal(SIGCHLD, chld_handler);

        s_info = (slave_info *) calloc(ssize + 1, sizeof(slave_info) * 2);

        while((fgets(buf, sizeof(buf), fp)) != NULL){ // whole file read
                s_info = (slave_info *)realloc(s_info, sizeof(slave_info) * (ssize + 1));
                name = strtok(buf, " "); path = strtok(NULL, " "); // column token 분리 
                path[strlen(path) - 1] = 0; // 개행 제거 

                if((pid = fork()) > 0){
                        s_info[i].s_pid = pid;
                        strncpy(s_info[i].name, name, sizeof(s_info[i].name));
                        strncpy(s_info[i].path, path, sizeof(s_info[i].path));
                        s_info[i].status = 1;
                        s_info[i].active = 1;
                }
                else if (pid == 0) {
                        execlp(path, name, NULL);
                        //free(s_info);
                        exit(0);
                }
                i++;
                ssize++;
        }

        fclose(fp);

                              while(1){
                get_time();

                printf("프로세스    PID     상태    활성여부\n");
                for(i = 0; i < ssize; i++){
                        printf("%5s     %5d     %5s     %5s\n",
                                s_info[i].name,
                                s_info[i].s_pid,
                                s_info[i].status == 1 ? "LIVE" : "DOWN" ,
                                s_info[i].active == 1 ? "ACTIVE" : "DEACTIVE"
                        );
                }

                get_ipcmsg();

                sleep(5);
        }

        free(s_info);
        return;
}

void get_time(){
        time_t timer;
        struct tm *t;
        char buffer[1024];
        timer = time(NULL);
        t = localtime(&timer);
        snprintf(buffer, 15,  "%.4d%.2d%.2d%.2d%.2d%.2d",
                 t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
        printf("[%s]\n", buffer);
}

void get_ipcmsg(){
        int msqid;
        int i;
        ipcMsg ipcmsg;
        ipcMsgType ipc;
        pid_t child;

        if((msqid = msgget((key_t) 123, IPC_EXCL | 0666)) == 1){
                printf("msgget failed\n");
        }

        if(msgrcv(msqid, &ipcmsg, sizeof(ipcMsg) - sizeof(long), 1, IPC_NOWAIT) != -1){
                printf("[%d] -> %d\n", ipc, ipcmsg.pno);
                switch(ipcmsg.ipcmsg_t){
                        case ACTIVE:{
                                s_info[ipcmsg.pno].active = 1;
                                for(i = 0; i < ssize; i++){
                                        if(s_info[i].status == 0 && s_info[i].active == 1){
                                                printf("Invoke Process (%s)\n", s_info[i].name);
                                                if((child = fork()) > 0){
                                                        s_info[i].s_pid = child;
                                                        s_info[i].status = 1;
                                                } else {
                                                        execlp(s_info[ipcmsg.pno].path, s_info[ipcmsg.pno].name, NULL);
                                                                                                        } else {
                                                        execlp(s_info[ipcmsg.pno].path, s_info[ipcmsg.pno].name, NULL);
                                                        exit(0);
                                                }
                                        }

                                }
                                break;
                        }
                        case DEACTIVE:{
                                s_info[ipcmsg.pno].active = 0;
                                kill(s_info[ipcmsg.pno].s_pid, SIGKILL);
                                break;
                        }
                        case ACTIVE_ALL:{
                                for(i = 0; i < ssize; i++){
                                        s_info[i].active = 1;
                                        printf("Invoke Process (%s)\n", s_info[i].name);
                                        if((child = fork()) > 0){
                                                s_info[i].s_pid = child;
                                                s_info[i].status = 1;
                                        } else {
                                                execlp(s_info[i].path, s_info[i].name, NULL);
                                                exit(0);
                                        }
                                }
                                break;
                        }
                        case DEACTIVE_ALL:{
                                for(i = 0; i < ssize; i++){
                                        kill(s_info[i].s_pid, SIGKILL);
                                        s_info[i].active = 0;
                                        s_info[i].status = 0;
                                        s_info[i].s_pid = 0;
                                }
                                break;
                        }
                        case STOP_ALL:{
                                for(i = 0; i < ssize; i++){
                                        kill(s_info[i].s_pid, SIGKILL);
                                        printf("[%d] is down\n", s_info[i].s_pid);
                                        s_info[i].s_pid = 0;
                                        s_info[i].status = 0;
                                        s_info[i].active = 0;
                                }
                                exit(0);
                                break;
                        }

                }
        }
}
```
3. trigger.c
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct{
        long msgtype;
        int ipcmsg_t;
        int pno;
} ipcMsg;

typedef enum{
        //IPC = 1,
        ACTIVE = 1,
        DEACTIVE,
        ACTIVE_ALL,
        DEACTIVE_ALL,
        STOP_ALL
} ipcMsgType;

int main(int argc, char *argv[]){
        if(argc > 3){ 
                printf("usage : ./TRIGGER <number> or ./TRIGGER <number> <processname>. processname must be same with exec file\n");
                exit(0);
        } else if(argc == 1){ 
                printf("usage : ./TRIGGER <number> or ./TRIGGER <number> <processname>. processname must be same with exec file\n");
                exit(0);
        }   

        if(atoi(argv[1]) > 5){ 
                printf("argument must be under 6\n");
                exit(0);
        }   
    
        int cmd = atoi(argv[1]);

        int key_id;
        if((key_id = msgget((key_t) 123, IPC_CREAT | 0666)) == -1){
                printf("msgget failed\n");
                return 1;
        }   
    
        ipcMsg msg;
        msg.msgtype = 1;
        msg.ipcmsg_t = cmd;

        if(argv[2] != NULL){
                printf("%d\n", msg.pno);
                msg.pno = atoi(argv[2]);
        }   


        switch(msg.ipcmsg_t){
                case ACTIVE :{
                        if(msgsnd(key_id, &msg, (sizeof(ipcMsg) - sizeof(long)), 0) == -1){
                                printf("send msg error.\n");
                                exit(0);
                        } else {
                                printf("[IPC TYPE %d] : send msg complete\n", cmd);
                                printf("argv[2] is %d\n", msg.pno);
                        }
                        break;
                }

                case DEACTIVE :{
                        if(msgsnd(key_id, &msg, (sizeof(ipcMsg) - sizeof(long)), 0) == -1){
                                printf("send msg error.\n");
                                exit(0);
                        } else {
                                printf("[IPC TYPE %d] : send msg complete\n", cmd);
                                printf("argv[2] is %d\n", msg.pno);
                        }
                        break;
                }

                case ACTIVE_ALL :{
                        if(msgsnd(key_id, &msg, (sizeof(ipcMsg) - sizeof(long)), 0) == -1){
                                printf("send msg error.\n");
                                exit(0);
                        } else {
                                printf("[IPC TYPE %d] : send msg complete\n", cmd);
                                printf("argv[2] is %d\n", msg.pno);
                        }
                        break;
                }

                case DEACTIVE_ALL :{
                        if(msgsnd(key_id, &msg, (sizeof(ipcMsg) - sizeof(long)), 0) == -1){
                                printf("send msg error.\n");
                                exit(0);
                        } else {
                                printf("[IPC TYPE %d] : send msg complete\n", cmd);
                                printf("argv[2] is %d\n", msg.pno);
                        }
                        break;
                }

                case STOP_ALL :{
                        if(msgsnd(key_id, &msg, (sizeof(ipcMsg) - sizeof(long)), 0) == -1){
                                printf("send msg error.\n");
                                exit(0);
                        } else {
                                printf("[IPC TYPE %d] : send msg complete\n", msg.ipcmsg_t);
                        }
                        break;
                }

                default :{
                        printf("invalid parameter\n");
                        exit(0);
                }

        }

        return 0;
}
```

4. slave.c
```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>

char buffer[1024];

void get_time(){
        time_t timer;
        struct tm *t; 
        timer = time(NULL);
        t = localtime(&timer);
        snprintf(buffer, 15, "%.4d%.2d%.2d%.2d%.2d%.2d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
}

void append_file(char *name, int cnt){
        FILE *fp = NULL;
        char file_name[1024] = {0,};

        sprintf(file_name, "%s.txt", name);

        if((fp = fopen(file_name, "a+")) == NULL){
                fprintf(fp, "file open error\n");
                return;
        }   
        get_time();
        fprintf(fp, "%s %s %d\n", buffer, name, cnt);
        fflush(fp);
        fclose(fp);
}

void main(int argc, char *argv[])
{
        int i = 0;
        FILE *fp;
        time_t timer;
        struct tm *t; 
        char p_name[124] = {0,};
        char f_name[127] = {0,};
        timer = time(NULL);
        t = localtime(&timer);

        if (argc != 1) {
                strcpy(p_name, "SLAVE");
        }   
        else {
                strcpy(p_name, argv[0]);
        }   

        sprintf(f_name, "%s.txt", p_name);

        if((fp = fopen(f_name, "a+")) == NULL){
                fprintf(fp, "file open error\n");
                return;
        }   
                        return;
        }

        snprintf(buffer, 30, "==============================");
        fprintf(fp, "%s\n", buffer);
        fflush(fp);
        snprintf(buffer, 40, "%.4d%.2d%.2d%.2d%.2d%.2d [%s] is alive!!!", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, p_name);
        fprintf(fp, "%s\n", buffer);
        fflush(fp);

        while(i < 6){
                append_file(p_name, i + 1);
                i++;
                sleep(5);
        }

        snprintf(buffer, 30, "%s is terminate", p_name);
        fprintf(fp, "%s\n", buffer);
        snprintf(buffer, 30, "==============================");
        fprintf(fp, "%s\n", buffer);
        fflush(fp);
        fclose(fp);
        exit(0);
}
```
