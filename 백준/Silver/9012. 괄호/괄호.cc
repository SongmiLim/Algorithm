#include <iostream>
#include<vector>
using namespace std;


void Solve(string& str) {
	string tmp;

	for (auto& s : str) {
		if (tmp.size() == 0){
			if (s == ')') {
				cout << "NO" << endl;
				return;
			}
			tmp.push_back(s);
		} else if (tmp.back() == s) {
			tmp.push_back(s);
		} else {
			tmp.pop_back();
		}
	}

	if (tmp.size() == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	int t;
	vector<string> result;

	cin >> t;

	while (t--) {
		string str;
		cin >> str;
		Solve(str);
	}

	return 0;
}