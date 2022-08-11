/etc/passwd
===========
  ![image](https://user-images.githubusercontent.com/70207093/184074633-76a32665-131b-4c93-adb2-e80860bf9cbc.png)
* 개요 : /etc/passwd는 시스템 액세스 권한이 있는 모든 사용자들을 추적하는데 사용
* 다음 정보가 들어 있으며, 콜론으로 분리된 파일
* * 사용자 이름
* * 암호화된 비밀번호
* * 사용자 ID 번호(UID)
* * 사용자 그룹 번호(GID)
* * 사용자 전체 이름(GECOS)
* * 사용자 홈 디렉토리
* * 로그인 쉘
> 요약 : 사용자 이름:암호화 비밀번호:UID:GID:COMMENT:홈 디렉토리:로그인 쉘

/etc/shadow
===========
  ![image](https://user-images.githubusercontent.com/70207093/184075825-7878f383-834f-4df7-923a-757b54599bf0.png)
* 개요 : /etc/shadow에는 암호화된 패스워드와 패스워드 설정 정책 기재, 관리자 계정 및 그룹만이 해당 파일을 READ 가능
* 해당 필드는 $로 구분되어 있으며, 다음과 같이 구분 : $algorithm_id$salt$encrypted_password
