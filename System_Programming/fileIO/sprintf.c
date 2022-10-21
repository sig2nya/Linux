#include<stdio.h>

char buffer[200];
int i, j;
double fp;
char *s = "baltimore";
char c;

int main(void){
    c = 'l';
    i = 35;
    fp = 1.7320508;
    
    j = sprintf(buffer, "%s\n", s);
    j += sprintf(buffer + j, "%s\n", s);
    j += sprintf(buffer + j, "%d\n", i);
    j += sprintf(buffer + j, "%f\n", fp);
    printf("string : \n %s\ncharater count = %d\n", buffer, j);
    return 0;
}
