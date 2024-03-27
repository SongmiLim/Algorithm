#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int N;
	vector <int> num_list;
	stack <int> comp_list;
	vector <int> answer;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		num_list.push_back(num);
	}

	for (int i = N-1; i>=0; i--) {
		while (!comp_list.empty() && comp_list.top() <= num_list[i]) {
			comp_list.pop();
		}
		if (comp_list.empty()) {
			answer.push_back(-1);
		}
		else {
			answer.push_back(comp_list.top());
		}
		comp_list.push(num_list[i]);
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	return 0;
}