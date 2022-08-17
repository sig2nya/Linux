* 참조 : https://www.youtube.com/playlist?list=PLVsNizTWUw7EoFNBhIdVFp9eT6P22hU1o

커널 컴파일
===========
* 순서
  ![image](https://user-images.githubusercontent.com/70207093/185100284-93f083fd-493c-461f-abf7-f77676eb705d.png)

실습
====
1. uname -r</br>
  ![image](https://user-images.githubusercontent.com/70207093/185100947-ccc47ff9-26a3-4cc2-9e36-dedf93a1a9e0.png)
2. www.kernel.org 접속 및 최신버전 download</br>
  ![image](https://user-images.githubusercontent.com/70207093/185101190-411a2deb-84c6-4654-a4d2-fa5a6d907cf0.png)
  ![image](https://user-images.githubusercontent.com/70207093/185101437-26e1fe34-b208-4620-8956-aea5ae73ab26.png)
3. /usr/src 폴더로 해당 파일 mv 및 압축 풀기</br>
  ![image](https://user-images.githubusercontent.com/70207093/185102082-87e2a2de-c962-4219-a4cb-aa17766d6c5d.png)
4. 아카이브 파일을 해제
```
 > tar xvf linux-5.19.1.tar
```
  ![image](https://user-images.githubusercontent.com/70207093/185102622-e29cc840-e549-4491-b2d6-d90ca6847ee8.png)
5. 해당 폴더로 이동</br>
   ![image](https://user-images.githubusercontent.com/70207093/185102818-4f7bc349-04f3-4a7f-8ca2-a2b3d26b54d4.png)
6. 컴파일에 필요한 패키지를 설치</br>
```
 > apt -y install gt-5default libssl-dev make gcc g++ flex bison
```
   ![image](https://user-images.githubusercontent.com/70207093/185103162-411b0c2b-faa2-4a1f-8608-818dc6143b54.png)
7. kernel 설정을 위한 명령 수행</br>
```
 > make mrproper
 > make xconfig
```
  ![image](https://user-images.githubusercontent.com/70207093/185103408-9d2e463a-b815-4439-8385-240c944972d2.png)
* 상기 명령을 수행하면 다음과 같은 kernel configuration 화면 출력</br>
  ![image](https://user-images.githubusercontent.com/70207093/185103477-776f767a-55e1-4126-a2d9-f9551365dca8.png)
8. configuration 수행</br>
   ![image](https://user-images.githubusercontent.com/70207093/185104037-38bc0378-d1f8-43a5-859b-73420c45765f.png)
* 위와 같이 CPU, File System, Network 등등등 다양한 kernel 설정이 가능
9. 컴파일 수행</br>
```
 > make ; make modules_install ; make install
```
   ![image](https://user-images.githubusercontent.com/70207093/185104514-c1ea11d4-d509-48a4-8be5-a955a50f6c73.png)
