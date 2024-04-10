#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int m, n;
vector <int> list;
int visited[10001];
vector <int> v;
void solve(int cnt) {
	if (cnt == m) {
		for (auto& a : v) {
			cout << a << " ";
		}
		cout << "\n";
		return;
	}
	int tmp = 0;
	for (int i = 0; i < list.size(); i++) {
		if (tmp!=list[i]) {
			v.push_back(list[i]);
			tmp = list[i];
			solve(cnt + 1);
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
	solve(0);

	return 0;
}