#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max_n = max(n, m);
    int min_n = min(n, m);

    int i = max_n;
    int j = 1;
    int gcd = 0;
    int lcm = 0;

    while (true) {
        if (n % i == 0 && m % i == 0) {
            gcd = i;
            break;
        }
        i--;
    }


    while (true) {
        if (max_n * j % min_n == 0) {
            lcm = max_n * j;
            break;
        }
        j++;
    }
    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}