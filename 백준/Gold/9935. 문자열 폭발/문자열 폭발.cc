#include <iostream>

using namespace std;


int main() {
	string str, bomb_str;
	string result;

	cin >> str;
	cin >> bomb_str;

	for (auto& s : str) {
		result.push_back(s);

		if (result.size() >= bomb_str.size() && result.substr(result.size() - bomb_str.size()) == bomb_str) {
			result.erase(result.size() - bomb_str.size());
		}
	}

	if (result.size() == 0) {
		cout << "FRULA" << endl;
	} else {
		cout << result << endl;
	}
	return 0;
}