#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = strings;

    sort(answer.begin(), answer.end(), [n](string& s1, string& s2) {
        if (s1[n] == s2[n]) {
            for (int i = 0; i < min(s1.size(), s2.size()); i++) {
                if (s1[i] != s2[i]) 
                    return s1[i] < s2[i];
            }
        }
        return s1[n] < s2[n];
        });
    
    return answer;
}