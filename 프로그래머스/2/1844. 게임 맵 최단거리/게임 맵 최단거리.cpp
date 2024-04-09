#include<vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int visited[100][100] = {0, };

int bfs(int y, int x, vector<vector<int>> maps) {
    queue <pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    int cnt = 1;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if((y==maps.size()-1) && (x == maps[0].size()-1)) {
            return visited[y][x];
        }
        
        for(int i=0;i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny<0 || nx<0 || ny>=maps.size() || nx>=maps[0].size()) {
                continue;
            }
            
            if(visited[ny][nx] == 0 && maps[ny][nx] == 1) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x]+1;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    answer = bfs(0, 0, maps); 
    return answer;
}