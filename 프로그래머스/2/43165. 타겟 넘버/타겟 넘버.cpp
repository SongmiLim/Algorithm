#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer;

void bfs(vector<int> numbers, int target) {
    queue <pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty()) {
        int index = q.front().first;
        int sum = q.front().second;
        q.pop();
        
        if (index == numbers.size()) {
            if(sum == target) {
                answer++;
            }
            continue;
        }
        q.push({index+1, sum+numbers[index]});
        q.push({index+1, sum-numbers[index]});
    }
}

int solution(vector<int> numbers, int target) {
    answer = 0;

    bfs(numbers, target);
    
    return answer;
}