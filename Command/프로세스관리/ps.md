ps -ef
======
* 개요 : 현재 구동되고 있는 프로세스는 서버 관리에서 매우 중요하다. ps를 잘 사용해보자. 주로, ps -ef | grep <프로세스 이름> 형태로 주로 사용.
* \> ps -ef : 현재 도는 프로세스에서 부모 PID와 자식 PID의 관계를 볼 수 있다.
  ![image](https://user-images.githubusercontent.com/70207093/181177562-4b3cffe7-7aa8-4260-8a17-76194741cdcd.png)

ps aux
======
* 개요 : 프로세스 상태 확인을 위해서는 ps aux가 더 유용하다.
* \> ps aux
  ![image](https://user-images.githubusercontent.com/70207093/181178760-22aaee0c-ff22-44e6-8318-3abd5593c62a.png)
