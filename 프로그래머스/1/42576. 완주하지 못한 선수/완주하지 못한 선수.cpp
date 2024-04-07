#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multimap <string, int> map_part;
    multimap <string, int> map_comp;
    
    for(int i=0;i<participant.size(); i++) {
        map_part.insert({participant[i], i});
    }
    
    for(int i=0;i<completion.size(); i++) {
        map_comp.insert({completion[i], i});
    }
    
    for(auto iter = map_comp.begin(); iter!=map_comp.end();iter++){
        auto tmp = map_part.find(iter->first);
        if(tmp != map_part.end()) {
            map_part.erase(tmp);
        }
    }

    for(auto iter:map_part){
        answer += iter.first;
    }
    return answer;
}