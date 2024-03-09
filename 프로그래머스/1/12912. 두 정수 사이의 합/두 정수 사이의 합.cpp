#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int max_n = max(a, b);
    int min_n = min(a, b);
    for (int i = min_n; i <= max_n; i++) {
        answer += i;
    }
    return answer;
}