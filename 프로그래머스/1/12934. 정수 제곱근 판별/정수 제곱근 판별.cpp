#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long i = 1;

    while(true) {
        if (n == i * i) {
            answer = (i + 1) * (i + 1);
            break;
        }
        if (i > sqrt(n)) {
            answer = -1;
            break;
        }
        i++;
    }
    return answer;
}