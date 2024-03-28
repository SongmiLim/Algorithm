#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
bool visited[9] = { false, };
vector <int> num_list;
vector <int> answer;

void solution(int cnt) {
	if (cnt == M) {
		for (auto& a : num_list)
			cout << a << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
			num_list.push_back(i);
			solution(cnt+1);
			num_list.pop_back();
	}
}

int main() {
	cin >> N >> M;

	solution(0);

	return 0;
}