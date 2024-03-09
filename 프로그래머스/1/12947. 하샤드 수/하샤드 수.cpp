#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;

    string s =  to_string(x);
    for (int i = 0; i < s.size(); i++) {
        sum += (int)(s[i] - '0');
    }
    stoi(s) % sum == 0 ? answer = true : answer = false;

    return answer;
}