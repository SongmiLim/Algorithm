#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int k = 3;   // k에 할당하는 수에따라 2진법,3진법,,, 등 적용 가능하다
    vector <int> v;

    while (true) {
        v.push_back(n % k);
        n = n / k;
        if (n == 0)
            break;
    }
    for (int i = 0; i < v.size(); i++) {
        answer += v[i] * pow(3, v.size() - i - 1);
    }
    return answer;
}