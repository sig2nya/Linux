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

2. > df 명령어를 통하여 RAID 구성 요소 확인
* RAID0과 RAID1이 사라짐을 확인
  ![image](https://user-images.githubusercontent.com/70207093/186553902-84a67bed-f19c-4566-a5ca-fe1a494d410a.png)
