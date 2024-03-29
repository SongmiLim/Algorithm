#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> num_list;
vector<int> dp;

int solve(int n) {
    dp.resize(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int main() {
    int answer = 0;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        cin >> n;
        num_list.push_back(n);
    }

    for (auto& n : num_list) {
        cout << solve(n) << '\n';
    }

    return 0;
}