#include <string>
#include <vector>
#include <queue>

#define MAX 200
using namespace std;

bool visited[MAX];
void bfs(vector<vector<int>> computers, int computer_index) {
    queue <int> q;
    q.push(computer_index);
    visited[computer_index] = true;
    
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        
        for(int i=0;i<computers[index].size();i++) {
            if(computers[index][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
    
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++) {
        if(!visited[i]) {
            bfs(computers, i);
            answer++;
        }
    }
    return answer;
}