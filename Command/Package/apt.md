apt
===
* 개요 : 'dpkg' 명령어의 패키지 의존성 문제를 해결, 인터넷을 통하여 필요한 파일을 Repository에서 자동으로 다운로드 및 설치
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
