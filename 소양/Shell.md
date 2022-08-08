Shell의 정의
============
* 개요 : Shell은 사용자가 커널의 서비스 기능을 사용할 수 있도록 하기 위한 통로 혹은 인터페이스. CLI와 GUI 방식으로 구분하며, 주로 리눅스 Shell이라고 한다면 CLI 방식
* 특징 : 사용자로부터 명령어를 입력받아 해석 및 처리 수행 / 사용자는 셸을 통하여 커널을 제어하며 기능을 이용 / Shell은 일반 응용 프로그램과 같이 커널이 제공하는 시스템 콜을 통해 구현. 즉, 사용자가 커널에게 쉽게 명령을 내릴 수 있는 목적으로 만들어진 기본 응용 프로그램

Shell의 유형
============
1) Bourne Shell 계열 : sh(bourne shell) / ksh(korn shell) / bash(borune again shell)
2) C Shell 계열 : csh(C shell) / lcsh(TC shell)
* * 현재 Shell 확인 방법 : echo $SHELL (환경변수 SHELL을 통하여 현재 로그인한 Shell 확인) / chsh -l 명령어를 통하여 지원 Shell 목록 확인 / cat /etc/shells

