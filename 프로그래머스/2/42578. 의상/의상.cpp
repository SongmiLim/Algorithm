#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> category_num;
    
    for(auto& cloth: clothes) {
        category_num[cloth[1]]++;
    }
    
    for(auto& pair: category_num) {
        answer *= pair.second + 1;
    }
 
    return answer - 1;
}