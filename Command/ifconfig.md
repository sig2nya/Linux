ifconfig
========
* 개요 : Ubuntu 18.04를 사용하던 와중에 애플리케이션을 리부트 하였다(맨날 CentOS만 써서 헷갈림...). 그랬더니, DHCP로 IP를 받아 온건지... IP주소가 갑자기 바뀌었다... Ubuntu는 /etc/sysconfig/network-script 디렉토리가 없는건지 모르겠지만 수동으로 ip를 고정해야하였다. 다행이 ifconfig는 동작을 하였고, ifconfig로 네트워크 인터페이스의 ip를 설정하는 방법을 알아보자. 사실 알아보고말고 자시고 없다.
* 사용법 : ifconfig [Network Interface Name] [IP]
* NetMask / BroadCast 설정 포함 사용법 : ifconfig [Network Interface Name] [IP] netmask [Netmask Addr] broadcast [Broadcast Addr]
* Prefix를 통한 설정 사용법 : ifconfig eth0 172.0.0.1/24 처럼 접두어를 통하여 NetMask도 설정 가능.
* GateWay 설정 : route add default gw [IP]
* * 설정한 값은 영구적이지 않으며, 네트워크 서비스를 재시작(리부팅 등)하면 설정 값은 지워진다.
