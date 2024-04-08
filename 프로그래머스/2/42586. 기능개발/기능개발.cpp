#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>q;
    int cnt;
    for (int i = 0; i <progresses.size(); i++) {
        q.push(progresses[i]);
    }

    while (!q.empty()) {
        cnt = 0;
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }

        while (!q.empty() && progresses[progresses.size() - q.size()] >= 100) {
            q.pop();
            cnt++;
        }

        if (cnt != 0) {
            answer.push_back(cnt);
        }
    }
    return answer;
}