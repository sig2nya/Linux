* 참고 : [https://blackinkgj.github.io/ncurses/](https://wiki.kldp.org/wiki.php/NCURSES-Programming-HOWTO#s-1.4.4)

Hello, World!
=============
 - 역시 프로그래밍의 시작은 "Hello, World"이다. ncurses를 사용하여, "Hello, World"를 출력해보자.

<h3>hello.c</h3>

```c

#include<ncurses.h>

int main(){
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
    
    return 0;
}
```
 - compile
   > gcc -o hello hello.c -lncurses

<h3> 결과 </h3>
<img width="425" alt="image" src="https://user-images.githubusercontent.com/70207093/208558313-990020eb-1f77-425c-b591-88e092b4b5ef.png">

분석
====
1. initscr() : 해당 함수는 curses mode로 터미널을 초기화 수행, 몇몇 구현에서는 화면을 클리어하고 빈 화면을 출력, curses 패키지를 이용하여 스크린 처리를 하려면 이 함수를 반드시 먼저 호출, curses 시스템을 초기화 및 'stdscr' 메모리 할당, initscr() 호출 후, curses setting을 위한 다양한 초기화 수행
2. printw() : printw는 "Hello World!!!"를 출력, 해당 함수는 stdscr이라 불리우는 window 내에 (y, x) 위치에 데이터를 출력한다는 점을 제외하고는 printf와 비슷한 함수
3. refresh() : printw 함수를 호출 후, data는 stdscr라 불리우는 가상 window에만 쓰여지고 화면에 아직 나타나지 않음, printw가 하는 일은 몇몇 플래그 및 데이터 구조체들을 갱신 후 stdscr에 해당하는 버퍼에 데이터를 write 수행, 그것을 화면에 출력하기 위해서는 refresh() 함수를 호출하여 curses 시스템이 buffer 내용들을 화면에 나타내도록 수행
4. endwin() : 최종적으로 curses mode를 끝내기 위해서 사용, endwin을 호출하지 않으면 terminal은 오작동 할 것이다. endwin() 함수는 curses 하위 시스템과 데이터 구조체가 점유했던 메모리를 해제 및 terminal을 원복. 따라서, endwin은 curses mode에서 작업을 마친 후 반드시 호출.

