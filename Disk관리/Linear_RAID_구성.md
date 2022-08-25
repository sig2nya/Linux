Linear RAID 구성
================
* 개요 : Linear RAID를 구현. sdb / sdc 디스크 사용
* 선행작업 : mdadm 필요 -> RAID 구성에 필요한 명령어
* 다음과 같이 mdadm not found가 출력되면, install 수행</br>
  ![image](https://user-images.githubusercontent.com/70207093/186327949-f8b50f43-8fc3-469a-8887-dac0894ab601.png)
> RAID 구성 명령어 : \> mdadm --create /dev/md9 --level=linear --raid-devices=2 /dev/sdb1 /dev/sdc1
* 성공하면, 아래와 같이 출력.</br>
  ![image](https://user-images.githubusercontent.com/70207093/186328586-b5199a8b-ed2e-45bc-9115-68c7062934bc.png)
> RAID 구성 확인 : \> mdadm --detail --scan
* md9라는 이름으로 RAID가 구성된 것을 확인</br>
  ![image](https://user-images.githubusercontent.com/70207093/186328938-52fe8ad0-8d5a-4cd0-b2d1-6c81066b8642.png)
* RAID 사용을 위한 작업
> \> mkfs.ext4 /dev/md9
</br>

  ![image](https://user-images.githubusercontent.com/70207093/186329172-f5cdd755-6d87-4c42-8191-fd9f7f33c0d2.png)
> \> mkdir /raidLinear; \> mount /dev/md9  /raidLinear; \> df

* 해당 마운트 포인트에, md9 RAID가 설정이 된 것을 확인</br>
  ![image](https://user-images.githubusercontent.com/70207093/186329321-ecdbd3c7-525b-4781-af4d-d026b2e6d31a.png)

> \> mdadm --detail /dev/md9
* RAID 구성의 detail 확인</br>
  ![image](https://user-images.githubusercontent.com/70207093/186329523-4cd9bdf5-7146-4b4f-b545-1fdd1c2f3b65.png)

* RAID 구성의 적용을 위해, /etc/fstab을 다음과 같이 수정.
  ![image](https://user-images.githubusercontent.com/70207093/186548260-04ca6c02-fae9-49b7-821c-0dd1af50c6d7.png)
