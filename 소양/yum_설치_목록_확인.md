yum을 통해 install된 package와 install 가능한 package 목록 확인법
================================================================
* 개요 : 맨날 까먹는 yum list와 yum installed를 사용해보자.
* \> yum list 명령어를 수행해보면 굉장히 많은 package가 출력되는 것을 확인</br>
  ![image](https://user-images.githubusercontent.com/70207093/180671327-ccb2ece9-df37-4ffc-be58-5c09147ad186.png)
* \> yum list | grep tomcat을 수행하여 tomcat을 포함하는 package만 검색
  ![image](https://user-images.githubusercontent.com/70207093/180671395-ea6cb82b-0967-4761-b479-8f29e177991b.png)
* \> yum list installed를 통하여 설치된 package를 확인 가능</br>
  ![image](https://user-images.githubusercontent.com/70207093/180671432-a10df1bd-706a-4c7b-8a99-131fcf55aac4.png)
