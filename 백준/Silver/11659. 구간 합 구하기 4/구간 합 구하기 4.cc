#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> answer;
	int dp[100001] = { 0, };
	int num_list[100001] = { 0, };
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_list[i + 1] = num;
	}

	dp[1] = num_list[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + num_list[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		answer.push_back(dp[b] - dp[a-1]);
	}
	for (auto& a : answer) {
		cout << a << '\n';
	}
	return 0;
}