#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = -1;
    stack <int> temp;
    
    for (int i = s.size() - 1; i >=0; i--) {
        
        if(!temp.empty() && s[i] == temp.top()){
            s.pop_back();
            temp.pop();
        }
        
        else{
            temp.push(s[i]);
        }
    }
    
    temp.size() == 0 ? answer = 1 : answer = 0;
    return answer;
}