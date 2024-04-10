#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

bool is_prime(int num) {
    bool flag = true;
    
    if(num == 0 || num == 1) 
        return false;
    
    for(int i=2;i<num;i++) {
        if(num%i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

int get_answer(string numbers) {
    int cnt = 0;
    vector <int> temp;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i=1;i<=numbers.size();i++) {
            string s = numbers.substr(0, i);
            temp.push_back(stoi(s));
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    
    for(auto &a: temp){
        if(is_prime(a)) {
            cnt++;
        }
    }
    return cnt;
}

int solution(string numbers) {
    int answer = 0;
    answer = get_answer(numbers);
    
    return answer;
}