#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n>0) {
        int tmp = n%3;
        
        n/=3;
        if(tmp == 0) {
            n--;
        }
        
        answer = "412"[tmp] + answer;
    }
    
    return answer;
}