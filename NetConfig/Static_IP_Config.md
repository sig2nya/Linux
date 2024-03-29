/etc/sysconfig/network-scripts/ifcfg-eth[N]
==============================
* 개요 : 서버 IP를 리눅스로 구성하여 DHCP(network-scripts / dynamic)로 설정하게 될 경우 서버의 IP가 계속 바뀐다. 즉, Client는 요청을 수행하는데 계속 변경된 IP로 요청해야한다(너가 우편물 배달 일을 하는데, 계속 주소가 바뀐다고 생각해보자). 이를 위해 Linux IP를 고정으로 설정하는 방법을 알아보자.
* 네트워크 인터페이스마다 환경설정을 수행. 첫번째 이더넷 카드는 ifcfg-eth0, 두번째 이더넷 카드는 ifcfg-eth1 등으로 네이밍
* * 설정 변경 후, systemctl restart network 혹은 service network restart를 수행해주자.

1) /etc/sysconfig/network-scripts에서 ifcfg로 시작하는 파일을 찾는다.
   <img width="557" alt="image" src="https://user-images.githubusercontent.com/70207093/178420493-5e9c5c04-0875-46a4-a19e-6d390c722df2.png">

2) Network Interface에 대한 정보 확인</br>
   <img width="304" alt="image" src="https://user-images.githubusercontent.com/70207093/178420655-1bf54ad0-7d4c-431b-9097-97574c30c94e.png">
* * TYPE : 장치 타입
* * BOOTPROTO : IP 할당 타입(none / static / dhcp) -> 고정으로 IP 할당시에는 당연히 static으로 
* * IPV4_FAILURE_FATAL : IP 할당 실패시 네트워크 종료 여부(yes / no)
* * IPV6INIT : IPV6 사용 여부
* * NAME : Network 장치 이름
* * UUID : MAC 주소
* * IPADDR : IP 주소
* * ONBOOT : 부팅시 자동 활성 여부
* * GATEWAY : 게이트웨이
* * DNS1 : DNS 주소

3) Network Configure 수정 이후 "service network restart"를 통하여 네트워크 설정 Confirm
   <img width="520" alt="image" src="https://user-images.githubusercontent.com/70207093/178421695-73c97aed-95fe-4c11-969a-a5a62a78a47d.png"> 

```
# 설정 대상이 되는 인터페이스
DEVICE = eth0

# IP 할당 방법 설정 / 수동 - static / 자동(동적) - dhcp
BOOTPROTO=static

# 인터페이스의 Mac Address
HWADDR=xx:xx:xx:xx:xx:xx

# 브로드캐스트 주소
BROADCAST=

# IP주소
IPADDR=

# NETMASK
NETMASK=

# NETWORK Adds
NETWORK=
```
