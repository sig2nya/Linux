* 참조 : https://velog.io/@chullll/7.-apt
![image](https://user-images.githubusercontent.com/70207093/184782006-bdeeb7c7-28b7-4954-9b3f-d50832c6998e.png)


apt
===
* 개요 : 'dpkg' 명령어의 패키지 의존성 문제를 해결, 인터넷을 통하여 필요한 파일을 Repository에서 자동으로 다운로드 및 설치, apt는 apt install 명령 요청을 받으면 /etc/apt/sources.list파일을 먼저 확인</br>
  ![image](https://user-images.githubusercontent.com/70207093/184782227-67998f18-36c9-484a-b8f2-cf863323a6f4.png)
* mirror.kakao.com/ubuntu
  ![image](https://user-images.githubusercontent.com/70207093/184782414-11cf377d-6648-457d-b8e5-c4fd8127b5e8.png)
* 사용법
```
1. 기본 설치 : apt install 패키지 이름
2. 패키지 목록 업데이트 : apt update
3. 삭제 : apt remove / purge 패키지 이름
4. 내려받은 파일 제거 : apt clean / autoclean
5. 패키지 정보 확인 : apt-cache show 패키지 이름
6. 패키지 의존성 확인 : apt-cache depends 패키지 이름
```
* 패키지 설치 전, 정보 확인</br>
  ![image](https://user-images.githubusercontent.com/70207093/184781698-afe90ce6-f45d-43a2-b377-32f1f59283c1.png)
* 설치 수행</br>
  ![image](https://user-images.githubusercontent.com/70207093/184781804-ffdc8773-ce2e-4504-a08b-8fef3be5c120.png)
