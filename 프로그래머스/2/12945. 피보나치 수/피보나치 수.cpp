#include <string>
#include <vector>

using namespace std;

vector <long long> memo;

int fibo(long long num) {
    /*if (num <= 1)
        return num;
    if (memo[num] != -1)
        return memo[num];
    memo[num] = fibo(num - 1) + fibo(num - 2) ;
    return memo[num];*/

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= num; i++) {
        memo[i] = (memo[i - 1] + memo[i - 2])%1234567;
    }
    return memo[num];
}

int solution(int n) {
    int answer = 0;
    memo.resize(n + 1, -1);

    answer = fibo(n);
    //answer = answer % 1234567;

    return answer;
}