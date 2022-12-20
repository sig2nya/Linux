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
