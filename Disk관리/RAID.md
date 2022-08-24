* 참조 : https://blackhunydev.tistory.com/180

각 RAID 방식 비교
=================
![image](https://user-images.githubusercontent.com/70207093/186291747-535c3d17-9c3b-4496-8b31-6012e264f3c5.png)

* 다음 설명에서 디스크의 용량은 개당 1T라고 가정하며, N은 디스크의 개수를 의미한다. 즉, 5N으로 Linear RAID 구성시 총 저장 공간은 5TB이다.

1. Linear RAID : 디스크에 저장되는 데이터가 순차적으로 저장. 즉, 앞의 디스크 메모리가 여유롭다면, 뒤쪽의 디스크에는 데이터가 저장되지 않음. LVM(Logical Volume Manager) 라고도 한다. / 메모리 사용량 : N TB
2. RAID0 : 디스크가 서로 번갈아가면서 저장. 가장 빠른 속도. 데이터를 저장할 때, 모든 디스크를 동시에 사용하지만 하나 이상의 디스크 손실이 발생한다면 모든 데이터를 잃어버린다. / 메모리 사용량 : N TB 
3. RAID1 : RAID1은 Mirroring 개념의 RAID 구성. 즉, 하나의 디스크가 고장나더라도 데이터의 손상이 없기에 Back-Up 용도로 사용하기 적합하다. 하지만, 저장 공간에 대한 효율은 떨어진다. / 메모리 사용량 : (N/2) TB
4. RAID5 : RAID0 + RAID1 방식의 장점을 조합한 RAID 구성 방식. 디스크의 오류가 발생할 경우, Parity를 이용하여 데이터 복구 가능. 디스크는 최소 3개를 요구하며, 보통 5개로 구성한다. 디스크 1개가 고장시, 복구가 가능하지만 2개 이상이 동시에 고장시에는 복구가 불가능하다. / 메모리 사용량 : (N-1) TB
5. RAID6 : RAID6 방식은 RAID5를 개선한 방법으로 2개의 디스크가 동시에 고장나도 복구가 가능하다. 2개의 Parity를 사용함으로써, RAID5의 단점을 보완한다. RAID5보다 효율이 떨어진다. / 메모리 사용량 : (N-2) TB

실습
====
* 개요 : VirtualBox로 RAID 구성을 실습해보자. 보통, 서버에서는 SCSI(SAS) 포트로 구성하기에 하기 실습은 SCSI 컨트롤러를 통하여 실습하였다.

1. 먼저, VirtualBox VM 설정을 진행하자. SCSI 컨트롤러 구성을 위해, VM 설정 -> 저장소 -> LsiLogic(기본 SCSI)를 추가한다.
   ![image](https://user-images.githubusercontent.com/70207093/186299957-ee80aa78-642a-4120-9cd9-c7f7a16586ee.png)

2. 다음과 같이 하드디스크를 추가해준다. 이제 순차적으로 RAID 구성을 진행해보겠다. RAID 실습을 위해, 다음과 같이 SCSI에 총 하드디스크 7개를 달아주었다.
   ![image](https://user-images.githubusercontent.com/70207093/186300876-c7000f6a-846f-45fc-b47f-9fc0225f4cb3.png)

3. Linux에서 확인해보자. ls -al /dev/sd* 명령어를 수행하면, 다음과 같이 가상 하드디스크가 인식되는 것을 확인 가능하다. (sda는 SATA 포트)
   ![image](https://user-images.githubusercontent.com/70207093/186301145-69865935-7013-4f74-b101-fcb7d2005351.png)

4. sdb에 대한 파티션 분할은 다음과 같이 진행하였다. (fdisk /dev/sdb)
   ![image](https://user-images.githubusercontent.com/70207093/186301443-f9af2c17-e4b1-4385-82e4-fd5270daf829.png)

5. print ( > p 수행 )시에 결과는 다음과 같다.
   ![image](https://user-images.githubusercontent.com/70207093/186301597-9a974dc5-e083-49c4-ac78-75b0ea21756a.png)

6. RAID 구성을 위해 Type을 바꾸어야 한다. t를 입력하고, l로 code list를 확인 가능하다. RAID의 경우 코드가 fd이다.(사진 오른쪽 아래 3번째)
   ![image](https://user-images.githubusercontent.com/70207093/186301810-f9e71681-399d-4930-8c3e-cb4ad97ad3dc.png)

7. Type을 바꾼 후, p를 해보면 Linux raid autodetect로 바뀐 것을 확인 가능.
   ![image](https://user-images.githubusercontent.com/70207093/186301955-b33d67e3-a76f-4d63-a22d-fe27acf116b0.png)

8. 다 되었으면, w로 적용시키자. 나머지 disk에 대해서도 fdisk 명령을 통하여 위와 같은 과정을 수행해주자. 이제 본격적으로 RAID 실습을 진행해보자.

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
