```java
#!/bin/sh
VIP="192.168.0.100" # Virtual IP
DEV="enp0s3" # Network Interface

healthcheck(){
  ping -c 1 -w 1 $VIP > /dev/null
  return $?
}

ip_pingchack(){
  ping -c 1 -w 1 192.168.0.8 > /dev/null
  return $?
}

ip_takeover(){
  IP=$(ip addr show | grep $DEV | egrep -o '([0-9]{1, 3}.){3}[0-9]{1, 3}' | head -1)
  # Virtual IP Take over
  ip addr add $VIP/24 dev $DEV
  echo "$VIP is designated to $IP:$DEV"
}

while ! ip_pingcheck; do # 해당 IP로 ping이 가지 않으면
done
```
