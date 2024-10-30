#include <iostream>
#include<stack>
#include <vector>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> result(n + 1, 0);
	vector<int> heights(n + 1, 0);
	stack<int> s;

	for (int i = 1; i <= n; ++i) {
		cin >> heights[i];
	}

	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && heights[s.top()] < heights[i])
			s.pop();
		
		if (!s.empty())
			result[i] = s.top();

		s.push(i);
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << result[i] << " ";
	}
	return 0;
}