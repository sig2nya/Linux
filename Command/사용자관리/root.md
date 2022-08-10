* 참고 : https://ihp001.tistory.com/13?category=809001 / http://www.igloosec.co.kr/security-information/%EB%A6%AC%EB%88%85%EC%8A%A4-pam-%EB%AA%A8%EB%93%88%EC%9D%98-%EC%9D%B4%ED%95%B4/

root 관리
=========
* 사용자 분류 : root / 일반 -> 사용자는 UID(User Identity)를 통해서 관리. root는 0번이 할당되고 root를 Super User로 인식. 일반 사용자는 1번부터 부여.
* 시스템 계정 : 시스템의 필요에 의해 생성된 계정. vim, daemon, adm, game 등
* root 계정 관리 : 다른 슈퍼유저의 존재 점검. PAM을 이용하여 root 계정으로의 직접 로그인을 막고, su 명령 사용 유도.
* * PAM : PAM (Pluggable Authentication Module)이란 리눅스에서 사용하는 '인증 모듈'로써 애플리케이션에 대한 사용자 권한을 제어
