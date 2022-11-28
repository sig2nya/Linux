 * 참고 : https://minwook-shin.github.io/basic-ncurses/

ncurses.h
=========
1. 개요 : terminal graphic library, 프로그래머가 TUI를 terminal independent한 방식으로 기록할 수 있도록 API 제공
2. 장점 : cursor 이동, keyboard 및 mouse로 control 가능하며, user freindly하게 Window Size나 Color 제어 가능
3. 주요 API
 - initscr() : ncurses TUI 모드를 사용하기 시작했다고 noti. 가장 먼저 호출되며, 기본 size의 window 생성
 - start_color() : ncurses에 color attribute를 사용한다고 선언. color 사용을 위해 반드시 가장 먼저 선언
 - init_pair() : pair의 글자 색과 배경 색 attribute를 지정
 - attron() : 적용할 attribute를 설정
 - printw() : const char 형식의 문자열을 출력하며, 눈에 보이지는 않는다.
 - refresh() : 이 함수가 호출되기 전까지 수행한 작업들을 screen에 update하며, printw()와 같은 함수들은 이 함수로 인하여 실제로 출력
 - getch() : 문자를 입력하였는지 check. 보통, 실행파일이 바로 종료되지 않도록 하기 위하여 사용
 - endwin() : ncurses TUI 모드를 사용 종료

```C
#include<ncurses.h>
int main(){
  initscr();
  start_color();
  init_pair(1, COLOR_RED, COLOR_WHITE);
  attron(COLOR_PAIR(1));
  printw("Hello, World!");
  attroff(COLOR_PAIR(1));
  refresh();
  getch();
  endwin();
  return 0;
}
```
