RAID 장애 발생
==============
* 개요 : 고의로 RAID 1, 5에서 장애 발생 후에 복구를 시킴. 이번 실습에서는 해당 디스크의 케이블을 강제로 제거하여 장애를 발생.
1. Virtualbox 설정에서 SCSI 2번과 5번(RAID 1, 5)에 해당하는 Disk를 강제로 제거한다.
* 제거 전
  ![image](https://user-images.githubusercontent.com/70207093/186553197-0d854d1a-cafe-46f5-8419-f847f729f717.png)
* 제거 후
  ![image](https://user-images.githubusercontent.com/70207093/186553344-99c677b1-6602-4adb-8e07-5edd7d377d1d.png)
* 해당 VM에 대한 DISK 확인. SCSI 2번과 5번이 사라진 것을 확인 가능</br>
  ![image](https://user-images.githubusercontent.com/70207093/186553514-fb9097d2-d022-41b6-bc87-645022b37fda.png)
* Disk를 제거한 후에 부팅이 평소보다 더 오래걸릴 수 있다.

2. \> df 명령어를 통하여 RAID 구성 요소 확인
* RAID0과 RAID1이 사라짐을 확인</br>
  ![image](https://user-images.githubusercontent.com/70207093/186553902-84a67bed-f19c-4566-a5ca-fe1a494d410a.png)

3. \> mdadm --detail --scan
* 장애를 발생시킨 RAID가 Inactive 상태인 것을 확인 가능</br>
  ![image](https://user-images.githubusercontent.com/70207093/186554182-ec21ad66-5bc0-4d8b-a095-61a532846b56.png)

RAID 장애 복구
==============
* 개요 : RAID1과 RAID5은 장애를 허용하기 때문에 강제로 실행시킬 수 있다.
1. \> mdadm --run /dev/md1 명령어 수행을 통해 먼저 md1에 대한 RAID를 복구시킨다. 다음과 같이, Inactive 상태에서 Active 상태로 바뀐 것을 확인 가능하다. </br>
   ![image](https://user-images.githubusercontent.com/70207093/186554562-357207de-50e0-49b4-abca-cc1ada9820cc.png)
2. \> df 명령어를 통해 다음과 같이 md1이 살아난 것을 확인 가능하다.
   ![image](https://user-images.githubusercontent.com/70207093/186554675-2194015a-8e40-4fc1-b9ef-2cf5e3e0d0c7.png)
3. \> mdadm --detail /dev/md1 명령어를 통해 각 RAID 장치에 대한 세부 정보 확인 가능.
   ![image](https://user-images.githubusercontent.com/70207093/186554838-36ebda77-36c5-453e-ab73-7893ea50f563.png)
