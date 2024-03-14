#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    m[words[0]] = 1;

    for (int i = 1; i < words.size(); i++) {
        if (m.find(words[i])!=m.end() || words[i - 1][words[i - 1].size() - 1] != words[i][0]) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        else {
            m[words[i]] = 1;
        }
    }

    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}