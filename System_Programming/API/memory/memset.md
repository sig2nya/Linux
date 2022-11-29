memset
======
 - 선언된 memory를 초기화 하기 위해 사용
 - void *memset(void *ptr, int value, size_t num);

```c
#include<stdio.h>
#include<string.h>

int main(){
    int arr[5];
    int i;
    for(i = 0; i < 5; i++){
        printf("[%d] ", *(arr + i));
    }
    printf("\n");
    
    memset(arr, 0x00, sizeof(int) * 5);
    
    for(i = 0; i < 5; i++){
        pirntf("[%d] ", *(arr + i));
    }
    printf("\n");
    
    memset(arr, 1, sizeof(int) * 5); // memset은 value를 unsigned char로 저장한다. memset에 value는 반드시 0(0x00) 혹은 NULL로 초기화 하자
    for(i = 0; i < 5; i++){
        printf("[%d] ", *(arr + i));
    }
    printf("\n");
    return 0;
}
```
