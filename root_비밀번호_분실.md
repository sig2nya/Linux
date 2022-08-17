root 비밀번호를 분실하였을 때
============================
1. Ubuntu 기준 부팅시에 esc key를 연타하면 다음과 같은 화면 출력. 해당 UI는 GRUB라고 한다.</br>
   ![image](https://user-images.githubusercontent.com/70207093/185094773-fe688608-3db7-4246-a83c-0f990b567f4e.png)
2. 아래로 스크롤하여 다음의 Line에 접근</br>
   <img width="323" alt="image" src="https://user-images.githubusercontent.com/70207093/185095425-0b0c0ebd-87c4-4f12-be3d-65050de867cf.png">
3. Line의 마지막에 'init=/bin/bash' 명령 작성 및 'ctr+x'</br>
   <img width="320" alt="image" src="https://user-images.githubusercontent.com/70207093/185095715-472545ae-7608-47f1-9060-0622466b1c20.png">
4. booting이 되며 root로 접속 완료(현재는 READ ONLY 모드이며, passwd로 패스워드 변경이 불가)</br>
   ![image](https://user-images.githubusercontent.com/70207093/185095879-51facff1-625d-4b5c-a3d8-e6a75f73e1ca.png)
5. \> mount -o remount,rw / 명령 수행 및 passwd로 비밀번호 변경</br>
   ![image](https://user-images.githubusercontent.com/70207093/185096477-4007a9ee-559b-4670-9e5b-7a34e0a82ec2.png)
6. reboot 수행

GRUB 보안 설정
==============
* 개요 : 위의 실습에서 GRUB에 접근 가능하다면 누구나 root의 계정을 변조시킬 것으로 예상된다. 이를 예방하기 위해, BIOS / GRUB 등 주요 시스템 애플리케이션에 대한 보안 설정이 가능하다.
* /etc/default/grub 을 vi 편집기로 열어보자.
```
 > vi /etc/grub.d/00_header
 마지막 4줄에 다음과 같이 스크립트 추가
 cat << EOF
 set superusers="grubuser" // superusers 항목은 id의 개념
 password grubuser 1234 // grubuser id에 대한 pasword 설정
 EOF
 스크립트 작성 이후, update-grub을 통해 변경 사항을 적용
```
   ![image](https://user-images.githubusercontent.com/70207093/185098863-fbc637c2-954b-45f2-a553-5e1b555534dc.png)
* vi 편집기로 00_header 파일을 수정하였다면, reboot 및 GRUB에 접속해보자. 다음과 같이, username과 password가 필요하다.
  ![image](https://user-images.githubusercontent.com/70207093/185099362-fe12dc81-2249-426f-8b63-3e32ac50d089.png)
* username 및 password로 접속 후 GRUB에 접근 가능
  ![image](https://user-images.githubusercontent.com/70207093/185099529-b94aa92e-b272-4f3c-92e9-1a50b696db91.png)
