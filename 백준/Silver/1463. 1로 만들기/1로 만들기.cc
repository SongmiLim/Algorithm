#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;

int main() {
    int answer = 0;

    cin >> n;
    dp.resize(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    answer = dp[n];
    cout << answer;

    return 0;
}