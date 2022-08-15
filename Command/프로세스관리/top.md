* 참조 : https://zzsza.github.io/development/2018/07/18/linux-top/

top
===
* 개요 : Linux에서 현재 리소스에 대한 사용률을 보여주는 명령어
* 사용법 및 옵션
* 1) 옵션 없이 사용하면, 3초 주기로 Refresh
* 2) shift + p : CPU 사용률 내림차순
* 3) shift + m : 메모리 사용률 내림차순
* 4) shift + t : 프로세스가 돌아가고 있는 시간 순
* 5) k : kill / k 입력 후 PID 번호 작성
* 6) f : sort field 선택 화면 -> q 누르면 RES 순으로 정렬
* 7) a : 메모리 사용량에 따라 정렬
* 8) b : batch 모드로 작동
* * \> top 명령어 수행

top vs htop
===========
* 개요 : top과 htop은 인터페이스도 비슷하다. 무슨 차이가 있는지 알아보자.
* \> top
  ![image](https://user-images.githubusercontent.com/70207093/181177927-0df21a4e-784e-4495-a701-5dcac4539ad9.png)

* \> htop
  ![image](https://user-images.githubusercontent.com/70207093/181178195-018ce5cc-d90b-4689-a3ea-51877ed3d889.png)
