Linux Server
============
* 리눅스 서버를 구성한 경우 해킹을 위해 Ping을 통하여 특정 서버에 대한 존재 유무를 확인한다.
* 해당 서버가 중요하거나 노출시킬 필요가 없다면 Ping을 통해 운영상태를 확인할 수 없도록 차단하는 것이 좋다.
* 1) 아무런 조치를 취하지 않은 경우</br>
     <img width="627" alt="image" src="https://user-images.githubusercontent.com/70207093/178438486-37fcf3d3-edf7-4227-b7e6-69be75fe3918.png">
* 2) 다음의 명령어를 수행한 경우 : echo 1 > /proc/sys/net/ipv4/icmp_echo_ignore_all 혹은 sysctl -w net.ipv4.icmp_echo_ignore_all=1
     <img width="627" alt="image" src="https://user-images.githubusercontent.com/70207093/178439007-4e651649-4b32-4096-9e6b-b5226f247929.png">
