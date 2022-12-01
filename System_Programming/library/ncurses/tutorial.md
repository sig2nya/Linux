* 참고 : https://blackinkgj.github.io/ncurses/

Tutorial
========
 - 역시 프로그래밍의 시작은 "Hello, World"이다. ncurses를 사용하여, "Hello, World"를 3초간 출력한 뒤에 종료하는 프로그램을 작성해보자.

<h3>ncurses.c</h3>

```c
#include<ncurses.h>
#include<stdio.h>

int func1(){
  initscr();
  mvprintw(0, 0, "Hello, World");
  refresh();
  sleep(3);
  endwin();
  return 0;
}

int main(){
  return func1();
}
```

 - compile
   > gcc -o ncurses ncurses.c -lncurses

<h3>결과<h3>
<img width="452" alt="image" src="https://user-images.githubusercontent.com/70207093/204939829-1eb0bd13-87ff-446a-aafa-c0ddeb809960.png">
