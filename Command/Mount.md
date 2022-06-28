* 먼 옛날, CD라는 저장 매체가 존재하였다. CD라는 저장 매체는 컴퓨터 본체에 삽입 될 수 있었으며, 당신이 Window 운영체제를 쓴다면 '내 컴퓨터' 애플리케이션에서 CD에 저장된 파일을 사용할 수 있었다.
* Window 운영체제만 사용해보았다면, 당신은 '마운트'에 대한 지식을 몰라도 된다.(Window는 자동으로 마운트를 수행해줌) 하지만, Linux는 다르다.
* CD나 USB를 본체에 삽입하는 경우, '내 컴퓨터'에서 ':E', ':D'라는 폴더가 자동으로 생성되는 것을 확인할 수 있는데 이게 마운트다.(PnP : Plug n Play 기능 덕분에...)

mount
=====
* 1) 리눅스는 윈도우즈처럼 자동으로 mount 수행을 하진 않는다.
* 2) 즉, 어떠한 Device를 해당 운영체제에 연결하였다면 관리자가 직접 mount 작업을 해주어야 한다.

* 첨언 : VMWare 혹은 Virtual Box와 같이 가상화 환경에서, Host의 파일을 Guest에 옮기기 위해 마운트 사용도 가능하다.