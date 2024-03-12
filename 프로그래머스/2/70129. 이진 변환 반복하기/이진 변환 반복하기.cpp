#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int erase_cnt = 0;
    int chage_cnt = 0;
    vector<int> binary_num;

    while (s != "1") {
        binary_num.clear();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                s.erase(s.begin() + i);
                i--;
                erase_cnt++;
            }
        }
        int n = s.size();
        while (n > 0) {
            binary_num.push_back(n % 2);
            n = n / 2;
        }

        s.clear();
        for (int j = binary_num.size()-1; j >=0; j--) {
            s += to_string(binary_num[j]);
        }
        chage_cnt++;
    }
    
    answer.push_back(chage_cnt);
    answer.push_back(erase_cnt);

    return answer;
}