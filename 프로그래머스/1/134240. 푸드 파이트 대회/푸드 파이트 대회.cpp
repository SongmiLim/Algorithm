#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    for (int i = food.size() - 1; i > 0; i--) {
        int cnt = food[i]/2;
        while (cnt) {
            answer = to_string(i) + answer + to_string(i);
            cnt--;
        }
    }

    return answer;
}