cron
====
* 개요 : 주기적으로 반복되는 일을 자동적으로 실행, 관련 데몬은 'crond'이며 파일은 /etc/crontab에 존재
* 사용법
```
/etc/crontab
- 분 시 일 월 요일 사용자 실행명령
ex) 00 05 1 * * root cp -r /home /backup
```

at
==
* 개요 : cron과의 차이로는 at은 일회성 작업을 예약한다는 것
* 사용법
```
- 예약 : # at <시간>
ex) at 3:00am tomorrow / at now + 1 hours
- at> 프롬프트에 예약 명령어 입력 후 [Enter]
- 완료되면 [Ctrl] + [D]
- 확인 : # at-l
- 취소 : # atrm <작업번호>
```
