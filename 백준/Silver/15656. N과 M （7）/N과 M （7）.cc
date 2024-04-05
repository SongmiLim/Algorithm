#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector <int> num_list;
vector <int> answer;

void solution(int index, int cnt) {
	if (cnt == M) {
		for (auto& a : answer)
			cout << a << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < num_list.size(); i++) {
		answer.push_back(num_list[i]);
		solution(i + 1, cnt + 1);
		answer.pop_back();
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
	solution(0, 0);

	return 0;
}