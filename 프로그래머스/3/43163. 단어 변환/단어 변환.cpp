#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool change_word(string cur_word, string word) {
    bool flag = false;
    int cnt = 0;
    
    for(int i=0;i<word.size();i++) {
        if(cur_word[i]!=word[i]) {
            cnt++;
        }
        if(cnt>=2) {
            return false;
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    if(find(words.begin(), words.end(), begin) != words.end())
        return 1;
    
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    
    q.push({begin, 0});
    while(!q.empty()) {
        string cur_word = q.front().first;
        int index = q.front().second;
        q.pop();
        
        if(cur_word == target) {
            return index;
        }
        
        for(auto &word: words) {
            if(change_word(cur_word, word) && visited.find(word) == visited.end()) {
                q.push({word, ++index});
                visited.insert(word);
            }
        }
    }
    
    return answer;
}