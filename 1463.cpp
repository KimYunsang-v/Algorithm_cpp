/*
���̳��� ���α׷���
���� : 1�� �����
���� :
���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

1. X�� 3���� ������ ��������, 3���� ������.
2. X�� 2�� ������ ��������, 2�� ������.
3. 1�� ����.

���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.
*/
#include <iostream>
#include <algorithm> 
using namespace std;

int makeOne(int n, int a[]){
	// ���� a[n]�� ���� �ִٸ� a[n]�� ���� - ���� �ߴ� ������ �� ���� �ʱ� ����
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
		if(n%3 == 0) // n�� 3���� ������ �������� n/3�� ���ȣ�� �� + 1
			a[n] = makeOne(n/3, a) + 1;
		if(n%2 == 0) {
			/* n�� 2�� ������ �������� 0�̸� �ٷ� makeOne(n/2,a) +1 �� a[n]���� �ǰ� 
			 �ƴϸ� makeOne(n/2,a) +1 ���� ���� a[n]���� �� �� ���� ���� a[n]�� ���� */

			//a[n] = !a[n] || (a[n] > makeOne(n/2, a)+1) ? makeOne(n/2, a)+1 : a[n] ;
			if(a[n] == 0)
				a[n] = makeOne(n/2, a) + 1 ;
			else
				a[n] = a[n] > (makeOne(n/2, a)+1) ? makeOne(n/2, a)+1 : a[n];		
		}
		/* n�� 0�̸� �ٷ� makeOne(n-1,a) +1 �� a[n]���� �ǰ� 
			 �ƴϸ� makeOne(n-1,a) +1 ���� ���� a[n]���� �� �� ���� ���� a[n]�� ���� */
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