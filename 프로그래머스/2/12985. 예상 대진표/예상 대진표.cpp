#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a--; 
    b--;
    
    while(true) {
        if(a == b) {
            break;
        }
        
        a = a/2;
        b = b/2;
        answer++;
    }
    
    return answer;
}