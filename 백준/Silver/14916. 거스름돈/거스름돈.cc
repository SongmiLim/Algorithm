#include <iostream>

int main()
{
	int n;
	int cnt = 0;
	
	std::cin >> n;
	
	while (n > 0) {
		if (n % 5 == 0){
			cnt += n / 5;
			break;
		}
		else {
			n -= 2;
			cnt++;
		}
		if (n < 0){
			cnt = -1;
			break;
		}
	}

	std::cout << cnt;

	return 0;
}