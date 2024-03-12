#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool visited[101][101];

int bfs(vector<vector<int>> map, int r, int c, int m, int n) {
    queue<pair<int, int>> q;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int cnt = 0;

    q.push({ r, c });
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            if (!visited[nx][ny] && map[x][y] == map[nx][ny]) {
                q.push({ nx,ny });
                visited[nx][ny] = true;;
                cnt++;
            }
        }
    }
    return cnt;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector <int> size_of_one_area;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] != 0) {
                size_of_one_area.push_back(bfs(picture, i, j, m ,n));
                number_of_area++;
            }
        }
    }
    sort(size_of_one_area.rbegin(), size_of_one_area.rend());
    max_size_of_one_area = size_of_one_area[0];

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;


    return answer;
}