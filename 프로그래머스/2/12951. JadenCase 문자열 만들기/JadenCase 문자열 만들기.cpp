#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*string solution(string s) {
    string answer = "";
    vector <int > temp;

    int index = 0;
    int current;
    current = s.find(' ');

    while (current != string::npos) {
        int num = stoi(s.substr(index, current - index));
        temp.push_back(num);
        index = current + 1;
        current = s.find(' ', index);
    }
    temp.push_back(stoi(s.substr(index, current - index)));
    sort(temp.begin(), temp.end());
    answer = to_string(temp[0]) + " " + to_string(temp[temp.size() - 1]);

    return answer;
}*/

string solution(string s) {
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
}