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
#include <algorithm> 
using namespace std;

int makeOne(int n, int a[]){
	// 만약 a[n]의 값이 있다면 a[n]값 리턴 - 기존 했던 연산을 또 하지 않기 위함
	if(a[n] != 0) return a[n];

	switch(n){
	case 1:
		a[n] = 0;
		break;
	case 2:
	case 3:
		a[n] = 1;
		break;

	default:
		if(n%3 == 0) // n이 3으로 나누어 떨어지면 n/3을 재귀호출 후 + 1
			a[n] = makeOne(n/3, a) + 1;
		if(n%2 == 0) {
			/* n이 2로 나누어 떨어지고 0이면 바로 makeOne(n/2,a) +1 이 a[n]값이 되고 
			 아니면 makeOne(n/2,a) +1 값과 기존 a[n]값을 비교 후 작은 값을 a[n]에 넣음 */

			//a[n] = !a[n] || (a[n] > makeOne(n/2, a)+1) ? makeOne(n/2, a)+1 : a[n] ;
			if(a[n] == 0)
				a[n] = makeOne(n/2, a) + 1 ;
			else
				a[n] = a[n] > (makeOne(n/2, a)+1) ? makeOne(n/2, a)+1 : a[n];		
		}
		/* n이 0이면 바로 makeOne(n-1,a) +1 이 a[n]값이 되고 
			 아니면 makeOne(n-1,a) +1 값과 기존 a[n]값을 비교 후 작은 값을 a[n]에 넣음 */
		//a[n] = !a[n] || (a[n] > makeOne(n-1, a)+1) ? makeOne(n-1, a)+1 : a[n] ;
		if(a[n] == 0)
				a[n] = makeOne(n-1, a)+1 ;
			else
				a[n] = a[n] > (makeOne(n-1, a)+1) ? makeOne(n-1, a)+1 : a[n];		
		break;
	}
	return a[n];
}

int main(){
	int num;
	int arr[100001] = {0};
	cin >> num;

	cout << makeOne(num, arr);

	return 0;
}