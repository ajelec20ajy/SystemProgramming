Assignment : Attack Lab

[Phase 1 : ctarget.l1]

ctarget 프로그램에서 touch1 함수가 실행되도록 버퍼 오버플로우를 일으켜 반환 주소 수정하기. touch1의 메모리 주소 찾아내 수행.


[Phase 2: ctarget.l2]

 ctarget 프로그램에서 touch2 함수를 실행하되, 쿠키 값을 인자로 전달하기. %rdi에 쿠키 값을 넣도록 쉘 코드 작성 후, 스택에 쉘 코드 주입시켜 touch2로 점프시킴.
 

[Phase 3: ctarget.l3]

  ctarget 프로그램에서 tocuh3 함수를 실행하되, 쿠키 값을 문자열 형태로 전달하기. %rdi가 이 문자열이 저장된 메모리 주소를 가리키도록 쉘코드 작성 후 스택에 주입시켜 touch3로 점프시킴.


[Phae 4: rtarget.l2]

 rtarget 프로그램에는 스택 보호 기법이 적용되어 있어, 직접 스택에 쉘코드 주입이 불가능하다. 따라서, ROP 공격을 구현해 프로그램 내 존재하는 코드조각 가젯들을 연결한다. pop %rax; ret 가젯으로 쿠키 값을 레지스터에 로드하고, move %rax, %rdi; ret 가젯으로 인자를 설정 후 touch2를 실행한다.


[Phase 5: rtarget.l3]
 
rtarget 프로그램에서, phase3와 같이 문자열을 인자로 전달하기. 여러 개의 가젯을 연결한다. %rsp 값을 이용해 문자열의 주소를 계산 후, mov 가젯들을 거쳐 주소 값을 %rdi까지 옮긴 후 최종적으로 touch3를 호출한다.
