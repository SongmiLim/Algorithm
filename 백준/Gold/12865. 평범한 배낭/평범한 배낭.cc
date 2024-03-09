#include <iostream>
#include <string.h>
#include <algorithm>

int N, K;
int weight[101];
int value[101];
int dp[101][100001];

int main() {
	std::cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		std::cin >> weight[i] >> value[i];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= K; w++) {
			if (weight[i] <= w)   
				// max(이전 아이템의 최대 가치, 이전 아이템 빼고 현재 물건을 넣는 가치)
				dp[i][w] = std::max(dp[i - 1][w], value[i] + dp[i - 1][w - weight[i]]);  
			else 
				dp[i][w] = dp[i-1][w];
		}
	}
	std::cout << dp[N][K];

	return 0;
}