#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int l, c;
vector <string> alphabet_list;
vector <string> s;

bool is_possible(vector <string> s) {
	int n = 0;

	for (auto& c : s) {
		if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u") {
			n++;
		}
	}

	if (n >= 1 && s.size() - n >= 2)
		return true;
	return false;
}

void solve(int idx, int cnt) {
	if (cnt == l && is_possible(s)) {
		for (int i = 0; i < s.size(); i++) {
			cout << s[i];
		}
		cout << "\n";
	}

	for (int i = idx; i < alphabet_list.size(); i++) {
		s.push_back(alphabet_list[i]);
		solve(i + 1, cnt + 1);
		s.pop_back();
	}
}
int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		string s;
		cin >> s;
		alphabet_list.push_back(s);
	}

	sort(alphabet_list.begin(), alphabet_list.end());
	solve(0, 0);

;	return 0;
}