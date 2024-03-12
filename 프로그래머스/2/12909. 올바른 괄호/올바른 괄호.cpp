#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int left = 0;
    int right = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            left++;
        }

        else if (s[i] == ')') {
            right++;
        }

        if (right > left) {
            answer = false;
            break;
        }
    }
    if (left != right)
        answer = false;

    return answer;
}