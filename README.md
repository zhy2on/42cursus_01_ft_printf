# ft_printf
## 기본 개요
* printf를 구현한다.
* mandatory part는 specifier로 csdiupxX%만 구현하면 된다.
* Original printf 에서는 고정 버퍼를 사용한다. 버퍼가 다 차면 출력하고 버퍼를 비우는 식인데, 과제에서는 꼭 그렇게 하지 않아도 된다.

## 구현 개요
* 문자열 format과 가변인자를 받는다. printf("format", 변수) 꼴
* format 안에서 %를 만날 때까지 출력한다.
* %를 만나면 flag, precision, specifier에 대한 정보를 분석한다.
* specifier를 만날 때까지가 printf에서 지정한 서식의 영향이 유효한 범위이다.

## 함수 개요
* print_char
  * width에 맞춰 패딩을 하고 해당 문자를 출력한다. 이 때 %%의 경우 0flag가 가능하며 -flag와 0flag 동시 사용도 가능하다. 이 때 0flag가 무시되기 때문에 해당 부분을 예외처리 해준다.
* print_string
  * precision만큼 문자를 출력하고 width에 맞춰 패딩한다. precision이 문자열보다 크더라도 문자열만큼만 출력한다.
* print_nbr
  * precision이 존재한다면 0flag는 무시되며, 숫자를 출력하고 precision만큼 남은 부분을 0으로 채우고, 그 다음 width만큼 남은 부분을 공백으로 채운다.
  * precision이 숫자길이보다 작더라도 숫자길이만큼 출력한다.
  * 숫자가 0이면서 precison이 0이면 아예 아무것도 출력되지 않는다.

## 자료 정리
* printf
  * 인자: 문자열, 가변인자
  * printf는 첫 번째 인자로 출력하고자 하는 포맷 문자열을 전달한다.
  * 포맷 지정 문자열의 ``%``문자는 변환 사양 문자로 flags와 길이 수정자가 옵션으로 올 수 있다.
  * 포맷 지정자 문자인 ``diouxXaAeEfFgG%`` 중 하나를 사용한다. <https://ehpub.co.kr/24-printf-%ED%95%A8%EC%88%98/>
  * ``%[플래그(flag)][폭(width)][.정밀도(precision)]서식 문자(specifier)`` <https://modoocode.com/35>

* stdarg.h
  * C언어에서 ``stdarg.h`` 헤더를 사용하면 함수 선언 시 가변 인자(Variable arguments)를 가질 수 있다.
  * ``stdarg.h`` 헤더파일은 자료형으로 ``va_list``를 가지며, 함수로 ``va_start``, ``va_arg``, ``va_end`` 등의 함수를 포함하고 있다.

* 가변인자
  * 가변인자를 사용하기 위해선 최소 한 개 이상의 고정인수가 있어야 하며 ``...``은 파라미터 순서상 가장 마지막에 위치해야 한다.

* va_start
  * argument pointer를 고정인수 다음 위치로 초기화 시킨다.

* va_arg
  * 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져온다. 이후 자료형 크기만큼 포인터를 순방향 이동시킨다. <https://dojang.io/mod/page/view.php?id=577>
  * var_type을 설정할 때 char, short의 경우에는 int로 대신 쓰고, float의 경우에는 double로 대신 쓴 이후 형변환을 해주어야 한다.

* va_end
  * 사용이 끝난 포인터를 NULL로 초기화시킨다.

* mac os 환경과 wsl 환경에서 플래그 위치에 따른 차이
  * mac os에서는 서식 위치가 바뀌거나 0 flag가 c와 같이 오는 경우도 알아서 출력을 해준다. 여기에 맞춰서 ft_printf를 구현해야 한다.
  * mac os에선 NULL 문자열을 출력할 때 (null)이 출력 되고 wsl에선 seg fault가 발생한다.

* specifer별 정리 (mac os 기준) (gcc -Wall -Wextra -Werror 기준...😭 빼먹고 테스트 하다가 큰 일 날 뻔..)
  * https://dojang.io/mod/page/view.php?id=736 (코딩도장 서식 지정자별 자료형 크기 참고)

| specifier | '-' flag | '0' flag | width | precision | 비고 |
|:---------:|:------------------------:|:--------:|:-----:|:---------:|------|
|%c| O | X | O | X | width에 맞춰 정렬한다. |
|%s| O | X | O | O | precision만큼 출력하고 width에 맞춰 정렬한다. precision이 문자열보다 크더라도 문자열만큼만 출력한다.|
|%d| O | O | O | O | precision이 존재하면 precision에 맞춰 남은 앞부분을 0으로 채우고 음수인 경우 그 앞에 부호를 붙인 후, width에 맞춰 공백을 채운다. ( precision이 숫자길이보다 작더라도 숫자길이만큼 출력한다.) 이 때 width는 0 flag 이더라도 공백으로 채워진다. precision이 존재하지 않는다면 width에 맞춰 앞 부분을 공백으로 채운 후 그 앞에 부호를 붙인다. 이 때 0 flag이면 '0'으로 앞 부분을 채운다. 숫자 0의 경우 .이 찍힌 상태에서 precision이 0이면 숫자 0은 출력되지 않는다. |
|%i| O | O | O | O | '' |
|%u| O | O | O | O | '' |
|%p| O | X | O | X | 앞에 0x를 붙여서 반환한다. 왼쪽 정렬인 경우 0x를 제일 먼저 출력한다. 공백으로 padding할 때는 패딩 이후 0x를 출력한다. |
|%x| O | O | O | O | precision이 존재하면 precision에 맞춰 남은 앞부분을 0으로 채우고, width에 맞춰 공백을 채운다. |
|%X| O | O | O | O | '' |
|%%| O | O | O | X | %c와 비슷하지만, %의 경우 0 플래그가 적용된다. 또한 -0을 동시에 쓰는 것이 유효하다. |

| specifier | '#' flag | ' ' flag | '+' flag | 비고 |
|:---------:|:--------:|:--------:|:--------:|------|
|%c| X | X | X |    |
|%s| X | X | X |    |
|%d| X | O | O | ' ' 플래그가 있는 경우 음수가 아니면서 precision이 너비보다 클 때, 너비가 0보다 작거나 같을 때 앞을 한 칸 띄고 출력한다. |
|%i| X | O | O | '' |
|%u| X | X | X |    |
|%p| X | X | X | void* NULL 출력시 0x0을 출력한다. |
|%x| O | X | X | #플래그로 0을 출력하는 경우 0x0이 아니라 0이 출력된다. #플래그의 경우 왼쪽 정렬이거나 0flag일 때 0x를 제일 먼저 출력한다. 공백으로 padding할 때는 패딩 이후 0x를 출력한다. |
|%X| O | X | X | '' |
|%%| X | X | X |    |

* library 이용 컴파일
  * ``gcc`` c파일 ``-L`` 라이브러리 경로 ``-l`` 라이브러리명
  * ex) 라이브러리명은 lib를 뺀 이름으로 한다.
  ```c
  gcc test.c -L ./ -l ftprintf
  ```
  
* 숫자 접두사
  * 숫자 출력 서식지정자에서 가변인자에 접두사 0이 붙은 경우 8진수, 0x/0X가 붙은 경우 16진수를 뜻한다.
