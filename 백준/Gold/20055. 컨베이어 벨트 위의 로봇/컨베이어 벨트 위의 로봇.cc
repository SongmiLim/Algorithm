#include <iostream>
#include <vector>
using namespace std;

struct Belt{
	bool is_robot;
	int durability;
};

int n, k;


int main() {
	cin >> n >> k;
	vector <Belt> conveyor(2 * n);
	int answer = 0;
	int cnt = 0;

	for (int i = 0; i < 2 * n; i++) {
		cin >> conveyor[i].durability;
	}

	while (true) {

		if (cnt >= k)
			break;

		// move belt
		Belt temp = conveyor[conveyor.size() - 1];
		conveyor.pop_back();
		conveyor.insert(conveyor.begin(), temp);
		
		// down robot
		if (conveyor[n - 1].is_robot)
			conveyor[n - 1].is_robot = false;
		
		// move robot
		for (int i = n - 2; i >= 0; i--) {
			if (!conveyor[i].is_robot)
				continue;

			int next = i + 1;
			if (!conveyor[next].is_robot && conveyor[next].durability>=1) {
				conveyor[i].is_robot = false;
				conveyor[next].is_robot = true;
				conveyor[next].durability--;
				
				if (conveyor[next].durability == 0)
					cnt++;
			}
		}

		// down robot
		if (conveyor[n - 1].is_robot)
			conveyor[n - 1].is_robot = false;

		// up robot
		if (!conveyor[0].is_robot && conveyor[0].durability > 0) {
			conveyor[0].is_robot = true;
			conveyor[0].durability--;

			if (conveyor[0].durability == 0)
				cnt++;
		}

		answer++;
	}

	cout << answer;
}