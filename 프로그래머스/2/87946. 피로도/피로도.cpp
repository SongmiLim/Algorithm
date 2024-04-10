#include <string>
#include <vector>

using namespace std;
bool visited[9];
int max_cnt = 0;

void get_answer(vector<vector<int>> dungeons, int index, int k, int cur_cnt, int &max_cnt) {
    if (max_cnt < cur_cnt) {
        max_cnt = cur_cnt;
    }

    if (cur_cnt == dungeons.size() && dungeons[index][0]<k) {
        return;
    }

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            k -= dungeons[i][1];
            visited[i] = true;
            get_answer(dungeons, i, k, cur_cnt + 1, max_cnt);
            visited[i] = false;
            k += dungeons[i][1];
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    get_answer(dungeons, 0, k, 0, max_cnt);
    answer = max_cnt;
    return answer;
}