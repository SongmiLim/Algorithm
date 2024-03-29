#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
    int ans = 0;
    long long N = n;
    
    while(n>0){
        if(n%2 == 0){
            n/=2;
        }
        else{
            n--;
            ans++;
        }
    }
    return ans;
}