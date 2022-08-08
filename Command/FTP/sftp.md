* 참조 : https://jjeongil.tistory.com/1422

SFTP
====
* 개요 : SFTP (SSH File Transfer Protocol)는 FTP의 기능을 모두 지원하며, 암호화된 파일 전송 프로토콜이다. SFTP를 통해 파일을 전송하려면, 원격 시스템에 대해 '파일 쓰기' 권한이 필요하다.
* 연결 설정 : sftp [remote_username@serverip / hostname] -> 사용자 암호가 필요할 수 있음
* Command
> put [filename.zip] : File 업로드
> get [filename.tar.zip] : File 다운로드 / get [filename1.tar.zip] [filename2.tar.zip] : filename1.tar.zip을 filename2.tar.zip으로 이름을 변경하여 저장
> pwd : 원격 서버의 현재 경로
> lpwd : Local의 현재 경로
> lls : Local의 파일 목록
> bye / quit : sftp 작업 종료
