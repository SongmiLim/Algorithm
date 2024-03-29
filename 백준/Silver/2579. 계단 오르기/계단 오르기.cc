#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> stairs;

int dp[301];
int solve() {
	
	dp[1] = stairs[1];
	dp[2] = stairs[1]+stairs[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
	}
	return dp[N];
}

int main() {
	int answer = 0;
	cin >> N;
	stairs.resize(N+1, 0);

	for (int i = 1; i <= N; i++) {
		int s;
		cin >> s;
		stairs[i] = s;
	}
	
	answer = solve();
	cout << answer;
	
	return 0;
}