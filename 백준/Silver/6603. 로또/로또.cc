#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

void solve(vector<int> num_list, int idx, int cnt) {
	if (cnt == 6) {
		for (auto& a : v) {
			cout << a << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < num_list.size(); i++) {
			v.push_back(num_list[i]);
			solve(num_list, i+1, cnt + 1);
			v.pop_back();
	}
}

int main() {
	while (true) {
		int k;
		vector<int> num_list;
		cin >> k;
		if (k == 0) {
			break;
		}

		for (int i = 0; i < k; i++) {
			int num;
			cin >> num;
			num_list.push_back(num);
		}
		sort(num_list.begin(), num_list.end());
		solve(num_list,0, 0);
		cout << "\n";
	}
	return 0;
}