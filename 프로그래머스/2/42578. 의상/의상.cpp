#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector <int> cnt_list;
    unordered_map <string, vector<string>> vector_map;
    
    for(int i=0; i<clothes.size(); i++) {
        vector_map[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    for(auto a: vector_map) {
        cnt_list.push_back(a.second.size() + 1);
    }
    
    for(int i=0; i<cnt_list.size();i++) {
        answer *= cnt_list[i];
    }
    answer--;
    return answer;
}