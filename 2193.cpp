#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int j = 1;

	int *a = new int[n+1];
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	a[3] = 2;
	if(n <= 2)
		cout << 1;
	else if( n == 3)
		cout << a[3];
	else{
		for(int i = 4; i <= n; i++){
			a[i] = a[i-1] + j;
			j++;
		}
		cout << a[n];
	}
}