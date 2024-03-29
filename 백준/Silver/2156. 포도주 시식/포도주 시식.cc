#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000

vector<int> glass;

int solve(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = glass[1];
    dp[2] = glass[1] + glass[2];
    dp[3] = max(max(dp[2], glass[1] + glass[3]), glass[2] + glass[3]);

    for (int i = 4; i <= n; i++) {
        dp[i] = max(max(dp[i - 3] + glass[i - 1], dp[i - 2]) + glass[i], dp[i - 4] + glass[i - 1] + glass[i]);
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    glass.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> glass[i];
    }

    int answer = solve(n);
    cout << answer;

    return 0;
}
