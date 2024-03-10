#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    string answer;

    map <string, char> m;
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';

    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            answer += s[i];
            //temp.clear();
        }
        else {
            temp += s[i];
            if (m[temp] != 0) {
                answer += m[temp];
                temp.clear();
            }
        }
    }

    return stoi(answer);
}