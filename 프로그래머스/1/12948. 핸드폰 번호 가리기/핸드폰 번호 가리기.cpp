#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    char x = '*';
    
    for(int i=0;i<answer.size()-4;i++){
        answer[i] = x;
    }
    return answer;
}