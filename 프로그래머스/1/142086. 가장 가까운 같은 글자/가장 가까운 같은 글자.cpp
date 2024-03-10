#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); i++) {
        int pos = -1;
        for (int j = i-1; j >= 0; j--) {
            if (s[i] == s[j]) {
                pos = i - j;
                break;
            }
        }
        answer.push_back(pos);
    }
    return answer;
}