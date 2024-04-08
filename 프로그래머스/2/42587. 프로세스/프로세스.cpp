#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>>q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });
    }

    while (true) {

        bool flag = true;
        for (int i = 0; i < priorities.size(); i++) {
            if (priorities[i] > q.front().first) {
                q.push(q.front());
                q.pop();
                flag = false;
                break;
            }
        }

        if (flag) {
            answer++;
            if (q.front().second == location) {
                break;
            }
            priorities[q.front().second] = -1;
            q.pop();
        }
    }
    return answer;
}