#include <iostream>

using namespace std;

int N;
int solve() {
	int cnt = 0;
	while (true) {
	
		if (N % 5 == 0) {
			if (N == 0)
				break;
			cnt += N / 5;
			break;
		}

		N -= 3;
		cnt++;

		if (N < 0) {
			cnt = -1;
			break;
		}


	}
	return cnt;
}

int main() {
	int answer = 0;
	cin >> N;
	
	answer = solve();

	cout << answer;
	return 0;
}