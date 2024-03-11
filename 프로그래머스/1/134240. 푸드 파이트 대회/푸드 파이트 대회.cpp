#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int total_num = 1;
    for (int i = 1; i < food.size(); i++) {
        if (food[i] % 2 != 0) {
            food[i] -= 1;
        }
        total_num += food[i];
    }

    vector <int> food_list(total_num,0);
    int pos = 0;

    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i] / 2; j++) {
            food_list[pos] = i;
            food_list[total_num - 1 - pos] = i;
            pos++;
        }
    }
    for (auto& a : food_list) {
        answer += to_string(a) ;
    }

    return answer;
}