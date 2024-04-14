#include <string>
#include <vector>
#include <iostream>
#define MAX 200

using namespace std;

vector<vector<int>> graph;
bool visited[MAX];

void dfs(int node) {
    visited[node] = true;
    
    for(int i=0;i<graph[node].size();i++) {
        if(!visited[graph[node][i]]) {
            dfs(graph[node][i]);
        }
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph.resize(n, vector<int>(0));
    
    for(int i=0;i<computers.size();i++) {
        for(int j=0;j<computers[i].size();j++) {
            if(computers[i][j] == 1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    for(int i=0;i<graph.size();i++) {
        for(int j=0;j<graph[i].size();j++) {
            if(!visited[graph[i][j]]) {
                dfs(graph[i][j]);
                ++answer;
            }
        }
   }
    return answer;
}