<h3>window_border.c</h3>

```c
#include<ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[]){
  WINDOW *my_win;
  int startx, starty, width, height;
  int ch;
  
  initscr(); // start curses mode
  cbreak(); // Line buffering disabled, Pass on every thing to me
  
  keypad(stdscr, TRUE);
  
  height = 3;
  width = 10;
  starty = (LINES - height) / 2; // Calculating for a center placement of this window
  startx = (COLS - width) / 2;
  printw("Press F1 to exit\n");
  refresh();
  my_win = create_newwin(height, width, starty, startx);
  
  while((ch = getch()) != KEY_F(1)){
    switch(ch){
      case KEY_LEFT:
        destroy_win(my_win);
        my_win = create_newwin(height, width, starty, --startx);
        break;
      case KEY_RIGHT:
        destroy_win(my_win);
        my_win = create_newwin(height, width, starty, ++startx);
        break;
      case KEY_UP:
        destroy_win(my_win);
        my_win = create_newwin(height, width, --starty, startx);
        break;
      case KEY_DOWN:
        my_win = create_newwin(height, width, ++starty, startx);
        break;
    }
  }
  
  endwin(); // End curses mode
  return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx){
  WINDOW *local_win;
  local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0); // 0, 0 gives default characters for the vertical and horizontal lines
  wrefresh(local_win); // Show that box
  
  return local_win;
}

void destroy_win(WINDOW *local_win){
  wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  // box(local_win, ' ', ' '); : this won't produce the desired result of erasing the window, It will leave it's four corners and so an ugly remnant of window
  wrefresh(local_win);
  /*
      The peameters taken are
      1. win : the window on which to operate
      2. ls : character to be used for the left side of the window
      3. rs : character to be used for the right side of the window
      4. ts : character to be used for the top side of the window
      5. bs : character to be used for the bottom side of the window
      6. tl : character to be used for the top left corner of the window
      7. tr : character to be used for the top right corner of the window
      8. bl : character to be used for the bottom left corner of the window
      9. br : character to be used for the bottom right corner of the window
  */
  delwin(local_win);
}
```

<h3>결과</h3>
<img width="470" alt="image" src="https://user-images.githubusercontent.com/70207093/208827551-51b13867-7bff-4276-9f3c-17833f6f7c15.png">
