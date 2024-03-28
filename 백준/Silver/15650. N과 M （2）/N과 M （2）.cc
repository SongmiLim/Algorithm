#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visited[9];
vector <int> temp;



void solve(int n) {
	if (temp.size() == M) {
		for (auto& a : temp) {
			cout << a << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = n; i <= N; i++) {
		temp.push_back(i);
		solve(i + 1);
		temp.pop_back();
	}
}

int main() {
	cin >> N >> M;
	solve(1);
	return 0;
}