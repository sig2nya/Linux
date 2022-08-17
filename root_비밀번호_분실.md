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
