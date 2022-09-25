1.make 명령어
=============
 - Unux / Linux 내에 포함된 명령어. makefile이라는 파일을 참조하여 컴파일러에게 명령을 전달하며, makefile에 작성된 명령어가 순차적으로 실행되게 할 수 있다.
 - make 명령어를 통하여 여러 단계의 컴파일 과정을 한번에 수행

2.makefile
==========
 - make 명령어로 실행할 명령들을 기술해 놓은 파일
 - 목적 파일, 재료 파일, 명령어, 매크로가 기술되어 있음
 - 자동 변수
 - - $@ : 현재 타겟의 이름
 - - $* : 현재 타겟의 이름(확장자 제거)
 - - $^ : 현재 타겟의 디펜던시
 - - $? : 현재 타겟의 디펜던시 중 변경된 것들의 목록
 - - $< : 첫 번째 디펜던시 파일

makefile 예시
```c
CC = gcc // Macro

target1 : dependency1 dependency2
          command1
          command2

target2 : dependency3 dependecy4
          command3
          command4
```
```c
CC = gcc
prog : main.o foo.o
        &(CC) -o $@ main.o foo.o
      // $ make prog
      // == gcc -o prog main.o foo.o

%.o : %.c // %는 input에 따라 달라진다.
        &(CC) -c -o $@ ${CFLAG} $<
      // $ make CFLAG="-g"
      // $ make myProg.o
      // == -gcc -c -o myProg.o -g myProg.c
```
