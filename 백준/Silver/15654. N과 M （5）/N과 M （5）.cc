#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool visited[10001] = { false, };
vector <int> num_list;
vector <int> answer;

void solution(int cnt) {
	if (cnt == M) {
		for (auto& a : answer)
			cout << a << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < num_list.size();i++) {
		if (!visited[num_list[i]]) {
			answer.push_back(num_list[i]);
			visited[num_list[i]] = true;
			solution(cnt + 1);
			answer.pop_back();
			visited[num_list[i]] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		num_list.push_back(num);
	}
	sort(num_list.begin(), num_list.end());
	solution(0);

	return 0;
}