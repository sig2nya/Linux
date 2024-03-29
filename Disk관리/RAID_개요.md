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

실습 준비
=========
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
