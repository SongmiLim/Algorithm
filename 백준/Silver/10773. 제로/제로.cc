#include <iostream>
#include<stack>

using namespace std;


int main() {
	int k;
	stack<int> nums;

	cin >> k;

	while (k--) {
		int num;
		cin >> num;
		if (num == 0 && nums.size() != 0) {
			nums.pop();
		} else {
			nums.push(num);
		}
	}
	int sum = 0;
	while (!nums.empty()) {
		sum += nums.top();
		nums.pop();
	}
	cout << sum << endl;
	return 0;
}