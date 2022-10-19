#include<stdio.h>
#include<stdli.h>

int main(void){
    FILE *fp;
    if((fp = fopen("mylib/myfile", "r")) == NULL){
        perror("Cound'nt open data file");
        abort();
    }
}
