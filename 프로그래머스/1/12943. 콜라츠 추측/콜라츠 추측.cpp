#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long n = (long)num;

    int answer = 0;
    if (n == 1) {
        return answer;
    }

    while (true) {
        if (answer >= 500) {
            answer = -1;
            break;
        }
        if (n == 1) {
            break;
        }
        else if (n % 2 == 0) {
            n = n / 2;
        }
        else if (n % 2 != 0) {
            n = n * 3 + 1;
        }
        answer++;
    }
    return answer;
}