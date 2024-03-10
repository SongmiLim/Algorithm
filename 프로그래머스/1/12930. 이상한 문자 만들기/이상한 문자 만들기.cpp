#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int pos = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            pos = 0;
            continue;
        }
        if (pos % 2 == 0) {
            s[i] = toupper(s[i]);
            pos++;
        }
        else if (pos % 2 != 0) {
            s[i] = tolower(s[i]);
            pos++;
        }
    }
    answer = s;
    return answer;
}