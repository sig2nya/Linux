* 참조 : https://velog.io/@bonjaski0989/%EB%A6%AC%EB%88%85%EC%8A%A4-%EB%A7%81%ED%81%AC-Hard-Link-Symbolic-Link

링크
====
![image](https://user-images.githubusercontent.com/70207093/184623801-5d494ba6-35c6-439e-981f-b6b656f34d1d.png)
* 개요 : 파일 링크에는 '하드 링크'와 '심볼릭 링크' 두 가지가 존재 / 일반적으로 '심볼릭 링크'를 주로 사용하며, Windows의 '바로 가기'도 심볼릭 링크에 해당
* inode : 리눅스에서 사용되는 자료구조 / 모든 파일 혹은 디렉토리는 inode를 1개 갖고 있으며, inode에는 해당 파일에 대한 정보가 존재(소유권, 허가권, 파일 종류, 위치 등) / 심볼릭 링크를 생성하면 새로운 inode가 생성
* inode block : inode가 모인 공간
* data block : 실제 데이터가 저장된 디스크 공간
* hard link 만들기 : 옵션 없이 사용
  ![image](https://user-images.githubusercontent.com/70207093/184624460-67df742b-b782-4779-802a-e9c971587860.png)
* soft link 만들기 : -s 옵션을 사용
  ![image](https://user-images.githubusercontent.com/70207093/184624641-d23d30a2-9256-4522-9750-09ec86009341.png)
* 생성한 link 확인 : ls -il (inode 확인)</br>
  ![image](https://user-images.githubusercontent.com/70207093/184624768-d9c01540-a251-4625-897f-c05e26c48eb1.png)
* hard link와 soft link의 차이</br>
  ![image](https://user-images.githubusercontent.com/70207093/184624955-dfa8e457-56c2-447a-8627-10692570c55b.png)
