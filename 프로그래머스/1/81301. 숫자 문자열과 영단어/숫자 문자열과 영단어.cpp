#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans;
    int cnt = 0;
    string tmp;
    
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            ans += s[i];
            continue;
        }
        else {
            cnt++;
            tmp += s[i];
        }

        if (cnt > 0) {
            if (tmp == "zero") {
                ans += '0';
                tmp.clear();
            }
            else if (tmp == "one") {
                ans += '1';
                tmp.clear();
            }
            else if (tmp == "two") {
                ans += '2';
                tmp.clear();
            }
            else if (tmp == "three") {
                ans += '3';
                tmp.clear();
            }
            else if (tmp == "four") {
                ans += '4';
                tmp.clear();
            }
            else if (tmp == "five") {
                ans += '5';
                tmp.clear();
            }
            else if (tmp == "six") {
                ans += '6';
                tmp.clear();
            }
            else if (tmp == "seven") {
                ans += '7';
                tmp.clear();
            }
            else if (tmp == "eight") {
                ans += '8';
                tmp.clear();
            }
            else if (tmp == "nine") {
                ans += '9';
                tmp.clear();
            }
        }
    }
    answer = stoi(ans);
    return answer;
}
