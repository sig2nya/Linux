#include<stdio.h>

#define log(fmt, ...)\
  printf("[%s : %d] [%s]" fmt "\t\t\t (%s, %s)\n", \
           __FILE__, __LINE__, __func__, __DATE__, __TIME__);
 int main(){
           log("Hello, World");
}
