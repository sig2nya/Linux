* 참고 : https://www.ibm.com/docs/ko/aix/7.3?topic=files-fcntlh-file / https://badayak.com/m/4398

open
====
1. open의 경우 LINUX에서 제공하는 API이다. C의 표준 라이브러리에서는 fopen을 통해서 file open을 수행한다. 해당 함수는 fcntl.h에 존재한다.
2. 형태 : int open(const char *filename, int flags[, mode_t mode])
3. 인수 
    - char *filename : 대상 파일 이름
    - int flags : 대상 파일에 대한 열기 옵션
    - [, mode_t MODE] : O_CREAT 옵션 사용에 의해 파일이 생성될 때 지정되는 파일 접근 권한
4. OPEN Option
    - O_RDONLY : 읽기 전용
    - O_WRONLY : 쓰기 전용
    - O_RDWR : 읽기 / 쓰기 전용
5. Option(select)
   ![image](https://user-images.githubusercontent.com/70207093/196572945-3bffd37a-659b-4115-ab5d-9434a943d1e6.png)

```c
 /*
   * open 함수
   * #include<fcntl.h>
   * int open(const char *pathname, int oflag, ... );
   * 
   * option : O_RDONLY : 읽기 전용 / O_WRONLY : 쓰기 전용 / O_PWDR : 읽기 및 쓰기 전용
   *
   * option(select) : O_APPEND : 파일의 끝에 추가 / O_CREAT : 파일 미존재시 새로 생성 / O_EXCL : O_CREAT와 함께 지정시, 파일이 이미 존재하는 경우 오류 발생
   * O_TRUNC : 이미 존재하는 파일을 읽기 / 쓰기 모드로 열었을 때, 파일 크기가 0으로 줄어든다
   * O_NOCTTY : pathname이 터미널 장치를 가리키는 경우, 해당 장치를 이 프로세스의 제어 터미널로 배정하지 않도록 수행
   * O_NONBLOCK : pathname이 FIFO나 블록 특수 파일, 문자 특수 파일을 지칭하는 경우, 그 파일의 열기 및 이후의 I/O 작업들에 대해 비차단 모드를 설정
   * O_DSYNC : 각 write 연산이 물리적 I/O 연산의 완료를 기다리게 화며, 방금 기록한 자료를 읽을 수 있는 능력에 미치지 않는 파일 특성 갱신은 기다리지 않도록 수행
   * O_RSYNC : 파일 서술자에 대한 각 read 연산이 파일의 동일 부분에 대해 유보된 기록의 완료를 기다리게 한다
   * O_SYNC : 각 write 연산이 물리적 I/O의 완료를 기다리게한다.
   * 
  */
  
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  #include<unistd.h>
  #include<sys/types.h>
  #include<sys/stat.h>
  #include<fcntl.h>
  
  static int append_file(void){
          int fd = open("datafile", O_WRONLY | O_APPEND);
          dprintf(fd, "Hello, Again..!\n");
          close(fd);
          return 0;
  }
  
  static int trunc_file(void){
          int fd = open("datafile", O_WRONLY | O_CREAT | O_TRUNC, 0600);
          dprintf(fd, "Byebye file\n");
          close(fd);
          return 0;
  }
  
  static int write_file(void){
          int fd = open("datafile", O_WRONLY | O_CREAT, 0600);
          dprintf(fd, "Hello, World!\n", 123);
          close(fd);
          return 0;
  }
  
  int main(){
          write_file();
          trunc_file();
          append_file();
          return 0;
  }
```
