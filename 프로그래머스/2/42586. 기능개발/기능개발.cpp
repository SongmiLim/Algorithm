#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int>st;
    int cnt;
    for (int i = progresses.size() - 1; i >= 0; i--) {
        st.push(progresses[i]);
    }

    while (!st.empty()) {
        cnt = 0;
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }

        while (!st.empty() && progresses[progresses.size() - st.size()] >= 100) {
            st.pop();
            cnt++;
        }

        if (cnt != 0) {
            answer.push_back(cnt);
        }
    }
    return answer;
}