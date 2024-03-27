#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
bool visited[9] = { false, };
vector <int> num_list;
vector <int> answer;

void solution() {
	for (int i = 1; i <= N; i++) {
		string str = "";
		if (num_list.size() == M) {
			for (auto& a : num_list)
				str += to_string(a) + " ";
			cout << str << '\n';
			return;
		}

		if (!visited[i]) {
			num_list.push_back(i);
			visited[i] = true;
			solution();
			num_list.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	
	solution();

	return 0;
}