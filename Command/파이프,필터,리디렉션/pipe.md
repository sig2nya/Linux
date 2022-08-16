파이프
======
* 개요 : 두 개의 프로그램을 연결해주는 연결 통로를 의미, '|' 문자를 사용
* ex) # ls -l /etc | more

필터
====
* 개요 : 필요한 것만 걸러주는 명령어, grep / tail / wc / sort / grep / awk / sed 등이 있으며, 주로 파이프와 같이 사용
* ex) # ps -ef | grep bash

리디렉션
=======
* 개요 : 표준 입출력의 방향을 바꿈
* ex) # ls -l > list.txt / soft < list.txt > out.txt
