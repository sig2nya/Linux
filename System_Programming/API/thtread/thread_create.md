thread_create
=============
```c
#include<pthread.h>
int pthread_create(pthread *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);
```
 - pthread_create가 호출되어 성공시, tidp가 가리키는 메모리에는 생성된 thread_id가 저장
 - attr 인수는 thread 특성을 설정하는데 사용. default : NULL
 - start_routine 함수는 인수를 하나 받는데, 이 인수는 형식 없는 포인터
 - start_routine에 여러 정보를 인수로 넘겨주고 싶다면, 그것들을 구조체로 저장하고 구조체의 주소를 인수로 지정.
 - 생성된 thread는 process 주소 공간에 접근 가능
 - 호출한 thread의 부동 소수점 환경과 신호 마스크 또한 copy를 수행
