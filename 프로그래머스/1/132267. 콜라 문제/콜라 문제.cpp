#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int now_bottle_cnt = n;

    while (now_bottle_cnt / a >= 1) {
        int give_bottle = (now_bottle_cnt / a) * a;
        now_bottle_cnt -= give_bottle;
        
        int received_bottle = (give_bottle / a) * b;
        now_bottle_cnt += received_bottle;

        answer += received_bottle;
    }
    return answer;
}