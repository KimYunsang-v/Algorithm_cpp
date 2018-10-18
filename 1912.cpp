#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,max;
	int arr[100010] = {};
	int d[100010] = {};
	cin >> n ;

	for(int i = 1; i <=n; i++)
		cin >> arr[i];

	for(int i=1; i<=n; i++){
		if(d[i-1] + arr[i] > arr[i]){
			d[i] = d[i-1] + arr[i];
		}
		else {
			d[i] = arr[i];
		}
	}
	
	max = d[1];
	for(int i=2; i<=n; i++)
		if(max < d[i])
			max = d[i];

	cout << max;
}