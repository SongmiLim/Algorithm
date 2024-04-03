#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end());
    
    int end = 0;
    for(auto& target: targets){
        if(target[0]>=end){
            cout<< target[0]<<endl;
            end = target[1];
            answer++;
        }
        else{
            end = min(end, target[1]);
        }
    }
    return answer;
}