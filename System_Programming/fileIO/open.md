* 참고 : https://www.ibm.com/docs/ko/aix/7.3?topic=files-fcntlh-file / https://badayak.com/m/4398

open
====
1. open의 경우 LINUX에서 제공하는 API이다. C의 표준 라이브러리에서는 fopen을 통해서 file open을 수행한다. 해당 함수는 fcntl.h에 존재한다.
2. 형태 : int open(const char *filename, int flags[, mode_t mode])
3. 인수 
    - char *filename : 대상 파일 이름
    - int flags : 대상 파일에 대한 열기 옵션
    - [, mode_t MODE] : O_CREAT 옵션 사용에 의해 파일이 생성될 때 지정되는 파일 접근 권한
4. OPEN Option
    - O_RDONLY : 읽기 전용
    - O_WRONLY : 쓰기 전용
    - O_RDWR : 읽기 / 쓰기 전용
5. Option(select)
   ![image](https://user-images.githubusercontent.com/70207093/196572945-3bffd37a-659b-4115-ab5d-9434a943d1e6.png)
