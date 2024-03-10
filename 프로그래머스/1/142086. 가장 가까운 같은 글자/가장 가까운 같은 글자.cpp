#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s)
{
    map<char, int> mp;
    vector<int> answer;


    for (int i = 0; i < s.size(); ++i)
    {
        if (mp.find(s[i]) != mp.end()) 
            answer.push_back(i - mp[s[i]]);
        else
            answer.push_back(-1);
        // map 에 key, value 넣기   => 왜 여기서  => insert 시 중복된 키값이 들어오면 insert 불가
        // 따라서 해당 키에 따른 value값이 업데이트 되면 직접 값을 업데이트 시켜줘야함
        mp[s[i]] = i;  
    }
    return answer;
}

/*
vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); i++) {
        int pos = -1;
        for (int j = i-1; j >= 0; j--) {
            if (s[i] == s[j]) {
                pos = i - j;
                break;
            }
        }
        answer.push_back(pos);
    }
    return answer;
}
*/