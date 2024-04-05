#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while(true) {
        if(abs(a - b) == 1 && ((a+b) % 4 == 3)) {
            break;
        }
        
        a = (a-1)/2 + 1;
        b = (b-1)/2 + 1;
        answer++;
    }
    
    return answer;
}