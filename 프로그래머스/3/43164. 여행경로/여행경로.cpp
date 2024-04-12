#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> answer_lists;
vector <string > s;
vector<bool> visited;

void dfs(vector<vector<string>>tickets, int ticket_index, int cnt) {
    visited[ticket_index] = true;
    s.push_back(tickets[ticket_index][1]);
   
    if (cnt == tickets.size()) {
        for (int i = 0; i < tickets.size(); i++) {
            if (visited[i] == false) {
                return;
            }
        }
        answer_lists.push_back(s);
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[ticket_index][1] == tickets[i][0]) {
            dfs(tickets, i, cnt + 1);
            visited[i] = false;
            s.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            s.clear();
            s.push_back(tickets[i][0]);
            visited.clear();
            visited.resize(tickets.size()+1, 0);
            visited[i] = true;
            dfs(tickets, i, 1);
        }
    }
    sort(answer_lists.begin(), answer_lists.end());
    answer = answer_lists[0];

    return answer;
}