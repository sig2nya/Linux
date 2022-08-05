ifconfig
========
* 개요 : Ubuntu 18.04를 사용하던 와중에 애플리케이션을 리부트 하였다. 그랬더니, DHCP로 IP를 받아 온건지... IP주소가 갑자기 바뀌었다... Ubuntu는 /etc/sysconfig/network-script 디렉토리가 없는건지 모르겠지만 수동으로 ip를 고정해야하였다. 다행이 ifconfig는 동작을 하였고, ifconfig로 네트워크 인터페이스의 ip를 설정하는 방법을 알아보자. 사실 알아보고말고 자시고 없다.
* 사용법 : ifconfig [Network Interface Name] [IP]
