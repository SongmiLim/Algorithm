#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int m;
vector<vector<int>> visited;
vector<vector<int>> result_land;
vector<int> max_array;

void bfs(int a, int b){
    int dx[4] = {-1, 1, 0 , 0};
    int dy[4] = {0, 0, -1, 1};
    int oil = 0;
    vector<int> max_array_visited(n,0);

    queue <pair<int, int>> q;
    q.push({ a, b });
    visited[a][b] = 1;

    while (!q.empty()) {
        oil++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }

            if (visited[nx][ny]==0 && result_land[nx][ny] >0 ) {
                q.push({ nx, ny });
                visited[nx][ny] = 1;
            }
        }
    }

    q.push({ a, b });
    result_land[a][b] = oil;
    max_array_visited[b] = 1;
    max_array[b] += oil;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }

            if (visited[nx][ny] == 1 && result_land[nx][ny]==1) {
                q.push({ nx, ny });
                result_land[nx][ny] = oil;
                max_array_visited[ny] == 0 ? max_array[ny] += oil : max_array[ny];
                max_array_visited[ny] = 1;
            }
        }
    }

}

int solution(vector<vector<int>> land) {
    int answer = 0;
    m = land.size();
    n = land[0].size();
    result_land = land;
    max_array.resize(n, 0);

    visited.resize(m, vector<int>(n, 0));

    for (int i = 0; i < land.size(); i++) 
    {
        for(int j=0;j<land[i].size();j++){
            if (visited[i][j]==0 && land[i][j] > 0) {
                bfs(i, j);
            }
        }
    }

    sort(max_array.rbegin(), max_array.rend());
    answer = max_array[0];

    return answer;
}