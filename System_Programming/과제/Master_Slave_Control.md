요구사항
========
1. 다음 형식의 PROCESS.txt 파일이 존재한다고 하자.</br>
   ![image](https://user-images.githubusercontent.com/70207093/200249806-a752d5e5-d7c3-4b4d-846c-386bc6d221aa.png)
2. Master Process는 최초기동 된다. 최초기동 시, PROCESS.txt 파일을 읽어들인다. 또한, Master Process는 해당 List를 읽어들여 Slave Process를 기동시킨다.
   - 단, Slave 기동 시, 프로세스 명을 인자로 넘겨준다. 각 Slave Process는 자신의 Process 명을 알아야 한다.
```c
void read_process(){
        char buf[30];
        char *slaves[2];
        FILE *fp = fopen("./PROCESS.txt", "r");
        if(fp == NULL){
                printf("PROCESS.txt file read error\n");
                return;
        }   
        int i;
        for(i = 0; i < 2; i++){
                // read line in file
                char *str = fgets(buf, MAX_LIST_LEN, fp);
                // line parsing
                char *result = strtok(str, " ");
                slaves[0] = result;
                result = strtok(NULL, " ");
                slaves[1] = result;
                printf("[%d] parsing result : %s %s", i, slaves[0], slaves[1]);
                fseek(fp, ftell(fp), SEEK_SET);
        }   
        close(fp);
        return;
}

```
