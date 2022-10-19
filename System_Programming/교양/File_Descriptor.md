파일 기술자(File Descriptor)
============================
* 개념 : 리눅스 시스템에서 프로세스가 파일을 다룰때 사용하는 개념. File Descriptor는 프로세스에서 특정 파일에 접근하기 위한 uint이다.
* 주요 사용 : open 혹은 creat 함수를 호출할 때, 인자로 사용되며 어떠한 파일을 대상으로 read 및 write를 수행할지 구분하는 값
* 특징 : fd 0번, 1번, 2번은 reserved fd로써 0번은 stdin, 1번은 stdout, 2번은 stderr에 매핑
