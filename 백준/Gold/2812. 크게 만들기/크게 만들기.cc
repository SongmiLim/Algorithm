#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int N, K;
	string num;
	stack <int> tmp;
	vector <int> ans;

	cin >> N >> K;
	cin >> num;

	int cnt = K;
	for (int i = 0; i < N; i++) {
		
		while (!tmp.empty() && (tmp.top() < num[i] - '0' ) && cnt > 0) {
			tmp.pop();
			--cnt;
		}
		if (tmp.size() < N - K) {
			tmp.push(num[i] - '0');
		}
	}

	while (!tmp.empty()) {
		ans.push_back(tmp.top());
		tmp.pop();
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}