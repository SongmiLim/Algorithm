#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_numbers;
    
    for (auto& a : numbers) {
        s_numbers.push_back(to_string(a));
    }

    sort(s_numbers.begin(), s_numbers.end(), compare);
    
    for(auto num : s_numbers) {
        answer += num;
    }

    if(answer[0] == '0') {
        return "0";
    }

    return answer;
}