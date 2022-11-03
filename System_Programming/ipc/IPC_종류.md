* 참고 : https://jwprogramming.tistory.com/54

IPC 종류
========
1) PIPE : 반이중 통신. 즉, PIPE를 이용하면 한 번에 하나의 입력 혹은 출력만 가능. 사용이 간단하다. 익명 파이프라고도 하며, 통신을 수행할 프로세스를 명확히 아는 경우에 사용. 가령, 부모는 PIPE를 생성하고, fork를 호출하고, write로 PIPE에 작성하고, 자식은 read로 PIPE로 읽는 방법 등이 있다.
2) FIFO(Named PIPE) : Named PIPE의 경우 전혀 모르는 프로세스 사이에서 통신이 가능. 즉, 부모 프로세스와 무관하게 전혀 다른 프로세스들과 통신 가능.
3) Message Queue : Message Queue는 메모리 공간에 생성되며, PIPE에만 국한되어 저장된 메모리 공간이 아니다. 단지, 프로세스들은 Message Queue에 쉽게 접근이 가능하며 Read / Write를 간단하게 수행할 수 있다.
4) Shared Memory : PIPE, Named PIPE, Message Queue는 프로세스의 통신을 위한 선로라면, Shared Memory는 프로세스가 공유할 수 있는 공간이다. 허가되지 않은 프로세스가 해당 Shared Memory에 접근할 때, Kernel은 SIGSEGV 신호를 발생시킨다.
