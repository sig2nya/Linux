Database Server 구축
====================
* 개요 : 서버에서 매우 중요한 데이터베이스를 구축해보자. 이번 실습에서는 MariaDB를 사용하며, Ubuntu에서는 MariaDB를 기본적으로 제공한다고 한다.
1. 설치
 \> apt -y install mariadb-server mariadb-client
2. 서비스 시작
 \> systemctl restart mariadb; systemctl enable mariadb
3. 방화벽 설정 -> mariadb는 3306 포트 사용
 \> ufw allow 3306
4. Client 접속 계정 생성
 \> mysqladmin -u root password '1234'; systemctl restart mariadb
 ![image](https://user-images.githubusercontent.com/70207093/186569137-dd73937c-c798-475c-a4be-d9905db34610.png)
5. Client 접속
 \> mysql -u root -p</br>
 ![image](https://user-images.githubusercontent.com/70207093/186569217-51eff7c6-e103-4fc6-b47b-1ec6214c90ad.png)
6. Mariadb는 외부에서 접속 비허용이 기본값이다. 따라서, 다음의 configuration이 필요하다.
 \> vim /etc/mysql/mariadb.conf.d/50-server.cnf
 ![image](https://user-images.githubusercontent.com/70207093/186569573-0f91010d-8247-4060-8915-1c90356df043.png)
* bind-address 항목을 주석처리해준다.
7. root 계정에 아무나 접근 불가능하기 때문에, 허용할 IP를 지정해야한다.
* MariaDB 서버 접속 및 다음 쿼리문 실행
 \> select host, user, plugin, authentication_string from mysql.user;
 ![image](https://user-images.githubusercontent.com/70207093/186570123-f3e6c794-8844-41b3-9022-a403b4713905.png)
* 권한 privileges를 위한 다음의 쿼리문 수행
 \> grant all privileges on *.* to 'root'@'%' identified by 'password';
