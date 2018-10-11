#include <iostream>
using namespace std;

int a[41] = {1, 1};
int fibonacci(int n) {
	if(a[n] > 1) return a[n];
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
        a[n] = fibonacci(n-1) + fibonacci(n-2);
		return a[n];
    }
}

int main(){
	int n;
	
	int in[100] ={0};
	int k;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> k;
		in[i] = k;
	}
	
	for(int i = 0 ; i < n ; i++){
		 k = in[i];
		 if(k == 0)
			 cout << 1 << " " << 0 << "\n";
		 else if(k == 1)
			 cout << 0 << " " << 1 << "\n";
		 else{
			fibonacci(k);
			cout << a[k-1] << " " << a[k] << "\n";		 
		 }
	}
	return 0;
}
