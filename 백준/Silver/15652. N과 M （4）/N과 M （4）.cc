#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector <int> num_list;
vector <int> answer;

void solution(int idx, int cnt) {
	if (cnt == M) {
		for (auto& a : num_list)
			cout << a << " ";
		cout << '\n';
		return;
	}

	for (int i = idx; i <= N; ++i) {
		num_list.push_back(i);
		solution(i, cnt + 1);
		num_list.pop_back();
	}
}

int main() {
	cin >> N >> M;
	solution(1, 0);

	return 0;
}