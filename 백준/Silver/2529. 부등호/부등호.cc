#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k;
vector <string> list;
vector<string> answer;
vector<int> temp;
bool visited[10];

void solve(int cnt) {
	if (cnt == k + 1) {
		bool flag = false;
		for (int j = 0; j < list.size(); j++) {
			if (list[j] == "<") {
				if (temp[j] < temp[j + 1]) {
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (list[j] == ">") {
				if (temp[j] > temp[j + 1]) {
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			string s = "";
			for (auto& a : temp) {
				s += to_string(a);
			}
			answer.push_back(s);
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			temp.push_back(i);
			visited[i] = true;
			solve(cnt + 1);
			visited[i] = false;
			temp.pop_back();
		}

	}
}

int main() {
	string str;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> str;
		list.push_back(str);
	}

	solve(0);
	sort(answer.begin(), answer.end());

	cout << answer[answer.size() - 1] << '\n';
	cout << answer[0];
	return 0;
}