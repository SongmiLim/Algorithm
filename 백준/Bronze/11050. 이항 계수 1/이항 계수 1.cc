#include <iostream>
#include <vector>

using namespace std;

int factorial(int n) {
    int ans = 1;
    for (int i = 1; i <=n; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int answer = factorial(n) / (factorial(n - k) * factorial(k));
    cout << answer;
    return 0;
}