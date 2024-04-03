#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1]<b[1];
    }
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int end = 0;
    for(auto& target: targets){
        if(target[0]>=end){
            cout<< target[0]<<endl;
            end = target[1];
            answer++;
        }
    }
    return answer;
}