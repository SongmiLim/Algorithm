#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int m, n;
vector <int> list;
int visited[10001];
vector <int> v;
set <vector<int>> s;

void solve(int idx, int cnt) {
	if (cnt == m) {
		s.insert(v);
		return;
	}

	for (int i = 0; i < list.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(list[i]);
			solve(i, cnt + 1);
			visited[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}
	sort(list.begin(), list.end());
	solve(0, 0);

	for (auto& a : s) {
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}