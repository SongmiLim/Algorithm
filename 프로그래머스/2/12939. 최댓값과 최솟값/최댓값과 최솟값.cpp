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
    string n;
    vector <int> tmp;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            tmp.push_back(stoi(n));
            n.clear();
        }
        else {
            n += s[i];
        }
    }
    tmp.push_back(stoi(n));
    sort(tmp.begin(), tmp.end());
    answer = to_string(tmp[0]) + " " + to_string(tmp[tmp.size() - 1]);
    return answer;
}