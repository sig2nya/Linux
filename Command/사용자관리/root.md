* 참고 : https://ihp001.tistory.com/13?category=809001 / http://www.igloosec.co.kr/security-information/%EB%A6%AC%EB%88%85%EC%8A%A4-pam-%EB%AA%A8%EB%93%88%EC%9D%98-%EC%9D%B4%ED%95%B4/

root 관리
=========
* 사용자 분류 : root / 일반 -> 사용자는 UID(User Identity)를 통해서 관리. root는 0번이 할당되고 root를 Super User로 인식. 일반 사용자는 1번부터 부여.
* 시스템 계정 : 시스템의 필요에 의해 생성된 계정. vim, daemon, adm, game 등
* root 계정 관리 : 다른 슈퍼유저의 존재 점검. PAM을 이용하여 root 계정으로의 직접 로그인을 막고, su 명령 사용 유도.
* * PAM : PAM (Pluggable Authentication Module)이란 리눅스에서 사용하는 '인증 모듈'로써 애플리케이션에 대한 사용자 권한을 제어

사용자 관리
===========
* 사용자 정보 : /etc/default/useradd에 
* 사용자 계정 생성 : useradd [option] 사용자계정 이름
* 옵션
> -p : 비밀번호 지정 / --password
> -d : 홈 디렉터리 지정 / --home-dir
> -g : 그룹을 지정 / --group
> -G : 추가 그룹 지정 / --groups
> -c : 사용자 설명 설정 / --comment
> -s : 사용자 셸 지정 / --shell
> -D : /etc/default/useradd에 설정된 유저추가와 관련된 기본 사항들을 보여주며 -D 옵션과 같이 나머지 옵션들을 추가로 주면 그 옵션의 기본값을 바꿈
> -m : 홈 디렉터리 생성
> -k : 사용자 생성시에 제공되는 환경 파일들은 기본적으로 /etc/skel로 지정되어 있으며, 이외의 디렉터리 지정시에 사용
> -f : Password 만기 이후 며칠뒤에 계정이 영구적으로 불가능하게 할건지 설정
> -e : 계정 만기일. YYYY-MM-DD 형태 / --expiredate
> -u : UID 값 지정
