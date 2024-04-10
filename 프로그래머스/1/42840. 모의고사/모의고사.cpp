#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int get_score(vector<int> answers, vector<int> student_method) {
    vector<int> student_ans;
    int score = 0;
    
    for(int i=0;i<answers.size();i++) {
        student_ans.push_back(student_method[i%student_method.size()]);
    }
    
    for(int i=0;i<answers.size();i++) {
        if(answers[i] == student_ans[i]) {
            score++;
        }
    }
    return score;
}

vector<int> get_max_score(vector<int> answers) {
    vector<int> temp;
    vector<int> max_score;
    
    temp.push_back(get_score(answers, {1,2,3,4,5}));
    temp.push_back(get_score(answers, {2, 1, 2, 3, 2, 4, 2, 5}));
    temp.push_back(get_score(answers, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}));
    
    int max = *max_element(temp.begin(), temp.end());
    
    for(int i=0;i<temp.size();i++) {
        if(max == temp[i]){
            max_score.push_back(i+1);
        }
    }
    return max_score;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    answer = get_max_score(answers);
    return answer;
}