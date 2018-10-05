/*
다이나믹 프로그래밍
제목 : 1로 만들기
문제 :
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/
#include <iostream>
using namespace std;

int makeOne(int i){
	int count = 0;

	while(i != 1){
		if(i % 2 != 0 && i % 3 != 0){
			i -= 1;
		}
		else if(i % 2 == 0 && i % 3 != 0) {
			i /= 2;
		}else if(i % 2 
	}

}

int main(){
	int num;
	cin >> num;





	return 0;
}