#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";

    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == ' ') {
            s[i] = toupper(s[i]);
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    answer = s;

    return answer;
}

/*string solution(string s) {
    string answer = "";
    vector<string> tmp;
    string buf;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            tmp.push_back(buf);
            buf.clear();
        }
        s[i] != ' '? buf += s[i] : buf;
    }
    tmp.push_back(buf);

    for (int i = 0; i < tmp.size();i++) {
        if (islower(tmp[i][0])) {
            tmp[i][0] = toupper(tmp[i][0]);
        }
        
        for (int j = 1; j < tmp[i].size(); j++) {
            if (isupper(tmp[i][j])) {
                tmp[i][j] = tolower(tmp[i][j]);
            }
        }
    }
    
    for (int i = 0; i < tmp.size(); i++) {
        if(i!=0){
            answer += " ";
        }
        answer += tmp[i];
    }

    return answer;
}*/