#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> tmp;
    bool flag = false;

    for (int i = 1; i < words.size(); i++) {
        if (flag)
            break;

        tmp.push_back(words[i - 1]);
        if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) {
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);
            answer.push_back((i + 1) % n == 0 ? (i + 1) / n : (i + 1) / n + 1);
            break;
        }

        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] == words[i]) {
                answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);
                answer.push_back((i + 1) % n == 0 ? (i + 1) / n : (i + 1) / n + 1);
                flag = true;
                break;
            }
        }
    }
    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}