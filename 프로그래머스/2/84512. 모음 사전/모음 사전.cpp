#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector <string> v;
vector <vector <string>> index_words;

void get_all_words(vector <string> all_words) {
    
    index_words.push_back(v);

    if(v.size() == all_words.size()) {
        return;
    }
    
    for(int i=0;i<all_words.size();i++) {
        v.push_back(all_words[i]);
        get_all_words(all_words);
        v.pop_back();
    }
}

int get_word_index(string word) {
    int cnt = 0;
    
    for(auto&a : index_words) {
        string s = "";
        
        for(int i=0;i<a.size();i++) {
            s+=a[i];
        }
        
        if(s == word){
            return cnt;
        }
        
        cnt++;
    } 
}

int solution(string word) {
    int answer = 0;
    get_all_words({"A", "E", "I", "O", "U"});
    
    answer = get_word_index(word);
    
    return answer;
}