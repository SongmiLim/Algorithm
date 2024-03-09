#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int k = 3;
    vector <int> v;
    
   while (true) {
       v.push_back(n%k);
       n = n/k;
       if(n==0)
           break;
   }
    for(int i=0;i<v.size();i++){
        answer += v[i]*pow(3,v.size()-i-1);
    }
    return answer;
}