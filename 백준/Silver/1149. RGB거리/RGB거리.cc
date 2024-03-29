#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> cost;
vector<vector<int>> dp;

int solve() {
    dp.resize(n, vector<int>(3, 0));
    dp[0][0] = cost[0][0];  // 첫번째집 빨간색
    dp[0][1] = cost[0][1];  // 첫번째집 초록색
    dp[0][2] = cost[0][2];  // 첫번째집 파란색

    for (int i = 1; i < n; i++) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    return min({ dp[n-1][0],dp[n-1][1],dp[n-1][2] });
}

int main() {
    int answer = 0;
    cin >> n; 
    cost.resize(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    answer = solve();
    cout << answer;

    return 0;
}