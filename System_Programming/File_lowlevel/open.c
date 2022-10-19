
  /*
   * open 함수
   * #include<fcntl.h>
   * int open(const char *pathname, int oflag, ... );
   * 
   * option : O_RDONLY : 읽기 전용 / O_WRONLY : 쓰기 전용 / O_PWDR : 읽기 및 쓰기 전용
   *
   * option(select) : O_APPEND : 파일의 끝에 추가 / O_CREAT : 파일 미존재시 새로 생성 / O_EXCL : O_CREAT와 함께 지정시, 파일이 이미 존재하는 경우 오류 발생
   * O_TRUNC : 이미 존재하는 파일을 일기 / 쓰기 모드로 열었을 때, 파일 크기가 0으로 줄어든다
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
