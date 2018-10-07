/*
다이나믹 프로그래밍
제목 :계단 오르기
문제 :
   ※ https://www.acmicpc.net/problem/2579 참고
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n; // 입력 받는 갯수
	int num;
	int stair[305] = {0};
	int dp[305] = {0};

	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> num;
		stair[i] = num;
	}


	// 첫번 째 계단은 무조건 밟아야 한다.
	// 두번 째 계단에서 최대값은 첫번 째 계단 + 두번 째 계단
	// 세번 째 계단은 첫번 째 계단에서 올라올 때와 두번째 계단에서 올라올 경우가 있다.
	for(int i = 1; i <= 3 && i <= n; i++){
		if(i != 3)
			dp[i] = dp[i-1] + stair[i];
		else
			dp[i] = max(dp[i-2] + stair[i] , stair[i-1] + stair[i]);
	}

	//네번 째 계단에서 최대값은 전 계단을 밟고 올라오는 경우와 전전 계단을 밟고 올라오는 경우가 있다.
	//전 계단을 밟은 경우에는 전전 계단을 밟지 못한다. (세개의 계단을 연속해서 밟지 못함)
	//따라서 전전전 계단에서의 최대값과 전 계단의 점수 + 현재 계단의 점수를 더하면 현재 계단에서의 최대값이 된다.
	//전전 계단을 밟고 올라오는 경우에는 전전 계단에서의 최대값과 현재 계단의 점수를 더하면 현재 계단에서의 최대값이 된다.
	for(int i = 4; i <= n; i++)
		dp[i] = max( dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);

	cout << dp[n];

	return 0;
}