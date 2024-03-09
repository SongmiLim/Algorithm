#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> temp = arr;
    vector<int> answer = arr;
    
    sort(temp.begin(), temp.end());
    int pos = 0;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i] == temp[0]){
            pos = i;
            break;}
    }
    
    answer.erase(answer.begin()+pos);
    
    if(answer.size()==0)
        answer.push_back(-1);
    
    return answer;
}